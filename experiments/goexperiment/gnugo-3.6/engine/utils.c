/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * This is GNU Go, a Go program. Contact gnugo@gnu.org, or see       *
 * http://www.gnu.org/software/gnugo/ for more information.          *
 *                                                                   *
 * Copyright 1999, 2000, 2001, 2002, 2003 and 2004                   *
 * by the Free Software Foundation.                                  *
 *                                                                   *
 * This program is free software; you can redistribute it and/or     *
 * modify it under the terms of the GNU General Public License as    *
 * published by the Free Software Foundation - version 2             *
 *                                                                   *
 * This program is distributed in the hope that it will be useful,   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of    *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     *
 * GNU General Public License in file COPYING for more details.      *
 *                                                                   *
 * You should have received a copy of the GNU General Public         *
 * License along with this program; if not, write to the Free        *
 * Software Foundation, Inc., 59 Temple Place - Suite 330,           *
 * Boston, MA 02111, USA.                                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "gnugo.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "liberty.h"
#include "sgftree.h"
#include "random.h"
#include "gg_utils.h"


/*
 * Change the status of all the stones in the dragon at (dr).
 */

void
change_dragon_status(int dr, int status)
{
  int pos;
  int origin = dragon[dr].origin;

  for (pos = BOARDMIN; pos < BOARDMAX; pos++)
    if (ON_BOARD(pos)) {
      if (dragon[pos].origin == origin)
	dragon[pos].status = status;
    }
}


/*
 * Check whether a move at (move) stops the enemy from playing at (apos).
 */

int
defend_against(int move, int color, int apos)
{
  if (trymove(move, color, "defend_against", NO_MOVE)) {
    if (safe_move(apos, OTHER_COLOR(color)) == 0) {
      popgo();
      return 1;
    }
    popgo();
  }
  return 0;
}


/* 
 * Returns true if color can cut at (pos), or if connection through (pos)
 * is inhibited. This information is collected by find_cuts(), using the B
 * patterns in the connections database.
 */

int
cut_possible(int pos, int color)
{
  return (cutting_points[pos] & OTHER_COLOR(color)) != 0;
}


/*
 * does_attack(move, str) returns true if the move at (move)
 * attacks (str). This means that it captures the string, and that
 * (str) is not already dead.
 */

int
does_attack(int move, int str)
{
  int color = board[str];
  int other = OTHER_COLOR(color);
  int result = 0;
  int acode = 0;
  int dcode = 0;
  int spos = NO_MOVE;
  
  if (stackp == 0) {
    if (worm[str].attack_codes[0] != 0 
	&& worm[str].defense_codes[0] == 0)
      return 0;
    spos = worm[str].defense_points[0];
  }
  else {
    attack_and_defend(str, &acode, NULL, &dcode, &spos);
    if (acode != 0 && dcode == 0)
      return 0;
  }
  
  if (trymove(move, other, "does_attack-A", str)) {
    if (!board[str] || !find_defense(str, NULL)) {
      result = WIN;
      increase_depth_values();
      if (spos != NO_MOVE && trymove(spos, color, "does_attack-B", str)) {
	if (board[str] && !attack(str, NULL))
	  result = 0;
	popgo();
      }
      decrease_depth_values();
    }
    popgo();
  }

  return result;
}


/*
 * does_defend(move, str) returns true if the move at (move)
 * defends (str). This means that it defends the string, and that
 * (str) can be captured if no defense is made.
 */

int
does_defend(int move, int str)
{
  int color = board[str];
  int other = OTHER_COLOR(color);
  int result = 0;
  int spos = NO_MOVE;

  if (stackp == 0) {
    if (worm[str].attack_codes[0] == 0)
      return 0;
    else
      spos = worm[str].attack_points[0];
  }
  else if (!attack(str, &spos))
    return 0;

  gg_assert(spos != NO_MOVE);
  
  if (trymove(move, color, "does_defend-A", str)) {
    if (!attack(str, NULL)) {
      result = 1;
      increase_depth_values();
      if (trymove(spos, other, "does_defend-B", str)) {
	if (!board[str] || !find_defense(str, NULL))
	  result = 0;
	popgo();
      }
      decrease_depth_values();
    }
    popgo();
  }

  return result;
}


/* 
 * Example: somewhere(WHITE, 2, apos, bpos, cpos).
 * 
 * Returns true if one of the vertices listed
 * satisfies board[pos]==color. Here num_moves is the
 * number of moves. If check_alive is true, the dragon is not allowed
 * to be dead. This check is only valid if stackp==0.
 */

int
somewhere(int color, int check_alive, int num_moves, ...)
{
  va_list ap;
  int pos;
  int k;

  gg_assert(stackp == 0 || !check_alive);
  
  va_start(ap, num_moves);
  for (k = 0; k < num_moves; k++) {
    pos = va_arg(ap, int);

    if (board[pos] == color
	&& (!check_alive || dragon[pos].status != DEAD))
      return 1;
  }

  return 0;
}

/* Search along the edge for the first visible stone. Start at apos
 * and move in the direction of bpos. Return 1 if the first visible
 * stone is of the given color. It is required that apos and bpos are
 * at the same distance from the edge.
 *
 * FIXME: The detection of the first visible stone is quite crude and
 * probably needs to be improved.
 */
int
visible_along_edge(int color, int apos, int bpos)
{
  int ai = I(apos);
  int aj = J(apos);
  int bi = I(bpos);
  int bj = J(bpos);
  int pos;
  int forward;
  int up;
  ASSERT1((ai == bi) ^ (aj == bj), apos);

  if (ai == bi) {
    if (aj > bj)
      forward = WEST(0);
    else
      forward = EAST(0);

    if (ai < board_size/2) {
      pos = POS(0, bj);
      up = SOUTH(0);
    }
    else {
      pos = POS(board_size - 1, bj);
      up = NORTH(0);
    }
  }
  else {
    if (ai > bi)
      forward = NORTH(0);
    else
      forward = SOUTH(0);

    if (aj < board_size/2) {
      pos = POS(bi, 0);
      up = EAST(0);
    }
    else {
      pos = POS(bi, board_size - 1);
      up = WEST(0);
    }
  }
  
  for (; ON_BOARD(pos); pos += forward) {
    int k;
    for (k = 4; k >= 0; k--) {
      ASSERT_ON_BOARD1(pos + k * up);
      if (board[pos + k * up] == color)
	return 1;
      else if (board[pos + k * up] == OTHER_COLOR(color))
	return 0;
    }
  }

  return 0;
}

/* Is the board symmetric (or rather antisymmetric) with respect to
 * mirroring in tengen after a specific move has been played? If the
 * move is PASS_MOVE, check the current board.
 *
 * If strict is set we require that each stone is matched by a stone
 * of the opposite color at the mirrored vertex. Otherwise we only
 * require that each stone is matched by a stone of either color.
 */
int
test_symmetry_after_move(int move, int color, int strict)
{
  int pos;
  int result = 1;

  if (move != PASS_MOVE) {
    if (board[move] != EMPTY)
      return 0;
    if (!trymove(move, color, "find_mirror_move", NO_MOVE))
      return 0;
  }
  
  for (pos = BOARDMIN; pos < MIRROR_MOVE(pos); pos++) {
    int sum;
    if (!ON_BOARD(pos))
      continue;
    
    sum = board[pos] + board[MIRROR_MOVE(pos)];
    if (sum != EMPTY + EMPTY && sum != BLACK + WHITE) {
      if (strict || sum == EMPTY + WHITE || sum == EMPTY + BLACK) {
      result = 0;
      break;
      }
    }
  }

  if (move != PASS_MOVE)
    popgo();
  
  return result;
}


/* The function play_break_through_n() plays a sequence of moves,
 * alternating between the players and starting with color. After
 * having played through the sequence, the three last coordinate pairs
 * gives a position to be analyzed by break_through(), to see whether
 * either color has managed to enclose some stones and/or connected
 * his own stones. If any of the three last positions is empty, it's
 * assumed that the enclosure has failed, as well as the attempt to
 * connect.
 *
 * If one or more of the moves to play turns out to be illegal for
 * some reason, the rest of the sequence is played anyway, and
 * break_through() is called as if nothing special happened.
 *
 * Like break_through(), this function returns 1 if the attempt to
 * break through was succesful and 2 if it only managed to cut
 * through.
 */
   
int
play_break_through_n(int color, int num_moves, ...)
{
  va_list ap;
  int mcolor = color;
  int success = 0;
  int i;
  int played_moves = 0;
  int apos;
  int xpos;
  int ypos;
  int zpos;
  
  va_start(ap, num_moves);

  /* Do all the moves with alternating colors. */
  for (i = 0; i < num_moves; i++) {
    apos = va_arg(ap, int);

    if (apos != NO_MOVE
	&& (trymove(apos, mcolor, "play_break_through_n", NO_MOVE)
	    || tryko(apos, mcolor, "play_break_through_n")))
      played_moves++;
    mcolor = OTHER_COLOR(mcolor);
  }

  /* Now do the real work. */
  xpos = va_arg(ap, int);
  ypos = va_arg(ap, int);
  zpos = va_arg(ap, int);
    
  /* Temporarily increase the depth values with the number of explicitly
   * placed stones.
   */
#if 0
  modify_depth_values(played_moves);
#endif
  
  if (board[xpos] == EMPTY
      || board[ypos] == EMPTY
      || board[zpos] == EMPTY)
    success = 1;
  else
    success = break_through(xpos, ypos, zpos);

#if 0
  modify_depth_values(-played_moves);
#endif
  
  /* Pop all the moves we could successfully play. */
  for (i = 0; i < played_moves; i++)
    popgo();

  va_end(ap);
  return success;
}


