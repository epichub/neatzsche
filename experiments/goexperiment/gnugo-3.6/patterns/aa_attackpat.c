/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h> /* for NULL */
#include "liberty.h"
#include "patterns.h"

static struct patval aa_attackpat0[] = {
  {684,1}
};

static struct patval aa_attackpat1[] = {
  {646,1},	{648,1},	{684,1},	{649,3},
  {645,3}
};

static struct patval aa_attackpat2[] = {
  {685,1},	{720,1},	{684,1},	{723,3},
  {686,3}
};

static struct patval aa_attackpat3[] = {
  {720,1},	{685,1},	{723,3},	{686,3}
};

static struct patval aa_attackpat4[] = {
  {686,1},	{684,1}
};

static struct patval aa_attackpat5[] = {
  {684,1},	{722,1}
};

static struct patval aa_attackpat6[] = {
  {721,1},	{686,1},	{723,1},	{684,1},
  {648,1}
};

static struct patval aa_attackpat7[] = {
  {684,1}
};

static struct patval aa_attackpat8[] = {
  {684,1},	{722,1}
};

static struct patval aa_attackpat9[] = {
  {685,1},	{721,1},	{647,1}
};

static struct patval aa_attackpat10[] = {
  {648,1},	{684,1},	{721,1}
};

static struct patval aa_attackpat11[] = {
  {722,1},	{684,1},	{686,1}
};

static struct patval aa_attackpat12[] = {
  {684,1},	{685,1},	{686,3}
};

static struct patval aa_attackpat13[] = {
  {686,1},	{722,1},	{684,1}
};

static struct patval aa_attackpat14[] = {
  {648,1},	{684,1},	{723,1},	{722,1}
};

static struct patval aa_attackpat15[] = {
  {684,1},	{648,3},	{721,3}
};

static struct patval aa_attackpat16[] = {
  {721,1},	{722,1},	{723,1},	{684,1},
  {685,3}
};

static struct patval aa_attackpat17[] = {
  {721,1},	{647,1},	{685,1}
};

static struct patval aa_attackpat18[] = {
  {648,1},	{723,1},	{649,1}
};

static struct patval aa_attackpat19[] = {
  {684,1},	{611,1},	{685,1}
};

static struct patval aa_attackpat20[] = {
  {722,1},	{684,1}
};

static struct patval aa_attackpat21[] = {
  {649,1},	{723,1},	{647,1},	{611,1},
  {686,1}
};

static struct patval aa_attackpat22[] = {
  {648,1},	{685,1},	{684,1}
};

static struct patval aa_attackpat23[] = {
  {685,1},	{683,1}
};

static struct patval aa_attackpat24[] = {
  {685,1},	{721,1},	{720,1}
};

static struct pattern aa_attackpat[26];

static int
autohelperaa_attackpat0(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A) == 2;
}

static int
autohelperaa_attackpat5(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return accuratelib(move, color, MAX_LIBERTIES, NULL)>3;
}

static int
autohelperaa_attackpat8(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return safe_move(move, color);
}

static int
autohelperaa_attackpat10(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return accuratelib(move, color, MAX_LIBERTIES, NULL)>3;
}

static int
autohelperaa_attackpat11(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(722, trans, move);

  return countlib(A)==2 && accuratelib(move, color, MAX_LIBERTIES, NULL)>3;
}

static int
autohelperaa_attackpat12(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(648, trans, move);

  return countlib(A)==3 && accuratelib(move, color, MAX_LIBERTIES, NULL)>=3;
}

static int
autohelperaa_attackpat13(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return safe_move(move, color) && play_attack_defend2_n(color, 1, 1, move, A, B)&& !play_connect_n(color, 1, 1, move, A, B);
}

static int
autohelperaa_attackpat14(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(685, trans, move);
  A = AFFINE_TRANSFORM(721, trans, move);

  return countlib(A) == 2 && accuratelib(b, OTHER_COLOR(color), MAX_LIBERTIES, NULL) <= 2;
}