/* The function play_attack_defend_n() plays a sequence of moves,
 * alternating between the players and starting with color. After
 * having played through the sequence, the last coordinate pair gives
 * a target to attack or defend, depending on the value of do_attack.
 * If there is no stone present to attack or defend, it is assumed
 * that it has already been captured. If one or more of the moves to
 * play turns out to be illegal for some reason, the rest of the
 * sequence is played anyway, and attack/defense is tested as if
 * nothing special happened.
 *
 * A typical use for these functions is to set up a ladder in an
 * autohelper and see whether it works or not.
 */
   
int
play_attack_defend_n(int color, int do_attack, int num_moves, ...)
{
  va_list ap;
  int mcolor = color;
  int success = 0;
  int i;
  int played_moves = 0;
  int apos;
  int zpos;
  
  va_start(ap, num_moves);

  /* Do all the moves with alternating colors. */
  for (i = 0; i < num_moves; i++) {
    apos = va_arg(ap, int);

    if (apos != NO_MOVE
	&& (trymove(apos, mcolor, "play_attack_defend_n", NO_MOVE)
	    || tryko(apos, mcolor, "play_attack_defend_n")))
      played_moves++;
    mcolor = OTHER_COLOR(mcolor);
  }

  /* Now do the real work. */
  zpos = va_arg(ap, int);

  /* Temporarily increase the depth values with the number of explicitly
   * placed stones.
   *
   * This improves the reading of pattern constraints but
   * unfortunately tends to be too expensive. For the time being it is
   * disabled.
   */
#if 0
  modify_depth_values(played_moves);
#endif
  
  if (do_attack) {
    if (board[zpos] == EMPTY)
      success = WIN;
    else
      success = attack(zpos, NULL);
  }
  else {
    if (board[zpos] == EMPTY)
      success = 0;
    else {
      int dcode = find_defense(zpos, NULL);
      if (dcode == 0 && !attack(zpos, NULL))
	success = WIN;
      else
	success = dcode;
    }
  }

#if 0
  modify_depth_values(-played_moves);
#endif
  
  /* Pop all the moves we could successfully play. */
  for (i = 0; i < played_moves; i++)
    popgo();

  va_end(ap);
  return success;
}


/* The function play_attack_defend2_n() plays a sequence of moves,
 * alternating between the players and starting with color. After
 * having played through the sequence, the two last coordinate pairs
 * give two targets to simultaneously attack or defend, depending on
 * the value of do_attack. If there is no stone present to attack or
 * defend, it is assumed that it has already been captured. If one or
 * more of the moves to play turns out to be illegal for some reason,
 * the rest of the sequence is played anyway, and attack/defense is
 * tested as if nothing special happened.
 *
 * A typical use for these functions is to set up a crosscut in an
 * autohelper and see whether at least one cutting stone can be
 * captured.
 */
   
int
play_attack_defend2_n(int color, int do_attack, int num_moves, ...)
{
  va_list ap;
  int mcolor = color;
  int success = 0;
  int i;
  int played_moves = 0;
  int apos;
  int ypos;
  int zpos;
  
  va_start(ap, num_moves);

  /* Do all the moves with alternating colors. */
  for (i = 0; i < num_moves; i++) {
    apos = va_arg(ap, int);

    if (apos != NO_MOVE
	&& (trymove(apos, mcolor, "play_attack_defend_n", NO_MOVE)
	    || tryko(apos, mcolor, "play_attack_defend_n")))
      played_moves++;
    mcolor = OTHER_COLOR(mcolor);
  }

  /* Now do the real work. */
  ypos = va_arg(ap, int);
  zpos = va_arg(ap, int);

  /* Temporarily increase the depth values with the number of explicitly
   * placed stones.
   */
#if 0
  modify_depth_values(played_moves);
#endif
  

  /* FIXED: tm - returns ko results correctly (3.1.22) */
  if (do_attack) {
    if (board[ypos] == EMPTY || board[zpos] == EMPTY)
      success = WIN;
    else
      success = attack_either(ypos, zpos);
  }
  else {
    if (board[ypos] == EMPTY || board[zpos] == EMPTY)
      success = 0;
    else
      success = defend_both(ypos, zpos);
  }

#if 0
  modify_depth_values(-played_moves);
#endif
  
  /* Pop all the moves we could successfully play. */
  for (i = 0; i < played_moves; i++)
    popgo();

  va_end(ap);
  return success;
}


/* The function play_connect_n() plays a sequence of moves,
 * alternating between the players and starting with color. After
 * having played through the sequence, the two last coordinates
 * give two targets that should be connected or disconnected, depending on
 * the value of do_connect. If there is no stone present to connect or
 * disconnect, it is assumed that the connection has failed. If one or
 * more of the moves to play turns out to be illegal for some reason,
 * the rest of the sequence is played anyway, and connection/disconnection
 * is tested as if nothing special happened.
 */

int 
play_connect_n(int color, int do_connect, int num_moves, ...)
{
  va_list ap;
  int mcolor = color;
  int success = 0;
  int i;
  int played_moves = 0;
  int apos;
  int ypos;
  int zpos;

  va_start(ap, num_moves);

  /* Do all the moves with alternating colors. */
  for (i = 0; i < num_moves; i++) {
    apos = va_arg(ap, int);

    if (apos != NO_MOVE
	&& (trymove(apos, mcolor, "play_connect_n", NO_MOVE)
	    || tryko(apos, mcolor, "play_connect_n")))
      played_moves++;
    mcolor = OTHER_COLOR(mcolor);
  }

  /* Now do the real work. */
  ypos = va_arg(ap, int);
  zpos = va_arg(ap, int);

  /* Temporarily increase the depth values with the number of explicitly
   * placed stones.
   *
   * This improves the reading of pattern constraints but
   * unfortunately tends to be too expensive. For the time being it is
   * disabled.
   */
#if 0
  modify_depth_values(played_moves);
#endif
  
  /* See if ypos and zpos can be connected (or disconnected). */
  if (do_connect) {
    if (board[ypos] == EMPTY || board[zpos] == EMPTY)
      success = 0;
    else
      success = string_connect(ypos, zpos, NULL);
  }
  else {
    if (board[ypos] == EMPTY || board[zpos] == EMPTY)
      success = WIN;
    else
      success = disconnect(ypos, zpos, NULL);
  }

#if 0
  modify_depth_values(-played_moves);
#endif
  
  /* Pop all the moves we could successfully play. */
  for (i = 0; i < played_moves; i++)
    popgo();

  va_end(ap);
  return success;
}



/* 
 * It is assumed in reading a ladder if stackp >= depth that
 * as soon as a bounding stone is in atari, the string is safe.
 * It is used similarly at other places in reading.c to implement simplifying
 * assumptions when stackp is large. DEPTH is the default value of depth.
 *
 * Unfortunately any such scheme invites the ``horizon effect.'' Increasing
 * DEPTH will make the program stronger and slower.
 *
 */

/* Tactical reading using C functions */
#define DEPTH                16
#define BRANCH_DEPTH         13
#define BACKFILL_DEPTH       12
#define BACKFILL2_DEPTH       5
#define BREAK_CHAIN_DEPTH     7
#define SUPERSTRING_DEPTH     7
#define FOURLIB_DEPTH         7
#define KO_DEPTH              8

#if 0
#undef FOURLIB_DEPTH
#define FOURLIB_DEPTH         9
#endif


#define AA_DEPTH              6

/* Pattern based reading */
#define OWL_DISTRUST_DEPTH    6
#define OWL_BRANCH_DEPTH      8
#define OWL_READING_DEPTH    20
#define SEMEAI_BRANCH_DEPTH  12
#define SEMEAI_BRANCH_DEPTH2  6

/* Connecton reading */
#define CONNECT_NODE_LIMIT 2000
#define CONNECT_DEPTH        64
#define CONNECT_DEPTH2       20

#define BREAKIN_NODE_LIMIT  400
#define BREAKIN_DEPTH	     14

/* Set the various reading depth parameters. If mandated_depth_value
 * is not -1 that value is used; otherwise the depth values are
 * set as a function of level. The parameter mandated_depth_value
 * can be set at the command line to force a particular value of
 * depth; normally it is -1.
 */

void
set_depth_values(int level, int report_levels)
{
  static int node_limits[] = {500, 500, 450, 400, 400, 325, 275,
			      200, 150, 100, 75, 50};
  int depth_level;

  /*
   * Other policies depending on level:
   * aftermath.c:   >=  8: call estimate_score().
   * dragon.c:      >=  8: compute owl threats (currently disabled)
   * genmove.c:     >=  8: call estimate_score().
   * owl.c:         >=  9: use vital attack pattern database
   *                >=  8: increase depth values in owl_substantial
   *                >=  8: don't turn off owl_phase in semeai reading
   * reading.c:     >=  8: Use superstrings and do more backfilling.
   * value_moves.c: >=  6: try to find more owl attacks/defenses
   * breakin.c:     >= 10: try to find break-ins. (*)
   *
   * The break-in code (*) is particularly expensive. 
   *
   * Speedups between levels 9 and 10 and between levels 7 and 8
   * are obtained by turning off services, and between these
   * levels no changes are made in the depths. The parameter
   * depth_level is the correction compared to the default settings at level
   * 10 for most reading depths.
   */
  if (level >= 10)
    depth_level = level - 10;
  else if (level == 9)
    depth_level = 0;
  else if (level == 8)
    depth_level = -1;
  else 
    depth_level = level - 8;

  depth                = gg_max(6, DEPTH 	    + depth_level);
  branch_depth         = gg_max(3, BRANCH_DEPTH	    + depth_level);
  backfill_depth       = gg_max(2, BACKFILL_DEPTH    + depth_level);
  backfill2_depth      = gg_max(1, BACKFILL2_DEPTH   + depth_level);
  break_chain_depth    = gg_max(2, BREAK_CHAIN_DEPTH + depth_level);
  if (level >= 8)
    owl_distrust_depth = gg_max(1, (2 * OWL_DISTRUST_DEPTH + depth_level) / 2);
  else
    owl_distrust_depth = gg_max(1, (2 * OWL_DISTRUST_DEPTH - 1
				    + depth_level) / 2);
  owl_branch_depth     = gg_max(2, (2 * OWL_BRANCH_DEPTH   + depth_level) / 2);
  owl_reading_depth    = gg_max(5, (2 * OWL_READING_DEPTH  + depth_level) / 2);

  /* Atari-atari depth levels are unchanged only between levels 7/8, 9/10: */
  if (level >= 10)
    aa_depth = gg_max(0, AA_DEPTH + (level - 10));
  else if (level == 9)
    aa_depth = gg_max(0, AA_DEPTH);
  else if (level >= 7)
    aa_depth = gg_max(0, AA_DEPTH - 1);
  else
    aa_depth = gg_max(0, AA_DEPTH - (8 - level));

  /* Exceptions:
   * fourlib_depth: This is constant from levels 7 to 10.
   * superstring_depth: set to 0 below level 8.
   */
  if (level >= 10)
    ko_depth            = gg_max(1, KO_DEPTH + (level - 10));
  else if (level == 9)
    ko_depth            = gg_max(1, KO_DEPTH);
  else if (level >= 7)
    ko_depth            = gg_max(1, KO_DEPTH - 1);
  else
    ko_depth            = gg_max(1, KO_DEPTH + (level - 8));

  if (level >= 10)
    fourlib_depth       = gg_max(1, FOURLIB_DEPTH + (level - 10));
  else if (level >= 7)
    fourlib_depth       = gg_max(1, FOURLIB_DEPTH);
  else
    fourlib_depth       = gg_max(1, FOURLIB_DEPTH + (level - 7));

  if (level >= 8)
    superstring_depth = gg_max(1, SUPERSTRING_DEPTH);
  else
    superstring_depth = 0;

  if (level >= 10)
    owl_node_limit      = OWL_NODE_LIMIT * pow(1.5, depth_level);
  else {
    owl_node_limit      = (OWL_NODE_LIMIT * node_limits[10 - level] /
			   node_limits[0]);
    owl_node_limit      = gg_max(20, owl_node_limit);
  }

  semeai_branch_depth  = gg_max(2, (2*SEMEAI_BRANCH_DEPTH  + depth_level) / 2);
  semeai_branch_depth2 = gg_max(2, (2*SEMEAI_BRANCH_DEPTH2 + depth_level) / 2);
  semeai_node_limit    = SEMEAI_NODE_LIMIT * pow(1.5, depth_level);

  connect_depth         = gg_max(2, CONNECT_DEPTH  + 2 * depth_level);
  connect_depth2        = gg_max(2, CONNECT_DEPTH2 + 2 * depth_level);
  connection_node_limit = CONNECT_NODE_LIMIT * pow(1.5, depth_level);
  breakin_depth 	= gg_max(2, BREAKIN_DEPTH + 2 * depth_level);
  breakin_node_limit 	= BREAKIN_NODE_LIMIT * pow(1.5, depth_level);

  if (mandated_depth != -1)
    depth = mandated_depth;
  if (mandated_backfill_depth != -1)
    backfill_depth = mandated_backfill_depth;
  if (mandated_backfill2_depth != -1)
    backfill2_depth = mandated_backfill2_depth;
  if (mandated_break_chain_depth != -1)
    break_chain_depth = mandated_break_chain_depth;
  if (mandated_superstring_depth != -1)
    superstring_depth = mandated_superstring_depth;
  if (mandated_branch_depth != -1)
    branch_depth = mandated_branch_depth;
  if (mandated_fourlib_depth != -1)
    fourlib_depth = mandated_fourlib_depth;
  if (mandated_ko_depth != -1)
    ko_depth = mandated_ko_depth;
  if (mandated_aa_depth != -1)
    aa_depth = mandated_aa_depth;
  if (mandated_owl_distrust_depth != -1)
    owl_distrust_depth = mandated_owl_distrust_depth;
  if (mandated_owl_branch_depth != -1)
    owl_branch_depth = mandated_owl_branch_depth;
  if (mandated_owl_reading_depth != -1)
    owl_reading_depth = mandated_owl_reading_depth;
  if (mandated_owl_node_limit != -1)
    owl_node_limit = mandated_owl_node_limit;

  depth_offset = 0;
  
  if (report_levels) {
    fprintf(stderr, "at level %d:\n\n\
depth: %d\n\
branch_depth: %d\n\
backfill_depth: %d\n\
backfill2_depth: %d\n\
break_chain_depth: %d\n\
owl_distrust_depth: %d\n\
owl_branch_depth: %d\n\
owl_reading_depth: %d\n\
aa_depth: %d\n\
ko_depth: %d\n\
fourlib_depth: %d\n\
superstring_depth: %d\n\
owl_node_limit: %d\n\
semeai_branch_depth: %d\n\
semeai_branch_depth2: %d\n\
semeai_node_limit: %d\n\
connect_depth: %d\n\
connect_depth2: %d\n\
connection_node_limit: %d\n\
breakin_depth: %d\n\
breakin_node_limit: %d\n\n",
	    level, depth, branch_depth, backfill_depth, backfill2_depth,
	    break_chain_depth, owl_distrust_depth, owl_branch_depth,
	    owl_reading_depth, aa_depth, ko_depth, fourlib_depth,
	    superstring_depth, owl_node_limit, semeai_branch_depth, 
	    semeai_branch_depth2, semeai_node_limit, connect_depth, 
            connect_depth2, connection_node_limit, breakin_depth, 
	    breakin_node_limit);
  }
}


/*
 * Modify the various tactical reading depth parameters. This is
 * typically used to avoid horizon effects. By temporarily increasing
 * the depth values when trying some move, one can avoid that an
 * irrelevant move seems effective just because the reading hits a
 * depth limit earlier than it did when reading only on relevant
 * moves.
 */

void
modify_depth_values(int n)
{
  depth              += n;
  backfill_depth     += n;
  backfill2_depth    += n;
  break_chain_depth  += n;
  superstring_depth  += n;
  branch_depth       += n;
  fourlib_depth      += n;
  ko_depth           += n;
  breakin_depth	     += n;
  depth_offset       += n;
}

void
increase_depth_values(void)
{
  modify_depth_values(1);
}

void
decrease_depth_values(void)
{
  modify_depth_values(-1);
}

/* These functions allow more drastic temporary modifications of the
 * depth values. Typical use is to turn certain depth values way down
 * for reading where speed is more important than accuracy, e.g. for
 * the influence function.
 */

static int save_depth;
static int save_backfill_depth;
static int save_backfill2_depth;
static int save_break_chain_depth;
static int save_superstring_depth;
static int save_branch_depth;
static int save_fourlib_depth;
static int save_ko_depth;

/* Currently this function is never called. */

void
set_temporary_depth_values(int d, int b, int b2, int bc,
			   int ss, int br, int f, int k)
{
  save_depth             = depth;
  save_backfill_depth    = backfill_depth;
  save_backfill2_depth   = backfill2_depth;
  save_break_chain_depth = break_chain_depth;
  save_superstring_depth = superstring_depth;
  save_branch_depth      = branch_depth;
  save_fourlib_depth     = fourlib_depth;
  save_ko_depth          = ko_depth;

  depth             = d;
  backfill_depth    = b;
  backfill2_depth   = b2;
  break_chain_depth = bc;
  superstring_depth = ss;
  branch_depth      = br;
  fourlib_depth     = f;
  ko_depth          = k;
}

void
restore_depth_values()
{
  depth             = save_depth;
  backfill_depth    = save_backfill_depth;
  backfill2_depth   = save_backfill2_depth;
  break_chain_depth = save_break_chain_depth;
  superstring_depth = save_superstring_depth;
  branch_depth      = save_branch_depth;
  fourlib_depth     = save_fourlib_depth;
  ko_depth          = save_ko_depth;
}

/*******************
 * Detect blunders *
 *******************/

static int detect_owl_blunder(int move, int color, int *defense_point,
			      char safe_stones[BOARDMAX], int liberties,
			      float *return_value, int save_verbose);