static int
autohelperaa_attackpat15(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);

  return countlib(A) == 3;
}

static int
autohelperaa_attackpat16(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);

  return countlib(A)==3 && accuratelib(move, color, MAX_LIBERTIES, NULL)>=2;
}

static int
autohelperaa_attackpat17(int trans, int move, int color, int action)
{
  int a, b, e, C, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);
  e = AFFINE_TRANSFORM(719, trans, move);
  C = AFFINE_TRANSFORM(683, trans, move);
  D = AFFINE_TRANSFORM(757, trans, move);

  return !play_attack_defend_n(color, 1, 1, move, e) && play_attack_defend_n(color, 1, 2, move, a, C) && play_attack_defend_n(color, 1, 2, b, a, D);
}

static int
autohelperaa_attackpat18(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(610, trans, move);

  return countlib(A)==2 && accuratelib(move, color, MAX_LIBERTIES, NULL)>1;
}

static int
autohelperaa_attackpat19(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(758, trans, move);

  return countlib(A)==2 && accuratelib(move, color, MAX_LIBERTIES, NULL)>1;
}

static int
autohelperaa_attackpat20(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(758, trans, move);

  return countlib(A)==2 && accuratelib(move, color, MAX_LIBERTIES, NULL)>2;
}

static int
autohelperaa_attackpat21(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(759, trans, move);

  return countlib(A) <= 4 && play_attack_defend_n(color, 1, 2, move, b, A) && play_attack_defend_n(color, 0, 2, move, NO_MOVE, move);
}