static void detect_tactical_blunder(int move, int color, int *defense_point,
				    char safe_stones[BOARDMAX],
				    int liberties, int *libs,
				    float *return_value, int save_verbose);

/* Check that the move at color doesn't involve any kind of blunder,
 * regardless of size.
 */
int
confirm_safety(int move, int color, int *defense_point,
	       char safe_stones[BOARDMAX])
{
  return (blunder_size(move, color, defense_point, safe_stones) == 0.0);
}

/* This function will detect some blunders. If the move reduces the
 * number of liberties of an adjacent friendly string, there is a
 * danger that the move could backfire, so the function checks that no
 * friendly worm which was formerly not attackable becomes attackable,
 * and it checks that no opposing worm which was not defendable
 * becomes defendable.
 *
 * It returns the estimated size of the blunder, or 0.0 if nothing
 * bad has happened.
 *
 * The array safe_stones[] contains the stones that are supposedly
 * safe after (move). It may be NULL.
 *
 * For use when called from fill_liberty, this function may optionally
 * return a point of defense, which, if taken, will presumably make
 * the move at (move) safe on a subsequent turn.
 */

float
blunder_size(int move, int color, int *defense_point,
	     char safe_stones[BOARDMAX])
{
  int libs[5];
  int liberties = accuratelib(move, color, 5, libs);
  int trouble = 0;
  int save_verbose = verbose;
  float return_value = 0.0;
  int atari;
  char defense_moves[BOARDMAX];
  
  if (defense_point)
    *defense_point = NO_MOVE;

  TRACE("Checking safety of a %s move at %1m\n", color_to_string(color), move);

  if (verbose > 0)
    verbose--;

  /* We start by checking whether we have accidentally killed an own
   * dragon.
   */
  trouble = detect_owl_blunder(move, color, defense_point,
			       safe_stones, liberties,
			       &return_value, save_verbose);
  

  /* Next we see whether the move has caused tactical complications.
   * The trouble variable is set if a string next to the move with few
   * liberties has not gained liberties by the move.
   */
  if (trouble)
    detect_tactical_blunder(move, color, defense_point, safe_stones,
			    liberties, libs, &return_value, save_verbose);

  /* FIXME: We would also need a detect_semeai_blunder() to check
   * against moves which make the outcome of a semeai worse, e.g. by
   * letting the opponent live in seki.
   */

  
  /* Finally we call the atari-atari code to see whether the move has
   * set up some combination attack that didn't exist before. We do
   * this last to avoid duplicate blunder reports.
   */
  atari = atari_atari_blunder_size(color, move, defense_moves, safe_stones);
  if (atari) {
    if (defense_point) {
      /* FIXME: Choose defense point more systematically. */
      int pos;
      *defense_point = NO_MOVE;
      for (pos = BOARDMIN; pos < BOARDMAX; pos++)
	if (ON_BOARD(pos) && defense_moves[pos]) {
	  *defense_point = pos;
	  break;
	}
    }
    verbose = save_verbose;
    TRACE("Combination attack appears.\n");
    return_value += (float) atari;
  }

  verbose = save_verbose;
  return return_value;
}

/* Check whether we have accidentally killed an own dragon adjacent to
 * move. If this happens, we mark its stones as no longer safe, and
 * remember the dragon's size.
 */

static int
detect_owl_blunder(int move, int color, int *defense_point,
		   char safe_stones[BOARDMAX], int liberties,
		   float *return_value, int save_verbose)
{
  int k;
  int ii;
  int trouble = 0;
  int dragon_analyzed[4] = {0, 0, 0, 0};
  int current_verbose = verbose;
  
  for (k = 0; k < 4; k++) {
    int bpos = move + delta[k];
    int j;
    /* We get worried if there is a liberty problem (and in this case
     * there might also be tactical trouble), or if we play inside
     * our eye space and the dragon is only just alive.
     */
    if (board[bpos] != color)
      continue;
    if (liberties <= worm[bpos].liberties
	&& liberties <= 4)
      trouble = 1;
    else
      if (min_eyes(&(DRAGON2(bpos).genus)) > 2
	  || !is_proper_eye_space(move))
	continue;

    /* Don't test the same dragon twice. */
    for (j = 0; j < k; j++)
      if (dragon_analyzed[j] == dragon[bpos].origin)
	break;
    if (j < k)
      continue;
    dragon_analyzed[k] = dragon[bpos].origin;

    /* Don't reanalyze if (move) is an owl defense for (bpos). */
    if (safe_stones && safe_stones[bpos] == OWL_SAVED_STONE)
      continue;

    if ((dragon[bpos].status == ALIVE
	 || (safe_stones 
	     && safe_stones[bpos]))
	&& DRAGON2(bpos).safety != INVINCIBLE
	&& DRAGON2(bpos).safety != STRONGLY_ALIVE) {
      int kworm = NO_MOVE;
      int acode = owl_confirm_safety(move, bpos, defense_point, &kworm);

      /* If owl couldn't confirm safety, maybe semeai can. */
      if (acode != WIN) {
	int r;
	for (r = 0; r < DRAGON2(bpos).neighbors; r++) {
	  int neighbor = dragon2[DRAGON2(bpos).adjacent[r]].origin;
	  int resultb;
	  if (board[neighbor] == color)
	    continue;
	  owl_analyze_semeai_after_move(move, color, neighbor, bpos,
					NULL, &resultb, NULL, 1, NULL, 0);
	  if (resultb == 0)
	    acode = WIN;
	}
      }
      
      if (acode == 0) {
	verbose = save_verbose;
	TRACE("Dragon at %1m becomes attackable.\n", bpos);
	verbose = current_verbose;
	*return_value += 2.0 * dragon[bpos].effective_size;
	if (safe_stones)
	  mark_dragon(bpos, safe_stones, 0);
      }
      else if (acode == LOSS) {
	verbose = save_verbose;
	TRACE("Dragon at %1m becomes attackable.\n", bpos);
	verbose = current_verbose;
	if (kworm == move) {
	  int l;
	  /* the worm origin was messed by our own move */
	  for (l = 0; l < 4; l++) {
	    int kworm = move + delta[l];
	    if (board[kworm] == color) {
	      *return_value += 2.0 * worm[kworm].effective_size;
	      if (safe_stones)
		for (ii = BOARDMIN; ii < BOARDMAX; ii++)
		  if (ON_BOARD(ii) && worm[ii].origin == worm[kworm].origin)
		    safe_stones[ii] = 0;
	    }
	  }
	}
	else {
	  *return_value += 2.0 * worm[kworm].effective_size;
	  if (safe_stones)
	    for (ii = BOARDMIN; ii < BOARDMAX; ii++)
	      if (ON_BOARD(ii) && worm[ii].origin == worm[kworm].origin)
		safe_stones[ii] = 0;
	}
      }
    }
  }

  return trouble;
}

/* Check whether a move causes any unexpected and unwelcome changes in
 * the tactical status of worms all over the board.
 */
static void
detect_tactical_blunder(int move, int color, int *defense_point,
			char safe_stones[BOARDMAX],
			int liberties, int *libs,
			float *return_value, int save_verbose)
{
  int other = OTHER_COLOR(color);
  int pos;
  int ii;
  int current_verbose = verbose;

  if (!trymove(move, color, NULL, NO_MOVE))
    return;
  
  /* Need to increase the depth values during this reading to avoid
   * horizon effects.
   */
  increase_depth_values();
  
  for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
    if (!IS_STONE(board[pos])
	|| worm[pos].origin != pos
	|| pos == move)
      continue;
    
    /* First, we look for a new tactical attack. */
    if (board[pos] == color
	&& ((safe_stones && safe_stones[pos])
	    || (!safe_stones && worm[pos].attack_codes[0] == 0))
	&& attack(pos, NULL)) {
      /* A safe worm of ours has become attackable. */
      if (defense_point)
	find_defense(pos, defense_point);
      verbose = save_verbose;
      TRACE("After %1m Worm at %1m becomes attackable.\n", move, pos);
      verbose = current_verbose;
      *return_value += worm[pos].effective_size;
      if (safe_stones) /* Can't use mark_string. */
	for (ii = BOARDMIN; ii < BOARDMAX; ii++)
	  if (worm[ii].origin == worm[pos].origin)
	    safe_stones[ii] = 0;
    }
    else if (board[pos] == other
	     && worm[pos].origin == pos
	     && worm[pos].attack_codes[0] != 0
	     && worm[pos].defense_codes[0] == 0
	     && find_defense(pos, NULL)) {
      /* A dead opponent's worm has become defendable.
       * Also ask the owl code whether the string can live
       * strategically. To do this we need to temporarily undo
       * the trymove().
       */
      int owl_attacks;
      int defense_effective = 0;
      
      popgo();
      decrease_depth_values();
      owl_attacks = owl_does_attack(move, pos, NULL);
      if (owl_attacks != WIN) {
	*return_value += 2 * worm[pos].effective_size;
	defense_effective = 1;
	verbose = save_verbose;
	TRACE("After %1m worm at %1m becomes defendable - A.\n", move, pos);
	verbose = current_verbose;
      }
      else if (dragon[pos].status != ALIVE) {
	/* Before redoing the trymove we also check whether the worm now
	 * has a semeai defense. See blunder:26 for an example.
	 *
	 * If the worm already was alive in seki, it is generally okay
	 * that it also becomes tactically safe when the outer
	 * liberties are filled, see e.g. blunder:32,34. Thus the
	 * check above.
	 */
	int k;
	int adj[MAXCHAIN];
	int num_adj;
	num_adj = extended_chainlinks(pos, adj, 0);
	for (k = 0; k < num_adj; k++) {
	  int neighbor = adj[k];
	  int resulta;
	  owl_analyze_semeai_after_move(move, color, pos, neighbor,
					&resulta, NULL, NULL, 1, NULL, 1);
	  if (resulta != 0) {
	    *return_value += 2 * worm[pos].effective_size;
	    defense_effective = 1;
	    verbose = save_verbose;
	    TRACE("After %1m worm at %1m becomes defendable - B.\n",
		  move, pos);
	    verbose = current_verbose;
	    break;
	  }
	}
      }
      
      trymove(move, color, NULL, NO_MOVE);
      increase_depth_values();
      
      if (defense_effective && defense_point) {
	int dpos;
	if (attack(pos, &dpos)) {
	  *defense_point = dpos;
	  /* Check that this move is legal and effective also on the
           * original board, otherwise find a tactical attack there
           * instead.
	   */
	  popgo();
	  
	  if (!is_legal(dpos, color)
	      || play_attack_defend_n(color, 0, 1, dpos, pos))
	    attack(pos, defense_point);

	  /* Redo the move, we know that it won't fail. */
	  trymove(move, color, NULL, NO_MOVE);
	}
	else {
	  verbose = save_verbose;
	  TRACE("No attack found (unexpectedly) on %1m after move at %1m.\n",
		pos, move);
	  verbose = current_verbose;
	}
      }
    }
  }

  /* Look for double atari style complications of the move.
   *
   * FIXME: Since we have an atari_atari check in blunder_size(), do
   * we still need to do this step?
   */
  if (liberties == 2) {
    float d_a_blunder_size;
    if (double_atari(libs[0], other, &d_a_blunder_size, safe_stones)) {
      if (defense_point && safe_move(libs[0], color) == WIN)
	*defense_point = libs[0];
      *return_value += d_a_blunder_size;
      verbose = save_verbose;
      TRACE("Double threat appears at %1m.\n", libs[0]);
      verbose = current_verbose;
    }
    else if (double_atari(libs[1], other, &d_a_blunder_size, safe_stones)) {
      if (defense_point && safe_move(libs[1], color) == WIN)
	*defense_point = libs[1];
      *return_value += d_a_blunder_size;
      verbose = save_verbose;
      TRACE("Double threat appears at %1m.\n", libs[1]);
      verbose = current_verbose;
    }
  }
  
  /* Reset the depth values. */
  decrease_depth_values();

  popgo();
}


/* Returns true if a move by (color) fits the following shape:
 * 
 *
 *    X*        (O=color)
 *    OX
 * 
 * capturing one of the two X strings. The name is a slight
 * misnomer since this includes attacks which are not necessarily
 * double ataris, though the common double atari is the most
 * important special case.
 * 
 * If safe_stones != NULL, then only attacks on stones marked as safe are
 * tried.
 *
 * The value of the double atari attack is returned in *value (unless
 * value is NULL), and the attacked stones are marked unsafe.
 */

int
double_atari(int move, int color, float *value, char safe_stones[BOARDMAX])
{
  int other = OTHER_COLOR(color);
  int k;
  int m = I(move);
  int n = J(move);

  if (!ON_BOARD(move))
    return 0;

  /* Loop over the diagonal directions. */
  for (k = 4; k < 8; k++) {
    int dm = deltai[k];
    int dn = deltaj[k];
    
    /* because (m, n) and (m+dm, n+dn) are opposite
     * corners of a square, ON_BOARD2(m, n) && ON_BOARD2(m+dm, n+dn)
     * implies ON_BOARD2(m+dm, n) and ON_BOARD2(n, n+dn)
     *
     * Only try to attack supposedly safe stones.
     */
    if (BOARD(m+dm, n+dn) == color
	&& BOARD(m, n+dn) == other
	&& BOARD(m+dm, n) == other
	&& (!safe_stones
	    || (safe_stones[POS(m, n+dn)] && safe_stones[POS(m+dm, n)]))
	&& trymove(move, color, "double_atari", NO_MOVE)) {
      if (countlib(move) > 1
	  && (BOARD(m, n+dn) == EMPTY || BOARD(m+dm, n) == EMPTY 
	      || !defend_both(POS(m, n+dn), POS(m+dm, n)))) {
	popgo();
	if (value) {
	  if (worm[POS(m, n+dn)].effective_size
	      > worm[POS(m+dm, n)].effective_size) {
	    *value = 2.0 * worm[POS(m, n+dn)].effective_size;
	    if (safe_stones)
	      mark_string(POS(m, n+dn), safe_stones, 0);
	  }
	  else {
	    *value = 2.0 * worm[POS(m+dm, n)].effective_size;
	    if (safe_stones)
	      mark_string(POS(m+dm, n), safe_stones, 0);
	  }
	}
	return 1;
      }
      popgo();
    }
  }
  
  return 0;
}
    

static int
capture_non_invincible_strings(int color, int exceptions[BOARDMAX])
{
  int other = OTHER_COLOR(color);
  int something_captured = 1; /* To get into the first turn of the loop. */
  int moves_played = 0;
  int save_moves;
  int libs[MAXLIBS];
  int liberties;
  int pos;
  int k;
  
  while (something_captured) {
    /* Nothing captured so far in this turn of the loop. */
    something_captured = 0;

    /* Visit all friendly strings on the board. */
    for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
      if (board[pos] != color || find_origin(pos) != pos)
	continue;

      if (exceptions && exceptions[pos])
	continue;
      
      /* Try to capture the string at pos. */
      liberties = findlib(pos, MAXLIBS, libs);
      save_moves = moves_played;
      for (k = 0; k < liberties; k++) {
	if (trymove(libs[k], other, "unconditional_life", pos))
	  moves_played++;
      }
      
      /* Successful if already captured or a single liberty remains.
       * Otherwise we must rewind and take back the last batch of moves.
       */
      if (board[pos] == EMPTY)
	something_captured = 1;
      else if (findlib(pos, 2, libs) == 1) {
	/* Need to use tryko as a defense against the extreme case
	 * when the only opponent liberty that is not suicide is an
	 * illegal ko capture, like in this 5x5 position:
	 * +-----+
	 * |.XO.O|
	 * |XXOO.|
	 * |X.XOO|
	 * |XXOO.|
	 * |.XO.O|
	 * +-----+
	 */
	int success = tryko(libs[0], other, "unconditional_life");
	gg_assert(success);
	moves_played++;
	something_captured = 1;
      }
      else
	while (moves_played > save_moves) {
	  popgo();
	  moves_played--;
	}
    }
  }
  return moves_played;
}