static int
autohelperaa_attackpat22(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(649, trans, move);
  B = AFFINE_TRANSFORM(723, trans, move);

  return countlib(A) == 3 && countlib(B) > 1 && play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperaa_attackpat23(int trans, int move, int color, int action)
{
  int A, B, C;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(646, trans, move);
  C = AFFINE_TRANSFORM(648, trans, move);

  return  countlib(A) == 1 && countlib(B) + countlib(C) <= 6 && !play_attack_defend2_n(color, 0, 1, move, B, C);
}

static int
autohelperaa_attackpat24(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(757, trans, move);
  B = AFFINE_TRANSFORM(722, trans, move);

  return countlib(A)<=3 && countlib(B)<=3 && (play_attack_defend_n(color, 1, 1, move, A) || play_attack_defend_n(color, 1, 1, move, B));
}

static struct pattern aa_attackpat[] = {
  {aa_attackpat0,1,4, "A1",0,0,0,1,0,1,0x0,685,
    { 0x00303000, 0x00f00000, 0x30300000, 0x003c0000, 0x00f00000, 0x30300000, 0x003c0000, 0x00303000},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat0,3,0.010000},
  {aa_attackpat1,5,8, "A2",-1,-2,1,2,2,4,0x2,683,
    { 0xfcfcfc7c, 0xfdffff00, 0xfcfcfcf4, 0xfffffd00, 0xfffffd00, 0xfcfcfc7c, 0xfdffff00, 0xfcfcfcf4},
    { 0x80608000, 0x98200000, 0x08240800, 0x00209800, 0x00209800, 0x80608000, 0x98200000, 0x08240800}
   , 0x0,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {aa_attackpat2,5,8, "A3",-1,0,2,1,3,1,0x2,721,
    { 0x3c3c3c14, 0x00fcfc00, 0xf0f0f000, 0xfdfd0000, 0xfcfc0000, 0x3c3c3c00, 0x00fdfd00, 0xf0f0f050},
    { 0x18202000, 0x00a40800, 0x20209000, 0x80680000, 0x08a40000, 0x20201800, 0x00688000, 0x90202000}
   , 0x0,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {aa_attackpat3,4,8, "A4",-1,0,2,1,3,1,0x2,721,
    { 0x0c3c3c14, 0x00f0fc00, 0xf0f0c000, 0xfd3d0000, 0xfcf00000, 0x3c3c0c00, 0x003dfd00, 0xc0f0f050},
    { 0x08102000, 0x00900800, 0x20108000, 0x80180000, 0x08900000, 0x20100800, 0x00188000, 0x80102000}
   , 0x0,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {aa_attackpat4,2,4, "A5",-1,0,1,2,2,2,0x2,685,
    { 0x00f0fcf0, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0x003cfc3c},
    { 0x00200420, 0x00204000, 0x40200000, 0x04220000, 0x40200000, 0x04200000, 0x00220400, 0x00204020}
   , 0x0,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {aa_attackpat5,2,8, "A6",-1,-1,0,1,1,2,0x0,720,
    { 0x2c3c3c00, 0x00f8fc00, 0xf0f0e000, 0xfcbc0000, 0xfcf80000, 0x3c3c2c00, 0x00bcfc00, 0xe0f0f000},
    { 0x00201800, 0x00608000, 0x90200000, 0x08240000, 0x80600000, 0x18200000, 0x00240800, 0x00209000}
   , 0x100,0.000000,NULL,1,NULL,autohelperaa_attackpat5,3,0.050000},
  {aa_attackpat6,5,4, "A7",-1,0,1,2,2,2,0x0,685,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00688068, 0x90202000, 0x08a40000, 0x22221900, 0x20209000, 0x80680000, 0x19222200, 0x00a408a4}
   , 0x10,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {aa_attackpat7,1,8, "A8",-1,-1,1,1,2,2,0x0,685,
    { 0x0c3cfc00, 0xc0f0fc00, 0xfcf0c000, 0xfc3c0c00, 0xfcf0c000, 0xfc3c0c00, 0x0c3cfc00, 0xc0f0fc00},
    { 0x04204000, 0x40200400, 0x04204000, 0x40200400, 0x04204000, 0x40200400, 0x04204000, 0x40200400}
   , 0x100,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {aa_attackpat8,2,4, "A9",0,0,1,1,1,1,0x0,721,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00201800, 0x00608000, 0x90200000, 0x08240000, 0x80600000, 0x18200000, 0x00240800, 0x00209000}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat8,3,1.000000},
  {aa_attackpat9,3,4, "A10",-1,-1,1,1,2,2,0x0,683,
    { 0xfcfc3000, 0x3cfc3c00, 0x30fcfc00, 0xf0fcf000, 0x3cfc3c00, 0x30fcfc00, 0xf0fcf000, 0xfcfc3000},
    { 0x00982000, 0x20902000, 0x20980000, 0x20182000, 0x20902000, 0x20980000, 0x20182000, 0x00982000}
   , 0x0,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {aa_attackpat10,3,8, "A11",-1,-2,1,0,2,2,0x0,723,
    { 0x00fcfc0c, 0xf0f0f000, 0xfcfc0000, 0x3f3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3f00, 0x00fcfcc0},
    { 0x00688000, 0x90202000, 0x08a40000, 0x20201800, 0x20209000, 0x80680000, 0x18202000, 0x00a40800}
   , 0x100,0.000000,NULL,1,NULL,autohelperaa_attackpat10,3,0.050000},
  {aa_attackpat11,3,8, "A12",0,-1,2,1,2,2,0x2,648,
    { 0x00f0fcf0, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0x003cfc3c},
    { 0x00200820, 0x00208000, 0x80200000, 0x08220000, 0x80200000, 0x08200000, 0x00220800, 0x00208020}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat11,3,0.040000},
  {aa_attackpat12,3,8, "A13",-1,-1,2,0,3,1,0x2,720,
    { 0x3c3c3c1c, 0x00fcfc00, 0xf0f0f000, 0xfffd0000, 0xfcfc0000, 0x3c3c3c00, 0x00fdff00, 0xf0f0f0d0},
    { 0x10202000, 0x00a40000, 0x20201000, 0x00680000, 0x00a40000, 0x20201000, 0x00680000, 0x10202000}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat12,3,0.040000},
  {aa_attackpat13,3,4, "A14",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00204820, 0x40208000, 0x84200000, 0x08220400, 0x80204000, 0x48200000, 0x04220800, 0x00208420}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat13,3,6.400001},
  {aa_attackpat14,4,8, "A15",-1,0,1,2,2,2,0x0,685,
    { 0x0030fc3c, 0xc0f0c000, 0xfc300000, 0x0f3f0c00, 0xc0f0c000, 0xfc300000, 0x0c3f0f00, 0x0030fcf0},
    { 0x00208808, 0x80208000, 0x88200000, 0x0a200800, 0x80208000, 0x88200000, 0x08200a00, 0x00208880}
   , 0x10,0.000000,NULL,1,NULL,autohelperaa_attackpat14,3,0.040000},
  {aa_attackpat15,3,8, "A16",-1,0,1,1,2,1,0x2,647,
    { 0x00f47c00, 0x70f0d000, 0xf47c0000, 0x1c3c3400, 0xd0f07000, 0x7cf40000, 0x343c1c00, 0x007cf400},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat15,3,0.010000},
  {aa_attackpat16,5,8, "A17",-1,-2,2,1,3,3,0x2,647,
    { 0xc0fcdcfc, 0xfc70f000, 0xdffe0c00, 0x3f37ff2f, 0xf070fce0, 0xdcfcc000, 0xff373f00, 0x0cfedfff},
    { 0x40280808, 0x0420a000, 0x80a00400, 0x2a204000, 0xa0200400, 0x08284000, 0x40202a00, 0x04a08080}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat16,3,0.040000},
  {aa_attackpat17,3,8, "A18",-2,-1,2,2,4,3,0x0,648,
    { 0x30fcfffc, 0xf0fcf0c0, 0xfffc3000, 0x3fff3f0c, 0xf0fcf0c0, 0xfffc3000, 0x3fff3f0c, 0x30fcfffc},
    { 0x10982000, 0x20942000, 0x20981000, 0x20582000, 0x20942000, 0x20981000, 0x20582000, 0x10982000}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat17,0,1.960000},
  {aa_attackpat18,3,8, "A19",-1,0,1,2,2,2,0x0,722,
    { 0x0030fcfc, 0xc0f0c000, 0xfc300000, 0x0f3f0f00, 0xc0f0c000, 0xfc300000, 0x0f3f0f00, 0x0030fcfc},
    { 0x00108088, 0x80100000, 0x08100000, 0x02100a00, 0x00108000, 0x80100000, 0x0a100200, 0x00100888}
   , 0x100,0.000000,NULL,1,NULL,autohelperaa_attackpat18,0,0.040000},
  {aa_attackpat19,3,8, "A20",-2,0,0,1,2,1,0x8,610,
    { 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0x003f3f00},
    { 0x00202000, 0x00a00000, 0x22200000, 0x00280008, 0x00a00080, 0x20200000, 0x00280000, 0x00202200}
   , 0x100,0.000000,NULL,1,NULL,autohelperaa_attackpat19,3,0.040000},
  {aa_attackpat20,2,8, "A21",0,-1,1,1,1,2,0x2,648,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00240800, 0x00209000, 0x80600000, 0x18200000, 0x90200000, 0x08240000, 0x00201800, 0x00608000}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat20,3,0.040000},
  {aa_attackpat21,5,8, "A22",-1,0,2,2,3,2,0x0,648,
    { 0x00f0fcfc, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0c, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0x003cfffc},
    { 0x009000a8, 0x20100000, 0x02180000, 0x02122208, 0x00102080, 0x00900000, 0x22120200, 0x001802a8}
   , 0x10,0.000000,NULL,1,NULL,autohelperaa_attackpat21,0,0.970000},
  {aa_attackpat22,3,8, "A23",-1,-1,1,1,2,2,0x0,683,
    { 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00},
    { 0x0020a400, 0x80a04000, 0x68200000, 0x04280800, 0x40a08000, 0xa4200000, 0x08280400, 0x00206800}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat22,3,0.376000},
  {aa_attackpat23,2,4, "A24",-1,-1,0,1,1,2,0x0,721,
    { 0x303c3000, 0x00fc3000, 0x30f03000, 0x30fc0000, 0x30fc0000, 0x303c3000, 0x00fc3000, 0x30f03000},
    { 0x20102000, 0x00980000, 0x20102000, 0x00980000, 0x00980000, 0x20102000, 0x00980000, 0x20102000}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat23,0,0.667600},
  {aa_attackpat24,3,8, "A25",-1,-1,1,1,2,2,0x0,647,
    { 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00},
    { 0x08182400, 0x00906800, 0x60908000, 0xa4180000, 0x68900000, 0x24180800, 0x0018a400, 0x80906000}
   , 0x0,0.000000,NULL,1,NULL,autohelperaa_attackpat24,0,0.592000},
  {NULL, 0,0,NULL,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},0,0.0,NULL,0,NULL,NULL,0,0.0}
};

#include "dfa-mkpat.h"
static const state_rt_t state_aa_attackpat[310] = {
{0,{0,0,0,0}},	{0,{0,1,2,0}},	{0,{2,0,3,0}},
{0,{3,4,5,0}},	{0,{5,5,5,0}},	{0,{5,0,6,0}},
{8,{6,7,8,0}},	{0,{8,0,0,0}},	{0,{8,9,10,9}},
{0,{10,10,10,10}},	{0,{10,10,11,0}},	{0,{11,12,0,0}},
{0,{12,13,13,14}},	{0,{14,14,14,14}},	{0,{14,14,14,15}},
{0,{15,15,16,16}},	{0,{16,17,0,18}},	{0,{0,0,0,17}},
{0,{17,17,17,16}},	{0,{17,17,18,0}},	{0,{18,18,18,18}},
{4,{17,17,17,17}},	{0,{17,0,18,0}},	{0,{0,0,18,0}},
{0,{18,19,20,0}},	{0,{17,19,19,0}},	{0,{19,20,20,0}},
{0,{20,21,21,0}},	{0,{21,22,20,0}},	{0,{22,21,19,0}},
{0,{22,22,22,22}},	{0,{22,22,22,22}},	{0,{22,0,0,0}},
{0,{22,22,22,22}},	{0,{22,0,0,0}},	{0,{22,0,0,0}},
{0,{22,0,0,0}},	{0,{21,0,22,0}},	{0,{22,0,22,0}},
{0,{22,22,22,22}},	{0,{22,22,22,22}},	{0,{22,0,0,0}},
{0,{22,23,24,23}},	{0,{24,25,26,25}},	{0,{26,24,25,24}},
{0,{26,27,28,27}},	{0,{28,0,29,0}},	{0,{27,0,29,30}},
{0,{26,0,0,0}},	{0,{29,23,30,23}},	{0,{30,31,32,0}},
{0,{20,21,28,21}},	{0,{31,31,31,31}},	{0,{31,31,31,31}},
{0,{31,31,31,31}},	{0,{31,0,31,0}},	{0,{31,31,31,31}},
{0,{31,0,0,0}},	{0,{31,0,0,0}},	{0,{31,0,0,0}},
{0,{31,0,0,0}},	{0,{0,31,0,0}},	{0,{31,31,31,31}},
{0,{31,0,0,0}},	{0,{31,0,32,0}},	{0,{30,0,0,0}},
{0,{29,31,32,0}},	{0,{32,0,29,0}},	{0,{32,0,0,0}},
{0,{31,0,32,0}},	{0,{30,0,26,0}},	{0,{31,0,25,0}},
{0,{30,0,0,0}},	{0,{29,24,25,0}},	{0,{0,0,22,0}},
{0,{0,0,26,0}},	{0,{0,21,27,0}},	{0,{0,0,27,0}},
{0,{24,0,27,0}},	{0,{23,18,24,0}},	{0,{26,0,16,0}},
{0,{25,0,0,0}},	{0,{25,0,0,0}},	{0,{0,0,25,0}},
{0,{0,0,25,0}},	{0,{0,25,0,0}},	{0,{25,0,0,0}},
{0,{25,25,25,25}},	{0,{0,0,25,0}},	{0,{0,0,25,0}},
{0,{25,0,0,0}},	{0,{25,25,25,25}},	{0,{25,0,0,0}},
{0,{25,25,25,25}},	{0,{25,0,0,0}},	{0,{25,26,25,0}},
{0,{0,0,26,0}},	{0,{26,0,0,0}},	{0,{26,27,0,0}},
{0,{0,22,27,0}},	{0,{0,21,0,0}},	{0,{0,24,0,0}},
{0,{18,0,18,0}},	{0,{21,0,0,0}},	{0,{23,0,0,0}},
{0,{23,0,17,0}},	{0,{0,0,23,0}},	{0,{0,0,23,0}},
{20,{23,23,23,23}},	{20,{0,0,0,0}},	{0,{0,0,22,0}},
{0,{22,22,22,22}},	{0,{22,0,0,0}},	{0,{15,0,0,0}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,0}},
{0,{0,0,0,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{0,0,0,21}},	{16,{0,0,0,0}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{0,0,20,0}},
{0,{0,0,20,0}},	{0,{20,0,0,0}},	{0,{20,20,20,0}},
{9,{0,0,0,0}},	{0,{0,19,0,0}},	{0,{19,19,19,19}},
{0,{19,19,19,19}},	{0,{19,19,19,19}},	{0,{19,19,19,19}},
{0,{19,0,0,0}},	{0,{19,19,19,0}},	{0,{19,19,19,19}},
{0,{19,19,19,19}},	{0,{19,0,0,0}},	{0,{19,0,0,0}},
{0,{19,0,20,0}},	{0,{0,0,0,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,0,0,0}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{21,{0,0,0,0}},
{0,{19,19,19,19}},	{0,{19,19,19,19}},	{0,{19,19,19,19}},
{0,{0,0,0,19}},	{0,{19,19,19,19}},	{0,{19,19,19,19}},
{0,{19,19,19,19}},	{0,{19,0,0,0}},	{0,{19,0,0,0}},
{0,{19,19,19,0}},	{0,{19,19,19,0}},	{0,{19,19,19,19}},
{0,{19,19,19,19}},	{0,{19,19,19,19}},	{0,{19,19,19,19}},
{0,{0,0,19,0}},	{0,{0,19,0,0}},	{0,{19,19,19,19}},
{0,{19,19,19,19}},	{0,{19,0,0,0}},	{0,{19,19,19,19}},
{0,{19,19,19,19}},	{0,{0,0,0,19}},	{0,{19,19,19,19}},
{0,{19,19,19,0}},	{0,{19,19,19,19}},	{5,{0,0,0,0}},
{6,{0,0,0,0}},	{0,{17,17,17,0}},	{10,{0,0,0,0}},
{0,{16,16,16,16}},	{0,{0,0,0,16}},	{0,{16,16,16,16}},
{0,{16,16,16,16}},	{0,{16,16,16,16}},	{0,{16,16,0,0}},
{0,{16,16,16,16}},	{0,{16,16,16,16}},	{22,{0,0,0,0}},
{0,{15,15,15,15}},	{0,{15,15,15,15}},	{0,{15,0,0,0}},
{0,{15,15,15,15}},	{0,{15,15,15,15}},	{0,{0,0,0,15}},
{0,{15,15,15,15}},	{0,{15,15,15,15}},	{0,{15,15,15,15}},
{0,{0,0,0,15}},	{0,{15,15,15,15}},	{0,{15,15,15,15}},
{0,{0,0,0,15}},	{0,{15,15,15,15}},	{0,{15,15,15,15}},
{0,{0,0,0,15}},	{0,{0,0,0,15}},	{0,{15,15,15,15}},
{0,{0,0,15,0}},	{0,{0,0,15,0}},	{0,{15,0,15,0}},
{0,{15,0,0,0}},	{0,{0,0,15,0}},	{0,{15,15,15,15}},
{0,{15,15,15,0}},	{0,{15,0,0,0}},	{0,{15,0,0,0}},
{0,{0,0,15,0}},	{0,{15,0,0,0}},	{0,{14,0,15,0}},
{0,{15,0,0,0}},	{0,{15,0,15,0}},	{0,{15,15,15,15}},
{0,{0,0,15,0}},	{0,{0,0,15,0}},	{3,{0,0,0,0}},
{0,{14,0,0,0}},	{11,{0,0,0,0}},	{0,{13,0,0,0}},
{0,{13,0,0,0}},	{0,{13,13,13,0}},	{0,{13,0,13,0}},
{0,{13,0,0,0}},	{0,{13,13,13,0}},	{0,{0,13,0,0}},
{23,{0,0,0,0}},	{24,{0,0,0,0}},	{0,{11,11,11,11}},
{1,{0,0,0,0}},	{0,{10,10,10,10}},	{0,{10,0,0,0}},
{0,{10,10,10,10}},	{13,{0,0,0,0}},	{14,{0,0,0,0}},
{0,{0,0,0,8}},	{0,{8,8,8,8}},	{18,{0,0,0,0}},
{19,{0,0,0,0}},	{0,{6,6,6,6}},	{0,{0,0,6,0}},
{0,{6,0,0,0}},	{0,{0,0,0,6}},	{0,{6,6,6,6}},
{0,{6,0,0,0}},	{0,{0,0,6,0}},	{2,{0,0,0,0}},
{0,{5,5,5,5}},	{0,{5,5,5,5}},	{0,{0,0,0,5}},
{0,{5,5,5,5}},	{0,{5,5,5,5}},	{0,{5,5,5,0}},
{0,{5,5,5,5}},	{0,{0,0,0,5}},	{0,{5,5,5,5}},
{0,{0,0,0,5}},	{7,{0,0,0,0}},	{0,{4,4,4,4}},
{0,{4,0,0,0}},	{0,{4,4,4,4}},	{0,{0,0,0,4}},
{0,{4,4,4,4}},	{0,{4,4,4,4}},	{0,{4,4,4,4}},
{25,{0,0,0,0}},	{0,{3,3,3,3}},	{0,{3,0,3,0}},
{0,{3,3,3,3}},	{0,{0,0,0,3}},	{15,{0,0,0,0}},
{0,{2,2,2,0}},	{0,{0,0,0,2}},	{0,{2,2,2,2}},
{12,{0,0,0,0}},	{0,{0,0,0,1}},	{0,{0,0,0,1}},
{0,{0,0,0,1}},	{0,{1,1,1,1}},	{0,{1,0,0,0}},
{17,{0,0,0,0}},	};

static const attrib_rt_t idx_aa_attackpat[26] = {
{-1,0},	{18,0},	{21,0},	{3,0},
{23,0},	{24,0},	{9,0},	{17,0},
{0,0},	{15,0},	{7,0},	{14,0},
{4,0},	{11,0},	{13,0},	{1,0},
{20,0},	{16,0},	{10,0},	{6,0},
{8,0},	{5,0},	{22,0},	{12,0},
{2,0},	{19,0},	};

static dfa_rt_t dfa_aa_attackpat = {
 "aa_attackpat",
state_aa_attackpat,
idx_aa_attackpat};

struct pattern_db aa_attackpat_db = {
  -1,
  0,
  aa_attackpat
 ,& dfa_aa_attackpat
};