/* Find those worms of the given color that can never be captured,
 * even if the opponent is allowed an arbitrary number of consecutive
 * moves. The coordinates of the origins of these worms are written to
 * the worm arrays and the number of non-capturable worms is
 * returned.
 *
 * The algorithm is to cycle through the worms until none remains or
 * no more can be captured. A worm is removed when it is found to be
 * capturable, by letting the opponent try to play on all its
 * liberties. If the attack fails, the moves are undone. When no more
 * worm can be removed in this way, the remaining ones are
 * unconditionally alive.
 *
 * After this, unconditionally dead opponent worms and unconditional
 * territory are identified. This is almost, but only almost,
 * straightforward. We first present a simple but only almost correct
 * solution, then show how to patch up its deficiencies.
 *
 * - - - - - - -
 *
 * Algorithm 1, simple but slightly incorrect.
 *
 * To find unconditionally dead opponent worms and unconditional
 * territory, we continue from the position obtained at the end of the
 * previous operation (only unconditionally alive strings remain for
 * color) with the following steps:
 *
 * 1. Play opponent stones on all liberties of the unconditionally
 *    alive strings except where illegal. (That the move order may
 *    determine exactly which liberties can be played legally is not
 *    important. Just pick an arbitrary order).
 * 2. Recursively extend opponent strings in atari, except where this
 *    would be suicide.
 * 3. Play an opponent stone anywhere it can get two empty
 *    neighbors. (I.e. split big eyes into small ones).
 * 4. Play an opponent stone anywhere it can get one empty
 *    neighbor. (I.e. reduce two space eyes to one space eyes.)
 *
 * Remaining opponent strings in atari and remaining liberties of the
 * unconditionally alive strings constitute the unconditional
 * territory.
 *
 * Opponent strings from the initial position placed on
 * unconditional territory are unconditionally dead.
 *
 * - - - - - - -
 *
 * The deficiency with this algorithm is that a certain class of sekis
 * are considered as dead, e.g. this position:
 *
 * .OOOOO.
 * OOXXXOO
 * OXX.XXO
 * OX.O.XO
 * OX.O.XO
 * OXX.XXO
 * OOXXXOO
 * .OOOOO.
 *
 * The problem is that while removing the two O stones, X is reduced
 * to a single small eye. Still O cannot capture these stones under
 * alternating play since the eyespace is too big.
 *
 * Before discussing this seki further we make a preliminary
 * modification of the algorithm.
 *
 * - - - - - - -
 *
 * Algorithm 2. More complex but still slightly incorrect algorithm:
 *
 * 1. Run algorithm 1.
 * 2. Return to the original position.
 * 3. Capture all capturable O strings which according to algorithm 1
 *    do not belong to unconditional territory.
 * 4. Play opponent stones on all liberties of the unconditionally
 *    alive strings except where illegal. (That the move order may
 *    determine exactly which liberties can be played legally is not
 *    important. Just pick an arbitrary order).
 * 5. Recursively extend opponent strings in atari, except where this
 *    would be suicide.
 * 6. Capture all remaining capturable O strings.
 * 7. Repeat 4 and 5 once.
 * 8. Play an opponent stone anywhere it can get two empty
 *    neighbors. (I.e. split big eyes into small ones).
 * 9. Play an opponent stone anywhere it can get one empty
 *    neighbor. (I.e. reduce two space eyes to one space eyes.)
 *
 * Remaining opponent strings in atari and remaining liberties of the
 * unconditionally alive strings constitute the unconditional
 * territory.
 *
 * Opponent strings from the initial position placed on
 * unconditional territory are unconditionally dead.
 *
 * - - - - - - -
 *
 * We can observe that, after step 5, an X group with at least two
 * distinct eyespaces would not risk being reduced to a single small
 * eye. Similarly an X group with a capturable O string of size at
 * least three would allow the formation of two distinct small eyes
 * after being captured. Thus it is easy to see that the only X groups
 * which would live in seki but could not be transformed into
 * unconditionally alive groups would have a single eyespace with a
 * capturable O string of size at most 2. Furthermore the eyespace
 * would not be possible to subdivide. Then if the capturable string
 * would be of size 1 it would in all cases form a nakade and we would
 * not have a seki. The plausible seki positions would all be
 * reducable to the following eyeshape:
 *
 * .OOOOO.
 * OOXXXO.
 * OXX.XOO
 * OX.OXXO
 * OXXO.XO
 * OOX.XXO
 * .OXXXOO
 * .OOOOO.
 *
 * The remaining question is what effects cutting points in the X
 * group would have. For example these X groups are dead:
 *
 * .OOOOO.   .OOOOO.   .OOOOO.   .OOOOO.   ..OOOO.   ..OOOO.
 * .OXXXO.   .OXXXO.   .OXXXO.	 .OXXXO.   OOOXXO.   OOOXXO.
 * OOX.XO.   OOX.XOO   OOX.XOO	 OOX.XOO   OXX.XO.   OXX.XOO
 * OX.OXOO   OX.OXXO   OX.OXXO	 OX.OXXO   OX.OXOO   OX.OXXO
 * OXXO.XO   OXXO.XO   OXXO.XO	 OXXO.XO   OXXO.XO   OXXO.XO
 * OOX.XXO   OOX.XOO   OOX.XXO	 OOX.XXO   OOX.XXO   OOX.XXO
 * .OXXXOO   .OXXXO.   .OXXOOO	 .OOXXOO   .OXXXOO   .OXXOOO
 * .OOOOO.   .OOOOO.   .OOOO..	 ..OOOO.   .OOOOO.   .OOOO..
 *
 * while these are alive in seki
 *
 * ..OOOO.   .OOOO..   .OOOO..   ..OOOO.   ..OOOO.
 * OOOXXO.   .OXXOO.   OOXXOO.	 .OOXXO.   OOOXXO.
 * OXX.XOO   OOX.XOO   OXX.XOO	 OOX.XOO   OXX.XOO
 * OX.OXXO   OX.OXXO   OX.OXXO	 OX.OXXO   OX.OXXO
 * OXXO.XO   OXXO.XO   OOXO.XO	 OXXO.XO   OOXO.XO
 * OOX.XXO   OOX.XXO   .OX.XXO	 OOX.XXO   .OX.XXO
 * .OXXXOO   .OXXXOO   .OXXOOO	 .OXXXOO   .OXXXOO
 * .OOOOO.   .OOOOO.   .OOOO..	 ..OOOO.   .OOOOO.
 *
 * The critical distinction between the dead ones and the seki ones is
 * that the stones marked a and b below,
 *
 * .OOOOO.
 * OOXXXO.
 * OXX.XOO
 * OX.ObXO
 * OXaO.XO
 * OOX.XXO
 * .OXXXOO
 * .OOOOO.
 *
 * belong to different strings for the dead groups and to the same
 * string for the seki groups.
 *
 * The trick to avoid misclassifying areas where the opponent can form
 * a seki group but not an invincible group as unconditional territory
 * is thus to detect the formation above and add a third stone to the
 * O group before the capturing in step 6 above.
 *
 * This leads to the final algorithm.
 *
 * - - - - - - -
 *
 * Algorithm 3. Final and correct algorithm:
 *
 * 1. Run algorithm 1.
 * 2. Return to the original position.
 * 3. Capture all capturable O strings which according to algorithm 1
 *    do not belong to unconditional territory.
 * 4. Play opponent stones on all liberties of the unconditionally
 *    alive strings except where illegal. (That the move order may
 *    determine exactly which liberties can be played legally is not
 *    important. Just pick an arbitrary order).
 * 5. Recursively extend opponent strings in atari, except where this
 *    would be suicide.
 * 6. Identify eyespaces of the kind described above and extend any
 *    matching two-stone string with a third stone.
 * 7. Capture all remaining capturable O strings.
 * 8. Repeat 4 and 5 once.
 * 9. Play an opponent stone anywhere it can get two empty
 *    neighbors. (I.e. split big eyes into small ones).
 * 10. Play an opponent stone anywhere it can get one empty
 *    neighbor. (I.e. reduce two space eyes to one space eyes.)
 *
 * Remaining opponent strings in atari and remaining liberties of the
 * unconditionally alive strings constitute the unconditional
 * territory.
 *
 * Opponent strings from the initial position placed on
 * unconditional territory are unconditionally dead.
 *
 * - - - - - - -
 *
 * On return, unconditional_territory[][] is 1 where color has
 * unconditionally alive stones, 2 where it has unconditional
 * territory, and 0 otherwise.
 */

void
unconditional_life(int unconditional_territory[BOARDMAX], int color)
{
  int found_one;
  int other = OTHER_COLOR(color);
  int libs[MAXLIBS];
  int liberties;
  int pos;
  int k, r;
  int moves_played;
  int potential_sekis[BOARDMAX];

  /* Find isolated two-stone strings which might be involved in the
   * kind of seki described in the comments.
   */
  memset(potential_sekis, 0, sizeof(potential_sekis));
  for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
    int isolated = 1;
    int stones[2];
    int pos2;
    
    if (board[pos] != color
	|| find_origin(pos) != pos
	|| countstones(pos) != 2)
      continue;
    
    findstones(pos, 2, stones);
    for (k = 0; k < 2 && isolated; k++) {
      for (r = 0; r < 8 && isolated; r++) {
	pos2 = stones[k] + delta[r];
	if (!ON_BOARD(pos2)
	    || (board[pos2] == color
		&& !same_string(pos, pos2)))
	  isolated = 0;
      }
    }

    if (isolated) {
      potential_sekis[stones[0]] = 1;
      potential_sekis[stones[1]] = 1;
    }
  }
  
  moves_played = capture_non_invincible_strings(color, potential_sekis);
  /* The strings still remaining except those marked in
   * potential_sekis[] are uncapturable. Now see which opponent
   * strings can survive.
   *
   * 1. Play opponent stones on all liberties of the unconditionally
   *    alive strings except where illegal.
   */
  for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
    if (board[pos] != color || potential_sekis[pos] || find_origin(pos) != pos)
      continue;
      
    /* Play as many liberties as we can. */
    liberties = findlib(pos, MAXLIBS, libs);
    for (k = 0; k < liberties; k++) {
      if (trymove(libs[k], other, "unconditional_life", pos))
	moves_played++;
    }
  }

  /* 2. Recursively extend opponent strings in atari, except where this
   *    would be suicide.
   */
  found_one = 1;
  while (found_one) {
    /* Nothing found so far in this turn of the loop. */
    found_one = 0;

    for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
      if (board[pos] != other || countlib(pos) > 1)
	continue;
	
      /* Try to extend the string at (m, n). */
      findlib(pos, 1, libs);
      if (trymove(libs[0], other, "unconditional_life", pos)) {
	moves_played++;
	found_one = 1;
      }
    }
  }

  /* Now see whether there are any significant sekis on the board. */
  for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
    if (!potential_sekis[pos]
	|| board[pos] == EMPTY
	|| find_origin(pos) != pos)
      continue;
    for (r = 0; r < 4; r++) {
      int up = delta[r];
      int right = delta[(r + 1) % 4];
      int locally_played_moves = 0;
      if (board[pos + up] != color
	  || board[pos + up + up] != EMPTY
	  || board[pos - up] != EMPTY)
	continue;
      for (k = 0; k < 2; k++) {
	if (k == 1)
	  right = -right;
	if (board[pos + right] != EMPTY || board[pos + up - right] != EMPTY)
	  continue;
	if (board[pos - right] == EMPTY
	    && trymove(pos - right, other, "unconditional_life", pos))
	  locally_played_moves++;
	if (board[pos + up + right] == EMPTY
	    && trymove(pos + up + right, other, "unconditional_life", pos))
	  locally_played_moves++;
	if (board[pos - right] == other && board[pos + up + right] == other
	    && same_string(pos - right, pos + up + right)) {
	  /* This is a critical seki. Extend the string with one stone
           * in an arbitrary direction to break the seki.
	   */
	  while (locally_played_moves > 0) {
	    popgo();
	    locally_played_moves--;
	  }
	  trymove(pos - up, color, "unconditional_life", pos);
	  moves_played++;
	  break;
	}
	else {
	  while (locally_played_moves > 0) {
	    popgo();
	    locally_played_moves--;
	  }
	}
      }
      if (countstones(pos) > 2)
	break;
    }
  }

  /* Capture the strings involved in potential sekis. */
  for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
    if (!potential_sekis[pos] || board[pos] == EMPTY)
      continue;
    /* Play as many liberties as we can. */
    liberties = findlib(pos, MAXLIBS, libs);
    for (k = 0; k < liberties; k++) {
      if (trymove(libs[k], other, "unconditional_life", pos))
	moves_played++;
    }
  }
    

  for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
    int apos;
    int bpos;
    int aopen, bopen;
    int alib, blib;
    if (board[pos] != other || countlib(pos) != 2)
      continue;
    findlib(pos, 2, libs);
    apos = libs[0];
    bpos = libs[1];
    if (abs(I(apos) - I(bpos)) + abs(J(apos) - J(bpos)) != 1)
      continue;
    
    /* Only two liberties and these are adjacent. Play one. We want
     * to maximize the number of open liberties. In this particular
     * situation we can count this with approxlib for the opposite
     * color. If the number of open liberties is the same, we
     * maximize the total number of obtained liberties.
     * Two relevant positions:
     *
     * |XXX. 
     * |OOXX    |XXXXXXX
     * |O.OX    |OOXOOOX
     * |..OX    |..OO.OX
     * +----    +-------
     */
    aopen = approxlib(apos, color, 4, NULL);
    bopen = approxlib(bpos, color, 4, NULL);
    alib  = approxlib(apos, other, 4, NULL);
    blib  = approxlib(bpos, other, 4, NULL);
    
    if (aopen > bopen || (aopen == bopen && alib >= blib)) {
      trymove(apos, other, "unconditional_life", pos);
      moves_played++;
    }
    else {
      trymove(bpos, other, "unconditional_life", pos);
      moves_played++;
    }
  }
  
  /* Identify unconditionally alive stones and unconditional territory. */
  memset(unconditional_territory, 0, sizeof(int) * BOARDMAX);
  for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
    if (board[pos] == color && !potential_sekis[pos]) {
      unconditional_territory[pos] = 1;
      if (find_origin(pos) == pos) {
	liberties = findlib(pos, MAXLIBS, libs);
	for (k = 0; k < liberties; k++)
	  unconditional_territory[libs[k]] = 2;
      }
    }
    else if (board[pos] == other && countlib(pos) == 1) {
      unconditional_territory[pos] = 2;
      findlib(pos, 1, libs);
      unconditional_territory[libs[0]] = 2;
    }
  }
  
  /* Take back all moves. */
  while (moves_played > 0) {
    popgo();
    moves_played--;
  }
}


/* Score the game and determine the winner */

void
who_wins(int color, FILE *outfile)
{
  float result;

  silent_examine_position(EXAMINE_DRAGONS);

#if 0
  float white_score;
  float black_score;
  int winner;
#endif

  if (color != BLACK && color != WHITE)
    color = BLACK;

#if 0
  /* Use the aftermath code to compute the final score. (Slower but
   * more reliable.) 
   */
  result = aftermath_compute_score(color, komi);
  if (result > 0.0)
    winner = WHITE;
  else {
    winner = BLACK;
    result = -result;
  }
#endif

  result = estimate_score(NULL, NULL);
  if (result == 0.0)
    fprintf(outfile, "Result: jigo   ");
  else
    fprintf(outfile, "Result: %c+%.1f   ",
	    (result > 0.0) ? 'W' : 'B', gg_abs(result));
}



/* Find the stones of an extended string, where the extensions are
 * through the following kinds of connections:
 *
 * 1. Solid connections (just like ordinary string).
 *
 *    OO
 *
 * 2. Diagonal connection or one space jump through an intersection
 *    where an opponent move would be suicide or self-atari.
 *
 *    ...
 *    O.O
 *    XOX
 *    X.X
 *
 * 3. Bamboo joint.
 *
 *    OO
 *    ..
 *    OO
 *
 * 4. Diagonal connection where both adjacent intersections are empty.
 *
 *    .O
 *    O.
 *
 * 5. Connection through adjacent or diagonal tactically captured stones.
 *    Connections of this type are omitted when the superstring code is
 *    called from reading.c, but included when the superstring code is
 *    called from owl.c
 */

static void
do_find_superstring(int str, int *num_stones, int *stones,
		    int *num_lib, int *libs, int maxlibs,
		    int *num_adj, int *adjs, int liberty_cap,
		    int proper, int type);

static void
superstring_add_string(int str,
		       int *num_my_stones, int *my_stones,
		       int *num_stones, int *stones,
		       int *num_libs, int *libs, int maxlibs,
		       int *num_adj, int *adjs, int liberty_cap,
		       char mx[BOARDMAX],
		       char ml[BOARDMAX],
		       char ma[BOARDMAX],
		       int do_add);

void
find_superstring(int str, int *num_stones, int *stones)
{
  do_find_superstring(str, num_stones, stones,
		      NULL, NULL, 0,
		      NULL, NULL, 0,
		      0, 1);
}

/* This is the same as find_superstring, except that connections of
 * type 5 are omitted. This is used in semeai analysis.
 */
void
find_superstring_conservative(int str, int *num_stones, int *stones)
{
  do_find_superstring(str, num_stones, stones,
		      NULL, NULL, 0,
		      NULL, NULL, 0,
		      0, 0);
}


/* This function computes the superstring at (str) as described above,
 * but omitting connections of type 5. Then it constructs a list of
 * liberties of the superstring which are not already liberties of
 * (str).
 *
 * If liberty_cap is nonzero, only liberties of substrings of the
 * superstring which have fewer than liberty_cap liberties are
 * generated.
 */

void
find_superstring_liberties(int str,
			   int *num_libs, int *libs, int liberty_cap)
{
  do_find_superstring(str, NULL, NULL,
		      num_libs, libs, MAX_LIBERTIES,
		      NULL, NULL, liberty_cap,
		      0, 0);
}

/* This function is the same as find_superstring_liberties, but it
 * omits those liberties of the string (str), presumably since
 * those have already been treated elsewhere.
 *
 * If liberty_cap is nonzero, only liberties of substrings of the
 * superstring which have at most liberty_cap liberties are
 * generated.
 */

void
find_proper_superstring_liberties(int str, 
				  int *num_libs, int *libs, 
				  int liberty_cap)
{
  do_find_superstring(str, NULL, NULL,
		      num_libs, libs, MAX_LIBERTIES,
		      NULL, NULL, liberty_cap,
		      1, 0);
}

/* This function computes the superstring at (str) as described above,
 * but omitting connections of type 5. Then it constructs a list of
 * liberties of the superstring which are not already liberties of
 * (str).
 *
 * If liberty_cap is nonzero, only liberties of substrings of the
 * superstring which have fewer than liberty_cap liberties are
 * generated.
 */

void
find_superstring_stones_and_liberties(int str,
				      int *num_stones, int *stones,
				      int *num_libs, int *libs,
				      int liberty_cap)
{
  do_find_superstring(str, num_stones, stones,
		      num_libs, libs, MAX_LIBERTIES,
		      NULL, NULL, liberty_cap,
		      0, 0);
}

/* analogous to chainlinks, this function finds boundary chains of the
 * superstring at (str), including those which are boundary chains of
 * (str) itself. If liberty_cap != 0, only those boundary chains with
 * <= liberty_cap liberties are reported.
 */

void
superstring_chainlinks(int str, 
		       int *num_adj, int adjs[MAXCHAIN],
		       int liberty_cap)
{
  do_find_superstring(str, NULL, NULL,
		      NULL, NULL, 0,
		      num_adj, adjs, liberty_cap,
		      0, 2);
}


/* analogous to chainlinks, this function finds boundary chains of the
 * superstring at (str), omitting those which are boundary chains of
 * (str) itself. If liberty_cap != 0, only those boundary chains with
 * <= liberty_cap liberties are reported.
 */

void
proper_superstring_chainlinks(int str,
			      int *num_adj, int adjs[MAXCHAIN],
			      int liberty_cap)
{
  do_find_superstring(str, NULL, NULL,
		      NULL, NULL, 0,
		      num_adj, adjs, liberty_cap,
		      1, 2);
}

/* Do the real work finding the superstring and recording stones,
 * liberties, and/or adjacent strings.
 */
static void
do_find_superstring(int str, int *num_stones, int *stones,
		    int *num_libs, int *libs, int maxlibs,
		    int *num_adj, int *adjs, int liberty_cap,
		    int proper, int type)
{
  int num_my_stones;
  int my_stones[MAX_BOARD * MAX_BOARD];
  
  char mx[BOARDMAX]; /* stones */
  char ml[BOARDMAX]; /* liberties */
  char ma[BOARDMAX]; /* adjacent strings */

  int k, l, r;
  int color = board[str];
  int other = OTHER_COLOR(color);

  memset(mx, 0, sizeof(mx));
  memset(ml, 0, sizeof(ml));
  memset(ma, 0, sizeof(ma));

  if (num_stones)
    *num_stones = 0;
  if (num_libs)
    *num_libs = 0;
  if (num_adj)
    *num_adj = 0;

  /* Include the string itself in the superstring. Only record stones,
   * liberties, and/or adjacent strings if proper==0.
   */
  num_my_stones = 0;
  superstring_add_string(str, &num_my_stones, my_stones,
			 num_stones, stones,
			 num_libs, libs, maxlibs,
			 num_adj, adjs, liberty_cap,
			 mx, ml, ma,
			 !proper);

  /* Loop over all found stones, looking for more strings to include
   * in the superstring. The loop is automatically extended over later
   * found stones as well.
   */
  for (r = 0; r < num_my_stones; r++) {
    int pos = my_stones[r];

    for (k = 0; k < 4; k++) {
      /* List of relative coordinates. (pos) is marked by *.
       *
       *  ef.
       *  gb.
       *  *ac
       *  .d.
       *
       */
      int right = delta[k];
      int up = delta[(k+1)%4];
      
      int apos = pos + right;
      int bpos = pos + right + up;
      int cpos = pos + 2*right;
      int dpos = pos + right - up;
      int epos = pos + 2*up;
      int fpos = pos + right + 2*up;
      int gpos = pos + up;
      int unsafe_move;
      
      if (!ON_BOARD(apos))
	continue;
      
      /* Case 1. Nothing to do since stones are added string by string. */
            
      /* Case 2. */
      if (board[apos] == EMPTY) {
	if (type == 2)
	  unsafe_move = (approxlib(apos, other, 2, NULL) < 2);
	else
	  unsafe_move = is_self_atari(apos, other);
	
	if (unsafe_move && type == 1 && is_ko(apos, other, NULL))
	  unsafe_move = 0;
	
	if (unsafe_move) {
	  if (board[bpos] == color && !mx[bpos])
	    superstring_add_string(bpos, &num_my_stones, my_stones,
				   num_stones, stones,
				   num_libs, libs, maxlibs,
				   num_adj, adjs, liberty_cap,
				   mx, ml, ma, 1);
	  if (board[cpos] == color && !mx[cpos])
	    superstring_add_string(cpos, &num_my_stones, my_stones,
				   num_stones, stones,
				   num_libs, libs, maxlibs,
				   num_adj, adjs, liberty_cap,
				   mx, ml, ma, 1);
	  if (board[dpos] == color && !mx[dpos])
	    superstring_add_string(dpos, &num_my_stones, my_stones,
				   num_stones, stones,
				   num_libs, libs, maxlibs,
				   num_adj, adjs, liberty_cap,
				   mx, ml, ma, 1);
	}
      }
      
      /* Case 3. */
      /* Notice that the order of these tests is significant. We must
       * check bpos before fpos and epos to avoid accessing memory
       * outside the board array. (Notice that fpos is two steps away
       * from pos, which we know is on the board.)
       */
      if (board[apos] == color && board[bpos] == EMPTY
	  && board[fpos] == color && board[epos] == color && !mx[epos]
	  && board[gpos] == EMPTY)
	superstring_add_string(epos, &num_my_stones, my_stones,
			       num_stones, stones,
			       num_libs, libs, maxlibs,
			       num_adj, adjs, liberty_cap,
			       mx, ml, ma, 1);
      /* Don't bother with f, it is part of the string just added. */
      
      /* Case 4. */
      if (board[bpos] == color && !mx[bpos]
	  && board[apos] == EMPTY && board[gpos] == EMPTY)
	superstring_add_string(bpos, &num_my_stones, my_stones,
			       num_stones, stones,
			       num_libs, libs, maxlibs,
			       num_adj, adjs, liberty_cap,
			       mx, ml, ma, 1);
      
      /* Case 5. */
      if (type == 1)
	for (l = 0; l < 2; l++) {
	  int upos;
	  
	  if (l == 0) {
	    /* adjacent lunch */
	    upos = apos;
	  }
	  else {
	    /* diagonal lunch */
	    upos = bpos;
	  }
	  
	  if (board[upos] != other)
	    continue;
	  
	  upos = find_origin(upos);
	  
	  /* Only do the reading once. */
	  if (mx[upos] == 1)
	    continue;
	  
	  mx[upos] = 1;
	  
	  if (attack(upos, NULL)
	      && !find_defense(upos, NULL)) {
	    int lunch_stones[MAX_BOARD*MAX_BOARD];
	    int num_lunch_stones = findstones(upos, MAX_BOARD*MAX_BOARD,
					      lunch_stones);
	    int m, n;
	    for (m = 0; m < num_lunch_stones; m++)
	      for (n = 0; n < 8; n++) {
		int vpos = lunch_stones[m] + delta[n];
		if (board[vpos] == color && !mx[vpos])
		  superstring_add_string(vpos,
					 &num_my_stones, my_stones,
					 num_stones, stones,
					 num_libs, libs, maxlibs,
					 num_adj, adjs, liberty_cap,
					 mx, ml, ma, 1);
	      }
	  }
	}
      if (num_libs && maxlibs > 0 && *num_libs >= maxlibs)
	return;
    }
  }
}

/* Add a new string to a superstring. Record stones, liberties, and
 * adjacent strings as asked for.
 */
static void
superstring_add_string(int str,
		       int *num_my_stones, int *my_stones,
		       int *num_stones, int *stones,
		       int *num_libs, int *libs, int maxlibs,
		       int *num_adj, int *adjs, int liberty_cap,
		       char mx[BOARDMAX],
		       char ml[BOARDMAX],
		       char ma[BOARDMAX],
		       int do_add)
{
  int num_my_libs;
  int my_libs[MAXLIBS];
  int num_my_adj;
  int my_adjs[MAXCHAIN];
  int new_stones;
  int k;
  
  ASSERT1(mx[str] == 0, str);

  /* Pick up the stones of the new string. */
  new_stones = findstones(str, board_size * board_size,
			  &(my_stones[*num_my_stones]));
  
  mark_string(str, mx, 1);
  if (stones) {
    gg_assert(num_stones);
    for (k = 0; k < new_stones; k++) {
      if (do_add) {
	stones[*num_stones] = my_stones[*num_my_stones + k];
	(*num_stones)++;
      }
    }
  }
  (*num_my_stones) += new_stones;

  /* Pick up the liberties of the new string. */
  if (libs) {
    gg_assert(num_libs);
    /* Get the liberties of the string. */
    num_my_libs = findlib(str, MAXLIBS, my_libs);

    /* Remove this string from the superstring if it has too many
     * liberties.
     */
    if (liberty_cap > 0 && num_my_libs > liberty_cap)
      (*num_my_stones) -= new_stones;

    for (k = 0; k < num_my_libs; k++) {
      if (ml[my_libs[k]])
	continue;
      ml[my_libs[k]] = 1;
      if (do_add && (liberty_cap == 0 || num_my_libs <= liberty_cap)) {
	libs[*num_libs] = my_libs[k];
	(*num_libs)++;
	if (*num_libs == maxlibs)
	  break;
      }
    }
  }

  /* Pick up adjacent strings to the new string. */
  if (adjs) {
    gg_assert(num_adj);
    num_my_adj = chainlinks(str, my_adjs);
    for (k = 0; k < num_my_adj; k++) {
      if (liberty_cap > 0 && countlib(my_adjs[k]) > liberty_cap)
	continue;
      if (ma[my_adjs[k]])
	continue;
      ma[my_adjs[k]] = 1;
      if (do_add) {
	adjs[*num_adj] = my_adjs[k];
	(*num_adj)++;
      }
    }
  }
}

/* Internal timers for assessing time spent on various tasks. */
#define NUMBER_OF_TIMERS 4
static double timers[NUMBER_OF_TIMERS];

/* Start a timer. */
void
start_timer(int n)
{
  gg_assert(n >= 0 && n < NUMBER_OF_TIMERS);
  if (!showtime)
    return;

  timers[n] = gg_cputime();
}

/* Report time spent and restart the timer. Make no report if elapsed
 * time is less than mintime.
 */
double
time_report(int n, const char *occupation, int move, double mintime)
{
  double t;
  double dt;
  gg_assert(n >= 0 && n < NUMBER_OF_TIMERS);

  if (!showtime)
    return 0.0;

  t = gg_cputime();
  dt = t - timers[n];
  if (dt > mintime) {
    gprintf("%s", occupation);
    if (move != NO_MOVE)
      gprintf("%1m", move);
    fprintf(stderr, ": %.2f sec\n", dt);
  }
  timers[n] = t;
  return dt;
}

void
clearstats()
{
  stats.nodes                    = 0;
  stats.read_result_entered      = 0;
  stats.read_result_hits         = 0;
  stats.trusted_read_result_hits = 0;
}
  
void
showstats()
{
  gprintf("Nodes:                    %d\n", stats.nodes);
  gprintf("Read results entered:     %d\n", stats.read_result_entered);
  gprintf("Read result hits:         %d\n", stats.read_result_hits);
  gprintf("Trusted read result hits: %d\n", stats.trusted_read_result_hits);
}


/*
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 2
 * End:
 */
