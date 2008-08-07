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

static struct patval owl_attackpat0[] = {
  {758,1},	{721,1},	{757,3}
};

static struct patval owl_attackpat1[] = {
  {719,1},	{721,1},	{757,3}
};

static struct patval owl_attackpat2[] = {
  {685,1},	{684,1}
};

static struct patval owl_attackpat3[] = {
  {684,1}
};

static struct patval owl_attackpat4[] = {
  {685,1},	{647,1},	{610,1}
};

static struct patval owl_attackpat5[] = {
  {722,1},	{685,1},	{719,3},	{682,3}
};

static struct patval owl_attackpat6[] = {
  {647,1},	{685,1}
};

static struct patval owl_attackpat7[] = {
  {609,1},	{684,1},	{646,3}
};

static struct patval owl_attackpat8[] = {
  {609,1},	{682,1},	{684,1}
};

static struct patval owl_attackpat9[] = {
  {684,1}
};

static struct patval owl_attackpat10[] = {
  {684,1},	{646,3},	{683,3}
};

static struct patval owl_attackpat11[] = {
  {684,1}
};

static struct patval owl_attackpat12[] = {
  {685,1},	{648,1},	{647,1}
};

static struct patval owl_attackpat13[] = {
  {684,1},	{721,3}
};

static struct patval owl_attackpat14[] = {
  {685,1},	{684,1}
};

static struct patval owl_attackpat15[] = {
  {648,1},	{758,1},	{759,3}
};

static struct patval owl_attackpat16[] = {
  {687,1},	{684,1}
};

static struct patval owl_attackpat17[] = {
  {722,1},	{684,1}
};

static struct patval owl_attackpat18[] = {
  {721,1},	{685,1},	{648,1},	{758,1}
};

static struct patval owl_attackpat19[] = {
  {684,1},	{648,1},	{647,3},	{758,3}
};

static struct patval owl_attackpat20[] = {
  {722,1}
};

static struct patval owl_attackpat21[] = {
  {684,1},	{685,1}
};

static struct patval owl_attackpat22[] = {
  {684,1},	{721,1}
};

static struct patval owl_attackpat23[] = {
  {685,1},	{721,1}
};

static struct patval owl_attackpat24[] = {
  {685,1},	{647,1}
};

static struct patval owl_attackpat25[] = {
  {758,1}
};

static struct patval owl_attackpat26[] = {
  {684,1},	{648,3},	{647,3}
};

static struct patval owl_attackpat27[] = {
  {684,1},	{648,3},	{647,3},	{610,3},
  {611,3}
};

static struct patval owl_attackpat28[] = {
  {684,1},	{796,1},	{647,3},	{610,3},
  {648,3},	{611,3}
};

static struct patval owl_attackpat29[] = {
  {684,1},	{721,1}
};

static struct patval owl_attackpat30[] = {
  {684,1}
};

static struct patval owl_attackpat31[] = {
  {648,1},	{723,1},	{686,1},	{649,3}
};

static struct patval owl_attackpat32[] = {
  {684,1},	{721,1}
};

static struct patval owl_attackpat33[] = {
  {684,1},	{648,3},	{647,3}
};

static struct patval owl_attackpat34[] = {
  {684,1},	{647,3},	{794,3},	{648,3},
  {795,3}
};

static struct patval owl_attackpat35[] = {
  {759,1}
};

static struct patval owl_attackpat36[] = {
  {683,1},	{647,1},	{646,3}
};

static struct patval owl_attackpat37[] = {
  {685,1},	{686,1},	{646,3},	{723,3}
};

static struct patval owl_attackpat38[] = {
  {684,1},	{647,1}
};

static struct patval owl_attackpat39[] = {
  {684,1},	{647,1}
};

static struct patval owl_attackpat40[] = {
  {758,1},	{721,1}
};

static struct patval owl_attackpat41[] = {
  {758,1},	{721,1}
};

static struct patval owl_attackpat42[] = {
  {758,1},	{721,1}
};

static struct patval owl_attackpat43[] = {
  {758,1},	{721,1}
};

static struct patval owl_attackpat44[] = {
  {685,1},	{647,1}
};

static struct patval owl_attackpat45[] = {
  {684,1},	{720,3},	{683,3},	{647,3}
};

static struct patval owl_attackpat46[] = {
  {684,1},	{720,3},	{683,3},	{647,3}
};

static struct patval owl_attackpat47[] = {
  {648,1},	{684,1},	{610,1}
};

static struct patval owl_attackpat48[] = {
  {758,1}
};

static struct patval owl_attackpat49[] = {
  {685,1},	{648,1}
};

static struct patval owl_attackpat50[] = {
  {759,1},	{721,1},	{760,3}
};

static struct patval owl_attackpat51[] = {
  {759,1},	{721,1},	{760,3}
};

static struct patval owl_attackpat52[] = {
  {646,1},	{611,1},	{647,1},	{685,1},
  {757,3},	{720,3}
};

static struct patval owl_attackpat53[] = {
  {686,1},	{722,1},	{723,3},	{610,3}
};

static struct patval owl_attackpat54[] = {
  {721,1}
};

static struct patval owl_attackpat55[] = {
  {685,1},	{721,1},	{644,3},	{681,3},
  {645,3}
};

static struct patval owl_attackpat56[] = {
  {721,1},	{649,3},	{650,3},	{648,3}
};

static struct patval owl_attackpat57[] = {
  {721,1},	{649,3},	{648,3}
};

static struct patval owl_attackpat58[] = {
  {648,1},	{721,1}
};

static struct patval owl_attackpat59[] = {
  {759,1}
};

static struct patval owl_attackpat60[] = {
  {650,1}
};

static struct patval owl_attackpat61[] = {
  {648,1}
};

static struct patval owl_attackpat62[] = {
  {684,1}
};

static struct patval owl_attackpat63[] = {
  {723,1}
};

static struct patval owl_attackpat64[] = {
  {684,1},	{722,1},	{721,3}
};

static struct patval owl_attackpat65[] = {
  {685,1},	{722,1},	{684,1},	{720,3}
};

static struct patval owl_attackpat66[] = {
  {684,1},	{685,1},	{683,3},	{686,3}
};

static struct patval owl_attackpat67[] = {
  {684,1},	{648,1},	{647,3}
};

static struct patval owl_attackpat68[] = {
  {760,1},	{686,1},	{723,3}
};

static struct patval owl_attackpat69[] = {
  {684,1}
};

static struct patval owl_attackpat70[] = {
  {720,1},	{684,1}
};

static struct patval owl_attackpat71[] = {
  {684,1}
};

static struct patval owl_attackpat72[] = {
  {721,1},	{720,3}
};

static struct patval owl_attackpat73[] = {
  {647,1},	{648,1},	{758,1}
};

static struct patval owl_attackpat74[] = {
  {684,1},	{722,1},	{720,1},	{611,3},
  {758,3}
};

static struct patval owl_attackpat75[] = {
  {684,1},	{721,3},	{758,3},	{648,3},
  {647,3}
};

static struct patval owl_attackpat76[] = {
  {684,1}
};

static struct patval owl_attackpat77[] = {
  {684,1}
};

static struct patval owl_attackpat78[] = {
  {684,1}
};

static struct patval owl_attackpat79[] = {
  {648,1},	{649,1}
};

static struct patval owl_attackpat80[] = {
  {648,1},	{649,1}
};

static struct patval owl_attackpat81[] = {
  {686,1},	{722,1},	{684,1},	{723,3},
  {721,3}
};

static struct patval owl_attackpat82[] = {
  {722,1},	{611,3},	{610,3},	{612,3}
};

static struct patval owl_attackpat83[] = {
  {722,1},	{611,3},	{612,3},	{610,3}
};

static struct patval owl_attackpat84[] = {
  {648,1},	{759,3},	{758,3}
};

static struct patval owl_attackpat85[] = {
  {684,1},	{648,1}
};

static struct patval owl_attackpat86[] = {
  {684,1},	{720,1}
};

static struct patval owl_attackpat87[] = {
  {684,1}
};

static struct patval owl_attackpat88[] = {
  {720,1},	{684,1},	{610,3},	{612,3},
  {611,3}
};

static struct patval owl_attackpat89[] = {
  {684,1},	{685,1},	{719,3},	{645,3},
  {682,3}
};

static struct patval owl_attackpat90[] = {
  {684,1}
};

static struct patval owl_attackpat91[] = {
  {684,1}
};

static struct patval owl_attackpat92[] = {
  {684,1}
};

static struct patval owl_attackpat93[] = {
  {684,1},	{688,3},	{651,3},	{725,3}
};

static struct patval owl_attackpat94[] = {
  {684,1}
};

static struct patval owl_attackpat95[] = {
  {684,1},	{723,1}
};

static struct patval owl_attackpat96[] = {
  {686,1},	{684,1},	{723,3}
};

static struct patval owl_attackpat97[] = {
  {684,1},	{687,3},	{650,3},	{724,3},
  {761,3}
};

static struct patval owl_attackpat98[] = {
  {721,1},	{685,1},	{722,3}
};

static struct patval owl_attackpat99[] = {
  {684,1},	{723,1}
};

static struct patval owl_attackpat100[] = {
  {684,1},	{723,1}
};

static struct patval owl_attackpat101[] = {
  {647,1},	{684,1},	{757,3},	{758,3},
  {760,3},	{759,3}
};

static struct patval owl_attackpat102[] = {
  {759,1},	{648,3},	{649,3}
};

static struct patval owl_attackpat103[] = {
  {648,1},	{759,1},	{686,3}
};

static struct patval owl_attackpat104[] = {
  {648,1},	{759,1},	{686,3}
};

static struct patval owl_attackpat105[] = {
  {721,1},	{684,1},	{687,1}
};

static struct patval owl_attackpat106[] = {
  {721,1},	{684,1},	{687,1}
};

static struct patval owl_attackpat107[] = {
  {720,1},	{683,1},	{685,1},	{722,1}
};

static struct patval owl_attackpat108[] = {
  {758,1},	{686,1}
};

static struct patval owl_attackpat109[] = {
  {684,1},	{758,3}
};

static struct patval owl_attackpat110[] = {
  {648,1},	{723,1},	{721,1},	{686,1}
};

static struct patval owl_attackpat111[] = {
  {648,1},	{649,1},	{684,1},	{723,1},
  {721,1}
};

static struct patval owl_attackpat112[] = {
  {720,1},	{683,1},	{646,1},	{758,1},
  {759,1},	{685,1}
};

static struct patval owl_attackpat113[] = {
  {684,1},	{722,1}
};

static struct patval owl_attackpat114[] = {
  {758,1},	{721,1}
};

static struct patval owl_attackpat115[] = {
  {648,1},	{649,1}
};

static struct patval owl_attackpat116[] = {
  {686,1},	{684,1}
};

static struct patval owl_attackpat117[] = {
  {611,1},	{684,1},	{647,3},	{612,3}
};

static struct patval owl_attackpat118[] = {
  {721,1},	{686,1},	{684,1},	{647,3},
  {649,3}
};

static struct patval owl_attackpat119[] = {
  {683,1},	{646,1},	{647,1},	{649,1}
};

static struct patval owl_attackpat120[] = {
  {684,1},	{758,3},	{760,3},	{759,3}
};

static struct patval owl_attackpat121[] = {
  {684,1},	{720,1},	{683,3}
};

static struct patval owl_attackpat122[] = {
  {684,1}
};

static struct patval owl_attackpat123[] = {
  {646,1},	{685,1},	{684,1},	{720,3}
};

static struct patval owl_attackpat124[] = {
  {758,1},	{721,1},	{684,1},	{759,1}
};

static struct patval owl_attackpat125[] = {
  {720,1},	{758,1},	{683,1}
};

static struct patval owl_attackpat126[] = {
  {758,1},	{683,1},	{720,1},	{796,1},
  {757,3},	{794,3}
};

static struct patval owl_attackpat127[] = {
  {647,1},	{684,1},	{648,1},	{683,3},
  {720,3}
};

static struct patval owl_attackpat128[] = {
  {648,1},	{684,1},	{650,3},	{649,3}
};

static struct patval owl_attackpat129[] = {
  {684,1}
};

static struct patval owl_attackpat130[] = {
  {684,1},	{721,1},	{759,3},	{758,3}
};

static struct patval owl_attackpat131[] = {
  {684,1},	{758,3},	{647,3}
};

static struct patval owl_attackpat132[] = {
  {721,1},	{684,1}
};

static struct patval owl_attackpat133[] = {
  {684,1}
};

static struct patval owl_attackpat134[] = {
  {758,1},	{684,1},	{721,3},	{759,3}
};

static struct patval owl_attackpat135[] = {
  {721,1},	{684,1}
};

static struct patval owl_attackpat136[] = {
  {684,1}
};

static struct patval owl_attackpat137[] = {
  {684,1},	{721,3}
};

static struct patval owl_attackpat138[] = {
  {684,1},	{721,1}
};

static struct patval owl_attackpat139[] = {
  {684,1},	{721,3}
};

static struct patval owl_attackpat140[] = {
  {647,1},	{721,1}
};

static struct patval owl_attackpat141[] = {
  {758,1},	{684,1}
};

static struct patval owl_attackpat142[] = {
  {758,1},	{684,1},	{647,1},	{720,3}
};

static struct patval owl_attackpat143[] = {
  {685,1},	{684,1},	{720,1},	{758,1}
};

static struct patval owl_attackpat144[] = {
  {757,1},	{684,1},	{683,1}
};

static struct patval owl_attackpat145[] = {
  {649,1},	{648,1},	{684,1},	{723,1}
};

static struct patval owl_attackpat146[] = {
  {721,1},	{647,1},	{684,1}
};

static struct patval owl_attackpat147[] = {
  {646,1},	{684,1},	{720,3},	{757,3}
};

static struct patval owl_attackpat148[] = {
  {686,1},	{720,1},	{684,1},	{685,1},
  {758,1}
};

static struct patval owl_attackpat149[] = {
  {648,1},	{647,1},	{722,1},	{685,1},
  {683,1}
};

static struct patval owl_attackpat150[] = {
  {684,1}
};

static struct patval owl_attackpat151[] = {
  {684,1},	{722,3}
};

static struct patval owl_attackpat152[] = {
  {721,1},	{759,1}
};

static struct patval owl_attackpat153[] = {
  {648,1},	{684,1},	{647,3}
};

static struct patval owl_attackpat154[] = {
  {684,1},	{647,3}
};

static struct patval owl_attackpat155[] = {
  {722,1},	{684,1},	{758,1},	{757,3}
};

static struct patval owl_attackpat156[] = {
  {722,1},	{684,1},	{758,1},	{682,3}
};

static struct patval owl_attackpat157[] = {
  {684,1},	{685,1},	{723,1},	{760,3}
};

static struct patval owl_attackpat158[] = {
  {686,1},	{722,1},	{684,1}
};

static struct patval owl_attackpat159[] = {
  {686,1},	{684,1}
};

static struct patval owl_attackpat160[] = {
  {722,1},	{684,1},	{686,1}
};

static struct patval owl_attackpat161[] = {
  {722,1},	{684,1},	{686,1}
};

static struct patval owl_attackpat162[] = {
  {684,1},	{722,1},	{648,3},	{686,3}
};

static struct patval owl_attackpat163[] = {
  {684,1},	{722,1},	{648,3},	{721,3}
};

static struct patval owl_attackpat164[] = {
  {684,1},	{722,1},	{648,3},	{686,3}
};

static struct patval owl_attackpat165[] = {
  {684,1},	{722,1},	{723,1},	{650,1},
  {687,1},	{721,3}
};

static struct patval owl_attackpat166[] = {
  {684,1},	{721,1},	{760,1},	{759,1}
};

static struct patval owl_attackpat167[] = {
  {686,1},	{723,1},	{684,1},	{721,1},
  {760,3},	{758,3}
};

static struct patval owl_attackpat168[] = {
  {684,1},	{685,1},	{757,1},	{795,1},
  {723,1},	{797,3},	{760,3}
};

static struct patval owl_attackpat169[] = {
  {686,1},	{684,1},	{721,1},	{649,3},
  {611,3},	{722,3}
};

static struct patval owl_attackpat170[] = {
  {722,1},	{686,1},	{684,1},	{649,3},
  {723,3},	{721,3}
};

static struct patval owl_attackpat171[] = {
  {610,1},	{721,1},	{685,1},	{611,1}
};

static struct patval owl_attackpat172[] = {
  {686,1},	{684,1},	{721,3},	{649,3},
  {722,3},	{647,3},	{723,3}
};

static struct patval owl_attackpat173[] = {
  {684,1},	{721,1},	{686,1},	{648,1},
  {723,1},	{759,1}
};

static struct patval owl_attackpat174[] = {
  {647,1},	{684,1},	{686,1},	{649,1},
  {722,1}
};

static struct patval owl_attackpat175[] = {
  {758,1},	{757,1},	{647,3},	{646,3}
};

static struct patval owl_attackpat176[] = {
  {684,1},	{721,1},	{686,1},	{648,1},
  {723,1}
};

static struct patval owl_attackpat177[] = {
  {758,1},	{720,1},	{684,1},	{648,1},
  {647,3},	{683,3},	{757,3}
};

static struct patval owl_attackpat178[] = {
  {686,1},	{722,1},	{684,1},	{723,3},
  {721,3}
};

static struct patval owl_attackpat179[] = {
  {720,1},	{721,1},	{646,3},	{683,3}
};

static struct patval owl_attackpat180[] = {
  {684,1}
};

static struct patval owl_attackpat181[] = {
  {609,1},	{721,1},	{720,1},	{646,3},
  {683,3}
};

static struct patval owl_attackpat182[] = {
  {684,1},	{757,1}
};

static struct patval owl_attackpat183[] = {
  {683,1},	{684,1}
};

static struct patval owl_attackpat184[] = {
  {647,1},	{685,1}
};

static struct patval owl_attackpat185[] = {
  {645,1},	{646,1},	{684,1}
};

static struct patval owl_attackpat186[] = {
  {686,1},	{684,1}
};

static struct patval owl_attackpat187[] = {
  {686,1},	{722,1},	{684,1},	{649,1}
};

static struct patval owl_attackpat188[] = {
  {684,1},	{686,1}
};

static struct patval owl_attackpat189[] = {
  {720,1},	{684,1},	{685,1}
};

static struct patval owl_attackpat190[] = {
  {648,1},	{719,1},	{684,1},	{683,1},
  {682,1}
};

static struct patval owl_attackpat191[] = {
  {647,1},	{721,1}
};

static struct patval owl_attackpat192[] = {
  {647,1},	{721,1}
};

static struct patval owl_attackpat193[] = {
  {758,1},	{683,1},	{720,1},	{646,3}
};

static struct patval owl_attackpat194[] = {
  {683,1},	{647,1},	{685,1},	{720,3}
};

static struct patval owl_attackpat195[] = {
  {685,1},	{683,1},	{722,1}
};

static struct patval owl_attackpat196[] = {
  {646,1},	{648,1},	{684,1},	{721,1},
  {759,1}
};

static struct patval owl_attackpat197[] = {
  {646,1},	{722,1},	{684,1},	{721,1},
  {759,1}
};

static struct patval owl_attackpat198[] = {
  {722,1},	{683,1},	{721,1},	{684,1},
  {759,3}
};

static struct patval owl_attackpat199[] = {
  {646,1},	{760,1},	{684,1},	{721,1},
  {722,1}
};

static struct patval owl_attackpat200[] = {
  {647,1},	{683,1},	{722,1},	{684,1},
  {648,1}
};

static struct patval owl_attackpat201[] = {
  {647,1},	{684,1},	{721,1}
};

static struct patval owl_attackpat202[] = {
  {610,1},	{611,1},	{684,1}
};

static struct patval owl_attackpat203[] = {
  {758,1},	{720,1},	{684,1}
};

static struct patval owl_attackpat204[] = {
  {683,1},	{684,1},	{720,1},	{686,1}
};

static struct patval owl_attackpat205[] = {
  {683,1},	{684,1},	{720,1},	{686,1}
};

static struct patval owl_attackpat206[] = {
  {610,1},	{722,1},	{684,1}
};

static struct patval owl_attackpat207[] = {
  {720,1},	{758,1},	{647,1},	{684,1},
  {757,3}
};

static struct patval owl_attackpat208[] = {
  {648,1},	{686,1},	{720,1},	{684,1},
  {758,1}
};

static struct patval owl_attackpat209[] = {
  {720,1},	{758,1},	{648,1},	{684,1}
};

static struct patval owl_attackpat210[] = {
  {648,1},	{684,1},	{721,1},	{759,1},
  {797,3}
};

static struct patval owl_attackpat211[] = {
  {721,1},	{684,1},	{759,1},	{648,1},
  {612,3},	{760,3}
};

static struct patval owl_attackpat212[] = {
  {684,1},	{722,1}
};

static struct patval owl_attackpat213[] = {
  {684,1},	{722,1}
};

static struct patval owl_attackpat214[] = {
  {722,1},	{684,1}
};

static struct patval owl_attackpat215[] = {
  {722,1},	{684,1}
};

static struct patval owl_attackpat216[] = {
  {648,1},	{721,1}
};

static struct patval owl_attackpat217[] = {
  {648,1},	{721,1}
};

static struct patval owl_attackpat218[] = {
  {721,1},	{647,1}
};

static struct patval owl_attackpat219[] = {
  {721,1},	{647,1}
};

static struct patval owl_attackpat220[] = {
  {722,1},	{648,1}
};

static struct patval owl_attackpat221[] = {
  {684,1},	{686,1}
};

static struct patval owl_attackpat222[] = {
  {647,1},	{758,1}
};

static struct patval owl_attackpat223[] = {
  {649,1},	{684,1}
};

static struct patval owl_attackpat224[] = {
  {647,1},	{721,1},	{648,3},	{722,3}
};

static struct patval owl_attackpat225[] = {
  {646,1},	{722,1},	{684,1}
};

static struct patval owl_attackpat226[] = {
  {721,1},	{684,1}
};

static struct patval owl_attackpat227[] = {
  {685,1},	{647,3},	{795,3},	{832,3}
};

static struct patval owl_attackpat228[] = {
  {684,1},	{724,1},	{721,1},	{687,1}
};

static struct patval owl_attackpat229[] = {
  {684,1},	{724,1},	{721,1},	{687,1}
};

static struct patval owl_attackpat230[] = {
  {758,1},	{648,1},	{721,3}
};

static struct patval owl_attackpat231[] = {
  {758,1},	{648,1},	{721,3}
};

static struct patval owl_attackpat232[] = {
  {720,1},	{686,1},	{684,1},	{683,3}
};

static struct patval owl_attackpat233[] = {
  {758,1},	{686,1}
};

static struct patval owl_attackpat234[] = {
  {684,1},	{650,1}
};

static struct patval owl_attackpat235[] = {
  {684,1}
};

static struct patval owl_attackpat236[] = {
  {686,1},	{684,1}
};

static struct patval owl_attackpat237[] = {
  {684,1},	{686,1},	{610,1}
};

static struct patval owl_attackpat238[] = {
  {684,1},	{687,1},	{650,3},	{647,3},
  {613,3},	{724,3}
};

static struct patval owl_attackpat239[] = {
  {647,1},	{759,1},	{648,3}
};

static struct patval owl_attackpat240[] = {
  {647,1},	{759,1},	{648,3}
};

static struct patval owl_attackpat241[] = {
  {684,1},	{723,1}
};

static struct patval owl_attackpat242[] = {
  {648,1}
};

static struct patval owl_attackpat243[] = {
  {648,1}
};

static struct patval owl_attackpat244[] = {
  {684,1}
};

static struct patval owl_attackpat245[] = {
  {723,1},	{648,1}
};

static struct patval owl_attackpat246[] = {
  {685,1},	{721,1}
};

static struct patval owl_attackpat247[] = {
  {685,1},	{647,1},	{649,3},	{648,3}
};

static struct patval owl_attackpat248[] = {
  {685,1},	{721,1},	{647,1},	{648,3},
  {649,3},	{686,3}
};

static struct patval owl_attackpat249[] = {
  {647,1}
};

static struct patval owl_attackpat250[] = {
  {647,1}
};

static struct patval owl_attackpat251[] = {
  {647,1}
};

static struct patval owl_attackpat252[] = {
  {684,1},	{722,1}
};

static struct patval owl_attackpat253[] = {
  {720,1},	{684,1},	{683,3}
};

static struct patval owl_attackpat254[] = {
  {684,1}
};

static struct patval owl_attackpat255[] = {
  {685,1},	{647,1},	{648,1},	{610,3}
};

static struct patval owl_attackpat256[] = {
  {646,1},	{647,1}
};

static struct patval owl_attackpat257[] = {
  {723,1},	{760,3},	{646,3}
};

static struct patval owl_attackpat258[] = {
  {722,1},	{760,3},	{759,3},	{646,3}
};

static struct patval owl_attackpat259[] = {
  {684,1},	{685,1},	{646,3},	{760,3},
  {647,3}
};

static struct patval owl_attackpat260[] = {
  {683,1},	{722,1},	{684,1},	{723,3},
  {649,3},	{686,3}
};

static struct patval owl_attackpat261[] = {
  {722,1},	{647,1}
};

static struct patval owl_attackpat262[] = {
  {722,1},	{647,1}
};

static struct patval owl_attackpat263[] = {
  {646,1},	{684,1}
};

static struct patval owl_attackpat264[] = {
  {684,1},	{723,1}
};

static struct patval owl_attackpat265[] = {
  {684,1}
};

static struct patval owl_attackpat266[] = {
  {684,1},	{723,1}
};

static struct patval owl_attackpat267[] = {
  {684,1},	{723,1}
};

static struct patval owl_attackpat268[] = {
  {758,1},	{648,1},	{721,3}
};

static struct patval owl_attackpat269[] = {
  {758,1},	{648,1},	{721,3}
};

static struct patval owl_attackpat270[] = {
  {721,1}
};

static struct patval owl_attackpat271[] = {
  {721,1},	{648,3},	{723,3},	{686,3},
  {649,3}
};

static struct patval owl_attackpat272[] = {
  {721,1},	{648,3},	{686,3},	{649,3}
};

static struct patval owl_attackpat273[] = {
  {685,1},	{647,1},	{683,1},	{759,3},
  {757,3},	{758,3}
};

static struct patval owl_attackpat274[] = {
  {684,1}
};

static struct patval owl_attackpat275[] = {
  {684,1},	{648,1}
};

static struct patval owl_attackpat276[] = {
  {684,1},	{648,1}
};

static struct patval owl_attackpat277[] = {
  {648,1},	{684,1},	{722,1},	{610,1}
};

static struct patval owl_attackpat278[] = {
  {720,1},	{684,1},	{683,1},	{649,3},
  {646,3}
};

static struct patval owl_attackpat279[] = {
  {721,1},	{683,1},	{722,1},	{646,3}
};

static struct patval owl_attackpat280[] = {
  {647,1},	{758,1}
};

static struct patval owl_attackpat281[] = {
  {722,1},	{759,1},	{760,1},	{684,1},
  {721,1}
};

static struct patval owl_attackpat282[] = {
  {758,1},	{759,3}
};

static struct patval owl_attackpat283[] = {
  {758,1}
};

static struct patval owl_attackpat284[] = {
  {647,1},	{721,1}
};

static struct patval owl_attackpat285[] = {
  {647,1},	{721,1}
};

static struct patval owl_attackpat286[] = {
  {647,1},	{721,1}
};

static struct patval owl_attackpat287[] = {
  {647,1},	{721,1}
};

static struct patval owl_attackpat288[] = {
  {759,1},	{647,1}
};

static struct patval owl_attackpat289[] = {
  {648,1},	{759,1}
};

static struct patval owl_attackpat290[] = {
  {722,1},	{685,1},	{719,3},	{682,3},
  {646,3},	{756,3}
};

static struct patval owl_attackpat291[] = {
  {686,1},	{722,1},	{610,3},	{572,3},
  {573,3},	{609,3}
};

static struct patval owl_attackpat292[] = {
  {686,1},	{684,1},	{722,1},	{723,3}
};

static struct patval owl_attackpat293[] = {
  {685,1}
};

static struct patval owl_attackpat294[] = {
  {684,1}
};

static struct patval owl_attackpat295[] = {
  {684,1}
};

static struct patval owl_attackpat296[] = {
  {684,1},	{722,1}
};

static struct patval owl_attackpat297[] = {
  {684,1},	{722,1}
};

static struct patval owl_attackpat298[] = {
  {722,1},	{684,1},	{647,1}
};

static struct patval owl_attackpat299[] = {
  {645,1},	{684,1}
};

static struct patval owl_attackpat300[] = {
  {721,1},	{684,1}
};

static struct patval owl_attackpat301[] = {
  {647,1},	{648,1},	{685,1}
};

static struct patval owl_attackpat302[] = {
  {683,1},	{684,1}
};

static struct patval owl_attackpat303[] = {
  {684,1},	{686,1},	{721,1}
};

static struct patval owl_attackpat304[] = {
  {684,1},	{685,1},	{683,1},	{758,1}
};

static struct patval owl_attackpat305[] = {
  {683,1},	{685,1},	{646,1}
};

static struct patval owl_attackpat306[] = {
  {648,1},	{684,1}
};

static struct patval owl_attackpat307[] = {
  {685,1},	{684,1},	{683,1},	{719,1},
  {756,1}
};

static struct patval owl_attackpat308[] = {
  {721,1},	{684,1},	{612,1},	{611,1}
};

static struct patval owl_attackpat309[] = {
  {685,1},	{684,1},	{683,1},	{719,1},
  {756,1}
};

static struct patval owl_attackpat310[] = {
  {646,1},	{684,1},	{720,1},	{758,1},
  {759,1},	{683,3}
};

static struct patval owl_attackpat311[] = {
  {720,1},	{647,1},	{611,1},	{684,1},
  {683,3},	{610,3}
};

static struct patval owl_attackpat312[] = {
  {758,1},	{684,1},	{721,3},	{759,3}
};

static struct patval owl_attackpat313[] = {
  {758,1},	{684,1},	{759,3}
};

static struct patval owl_attackpat314[] = {
  {646,1},	{684,1},	{720,1},	{758,1},
  {759,1},	{683,3}
};

static struct patval owl_attackpat315[] = {
  {686,1},	{647,1},	{648,1},	{683,1}
};

static struct patval owl_attackpat316[] = {
  {683,1},	{647,1},	{648,1},	{686,1}
};

static struct patval owl_attackpat317[] = {
  {647,1},	{683,1},	{611,1},	{684,1},
  {612,3}
};

static struct patval owl_attackpat318[] = {
  {684,1},	{647,3}
};

static struct patval owl_attackpat319[] = {
  {647,1},	{684,1},	{649,3}
};

static struct patval owl_attackpat320[] = {
  {684,1},	{682,1},	{720,1}
};

static struct patval owl_attackpat321[] = {
  {759,1},	{684,1},	{721,1},	{760,1}
};

static struct patval owl_attackpat322[] = {
  {684,1},	{647,1},	{646,1}
};

static struct patval owl_attackpat323[] = {
  {684,1},	{722,1},	{720,1},	{721,1}
};

static struct patval owl_attackpat324[] = {
  {685,1},	{720,1},	{684,1},	{648,3}
};

static struct patval owl_attackpat325[] = {
  {758,1},	{720,1},	{759,1}
};

static struct patval owl_attackpat326[] = {
  {685,1},	{720,1},	{759,1},	{684,1},
  {648,3}
};

static struct patval owl_attackpat327[] = {
  {648,1},	{683,1},	{684,1}
};

static struct patval owl_attackpat328[] = {
  {646,1},	{721,1},	{684,1}
};

static struct patval owl_attackpat329[] = {
  {723,1},	{684,1},	{721,1}
};

static struct patval owl_attackpat330[] = {
  {647,1},	{684,1},	{722,1},	{723,1}
};

static struct patval owl_attackpat331[] = {
  {684,1}
};

static struct patval owl_attackpat332[] = {
  {648,1},	{686,1},	{722,1},	{684,1}
};

static struct patval owl_attackpat333[] = {
  {684,1},	{648,1}
};

static struct patval owl_attackpat334[] = {
  {720,1},	{684,1},	{648,1}
};

static struct patval owl_attackpat335[] = {
  {684,1},	{720,1},	{648,1},	{758,3},
  {757,3},	{649,3},	{686,3}
};

static struct patval owl_attackpat336[] = {
  {720,1},	{684,1},	{648,3},	{649,3}
};

static struct patval owl_attackpat337[] = {
  {646,1},	{683,1},	{648,1},	{684,1},
  {721,1},	{722,1}
};

static struct patval owl_attackpat338[] = {
  {683,1},	{647,1},	{685,1}
};

static struct patval owl_attackpat339[] = {
  {686,1},	{684,1},	{611,1},	{612,3},
  {721,3},	{647,3}
};

static struct patval owl_attackpat340[] = {
  {723,1},	{686,1},	{649,1},	{609,1},
  {610,1},	{721,1},	{611,1}
};

static struct patval owl_attackpat341[] = {
  {720,1},	{683,1},	{646,1},	{721,1},
  {611,1},	{612,1},	{610,1},	{722,1}
};

static struct patval owl_attackpat342[] = {
  {722,1},	{684,1},	{683,1}
};

static struct patval owl_attackpat343[] = {
  {685,1},	{721,1},	{720,1}
};

static struct patval owl_attackpat344[] = {
  {647,1},	{684,1},	{721,1},	{759,1},
  {686,1}
};

static struct patval owl_attackpat345[] = {
  {646,1},	{683,1},	{759,1},	{760,1},
  {648,1},	{721,1},	{758,3},	{720,3}
};

static struct patval owl_attackpat346[] = {
  {686,1},	{648,1},	{722,1},	{760,1},
  {684,1},	{723,3}
};

static struct patval owl_attackpat347[] = {
  {758,1},	{720,1},	{684,1},	{757,3},
  {759,3},	{683,3}
};

static struct patval owl_attackpat348[] = {
  {720,1},	{647,1},	{646,1},	{611,1},
  {610,3}
};

static struct patval owl_attackpat349[] = {
  {719,1},	{683,1},	{685,1},	{757,1},
  {684,1}
};

static struct patval owl_attackpat350[] = {
  {721,1},	{611,1},	{722,1},	{647,1},
  {684,1}
};

static struct patval owl_attackpat351[] = {
  {647,1},	{684,1},	{683,3},	{757,3},
  {648,3},	{720,3}
};

static struct patval owl_attackpat352[] = {
  {647,1},	{684,1},	{721,1},	{648,1}
};

static struct patval owl_attackpat353[] = {
  {684,1},	{648,1}
};

static struct patval owl_attackpat354[] = {
  {646,1},	{684,1},	{685,1},	{645,3},
  {722,3},	{682,3}
};

static struct patval owl_attackpat355[] = {
  {685,1},	{684,1},	{723,1},	{720,3},
  {757,3}
};

static struct patval owl_attackpat356[] = {
  {722,1},	{682,1},	{648,1},	{647,1},
  {646,1},	{684,1},	{719,3},	{683,3}
};

static struct patval owl_attackpat357[] = {
  {758,1},	{760,1},	{724,1},	{720,1},
  {759,1},	{684,1}
};

static struct patval owl_attackpat358[] = {
  {684,1},	{759,1},	{760,1},	{719,1},
  {724,1},	{758,1},	{720,1}
};

static struct patval owl_attackpat359[] = {
  {757,1},	{720,1},	{683,1},	{648,1},
  {685,1},	{684,1},	{759,1}
};

static struct patval owl_attackpat360[] = {
  {648,1},	{646,1},	{720,1},	{649,1},
  {684,1},	{610,1}
};

static struct patval owl_attackpat361[] = {
  {684,1}
};

static struct patval owl_attackpat362[] = {
  {758,1}
};

static struct patval owl_attackpat363[] = {
  {684,1}
};

static struct patval owl_attackpat364[] = {
  {684,1}
};

static struct patval owl_attackpat365[] = {
  {722,1},	{686,1},	{648,1},	{684,1}
};

static struct patval owl_attackpat366[] = {
  {722,1},	{686,1},	{648,1},	{684,1}
};

static struct patval owl_attackpat367[] = {
  {648,1},	{646,1},	{647,1},	{722,1},
  {684,1},	{686,1}
};

static struct patval owl_attackpat368[] = {
  {684,1},	{723,1},	{648,3},	{649,3}
};

static struct patval owl_attackpat369[] = {
  {684,1},	{648,1},	{722,1}
};

static struct patval owl_attackpat370[] = {
  {684,1},	{720,1},	{685,1}
};

static struct patval owl_attackpat371[] = {
  {647,1},	{684,1},	{722,1},	{686,1}
};

static struct patval owl_attackpat372[] = {
  {647,1},	{684,1},	{723,1},	{722,1}
};

static struct patval owl_attackpat373[] = {
  {649,1},	{648,1},	{684,1},	{722,1}
};

static struct patval owl_attackpat374[] = {
  {757,1},	{720,1},	{685,1},	{684,1}
};

static struct patval owl_attackpat375[] = {
  {649,1},	{648,1},	{722,1},	{684,1}
};

static struct patval owl_attackpat376[] = {
  {686,1},	{647,1},	{684,1},	{722,1},
  {610,3}
};

static struct patval owl_attackpat377[] = {
  {758,1},	{684,1},	{720,1},	{648,1}
};

static struct patval owl_attackpat378[] = {
  {611,1},	{647,1},	{684,1},	{721,1},
  {649,1}
};

static struct patval owl_attackpat379[] = {
  {611,1},	{647,1},	{684,1},	{721,1},
  {759,1},	{758,3}
};

static struct patval owl_attackpat380[] = {
  {722,1},	{720,1},	{684,1},	{758,1}
};

static struct patval owl_attackpat381[] = {
  {683,1},	{720,1},	{647,1},	{685,1},
  {759,1},	{758,3}
};

static struct patval owl_attackpat382[] = {
  {722,1},	{684,1},	{723,1},	{648,3},
  {647,3}
};

static struct patval owl_attackpat383[] = {
  {684,1},	{610,1},	{646,1},	{648,1},
  {683,3},	{609,3}
};

static struct pattern owl_attackpat[385];

static int
autohelperowl_attackpat0(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);

  return  countlib(A)<4;
}

static int
autohelperowl_attackpat6(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);

  return  countlib(a)>2;
}

static int
autohelperowl_attackpat11(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);

  return  (somewhere(color, 0, 1, a) || !somewhere(color, 0, 1, b));
}

static int
autohelperowl_attackpat14(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(722, trans, move);

  return  countlib(A)>2;
}

static int
autohelperowl_attackpat17(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(609, trans, move);
  b = AFFINE_TRANSFORM(610, trans, move);

  return somewhere(color, 0, 2, a, b);
}

static int
autohelperowl_attackpat18(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  c = AFFINE_TRANSFORM(756, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, a, a) || !play_attack_defend_n(color, 1, 4, move, a, b, c, move);
}

static int
autohelperowl_attackpat27(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);

  return !somewhere(OTHER_COLOR(color), 0, 1, a) || ATTACK_MACRO(a);
}

static int
autohelperowl_attackpat28(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);

  return !ATTACK_MACRO(a);
}

static int
autohelperowl_attackpat32(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return !play_attack_defend_n(color, 1, 2, move, a, move);
}

static int
autohelperowl_attackpat33(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);

  return countlib(a)>2;
}

static int
autohelperowl_attackpat34(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);

  return owl_escape_value(a)>0;
}

static int
autohelperowl_attackpat36(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(646, trans, move);

  return countlib(A)>1;
}

static int
autohelperowl_attackpat39(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return !play_attack_defend_n(color, 1, 2, move, a, move);
}

static int
autohelperowl_attackpat41(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return countlib(a)==2;
}

static int
autohelperowl_attackpat42(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(646, trans, move);

  return !play_attack_defend2_n(OTHER_COLOR(color), 0, 3, move, b, c, a, b);
}

static int
autohelperowl_attackpat44(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(645, trans, move);
  b = AFFINE_TRANSFORM(608, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);
  d = AFFINE_TRANSFORM(721, trans, move);
  e = AFFINE_TRANSFORM(610, trans, move);
  f = AFFINE_TRANSFORM(685, trans, move);
  A = AFFINE_TRANSFORM(609, trans, move);

  return (accuratelib(a, OTHER_COLOR(color), MAX_LIBERTIES, NULL)==1 || countlib(b)>2) && countlib(A)<=3 && accuratelib(e, color, MAX_LIBERTIES, NULL)>1&& play_attack_defend_n(color, 1, 6, move, c, a, d, e, f, A)&& play_attack_defend_n(color, 0, 4, move, c, a, e, move);
}

static int
autohelperowl_attackpat45(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  c = AFFINE_TRANSFORM(719, trans, move);
  d = AFFINE_TRANSFORM(720, trans, move);

  return  (owl_escape_value(b) <= 0 && owl_escape_value(c) <= 0) || !play_attack_defend_n(color, 1, 2, move, a, d);
}

static int
autohelperowl_attackpat46(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(682, trans, move);

  return owl_escape_value(a) < 1;
}

static int
autohelperowl_attackpat48(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return countlib(B)<=3 && play_attack_defend_n(color, 1, 2, move, a, B);
}

static int
autohelperowl_attackpat49(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_attackpat51(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  C = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(OTHER_COLOR(color), 1, 2, move, a, C) || !play_attack_defend2_n(OTHER_COLOR(color), 0, 3, move, a, b, a, C);
}

static int
autohelperowl_attackpat52(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return owl_escape_value(a)>0;
}

static int
autohelperowl_attackpat53(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);

  return owl_escape_value(a)>0 && !play_attack_defend_n(color, 1, 3, move, a, b, move);
}

static int
autohelperowl_attackpat54(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return  play_attack_defend_n(OTHER_COLOR(color), 1, 1, move, a);
}

static int
autohelperowl_attackpat55(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(645, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  c = AFFINE_TRANSFORM(646, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_attackpat56(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(649, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_attackpat57(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_attackpat58(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return owl_escape_value(a) > 0;
}

static int
autohelperowl_attackpat59(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  b = AFFINE_TRANSFORM(611, trans, move);

  return owl_escape_value(a)+owl_escape_value(b) > 0;
}

static int
autohelperowl_attackpat61(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(720, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);

  return  play_attack_defend_n(color, 1, 4, move, a, b, c, c);
}

static int
autohelperowl_attackpat62(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);
  c = AFFINE_TRANSFORM(685, trans, move);
  d = AFFINE_TRANSFORM(611, trans, move);
  e = AFFINE_TRANSFORM(610, trans, move);

  return  accuratelib(d, OTHER_COLOR(color), MAX_LIBERTIES, NULL)<=2 && countlib(e)>3 && play_attack_defend_n(color, 1, 4, move, a, b, c, c);
}

static int
autohelperowl_attackpat66(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return  !play_attack_defend_n(color, 1, 1, move, move);
}

static int
autohelperowl_attackpat67(int trans, int move, int color, int action)
{
  int a, b, c, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);
  A = AFFINE_TRANSFORM(721, trans, move);

  return  (somewhere(OTHER_COLOR(color), 0, 1, a) || ! safe_move(a, color)) && !play_attack_defend_n(OTHER_COLOR(color), 0, 3, move, b, c, A);
}

static int
autohelperowl_attackpat71(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(757, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);

  return !play_connect_n(color, 0, 1, move, a, b);
}

static int
autohelperowl_attackpat72(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(686, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);

  return play_connect_n(OTHER_COLOR(color), 0, 2, move, a, a, c) && play_connect_n(OTHER_COLOR(color), 0, 2, move, b, b, c);
}

static int
autohelperowl_attackpat73(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(757, trans, move);

  return !owl_goal_dragon(A);
}

static int
autohelperowl_attackpat76(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);

  return  play_attack_defend2_n(color, 0, 2, move, a, move, b) && !play_attack_defend_n(color, 1, 2, move, a, b);
}

static int
autohelperowl_attackpat77(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);

  return  play_attack_defend2_n(color, 0, 2, move, a, move, b);
}

static int
autohelperowl_attackpat78(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return countlib(a)<=2 || accuratelib(move, OTHER_COLOR(color), MAX_LIBERTIES, NULL)>2;
}

static int
autohelperowl_attackpat79(int trans, int move, int color, int action)
{
  int a, b, c, d, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(682, trans, move);
  d = AFFINE_TRANSFORM(647, trans, move);
  A = AFFINE_TRANSFORM(645, trans, move);

  return  play_attack_defend2_n(color, 0, 4, move, a, b, c, A, b) && play_attack_defend2_n(color, 0, 4, move, b, a, d, move, A);
}

static int
autohelperowl_attackpat80(int trans, int move, int color, int action)
{
  int a, b, c, d, e, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(682, trans, move);
  d = AFFINE_TRANSFORM(647, trans, move);
  e = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(645, trans, move);

  return  owl_escape_value(e)>0 && play_attack_defend2_n(color, 0, 4, move, a, b, c, A, b) && play_attack_defend2_n(color, 0, 4, move, b, a, d, move, A);
}

static int
autohelperowl_attackpat82(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);

  return  (owl_escape_value(a)>0)||(owl_escape_value(b)>0);
}

static int
autohelperowl_attackpat83(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  b = AFFINE_TRANSFORM(720, trans, move);
  c = AFFINE_TRANSFORM(719, trans, move);
  d = AFFINE_TRANSFORM(682, trans, move);

  return owl_escape_value(a)>0&& (!somewhere(OTHER_COLOR(color), 0, 2, b, c)    || somewhere(color, 0, 2, b, d)    || (somewhere(color, 0, 1, c) && !safe_move(d, OTHER_COLOR(color))));
}

static int
autohelperowl_attackpat84(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);
  d = AFFINE_TRANSFORM(647, trans, move);
  e = AFFINE_TRANSFORM(610, trans, move);

  return owl_escape_value(a)>0 && (play_attack_defend_n(OTHER_COLOR(color), 1, 4, b, c, move, d, d) || !play_attack_defend_n(OTHER_COLOR(color), 0, 4, move, b, d, e, e));
}

static int
autohelperowl_attackpat85(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);

  return !(somewhere(color, 0, 1, a) && somewhere(color, 0, 1, b)) || somewhere(OTHER_COLOR(color), 0, 1, c);
}

static int
autohelperowl_attackpat87(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  b = AFFINE_TRANSFORM(609, trans, move);
  c = AFFINE_TRANSFORM(573, trans, move);
  d = AFFINE_TRANSFORM(572, trans, move);
  e = AFFINE_TRANSFORM(685, trans, move);

  return somewhere(color, 0, 4, a, b, c, d) && owl_escape_value(e) > 0;
}

static int
autohelperowl_attackpat88(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);
  c = AFFINE_TRANSFORM(649, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_attackpat89(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return owl_escape_value(a)>0;
}

static int
autohelperowl_attackpat90(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g, h, i, j;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  b = AFFINE_TRANSFORM(611, trans, move);
  c = AFFINE_TRANSFORM(610, trans, move);
  d = AFFINE_TRANSFORM(719, trans, move);
  e = AFFINE_TRANSFORM(718, trans, move);
  f = AFFINE_TRANSFORM(717, trans, move);
  g = AFFINE_TRANSFORM(682, trans, move);
  h = AFFINE_TRANSFORM(681, trans, move);
  i = AFFINE_TRANSFORM(680, trans, move);
  j = AFFINE_TRANSFORM(648, trans, move);

  return owl_escape_value(a)>0&& ((somewhere(color, 0, 3, b, c, j) && somewhere(color, 0, 6, d, e, f, g, h, i))   || (somewhere(color, 0, 1, j) && owl_escape_value(d)==0 && owl_escape_value(e)==0));
}

static int
autohelperowl_attackpat91(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g, h, i, j;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  c = AFFINE_TRANSFORM(681, trans, move);
  d = AFFINE_TRANSFORM(719, trans, move);
  e = AFFINE_TRANSFORM(718, trans, move);
  f = AFFINE_TRANSFORM(648, trans, move);
  g = AFFINE_TRANSFORM(611, trans, move);
  h = AFFINE_TRANSFORM(610, trans, move);
  i = AFFINE_TRANSFORM(574, trans, move);
  j = AFFINE_TRANSFORM(573, trans, move);

  return owl_escape_value(a)>0 && somewhere(color, 0, 5, f, g, h, i, j) && somewhere(color, 0, 4, b, c, d, e);
}

static int
autohelperowl_attackpat92(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, i, j, k;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(723, trans, move);
  d = AFFINE_TRANSFORM(760, trans, move);
  e = AFFINE_TRANSFORM(721, trans, move);
  f = AFFINE_TRANSFORM(759, trans, move);
  i = AFFINE_TRANSFORM(761, trans, move);
  j = AFFINE_TRANSFORM(724, trans, move);
  k = AFFINE_TRANSFORM(687, trans, move);

  return (somewhere(color, 0, 1, j) || (somewhere(color, 0, 1, i) && somewhere(color, 0, 1, k)))&& !play_attack_defend_n(color, 1, 7, move, a, b, c, d, e, f, move) && !play_attack_defend_n(color, 1, 5, move, a, b, e, f, move);
}

static int
autohelperowl_attackpat93(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g, h, i, j, k;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(795, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);
  c = AFFINE_TRANSFORM(794, trans, move);
  d = AFFINE_TRANSFORM(757, trans, move);
  e = AFFINE_TRANSFORM(722, trans, move);
  f = AFFINE_TRANSFORM(610, trans, move);
  g = AFFINE_TRANSFORM(573, trans, move);
  h = AFFINE_TRANSFORM(609, trans, move);
  i = AFFINE_TRANSFORM(572, trans, move);
  j = AFFINE_TRANSFORM(608, trans, move);
  k = AFFINE_TRANSFORM(571, trans, move);

  return  somewhere(color, 0, 4, a, b, c, d) && owl_escape_value(e)>0 && somewhere(color, 0, 6, f, g, h, i, j, k);
}

static int
autohelperowl_attackpat94(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(760, trans, move);
  b = AFFINE_TRANSFORM(538, trans, move);
  c = AFFINE_TRANSFORM(537, trans, move);
  d = AFFINE_TRANSFORM(536, trans, move);
  e = AFFINE_TRANSFORM(757, trans, move);
  f = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(a)>0&& owl_escape_value(b)==0&& owl_escape_value(c)==0&& owl_escape_value(d)==0&& somewhere(color, 0, 2, e, f);
}

static int
autohelperowl_attackpat95(int trans, int move, int color, int action)
{
  int b, c, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);
  A = AFFINE_TRANSFORM(722, trans, move);

  return owl_escape_value(A)>0 && play_attack_defend2_n(color, 0, 2, move, b, move, c);
}

static int
autohelperowl_attackpat97(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(649, trans, move);
  b = AFFINE_TRANSFORM(686, trans, move);
  c = AFFINE_TRANSFORM(723, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_attackpat98(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(758, trans, move);

  return  countlib(A)>1;
}

static int
autohelperowl_attackpat99(int trans, int move, int color, int action)
{
  int c, d, A;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(647, trans, move);
  d = AFFINE_TRANSFORM(648, trans, move);
  A = AFFINE_TRANSFORM(685, trans, move);

  return (owl_escape_value(A)>0) && play_attack_defend2_n(color, 0, 2, move, c, move, d);
}

static int
autohelperowl_attackpat100(int trans, int move, int color, int action)
{
  int c, d, A;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(647, trans, move);
  d = AFFINE_TRANSFORM(648, trans, move);
  A = AFFINE_TRANSFORM(646, trans, move);

  return (owl_escape_value(A)>0) && play_attack_defend2_n(color, 0, 2, move, c, move, d);
}

static int
autohelperowl_attackpat101(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  c = AFFINE_TRANSFORM(645, trans, move);
  d = AFFINE_TRANSFORM(683, trans, move);
  e = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(e)>0 && !play_attack_defend2_n(OTHER_COLOR(color), 0, 3, move, a, b, c, d);
}

static int
autohelperowl_attackpat102(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(611, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_attackpat103(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);

  return (!owl_goal_dragon(b))&& !play_connect_n(OTHER_COLOR(color), 0, 1, move, a, b);
}

static int
autohelperowl_attackpat104(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);

  return (!owl_goal_dragon(a))&& !play_connect_n(OTHER_COLOR(color), 0, 1, move, a, b);
}

static int
autohelperowl_attackpat105(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);

  return (owl_escape_value(a) > 0);
}

static int
autohelperowl_attackpat106(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(719, trans, move);

  return (owl_escape_value(a) > 0);
}

static int
autohelperowl_attackpat107(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return owl_escape_value(a) > 0;
}

static int
autohelperowl_attackpat110(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return  ATTACK_MACRO(a);
}

static int
autohelperowl_attackpat112(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return accuratelib(move, color, MAX_LIBERTIES, NULL)>1;
}

static int
autohelperowl_attackpat118(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(720, trans, move);

  return countlib(A)<=3 && accuratelib(b, OTHER_COLOR(color), MAX_LIBERTIES, NULL) <= 2 && play_attack_defend_n(color, 1, 2, move, b, b);
}

static int
autohelperowl_attackpat120(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return owl_eyespace(a);
}

static int
autohelperowl_attackpat122(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);

  return somewhere(OTHER_COLOR(color), 0, 1, b) || play_attack_defend_n(color, 1, 2, a, b, a);
}

static int
autohelperowl_attackpat123(int trans, int move, int color, int action)
{
  int b, A, C, W;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(611, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);
  C = AFFINE_TRANSFORM(646, trans, move);
  W = AFFINE_TRANSFORM(648, trans, move);

  return  play_attack_defend_n(color, 1, 1, move, W) && !play_attack_defend_n(color, 1, 4, move, A, b, C, b);
}

static int
autohelperowl_attackpat124(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);

  return !play_attack_defend_n(color, 1, 3, move, a, b, move);
}

static int
autohelperowl_attackpat125(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);

  return !obvious_false_eye(a, OTHER_COLOR(color)) || !obvious_false_eye(b, color);
}

static int
autohelperowl_attackpat129(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);

  return !ATTACK_MACRO(a);
}

static int
autohelperowl_attackpat130(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(609, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(758, trans, move);

  return !ATTACK_MACRO(a) && owl_proper_eye(b)&& (somewhere(OTHER_COLOR(color), 0, 1, c) || owl_proper_eye(c));
}

static int
autohelperowl_attackpat131(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return owl_eyespace(b) && !ATTACK_MACRO(a);
}

static int
autohelperowl_attackpat134(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);

  return countlib(c) > 1 && !play_attack_defend_n(color, 1, 3, move, a, b, move);
}

static int
autohelperowl_attackpat135(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);

  return owl_maxeye(b) > 0 && !play_attack_defend_n(color, 1, 1, move, a) && !obvious_false_eye(b, OTHER_COLOR(color));
}

static int
autohelperowl_attackpat136(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);

  return owl_maxeye(b)>0 && !play_attack_defend_n(color, 1, 1, move, a) && !obvious_false_eye(b, OTHER_COLOR(color));
}

static int
autohelperowl_attackpat137(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);

  return owl_eyespace(b) && !play_attack_defend_n(color, 1, 2, move, b, a);
}

static int
autohelperowl_attackpat138(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(610, trans, move);
  d = AFFINE_TRANSFORM(609, trans, move);

  return owl_maxeye(b)==0&& ((somewhere(color, 0, 1, c) && owl_lunch(c))    || (somewhere(color, 0, 1, d) && owl_lunch(d)))&& !play_attack_defend_n(color, 1, 1, move, a) && !obvious_false_eye(b, OTHER_COLOR(color));
}

static int
autohelperowl_attackpat139(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  C = AFFINE_TRANSFORM(683, trans, move);

  return countlib(C)==2 && countstones(C)>1 && !play_attack_defend_n(color, 1, 1, move, a) && !obvious_false_eye(b, OTHER_COLOR(color));
}

static int
autohelperowl_attackpat141(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(609, trans, move);

  return !ATTACK_MACRO(a);
}

static int
autohelperowl_attackpat142(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(609, trans, move);

  return countlib(A)==2;
}

static int
autohelperowl_attackpat143(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(795, trans, move);

  return countlib(a) > 1;
}

static int
autohelperowl_attackpat144(int trans, int move, int color, int action)
{
  int a, b, c, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(720, trans, move);
  c = AFFINE_TRANSFORM(647, trans, move);
  D = AFFINE_TRANSFORM(682, trans, move);

  return play_attack_defend_n(color, 1, 4, move, a, b, c, D);
}

static int
autohelperowl_attackpat145(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);

  return !play_attack_defend_n(color, 1, 2, a, move, move);
}

static int
autohelperowl_attackpat146(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(682, trans, move);

  return countlib(A) == 3;
}

static int
autohelperowl_attackpat147(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  C = AFFINE_TRANSFORM(609, trans, move);

  return  !ATTACK_MACRO(C) && (!somewhere(OTHER_COLOR(color), 0, 1, b) || (somewhere(OTHER_COLOR(color), 0, 1, b) && somewhere(color, 0, 1, a)));
}

static int
autohelperowl_attackpat148(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(645, trans, move);

  return  countlib(A) == 3;
}

static int
autohelperowl_attackpat149(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(610, trans, move);
  A = AFFINE_TRANSFORM(685, trans, move);

  return  play_attack_defend2_n(color, 0, 2, move, A, b, move);
}

static int
autohelperowl_attackpat151(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return !obvious_false_eye(a, OTHER_COLOR(color));
}

static int
autohelperowl_attackpat152(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(757, trans, move);

  return countlib(A)<3 && owl_eyespace(move);
}

static int
autohelperowl_attackpat153(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(609, trans, move);

  return  play_attack_defend_n(OTHER_COLOR(color), 1, 2, move, a, a) && (somewhere(OTHER_COLOR(color), 0, 1, b) || !safe_move(b, color));
}

static int
autohelperowl_attackpat155(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(723, trans, move);

  return countlib(A)>1;
}

static int
autohelperowl_attackpat156(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(723, trans, move);

  return countlib(A)>1;
}

static int
autohelperowl_attackpat159(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);

  return owl_eyespace(a) && accuratelib(b, OTHER_COLOR(color), MAX_LIBERTIES, NULL) <= 2 && play_attack_defend_n(color, 1, 2, move, b, b);
}

static int
autohelperowl_attackpat160(int trans, int move, int color, int action)
{
  int a, b, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(759, trans, move);
  A = AFFINE_TRANSFORM(722, trans, move);

  return  (owl_topological_eye(a, board[A])<=2) && (owl_topological_eye(b, board[A])==2);
}

static int
autohelperowl_attackpat161(int trans, int move, int color, int action)
{
  int a, b, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);
  A = AFFINE_TRANSFORM(685, trans, move);

  return  (owl_topological_eye(a, board[A])==2) && ((owl_topological_eye(b, board[A])==2) || (owl_topological_eye(b, board[A])==3));
}

static int
autohelperowl_attackpat162(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return owl_topological_eye(a, board[B])==3 && does_attack(move, B);
}

static int
autohelperowl_attackpat163(int trans, int move, int color, int action)
{
  int a, b, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(682, trans, move);

  return  owl_topological_eye(a, board[A])==3 && safe_move(b, color) && safe_move(move, color) && play_attack_defend_n(OTHER_COLOR(color), 1, 2, move, b, b);
}

static int
autohelperowl_attackpat164(int trans, int move, int color, int action)
{
  int a, b, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);
  A = AFFINE_TRANSFORM(647, trans, move);

  return  countlib(a)==2 && owl_topological_eye(b, board[A])==3;
}

static int
autohelperowl_attackpat167(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  b = AFFINE_TRANSFORM(572, trans, move);

  return !ATTACK_MACRO(b) && play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b);
}

static int
autohelperowl_attackpat168(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)==1;
}

static int
autohelperowl_attackpat169(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(760, trans, move);

  return !owl_proper_eye(move) && !ATTACK_MACRO(a);
}

static int
autohelperowl_attackpat170(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(OTHER_COLOR(color), 1, 1, move, a);
}

static int
autohelperowl_attackpat171(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(648, trans, move);
  A = AFFINE_TRANSFORM(685, trans, move);

  return  owl_big_eyespace(A) && play_attack_defend_n(color, 1, 1, move, b);
}

static int
autohelperowl_attackpat172(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return  1 || play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_attackpat173(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);

  return owl_mineye(move)==1 && accuratelib(b, OTHER_COLOR(color), MAX_LIBERTIES, NULL)==2 && !play_attack_defend_n(color, 1, 1, move, c) && !play_attack_defend_n(color, 1, 3, move, a, b, b);
}

static int
autohelperowl_attackpat174(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);

  return accuratelib(b, OTHER_COLOR(color), MAX_LIBERTIES, NULL)==2 && !play_attack_defend_n(color, 1, 1, move, c) && !play_attack_defend_n(color, 1, 3, move, a, b, b);
}

static int
autohelperowl_attackpat175(int trans, int move, int color, int action)
{
  int a, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(682, trans, move);

  return (owl_eyespace(a) || owl_eyespace(c))&& play_attack_defend_n(color, 1, 1, a, a) && play_attack_defend_n(OTHER_COLOR(color), 1, 1, move, a);
}

static int
autohelperowl_attackpat176(int trans, int move, int color, int action)
{
  int b, c, d, e, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);
  d = AFFINE_TRANSFORM(647, trans, move);
  e = AFFINE_TRANSFORM(720, trans, move);
  A = AFFINE_TRANSFORM(648, trans, move);

  return countlib(A) == 3 && !obvious_false_eye(d, OTHER_COLOR(color))&& play_attack_defend_n(color, 0, 3, move, b, c, move) && play_attack_defend_n(color, 0, 3, move, e, c, move)&& play_attack_defend2_n(color, 0, 5, move, c, b, d, e, b, e);
}

static int
autohelperowl_attackpat179(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(646, trans, move);

  return  ATTACK_MACRO(A) && !play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_attackpat180(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return  does_attack(move, A);
}

static int
autohelperowl_attackpat185(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(645, trans, move);

  return  countlib(A)>2;
}

static int
autohelperowl_attackpat186(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return owl_eyespace(move);
}

static int
autohelperowl_attackpat187(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(757, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  C = AFFINE_TRANSFORM(722, trans, move);

  return  countlib(C) <= 3 && owl_proper_eye(a) && owl_proper_eye(b);
}

static int
autohelperowl_attackpat188(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return owl_eyespace(move);
}

static int
autohelperowl_attackpat189(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);
  c = AFFINE_TRANSFORM(723, trans, move);
  d = AFFINE_TRANSFORM(649, trans, move);

  return (!ATTACK_MACRO(a) && accuratelib(d, color, MAX_LIBERTIES, NULL)>=3)|| (!ATTACK_MACRO(b) && accuratelib(c, color, MAX_LIBERTIES, NULL)>=3);
}

static int
autohelperowl_attackpat191(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);

  return countlib(a)==1 && countlib(b)==1 && countlib(c)<=2;
}

static int
autohelperowl_attackpat192(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);

  return countlib(a)<=2 && countlib(b)==1 && countlib(c)<=2;
}

static int
autohelperowl_attackpat194(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  B = AFFINE_TRANSFORM(609, trans, move);

  return countlib(a) == 1 && countlib(B) > 1;
}

static int
autohelperowl_attackpat196(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(718, trans, move);

  return !somewhere(color, 0, 1, a) || !DEFEND_MACRO(a);
}

static int
autohelperowl_attackpat197(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(718, trans, move);

  return !somewhere(color, 0, 1, a) || !DEFEND_MACRO(a);
}

static int
autohelperowl_attackpat198(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return !DEFEND_MACRO(a);
}

static int
autohelperowl_attackpat199(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return accuratelib(a, OTHER_COLOR(color), MAX_LIBERTIES, NULL) == 2;
}

static int
autohelperowl_attackpat201(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return !obvious_false_eye(a, OTHER_COLOR(color)) && owl_maxeye(move)>1;
}

static int
autohelperowl_attackpat202(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(609, trans, move);

  return countlib(A)==2;
}

static int
autohelperowl_attackpat204(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(647, trans, move);
  A = AFFINE_TRANSFORM(645, trans, move);

  return countlib(A)==2 && !safe_move(b, color);
}

static int
autohelperowl_attackpat205(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return !safe_move(a, color);
}

static int
autohelperowl_attackpat206(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(757, trans, move);
  b = AFFINE_TRANSFORM(795, trans, move);

  return somewhere(color, 0, 2, a, b);
}

static int
autohelperowl_attackpat212(int trans, int move, int color, int action)
{
  int a, B, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);
  C = AFFINE_TRANSFORM(721, trans, move);

  return (owl_escape_value(B)>0 || owl_escape_value(C)>0)&& !play_attack_defend2_n(color, 1, 1, move, move, a);
}

static int
autohelperowl_attackpat213(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);

  return  !play_attack_defend2_n(color, 1, 1, move, move, a);
}

static int
autohelperowl_attackpat214(int trans, int move, int color, int action)
{
  int a, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(719, trans, move);

  return  !safe_move(a, color) && !play_attack_defend2_n(color, 1, 3, move, NO_MOVE, a, a, c) && !play_attack_defend_n(color, 1, 2, move, a, move);
}

static int
autohelperowl_attackpat215(int trans, int move, int color, int action)
{
  int a, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(719, trans, move);

  return  !safe_move(a, color) && !play_attack_defend2_n(color, 1, 3, move, NO_MOVE, a, a, c);
}

static int
autohelperowl_attackpat216(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  C = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(C)>0 && play_attack_defend2_n(OTHER_COLOR(color), 1, 2, move, a, a, b);
}

static int
autohelperowl_attackpat217(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  C = AFFINE_TRANSFORM(647, trans, move);

  return owl_escape_value(C)>0 && play_attack_defend2_n(OTHER_COLOR(color), 1, 2, move, a, a, b);
}

static int
autohelperowl_attackpat219(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return countlib(a) <= 2;
}

static int
autohelperowl_attackpat220(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_attackpat221(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);

  return (owl_escape_value(a)>0 || owl_escape_value(b)>0) && play_attack_defend_n(color, 1, 2, move, c, c);
}

static int
autohelperowl_attackpat222(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);

  return play_attack_defend_n(OTHER_COLOR(color), 1, 2, move, a, a);
}

static int
autohelperowl_attackpat223(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(color, 1, 2, move, a, B);
}

static int
autohelperowl_attackpat224(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_attackpat225(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);

  return  !safe_move(a, color) && countlib(b)>1;
}

static int
autohelperowl_attackpat226(int trans, int move, int color, int action)
{
  int b, c, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(648, trans, move);
  c = AFFINE_TRANSFORM(610, trans, move);
  A = AFFINE_TRANSFORM(647, trans, move);

  return  owl_escape_value(b)>0 && play_attack_defend2_n(color, 0, 3, move, A, b, c, b) && play_attack_defend2_n(color, 0, 3, move, A, b, b, move);
}

static int
autohelperowl_attackpat227(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(794, trans, move);
  B = AFFINE_TRANSFORM(757, trans, move);

  return somewhere(OTHER_COLOR(color), 0, 2, A, B) && owl_escape_value(A) + owl_escape_value(B) > 0;
}

static int
autohelperowl_attackpat228(int trans, int move, int color, int action)
{
  int e, f, g, A, B;
  UNUSED(color);
  UNUSED(action);

  e = AFFINE_TRANSFORM(683, trans, move);
  f = AFFINE_TRANSFORM(720, trans, move);
  g = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(682, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return  (owl_escape_value(A) > 0 || owl_escape_value(B) > 0) && play_attack_defend2_n(color, 0, 4, move, g, f, e, f, move);
}

static int
autohelperowl_attackpat229(int trans, int move, int color, int action)
{
  int e, f, g, A, B;
  UNUSED(color);
  UNUSED(action);

  e = AFFINE_TRANSFORM(683, trans, move);
  f = AFFINE_TRANSFORM(720, trans, move);
  g = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(682, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return  (owl_escape_value(A) > 0 || owl_escape_value(B) > 0) && play_attack_defend2_n(color, 0, 4, move, g, f, e, f, move);
}

static int
autohelperowl_attackpat230(int trans, int move, int color, int action)
{
  int c, d, e, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(721, trans, move);
  d = AFFINE_TRANSFORM(720, trans, move);
  e = AFFINE_TRANSFORM(683, trans, move);
  A = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(757, trans, move);

  return  (owl_escape_value(A) > 0 || owl_escape_value(B) > 0) && ((somewhere(OTHER_COLOR(color), 0, 1, d) && play_attack_defend2_n(OTHER_COLOR(color), 1, 2, move, c, c, e))     || (!somewhere(OTHER_COLOR(color), 0, 1, d) && !play_attack_defend2_n(OTHER_COLOR(color), 0, 3, move, c, d, c, e)));
}

static int
autohelperowl_attackpat231(int trans, int move, int color, int action)
{
  int c, d, e, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(721, trans, move);
  d = AFFINE_TRANSFORM(720, trans, move);
  e = AFFINE_TRANSFORM(683, trans, move);
  A = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(757, trans, move);

  return  (owl_escape_value(A) > 0 || owl_escape_value(B) > 0) && ((somewhere(OTHER_COLOR(color), 0, 1, d) && play_attack_defend2_n(OTHER_COLOR(color), 1, 2, move, c, c, e))     || (!somewhere(OTHER_COLOR(color), 0, 1, d) && !play_attack_defend2_n(OTHER_COLOR(color), 0, 3, move, c, d, c, e)));
}

static int
autohelperowl_attackpat232(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);

  return !play_attack_defend_n(color, 1, 2, move, a, move)&& (somewhere(color, 0, 1, b) || !play_attack_defend_n(color, 1, 2, move, b, move));
}

static int
autohelperowl_attackpat234(int trans, int move, int color, int action)
{
  int b, c, d, e, f, g, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(685, trans, move);
  d = AFFINE_TRANSFORM(722, trans, move);
  e = AFFINE_TRANSFORM(723, trans, move);
  f = AFFINE_TRANSFORM(758, trans, move);
  g = AFFINE_TRANSFORM(759, trans, move);
  A = AFFINE_TRANSFORM(686, trans, move);

  return !owl_goal_dragon(A) && !play_attack_defend2_n(color, 1, 5, move, b, c, d, e, c, e)&& (somewhere(color, 0, 1, f) || !play_attack_defend2_n(color, 1, 5, move, d, b, f, g, b, g));
}

static int
autohelperowl_attackpat235(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g, h, i;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(688, trans, move);
  b = AFFINE_TRANSFORM(651, trans, move);
  c = AFFINE_TRANSFORM(614, trans, move);
  d = AFFINE_TRANSFORM(577, trans, move);
  e = AFFINE_TRANSFORM(540, trans, move);
  f = AFFINE_TRANSFORM(539, trans, move);
  g = AFFINE_TRANSFORM(538, trans, move);
  h = AFFINE_TRANSFORM(537, trans, move);
  i = AFFINE_TRANSFORM(536, trans, move);

  return (owl_escape_value(a)>0) + (owl_escape_value(b)>0)+(owl_escape_value(c)>0) + (owl_escape_value(d)>0)+(owl_escape_value(e)>0) + (owl_escape_value(f)>0)+(owl_escape_value(g)>0) + (owl_escape_value(h)>0)+(owl_escape_value(i)>0) < 2;
}

static int
autohelperowl_attackpat236(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(685, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return !owl_goal_dragon(A) && !play_connect_n(color, 1, 1, move, A, B);
}

static int
autohelperowl_attackpat237(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(722, trans, move);
  B = AFFINE_TRANSFORM(646, trans, move);

  return !play_connect_n(color, 1, 1, move, A, B);
}

static int
autohelperowl_attackpat238(int trans, int move, int color, int action)
{
  int a, B, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);
  C = AFFINE_TRANSFORM(686, trans, move);

  return play_connect_n(color, 0, 2, move, a, B, C);
}

static int
autohelperowl_attackpat239(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(646, trans, move);
  B = AFFINE_TRANSFORM(758, trans, move);

  return owl_strong_dragon(B) && !play_connect_n(OTHER_COLOR(color), 0, 1, move, A, B);
}

static int
autohelperowl_attackpat240(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(758, trans, move);
  B = AFFINE_TRANSFORM(646, trans, move);

  return owl_strong_dragon(B) && !play_connect_n(OTHER_COLOR(color), 0, 1, move, A, B);
}

static int
autohelperowl_attackpat241(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(646, trans, move);

  return owl_escape_value(c)>0 && play_attack_defend2_n(OTHER_COLOR(color), 1, 2, move, a, a, b);
}

static int
autohelperowl_attackpat242(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(685, trans, move);

  return  play_break_through_n(OTHER_COLOR(color), 2, move, a, b, a, c) == WIN;
}

static int
autohelperowl_attackpat243(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(685, trans, move);

  return  countlib(b)<=4 && countlib(c)<=4 && play_break_through_n(OTHER_COLOR(color), 2, move, a, b, a, c) == WIN;
}

static int
autohelperowl_attackpat244(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(647, trans, move);

  return  vital_chain(A) && vital_chain(B) && !play_attack_defend2_n(OTHER_COLOR(color), 0, 1, move, A, B);
}

static int
autohelperowl_attackpat245(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(720, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);

  return !play_attack_defend2_n(OTHER_COLOR(color), 0, 3, move, a, b, a, c);
}

static int
autohelperowl_attackpat246(int trans, int move, int color, int action)
{
  int a, A, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  A = AFFINE_TRANSFORM(686, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return  play_attack_defend_n(OTHER_COLOR(color), 1, 2, move, a, B) && !play_attack_defend_n(color, 0, 1, move, A);
}

static int
autohelperowl_attackpat247(int trans, int move, int color, int action)
{
  int a, b, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  A = AFFINE_TRANSFORM(648, trans, move);

  return !ATTACK_MACRO(A) && play_attack_defend_n(OTHER_COLOR(color), 1, 2, move, a, b);
}

static int
autohelperowl_attackpat248(int trans, int move, int color, int action)
{
  int a, A, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  A = AFFINE_TRANSFORM(611, trans, move);
  B = AFFINE_TRANSFORM(647, trans, move);

  return !ATTACK_MACRO(A) && ATTACK_MACRO(a) && !play_attack_defend_n(color, 0, 1, move, B);
}

static int
autohelperowl_attackpat249(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return  vital_chain(a) && vital_chain(b) && !play_attack_defend2_n(OTHER_COLOR(color), 0, 1, move, a, b);
}

static int
autohelperowl_attackpat250(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(611, trans, move);

  return countlib(c)>2 && vital_chain(b) && vital_chain(c)&& play_attack_defend_n(color, 1, 2, move, a, a) && !play_attack_defend2_n(OTHER_COLOR(color), 0, 1, a, b, c);
}

static int
autohelperowl_attackpat251(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(610, trans, move);

  return countlib(c)>2 && vital_chain(b) && vital_chain(c)&& play_attack_defend_n(color, 1, 2, move, a, a) && !play_attack_defend2_n(OTHER_COLOR(color), 0, 1, a, b, c);
}

static int
autohelperowl_attackpat252(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(B) > 0 && does_defend(move, a);
}

static int
autohelperowl_attackpat253(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(609, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);

  return  somewhere(color, 0, 2, a, b) && ATTACK_MACRO(c);
}

static int
autohelperowl_attackpat256(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);

  return  ATTACK_MACRO(a);
}

static int
autohelperowl_attackpat257(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(681, trans, move);
  b = AFFINE_TRANSFORM(573, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_attackpat258(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(574, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_attackpat260(int trans, int move, int color, int action)
{
  int a, b, C, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  C = AFFINE_TRANSFORM(722, trans, move);
  D = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(C)>0 && owl_goal_dragon(D) && !play_attack_defend2_n(OTHER_COLOR(color), 0, 1, move, a, b);
}

static int
autohelperowl_attackpat261(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return !play_attack_defend2_n(OTHER_COLOR(color), 0, 1, move, a, b);
}

static int
autohelperowl_attackpat262(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return !play_attack_defend2_n(OTHER_COLOR(color), 0, 1, move, a, b);
}

static int
autohelperowl_attackpat263(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(610, trans, move);

  return  ATTACK_MACRO(A) && !play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_attackpat264(int trans, int move, int color, int action)
{
  int a, b, c, D, E;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);
  D = AFFINE_TRANSFORM(720, trans, move);
  E = AFFINE_TRANSFORM(685, trans, move);

  return (owl_escape_value(a)>0 || owl_escape_value(b)>0)&& ((somewhere(color, 0, 1, E) || somewhere(OTHER_COLOR(color), 0, 1, E)) || owl_escape_value(a) < 0)&& !play_attack_defend2_n(color, 1, 3, move, c, D, move, D);
}

static int
autohelperowl_attackpat265(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(647, trans, move);

  return !same_string(a, b) && (countlib(a) <= 4 || countlib(b) <= 4 || countlib(c) <= 4);
}

static int
autohelperowl_attackpat266(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);

  return !is_same_dragon(a, b) && !play_connect_n(color, 1, 1, move, a, b);
}

static int
autohelperowl_attackpat267(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);

  return !is_same_dragon(a, b) && !play_connect_n(color, 1, 1, move, a, b);
}

static int
autohelperowl_attackpat268(int trans, int move, int color, int action)
{
  int a, b, c, d, E;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(757, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);
  d = AFFINE_TRANSFORM(720, trans, move);
  E = AFFINE_TRANSFORM(683, trans, move);

  return  (owl_escape_value(a) > 0 || owl_escape_value(b) > 0) && play_attack_defend2_n(OTHER_COLOR(color), 1, 3, move, c, d, c, E);
}

static int
autohelperowl_attackpat269(int trans, int move, int color, int action)
{
  int a, b, c, d, E;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(757, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);
  d = AFFINE_TRANSFORM(720, trans, move);
  E = AFFINE_TRANSFORM(683, trans, move);

  return  (owl_escape_value(a) > 0 || owl_escape_value(b) > 0) && play_attack_defend2_n(OTHER_COLOR(color), 1, 3, move, c, d, c, E);
}

static int
autohelperowl_attackpat270(int trans, int move, int color, int action)
{
  int b, c, d, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(610, trans, move);
  c = AFFINE_TRANSFORM(648, trans, move);
  d = AFFINE_TRANSFORM(647, trans, move);
  A = AFFINE_TRANSFORM(646, trans, move);

  return (owl_escape_value(c) > 0 || owl_escape_value(b) > 0)&& play_attack_defend2_n(color, 0, 2, move, d, A, move);
}

static int
autohelperowl_attackpat271(int trans, int move, int color, int action)
{
  int b, c, d, e, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(648, trans, move);
  d = AFFINE_TRANSFORM(685, trans, move);
  e = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);

  return (owl_escape_value(d) > 0 || owl_escape_value(b) > 0 || owl_escape_value(c) > 0)&& !play_attack_defend2_n(color, 0, 2, e, move, A, e);
}

static int
autohelperowl_attackpat272(int trans, int move, int color, int action)
{
  int b, c, d, e, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(610, trans, move);
  c = AFFINE_TRANSFORM(611, trans, move);
  d = AFFINE_TRANSFORM(648, trans, move);
  e = AFFINE_TRANSFORM(647, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);

  return (owl_escape_value(d) > 0 || owl_escape_value(b) > 0 || owl_escape_value(c) > 0)&& play_connect_n(OTHER_COLOR(color), 1, 2, e, move, e, A)&& play_connect_n(color, 0, 2, move, e, e, A);
}

static int
autohelperowl_attackpat274(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return  vital_chain(a) && vital_chain(b) && play_attack_defend2_n(OTHER_COLOR(color), 1, 1, move, a, b) && !play_connect_n(OTHER_COLOR(color), 1, 1, move, a, b);
}

static int
autohelperowl_attackpat275(int trans, int move, int color, int action)
{
  int b, c, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);
  A = AFFINE_TRANSFORM(646, trans, move);

  return  (ATTACK_MACRO(A) != WIN || (countstones(A)<=2 && does_attack(move, A))) && (!owl_goal_dragon(b) || !owl_goal_dragon(c));
}

static int
autohelperowl_attackpat276(int trans, int move, int color, int action)
{
  int b, c, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);
  A = AFFINE_TRANSFORM(646, trans, move);

  return  (ATTACK_MACRO(A) != WIN || (countstones(A)<=2 && does_attack(move, A))) && (!owl_goal_dragon(b) || !owl_goal_dragon(c));
}

static int
autohelperowl_attackpat277(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(722, trans, move);
  d = AFFINE_TRANSFORM(648, trans, move);

  return  owl_escape_value(a) > 0 && play_attack_defend_n(color, 1, 1, move, b) && !play_attack_defend_n(color, 1, 3, move, c, d, d);
}

static int
autohelperowl_attackpat278(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(OTHER_COLOR(color), 1, 2, move, a, B);
}

static int
autohelperowl_attackpat280(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(646, trans, move);
  B = AFFINE_TRANSFORM(757, trans, move);

  return owl_strong_dragon(A) && !play_connect_n(OTHER_COLOR(color), 0, 1, move, A, B);
}

static int
autohelperowl_attackpat282(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  b = AFFINE_TRANSFORM(611, trans, move);
  c = AFFINE_TRANSFORM(612, trans, move);
  d = AFFINE_TRANSFORM(649, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) +owl_escape_value(c) + owl_escape_value(d) > 0;
}

static int
autohelperowl_attackpat283(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(611, trans, move);
  b = AFFINE_TRANSFORM(612, trans, move);
  c = AFFINE_TRANSFORM(613, trans, move);
  d = AFFINE_TRANSFORM(650, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) +owl_escape_value(c) + owl_escape_value(d) > 0;
}

static int
autohelperowl_attackpat284(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(646, trans, move);

  return  countlib(a) == 1 && owl_escape_value(B) > 0;
}

static int
autohelperowl_attackpat285(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(720, trans, move);

  return  countlib(a) == 1 && owl_escape_value(B) > 0;
}

static int
autohelperowl_attackpat286(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return  countlib(a) == 1;
}

static int
autohelperowl_attackpat287(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return  countlib(a) == 1;
}

static int
autohelperowl_attackpat288(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(758, trans, move);
  B = AFFINE_TRANSFORM(646, trans, move);

  return owl_escape_value(A)>0 && !play_connect_n(OTHER_COLOR(color), 0, 1, move, A, B) && !play_connect_n(color, 1, 1, move, A, B);
}

static int
autohelperowl_attackpat289(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(758, trans, move);
  B = AFFINE_TRANSFORM(647, trans, move);

  return owl_escape_value(A)>0 && !play_connect_n(OTHER_COLOR(color), 0, 1, move, A, B) && !play_connect_n(color, 1, 1, move, A, B);
}

static int
autohelperowl_attackpat290(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(719, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  c = AFFINE_TRANSFORM(645, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_attackpat292(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(649, trans, move);
  c = AFFINE_TRANSFORM(650, trans, move);
  d = AFFINE_TRANSFORM(722, trans, move);

  return play_attack_defend_n(color, 1, 1, b, d) && play_attack_defend_n(color, 1, 2, move, a, a)&& play_attack_defend_n(color, 1, 4, move, b, NO_MOVE, a, a) && !play_attack_defend_n(color, 1, 2, move, b, c);
}

static int
autohelperowl_attackpat293(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return  (countlib(a)==1) && (countlib(B)==1);
}

static int
autohelperowl_attackpat294(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countstones(A)>3 && countlib(A)==1;
}

static int
autohelperowl_attackpat295(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countstones(A)<=3 && countlib(A)==1 && accuratelib(move, color, MAX_LIBERTIES, NULL) > 1;
}

static int
autohelperowl_attackpat296(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countstones(A)>3 && does_attack(move, A);
}

static int
autohelperowl_attackpat297(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countstones(A)<=3 && does_attack(move, A)&& (accuratelib(move, color, MAX_LIBERTIES, NULL) > 1 || is_ko_point(move));
}

static int
autohelperowl_attackpat298(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);

  return  does_attack(move, A);
}

static int
autohelperowl_attackpat300(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return owl_proper_eye(move);
}

static int
autohelperowl_attackpat301(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(643, trans, move);
  b = AFFINE_TRANSFORM(644, trans, move);

  return  somewhere(color, 0, 2, a, b);
}

static int
autohelperowl_attackpat305(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return DEFEND_MACRO(a) != WIN;
}

static int
autohelperowl_attackpat306(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(720, trans, move);
  A = AFFINE_TRANSFORM(647, trans, move);

  return countlib(A)==2 && !obvious_false_eye(b, OTHER_COLOR(color));
}

static int
autohelperowl_attackpat312(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);

  return countlib(a)>1 && !obvious_false_eye(b, OTHER_COLOR(color));
}

static int
autohelperowl_attackpat319(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(645, trans, move);

  return !ATTACK_MACRO(a);
}

static int
autohelperowl_attackpat322(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(645, trans, move);

  return countlib(A) == 4 && ATTACK_MACRO(A) != WIN;
}

static int
autohelperowl_attackpat323(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(757, trans, move);

  return countlib(A) == 2 && ATTACK_MACRO(A) != WIN;
}

static int
autohelperowl_attackpat324(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(646, trans, move);

  return !ATTACK_MACRO(A);
}

static int
autohelperowl_attackpat326(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(682, trans, move);

  return !ATTACK_MACRO(A);
}

static int
autohelperowl_attackpat337(int trans, int move, int color, int action)
{
  int a, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)<=3 && DEFEND_MACRO(a) != WIN;
}

static int
autohelperowl_attackpat338(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(757, trans, move);

  return play_attack_defend_n(color, 1, 1, a, a);
}

static int
autohelperowl_attackpat339(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return play_attack_defend_n(color, 0, 2, move, a, move);
}

static int
autohelperowl_attackpat340(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(611, trans, move);
  B = AFFINE_TRANSFORM(610, trans, move);

  return !somewhere(OTHER_COLOR(color), 0, 1, a) || (countlib(B) <= 6);
}

static int
autohelperowl_attackpat342(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(573, trans, move);

  return play_attack_defend_n(color, 1, 1, a, a) != 0 && !play_attack_defend_n(color, 1, 1, a, b);
}

static int
autohelperowl_attackpat343(int trans, int move, int color, int action)
{
  int a, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(759, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);

  return play_attack_defend_n(color, 1, 1, a, c) != 0 || play_attack_defend_n(color, 1, 1, a, a);
}

static int
autohelperowl_attackpat344(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(757, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);
  d = AFFINE_TRANSFORM(758, trans, move);

  return !play_attack_defend_n(color, 1, 3, move, a, b, b) && play_attack_defend_n(color, 0, 2, move, c, d);
}

static int
autohelperowl_attackpat356(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(719, trans, move);
  B = AFFINE_TRANSFORM(645, trans, move);

  return countlib(a)==1 && countlib(B)<=3 && DEFEND_MACRO(a)!=WIN;
}

static int
autohelperowl_attackpat357(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(722, trans, move);

  return !ATTACK_MACRO(A);
}

static int
autohelperowl_attackpat358(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(722, trans, move);

  return !ATTACK_MACRO(A);
}

static int
autohelperowl_attackpat359(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(718, trans, move);

  return countlib(A)==3;
}

static int
autohelperowl_attackpat363(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)==2 && accuratelib(move, color, MAX_LIBERTIES, NULL)>1 && finish_ko_helper(A);
}

static int
autohelperowl_attackpat364(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)==2 && accuratelib(move, color, MAX_LIBERTIES, NULL)>1 && finish_ko_helper(A);
}

static int
autohelperowl_attackpat365(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return owl_escape_value(A) > 0 || owl_escape_value(B) > 0;
}

static int
autohelperowl_attackpat366(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return owl_escape_value(A) > 0 || owl_escape_value(B) > 0;
}

static int
autohelperowl_attackpat367(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(614, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(648, trans, move);

  return !ATTACK_MACRO(a) && !play_attack_defend_n(OTHER_COLOR(color), 0, 1, b, c);
}

static int
autohelperowl_attackpat368(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(648, trans, move);

  return !safe_move(a, color) && play_attack_defend_n(color, 0, 2, move, a, move) && !play_attack_defend_n(color, 1, 3, move, b, c, c);
}

static int
autohelperowl_attackpat369(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  C = AFFINE_TRANSFORM(682, trans, move);

  return !play_attack_defend_n(color, 0, 3, move, a, b, C);
}

static int
autohelperowl_attackpat370(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);
  C = AFFINE_TRANSFORM(610, trans, move);

  return !play_attack_defend_n(color, 0, 3, move, a, b, C);
}

static int
autohelperowl_attackpat371(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(758, trans, move);

  return !play_attack_defend_n(color, 0, 3, move, NO_MOVE, a, B);
}

static int
autohelperowl_attackpat372(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(758, trans, move);

  return !play_attack_defend_n(color, 0, 3, move, NO_MOVE, a, B);
}

static int
autohelperowl_attackpat373(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(682, trans, move);

  return !play_attack_defend_n(color, 0, 3, move, NO_MOVE, a, B);
}

static int
autohelperowl_attackpat374(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(610, trans, move);

  return !play_attack_defend_n(color, 0, 3, move, NO_MOVE, a, B);
}

static int
autohelperowl_attackpat378(int trans, int move, int color, int action)
{
  int b, c, d, e, f, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(571, trans, move);
  c = AFFINE_TRANSFORM(647, trans, move);
  d = AFFINE_TRANSFORM(646, trans, move);
  e = AFFINE_TRANSFORM(609, trans, move);
  f = AFFINE_TRANSFORM(683, trans, move);
  A = AFFINE_TRANSFORM(608, trans, move);

  return countlib(A)==3 && !ATTACK_MACRO(b) && !play_attack_defend_n(color, 1, 5, move, c, d, e, f, f);
}

static int
autohelperowl_attackpat379(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);
  d = AFFINE_TRANSFORM(720, trans, move);
  e = AFFINE_TRANSFORM(683, trans, move);
  f = AFFINE_TRANSFORM(794, trans, move);

  return play_attack_defend_n(color, 1, 6, move, a, b, c, d, e, e) && !play_attack_defend_n(color, 1, 1, move, f);
}

static int
autohelperowl_attackpat380(int trans, int move, int color, int action)
{
  int e, A, B, C, D;
  UNUSED(color);
  UNUSED(action);

  e = AFFINE_TRANSFORM(685, trans, move);
  A = AFFINE_TRANSFORM(797, trans, move);
  B = AFFINE_TRANSFORM(686, trans, move);
  C = AFFINE_TRANSFORM(760, trans, move);
  D = AFFINE_TRANSFORM(722, trans, move);

  return countlib(A) > 2 && !play_attack_defend_n(color, 0, 7, move, NO_MOVE, B, NO_MOVE, C, NO_MOVE, D, e);
}

static int
autohelperowl_attackpat382(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(757, trans, move);
  B = AFFINE_TRANSFORM(756, trans, move);

  return  countlib(A) == 2 && countlib(B) > 1 && accuratelib(move, color, MAX_LIBERTIES, NULL) > 1;
}

static int
autohelperowl_attackpat383(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  B = AFFINE_TRANSFORM(574, trans, move);

  return  owl_proper_eye(a) && !ATTACK_MACRO(B);
}

static struct pattern_attribute attributes[] = {
#ifdef HAVE_TRANSPARENT_UNIONS
  {LAST_ATTRIBUTE,{.offset=0}},
  {THREATENS_TO_CAPTURE,{.offset=757}},
  {LAST_ATTRIBUTE,{.offset=0}},
  {THREATENS_EYE,{.offset=610}},
  {LAST_ATTRIBUTE,{.offset=0}}
#else
  {LAST_ATTRIBUTE,0.0,0},
  {THREATENS_TO_CAPTURE,0.0,757},
  {LAST_ATTRIBUTE,0.0,0},
  {THREATENS_EYE,0.0,610},
  {LAST_ATTRIBUTE,0.0,0}
#endif
};

static struct pattern owl_attackpat[] = {
  {owl_attackpat0,3,8, "A1",-1,-2,2,2,3,4,0x2,683,
    { 0xfdffffff, 0xfcfcfcf4, 0xfffffc00, 0xffffff3f, 0xfcfcfcf0, 0xfffffd00, 0xffffff7f, 0xfcffffff},
    { 0x041a0000, 0x00102420, 0x00904000, 0x60100000, 0x24100000, 0x001a0400, 0x00106020, 0x40900000}
   , 0x20,80.000000,attributes+0,1,NULL,autohelperowl_attackpat0,0,0.010000},
  {owl_attackpat1,3,8, "A2",-2,-2,2,2,4,4,0x2,683,
    { 0xfdffffff, 0xfffffff7, 0xfffffcfc, 0xffffff3f, 0xfffffff0, 0xfffffdff, 0xffffff7f, 0xfcffffff},
    { 0x00180000, 0x00102200, 0x00900080, 0x20100000, 0x22100000, 0x00180008, 0x00102000, 0x00900000}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat2,2,8, "A3",-1,-2,2,1,3,3,0x2,720,
    { 0xfcfcf000, 0xffff3f00, 0x3fffffff, 0xf0fcfcfc, 0x3fffffff, 0xf0fcfcfc, 0xfcfcf000, 0xffff3f00},
    { 0x00242000, 0x00a11000, 0x20600010, 0x10280000, 0x10a10000, 0x20240010, 0x00281000, 0x00602000}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat3,1,8, "A101",-1,0,2,2,3,2,0x2,721,
    { 0x3f3f3800, 0x00ffbf3f, 0xb0f0f0f0, 0xf8fc0000, 0xbfff0000, 0x383f3f3f, 0x00fcf8f0, 0xf0f0b000},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat4,3,8, "A102",-1,-2,2,2,3,4,0x2,721,
    { 0xfcffffff, 0xfcfcfcf0, 0xffffff00, 0xffffffff, 0xfcfcfcfc, 0xfffffc00, 0xffffff3f, 0xffffffff},
    { 0x40902000, 0x24900000, 0x201a0500, 0x00186060, 0x00902424, 0x20904000, 0x60180000, 0x051a2000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat5,4,8, "A103",-2,-2,1,1,3,3,0x2,720,
    { 0xfffefc00, 0xfcfdfd2c, 0xfcfcfc50, 0xfcfcfc00, 0xfdfdfc00, 0xfcfeff14, 0xfcfcfce0, 0xfcfcfc00},
    { 0x01102800, 0x00908004, 0xa0100000, 0x08180000, 0x80900000, 0x28100100, 0x00180840, 0x0010a000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat6,2,8, "A104",-1,-2,2,1,3,3,0x2,721,
    { 0xfcffffff, 0xfcfcfcf0, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xfffffc00, 0xffffff3f, 0xfcfcfcfc},
    { 0x40902000, 0x24900000, 0x20180400, 0x00186000, 0x00902400, 0x20904000, 0x60180000, 0x04182000}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_attackpat6,0,0.010000},
  {owl_attackpat7,3,8, "A105",-1,-3,2,2,3,5,0x2,721,
    { 0x7fffffff, 0xf4fcfcfc, 0xfffff700, 0xffff7fff, 0xfcfcf4fc, 0xffff7f00, 0x7fffffff, 0xf7ffffff},
    { 0x10200000, 0x00240000, 0x00201200, 0x00600080, 0x00240008, 0x00201000, 0x00600000, 0x12200000}
   , 0x0,99.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat8,3,8, "A106",-2,-2,1,1,3,3,0x2,647,
    { 0xfcfcfc00, 0xffffff00, 0xfcfcfffc, 0xfcfcfcc0, 0xffffff0c, 0xfcfcfcfc, 0xfcfcfc00, 0xfffcfc00},
    { 0x00205000, 0x40620000, 0x14200220, 0x00240480, 0x00624008, 0x50200020, 0x04240000, 0x02201400}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat9,1,8, "A107",-1,0,2,4,3,4,0x2,686,
    { 0x00ffffff, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3f, 0x00fcfcfc},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat10,3,8, "A108",-1,-1,1,1,2,2,0x2,648,
    { 0x5cfcfc00, 0xf4f4fc00, 0xfcfcd400, 0xfc7c7c00, 0xfcf4f400, 0xfcfc5c00, 0x7c7cfc00, 0xd4fcfc00},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x20,70.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat11,1,8, "A109",-1,0,2,2,3,2,0x2,685,
    { 0x00f8fcf8, 0xf0f0e000, 0xffbf0000, 0x2e3f3f3f, 0xe0f0f0f0, 0xfcf80000, 0x3f3f2e00, 0x00bfffbf},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x0,79.000000,attributes+0,1,NULL,autohelperowl_attackpat11,3,0.016000},
  {owl_attackpat12,3,8, "A110",-1,-1,2,2,3,3,0x2,721,
    { 0xfeffffff, 0xfcfcfcf8, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xfffffe00, 0xffffffbf, 0xfcfcfcfc},
    { 0x4090a000, 0xa4900000, 0x28180400, 0x00186800, 0x0090a400, 0xa0904000, 0x68180000, 0x04182800}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat13,2,8, "A111",-2,0,2,3,4,3,0x2,686,
    { 0x0037ffff, 0xc0f0d0f0, 0xff700000, 0x1f3f0f0e, 0xd0f0c0c0, 0xff370000, 0x0f3f1f3f, 0x0070fffe},
    { 0x00200000, 0x00200000, 0x01200000, 0x00200004, 0x00200040, 0x00200000, 0x00200000, 0x00200100}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat14,2,8, "A112",-1,-2,2,1,3,3,0x2,683,
    { 0xfcfcf000, 0xffff3f00, 0x3fffffff, 0xf0fcfcfc, 0x3fffffff, 0xf0fcfcfc, 0xfcfcf000, 0xffff3f00},
    { 0x00242000, 0x00a11000, 0x20600010, 0x10280000, 0x10a10000, 0x20240010, 0x00281000, 0x00602000}
   , 0x0,79.000000,attributes+0,1,NULL,autohelperowl_attackpat14,3,0.010000},
  {owl_attackpat15,3,8, "A113",-2,-3,1,0,3,3,0x8,685,
    { 0x003ffdff, 0xc0f0f070, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xfd3f0000, 0x0f3f3f37, 0x00f0fcfc},
    { 0x00128000, 0x80100020, 0x08100000, 0x00100800, 0x00108000, 0x80120000, 0x08100020, 0x00100800}
   , 0x0,99.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat16,2,8, "A114",0,-2,3,1,3,3,0x8,686,
    { 0x00fcfcfc, 0xf0f0f000, 0xffff0000, 0x3f3f3f3f, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0x00ffffff},
    { 0x00200004, 0x00200000, 0x00200000, 0x01200000, 0x00200000, 0x00200000, 0x00200100, 0x00200040}
   , 0x0,99.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat17,2,8, "A115",0,-3,3,1,3,4,0x2,648,
    { 0x00f0fcfc, 0xf0f0c000, 0xff3f0000, 0x0f3f3f3f, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0f00, 0x003fffff},
    { 0x00200800, 0x00208000, 0x80200000, 0x08200000, 0x80200000, 0x08200000, 0x00200800, 0x00208000}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_attackpat17,3,0.010000},
  {owl_attackpat18,4,8, "A201",-1,-2,2,2,3,4,0x2,611,
    { 0xffffffff, 0xfcfcfcfc, 0xffffff00, 0xffffffff, 0xfcfcfcfc, 0xffffff00, 0xffffffff, 0xffffffff},
    { 0x055aa000, 0x90902424, 0x28944000, 0x60181800, 0x24909000, 0xa05a0500, 0x18186060, 0x40942800}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat18,0,1.600000},
  {owl_attackpat19,4,8, "A203",-1,-2,1,1,2,3,0x2,721,
    { 0x0c7dff00, 0xd0f0fcd0, 0xfcf4c000, 0xfc3c1c00, 0xfcf0d000, 0xff7d0c00, 0x1c3cfc1c, 0xc0f4fc00},
    { 0x04208000, 0x80200400, 0x08204000, 0x40200800, 0x04208000, 0x80200400, 0x08204000, 0x40200800}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat20,1,8, "A204",0,-2,2,2,2,4,0x2,685,
    { 0x0030fcff, 0xc0f0c000, 0xfc300000, 0x0f3f0f03, 0xc0f0c000, 0xfc300000, 0x0f3f0f03, 0x0030fcff},
    { 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x80100000, 0x08100000, 0x00100800, 0x00108000}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat21,2,8, "A205",-1,-1,1,1,2,2,0x2,683,
    { 0xf8fcf000, 0xfcfc3800, 0x3cfcbc00, 0xb0fcfc00, 0x38fcfc00, 0xf0fcf800, 0xfcfcb000, 0xbcfc3c00},
    { 0x00242000, 0x00a01000, 0x20600000, 0x10280000, 0x10a00000, 0x20240000, 0x00281000, 0x00602000}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat22,2,8, "A205b",-1,-1,1,1,2,2,0x2,647,
    { 0xb0fcfc00, 0xf8fcf000, 0xfcfc3800, 0x3cfcbc00, 0xf0fcf800, 0xfcfcb000, 0xbcfc3c00, 0x38fcfc00},
    { 0x10281000, 0x00642000, 0x10a01000, 0x20640000, 0x20640000, 0x10281000, 0x00642000, 0x10a01000}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat23,2,8, "A206",-1,-1,2,1,3,2,0x2,648,
    { 0x30bcfcfc, 0xe0fcf000, 0xfcf83000, 0x3fff2f00, 0xf0fce000, 0xfcbc3000, 0x2fff3f00, 0x30f8fcfc},
    { 0x10182000, 0x00942000, 0x20901000, 0x20580000, 0x20940000, 0x20181000, 0x00582000, 0x10902000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat24,2,8, "A206b",-1,-1,2,1,3,2,0x2,722,
    { 0x3cfcfcfc, 0xf0fcfc00, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xfcfc3c00, 0x3fffff00, 0xf0fcfcfc},
    { 0x04902000, 0x20900400, 0x20184000, 0x40182000, 0x04902000, 0x20900400, 0x20184000, 0x40182000}
   , 0x0,78.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat25,1,8, "A207",0,0,2,2,2,2,0x2,722,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat26,3,8, "A207b",0,-2,2,1,2,3,0x2,722,
    { 0x007f7f3f, 0x50f0f0f0, 0xf4f40000, 0x3f3f1400, 0xf0f05000, 0x7f7f0000, 0x143f3f3f, 0x00f4f4f0},
    { 0x00210000, 0x00200010, 0x00200000, 0x00200000, 0x00200000, 0x00210000, 0x00200010, 0x00200000}
   , 0x0,58.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat27,5,8, "A207c",0,-3,2,2,2,5,0x2,722,
    { 0x007f7f3f, 0x50f0f0f0, 0xf5f50000, 0x3f3f1414, 0xf0f05050, 0x7f7f0000, 0x143f3f3f, 0x00f5f5f0},
    { 0x00210000, 0x00200010, 0x00200000, 0x00200000, 0x00200000, 0x00210000, 0x00200010, 0x00200000}
   , 0x0,78.000000,attributes+0,1,NULL,autohelperowl_attackpat27,3,0.610000},
  {owl_attackpat28,6,8, "A207d",0,-3,2,2,2,5,0x2,722,
    { 0x007f7f3f, 0x50f0f0f0, 0xf5f50000, 0x3f3f1414, 0xf0f05050, 0x7f7f0000, 0x143f3f3f, 0x00f5f5f0},
    { 0x00210000, 0x00200010, 0x00200000, 0x00200000, 0x00200000, 0x00210000, 0x00200010, 0x00200000}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat28,3,1.000000},
  {owl_attackpat29,2,8, "A208a",-1,-2,1,0,2,2,0x2,686,
    { 0x00bcbcfc, 0xa0f0f000, 0xf8f80000, 0x3f3f2b00, 0xf0f0a000, 0xbcbc0000, 0x2b3f3f00, 0x00f8f8fc},
    { 0x00280004, 0x00202000, 0x00a00000, 0x21200000, 0x20200000, 0x00280000, 0x00202100, 0x00a00040}
   , 0x0,55.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat30,1,8, "A208b",-1,-2,1,0,2,2,0x2,686,
    { 0x00f8f8fc, 0xf0f0a000, 0xbcbc0000, 0x2b3f3f00, 0xa0f0f000, 0xf8f80000, 0x3f3f2b00, 0x00bcbcfc},
    { 0x00200040, 0x00200000, 0x00200000, 0x00200100, 0x00200000, 0x00200000, 0x01200000, 0x00200004}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat31,4,8, "A208c",-1,0,2,2,3,2,0x2,722,
    { 0x003ffe7e, 0xc0f0f0b0, 0xfcf00000, 0x3f3f0d00, 0xf0f0c000, 0xfe3f0000, 0x0d3f3f3a, 0x00f0fcf4},
    { 0x00108028, 0x80100000, 0x08100000, 0x02120800, 0x00108000, 0x80100000, 0x08120200, 0x001008a0}
   , 0x0,56.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat32,2,8, "A208d",-1,-2,1,0,2,2,0x2,685,
    { 0x00bcbcfc, 0xa0f0f000, 0xf8f80000, 0x3f3f2b00, 0xf0f0a000, 0xbcbc0000, 0x2b3f3f00, 0x00f8f8fc},
    { 0x00280004, 0x00202000, 0x00a00000, 0x21200000, 0x20200000, 0x00280000, 0x00202100, 0x00a00040}
   , 0x0,56.000000,attributes+0,1,NULL,autohelperowl_attackpat32,3,1.000000},
  {owl_attackpat33,3,8, "A209",-1,-1,1,2,2,3,0x2,721,
    { 0x3a7f7f00, 0x50fcf8f8, 0xf4f4b000, 0xbcfc1400, 0xf8fc5000, 0x7f7f3a00, 0x14fcbcbc, 0xb0f4f400},
    { 0x10200000, 0x00240000, 0x00201000, 0x00600000, 0x00240000, 0x00201000, 0x00600000, 0x10200000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat33,3,0.010000},
  {owl_attackpat34,5,8, "A210",-1,-1,1,3,2,4,0x2,721,
    { 0x3c7f7f00, 0x50fcfcf0, 0xf4f4f000, 0xfcfc1400, 0xfcfc5000, 0x7f7f3c00, 0x14fcfc3c, 0xf0f4f400},
    { 0x14200000, 0x00240400, 0x00205000, 0x40600000, 0x04240000, 0x00201400, 0x00604000, 0x50200000}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_attackpat34,3,0.010000},
  {owl_attackpat35,1,8, "A211",0,-1,3,2,3,3,0x2,723,
    { 0x0038bfbf, 0x80f0e0c0, 0xf8b00000, 0x2f3f0a00, 0xe0f08000, 0xbf380000, 0x0a3f2f0f, 0x00b0f8f8},
    { 0x00100200, 0x00100080, 0x00100000, 0x00100000, 0x00100000, 0x02100000, 0x00100008, 0x00100000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat36,3,8, "A214",-1,-1,1,2,2,3,0x1,685,
    { 0x7cfcfc3c, 0xf4fcfc00, 0xfcfcf400, 0xffff7c00, 0xfcfcf400, 0xfcfc7c00, 0x7cffff00, 0xf4fcfcf0},
    { 0x20904000, 0x60180000, 0x04182000, 0x00902400, 0x00186000, 0x40902000, 0x24900000, 0x20180400}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_attackpat36,0,0.010000},
  {owl_attackpat37,4,8, "A215",-1,-1,2,2,3,3,0x2,647,
    { 0x40f8fcf4, 0xf4f0e000, 0xffbf0700, 0x2d3f7fff, 0xe0f0f4fc, 0xfcf84000, 0x7f3f2d00, 0x07bfff7f},
    { 0x00102420, 0x00904000, 0x60100000, 0x041a0000, 0x40900000, 0x24100000, 0x001a0400, 0x00106020}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat38,2,8, "A216",-1,-1,2,1,3,2,0x2,722,
    { 0x0cfcfcfc, 0xf0f0fc00, 0xfcfcc000, 0xff3f3f00, 0xfcf0f000, 0xfcfc0c00, 0x3f3fff00, 0xc0fcfcfc},
    { 0x04a40000, 0x20201400, 0x00684000, 0x50202000, 0x14202000, 0x00a40400, 0x20205000, 0x40680000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat39,2,8, "A216b",-1,-1,2,1,3,2,0x2,685,
    { 0x0cfcfcfc, 0xf0f0fc00, 0xfcfcc000, 0xff3f3f00, 0xfcf0f000, 0xfcfc0c00, 0x3f3fff00, 0xc0fcfcfc},
    { 0x04a40000, 0x20201400, 0x00684000, 0x50202000, 0x14202000, 0x00a40400, 0x20205000, 0x40680000}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat39,3,1.000000},
  {owl_attackpat40,2,8, "A217",0,-1,2,2,2,3,0x2,685,
    { 0x003fffff, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3f0000, 0x0f3f3f3f, 0x00f0fcfc},
    { 0x001a0000, 0x00102020, 0x00900000, 0x20100000, 0x20100000, 0x001a0000, 0x00102020, 0x00900000}
   , 0x0,40.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat41,2,8, "A217b",0,-1,2,2,2,3,0x2,685,
    { 0x003fffff, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3f0000, 0x0f3f3f3f, 0x00f0fcfc},
    { 0x001a0000, 0x00102020, 0x00900000, 0x20100000, 0x20100000, 0x001a0000, 0x00102020, 0x00900000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_attackpat41,0,0.010000},
  {owl_attackpat42,2,8, "A217c",0,-1,2,2,2,3,0x2,685,
    { 0x00ffffff, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3f, 0x00fcfcfc},
    { 0x001a0000, 0x00102020, 0x00900000, 0x20100000, 0x20100000, 0x001a0000, 0x00102020, 0x00900000}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat42,0,3.000000},
  {owl_attackpat43,2,8, "A218",-1,-1,2,2,3,3,0x2,685,
    { 0xffffffff, 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xffffff00, 0xffffffff, 0xfcfcfcfc},
    { 0x051a0000, 0x00102424, 0x00904000, 0x60100000, 0x24100000, 0x001a0500, 0x00106060, 0x40900000}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat44,2,8, "A219",-1,-1,2,2,3,3,0x2,722,
    { 0xfcfcfffc, 0xfcfcfcc0, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xfffcfc00, 0xffffff0c, 0xfcfcfcfc},
    { 0x40902000, 0x24900000, 0x20180400, 0x00186000, 0x00902400, 0x20904000, 0x60180000, 0x04182000}
   , 0x10,70.000000,attributes+0,1,NULL,autohelperowl_attackpat44,0,0.277760},
  {owl_attackpat45,4,8, "A220",-2,-1,1,2,3,3,0x2,721,
    { 0x177fff00, 0xd0f4f4fc, 0xfcf45000, 0x7c7c1c00, 0xf4f4d000, 0xff7f1700, 0x1c7c7cfc, 0x50f4fc00},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat45,3,0.376000},
  {owl_attackpat46,4,8, "A221",-2,-1,1,3,3,4,0x2,758,
    { 0x177fff00, 0xd0f4f4fc, 0xfcf45000, 0x7c7c1c00, 0xf4f4d000, 0xff7f1700, 0x1c7c7cfc, 0x50f4fc00},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_attackpat46,3,0.010000},
  {owl_attackpat47,3,8, "A222",-2,-2,1,3,3,5,0x2,721,
    { 0xeaffff00, 0xfefbfaf8, 0xffffacb8, 0xbcbcfc3c, 0xfafbfef0, 0xffffeab8, 0xfcbcbcbc, 0xacffff00},
    { 0x40608000, 0x94210000, 0x08260410, 0x00205820, 0x00219420, 0x80604010, 0x58200000, 0x04260800}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat48,1,8, "A223",0,0,2,2,2,2,0x2,759,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat48,0,0.610000},
  {owl_attackpat49,2,8, "A224",-1,-1,2,2,3,3,0x2,722,
    { 0x00fcffff, 0xf0f0f0c0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfffc0000, 0x3f3f3f0f, 0x00fcfcfc},
    { 0x0050a000, 0x90900000, 0x28140000, 0x00181800, 0x00909000, 0xa0500000, 0x18180000, 0x00142800}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat49,0,1.000000},
  {owl_attackpat50,3,8, "A225",0,-1,2,2,2,3,0x2,685,
    { 0x003cfffd, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0d, 0x00f0fcfc},
    { 0x00180200, 0x00102080, 0x00900000, 0x20100000, 0x20100000, 0x02180000, 0x00102008, 0x00900000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat51,3,8, "A226",0,-1,2,2,2,3,0x2,685,
    { 0x00fcfffd, 0xf0f0f0c0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfffc0000, 0x3f3f3f0d, 0x00fcfcfc},
    { 0x00180200, 0x00102080, 0x00900000, 0x20100000, 0x20100000, 0x02180000, 0x00102008, 0x00900000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat51,0,2.800000},
  {owl_attackpat52,6,8, "A227",-1,-2,1,2,2,4,0x2,721,
    { 0xf5ffff00, 0xfcfcf4f4, 0xfffc7c00, 0x7cfcfc0c, 0xf4fcfcc0, 0xfffff500, 0xfcfc7c7c, 0x7cfcff00},
    { 0x90902000, 0x28940000, 0x22181800, 0x0058a008, 0x00942880, 0x20909000, 0xa0580000, 0x18182200}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_attackpat52,0,0.010000},
  {owl_attackpat53,4,8, "A227b",0,-1,2,2,2,3,0x2,648,
    { 0x00f0fcf4, 0xf0f0c000, 0xff3d0000, 0x0d3f3f1f, 0xc0f0f0d0, 0xfcf00000, 0x3f3f0d00, 0x003dff7f},
    { 0x00100820, 0x00108000, 0x80100000, 0x08120000, 0x80100000, 0x08100000, 0x00120800, 0x00108020}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_attackpat53,0,0.610000},
  {owl_attackpat54,1,8, "A228",0,-2,1,0,1,2,0x2,685,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat54,0,1.000000},
  {owl_attackpat55,5,8, "A229",-1,-3,1,1,2,4,0x2,683,
    { 0xfcfc3c00, 0x3dffff00, 0xf0fcfcf4, 0xfcfcf000, 0xffff3d00, 0x3cfcfc7c, 0xf0fcfc00, 0xfcfcf000},
    { 0x00582000, 0x10902000, 0x20940000, 0x20181000, 0x20901000, 0x20580000, 0x10182000, 0x00942000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat55,0,0.019600},
  {owl_attackpat56,4,8, "A229b",-1,-3,1,0,2,3,0x2,685,
    { 0x003c7c7c, 0x40f0f000, 0xf4f00000, 0x3f3f0500, 0xf0f04000, 0x7c3c0000, 0x053f3f00, 0x00f0f4f4},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x0,79.000000,attributes+0,1,NULL,autohelperowl_attackpat56,0,0.016000},
  {owl_attackpat57,3,8, "A229c",-1,-2,1,0,2,2,0x2,685,
    { 0x003c7c7c, 0x40f0f000, 0xf4f00000, 0x3f3f0500, 0xf0f04000, 0x7c3c0000, 0x053f3f00, 0x00f0f4f4},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x0,79.000000,attributes+0,1,NULL,autohelperowl_attackpat57,0,0.016000},
  {owl_attackpat58,2,8, "A229d",-1,-1,1,0,2,1,0x2,685,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00188000, 0x80102000, 0x08900000, 0x20100800, 0x20108000, 0x80180000, 0x08102000, 0x00900800}
   , 0x0,79.000000,attributes+0,1,NULL,autohelperowl_attackpat58,0,0.010000},
  {owl_attackpat59,1,8, "A230",0,-1,2,2,2,3,0x2,722,
    { 0x0038ffff, 0xc0f0e0c0, 0xfcb00000, 0x2f3f0f00, 0xe0f0c000, 0xff380000, 0x0f3f2f0f, 0x00b0fcfc},
    { 0x00100200, 0x00100080, 0x00100000, 0x00100000, 0x00100000, 0x02100000, 0x00100008, 0x00100000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat59,0,0.016000},
  {owl_attackpat60,1,8, "A231",-1,0,1,3,2,3,0x0,686,
    { 0x003cfcfc, 0xc0f0f000, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xfc3c0000, 0x0f3f3f00, 0x00f0fcfc},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat61,1,8, "A232",0,-1,3,2,3,3,0x2,686,
    { 0x003cfcff, 0xc0f0f000, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xfc3c0000, 0x0f3f3f03, 0x00f0fcfc},
    { 0x00148000, 0x80101000, 0x08500000, 0x10100800, 0x10108000, 0x80140000, 0x08101000, 0x00500800}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat61,0,1.000000},
  {owl_attackpat62,1,8, "A232b",-1,0,2,2,3,2,0x2,722,
    { 0x003fffff, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3f0000, 0x0f3f3f3f, 0x00f0fcfc},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat62,3,0.416000},
  {owl_attackpat63,1,8, "A233",0,-1,3,2,3,3,0x2,686,
    { 0x00fcfcfc, 0xf0f0f000, 0xfffc0000, 0x3f3f3f0c, 0xf0f0f0c0, 0xfcfc0000, 0x3f3f3f00, 0x00fcfffc},
    { 0x00140008, 0x00101000, 0x00500000, 0x12100000, 0x10100000, 0x00140000, 0x00101200, 0x00500080}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat64,3,8, "A234",-1,0,2,1,3,1,0x2,648,
    { 0x00f4fc00, 0xf0f0d000, 0xff7f0000, 0x1c3c3c3c, 0xd0f0f0f0, 0xfcf40000, 0x3c3c1c00, 0x007fff00},
    { 0x00201800, 0x00608000, 0x90200000, 0x08240000, 0x80600000, 0x18200000, 0x00240800, 0x00209000}
   , 0x0,20.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat65,4,8, "A235",-1,-1,1,3,2,4,0x2,758,
    { 0xf73f3f00, 0x0cfcf4fc, 0xf0f07c00, 0x7cfcc000, 0xf4fc0c00, 0x3f3ff700, 0xc0fc7cfc, 0x7cf0f000},
    { 0x00202900, 0x00a08040, 0xa0200000, 0x08280000, 0x80a00000, 0x29200000, 0x00280804, 0x0020a000}
   , 0x0,77.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat66,4,8, "A236",-1,0,2,2,3,2,0x1,758,
    { 0x1f3f3f1f, 0x00f4fcfc, 0xf0f0d000, 0xff7d0000, 0xfcf40000, 0x3f3f1f00, 0x007dffff, 0xd0f0f0d0},
    { 0x00202004, 0x00a00000, 0x20200000, 0x01280000, 0x00a00000, 0x20200000, 0x00280100, 0x00202040}
   , 0x0,66.000000,attributes+0,1,NULL,autohelperowl_attackpat66,3,1.000000},
  {owl_attackpat67,3,8, "A237",-1,-1,1,2,2,3,0x2,721,
    { 0x0f7ffe00, 0xd0f0fcbc, 0xfcf4c000, 0xfc3c1c00, 0xfcf0d000, 0xfe7f0f00, 0x1c3cfcf8, 0xc0f4fc00},
    { 0x04218000, 0x80200410, 0x08204000, 0x40200800, 0x04208000, 0x80210400, 0x08204010, 0x40200800}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat67,3,0.970000},
  {owl_attackpat68,3,8, "A238",0,-1,3,2,3,3,0x2,758,
    { 0x2b3f0f37, 0x0038f8fc, 0xc0f0a000, 0xbdb30000, 0xf8380000, 0x0f3f2b00, 0x00b3bdff, 0xa0f0c070},
    { 0x00100022, 0x00100000, 0x00100000, 0x00120000, 0x00100000, 0x00100000, 0x00120002, 0x00100020}
   , 0x0,55.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat69,1,8, "A239",0,-1,2,1,2,2,0x2,685,
    { 0x00f8fcfc, 0xf0f0e000, 0xfcbc0000, 0x2f3f3f00, 0xe0f0f000, 0xfcf80000, 0x3f3f2f00, 0x00bcfcfc},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat70,2,8, "A240",-1,-2,1,1,2,3,0x2,721,
    { 0x3cfefe00, 0xf0fcfca0, 0xfcfcf000, 0xfcfc3c00, 0xfcfcf000, 0xfefe3c00, 0x3cfcfc28, 0xf0fcfc00},
    { 0x18600000, 0x10240800, 0x00249000, 0x80601000, 0x08241000, 0x00601800, 0x10608000, 0x90240000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat71,1,8, "A241",0,-2,2,1,2,3,0x2,685,
    { 0x00ffbeff, 0xb0f0f0b0, 0xf8fc0000, 0x3f3f3b00, 0xf0f0b000, 0xbeff0000, 0x3b3f3f3b, 0x00fcf8fc},
    { 0x00610000, 0x10200010, 0x00240000, 0x00201000, 0x00201000, 0x00610000, 0x10200010, 0x00240000}
   , 0x0,37.000000,attributes+0,1,NULL,autohelperowl_attackpat71,3,10.000000},
  {owl_attackpat72,2,8, "A242",-1,-3,1,1,2,4,0x2,685,
    { 0x04bcfcfc, 0xe0f0f400, 0xfcf84000, 0x7f3f2f00, 0xf4f0e000, 0xfcbc0400, 0x2f3f7f00, 0x40f8fcfc},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_attackpat72,0,16.000000},
  {owl_attackpat73,3,8, "A301",0,-1,1,2,1,3,0x2,685,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00928000, 0xa0100020, 0x08180000, 0x00102800, 0x0010a000, 0x80920000, 0x28100020, 0x00180800}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat73,0,0.010000},
  {owl_attackpat74,5,8, "A302",-1,-2,1,2,2,4,0x2,648,
    { 0xbcfdfe00, 0xf8fcfc90, 0xfdfcf800, 0xfcfcbc04, 0xfcfcf840, 0xfefdbc00, 0xbcfcfc18, 0xf8fcfd00},
    { 0x18600800, 0x10248800, 0x80249000, 0x88601000, 0x88241000, 0x08601800, 0x10608800, 0x90248000}
   , 0x0,30.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat75,5,8, "A305",0,-1,2,3,2,4,0x2,686,
    { 0x00757fff, 0x50f0d0d0, 0xf4740000, 0x1f3f1700, 0xd0f05000, 0x7f750000, 0x173f1f1f, 0x0074f4fc},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat76,1,8, "A401",-1,0,1,3,2,3,0x0,721,
    { 0x0f3f3f00, 0x00f0fcfc, 0xf0f0c000, 0xfc3c0000, 0xfcf00000, 0x3f3f0f00, 0x003cfcfc, 0xc0f0f000},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat76,3,3.600000},
  {owl_attackpat77,1,8, "A401a",-1,0,1,3,2,3,0x0,721,
    { 0x0f3f3f00, 0x00f0fcfc, 0xf0f0c000, 0xfc3c0000, 0xfcf00000, 0x3f3f0f00, 0x003cfcfc, 0xc0f0f000},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat77,3,3.000000},
  {owl_attackpat78,1,8, "A402",-1,0,2,3,3,3,0x0,722,
    { 0x0f3f3f00, 0x00f0fcfc, 0xf0f0c000, 0xfc3c0000, 0xfcf00000, 0x3f3f0f00, 0x003cfcfc, 0xc0f0f000},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat78,3,0.040000},
  {owl_attackpat79,2,8, "A403",-1,0,1,2,2,2,0x0,723,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00508080, 0x90100000, 0x08140000, 0x00101a00, 0x00109000, 0x80500000, 0x1a100000, 0x00140808}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_attackpat79,0,4.800000},
  {owl_attackpat80,2,8, "A403b",-2,0,1,2,3,2,0x0,723,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00508080, 0x90100000, 0x08140000, 0x00101a00, 0x00109000, 0x80500000, 0x1a100000, 0x00140808}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat80,0,2.890000},
  {owl_attackpat81,5,4, "A404",-1,0,1,2,2,2,0x0,648,
    { 0x00f4fcf4, 0xf0f0d000, 0xfc7c0000, 0x1d3f3f00, 0xd0f0f000, 0xfcf40000, 0x3f3f1d00, 0x007cfc7c},
    { 0x00200820, 0x00208000, 0x80200000, 0x08220000, 0x80200000, 0x08200000, 0x00220800, 0x00208020}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat82,4,8, "A406",-2,-2,1,0,3,2,0x0,685,
    { 0x00f0fcfc, 0xf0f0c000, 0xfd3d0000, 0x0f3f3f15, 0xc0f0f050, 0xfcf00000, 0x3f3f0f00, 0x003dfdfd},
    { 0x00100804, 0x00108000, 0x80100000, 0x09100000, 0x80100000, 0x08100000, 0x00100900, 0x00108040}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_attackpat82,0,0.016000},
  {owl_attackpat83,4,8, "A406b",-2,-3,1,1,3,4,0x0,685,
    { 0xa0f0fcfc, 0xf8f8c000, 0xfd3d2800, 0x0fbfbf15, 0xc0f8f850, 0xfcf0a000, 0xbfbf0f00, 0x283dfdfd},
    { 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x80100000, 0x08100000, 0x00100800, 0x00108000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat83,0,0.151360},
  {owl_attackpat84,3,8, "A406c",-2,-2,1,0,3,2,0x0,723,
    { 0x00fdfdfc, 0xf0f0f050, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfdfd0000, 0x3f3f3f14, 0x00fcfcfc},
    { 0x00508000, 0x90100000, 0x08140000, 0x00101800, 0x00109000, 0x80500000, 0x18100000, 0x00140800}
   , 0x0,81.000000,attributes+0,1,NULL,autohelperowl_attackpat84,0,0.970000},
  {owl_attackpat85,2,8, "A407",-1,-2,2,1,3,3,0x0,721,
    { 0xfcfcfc00, 0xffffff00, 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xfcfcfcfc, 0xfcfcfc00, 0xfcfcfc00},
    { 0x00208400, 0x80204000, 0x48200000, 0x04200800, 0x40208000, 0x84200000, 0x08200400, 0x00204800}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat85,3,0.019600},
  {owl_attackpat86,2,8, "A407b",-1,-2,2,1,3,3,0x0,648,
    { 0xfcfcfcbc, 0xfcfcfc00, 0xffffff00, 0xfffffefc, 0xfcfcfcfc, 0xfcfcfc00, 0xfeffff00, 0xfffffff8},
    { 0x08200414, 0x00204800, 0x40208000, 0x85210000, 0x48200000, 0x04200800, 0x00218500, 0x80204050}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat87,1,8, "A408",-2,-3,3,0,5,3,0x0,686,
    { 0x00fefffe, 0xf0f0f0e0, 0xfcff0000, 0x3f3f3f30, 0xf0f0f030, 0xfffe0000, 0x3f3f3f2e, 0x00fffcfc},
    { 0x00200100, 0x00200040, 0x00200000, 0x00200000, 0x00200000, 0x01200000, 0x00200004, 0x00200000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat87,3,0.016000},
  {owl_attackpat88,5,8, "A409",-2,-2,1,2,3,4,0x0,647,
    { 0xfcfcfcf8, 0xfefffc00, 0xfdfdfc38, 0xfeffff15, 0xfcfffe50, 0xfcfcfcb0, 0xfffffe00, 0xfcfdfdbd},
    { 0x48200410, 0x04214800, 0x40208410, 0x84214000, 0x48210400, 0x04204810, 0x40218400, 0x84204010}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat88,3,0.019600},
  {owl_attackpat89,5,4, "A410",-2,-1,1,1,3,2,0x0,683,
    { 0xfcfc3000, 0x3dfd3d00, 0x30fcfc54, 0xf0fcf000, 0x3dfd3d00, 0x30fcfc54, 0xf0fcf000, 0xfcfc3000},
    { 0x00642000, 0x10a01000, 0x20640000, 0x10281000, 0x10a01000, 0x20640000, 0x10281000, 0x00642000}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_attackpat89,3,0.010000},
  {owl_attackpat90,1,8, "A411",-3,-4,1,3,4,7,0x0,722,
    { 0x0a3fbfaf, 0x80f0fafa, 0xf8f08080, 0xbf3e0a00, 0xfaf08000, 0xbf3f0a0a, 0x0a3ebfbf, 0x80f0f8e8},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,79.000000,attributes+0,1,NULL,autohelperowl_attackpat90,3,0.023834},
  {owl_attackpat91,1,8, "A411a",-3,-4,2,2,5,6,0x0,722,
    { 0x0a3fbfaf, 0x80f0fafa, 0xfaf08080, 0xbf3e0a0a, 0xfaf08080, 0xbf3f0a0a, 0x0a3ebfbf, 0x80f0faea},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,79.000000,attributes+0,1,NULL,autohelperowl_attackpat91,3,0.019600},
  {owl_attackpat92,1,8, "A413a",-3,-2,0,3,3,5,0x0,720,
    { 0x3f3f3f3a, 0x00ffffff, 0xf0f0f0f0, 0xfeff0000, 0xffff0000, 0x3f3f3f3f, 0x00fffefe, 0xf0f0f0b0},
    { 0x00200010, 0x00200000, 0x00200000, 0x00210000, 0x00200000, 0x00200000, 0x00210000, 0x00200010}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_attackpat92,3,0.365200},
  {owl_attackpat93,4,8, "A414",-4,-3,0,3,4,6,0x0,686,
    { 0x00fcfefe, 0xf0f0f080, 0xfefc0000, 0x3f3f3f0a, 0xf0f0f080, 0xfefc0000, 0x3f3f3f0a, 0x00fcfefe},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,82.000000,attributes+0,1,NULL,autohelperowl_attackpat93,3,0.019600},
  {owl_attackpat94,1,8, "A414a",-3,-3,0,3,3,6,0x0,722,
    { 0x00feffff, 0xf0f0f0e0, 0xfffe0000, 0x3f3f3f2f, 0xf0f0f0e0, 0xfffe0000, 0x3f3f3f2f, 0x00feffff},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_attackpat94,3,0.023056},
  {owl_attackpat95,2,8, "A415",-1,-2,1,0,2,2,0x0,685,
    { 0x00fcfcbc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3e00, 0xf0f0f000, 0xfcfc0000, 0x3e3f3f00, 0x00fcfcf8},
    { 0x00240008, 0x00201000, 0x00600000, 0x12200000, 0x10200000, 0x00240000, 0x00201200, 0x00600080}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat95,3,1.810000},
  {owl_attackpat96,3,8, "A416",-1,-2,1,2,2,4,0x0,683,
    { 0xfcfc3c34, 0x3cfffc00, 0xf0fcfc30, 0xfdfff000, 0xfcff3c00, 0x3cfcfc30, 0xf0fffd00, 0xfcfcf070},
    { 0x00600020, 0x10200000, 0x00240000, 0x00221000, 0x00201000, 0x00600000, 0x10220000, 0x00240020}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat97,5,8, "A417",0,-1,3,2,3,3,0x0,722,
    { 0x003fffbf, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0e00, 0xf0f0c000, 0xff3f0000, 0x0e3f3f3f, 0x00f0fcf8},
    { 0x00214000, 0x40200010, 0x04200000, 0x00200400, 0x00204000, 0x40210000, 0x04200010, 0x00200400}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat97,3,0.019600},
  {owl_attackpat98,3,8, "A418",-1,-2,1,1,2,3,0x0,647,
    { 0xfcfcf400, 0xfcfc7c00, 0x7fffff00, 0xf4fcfcfc, 0x7cfcfcfc, 0xf4fcfc00, 0xfcfcf400, 0xffff7f00},
    { 0x04182000, 0x00902400, 0x21904000, 0x60180004, 0x24900040, 0x20180400, 0x00186000, 0x40902100}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat98,0,0.010000},
  {owl_attackpat99,2,8, "A419",0,0,1,2,1,2,0x0,722,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00200018, 0x00200000, 0x00200000, 0x02210000, 0x00200000, 0x00200000, 0x00210200, 0x00200090}
   , 0x0,68.000000,attributes+0,1,NULL,autohelperowl_attackpat99,3,1.810000},
  {owl_attackpat100,2,8, "A419b",0,0,1,2,1,2,0x0,722,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00200018, 0x00200000, 0x00200000, 0x02210000, 0x00200000, 0x00200000, 0x00210200, 0x00200090}
   , 0x0,68.000000,attributes+0,1,NULL,autohelperowl_attackpat100,3,1.810000},
  {owl_attackpat101,6,8, "A420",-1,-1,2,2,3,3,0x0,722,
    { 0x3dfdfdbd, 0xf0fcfc54, 0xfcfcf000, 0xffff3e00, 0xfcfcf000, 0xfdfd3d00, 0x3effff55, 0xf0fcfcf8},
    { 0x10a40010, 0x20241000, 0x00681000, 0x10612000, 0x10242000, 0x00a41000, 0x20611000, 0x10680010}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat101,3,1.810000},
  {owl_attackpat102,3,8, "A421",-1,-2,2,0,3,2,0x0,722,
    { 0x003c7f7f, 0x40f0f0c0, 0xf4f00000, 0x3f3f0500, 0xf0f04000, 0x7f3c0000, 0x053f3f0f, 0x00f0f4f4},
    { 0x00100201, 0x00100080, 0x00100000, 0x00100000, 0x00100000, 0x02100000, 0x00100009, 0x00100000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat102,0,0.016000},
  {owl_attackpat103,3,8, "A422",0,-1,2,2,2,3,0x0,685,
    { 0x0038ff18, 0xc0f0e0c0, 0xfcb00000, 0x2e3d0c00, 0xe0f0c000, 0xff380000, 0x0c3d2e0c, 0x00b0fc90},
    { 0x00108200, 0x80100080, 0x08100000, 0x00100800, 0x00108000, 0x82100000, 0x08100008, 0x00100800}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_attackpat103,0,6.010000},
  {owl_attackpat104,3,8, "A422a",0,-1,2,2,2,3,0x0,685,
    { 0x0038ff18, 0xc0f0e0c0, 0xfcb00000, 0x2e3d0c00, 0xe0f0c000, 0xff380000, 0x0c3d2e0c, 0x00b0fc90},
    { 0x00108200, 0x80100080, 0x08100000, 0x00100800, 0x00108000, 0x82100000, 0x08100008, 0x00100800}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_attackpat104,0,6.010000},
  {owl_attackpat105,3,8, "A423",-1,0,1,3,2,3,0x0,686,
    { 0x003c3cfc, 0x00f0f000, 0xf0f00000, 0x3f3f0300, 0xf0f00000, 0x3c3c0000, 0x033f3f00, 0x00f0f0fc},
    { 0x00280040, 0x00202000, 0x00a00000, 0x20200100, 0x20200000, 0x00280000, 0x01202000, 0x00a00004}
   , 0x0,61.000000,attributes+0,1,NULL,autohelperowl_attackpat105,3,0.010000},
  {owl_attackpat106,3,8, "A423a",-1,0,1,3,2,3,0x0,686,
    { 0x003c3cfc, 0x00f0f000, 0xf0f00000, 0x3f3f0300, 0xf0f00000, 0x3c3c0000, 0x033f3f00, 0x00f0f0fc},
    { 0x00280040, 0x00202000, 0x00a00000, 0x20200100, 0x20200000, 0x00280000, 0x01202000, 0x00a00004}
   , 0x0,61.000000,attributes+0,1,NULL,autohelperowl_attackpat106,3,0.010000},
  {owl_attackpat107,4,8, "A424",-1,-1,1,2,2,3,0x0,648,
    { 0xfcfcfc00, 0xfcfcfc00, 0xfffefc00, 0xfcfcfc2c, 0xfcfcfce0, 0xfcfcfc00, 0xfcfcfc00, 0xfcfeff00},
    { 0x68102800, 0x04988800, 0xa010a400, 0x88984000, 0x88980400, 0x28106800, 0x40988800, 0xa410a000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat107,0,0.010000},
  {owl_attackpat108,2,4, "A425",0,0,2,2,2,2,0x0,722,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00120021, 0x00100020, 0x00100000, 0x00120000, 0x00100000, 0x00120000, 0x00120021, 0x00100020}
   , 0x20,90.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat109,2,8, "A501",0,-2,2,1,2,3,0x2,722,
    { 0x003dffff, 0xc0f0f0d0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3d0000, 0x0f3f3f1f, 0x00f0fcfc},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat110,4,8, "A502",-1,0,1,2,2,2,0x2,685,
    { 0x003cfcbc, 0xc0f0f000, 0xfcf00000, 0x3f3f0e00, 0xf0f0c000, 0xfc3c0000, 0x0e3f3f00, 0x00f0fcf8},
    { 0x00188028, 0x80102000, 0x08900000, 0x22120800, 0x20108000, 0x80180000, 0x08122200, 0x009008a0}
   , 0x20,45.000000,attributes+0,1,NULL,autohelperowl_attackpat110,0,1.000000},
  {owl_attackpat111,5,8, "A503",-1,0,1,2,2,2,0x2,685,
    { 0x003cfcfc, 0xc0f0f000, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xfc3c0000, 0x0f3f3f00, 0x00f0fcfc},
    { 0x00288098, 0x80202000, 0x08a00000, 0x22210a00, 0x20208000, 0x80280000, 0x0a212200, 0x00a00898}
   , 0x10,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat112,6,8, "A503b",-1,-2,1,1,2,3,0x2,648,
    { 0xfcffff00, 0xfcfcfcf0, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc3c, 0xfcfcfc00},
    { 0xa8122200, 0x089808a0, 0x2010a800, 0x80988000, 0x08980800, 0x2212a800, 0x80988028, 0xa8102000}
   , 0x10,32.000000,attributes+0,1,NULL,autohelperowl_attackpat112,0,0.050000},
  {owl_attackpat113,2,8, "A504",0,0,1,1,1,1,0x2,721,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00201800, 0x00608000, 0x90200000, 0x08240000, 0x80600000, 0x18200000, 0x00240800, 0x00209000}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat114,2,8, "A505",0,-1,2,2,2,3,0x2,722,
    { 0x003fffff, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3f0000, 0x0f3f3f3f, 0x00f0fcfc},
    { 0x001a0000, 0x00102020, 0x00900000, 0x20100000, 0x20100000, 0x001a0000, 0x00102020, 0x00900000}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat115,2,8, "A506",-1,0,1,2,2,2,0x2,685,
    { 0x003cfcfc, 0xc0f0f000, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xfc3c0000, 0x0f3f3f00, 0x00f0fcfc},
    { 0x00108080, 0x80100000, 0x08100000, 0x00100a00, 0x00108000, 0x80100000, 0x0a100000, 0x00100808}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat116,2,8, "A507",-1,0,1,2,2,2,0x2,685,
    { 0x00f0fcf0, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0x003cfc3c},
    { 0x00200420, 0x00204000, 0x40200000, 0x04220000, 0x40200000, 0x04200000, 0x00220400, 0x00204020}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat117,4,8, "A508",0,-2,2,2,2,4,0x2,685,
    { 0x007effff, 0xd0f0f0e0, 0xfff40000, 0x3f3f1f0d, 0xf0f0d0c0, 0xff7e0000, 0x1f3f3f2f, 0x00f4fffd},
    { 0x00200100, 0x00200040, 0x02200000, 0x00200008, 0x00200080, 0x01200000, 0x00200004, 0x00200200}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat118,5,8, "A509",-1,0,1,2,2,2,0x2,685,
    { 0x007cfc7c, 0xd0f0f000, 0xfcf40000, 0x3f3f1d00, 0xf0f0d000, 0xfc7c0000, 0x1d3f3f00, 0x00f4fcf4},
    { 0x00280024, 0x00202000, 0x00a00000, 0x21220000, 0x20200000, 0x00280000, 0x00222100, 0x00a00060}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat118,3,0.400000},
  {owl_attackpat119,4,8, "A510",-1,-2,1,2,2,4,0x2,685,
    { 0xfcfcfcfc, 0xffffff00, 0xfcfcfcfc, 0xffffff00, 0xffffff00, 0xfcfcfcfc, 0xffffff00, 0xfcfcfcfc},
    { 0xa4900080, 0x28190400, 0x00186810, 0x4090a200, 0x04192800, 0x0090a410, 0xa2904000, 0x68180008}
   , 0x0,55.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat120,4,8, "A511",0,-1,2,2,2,3,0x2,685,
    { 0x003dfdfd, 0xc0f0f050, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xfd3d0000, 0x0f3f3f15, 0x00f0fcfc},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_attackpat120,3,0.010000},
  {owl_attackpat121,3,8, "A512",-1,-2,1,1,2,3,0x2,685,
    { 0x1c38fcfc, 0xc0f4ec00, 0xfcb0d000, 0xef7f0f00, 0xecf4c000, 0xfc381c00, 0x0f7fef00, 0xd0b0fcfc},
    { 0x08204000, 0x40200800, 0x04208000, 0x80200400, 0x08204000, 0x40200800, 0x04208000, 0x80200400}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat122,1,8, "A513",-2,0,1,2,3,2,0x4,722,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat122,3,0.610000},
  {owl_attackpat123,4,8, "A514",-1,-1,2,1,3,2,0x4,721,
    { 0xf7ffbf00, 0xbcfcf4fc, 0xf8fc7c00, 0x7cfcf800, 0xf4fcbc00, 0xbffff700, 0xf8fc7cfc, 0x7cfcf800},
    { 0x80602400, 0x18a04000, 0x60240800, 0x04289000, 0x40a01800, 0x24608000, 0x90280400, 0x08246000}
   , 0x10,45.000000,attributes+0,1,NULL,autohelperowl_attackpat123,3,1.600000},
  {owl_attackpat124,4,8, "A515",0,-2,1,2,1,4,0x2,647,
    { 0x00ffff00, 0xf0f0f0f0, 0xffff0000, 0x3c3c3c3c, 0xf0f0f0f0, 0xffff0000, 0x3c3c3c3c, 0x00ffff00},
    { 0x002a1600, 0x006060a0, 0x50a10000, 0x24240010, 0x60600010, 0x162a0000, 0x00242428, 0x00a15000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_attackpat124,3,1.000000},
  {owl_attackpat125,3,8, "A516",-1,-2,1,2,2,4,0x2,721,
    { 0xffffff00, 0xfcfcfcfc, 0xfffffe00, 0xfcfcfcbc, 0xfcfcfcf8, 0xffffff00, 0xfcfcfcfc, 0xfeffff00},
    { 0x68120000, 0x04180820, 0x0010a400, 0x80904000, 0x08180400, 0x00126800, 0x40908020, 0xa4100000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat125,0,0.016000},
  {owl_attackpat126,6,8, "A517",-1,-2,1,3,2,5,0x2,647,
    { 0xfdffff00, 0xfcfcfcf4, 0xfffffc00, 0xfcfcfc3c, 0xfcfcfcf0, 0xfffffd00, 0xfcfcfc7c, 0xfcffff00},
    { 0x68120000, 0x04180820, 0x0010a400, 0x80904000, 0x08180400, 0x00126800, 0x40908020, 0xa4100000}
   , 0x0,5.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat127,5,8, "A518",-1,-3,1,1,2,4,0x2,758,
    { 0x17ffff00, 0xf0f4f4fc, 0xfcfc5000, 0x7c7c3c00, 0xf4f4f000, 0xffff1700, 0x3c7c7cfc, 0x50fcfc00},
    { 0x00a08000, 0xa0200000, 0x08280000, 0x00202800, 0x0020a000, 0x80a00000, 0x28200000, 0x00280800}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat128,4,8, "A601",-1,0,1,3,2,3,0x1,723,
    { 0x003cfc7c, 0xc0f0f000, 0xfcf00000, 0x3f3f0d00, 0xf0f0c000, 0xfc3c0000, 0x0d3f3f00, 0x00f0fcf4},
    { 0x00248000, 0x80201000, 0x08600000, 0x10200800, 0x10208000, 0x80240000, 0x08201000, 0x00600800}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat129,1,8, "A602",-1,0,1,1,2,1,0x5,685,
    { 0x00fcbc00, 0xb0f0f000, 0xf8fc0000, 0x3c3c3800, 0xf0f0b000, 0xbcfc0000, 0x383c3c00, 0x00fcf800},
    { 0x00600000, 0x10200000, 0x00240000, 0x00201000, 0x00201000, 0x00600000, 0x10200000, 0x00240000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat129,3,1.000000},
  {owl_attackpat130,4,8, "A603",0,-2,1,2,1,4,0x2,685,
    { 0x00fdfd00, 0xf0f0f050, 0xffff0000, 0x3c3c3c3c, 0xf0f0f0f0, 0xfdfd0000, 0x3c3c3c14, 0x00ffff00},
    { 0x00280000, 0x00202000, 0x00a10000, 0x20200010, 0x20200010, 0x00280000, 0x00202000, 0x00a10000}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_attackpat130,3,1.011760},
  {owl_attackpat131,3,8, "A603b",0,-1,1,2,1,3,0x2,685,
    { 0x007dff00, 0xd0f0f0d0, 0xfcf40000, 0x3c3c1c00, 0xf0f0d000, 0xff7d0000, 0x1c3c3c1c, 0x00f4fc00},
    { 0x00200100, 0x00200040, 0x00200000, 0x00200000, 0x00200000, 0x01200000, 0x00200004, 0x00200000}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_attackpat131,3,0.610000},
  {owl_attackpat132,2,8, "A604",0,-1,1,3,1,4,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0x00ffff00},
    { 0x00280000, 0x00202000, 0x00a00000, 0x20200000, 0x20200000, 0x00280000, 0x00202000, 0x00a00000}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat133,1,8, "A605",0,-1,1,2,1,3,0xa,685,
    { 0x00fcfc00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0x00ffff00},
    { 0x00200000, 0x00200000, 0x00210000, 0x00200010, 0x00200010, 0x00200000, 0x00200000, 0x00210000}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat134,4,8, "A606",0,-2,1,2,1,4,0x2,685,
    { 0x00f7fd00, 0xf0f0d070, 0xff7f0000, 0x1c3c3c3c, 0xd0f0f0f0, 0xfdf70000, 0x3c3c1c34, 0x007fff00},
    { 0x00220400, 0x00204020, 0x40210000, 0x04200010, 0x40200010, 0x04220000, 0x00200420, 0x00214000}
   , 0x10,50.000000,attributes+0,1,NULL,autohelperowl_attackpat134,3,0.610000},
  {owl_attackpat135,2,8, "A607a",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00680000, 0x10202000, 0x00a40000, 0x20201000, 0x20201000, 0x00680000, 0x10202000, 0x00a40000}
   , 0x10,36.000000,attributes+0,1,NULL,autohelperowl_attackpat135,3,0.613600},
  {owl_attackpat136,1,8, "A607b",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00600000, 0x10200000, 0x00240000, 0x00201000, 0x00201000, 0x00600000, 0x10200000, 0x00240000}
   , 0x10,36.000000,attributes+0,1,NULL,autohelperowl_attackpat136,3,0.613600},
  {owl_attackpat137,2,8, "A607c",0,-1,1,1,1,2,0x2,685,
    { 0x00f4fc00, 0xf0f0d000, 0xfc7c0000, 0x1c3c3c00, 0xd0f0f000, 0xfcf40000, 0x3c3c1c00, 0x007cfc00},
    { 0x00604000, 0x50200000, 0x04240000, 0x00201400, 0x00205000, 0x40600000, 0x14200000, 0x00240400}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_attackpat137,3,0.610000},
  {owl_attackpat138,2,8, "A607d",0,-1,1,2,1,3,0x2,722,
    { 0x003fbf00, 0x80f0f0f0, 0xf8f00000, 0x3c3c0800, 0xf0f08000, 0xbf3f0000, 0x083c3c3c, 0x00f0f800},
    { 0x00290000, 0x00202010, 0x00a00000, 0x20200000, 0x20200000, 0x00290000, 0x00202010, 0x00a00000}
   , 0x10,36.000000,attributes+0,1,NULL,autohelperowl_attackpat138,3,0.101283},
  {owl_attackpat139,2,8, "A608",0,-1,1,1,1,2,0x2,685,
    { 0x00f4fc00, 0xf0f0d000, 0xfc7c0000, 0x1c3c3c00, 0xd0f0f000, 0xfcf40000, 0x3c3c1c00, 0x007cfc00},
    { 0x00600000, 0x10200000, 0x00240000, 0x00201000, 0x00201000, 0x00600000, 0x10200000, 0x00240000}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_attackpat139,3,0.378160},
  {owl_attackpat140,2,8, "A609",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00980000, 0x20102000, 0x00980000, 0x20102000, 0x20102000, 0x00980000, 0x20102000, 0x00980000}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat141,2,8, "A610",0,-2,1,1,1,3,0x2,722,
    { 0x00ff3f00, 0x30f0f0f0, 0xf0fc0000, 0x3c3c3000, 0xf0f03000, 0x3fff0000, 0x303c3c3c, 0x00fcf000},
    { 0x00620000, 0x10200020, 0x00240000, 0x00201000, 0x00201000, 0x00620000, 0x10200020, 0x00240000}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat141,3,1.000000},
  {owl_attackpat142,4,8, "A611",-1,-1,1,2,2,3,0x2,722,
    { 0x34ffff00, 0xf0fcf4f0, 0xfcfc7000, 0x7cfc3c00, 0xf4fcf000, 0xffff3400, 0x3cfc7c3c, 0x70fcfc00},
    { 0x10a24000, 0x60240020, 0x04281000, 0x00602400, 0x00246000, 0x40a21000, 0x24600020, 0x10280400}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat142,3,0.010000},
  {owl_attackpat143,4,8, "A612",-1,-1,1,2,2,3,0x2,648,
    { 0xbcffff00, 0xf8fcfcf0, 0xfcfcf800, 0xfcfcbc00, 0xfcfcf800, 0xffffbc00, 0xbcfcfc3c, 0xf8fcfc00},
    { 0x18622100, 0x10a40860, 0x20249000, 0x80681000, 0x08a41000, 0x21621800, 0x10688024, 0x90242000}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat143,3,0.010000},
  {owl_attackpat144,3,8, "A613",-1,-2,1,1,2,3,0x2,685,
    { 0x3fffff00, 0xf0fcfcfc, 0xfcfcf000, 0xfcfc3c00, 0xfcfcf000, 0xffff3f00, 0x3cfcfcfc, 0xf0fcfc00},
    { 0x22600000, 0x10280008, 0x00242000, 0x00a01000, 0x00281000, 0x00602200, 0x10a00080, 0x20240000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_attackpat144,3,1.000000},
  {owl_attackpat145,4,8, "A614",-1,-2,1,1,2,3,0x2,721,
    { 0x3cfcfcfc, 0xf0fcfc00, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xfcfc3c00, 0x3fffff00, 0xf0fcfcfc},
    { 0x10608088, 0x90240000, 0x08241000, 0x02601a00, 0x00249000, 0x80601000, 0x1a600200, 0x10240888}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_attackpat145,3,1.000000},
  {owl_attackpat146,3,4, "A615",0,-2,2,2,2,4,0x2,686,
    { 0x00fffcfc, 0xf0f0f030, 0xfcff0000, 0x3f3f3f30, 0xf0f0f030, 0xfcff0000, 0x3f3f3f30, 0x00fffcfc},
    { 0x00a90000, 0x20202010, 0x00a90000, 0x20202010, 0x20202010, 0x00a90000, 0x20202010, 0x00a90000}
   , 0x10,65.000000,attributes+0,1,NULL,autohelperowl_attackpat146,3,0.010000},
  {owl_attackpat147,4,8, "A616",-1,-2,2,1,3,3,0x4,722,
    { 0xf5ffbf00, 0xbcfcf4f4, 0xf8fc7c00, 0x7cfcf800, 0xf4fcbc00, 0xbffff500, 0xf8fc7c7c, 0x7cfcf800},
    { 0x80600000, 0x18200000, 0x00240800, 0x00209000, 0x00201800, 0x00608000, 0x90200000, 0x08240000}
   , 0x10,45.000000,attributes+0,1,NULL,autohelperowl_attackpat147,3,1.011760},
  {owl_attackpat148,5,8, "A617",-1,0,2,2,3,2,0x2,723,
    { 0x3c3f3f3f, 0x00fcfcf0, 0xf0f0f000, 0xffff0000, 0xfcfc0000, 0x3f3f3c00, 0x00ffff3f, 0xf0f0f0f0},
    { 0x18222120, 0x00a40860, 0x20209000, 0x806a0000, 0x08a40000, 0x21221800, 0x006a8024, 0x90202020}
   , 0x10,50.000000,attributes+0,1,NULL,autohelperowl_attackpat148,3,0.010000},
  {owl_attackpat149,5,8, "A618",-1,-1,1,1,2,2,0x2,720,
    { 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00},
    { 0x6090a800, 0xa4988000, 0xa8182400, 0x08986800, 0x8098a400, 0xa8906000, 0x68980800, 0x2418a800}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat149,0,3.000000},
  {owl_attackpat150,1,8, "A619",0,-1,1,0,1,1,0xa,721,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat151,2,8, "A620",0,-1,1,1,1,2,0x2,648,
    { 0x00fcf400, 0xf0f07000, 0x7cfc0000, 0x343c3c00, 0x70f0f000, 0xf4fc0000, 0x3c3c3400, 0x00fc7c00},
    { 0x00241000, 0x00601000, 0x10600000, 0x10240000, 0x10600000, 0x10240000, 0x00241000, 0x00601000}
   , 0x10,65.000000,attributes+0,1,NULL,autohelperowl_attackpat151,3,0.010000},
  {owl_attackpat152,2,8, "A621",0,-2,1,2,1,4,0x2,648,
    { 0x00bcff00, 0xe0f0f0c0, 0xfff80000, 0x3c3c2c0c, 0xf0f0e0c0, 0xffbc0000, 0x2c3c3c0c, 0x00f8ff00},
    { 0x00180200, 0x00102080, 0x00900000, 0x20100000, 0x20100000, 0x02180000, 0x00102008, 0x00900000}
   , 0x10,10.000000,attributes+0,1,NULL,autohelperowl_attackpat152,0,0.016000},
  {owl_attackpat153,3,8, "A622",0,-1,1,2,1,3,0x2,722,
    { 0x007ffe00, 0xd0f0f0b0, 0xfcf40000, 0x3c3c1c00, 0xf0f0d000, 0xfe7f0000, 0x1c3c3c38, 0x00f4fc00},
    { 0x00218000, 0x80200010, 0x08200000, 0x00200800, 0x00208000, 0x80210000, 0x08200010, 0x00200800}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_attackpat153,3,1.366000},
  {owl_attackpat154,2,8, "A623",0,-2,2,2,2,4,0xa,649,
    { 0x007fffff, 0xd0f0f0f0, 0xfff70000, 0x3f3f1f3f, 0xf0f0d0f0, 0xff7f0000, 0x1f3f3f3f, 0x00f7ffff},
    { 0x00210100, 0x00200050, 0x00200000, 0x00200000, 0x00200000, 0x01210000, 0x00200014, 0x00200000}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat155,4,8, "A701",-1,-2,1,1,2,3,0x0,683,
    { 0xfdffbc00, 0xbcfcfc34, 0xf8fcfc00, 0xfcfcf800, 0xfcfcbc00, 0xbcfffd00, 0xf8fcfc70, 0xfcfcf800},
    { 0x00621800, 0x10608020, 0x90240000, 0x08241000, 0x80601000, 0x18620000, 0x10240820, 0x00249000}
   , 0x0,79.000000,attributes+0,1,NULL,autohelperowl_attackpat155,3,0.010000},
  {owl_attackpat156,4,8, "A702",-1,-2,2,1,3,3,0x0,683,
    { 0xffffbc00, 0xbcfdfc3c, 0xf8fcfc10, 0xfcfcf800, 0xfcfdbc00, 0xbcffff10, 0xf8fcfcf0, 0xfcfcf800},
    { 0x40621800, 0x14608020, 0x90240400, 0x08245000, 0x80601400, 0x18624000, 0x50240820, 0x04249000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat156,3,0.010000},
  {owl_attackpat157,4,8, "A703",0,-1,2,2,2,3,0x0,721,
    { 0x0c3f3f0d, 0x00f0fcf0, 0xf0f0c000, 0xff3c0000, 0xfcf00000, 0x3f3f0c00, 0x003cff3d, 0xc0f0f0c0},
    { 0x04202008, 0x00a00400, 0x20204000, 0x42280000, 0x04a00000, 0x20200400, 0x00284200, 0x40202080}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat158,3,8, "A704",-1,-1,1,2,2,3,0x0,647,
    { 0xf0fcfc30, 0xfcfcf000, 0xfcfc3c00, 0x3cfffc00, 0xf0fcfc00, 0xfcfcf000, 0xfcff3c00, 0x3cfcfc30},
    { 0x10241820, 0x00649000, 0x90601000, 0x18660000, 0x90640000, 0x18241000, 0x00661800, 0x10609020}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat159,2,8, "A705b",-1,0,1,2,2,2,0x0,685,
    { 0x0030fc30, 0xc0f0c000, 0xfc300000, 0x0c3f0c00, 0xc0f0c000, 0xfc300000, 0x0c3f0c00, 0x0030fc30},
    { 0x00200020, 0x00200000, 0x00200000, 0x00220000, 0x00200000, 0x00200000, 0x00220000, 0x00200020}
   , 0x0,61.000000,attributes+0,1,NULL,autohelperowl_attackpat159,3,0.400000},
  {owl_attackpat160,3,8, "A706",-1,0,1,2,2,2,0x0,648,
    { 0x0030fc3c, 0xc0f0c000, 0xfc300000, 0x0f3f0c00, 0xc0f0c000, 0xfc300000, 0x0c3f0f00, 0x0030fcf0},
    { 0x00200820, 0x00208000, 0x80200000, 0x08220000, 0x80200000, 0x08200000, 0x00220800, 0x00208020}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat160,3,0.016000},
  {owl_attackpat161,3,8, "A707",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00204820, 0x40208000, 0x84200000, 0x08220400, 0x80204000, 0x48200000, 0x04220800, 0x00208420}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat161,3,0.019600},
  {owl_attackpat162,4,8, "A708",0,-1,2,1,2,2,0x0,721,
    { 0x003c7c10, 0x40f0f000, 0xf4f00000, 0x3c3d0400, 0xf0f04000, 0x7c3c0000, 0x043d3c00, 0x00f0f410},
    { 0x00200800, 0x00208000, 0x80200000, 0x08200000, 0x80200000, 0x08200000, 0x00200800, 0x00208000}
   , 0x20,80.000000,attributes+0,1,NULL,autohelperowl_attackpat162,3,0.610000},
  {owl_attackpat163,4,8, "A709",-1,0,1,2,2,2,0x0,686,
    { 0x00347c3c, 0x40f0d000, 0xf4700000, 0x1f3f0400, 0xd0f04000, 0x7c340000, 0x043f1f00, 0x0070f4f0},
    { 0x00200800, 0x00208000, 0x80200000, 0x08200000, 0x80200000, 0x08200000, 0x00200800, 0x00208000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat163,3,1.186000},
  {owl_attackpat164,4,8, "A710",0,-1,2,1,2,2,0x0,721,
    { 0x003c7c10, 0x40f0f000, 0xf4f00000, 0x3c3d0400, 0xf0f04000, 0x7c3c0000, 0x043d3c00, 0x00f0f410},
    { 0x00200800, 0x00208000, 0x80200000, 0x08200000, 0x80200000, 0x08200000, 0x00200800, 0x00208000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_attackpat164,3,0.016000},
  {owl_attackpat165,6,8, "A711",-1,0,1,3,2,3,0x0,648,
    { 0x00f4fcfc, 0xf0f0d000, 0xfc7c0000, 0x1f3f3f00, 0xd0f0f000, 0xfcf40000, 0x3f3f1f00, 0x007cfcfc},
    { 0x00600808, 0x10208000, 0x80240000, 0x0a201000, 0x80201000, 0x08600000, 0x10200a00, 0x00248080}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat166,4,8, "A712",0,-1,3,2,3,3,0x0,686,
    { 0x003cffff, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0f, 0x00f0fcfc},
    { 0x00280202, 0x00202080, 0x00a00000, 0x20200000, 0x20200000, 0x02280000, 0x0020200a, 0x00a00000}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat167,6,8, "A713",-1,0,2,2,3,2,0x0,759,
    { 0x00fdff3d, 0xf0f0f0d0, 0xfcfc0000, 0x3f3f3c00, 0xf0f0f000, 0xfffd0000, 0x3c3f3f1d, 0x00fcfcf0},
    { 0x00684028, 0x50202000, 0x04a40000, 0x22221400, 0x20205000, 0x40680000, 0x14222200, 0x00a404a0}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat167,3,1.600000},
  {owl_attackpat168,7,8, "A714",0,-1,3,2,3,3,0x0,758,
    { 0x0f3f3f0d, 0x00f0fcfc, 0xf0f0c000, 0xff3c0000, 0xfcf00000, 0x3f3f0f00, 0x003cfffd, 0xc0f0f0c0},
    { 0x06202008, 0x00a00408, 0x20204000, 0x42280000, 0x04a00000, 0x20200600, 0x00284280, 0x40202080}
   , 0x0,82.000000,attributes+0,1,NULL,autohelperowl_attackpat168,3,0.010000},
  {owl_attackpat169,6,8, "A715",0,-2,2,1,2,3,0x0,647,
    { 0x00fcf47c, 0xf0f07000, 0x7dfc0000, 0x373f3d04, 0x70f0f040, 0xf4fc0000, 0x3d3f3700, 0x00fc7df4},
    { 0x00280024, 0x00202000, 0x00a00000, 0x21220000, 0x20200000, 0x00280000, 0x00222100, 0x00a00060}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat169,3,0.610000},
  {owl_attackpat170,6,8, "A716",-1,0,1,2,2,2,0x0,648,
    { 0x00f4fc74, 0xf0f0d000, 0xfc7c0000, 0x1d3f3d00, 0xd0f0f000, 0xfcf40000, 0x3d3f1d00, 0x007cfc74},
    { 0x00600820, 0x10208000, 0x80240000, 0x08221000, 0x80201000, 0x08600000, 0x10220800, 0x00248020}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_attackpat170,3,1.000000},
  {owl_attackpat171,4,8, "A717",-1,-1,1,2,2,3,0x0,647,
    { 0x30fcf000, 0xf0fc3000, 0x3fff3000, 0x30fc3c3c, 0x30fcf0f0, 0xf0fc3000, 0x3cfc3000, 0x30ff3f00},
    { 0x00182000, 0x00902000, 0x22920000, 0x20180028, 0x209000a0, 0x20180000, 0x00182000, 0x00922200}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_attackpat171,0,0.610000},
  {owl_attackpat172,7,8, "A718",0,-1,2,2,2,3,0x0,648,
    { 0x0074f474, 0xd0f05000, 0x7f740000, 0x153f1d0c, 0x50f0d0c0, 0xf4740000, 0x1d3f1500, 0x00747f74},
    { 0x00200020, 0x00200000, 0x01200000, 0x00220004, 0x00200040, 0x00200000, 0x00220000, 0x00200120}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_attackpat172,3,1.000000},
  {owl_attackpat173,6,8, "A719",0,-1,2,2,2,3,0x0,722,
    { 0x003fff3f, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xff3f0000, 0x0c3f3f3f, 0x00f0fcf0},
    { 0x00298228, 0x80202090, 0x08a00000, 0x22220800, 0x20208000, 0x82290000, 0x08222218, 0x00a008a0}
   , 0x10,50.000000,attributes+0,1,NULL,autohelperowl_attackpat173,3,0.616000},
  {owl_attackpat174,5,8, "A719b",0,-1,2,1,2,2,0x8,685,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00a408a0, 0x20209000, 0x80680000, 0x18222200, 0x90202000, 0x08a40000, 0x22221800, 0x00688028}
   , 0x10,50.000000,attributes+0,1,NULL,autohelperowl_attackpat174,3,1.010000},
  {owl_attackpat175,4,8, "A720",-2,-2,2,1,4,3,0x0,721,
    { 0x7f7ffc3c, 0xd4fcff3c, 0xfcf4f4c0, 0xffff5c00, 0xfffcd400, 0xfc7f7f0c, 0x5cfffff0, 0xf4f4fcf0},
    { 0x02120014, 0x00100028, 0x00100000, 0x01110000, 0x00100000, 0x00120200, 0x001101a0, 0x00100050}
   , 0x0,40.000000,attributes+0,1,NULL,autohelperowl_attackpat175,0,0.592000},
  {owl_attackpat176,5,8, "A721",0,-1,2,2,2,3,0x0,722,
    { 0x003fff3f, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xff3f0000, 0x0c3f3f3f, 0x00f0fcf0},
    { 0x00288028, 0x80202000, 0x08a00000, 0x22220800, 0x20208000, 0x80280000, 0x08222200, 0x00a008a0}
   , 0x10,45.000000,attributes+0,1,NULL,autohelperowl_attackpat176,3,0.980800},
  {owl_attackpat177,7,8, "A801",-1,-1,1,2,2,3,0x2,722,
    { 0x1d7fff00, 0xd0f4fcf4, 0xfcf4d000, 0xfc7c1c00, 0xfcf4d000, 0xff7f1d00, 0x1c7cfc7c, 0xd0f4fc00},
    { 0x08228100, 0x80200860, 0x08208000, 0x80200800, 0x08208000, 0x81220800, 0x08208024, 0x80200800}
   , 0x20,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat178,5,8, "A802",-1,0,1,2,2,2,0x2,648,
    { 0x00f4fcf4, 0xf0f0d000, 0xfc7c0000, 0x1d3f3f00, 0xd0f0f000, 0xfcf40000, 0x3f3f1d00, 0x007cfc7c},
    { 0x00200860, 0x00208000, 0x80200000, 0x08220100, 0x80200000, 0x08200000, 0x01220800, 0x00208024}
   , 0x20,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat179,4,8, "A803",-1,-1,1,2,2,3,0x2,722,
    { 0x5cbfff00, 0xe4f4fcf0, 0xfcf8d400, 0xfc7c6c00, 0xfcf4e400, 0xffbf5c00, 0x6c7cfc3c, 0xd4f8fc00},
    { 0x08190000, 0x00102810, 0x00908000, 0xa0100000, 0x28100000, 0x00190800, 0x0010a010, 0x80900000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat179,0,1.600000},
  {owl_attackpat180,1,8, "A804",0,-1,1,2,1,3,0x2,685,
    { 0x00fcfa00, 0xf0f0b080, 0xbcfc0000, 0x383c3c00, 0xb0f0f000, 0xfafc0000, 0x3c3c3808, 0x00fcbc00},
    { 0x00244000, 0x40201000, 0x04600000, 0x10200400, 0x10204000, 0x40240000, 0x04201000, 0x00600400}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat180,3,1.000000},
  {owl_attackpat181,5,8, "A805",-1,-2,1,2,2,4,0x2,722,
    { 0x5cbfff00, 0xe4f4fcf0, 0xfffbd700, 0xfc7c6cfc, 0xfcf4e4fc, 0xffbf5c00, 0x6c7cfc3c, 0xd7fbff00},
    { 0x08190000, 0x00102810, 0x00908200, 0xa0100080, 0x28100008, 0x00190800, 0x0010a010, 0x82900000}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat182,2,8, "A806",-1,-1,1,2,2,3,0x2,721,
    { 0xffffff00, 0xfcfcfcfc, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfcfc, 0xfcfcfc00},
    { 0x42600000, 0x14200008, 0x00240400, 0x00205000, 0x00201400, 0x00604200, 0x50200080, 0x04240000}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat183,2,8, "A807",-1,-1,1,1,2,2,0x2,721,
    { 0x3cfcfc00, 0xf0fcfc00, 0xfcfcf000, 0xfcfc3c00, 0xfcfcf000, 0xfcfc3c00, 0x3cfcfc00, 0xf0fcfc00},
    { 0x20601000, 0x10680000, 0x10242000, 0x00a41000, 0x00681000, 0x10602000, 0x10a40000, 0x20241000}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat184,2,8, "A808",0,-1,1,2,1,3,0xa,722,
    { 0x00fcfc00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0x00ffff00},
    { 0x00906000, 0x60900000, 0x24190000, 0x00182410, 0x00906010, 0x60900000, 0x24180000, 0x00192400}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat185,3,8, "A809",-1,-2,1,2,2,4,0x2,721,
    { 0xfcfcfc0c, 0xffffff00, 0xfcfcfcfc, 0xfffcfc00, 0xffffff00, 0xfcfcfcfc, 0xfcfcff00, 0xfcfcfcc0},
    { 0x80205000, 0x4a610100, 0x14200858, 0x00248400, 0x01614a00, 0x50208094, 0x84240000, 0x08201400}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat185,3,0.010000},
  {owl_attackpat186,2,8, "A810",-1,0,1,2,2,2,0x0,648,
    { 0x0030fc30, 0xc0f0c000, 0xfc300000, 0x0c3f0c00, 0xc0f0c000, 0xfc300000, 0x0c3f0c00, 0x0030fc30},
    { 0x00200420, 0x00204000, 0x40200000, 0x04220000, 0x40200000, 0x04200000, 0x00220400, 0x00204020}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat186,3,0.010000},
  {owl_attackpat187,4,8, "A811",-1,0,1,2,2,2,0x0,648,
    { 0x00fcfcf0, 0xf0f0f000, 0xfcfc0000, 0x3c3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3c00, 0x00fcfc3c},
    { 0x002008a0, 0x00208000, 0x80200000, 0x08220200, 0x80200000, 0x08200000, 0x02220800, 0x00208028}
   , 0x10,65.000000,attributes+0,1,NULL,autohelperowl_attackpat187,3,0.019600},
  {owl_attackpat188,2,8, "A812",-2,-1,1,1,3,2,0x2,721,
    { 0xbcfcfc3c, 0xf8fcfc00, 0xfcfcf800, 0xffffbc00, 0xfcfcf800, 0xfcfcbc00, 0xbcffff00, 0xf8fcfcf0},
    { 0x00604020, 0x50200000, 0x04240000, 0x00221400, 0x00205000, 0x40600000, 0x14220000, 0x00240420}
   , 0x0,40.000000,attributes+0,1,NULL,autohelperowl_attackpat188,3,0.010000},
  {owl_attackpat189,3,8, "A813",-1,-1,1,1,2,2,0x2,683,
    { 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00},
    { 0x08642000, 0x10a01800, 0x20648000, 0x90281000, 0x18a01000, 0x20640800, 0x10289000, 0x80642000}
   , 0x10,85.000000,attributes+0,1,NULL,autohelperowl_attackpat189,3,1.400800},
  {owl_attackpat190,5,8, "A901",-1,-1,1,2,2,3,0xa,722,
    { 0x3c3cfc00, 0xc0ffff00, 0xfcf0f0f0, 0xfcfc0c00, 0xffffc000, 0xfc3c3c3c, 0x0cfcfc00, 0xf0f0fc00},
    { 0x20249000, 0x806a1200, 0x186020a0, 0x10a40800, 0x126a8000, 0x90242028, 0x08a41000, 0x20601800}
   , 0x10,70.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat191,2,8, "A902",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00984400, 0x60106000, 0x44980000, 0x24102400, 0x60106000, 0x44980000, 0x24102400, 0x00984400}
   , 0x10,70.000000,attributes+0,1,NULL,autohelperowl_attackpat191,0,0.019600},
  {owl_attackpat192,2,8, "A902b",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00984400, 0x60106000, 0x44980000, 0x24102400, 0x60106000, 0x44980000, 0x24102400, 0x00984400}
   , 0x10,30.000000,attributes+0,1,NULL,autohelperowl_attackpat192,0,0.019600},
  {owl_attackpat193,4,8, "A903",-1,-1,1,2,2,3,0xa,722,
    { 0x7cffff00, 0xf4fcfcf0, 0xfcfcf400, 0xfcfc7c00, 0xfcfcf400, 0xffff7c00, 0x7cfcfc3c, 0xf4fcfc00},
    { 0x28120000, 0x00180820, 0x0010a000, 0x80900000, 0x08180000, 0x00122800, 0x00908020, 0xa0100000}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat194,4,8, "A904",-1,-1,1,1,2,2,0xa,722,
    { 0x34fcfc00, 0xf0fcf400, 0xfcfc7000, 0x7cfc3c00, 0xf4fcf000, 0xfcfc3400, 0x3cfc7c00, 0x70fcfc00},
    { 0x20906000, 0x60980000, 0x24182000, 0x00982400, 0x00986000, 0x60902000, 0x24980000, 0x20182400}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat194,0,0.016000},
  {owl_attackpat195,3,8, "A905",-1,-1,1,1,2,2,0xa,646,
    { 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00},
    { 0x24102800, 0x00988400, 0xa0106000, 0x48980000, 0x84980000, 0x28102400, 0x00984800, 0x6010a000}
   , 0x10,36.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat196,5,8, "A906a",-1,-1,2,2,3,3,0xa,649,
    { 0xc0fcffff, 0xfcf0f0c0, 0xfcfc0c00, 0x3f3fff00, 0xf0f0fc00, 0xfffcc000, 0xff3f3f0f, 0x0cfcfcfc},
    { 0x80289204, 0x88602080, 0x18a00800, 0x21248800, 0x20608800, 0x92288000, 0x88242108, 0x08a01840}
   , 0x10,32.000000,attributes+0,1,NULL,autohelperowl_attackpat196,3,0.610000},
  {owl_attackpat197,5,8, "A906b",-1,-1,2,2,3,3,0xa,649,
    { 0xc0fcffff, 0xfcf0f0c0, 0xfcfc0c00, 0x3f3fff00, 0xf0f0fc00, 0xfffcc000, 0xff3f3f0f, 0x0cfcfcfc},
    { 0x80281a04, 0x0860a080, 0x90a00800, 0x29248000, 0xa0600800, 0x1a288000, 0x80242908, 0x08a09040}
   , 0x10,32.000000,attributes+0,1,NULL,autohelperowl_attackpat197,3,0.610000},
  {owl_attackpat198,5,8, "A907",-1,-1,2,2,3,3,0xa,648,
    { 0xf0fcfdff, 0xfcfcf040, 0xfcfc3c00, 0x3fffff00, 0xf0fcfc00, 0xfdfcf000, 0xffff3f07, 0x3cfcfcfc},
    { 0x20680800, 0x1028a000, 0x80a42000, 0x28a01000, 0xa0281000, 0x08682000, 0x10a02800, 0x20a48000}
   , 0x10,65.000000,attributes+0,1,NULL,autohelperowl_attackpat198,3,1.000000},
  {owl_attackpat199,5,8, "A908",-1,-1,2,2,3,3,0xa,686,
    { 0xc0fcfcff, 0xfcf0f000, 0xfcfc0c00, 0x3f3fff00, 0xf0f0fc00, 0xfcfcc000, 0xff3f3f03, 0x0cfcfcfc},
    { 0x80681842, 0x1860a000, 0x90a40800, 0x28249100, 0xa0601800, 0x18688000, 0x91242802, 0x08a49004}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_attackpat199,3,0.050000},
  {owl_attackpat200,5,8, "A909",-1,-1,2,1,3,2,0xa,723,
    { 0x3cfcfcfc, 0xf0fcfc00, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xfcfc3c00, 0x3fffff00, 0xf0fcfcfc},
    { 0x20a49810, 0xa0689000, 0x98682000, 0x18a52800, 0x9068a000, 0x98a42000, 0x28a51800, 0x20689810}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat201,3,8, "A910",0,-1,1,1,1,2,0x6,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00a80000, 0x20202000, 0x00a80000, 0x20202000, 0x20202000, 0x00a80000, 0x20202000, 0x00a80000}
   , 0x10,25.000000,attributes+0,1,NULL,autohelperowl_attackpat201,3,0.016000},
  {owl_attackpat202,3,8, "A911",0,-2,1,1,1,3,0x6,685,
    { 0x00f8fc00, 0xf0f0e000, 0xffbf0000, 0x2c3c3c3c, 0xe0f0f0f0, 0xfcf80000, 0x3c3c2c00, 0x00bfff00},
    { 0x00200000, 0x00200000, 0x02220000, 0x00200028, 0x002000a0, 0x00200000, 0x00200000, 0x00220200}
   , 0x10,25.000000,attributes+0,1,NULL,autohelperowl_attackpat202,3,0.010000},
  {owl_attackpat203,3,8, "A912",-1,-2,1,1,2,3,0x2,722,
    { 0xbfffff00, 0xf8fcfcfc, 0xfcfcf800, 0xfcfcbc00, 0xfcfcf800, 0xffffbf00, 0xbcfcfcfc, 0xf8fcfc00},
    { 0x19620000, 0x10240824, 0x00249000, 0x80601000, 0x08241000, 0x00621900, 0x10608060, 0x90240000}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat204,4,8, "A913",0,-1,1,2,1,3,0x2,722,
    { 0x3c3c3c3c, 0x00fcfc00, 0xf0f0f000, 0xffff0000, 0xfcfc0000, 0x3c3c3c00, 0x00ffff00, 0xf0f0f0f0},
    { 0x28200020, 0x00280800, 0x0020a000, 0x80a20000, 0x08280000, 0x00202800, 0x00a28000, 0xa0200020}
   , 0x10,80.000000,attributes+0,1,NULL,autohelperowl_attackpat204,3,0.610000},
  {owl_attackpat205,4,8, "A914",0,-1,1,2,1,3,0x2,722,
    { 0x3c3c3c3c, 0x00fcfc00, 0xf0f0f000, 0xffff0000, 0xfcfc0000, 0x3c3c3c00, 0x00ffff00, 0xf0f0f0f0},
    { 0x28200020, 0x00280800, 0x0020a000, 0x80a20000, 0x08280000, 0x00202800, 0x00a28000, 0xa0200020}
   , 0x10,25.000000,attributes+0,1,NULL,autohelperowl_attackpat205,3,1.000000},
  {owl_attackpat206,3,8, "A915",0,-2,2,2,2,4,0x2,648,
    { 0x00fafeff, 0xf0f0e0a0, 0xffbf0000, 0x2f3f3f3f, 0xe0f0f0f0, 0xfefa0000, 0x3f3f2f2b, 0x00bfffff},
    { 0x00200800, 0x00208000, 0x80220000, 0x08200020, 0x80200020, 0x08200000, 0x00200800, 0x00228000}
   , 0x10,85.000000,attributes+0,1,NULL,autohelperowl_attackpat206,3,0.010000},
  {owl_attackpat207,5,8, "A916",-1,-1,1,2,2,3,0x2,722,
    { 0x0dffff00, 0xf0f0fcf4, 0xfcfcc000, 0xfc3c3c00, 0xfcf0f000, 0xffff0d00, 0x3c3cfc7c, 0xc0fcfc00},
    { 0x08a20000, 0x20200820, 0x00288000, 0x80202000, 0x08202000, 0x00a20800, 0x20208020, 0x80280000}
   , 0x10,65.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat208,5,4, "A917",-1,-2,2,1,3,3,0x0,722,
    { 0x0c3ffc30, 0xc0f0fc30, 0xfcf0c000, 0xfc3f0c00, 0xfcf0c000, 0xfc3f0c00, 0x0c3ffc30, 0xc0f0fc30},
    { 0x08228020, 0x80200820, 0x08208000, 0x80220800, 0x08208000, 0x80220800, 0x08228020, 0x80200820}
   , 0x10,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat209,4,8, "A918",-1,-2,2,1,3,3,0x0,722,
    { 0x0c3ffc00, 0xc0f0fc30, 0xfcf0c000, 0xfc3c0c00, 0xfcf0c000, 0xfc3f0c00, 0x0c3cfc30, 0xc0f0fc00},
    { 0x08228000, 0x80200820, 0x08208000, 0x80200800, 0x08208000, 0x80220800, 0x08208020, 0x80200800}
   , 0x10,40.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat210,5,8, "A919",0,-2,2,3,2,5,0x2,686,
    { 0x003cffff, 0xc0f0f0c0, 0xfff20000, 0x3f3f0f2f, 0xf0f0c0e0, 0xff3c0000, 0x0f3f3f0f, 0x00f2ffff},
    { 0x00288200, 0x80202080, 0x09a00000, 0x20200804, 0x20208040, 0x82280000, 0x08202008, 0x00a00900}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat211,6,8, "A920",0,-2,2,2,2,4,0x2,686,
    { 0x003cfffd, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f01, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0d, 0x00f0fcfd},
    { 0x00288204, 0x80202080, 0x08a00000, 0x21200800, 0x20208000, 0x82280000, 0x08202108, 0x00a00840}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat212,2,8, "A1001",0,0,1,1,1,1,0x0,685,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00240800, 0x00209000, 0x80600000, 0x18200000, 0x90200000, 0x08240000, 0x00201800, 0x00608000}
   , 0x20,80.000000,attributes+0,1,NULL,autohelperowl_attackpat212,3,1.096000},
  {owl_attackpat213,2,8, "A1001b",0,0,1,1,1,1,0x0,685,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00240800, 0x00209000, 0x80600000, 0x18200000, 0x90200000, 0x08240000, 0x00201800, 0x00608000}
   , 0x20,50.000000,attributes+0,1,NULL,autohelperowl_attackpat213,3,3.000000},
  {owl_attackpat214,2,8, "A1002",-1,-3,1,0,2,3,0x0,686,
    { 0x003c3c30, 0x00f0f000, 0xf0f00000, 0x3c3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3c00, 0x00f0f030},
    { 0x00240800, 0x00209000, 0x80600000, 0x18200000, 0x90200000, 0x08240000, 0x00201800, 0x00608000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat214,3,3.160000},
  {owl_attackpat215,2,8, "A1003",-1,-3,1,0,2,3,0x0,686,
    { 0x003c3c30, 0x00f0f000, 0xf0f00000, 0x3c3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3c00, 0x00f0f030},
    { 0x00240800, 0x00209000, 0x80600000, 0x18200000, 0x90200000, 0x08240000, 0x00201800, 0x00608000}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_attackpat215,3,2.800000},
  {owl_attackpat216,2,8, "A1005",-1,-1,1,0,2,1,0x0,685,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00188000, 0x80102000, 0x08900000, 0x20100800, 0x20108000, 0x80180000, 0x08102000, 0x00900800}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_attackpat216,0,1.810000},
  {owl_attackpat217,2,8, "A1005b",-1,-1,1,0,2,1,0x0,685,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00188000, 0x80102000, 0x08900000, 0x20100800, 0x20108000, 0x80180000, 0x08102000, 0x00900800}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_attackpat217,0,1.810000},
  {owl_attackpat218,2,8, "A1006",0,-1,2,1,2,2,0x0,685,
    { 0x00fcfc30, 0xf0f0f000, 0xfcfc0000, 0x3c3f3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3f3c00, 0x00fcfc30},
    { 0x00980000, 0x20102000, 0x00980000, 0x20102000, 0x20102000, 0x00980000, 0x20102000, 0x00980000}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat219,2,8, "A1006b",0,-1,2,1,2,2,0x0,685,
    { 0x00fcfc30, 0xf0f0f000, 0xfcfc0000, 0x3c3f3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3f3c00, 0x00fcfc30},
    { 0x00980000, 0x20102000, 0x00980000, 0x20102000, 0x20102000, 0x00980000, 0x20102000, 0x00980000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat219,0,0.010000},
  {owl_attackpat220,2,8, "A1008",-1,-1,0,1,1,2,0x0,685,
    { 0x0030fc00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0x0030fc00},
    { 0x00108800, 0x80108000, 0x88100000, 0x08100800, 0x80108000, 0x88100000, 0x08100800, 0x00108800}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat220,0,0.016000},
  {owl_attackpat221,2,8, "A1008b",-1,0,1,2,2,2,0x0,685,
    { 0x00bcbcb0, 0xa0f0f000, 0xf8f80000, 0x3c3f2a00, 0xf0f0a000, 0xbcbc0000, 0x2a3f3c00, 0x00f8f838},
    { 0x00240020, 0x00201000, 0x00600000, 0x10220000, 0x10200000, 0x00240000, 0x00221000, 0x00600020}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat221,3,0.376000},
  {owl_attackpat222,2,8, "A1009",0,-1,1,2,1,3,0x2,721,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00920000, 0x20100020, 0x00180000, 0x00102000, 0x00102000, 0x00920000, 0x20100020, 0x00180000}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_attackpat222,0,1.000000},
  {owl_attackpat223,2,8, "A1010",-1,-2,1,0,2,2,0x2,685,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00600080, 0x10200000, 0x00240000, 0x00201200, 0x00201000, 0x00600000, 0x12200000, 0x00240008}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat223,3,1.000000},
  {owl_attackpat224,4,8, "A1011",0,-1,1,1,1,2,0x2,685,
    { 0x00fc7400, 0x70f07000, 0x74fc0000, 0x343c3400, 0x70f07000, 0x74fc0000, 0x343c3400, 0x00fc7400},
    { 0x00980000, 0x20102000, 0x00980000, 0x20102000, 0x20102000, 0x00980000, 0x20102000, 0x00980000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat224,0,0.016000},
  {owl_attackpat225,3,8, "A1012",-1,-1,1,2,2,3,0x0,721,
    { 0xf0ffbc00, 0xbcfcf030, 0xf8fc3c00, 0x3cfcf800, 0xf0fcbc00, 0xbcfff000, 0xf8fc3c30, 0x3cfcf800},
    { 0x80611800, 0x18608010, 0x90240800, 0x08249000, 0x80601800, 0x18618000, 0x90240810, 0x08249000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat225,3,1.006000},
  {owl_attackpat226,2,8, "A1013",-1,0,1,2,2,2,0x0,722,
    { 0x003cfc30, 0xc0f0f000, 0xfcf00000, 0x3c3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3c00, 0x00f0fc30},
    { 0x00284000, 0x40202000, 0x04a00000, 0x20200400, 0x20204000, 0x40280000, 0x04202000, 0x00a00400}
   , 0x0,10.000000,attributes+0,1,NULL,autohelperowl_attackpat226,3,2.890000},
  {owl_attackpat227,4,8, "A1014",0,-4,1,1,1,5,0x2,722,
    { 0x007fff00, 0xd0f0f0f0, 0xfcf40000, 0x3c3c1c00, 0xf0f0d000, 0xff7f0000, 0x1c3c3c3c, 0x00f4fc00},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_attackpat227,0,0.019600},
  {owl_attackpat228,4,8, "A1015",0,0,1,3,1,3,0x0,686,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00280000, 0x00202000, 0x00a00000, 0x20200000, 0x20200000, 0x00280000, 0x00202000, 0x00a00000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat228,3,1.096000},
  {owl_attackpat229,4,8, "A1015a",0,0,1,3,1,3,0x0,686,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00280000, 0x00202000, 0x00a00000, 0x20200000, 0x20200000, 0x00280000, 0x00202000, 0x00a00000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat229,3,1.096000},
  {owl_attackpat230,3,8, "A1016",0,-2,1,1,1,3,0x2,685,
    { 0x0037fe00, 0xc0f0d0b0, 0xfc700000, 0x1c3c0c00, 0xd0f0c000, 0xfe370000, 0x0c3c1c38, 0x0070fc00},
    { 0x00128000, 0x80100020, 0x08100000, 0x00100800, 0x00108000, 0x80120000, 0x08100020, 0x00100800}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat230,0,0.902176},
  {owl_attackpat231,3,8, "A1016a",0,-2,1,1,1,3,0x2,685,
    { 0x0037fe00, 0xc0f0d0b0, 0xfc700000, 0x1c3c0c00, 0xd0f0c000, 0xfe370000, 0x0c3c1c38, 0x0070fc00},
    { 0x00128000, 0x80100020, 0x08100000, 0x00100800, 0x00108000, 0x80120000, 0x08100020, 0x00100800}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat231,0,0.902176},
  {owl_attackpat232,4,8, "A1017",-1,-1,0,2,1,3,0x0,722,
    { 0x1c3c3c38, 0x00f4fc00, 0xf0f0d000, 0xfe7f0000, 0xfcf40000, 0x3c3c1c00, 0x007ffe00, 0xd0f0f0b0},
    { 0x08200020, 0x00200800, 0x00208000, 0x80220000, 0x08200000, 0x00200800, 0x00228000, 0x80200020}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_attackpat232,3,1.366000},
  {owl_attackpat233,2,8, "A1018",0,0,2,2,2,2,0x0,722,
    { 0x003f3f3e, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3e, 0x00f0f0f0},
    { 0x00120020, 0x00100020, 0x00100000, 0x00120000, 0x00100000, 0x00120000, 0x00120020, 0x00100020}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat234,2,8, "A1019",-1,0,1,3,2,3,0x0,648,
    { 0x00fcf8fc, 0xf0f0b000, 0xbcfc0000, 0x3b3f3f00, 0xb0f0f000, 0xf8fc0000, 0x3f3f3b00, 0x00fcbcfc},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_attackpat234,3,2.461600},
  {owl_attackpat235,1,4, "A1020",-3,-1,1,3,4,4,0x0,720,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xffffffff, 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xffffffff},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat235,3,0.024748},
  {owl_attackpat236,2,8, "A1021",-1,0,1,2,2,2,0x0,685,
    { 0x00303cfc, 0x00f0c000, 0xf0300000, 0x0f3f0300, 0xc0f00000, 0x3c300000, 0x033f0f00, 0x0030f0fc},
    { 0x00200460, 0x00204000, 0x40200000, 0x04220100, 0x40200000, 0x04200000, 0x01220400, 0x00204024}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat236,3,6.010000},
  {owl_attackpat237,3,8, "A1022",-2,-1,1,2,3,3,0x0,648,
    { 0xfcfcfcf8, 0xfcfcfc00, 0xfffffe00, 0xfeffffbf, 0xfcfcfcf8, 0xfcfcfc00, 0xfffffe00, 0xfeffffbf},
    { 0x00200020, 0x00200000, 0x00220000, 0x00220021, 0x00200020, 0x00200000, 0x00220000, 0x00220021}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_attackpat237,3,10.000000},
  {owl_attackpat238,6,8, "A1023",0,-1,3,2,3,3,0x0,685,
    { 0x0070fcf0, 0xd0f0c000, 0xfc340000, 0x0c3f1f00, 0xc0f0d000, 0xfc700000, 0x1f3f0c00, 0x0034fc3c},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat238,3,10.000000},
  {owl_attackpat239,3,8, "A1024a",0,-1,1,2,1,3,0x2,685,
    { 0x00fe7f00, 0x70f0f0e0, 0xf4fc0000, 0x3c3c3400, 0xf0f07000, 0x7ffe0000, 0x343c3c2c, 0x00fcf400},
    { 0x00900200, 0x20100080, 0x00180000, 0x00102000, 0x00102000, 0x02900000, 0x20100008, 0x00180000}
   , 0x2800,90.000000,attributes+0,1,NULL,autohelperowl_attackpat239,0,6.010000},
  {owl_attackpat240,3,8, "A1024b",0,-1,1,2,1,3,0x2,685,
    { 0x00fe7f00, 0x70f0f0e0, 0xf4fc0000, 0x3c3c3400, 0xf0f07000, 0x7ffe0000, 0x343c3c2c, 0x00fcf400},
    { 0x00900200, 0x20100080, 0x00180000, 0x00102000, 0x00102000, 0x02900000, 0x20100008, 0x00180000}
   , 0x2800,90.000000,attributes+0,1,NULL,autohelperowl_attackpat240,0,6.010000},
  {owl_attackpat241,2,8, "A1100",0,0,2,1,2,1,0x0,722,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00240018, 0x00201000, 0x00600000, 0x12210000, 0x10200000, 0x00240000, 0x00211200, 0x00600090}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_attackpat241,3,1.810000},
  {owl_attackpat242,1,4, "A1101",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00108010, 0x80100000, 0x08100000, 0x00110800, 0x00108000, 0x80100000, 0x08110000, 0x00100810}
   , 0x0,93.000000,attributes+0,1,NULL,autohelperowl_attackpat242,0,5.000000},
  {owl_attackpat243,1,4, "A1101b",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00108010, 0x80100000, 0x08100000, 0x00110800, 0x00108000, 0x80100000, 0x08110000, 0x00100810}
   , 0x0,94.000000,attributes+0,1,NULL,autohelperowl_attackpat243,0,1.816000},
  {owl_attackpat244,1,8, "A1101c",-1,-1,0,1,1,2,0x0,685,
    { 0x0030fc00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0x0030fc00},
    { 0x00204400, 0x40204000, 0x44200000, 0x04200400, 0x40204000, 0x44200000, 0x04200400, 0x00204400}
   , 0x0,81.000000,attributes+0,1,NULL,autohelperowl_attackpat244,3,1.160000},
  {owl_attackpat245,2,8, "A1102",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00108018, 0x80100000, 0x08100000, 0x02110800, 0x00108000, 0x80100000, 0x08110200, 0x00100890}
   , 0x0,95.000000,attributes+0,1,NULL,autohelperowl_attackpat245,0,3.000000},
  {owl_attackpat246,2,8, "A1104",-1,-1,1,1,2,2,0x0,683,
    { 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00},
    { 0x04182400, 0x00906400, 0x60904000, 0x64180000, 0x64900000, 0x24180400, 0x00186400, 0x40906000}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_attackpat246,0,1.600000},
  {owl_attackpat247,4,8, "A1105",-1,-1,2,1,3,2,0x2,721,
    { 0xfcfc7c7c, 0x7cfcfc00, 0xf4fcfc00, 0xfffff500, 0xfcfc7c00, 0x7cfcfc00, 0xf5ffff00, 0xfcfcf4f4},
    { 0x40902400, 0x24904000, 0x60180400, 0x04186000, 0x40902400, 0x24904000, 0x60180400, 0x04186000}
   , 0x20,85.000000,attributes+0,1,NULL,autohelperowl_attackpat247,0,1.600000},
  {owl_attackpat248,6,8, "A1106",-1,-1,2,2,3,3,0x2,758,
    { 0xfcff7f5f, 0x7cfcfcf0, 0xf4fcfc00, 0xfffdf500, 0xfcfc7c00, 0x7ffffc00, 0xf5fdff3f, 0xfcfcf4d4},
    { 0x50982400, 0x24946000, 0x60981400, 0x24586000, 0x60942400, 0x24985000, 0x60582400, 0x14986000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat248,0,1.960000},
  {owl_attackpat249,1,4, "A1107",-1,0,1,2,2,2,0x0,685,
    { 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00},
    { 0x00904000, 0x60100000, 0x04180000, 0x00102400, 0x00106000, 0x40900000, 0x24100000, 0x00180400}
   , 0x0,95.000000,attributes+0,1,NULL,autohelperowl_attackpat249,0,1.160000},
  {owl_attackpat250,1,8, "A1107b",-2,0,1,1,3,1,0x0,721,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00904000, 0x60100000, 0x04180000, 0x00102400, 0x00106000, 0x40900000, 0x24100000, 0x00180400}
   , 0x0,96.000000,attributes+0,1,NULL,autohelperowl_attackpat250,0,0.662800},
  {owl_attackpat251,1,8, "A1107c",-1,0,1,1,2,1,0x0,722,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00904000, 0x60100000, 0x04180000, 0x00102400, 0x00106000, 0x40900000, 0x24100000, 0x00180400}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat251,0,0.662800},
  {owl_attackpat252,2,8, "A1108",0,-1,1,1,1,2,0x0,648,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00241800, 0x00609000, 0x90600000, 0x18240000, 0x90600000, 0x18240000, 0x00241800, 0x00609000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat252,3,0.610000},
  {owl_attackpat253,3,8, "A1109",-1,-2,2,2,3,4,0x2,685,
    { 0x1cbcffff, 0xe0f4fcc0, 0xfffad000, 0xff7f2f2f, 0xfcf4e0e0, 0xffbc1c00, 0x2f7fff0f, 0xd0faffff},
    { 0x08240100, 0x00201840, 0x00608000, 0x90200000, 0x18200000, 0x01240800, 0x00209004, 0x80600000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_attackpat253,3,0.610000},
  {owl_attackpat254,1,8, "A1110",0,-3,1,2,1,5,0x2,648,
    { 0x00fcfa00, 0xf0f0b080, 0xbfff0000, 0x383c3c3c, 0xb0f0f0f0, 0xfafc0000, 0x3c3c3808, 0x00ffbf00},
    { 0x00241000, 0x00601000, 0x10600000, 0x10240000, 0x10600000, 0x10240000, 0x00241000, 0x00601000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat255,4,8, "A1111",-2,-2,2,2,4,4,0x4,683,
    { 0xfcffffff, 0xfffffcf0, 0xfffdff3c, 0xffffffdf, 0xfcffffdc, 0xfffffcf0, 0xffffff3f, 0xfffdffff},
    { 0x4090a400, 0xa4904000, 0x68180400, 0x04186800, 0x4090a400, 0xa4904000, 0x68180400, 0x04186800}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat256,2,8, "A1112",-1,-1,1,2,2,3,0x2,720,
    { 0xffffff00, 0xfcfcfcfc, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfcfc, 0xfcfcfc00},
    { 0x81900000, 0x28100004, 0x00180800, 0x0010a000, 0x00102800, 0x00908100, 0xa0100040, 0x08180000}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_attackpat256,0,1.000000},
  {owl_attackpat257,3,8, "A1113",-2,-2,2,2,4,4,0x0,722,
    { 0x7ffffcfd, 0xf4fcfc3c, 0xfcfcf400, 0xffff7f00, 0xfcfcf400, 0xfcff7f00, 0x7ffffff1, 0xf4fcfcfc},
    { 0x00110018, 0x00100010, 0x00100000, 0x02110000, 0x00100000, 0x00110000, 0x00110210, 0x00100090}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat257,0,0.016000},
  {owl_attackpat258,4,8, "A1114",-2,-2,2,2,4,4,0x0,721,
    { 0x7ffffdf1, 0xf4fcfc7c, 0xfcfcf400, 0xfcff7f00, 0xfcfcf400, 0xfdff7f00, 0x7ffffcf5, 0xf4fcfc3c},
    { 0x00110810, 0x00108010, 0x80100000, 0x08110000, 0x80100000, 0x08110000, 0x00110810, 0x00108010}
   , 0x0,81.000000,attributes+0,1,NULL,autohelperowl_attackpat258,0,0.016000},
  {owl_attackpat259,5,8, "A1115",-1,-1,2,2,3,3,0x0,721,
    { 0x4f7ffffd, 0xd4f0fcfc, 0xfcf4c400, 0xff3f5f00, 0xfcf0d400, 0xff7f4f00, 0x5f3ffffd, 0xc4f4fcfc},
    { 0x04206410, 0x40a04400, 0x64204000, 0x44290400, 0x44a04000, 0x64200400, 0x04294400, 0x40206410}
   , 0x0,81.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat260,6,8, "A1116",-1,-1,2,1,3,2,0x0,648,
    { 0x30fcfc54, 0xf0fcf000, 0xfcfc3000, 0x3dfd3d00, 0xf0fcf000, 0xfcfc3000, 0x3dfd3d00, 0x30fcfc54},
    { 0x20641800, 0x10689000, 0x90642000, 0x18a41000, 0x90681000, 0x18642000, 0x10a41800, 0x20649000}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_attackpat260,3,1.096000},
  {owl_attackpat261,2,8, "A1117",-1,-1,0,1,1,2,0x0,685,
    { 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00},
    { 0x00904800, 0x60108000, 0x84180000, 0x08102400, 0x80106000, 0x48900000, 0x24100800, 0x00188400}
   , 0x20,80.000000,attributes+0,1,NULL,autohelperowl_attackpat261,0,3.000000},
  {owl_attackpat262,2,8, "A1117a",-1,-1,0,1,1,2,0x0,685,
    { 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00},
    { 0x00904800, 0x60108000, 0x84180000, 0x08102400, 0x80106000, 0x48900000, 0x24100800, 0x00188400}
   , 0x20,80.000000,attributes+0,1,NULL,autohelperowl_attackpat262,0,3.000000},
  {owl_attackpat263,2,8, "A1118",-1,-1,1,1,2,2,0x2,721,
    { 0xf0fcfc00, 0xfcfcf000, 0xfcfc3c00, 0x3cfcfc00, 0xf0fcfc00, 0xfcfcf000, 0xfcfc3c00, 0x3cfcfc00},
    { 0x90600000, 0x18240000, 0x00241800, 0x00609000, 0x00241800, 0x00609000, 0x90600000, 0x18240000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat263,3,1.600000},
  {owl_attackpat264,2,8, "A1119",0,0,1,2,1,2,0x0,685,
    { 0x00383c0c, 0x00f0e000, 0xf0b00000, 0x2f3c0000, 0xe0f00000, 0x3c380000, 0x003c2f00, 0x00b0f0c0},
    { 0x00200008, 0x00200000, 0x00200000, 0x02200000, 0x00200000, 0x00200000, 0x00200200, 0x00200080}
   , 0x20,36.000000,attributes+0,1,NULL,autohelperowl_attackpat264,3,0.256336},
  {owl_attackpat265,1,8, "A1121",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00244004, 0x40201000, 0x04600000, 0x11200400, 0x10204000, 0x40240000, 0x04201100, 0x00600440}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_attackpat265,3,0.021760},
  {owl_attackpat266,2,8, "A1122",0,0,2,1,2,1,0x0,685,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00200008, 0x00200000, 0x00200000, 0x02200000, 0x00200000, 0x00200000, 0x00200200, 0x00200080}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat266,3,6.010000},
  {owl_attackpat267,2,8, "A1122a",0,0,2,1,2,1,0x0,685,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00200008, 0x00200000, 0x00200000, 0x02200000, 0x00200000, 0x00200000, 0x00200200, 0x00200080}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat267,3,6.010000},
  {owl_attackpat268,3,8, "A1123",0,-2,1,1,1,3,0x2,685,
    { 0x0037fe00, 0xc0f0d0b0, 0xfc700000, 0x1c3c0c00, 0xd0f0c000, 0xfe370000, 0x0c3c1c38, 0x0070fc00},
    { 0x00128000, 0x80100020, 0x08100000, 0x00100800, 0x00108000, 0x80120000, 0x08100020, 0x00100800}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat268,0,1.096000},
  {owl_attackpat269,3,8, "A1123a",0,-2,1,1,1,3,0x2,685,
    { 0x0037fe00, 0xc0f0d0b0, 0xfc700000, 0x1c3c0c00, 0xd0f0c000, 0xfe370000, 0x0c3c1c38, 0x0070fc00},
    { 0x00128000, 0x80100020, 0x08100000, 0x00100800, 0x00108000, 0x80120000, 0x08100020, 0x00100800}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat269,0,1.096000},
  {owl_attackpat270,1,8, "A1124",0,-1,2,1,2,2,0x0,722,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat270,0,1.096000},
  {owl_attackpat271,5,8, "A1124a",0,-1,2,1,2,2,0x0,685,
    { 0x003c7c54, 0x40f0f000, 0xf4f00000, 0x3d3d0500, 0xf0f04000, 0x7c3c0000, 0x053d3d00, 0x00f0f454},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat271,0,0.667600},
  {owl_attackpat272,4,8, "A1124b",0,-1,2,1,2,2,0x0,722,
    { 0x003c7c50, 0x40f0f000, 0xf4f00000, 0x3c3d0500, 0xf0f04000, 0x7c3c0000, 0x053d3c00, 0x00f0f414},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_attackpat272,0,3.475600},
  {owl_attackpat273,6,8, "A1125",-2,-1,1,2,3,3,0x0,721,
    { 0x3dfdfd20, 0xf0fcfc54, 0xfcfcf000, 0xfcfe3c00, 0xfcfcf000, 0xfdfd3d00, 0x3cfefc54, 0xf0fcfc20},
    { 0x24902400, 0x20984400, 0x60186000, 0x44982000, 0x44982000, 0x24902400, 0x20984400, 0x60186000}
   , 0x0,76.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat274,1,4, "A1126",-1,-1,0,1,1,2,0x0,685,
    { 0x0030fc00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0x0030fc00},
    { 0x00204400, 0x40204000, 0x44200000, 0x04200400, 0x40204000, 0x44200000, 0x04200400, 0x00204400}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_attackpat274,3,3.320000},
  {owl_attackpat275,2,8, "A1127",-1,-1,0,1,1,2,0x0,685,
    { 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00},
    { 0x00608400, 0x90204000, 0x48240000, 0x04201800, 0x40209000, 0x84600000, 0x18200400, 0x00244800}
   , 0x20,70.000000,attributes+0,1,NULL,autohelperowl_attackpat275,3,1.369456},
  {owl_attackpat276,2,8, "A1127a",-1,-1,0,1,1,2,0x0,685,
    { 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00},
    { 0x00608400, 0x90204000, 0x48240000, 0x04201800, 0x40209000, 0x84600000, 0x18200400, 0x00244800}
   , 0x20,70.000000,attributes+0,1,NULL,autohelperowl_attackpat276,3,1.369456},
  {owl_attackpat277,4,8, "A1128",0,-1,1,2,1,3,0x0,647,
    { 0x00fcfc00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0x00ffff00},
    { 0x00248800, 0x80209000, 0x88620000, 0x18200820, 0x90208020, 0x88240000, 0x08201800, 0x00628800}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_attackpat277,3,0.970000},
  {owl_attackpat278,5,8, "A1129",-1,-1,2,2,3,3,0x0,648,
    { 0x7fffff7c, 0xf4fcfcfc, 0xfcfcf400, 0xffff7d00, 0xfcfcf400, 0xffff7f00, 0x7dfffffc, 0xf4fcfcf4},
    { 0x29641000, 0x10681804, 0x1064a000, 0x90a41000, 0x18681000, 0x10642900, 0x10a49040, 0xa0641000}
   , 0x0,86.000000,attributes+0,1,NULL,autohelperowl_attackpat278,3,1.000000},
  {owl_attackpat279,4,8, "A1130",-2,-3,2,1,4,4,0x0,686,
    { 0x7cfeffff, 0xf4fcfce0, 0xfffef400, 0xffff7f2f, 0xfcfcf4e0, 0xfffe7c00, 0x7fffff2f, 0xf4feffff},
    { 0x24580800, 0x1018a400, 0x80946000, 0x68901000, 0xa4181000, 0x08582400, 0x10906800, 0x60948000}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat280,2,8, "A1131",0,-1,1,2,1,3,0x2,685,
    { 0x00ff3c00, 0x30f0f030, 0xf0fc0000, 0x3c3c3000, 0xf0f03000, 0x3cff0000, 0x303c3c30, 0x00fcf000},
    { 0x00920000, 0x20100020, 0x00180000, 0x00102000, 0x00102000, 0x00920000, 0x20100020, 0x00180000}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_attackpat280,0,6.010000},
  {owl_attackpat281,5,8, "A1132",-1,-1,2,2,3,3,0xa,648,
    { 0xf0fcffff, 0xfcfcf0c0, 0xfcfc3c00, 0x3fffff00, 0xf0fcfc00, 0xfffcf000, 0xffff3f0f, 0x3cfcfcfc},
    { 0x10681a06, 0x1064a080, 0x90a41000, 0x29641000, 0xa0641000, 0x1a681000, 0x1064290a, 0x10a49040}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat282,2,8, "A1133a",0,-1,4,2,4,3,0x0,723,
    { 0x003f3d3f, 0x00f0f070, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3d3f0000, 0x003f3f37, 0x00f0f0f0},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_attackpat282,0,0.021760},
  {owl_attackpat283,1,8, "A1133b",0,-1,4,2,4,3,0x0,722,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat283,0,0.021760},
  {owl_attackpat284,2,8, "A1134",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00980400, 0x20106000, 0x40980000, 0x24102000, 0x60102000, 0x04980000, 0x20102400, 0x00984000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat284,0,0.016000},
  {owl_attackpat285,2,8, "A1134b",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00980400, 0x20106000, 0x40980000, 0x24102000, 0x60102000, 0x04980000, 0x20102400, 0x00984000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat285,0,0.016000},
  {owl_attackpat286,2,8, "A1134c",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00980400, 0x20106000, 0x40980000, 0x24102000, 0x60102000, 0x04980000, 0x20102400, 0x00984000}
   , 0x0,40.000000,attributes+0,1,NULL,autohelperowl_attackpat286,0,0.010000},
  {owl_attackpat287,2,8, "A1134d",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00980400, 0x20106000, 0x40980000, 0x24102000, 0x60102000, 0x04980000, 0x20102400, 0x00984000}
   , 0x0,40.000000,attributes+0,1,NULL,autohelperowl_attackpat287,0,0.010000},
  {owl_attackpat288,2,8, "A1135",0,-2,1,1,1,3,0x2,685,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00900200, 0x20100080, 0x00180000, 0x00102000, 0x00102000, 0x02900000, 0x20100008, 0x00180000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat288,0,9.610001},
  {owl_attackpat289,2,8, "A1136",-1,0,2,2,3,2,0x0,685,
    { 0x003cff30, 0xc0f0f0c0, 0xfcf00000, 0x3c3f0c00, 0xf0f0c000, 0xff3c0000, 0x0c3f3c0c, 0x00f0fc30},
    { 0x00108210, 0x80100080, 0x08100000, 0x00110800, 0x00108000, 0x82100000, 0x08110008, 0x00100810}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat289,0,9.610001},
  {owl_attackpat290,6,8, "A1137",-2,-2,1,1,3,3,0x0,721,
    { 0x7ffffc00, 0xf4fdfd3d, 0xfcfcf450, 0xfcfc7c00, 0xfdfdf400, 0xfcff7f15, 0x7cfcfcf0, 0xf4fcfc00},
    { 0x00106800, 0x40908000, 0xa4100000, 0x08180400, 0x80904000, 0x68100000, 0x04180800, 0x0010a400}
   , 0x0,79.000000,attributes+0,1,NULL,autohelperowl_attackpat290,0,0.019600},
  {owl_attackpat291,6,8, "A1138",-1,-3,2,1,3,4,0x2,648,
    { 0xc0f0fcfc, 0xfcf0c000, 0xff3d0d00, 0x0f3fff5f, 0xc0f0fcd4, 0xfcf0c000, 0xff3f0f00, 0x0d3dffff},
    { 0x00101820, 0x00508000, 0x90100000, 0x08160000, 0x80500000, 0x18100000, 0x00160800, 0x00109020}
   , 0x0,30.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat292,4,8, "A1139",-1,-1,2,2,3,3,0x0,683,
    { 0xbcfcfcf4, 0xf8fcfc00, 0xfffcf800, 0xfdffbf0c, 0xfcfcf8c0, 0xfcfcbc00, 0xbffffd00, 0xf8fcff7c},
    { 0x00241860, 0x00609000, 0x91600000, 0x18260104, 0x90600040, 0x18240000, 0x01261800, 0x00609124}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat292,3,2.176000},
  {owl_attackpat293,1,8, "A1201",0,-1,1,1,1,2,0x0,648,
    { 0x0030fc00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0x0030fc00},
    { 0x00102400, 0x00904000, 0x60100000, 0x04180000, 0x40900000, 0x24100000, 0x00180400, 0x00106000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_attackpat293,0,0.016000},
  {owl_attackpat294,1,8, "A1203",-1,-1,0,1,1,2,0x0,685,
    { 0x00fc3000, 0x30f03000, 0x30fc0000, 0x303c3000, 0x30f03000, 0x30fc0000, 0x303c3000, 0x00fc3000},
    { 0x00640000, 0x10201000, 0x00640000, 0x10201000, 0x10201000, 0x00640000, 0x10201000, 0x00640000}
   , 0x10,80.000000,attributes+0,1,NULL,autohelperowl_attackpat294,3,0.016000},
  {owl_attackpat295,1,8, "A1204",-1,-1,0,1,1,2,0x0,685,
    { 0x00fc3000, 0x30f03000, 0x30fc0000, 0x303c3000, 0x30f03000, 0x30fc0000, 0x303c3000, 0x00fc3000},
    { 0x00640000, 0x10201000, 0x00640000, 0x10201000, 0x10201000, 0x00640000, 0x10201000, 0x00640000}
   , 0x10,30.000000,attributes+0,1,NULL,autohelperowl_attackpat295,3,0.034000},
  {owl_attackpat296,2,8, "A1205",-1,0,0,1,1,1,0x0,685,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00240800, 0x00209000, 0x80600000, 0x18200000, 0x90200000, 0x08240000, 0x00201800, 0x00608000}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_attackpat296,3,0.610000},
  {owl_attackpat297,2,8, "A1206",-1,0,0,1,1,1,0x0,685,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00240800, 0x00209000, 0x80600000, 0x18200000, 0x90200000, 0x08240000, 0x00201800, 0x00608000}
   , 0x10,30.000000,attributes+0,1,NULL,autohelperowl_attackpat297,3,0.630160},
  {owl_attackpat298,3,8, "A1207",-1,-2,1,0,2,2,0x0,685,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00a40800, 0x20209000, 0x80680000, 0x18202000, 0x90202000, 0x08a40000, 0x20201800, 0x00688000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat298,3,1.000000},
  {owl_attackpat299,2,8, "A1208",-2,-2,1,1,3,3,0x2,683,
    { 0xfcfcbc00, 0xbfffff00, 0xfafefffc, 0xfcfcf8e8, 0xffffbfac, 0xbcfcfcfc, 0xf8fcfc00, 0xfffefa00},
    { 0x00201000, 0x02600000, 0x10200108, 0x00240040, 0x00600204, 0x10200080, 0x00240000, 0x01201000}
   , 0x0,40.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat300,2,8, "A1209",0,-1,1,2,1,3,0x2,758,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00681000, 0x10602000, 0x10a40000, 0x20241000, 0x20601000, 0x10680000, 0x10242000, 0x00a41000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_attackpat300,3,0.010000},
  {owl_attackpat301,3,8, "A1301",-2,-2,3,3,5,5,0xa,723,
    { 0xeaffffff, 0xfffaf8f8, 0xffffaf2f, 0xbfbfffff, 0xf8faffff, 0xffffeae0, 0xffbfbfbf, 0xafffffff},
    { 0x4094a000, 0xa4901000, 0x28580400, 0x10186800, 0x1090a400, 0xa0944000, 0x68181000, 0x04582800}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_attackpat301,0,0.010000},
  {owl_attackpat302,2,8, "A1302",-1,-2,1,1,2,3,0xa,721,
    { 0x3fffff00, 0xf0fcfcfc, 0xfcfcf000, 0xfcfc3c00, 0xfcfcf000, 0xffff3f00, 0x3cfcfcfc, 0xf0fcfc00},
    { 0x20600000, 0x10280000, 0x00242000, 0x00a01000, 0x00281000, 0x00602000, 0x10a00000, 0x20240000}
   , 0x10,30.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat303,3,8, "A1303",-1,-2,1,1,2,3,0xa,648,
    { 0x20fcfcfc, 0xf0f8f000, 0xfcfc2000, 0x3fbf3f00, 0xf0f8f000, 0xfcfc2000, 0x3fbf3f00, 0x20fcfcfc},
    { 0x00280020, 0x00202000, 0x00a00000, 0x20220000, 0x20200000, 0x00280000, 0x00222000, 0x00a00020}
   , 0x10,90.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat304,4,8, "A1303b",-1,-2,1,1,2,3,0xa,721,
    { 0x3fff3f00, 0x30fcfcfc, 0xf0fcf000, 0xfcfc3000, 0xfcfc3000, 0x3fff3f00, 0x30fcfcfc, 0xf0fcf000},
    { 0x20622400, 0x10a84020, 0x60242000, 0x04a81000, 0x40a81000, 0x24622000, 0x10a80420, 0x20246000}
   , 0x10,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat305,3,8, "A1303c",-1,-1,1,2,2,3,0xa,721,
    { 0xfcfcfc00, 0xfcfefc00, 0xfcfcfc20, 0xfcfcfc00, 0xfcfefc00, 0xfcfcfc20, 0xfcfcfc00, 0xfcfcfc00},
    { 0xa0102000, 0x08980000, 0x20102800, 0x00988000, 0x00980800, 0x2010a000, 0x80980000, 0x28102000}
   , 0x10,85.000000,attributes+0,1,NULL,autohelperowl_attackpat305,0,1.000000},
  {owl_attackpat306,2,8, "A1304",0,-1,1,1,1,2,0xa,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00608000, 0x90200000, 0x08240000, 0x00201800, 0x00209000, 0x80600000, 0x18200000, 0x00240800}
   , 0x10,60.000000,attributes+0,1,NULL,autohelperowl_attackpat306,3,0.016000},
  {owl_attackpat307,5,8, "A1305",0,-1,2,2,2,3,0xa,721,
    { 0x3f3f3f00, 0x00fcffff, 0xf0f0f0c0, 0xfcfc0000, 0xfffc0000, 0x3f3f3f0f, 0x00fcfcfc, 0xf0f0f000},
    { 0x20202000, 0x00a80202, 0x20202080, 0x00a80000, 0x02a80000, 0x2020200a, 0x00a80000, 0x20202000}
   , 0x10,90.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat308,4,8, "A1305b",0,-1,2,2,2,3,0xa,685,
    { 0x00fcfcfc, 0xf0f0f000, 0xfffc0000, 0x3f3f3f0f, 0xf0f0f0c0, 0xfcfc0000, 0x3f3f3f00, 0x00fcffff},
    { 0x00280000, 0x00202000, 0x02a00000, 0x2020000a, 0x20200080, 0x00280000, 0x00202000, 0x00a00202}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat309,5,8, "A1306",0,-1,2,2,2,3,0xa,758,
    { 0x3f3f3f00, 0x00fcffff, 0xf0f0f0c0, 0xfcfc0000, 0xfffc0000, 0x3f3f3f0f, 0x00fcfcfc, 0xf0f0f000},
    { 0x20202000, 0x00a80202, 0x20202080, 0x00a80000, 0x02a80000, 0x2020200a, 0x00a80000, 0x20202000}
   , 0x10,85.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat310,6,8, "A1307",-1,-1,1,2,2,3,0xa,722,
    { 0xdcffff00, 0xfcf4fcf0, 0xfcfcdc00, 0xfc7cfc00, 0xfcf4fc00, 0xffffdc00, 0xfc7cfc3c, 0xdcfcfc00},
    { 0x88221200, 0x086008a0, 0x10208800, 0x80248000, 0x08600800, 0x12228800, 0x80248028, 0x88201000}
   , 0x10,85.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat311,6,8, "A1308",-1,-1,1,2,2,3,0xa,685,
    { 0x1cfcfc00, 0xf0f4fc00, 0xfffdd000, 0xfc7c3c1c, 0xfcf4f0d0, 0xfcfc1c00, 0x3c7cfc00, 0xd0fdff00},
    { 0x08a00000, 0x20200800, 0x02288000, 0x80202008, 0x08202080, 0x00a00800, 0x20208000, 0x80280200}
   , 0x10,90.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat312,4,8, "A1309",0,-1,1,2,1,3,0xa,685,
    { 0x00f7fd00, 0xf0f0d070, 0xfc7c0000, 0x1c3c3c00, 0xd0f0f000, 0xfdf70000, 0x3c3c1c34, 0x007cfc00},
    { 0x00220400, 0x00204020, 0x40200000, 0x04200000, 0x40200000, 0x04220000, 0x00200420, 0x00204000}
   , 0x10,90.000000,attributes+0,1,NULL,autohelperowl_attackpat312,3,0.016000},
  {owl_attackpat313,3,8, "A1310",0,-1,1,2,1,3,0xa,647,
    { 0x00fffd00, 0xf0f0f070, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfdff0000, 0x3c3c3c34, 0x00fcfc00},
    { 0x00221400, 0x00604020, 0x50200000, 0x04240000, 0x40600000, 0x14220000, 0x00240420, 0x00205000}
   , 0x10,30.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat314,6,8, "A1310b",-1,-1,1,2,2,3,0xa,648,
    { 0xdcffff00, 0xfcf4fcf0, 0xfcfcdc00, 0xfc7cfc00, 0xfcf4fc00, 0xffffdc00, 0xfc7cfc3c, 0xdcfcfc00},
    { 0x88221600, 0x086048a0, 0x50208800, 0x84248000, 0x48600800, 0x16228800, 0x80248428, 0x88205000}
   , 0x10,31.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat315,4,8, "A1311",-1,-1,1,2,2,3,0xa,722,
    { 0xfcfcfc3c, 0xfcfcfc00, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcffff00, 0xfcfcfcf0},
    { 0x20908020, 0xa0180000, 0x08182000, 0x00922800, 0x0018a000, 0x80902000, 0x28920000, 0x20180820}
   , 0x10,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat316,4,8, "A1311b",-1,-1,1,3,2,4,0xa,721,
    { 0xfcfcfc3c, 0xfcfcfc00, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcffff00, 0xfcfcfcf0},
    { 0x20908020, 0xa0180000, 0x08182000, 0x00922800, 0x0018a000, 0x80902000, 0x28920000, 0x20180820}
   , 0x10,81.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat317,5,8, "A1312",-1,-1,2,2,3,3,0xa,685,
    { 0x3cfcfcfc, 0xf0fcfc00, 0xfffcf000, 0xffff3f0d, 0xfcfcf0c0, 0xfcfc3c00, 0x3fffff00, 0xf0fcfffd},
    { 0x24a00000, 0x20280400, 0x02286000, 0x40a02008, 0x04282080, 0x00a02400, 0x20a04000, 0x60280200}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat318,2,8, "A1313",-1,-2,2,3,3,5,0xa,722,
    { 0x0e7effff, 0xd0f0fce8, 0xfff7c300, 0xff3f1fff, 0xfcf0d0fc, 0xff7e0e00, 0x1f3fffaf, 0xc3f7ffff},
    { 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat319,3,8, "A1314",-1,-2,1,1,2,3,0xa,722,
    { 0x38fcfc7c, 0xf0fcf800, 0xfcfcb000, 0xbfff3d00, 0xf8fcf000, 0xfcfc3800, 0x3dffbf00, 0xb0fcfcf4},
    { 0x10a00000, 0x20240000, 0x00281000, 0x00602000, 0x00242000, 0x00a01000, 0x20600000, 0x10280000}
   , 0x10,45.000000,attributes+0,1,NULL,autohelperowl_attackpat319,3,1.000000},
  {owl_attackpat320,3,8, "A1315",-2,-1,1,2,3,3,0xa,721,
    { 0xfcffff00, 0xfffffff0, 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xfffffcfc, 0xfcfcfc3c, 0xfcfcfc00},
    { 0x08210000, 0x00220910, 0x00208060, 0x80200000, 0x09220000, 0x00210824, 0x00208010, 0x80200000}
   , 0x0,55.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat321,4,8, "A1316",0,-1,2,2,2,3,0xa,685,
    { 0x00fcffff, 0xf0f0f0c0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfffc0000, 0x3f3f3f0f, 0x00fcfcfc},
    { 0x00280206, 0x00202080, 0x00a00000, 0x21200000, 0x20200000, 0x02280000, 0x0020210a, 0x00a00040}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat322,3,8, "A1317",-1,-1,1,2,2,3,0xa,685,
    { 0xfcfcfc00, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc3c, 0xfcfcfcf0, 0xfcfcfc00, 0xfcfcfc00, 0xfcffff00},
    { 0x80a00000, 0x28200000, 0x01290800, 0x0020a014, 0x00202850, 0x00a08000, 0xa0200000, 0x08290100}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat322,3,0.610000},
  {owl_attackpat323,4,8, "A1318",-1,-1,1,2,2,3,0xa,647,
    { 0xfcffff00, 0xfcfcfcf0, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc3c, 0xfcfcfc00},
    { 0x08291900, 0x0060a850, 0x90a08000, 0xa8240000, 0xa8600000, 0x19290800, 0x0024a814, 0x80a09000}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat323,3,0.610000},
  {owl_attackpat324,4,8, "A1319",-1,-2,2,1,3,3,0xa,758,
    { 0x3f3f7fff, 0x40fcfcfc, 0xf4f0f000, 0xffff0700, 0xfcfc4000, 0x7f3f3f00, 0x07ffffff, 0xf0f0f4fc},
    { 0x18202000, 0x00a40800, 0x20209000, 0x80680000, 0x08a40000, 0x20201800, 0x00688000, 0x90202000}
   , 0x10,61.000000,attributes+0,1,NULL,autohelperowl_attackpat324,3,1.000000},
  {owl_attackpat325,3,8, "A1319b",-1,0,2,2,3,2,0xa,685,
    { 0x3f3f3f3f, 0x00fcfcfc, 0xf0f0f000, 0xffff0000, 0xfcfc0000, 0x3f3f3f00, 0x00ffffff, 0xf0f0f0f0},
    { 0x09120200, 0x001008a4, 0x00108000, 0x80100000, 0x08100000, 0x02120900, 0x00108068, 0x80100000}
   , 0x10,30.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat326,5,8, "A1319c",-1,-2,2,1,3,3,0xa,722,
    { 0x3f3f7fff, 0x40fcfcfc, 0xf4f0f000, 0xffff0700, 0xfcfc4000, 0x7f3f3f00, 0x07ffffff, 0xf0f0f4fc},
    { 0x18212200, 0x00a40890, 0x20209000, 0x80680000, 0x08a40000, 0x22211800, 0x00688018, 0x90202000}
   , 0x10,61.000000,attributes+0,1,NULL,autohelperowl_attackpat326,3,1.000000},
  {owl_attackpat327,3,8, "A1320",-1,-1,1,1,2,2,0xa,722,
    { 0x3c3cfc00, 0xc0fcfc00, 0xfcf0f000, 0xfcfc0c00, 0xfcfcc000, 0xfc3c3c00, 0x0cfcfc00, 0xf0f0fc00},
    { 0x20249000, 0x80681000, 0x18602000, 0x10a40800, 0x10688000, 0x90242000, 0x08a41000, 0x20601800}
   , 0x10,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat328,3,8, "A1321",-1,-1,1,1,2,2,0xa,648,
    { 0xc0fcfc00, 0xfcf0f000, 0xfcfc0c00, 0x3c3cfc00, 0xf0f0fc00, 0xfcfcc000, 0xfc3c3c00, 0x0cfcfc00},
    { 0x80281000, 0x08602000, 0x10a00800, 0x20248000, 0x20600800, 0x10288000, 0x80242000, 0x08a01000}
   , 0x10,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat329,3,8, "A1322",-1,-2,1,0,2,2,0xa,648,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00280008, 0x00202000, 0x00a00000, 0x22200000, 0x20200000, 0x00280000, 0x00202200, 0x00a00080}
   , 0x10,40.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat330,4,8, "A1323",0,-1,3,1,3,2,0xa,649,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00a40808, 0x20209000, 0x80680000, 0x1a202000, 0x90202000, 0x08a40000, 0x20201a00, 0x00688080}
   , 0x10,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat331,1,8, "A1324",-3,-2,2,2,5,4,0xa,647,
    { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    { 0x40200000, 0x04210000, 0x00200410, 0x00204000, 0x00210400, 0x00204010, 0x40200000, 0x04200000}
   , 0x0,90.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat332,4,8, "A1325",-1,-1,2,2,3,3,0x6,721,
    { 0xffffff3f, 0xfcfcfcfc, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc00, 0xffffff00, 0xfcffffff, 0xfcfcfcf0},
    { 0x54208820, 0x84248400, 0x88205400, 0x48624800, 0x84248400, 0x88205400, 0x48624800, 0x54208820}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat333,2,8, "A1326",-2,-2,2,2,4,4,0x9,611,
    { 0xffffffff, 0xfcfcfefe, 0xffffff80, 0xffffffff, 0xfefcfcfc, 0xffffff0a, 0xffffffff, 0xffffffff},
    { 0x50208000, 0x84240000, 0x08211400, 0x00604810, 0x00248410, 0x80205000, 0x48600000, 0x14210800}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat334,3,8, "A1327",-2,-2,3,2,5,4,0x9,646,
    { 0xffffff80, 0xffffffff, 0xffffffff, 0xfcfcfefe, 0xffffffff, 0xffffffff, 0xfefcfcfc, 0xffffff0a},
    { 0x09219400, 0x80604814, 0x58208000, 0x84240800, 0x48608000, 0x94210900, 0x08248450, 0x80205800}
   , 0x10,85.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat335,7,8, "A1328",-1,-2,2,1,3,3,0xa,722,
    { 0x0d39ef5f, 0xc0b0ecd4, 0xecb0c000, 0xef390d00, 0xecb0c000, 0xef390d00, 0x0d39ef5f, 0xc0b0ecd4},
    { 0x08208000, 0x80200800, 0x08208000, 0x80200800, 0x08208000, 0x80200800, 0x08208000, 0x80200800}
   , 0x10,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat336,4,8, "A1329",-1,-1,2,1,3,2,0xa,722,
    { 0x0c3c7c6c, 0x40f0fc00, 0xf4f0c000, 0xff3e0500, 0xfcf04000, 0x7c3c0c00, 0x053eff00, 0xc0f0f4e4},
    { 0x08241004, 0x00601800, 0x10608000, 0x91240000, 0x18600000, 0x10240800, 0x00249100, 0x80601040}
   , 0x10,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat337,6,8, "A1330",-1,-1,2,1,3,2,0xa,647,
    { 0xf0fcfcec, 0xfcfcf000, 0xfcfc3c00, 0x3ffeff00, 0xf0fcfc00, 0xfcfcf000, 0xfffe3f00, 0x3cfcfcec},
    { 0xa0289844, 0x8868a000, 0x98a02800, 0x29a48900, 0xa0688800, 0x9828a000, 0x89a42900, 0x28a09844}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_attackpat337,3,0.610000},
  {owl_attackpat338,3,8, "A1331",-1,-1,1,1,2,2,0xa,648,
    { 0x3cfcfc00, 0xf0fcfc00, 0xfcfcf000, 0xfcfc3c00, 0xfcfcf000, 0xfcfc3c00, 0x3cfcfc00, 0xf0fcfc00},
    { 0x24902400, 0x20984400, 0x60186000, 0x44982000, 0x44982000, 0x24902400, 0x20984400, 0x60186000}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat338,0,1.000000},
  {owl_attackpat339,6,8, "A1332",0,-1,2,2,2,3,0xa,648,
    { 0x0074fcfc, 0xd0f0d000, 0xff740000, 0x1f3f1f0d, 0xd0f0d0c0, 0xfc740000, 0x1f3f1f00, 0x0074fffd},
    { 0x00200420, 0x00204000, 0x42200000, 0x04220008, 0x40200080, 0x04200000, 0x00220400, 0x00204220}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat339,3,1.000000},
  {owl_attackpat340,7,8, "A1333",-2,-1,1,2,3,3,0xa,685,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xfffffffc, 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xfffffffc},
    { 0x005800a8, 0x10102000, 0x02960200, 0x221212a8, 0x201010a8, 0x00580000, 0x12122200, 0x029602a8}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat340,0,0.016000},
  {owl_attackpat341,8,8, "A1334",-1,-1,2,2,3,3,0xa,649,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xfffffc00, 0xffffff3f, 0xfcfcfcf0, 0xfcfcfc00, 0xffffff00, 0xfcffffff},
    { 0xa8185800, 0x4858a800, 0x9692a800, 0xa894842a, 0xa85848a0, 0x5818a800, 0x8494a800, 0xa8929602}
   , 0x10,55.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat342,3,8, "A1335",-1,-2,1,1,2,3,0xa,758,
    { 0x3fffff00, 0xf0fcfcfc, 0xfcfcf000, 0xfcfc3c00, 0xfcfcf000, 0xffff3f00, 0x3cfcfcfc, 0xf0fcfc00},
    { 0x20605800, 0x50688000, 0x94242000, 0x08a41400, 0x80685000, 0x58602000, 0x14a40800, 0x20249400}
   , 0x10,41.000000,attributes+0,1,NULL,autohelperowl_attackpat342,3,1.600000},
  {owl_attackpat343,3,8, "A1335b",-1,-1,1,2,2,3,0xa,647,
    { 0xfcffff00, 0xfcfcfcf0, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc3c, 0xfcfcfc00},
    { 0x08192100, 0x00902850, 0x20908000, 0xa0180000, 0x28900000, 0x21190800, 0x0018a014, 0x80902000}
   , 0x10,41.000000,attributes+0,1,NULL,autohelperowl_attackpat343,0,1.600000},
  {owl_attackpat344,5,8, "A1336",0,-1,2,2,2,3,0xa,649,
    { 0x00ffffff, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3f, 0x00fcfcfc},
    { 0x00a90224, 0x20202090, 0x00a80000, 0x21222000, 0x20202000, 0x02a90000, 0x20222118, 0x00a80060}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_attackpat344,3,1.600000},
  {owl_attackpat345,8,8, "A1337",-1,-1,2,2,3,3,0xa,686,
    { 0xf4fdfffb, 0xfcfcf4d0, 0xfcfc7c00, 0x7effff00, 0xf4fcfc00, 0xfffdf400, 0xffff7e1f, 0x7cfcfcbc},
    { 0xa0189602, 0x88586080, 0x58902800, 0x24948800, 0x60588800, 0x9618a000, 0x8894240a, 0x28905800}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat346,6,8, "A1338",-2,0,2,2,4,2,0xa,758,
    { 0x00fffff7, 0xf0f0f0f0, 0xffff0000, 0x3d3f3f3e, 0xf0f0f0f0, 0xffff0000, 0x3f3f3d3f, 0x00ffff7e},
    { 0x00608962, 0x90208040, 0x89250000, 0x08221914, 0x80209050, 0x89600000, 0x19220806, 0x00258924}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat347,6,8, "A1339",-1,0,1,2,2,2,0xa,722,
    { 0x1d3f3d00, 0x00f4fc74, 0xf0f0d000, 0xfc7c0000, 0xfcf40000, 0x3d3f1d00, 0x007cfc74, 0xd0f0f000},
    { 0x08220000, 0x00200820, 0x00208000, 0x80200000, 0x08200000, 0x00220800, 0x00208020, 0x80200000}
   , 0x10,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat348,5,8, "A1340",-1,-1,1,2,2,3,0xa,685,
    { 0xfcfcfc00, 0xfcfcfc00, 0xfffdfc00, 0xfcfcfc1c, 0xfcfcfcd0, 0xfcfcfc00, 0xfcfcfc00, 0xfcfdff00},
    { 0x88900000, 0x28100800, 0x02188800, 0x8010a008, 0x08102880, 0x00908800, 0xa0108000, 0x88180200}
   , 0x10,40.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat349,5,8, "A1341",-2,0,2,2,4,2,0x6,759,
    { 0x3f3f3f3f, 0x00fcfffc, 0xf0f0f0c0, 0xffff0000, 0xfffc0000, 0x3f3f3f0c, 0x00ffffff, 0xf0f0f0f0},
    { 0x22202000, 0x00a80208, 0x20202080, 0x00a80000, 0x02a80000, 0x20202208, 0x00a80080, 0x20202000}
   , 0x10,40.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat350,5,8, "A1342",-2,-2,2,0,4,2,0x8,686,
    { 0x00fcffff, 0xf0f0f0c0, 0xffff0000, 0x3f3f3f3f, 0xf0f0f0f0, 0xfffc0000, 0x3f3f3f0f, 0x00ffffff},
    { 0x00a80900, 0x2020a040, 0x82a90000, 0x28202018, 0xa0202090, 0x09a80000, 0x20202804, 0x00a98200}
   , 0x10,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat351,6,8, "A1343",-1,-2,1,1,2,3,0xa,722,
    { 0x15ff7f00, 0x70f4f4f4, 0xf4fc5000, 0x7c7c3400, 0xf4f47000, 0x7fff1500, 0x347c7c7c, 0x50fcf400},
    { 0x00a00000, 0x20200000, 0x00280000, 0x00202000, 0x00202000, 0x00a00000, 0x20200000, 0x00280000}
   , 0x10,46.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat352,4,8, "A1344",0,-1,1,2,1,3,0x2,722,
    { 0x00fcff00, 0xf0f0f0c0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfffc0000, 0x3c3c3c0c, 0x00fcfc00},
    { 0x00a88100, 0xa0202040, 0x08a80000, 0x20202800, 0x2020a000, 0x81a80000, 0x28202004, 0x00a80800}
   , 0x10,46.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat353,2,8, "A1345",-1,-2,1,1,2,3,0xa,685,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfcfc},
    { 0x54208000, 0x84240400, 0x08205400, 0x40604800, 0x04248400, 0x80205400, 0x48604000, 0x54200800}
   , 0x10,46.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat354,6,8, "A1346",-1,-1,1,2,2,3,0x6,720,
    { 0xfc3c3400, 0x0dfd7f00, 0x70f0fcd4, 0xf4fcc000, 0x7ffd0d00, 0x343cfc5c, 0xc0fcf400, 0xfcf07000},
    { 0x80202000, 0x08a00000, 0x20200800, 0x00288000, 0x00a00800, 0x20208000, 0x80280000, 0x08202000}
   , 0x10,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat355,5,8, "A1347",-1,-2,2,0,3,2,0xa,759,
    { 0x053f3f0f, 0x00f0f4f4, 0xf0f04000, 0x7f3c0000, 0xf4f00000, 0x3f3f0500, 0x003c7f7f, 0x40f0f0c0},
    { 0x00202009, 0x00a00000, 0x20200000, 0x02280000, 0x00a00000, 0x20200000, 0x00280201, 0x00202080}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat356,8,8, "A1348",-2,-1,1,1,3,2,0xa,685,
    { 0xdcfcfc00, 0xfcf7fd00, 0xfcfcdc70, 0xfc7cfc00, 0xfdf7fc00, 0xfcfcdc34, 0xfc7cfc00, 0xdcfcfc00},
    { 0x84a48800, 0xa8229400, 0x88684820, 0x5820a800, 0x9422a800, 0x88a48420, 0xa8205800, 0x48688800}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_attackpat356,3,0.376000},
  {owl_attackpat357,6,8, "A1349a",-2,0,3,2,5,2,0xa,686,
    { 0x3f3f3f3f, 0x00fffffc, 0xf0f0f0f0, 0xffff0000, 0xffff0000, 0x3f3f3f3c, 0x00ffffff, 0xf0f0f0f0},
    { 0x09220202, 0x002009a4, 0x00208040, 0x80200000, 0x09200000, 0x02220904, 0x0020806a, 0x80200000}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_attackpat357,3,1.000000},
  {owl_attackpat358,7,8, "A1349b",-3,0,3,2,6,2,0xa,686,
    { 0x3f3f3f3f, 0x00ffffff, 0xf0f0f0f0, 0xffff0000, 0xffff0000, 0x3f3f3f3f, 0x00ffffff, 0xf0f0f0f0},
    { 0x09220202, 0x00210aa5, 0x00208090, 0x80200000, 0x0a210000, 0x02220919, 0x0020806a, 0x80200000}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_attackpat358,3,1.000000},
  {owl_attackpat359,7,8, "A1350",-1,-2,2,1,3,3,0xa,723,
    { 0x3f3fffff, 0xc0fcfcfc, 0xfcf0f000, 0xffff0f00, 0xfcfcc000, 0xff3f3f00, 0x0fffffff, 0xf0f0fcfc},
    { 0x2a21a240, 0x80a80898, 0x2820a000, 0x80a80900, 0x08a88000, 0xa2212a00, 0x09a88098, 0xa0202804}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_attackpat359,3,0.010000},
  {owl_attackpat360,6,8, "A1351",-2,-1,2,2,4,3,0xa,722,
    { 0xfcfcfcfc, 0xfcffff00, 0xfcfffcf0, 0xffffff30, 0xfffffc30, 0xfcfcfc3c, 0xffffff00, 0xfcfffcfc},
    { 0x98208080, 0x88250900, 0x08229850, 0x80608a20, 0x09258820, 0x80209814, 0x8a608000, 0x98220808}
   , 0x10,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat361,1,4, "A1401",0,0,3,3,3,3,0x6,722,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,46.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat362,1,8, "A1403",0,-2,3,1,3,3,0x6,722,
    { 0x00fffffe, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3e, 0x00fcfcfc},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x0,55.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat363,1,8, "A1501",-1,0,0,1,1,1,0x0,685,
    { 0x00303c00, 0x00f0c000, 0xf0300000, 0x0c3c0000, 0xc0f00000, 0x3c300000, 0x003c0c00, 0x0030f000},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_attackpat363,3,0.058000},
  {owl_attackpat364,1,4, "A1502",0,0,0,2,0,2,0x0,685,
    { 0x00303030, 0x00f00000, 0x30300000, 0x003f0000, 0x00f00000, 0x30300000, 0x003f0000, 0x00303030},
    { 0x00200010, 0x00200000, 0x00200000, 0x00210000, 0x00200000, 0x00200000, 0x00210000, 0x00200010}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_attackpat364,3,0.058000},
  {owl_attackpat365,4,8, "A1503",-2,-1,1,1,3,2,0x0,685,
    { 0x30fcfcf0, 0xf0fcf000, 0xfcfc3000, 0x3cff3f00, 0xf0fcf000, 0xfcfc3000, 0x3fff3c00, 0x30fcfc3c},
    { 0x10648860, 0x90249000, 0x88641000, 0x18621900, 0x90249000, 0x88641000, 0x19621800, 0x10648824}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_attackpat365,3,0.016000},
  {owl_attackpat366,4,8, "A1503a",-2,-1,1,1,3,2,0x0,685,
    { 0x30fcfcf0, 0xf0fcf000, 0xfcfc3000, 0x3cff3f00, 0xf0fcf000, 0xfcfc3000, 0x3fff3c00, 0x30fcfc3c},
    { 0x10648860, 0x90249000, 0x88641000, 0x18621900, 0x90249000, 0x88641000, 0x19621800, 0x10648824}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_attackpat366,3,0.016000},
  {owl_attackpat367,6,8, "A1504",-1,-2,1,2,2,4,0x2,719,
    { 0xfcfcfcfc, 0xffffff00, 0xfcfcfcfc, 0xffffff00, 0xffffff00, 0xfcfcfcfc, 0xffffff00, 0xfcfcfcfc},
    { 0x90a08860, 0xa9248000, 0x88281804, 0x0862a900, 0x8024a900, 0x88a09040, 0xa9620800, 0x18288824}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_attackpat367,3,1.600000},
  {owl_attackpat368,4,8, "A1601",-1,0,1,2,2,2,0x2,722,
    { 0x003c7c7c, 0x40f0f000, 0xf4f00000, 0x3f3f0500, 0xf0f04000, 0x7c3c0000, 0x053f3f00, 0x00f0f4f4},
    { 0x00200008, 0x00200000, 0x00200000, 0x02200000, 0x00200000, 0x00200000, 0x00200200, 0x00200080}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_attackpat368,3,1.960000},
  {owl_attackpat369,3,8, "A1602",-1,-2,1,1,2,3,0x2,686,
    { 0x30fcfcfc, 0xf0fcf000, 0xfcfc3000, 0x3fff3f00, 0xf0fcf000, 0xfcfc3000, 0x3fff3f00, 0x30fcfcfc},
    { 0x10608800, 0x90248000, 0x88241000, 0x08601800, 0x80249000, 0x88601000, 0x18600800, 0x10248800}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat369,3,1.000000},
  {owl_attackpat370,3,8, "A1603",-1,-2,1,1,2,3,0x2,758,
    { 0x3fff3f00, 0x30fcfcfc, 0xf0fcf000, 0xfcfc3000, 0xfcfc3000, 0x3fff3f00, 0x30fcfcfc, 0xf0fcf000},
    { 0x18602000, 0x10a40800, 0x20249000, 0x80681000, 0x08a41000, 0x20601800, 0x10688000, 0x90242000}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat370,3,1.000000},
  {owl_attackpat371,4,8, "A1604",0,-2,2,2,2,4,0x2,648,
    { 0x00fcfffc, 0xf0f0f0c0, 0xfffc0000, 0x3f3f3f0f, 0xf0f0f0c0, 0xfffc0000, 0x3f3f3f0c, 0x00fcffff},
    { 0x00a40920, 0x20209040, 0x81680000, 0x18222004, 0x90202040, 0x09a40000, 0x20221804, 0x00688120}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat371,3,1.000000},
  {owl_attackpat372,4,8, "A1605",0,-2,2,2,2,4,0x2,648,
    { 0x00fcfffc, 0xf0f0f0c0, 0xfffc0000, 0x3f3f3f0f, 0xf0f0f0c0, 0xfffc0000, 0x3f3f3f0c, 0x00fcffff},
    { 0x00a40908, 0x20209040, 0x81680000, 0x1a202004, 0x90202040, 0x09a40000, 0x20201a04, 0x00688180}
   , 0x10,55.000000,attributes+0,1,NULL,autohelperowl_attackpat372,3,1.000000},
  {owl_attackpat373,4,8, "A1606",-1,-2,1,1,2,3,0x2,686,
    { 0x30fcfcfc, 0xf0fcf000, 0xfcfc3000, 0x3fff3f00, 0xf0fcf000, 0xfcfc3000, 0x3fff3f00, 0x30fcfcfc},
    { 0x10608880, 0x90248000, 0x88241000, 0x08601a00, 0x80249000, 0x88601000, 0x1a600800, 0x10248808}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_attackpat373,3,1.000000},
  {owl_attackpat374,4,8, "A1607",-1,-2,1,1,2,3,0x2,758,
    { 0x3fff3f00, 0x30fcfcfc, 0xf0fcf000, 0xfcfc3000, 0xfcfc3000, 0x3fff3f00, 0x30fcfcfc, 0xf0fcf000},
    { 0x1a602000, 0x10a40808, 0x20249000, 0x80681000, 0x08a41000, 0x20601a00, 0x10688080, 0x90242000}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_attackpat374,3,1.000000},
  {owl_attackpat375,4,8, "A1608",-1,-2,1,1,2,3,0x2,685,
    { 0x3cfcfcfc, 0xf0fcfc00, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xfcfc3c00, 0x3fffff00, 0xf0fcfcfc},
    { 0x14608880, 0x90248400, 0x88245000, 0x48601a00, 0x84249000, 0x88601400, 0x1a604800, 0x50248808}
   , 0x10,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat376,5,8, "A1608b",0,-2,2,2,2,4,0x2,723,
    { 0x00fcffff, 0xf0f0f0c0, 0xfffd0000, 0x3f3f3f1f, 0xf0f0f0d0, 0xfffc0000, 0x3f3f3f0f, 0x00fdffff},
    { 0x00a40921, 0x20209040, 0x80680000, 0x18222000, 0x90202000, 0x09a40000, 0x20221805, 0x00688020}
   , 0x10,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat377,4,8, "A1609",-1,-2,1,2,2,4,0x2,722,
    { 0xfcffff00, 0xfcfcfcf0, 0xfffffc00, 0xfcfcfc3c, 0xfcfcfcf0, 0xfffffc00, 0xfcfcfc3c, 0xfcffff00},
    { 0x58228000, 0x84240820, 0x09219400, 0x80604814, 0x08248450, 0x80225800, 0x48608020, 0x94210900}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_attackpat378,5,8, "A1610",0,-2,2,2,2,4,0x2,723,
    { 0x00fcffff, 0xf0f0f0c0, 0xffff0000, 0x3f3f3f3f, 0xf0f0f0f0, 0xfffc0000, 0x3f3f3f0f, 0x00ffffff},
    { 0x00a80180, 0x20202040, 0x02a90000, 0x20202218, 0x20202090, 0x01a80000, 0x22202004, 0x00a90208}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat378,3,0.970000},
  {owl_attackpat379,6,8, "A1611",0,-2,2,3,2,5,0x2,686,
    { 0x00fdffff, 0xf0f0f0d0, 0xffff0000, 0x3f3f3f3f, 0xf0f0f0f0, 0xfffd0000, 0x3f3f3f1f, 0x00ffffff},
    { 0x00a80200, 0x20202080, 0x02a90000, 0x20202018, 0x20202090, 0x02a80000, 0x20202008, 0x00a90200}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_attackpat379,3,1.600000},
  {owl_attackpat380,4,8, "A1612",-1,-1,1,3,2,4,0x2,683,
    { 0x3c3f3f00, 0x00fcfcf0, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3f3f3c00, 0x00fcfc3c, 0xf0f0f000},
    { 0x08220800, 0x00208820, 0x80208000, 0x88200000, 0x88200000, 0x08220800, 0x00208820, 0x80208000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_attackpat380,3,0.610000},
  {owl_attackpat381,6,8, "A1613",-1,-1,1,2,2,3,0x2,722,
    { 0x3cfdff00, 0xf0fcfcd0, 0xfcfcf000, 0xfcfc3c00, 0xfcfcf000, 0xfffd3c00, 0x3cfcfc1c, 0xf0fcfc00},
    { 0x28906200, 0x60980880, 0x2418a000, 0x80982400, 0x08986000, 0x62902800, 0x24988008, 0xa0182400}
   , 0x10,75.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_attackpat382,5,8, "AC01",0,-1,2,1,2,2,0x2,649,
    { 0x007c7cfc, 0x50f0f000, 0xf4f40000, 0x3f3f1700, 0xf0f05000, 0x7c7c0000, 0x173f3f00, 0x00f4f4fc},
    { 0x00240808, 0x00209000, 0x80600000, 0x1a200000, 0x90200000, 0x08240000, 0x00201a00, 0x00608080}
   , 0x110,25.000000,attributes+1,1,NULL,autohelperowl_attackpat382,3,0.034000},
  {owl_attackpat383,6,8, "AE01",-2,-1,1,1,3,2,0xa,721,
    { 0xdcfcfc00, 0xfcf4fc00, 0xffffdd00, 0xfc7cfc7c, 0xfcf4fcf4, 0xfcfcdc00, 0xfc7cfc00, 0xddffff00},
    { 0x80208000, 0x88200000, 0x09220800, 0x00208824, 0x00208860, 0x80208000, 0x88200000, 0x08220900}
   , 0x110,20.000000,attributes+3,1,NULL,autohelperowl_attackpat383,3,0.610000},
  {NULL, 0,0,NULL,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},0,0.0,NULL,0,NULL,NULL,0,0.0}
};

#include "dfa-mkpat.h"
static const state_rt_t state_owl_attackpat[8017] = {
{0,{0,0,0,0}},	{0,{0,1,2,0}},	{0,{2,3,4,0}},
{0,{4,5,6,0}},	{0,{6,7,8,0}},	{0,{8,9,10,0}},
{0,{10,11,12,0}},	{0,{12,13,14,15}},	{0,{15,16,17,0}},
{0,{17,18,0,0}},	{0,{18,19,20,21}},	{0,{21,21,22,22}},
{0,{22,23,24,25}},	{0,{25,25,26,0}},	{0,{25,25,25,0}},
{0,{24,24,25,0}},	{0,{25,26,27,28}},	{0,{28,28,29,30}},
{0,{30,31,29,29}},	{0,{31,32,33,34}},	{0,{34,35,34,36}},
{0,{36,36,37,38}},	{0,{38,38,38,38}},	{0,{38,39,40,41}},
{0,{41,42,43,44}},	{0,{44,45,46,47}},	{0,{47,48,49,0}},
{0,{49,0,0,0}},	{0,{49,50,51,52}},	{0,{52,49,53,54}},
{0,{54,55,56,57}},	{0,{57,54,58,56}},	{0,{58,59,60,0}},
{0,{60,58,59,0}},	{0,{60,61,62,63}},	{0,{63,64,61,62}},
{0,{64,65,60,61}},	{0,{65,66,59,60}},	{0,{66,67,67,67}},
{0,{67,0,0,0}},	{0,{67,0,0,0}},	{0,{67,68,69,64}},
{0,{69,67,70,63}},	{0,{70,71,72,0}},	{0,{72,73,74,0}},
{0,{74,72,75,0}},	{0,{73,71,71,0}},	{0,{70,70,70,0}},
{0,{73,74,69,0}},	{0,{74,74,75,0}},	{0,{75,76,77,78}},
{0,{78,79,80,81}},	{0,{81,82,83,84}},	{0,{84,85,86,79}},
{0,{86,87,88,89}},	{0,{89,90,91,88}},	{0,{91,92,93,87}},
{0,{93,94,95,96}},	{0,{96,97,94,95}},	{0,{95,92,93,94}},
{0,{96,96,96,96}},	{0,{96,97,98,99}},	{0,{99,100,100,101}},
{0,{101,102,99,100}},	{0,{102,103,103,103}},	{0,{103,104,104,0}},
{0,{104,103,103,0}},	{0,{104,105,106,0}},	{0,{106,107,107,0}},
{0,{107,108,0,0}},	{0,{108,109,0,0}},	{0,{109,106,0,0}},
{0,{109,110,0,0}},	{0,{110,111,110,112}},	{0,{112,113,112,114}},
{0,{114,115,114,116}},	{0,{116,117,0,0}},	{0,{117,118,119,120}},
{0,{120,121,122,119}},	{0,{122,123,124,125}},	{0,{125,0,126,0}},
{0,{113,118,115,116}},	{0,{119,125,121,126}},	{0,{126,0,123,0}},
{0,{126,115,127,128}},	{0,{113,114,128,112}},	{0,{128,121,129,122}},
{0,{122,0,129,0}},	{0,{122,111,123,109}},	{0,{112,118,128,119}},
{0,{128,129,130,129}},	{0,{130,128,131,128}},	{0,{131,132,133,134}},
{0,{134,126,127,126}},	{0,{134,135,136,137}},	{0,{137,134,138,136}},
{0,{138,139,140,141}},	{0,{141,0,0,0}},	{0,{141,131,132,142}},
{0,{133,130,142,141}},	{0,{142,129,130,131}},	{0,{142,128,140,130}},
{0,{142,127,128,138}},	{0,{142,126,138,137}},	{0,{0,0,142,0}},
{0,{0,0,142,0}},	{0,{0,0,142,0}},	{0,{142,0,141,0}},
{0,{142,142,143,144}},	{0,{144,145,146,145}},	{0,{146,144,145,147}},
{0,{143,143,147,148}},	{0,{142,142,143,148}},	{0,{148,148,149,150}},
{0,{139,140,140,140}},	{0,{149,149,150,151}},	{0,{138,138,138,143}},
{0,{137,137,137,137}},	{0,{136,136,136,139}},	{0,{135,135,148,135}},
{0,{148,134,134,134}},	{0,{148,148,148,149}},	{0,{149,150,150,150}},
{0,{150,131,131,131}},	{0,{150,130,150,130}},	{0,{150,151,152,153}},
{0,{153,154,155,156}},	{0,{156,157,158,159}},	{0,{159,160,161,162}},
{0,{162,163,164,165}},	{0,{165,166,167,168}},	{0,{168,161,169,170}},
{0,{170,171,172,173}},	{0,{173,159,174,175}},	{0,{145,162,175,176}},
{0,{176,157,177,178}},	{0,{166,167,178,154}},	{0,{178,179,180,181}},
{0,{181,182,183,184}},	{0,{184,177,185,186}},	{0,{186,187,188,189}},
{308,{189,190,191,192}},	{0,{192,193,194,195}},	{0,{195,196,195,197}},
{0,{197,183,184,185}},	{308,{197,186,198,188}},	{0,{198,199,190,200}},
{0,{200,180,201,182}},	{308,{201,183,202,185}},	{0,{202,186,203,197}},
{0,{203,204,205,206}},	{0,{206,207,208,209}},	{0,{209,202,210,211}},
{0,{211,212,213,213}},	{0,{199,200,213,202}},	{0,{213,203,204,205}},
{0,{0,213,0,0}},	{0,{213,214,213,215}},	{0,{215,216,215,217}},
{0,{217,218,217,219}},	{0,{217,217,217,218}},	{0,{218,219,218,220}},
{0,{220,221,220,222}},	{0,{220,220,220,221}},	{0,{221,222,221,223}},
{0,{217,218,217,223}},	{0,{223,223,223,224}},	{0,{0,0,0,224}},
{0,{224,225,226,227}},	{0,{223,224,227,228}},	{0,{222,223,228,225}},
{0,{221,222,225,228}},	{0,{228,221,229,230}},	{0,{219,230,223,229}},
{0,{223,223,223,221}},	{0,{222,222,222,222}},	{0,{228,213,213,229}},
{0,{229,0,0,230}},	{0,{226,211,211,230}},	{0,{230,0,0,228}},
{0,{230,231,209,232}},	{0,{208,208,208,232}},	{0,{0,0,0,225}},
{0,{231,232,231,233}},	{0,{230,233,230,234}},	{0,{234,235,234,0}},
{0,{235,236,237,0}},	{0,{234,233,236,237}},	{0,{232,232,235,0}},
{0,{236,233,230,237}},	{0,{235,230,229,237}},	{0,{237,229,228,235}},
{0,{237,237,237,237}},	{0,{237,237,237,238}},	{0,{238,0,239,0}},
{0,{239,0,240,0}},	{0,{240,0,241,0}},	{0,{241,0,242,0}},
{0,{242,0,243,0}},	{0,{243,0,240,0}},	{0,{236,0,239,0}},
{0,{242,243,244,243}},	{0,{244,242,245,242}},	{0,{245,241,244,241}},
{0,{245,0,246,0}},	{0,{246,0,0,0}},	{0,{246,0,0,0}},
{0,{246,237,240,237}},	{0,{246,0,242,0}},	{0,{246,0,0,0}},
{0,{222,0,246,0}},	{0,{246,0,226,0}},	{0,{246,0,227,0}},
{0,{244,0,226,0}},	{0,{245,230,231,230}},	{0,{245,229,232,229}},
{0,{245,0,0,0}},	{0,{245,227,230,227}},	{0,{245,0,215,0}},
{0,{0,0,220,0}},	{0,{244,0,217,0}},	{0,{244,0,220,0}},
{0,{242,0,217,0}},	{0,{243,221,222,221}},	{0,{220,220,223,220}},
{0,{242,219,222,219}},	{0,{0,0,224,0}},	{0,{236,0,229,0}},
{0,{240,0,205,0}},	{0,{240,0,210,0}},	{0,{240,0,207,0}},
{0,{240,0,208,0}},	{0,{240,0,209,0}},	{0,{240,0,206,0}},
{0,{240,210,211,210}},	{0,{240,209,212,209}},	{0,{240,208,211,208}},
{0,{240,241,242,0}},	{0,{242,0,0,0}},	{0,{242,0,194,0}},
{0,{242,0,199,0}},	{0,{229,0,198,0}},	{0,{239,0,214,0}},
{0,{229,0,240,0}},	{0,{240,0,212,0}},	{0,{240,0,196,0}},
{0,{240,0,241,0}},	{0,{239,0,0,0}},	{0,{0,0,239,0}},
{0,{0,239,240,0}},	{0,{0,240,241,0}},	{0,{235,241,240,0}},
{0,{241,238,239,0}},	{0,{241,237,0,0}},	{0,{0,236,0,0}},
{0,{231,235,0,0}},	{0,{239,240,0,0}},	{0,{240,233,0,0}},
{0,{228,234,0,0}},	{0,{234,231,0,0}},	{0,{238,230,0,0}},
{0,{0,229,238,0}},	{0,{0,230,237,0}},	{0,{237,227,236,0}},
{0,{0,237,238,0}},	{0,{0,225,237,0}},	{0,{237,238,236,0}},
{0,{0,225,0,0}},	{0,{237,222,0,0}},	{0,{237,238,237,0}},
{0,{238,237,236,0}},	{0,{238,219,0,0}},	{0,{238,218,0,0}},
{0,{238,217,0,0}},	{0,{0,238,0,0}},	{0,{238,239,240,0}},
{199,{240,241,0,0}},	{0,{241,242,243,0}},	{0,{243,244,245,0}},
{0,{245,246,247,0}},	{199,{236,245,0,0}},	{0,{246,247,248,0}},
{0,{248,243,241,0}},	{0,{248,249,250,0}},	{199,{232,250,0,0}},
{0,{250,251,252,0}},	{0,{252,248,237,0}},	{0,{252,253,0,0}},
{199,{253,252,0,0}},	{0,{253,251,0,0}},	{0,{253,250,0,0}},
{0,{253,254,224,0}},	{199,{254,242,0,0}},	{0,{254,255,256,0}},
{0,{256,257,0,0}},	{0,{257,230,258,0}},	{199,{250,229,0,0}},
{0,{257,231,232,0}},	{0,{257,227,258,0}},	{0,{258,233,234,0}},
{0,{247,236,258,0}},	{0,{258,233,0,0}},	{0,{258,238,0,0}},
{199,{258,237,0,0}},	{0,{258,236,0,0}},	{0,{258,235,0,0}},
{0,{258,239,209,0}},	{0,{258,241,213,0}},	{0,{258,243,0,0}},
{0,{258,219,220,0}},	{0,{258,215,0,0}},	{0,{258,221,222,0}},
{0,{253,224,225,0}},	{0,{257,221,0,0}},	{0,{257,226,0,0}},
{0,{257,230,200,0}},	{199,{245,218,0,0}},	{0,{256,231,203,0}},
{0,{256,233,0,0}},	{0,{256,206,207,0}},	{199,{241,205,0,0}},
{0,{255,207,256,0}},	{0,{256,203,0,0}},	{0,{256,209,210,0}},
{0,{249,212,213,0}},	{0,{255,209,0,0}},	{0,{255,256,257,0}},
{199,{257,207,258,0}},	{0,{258,259,260,0}},	{0,{260,261,256,0}},
{0,{261,195,262,0}},	{199,{253,194,262,0}},	{0,{254,196,262,0}},
{0,{0,192,260,0}},	{0,{261,198,262,0}},	{199,{249,199,258,0}},
{0,{261,262,263,0}},	{0,{0,197,263,0}},	{0,{224,202,255,0}},
{199,{245,201,254,0}},	{0,{0,200,253,0}},	{0,{260,241,242,0}},
{0,{260,183,250,0}},	{0,{243,185,260,0}},	{0,{260,188,252,0}},
{199,{260,189,248,0}},	{0,{0,188,247,0}},	{0,{259,235,236,0}},
{0,{259,239,240,0}},	{0,{259,176,243,0}},	{0,{257,178,244,0}},
{0,{257,181,245,0}},	{0,{224,246,247,0}},	{0,{256,179,257,0}},
{199,{257,180,0,0}},	{0,{257,193,258,0}},	{0,{258,195,0,0}},
{0,{258,168,259,0}},	{199,{253,167,0,0}},	{0,{258,169,259,0}},
{0,{259,165,0,0}},	{0,{259,171,260,0}},	{0,{260,174,261,0}},
{0,{261,171,0,0}},	{0,{261,176,0,0}},	{199,{0,175,0,0}},
{0,{0,174,0,0}},	{0,{259,181,246,0}},	{0,{247,157,259,0}},
{199,{0,0,0,0}},	{0,{258,259,260,0}},	{0,{260,258,259,0}},
{0,{260,261,262,0}},	{0,{262,263,264,0}},	{0,{264,262,263,0}},
{0,{263,261,264,0}},	{0,{259,260,0,0}},	{0,{261,259,0,0}},
{0,{260,258,262,0}},	{0,{262,0,251,0}},	{0,{262,0,250,0}},
{0,{261,262,253,0}},	{0,{259,0,0,0}},	{0,{259,0,0,0}},
{0,{258,0,256,0}},	{0,{259,0,245,0}},	{0,{259,0,244,0}},
{0,{259,260,247,0}},	{0,{260,0,261,0}},	{0,{0,0,241,0}},
{0,{0,253,244,0}},	{0,{0,0,249,0}},	{0,{258,0,259,0}},
{0,{259,0,258,0}},	{0,{259,0,260,0}},	{0,{260,261,262,0}},
{0,{257,0,255,0}},	{0,{0,0,254,0}},	{0,{255,0,260,0}},
{0,{260,257,258,0}},	{0,{260,0,261,0}},	{0,{252,0,260,0}},
{0,{260,0,249,0}},	{0,{249,0,260,0}},	{0,{260,0,261,0}},
{0,{261,262,263,0}},	{0,{0,0,263,0}},	{0,{263,0,0,0}},
{0,{263,259,222,0}},	{0,{0,0,263,0}},	{0,{254,0,263,0}},
{0,{0,0,263,0}},	{0,{254,255,218,0}},	{0,{0,254,217,0}},
{0,{261,0,262,0}},	{0,{262,263,261,0}},	{0,{263,0,260,0}},
{0,{260,0,259,0}},	{0,{261,262,258,0}},	{0,{262,0,0,0}},
{0,{262,0,0,0}},	{0,{262,0,0,0}},	{0,{260,256,0,0}},
{0,{261,0,0,0}},	{0,{261,0,0,0}},	{0,{261,0,0,0}},
{0,{261,0,0,0}},	{0,{260,261,0,0}},	{0,{261,0,0,0}},
{0,{261,261,261,262}},	{0,{262,262,262,0}},	{0,{262,261,261,0}},
{0,{262,263,264,265}},	{0,{265,0,266,0}},	{0,{266,0,267,0}},
{0,{267,0,264,0}},	{0,{267,267,268,267}},	{0,{268,0,262,0}},
{0,{0,0,268,0}},	{0,{0,0,260,0}},	{0,{267,255,268,257}},
{0,{268,0,258,0}},	{0,{0,0,259,0}},	{0,{264,267,253,254}},
{0,{0,267,0,0}},	{0,{264,267,254,0}},	{0,{267,268,255,0}},
{0,{0,265,252,0}},	{0,{255,267,256,255}},	{0,{267,268,269,0}},
{0,{0,269,249,0}},	{0,{246,246,246,269}},	{0,{251,251,251,251}},
{0,{0,261,248,0}},	{0,{267,263,264,0}},	{0,{242,242,242,242}},
{0,{266,0,243,0}},	{0,{266,266,267,266}},	{0,{267,0,248,0}},
{0,{267,268,237,238}},	{0,{263,268,269,263}},	{0,{262,262,262,262}},
{0,{261,266,262,261}},	{0,{267,268,269,0}},	{0,{0,0,269,0}},
{0,{269,266,267,0}},	{0,{268,269,266,0}},	{0,{0,244,266,0}},
{69,{268,269,270,269}},	{69,{0,0,270,0}},	{69,{270,0,271,0}},
{0,{271,0,272,0}},	{69,{272,265,266,265}},	{69,{272,0,268,0}},
{69,{272,273,264,263}},	{69,{0,236,264,0}},	{69,{264,235,265,0}},
{0,{271,0,272,0}},	{0,{272,273,0,0}},	{0,{273,240,274,0}},
{0,{257,257,257,257}},	{69,{273,256,257,256}},	{0,{273,0,261,0}},
{0,{273,0,216,0}},	{69,{273,253,254,253}},	{69,{273,252,253,252}},
{0,{273,273,273,273}},	{0,{273,0,0,0}},	{0,{0,0,273,0}},
{0,{0,273,0,0}},	{0,{273,0,0,0}},	{0,{273,274,0,0}},
{0,{274,0,0,0}},	{0,{274,0,0,0}},	{0,{0,0,274,0}},
{0,{274,0,275,0}},	{0,{275,0,276,0}},	{0,{270,276,0,0}},
{0,{276,275,0,0}},	{0,{276,0,0,0}},	{0,{276,0,0,0}},
{0,{276,0,0,0}},	{0,{0,0,276,0}},	{0,{264,276,0,0}},
{0,{276,0,0,0}},	{0,{0,0,276,0}},	{0,{276,0,0,0}},
{0,{276,0,0,0}},	{0,{276,0,0,0}},	{0,{276,276,277,0}},
{0,{275,275,275,0}},	{0,{276,0,0,0}},	{0,{276,0,277,0}},
{0,{277,278,279,280}},	{187,{280,281,282,0}},	{0,{282,0,283,0}},
{0,{283,283,284,285}},	{187,{285,278,279,0}},	{0,{285,286,287,286}},
{187,{287,288,289,0}},	{0,{289,290,291,0}},	{0,{291,292,293,292}},
{187,{293,273,274,0}},	{0,{293,293,293,0}},	{0,{293,294,295,269}},
{187,{0,270,295,0}},	{0,{295,0,272,0}},	{0,{295,296,297,277}},
{187,{297,279,298,0}},	{0,{298,281,282,0}},	{0,{298,299,300,283}},
{0,{300,260,261,262}},	{187,{300,263,0,0}},	{0,{265,0,265,0}},
{187,{0,261,0,0}},	{0,{298,269,270,269}},	{187,{298,271,299,0}},
{0,{299,273,274,0}},	{0,{299,275,300,275}},	{0,{254,254,254,300}},
{187,{0,0,0,0}},	{0,{260,260,260,260}},	{0,{262,262,262,262}},
{0,{270,270,270,297}},	{0,{297,298,299,249}},	{187,{249,250,0,0}},
{0,{298,298,299,300}},	{0,{300,301,302,301}},	{187,{258,259,287,0}},
{0,{260,261,301,0}},	{0,{301,263,302,263}},	{187,{264,244,0,0}},
{0,{265,301,302,241}},	{0,{268,0,302,0}},	{0,{302,294,295,294}},
{0,{302,303,275,258}},	{0,{303,0,0,0}},	{0,{303,285,235,236}},
{0,{278,252,303,0}},	{0,{303,304,305,254}},	{0,{233,233,233,233}},
{0,{285,285,285,285}},	{0,{286,286,286,286}},	{0,{250,250,250,250}},
{0,{301,227,228,229}},	{0,{301,302,303,302}},	{0,{303,247,248,247}},
{0,{303,300,301,300}},	{0,{303,290,304,245}},	{0,{304,222,223,224}},
{0,{304,243,268,243}},	{0,{296,296,296,296}},	{0,{303,304,305,221}},
{0,{274,275,275,275}},	{0,{304,239,305,239}},	{0,{305,306,307,218}},
{0,{280,272,272,272}},	{0,{250,233,306,0}},	{0,{306,280,294,235}},
{0,{306,297,298,214}},	{0,{306,233,299,233}},	{0,{306,307,308,267}},
{187,{308,213,0,0}},	{299,{308,309,310,0}},	{0,{310,310,310,310}},
{299,{0,0,310,0}},	{0,{310,311,312,262}},	{187,{312,220,248,0}},
{299,{312,0,307,0}},	{0,{312,313,0,0}},	{187,{0,313,0,0}},
{0,{313,297,298,257}},	{299,{300,300,300,0}},	{299,{0,0,0,0}},
{299,{306,0,0,0}},	{0,{310,293,294,253}},	{299,{310,296,311,0}},
{0,{259,251,301,251}},	{187,{227,209,237,0}},	{299,{309,0,0,0}},
{299,{0,0,309,0}},	{0,{309,310,288,247}},	{0,{246,309,287,246}},
{299,{297,0,309,0}},	{0,{301,307,285,244}},	{0,{308,289,289,289}},
{0,{304,305,308,242}},	{0,{289,290,241,241}},	{0,{240,303,306,240}},
{0,{306,307,308,309}},	{0,{309,0,310,0}},	{0,{0,0,310,0}},
{0,{310,0,311,0}},	{0,{311,0,0,0}},	{0,{311,312,0,0}},
{0,{312,301,313,303}},	{0,{313,0,304,0}},	{0,{313,314,306,0}},
{0,{314,0,0,0}},	{0,{314,315,0,0}},	{0,{315,316,297,298}},
{0,{316,0,299,0}},	{0,{316,0,301,0}},	{0,{316,0,0,0}},
{0,{316,302,317,0}},	{0,{293,293,293,293}},	{0,{316,0,297,0}},
{0,{316,0,293,0}},	{0,{316,317,318,319}},	{0,{319,319,320,319}},
{0,{320,0,0,0}},	{0,{313,314,316,316}},	{0,{319,320,315,315}},
{0,{320,315,315,315}},	{370,{316,0,0,0}},	{0,{312,312,311,312}},
{0,{312,312,312,312}},	{0,{317,317,0,0}},	{0,{309,309,309,309}},
{370,{315,315,0,0}},	{370,{0,0,0,0}},	{0,{314,314,315,314}},
{0,{313,313,313,313}},	{0,{314,0,0,0}},	{0,{314,311,312,311}},
{0,{313,310,310,310}},	{0,{313,309,309,309}},	{0,{313,0,0,0}},
{0,{313,307,307,307}},	{370,{0,313,0,0}},	{0,{313,0,314,0}},
{0,{314,0,0,0}},	{0,{311,0,311,0}},	{0,{0,0,313,0}},
{0,{313,0,0,0}},	{0,{313,0,0,0}},	{0,{313,0,0,0}},
{0,{313,0,0,0}},	{0,{313,0,0,0}},	{0,{309,0,313,0}},
{0,{313,0,304,0}},	{0,{313,0,0,0}},	{0,{0,0,310,0}},
{0,{302,0,312,0}},	{0,{0,0,312,0}},	{0,{312,0,0,0}},
{0,{312,0,0,0}},	{0,{312,0,0,0}},	{0,{312,0,0,0}},
{0,{312,0,0,0}},	{0,{312,0,0,0}},	{0,{312,0,0,0}},
{0,{312,0,0,0}},	{0,{304,0,312,0}},	{0,{276,0,311,0}},
{0,{311,311,311,312}},	{0,{312,312,312,0}},	{0,{312,312,312,313}},
{0,{0,313,0,0}},	{0,{313,313,313,0}},	{0,{313,313,0,0}},
{0,{306,306,306,306}},	{0,{308,308,308,308}},	{0,{311,307,311,307}},
{0,{311,311,311,311}},	{0,{311,312,312,0}},	{0,{312,312,313,312}},
{0,{313,313,313,313}},	{0,{313,313,313,0}},	{0,{309,309,309,309}},
{0,{312,0,0,0}},	{0,{312,0,0,0}},	{0,{312,312,312,0}},
{0,{312,311,311,0}},	{0,{312,312,313,314}},	{0,{314,314,315,0}},
{0,{315,315,316,317}},	{0,{0,0,317,0}},	{0,{317,317,317,318}},
{17,{0,0,0,0}},	{0,{0,317,318,0}},	{0,{318,318,318,319}},
{0,{0,319,0,0}},	{0,{319,0,320,0}},	{0,{320,321,322,0}},
{0,{322,322,322,322}},	{0,{0,0,322,0}},	{0,{299,299,322,301}},
{0,{322,323,324,325}},	{0,{325,325,325,0}},	{39,{325,325,326,0}},
{41,{0,0,0,0}},	{44,{0,0,0,0}},	{0,{0,0,305,0}},
{39,{323,323,323,0}},	{39,{323,322,324,0}},	{0,{324,325,326,327}},
{38,{320,320,327,0}},	{0,{323,323,327,0}},	{43,{0,0,0,0}},
{0,{0,0,326,0}},	{0,{326,320,321,0}},	{0,{326,326,326,327}},
{0,{0,0,300,0}},	{0,{326,301,302,0}},	{0,{0,0,326,0}},
{0,{280,280,303,326}},	{39,{308,308,309,326}},	{39,{309,309,311,0}},
{0,{321,296,297,325}},	{0,{325,325,325,326}},	{0,{278,278,278,0}},
{0,{325,325,325,0}},	{0,{292,292,292,0}},	{0,{324,324,324,0}},
{41,{274,274,274,0}},	{0,{323,324,325,326}},	{0,{0,0,0,326}},
{92,{326,326,326,327}},	{92,{0,0,0,327}},	{0,{324,324,324,324}},
{92,{323,323,323,326}},	{0,{326,327,326,0}},	{92,{0,0,285,323}},
{0,{326,326,327,318}},	{0,{319,319,319,327}},	{103,{324,324,325,327}},
{41,{0,0,0,316}},	{105,{0,0,0,0}},	{108,{0,0,279,317}},
{112,{0,0,0,0}},	{114,{0,0,0,0}},	{106,{0,0,0,0}},
{115,{0,0,0,0}},	{0,{306,306,320,308}},	{0,{313,313,313,0}},
{0,{319,319,278,0}},	{0,{303,303,317,316}},	{0,{312,312,313,315}},
{0,{263,0,0,0}},	{0,{316,316,316,316}},	{0,{316,0,316,0}},
{0,{0,0,0,316}},	{120,{0,0,0,0}},	{0,{315,315,0,0}},
{0,{315,0,0,0}},	{120,{315,315,315,315}},	{0,{315,0,0,0}},
{0,{315,315,315,0}},	{0,{315,316,316,317}},	{0,{317,0,0,0}},
{120,{317,317,317,317}},	{0,{317,316,316,316}},	{0,{0,0,0,317}},
{0,{317,0,0,0}},	{0,{317,317,317,317}},	{0,{306,0,317,318}},
{120,{318,0,318,0}},	{0,{0,0,0,318}},	{0,{318,0,318,319}},
{120,{0,0,0,319}},	{0,{319,0,0,0}},	{0,{319,319,319,319}},
{120,{319,319,319,319}},	{0,{317,319,317,317}},	{0,{0,0,0,319}},
{0,{0,0,319,318}},	{0,{319,319,319,319}},	{120,{319,0,0,0}},
{0,{318,0,0,0}},	{0,{318,319,320,321}},	{0,{321,322,323,324}},
{0,{324,325,326,327}},	{0,{327,328,328,328}},	{0,{328,328,328,329}},
{192,{0,0,0,0}},	{0,{328,328,328,0}},	{195,{328,328,329,329}},
{195,{329,329,329,329}},	{0,{329,330,330,330}},	{0,{330,329,331,329}},
{0,{329,328,328,328}},	{0,{330,330,330,330}},	{206,{330,330,330,330}},
{0,{330,330,330,330}},	{0,{330,329,331,329}},	{212,{331,331,331,332}},
{192,{332,332,332,332}},	{0,{332,332,332,331}},	{195,{332,332,332,332}},
{0,{332,332,332,332}},	{195,{0,0,0,0}},	{0,{331,332,333,334}},
{0,{0,0,0,334}},	{0,{334,335,336,337}},	{0,{0,0,337,0}},
{0,{0,0,337,0}},	{0,{337,338,304,339}},	{0,{294,339,296,297}},
{0,{339,302,340,300}},	{240,{0,0,0,0}},	{195,{339,339,339,339}},
{206,{339,339,339,339}},	{0,{339,339,339,339}},	{0,{339,337,340,337}},
{212,{314,314,314,314}},	{240,{313,313,313,313}},	{195,{338,338,338,338}},
{247,{338,0,339,340}},	{253,{340,0,338,339}},	{0,{340,0,337,341}},
{0,{341,342,343,288}},	{0,{343,343,343,343}},	{206,{343,343,343,343}},
{212,{305,305,305,343}},	{0,{304,304,304,304}},	{195,{342,342,342,342}},
{0,{342,0,343,344}},	{0,{344,311,312,309}},	{0,{281,282,344,282}},
{0,{0,0,344,307}},	{0,{344,345,346,347}},	{0,{270,271,272,279}},
{0,{346,274,275,347}},	{0,{347,285,285,285}},	{0,{284,284,286,284}},
{0,{283,283,283,283}},	{206,{345,345,345,345}},	{0,{345,345,345,345}},
{0,{345,344,346,344}},	{195,{346,0,0,0}},	{0,{346,0,294,295}},
{0,{346,297,347,295}},	{0,{259,304,261,268}},	{0,{304,267,305,346}},
{195,{272,272,272,346}},	{206,{337,337,337,337}},	{247,{345,345,346,347}},
{253,{0,0,309,310}},	{0,{346,0,346,0}},	{0,{312,313,314,346}},
{195,{0,0,0,346}},	{0,{335,0,318,285}},	{0,{0,0,345,284}},
{0,{334,285,284,283}},	{0,{344,321,322,323}},	{206,{310,310,310,344}},
{0,{267,267,267,344}},	{0,{267,266,268,343}},	{0,{274,0,276,277}},
{206,{264,264,264,341}},	{247,{341,0,296,297}},	{0,{0,0,295,299}},
{0,{299,300,301,340}},	{0,{305,0,306,340}},	{0,{340,341,312,313}},
{0,{341,237,238,245}},	{0,{341,240,297,242}},	{0,{267,0,267,268}},
{0,{0,340,0,268}},	{0,{340,275,241,276}},	{0,{336,276,233,240}},
{0,{238,239,239,237}},	{195,{338,0,0,0}},	{247,{0,0,283,284}},
{0,{337,338,289,234}},	{0,{259,0,259,261}},	{0,{337,337,337,338}},
{0,{338,338,338,339}},	{0,{305,304,305,339}},	{0,{339,339,339,340}},
{0,{340,340,341,341}},	{0,{341,341,341,341}},	{0,{341,341,341,341}},
{0,{341,341,341,341}},	{0,{341,341,341,341}},	{206,{341,341,341,341}},
{0,{340,340,340,340}},	{0,{296,295,296,295}},	{212,{238,238,238,238}},
{0,{338,338,338,338}},	{0,{0,0,0,338}},	{0,{338,338,338,0}},
{192,{337,337,337,0}},	{0,{337,337,337,289}},	{0,{337,337,337,337}},
{0,{337,337,337,338}},	{0,{338,338,338,338}},	{0,{338,338,338,339}},
{0,{0,0,0,339}},	{0,{339,339,339,315}},	{0,{315,315,315,315}},
{0,{338,338,338,338}},	{0,{338,322,338,322}},	{0,{279,279,279,314}},
{0,{337,338,339,340}},	{333,{340,340,340,340}},	{0,{340,341,340,342}},
{0,{342,342,342,342}},	{0,{207,207,207,207}},	{0,{207,207,207,207}},
{0,{0,0,0,340}},	{206,{340,340,340,340}},	{0,{340,341,0,0}},
{0,{341,341,341,341}},	{0,{341,342,341,343}},	{0,{0,343,0,0}},
{0,{343,344,344,329}},	{0,{330,330,330,331}},	{0,{231,231,231,231}},
{206,{0,0,0,0}},	{0,{341,0,341,0}},	{0,{233,233,233,233}},
{346,{0,336,0,0}},	{253,{0,335,0,0}},	{0,{338,339,340,324}},
{333,{323,323,323,323}},	{0,{339,339,339,190}},	{206,{339,340,339,339}},
{0,{239,239,239,239}},	{0,{0,329,0,339}},	{0,{339,339,339,0}},
{206,{339,339,339,339}},	{0,{339,339,339,217}},	{0,{339,0,0,340}},
{0,{338,0,0,340}},	{0,{340,0,341,0}},	{0,{336,0,0,0}},
{0,{340,0,0,0}},	{0,{339,340,0,0}},	{0,{340,340,340,340}},
{0,{332,0,340,333}},	{0,{331,0,0,340}},	{0,{335,0,340,0}},
{0,{0,340,341,0}},	{0,{341,0,0,0}},	{0,{341,0,331,0}},
{0,{0,0,341,0}},	{0,{338,0,0,341}},	{0,{337,0,332,340}},
{0,{0,0,333,0}},	{0,{339,340,340,340}},	{0,{340,0,0,0}},
{0,{0,0,0,340}},	{0,{323,0,323,339}},	{377,{0,0,0,0}},
{0,{321,0,321,0}},	{377,{337,337,337,337}},	{379,{337,337,337,0}},
{0,{336,336,336,0}},	{381,{0,0,0,0}},	{377,{335,335,335,335}},
{0,{0,0,0,335}},	{0,{335,0,0,330}},	{377,{335,335,335,335}},
{0,{0,0,0,335}},	{0,{335,335,335,0}},	{0,{335,335,335,313}},
{0,{335,335,335,335}},	{0,{0,0,335,0}},	{0,{310,335,310,310}},
{0,{335,335,335,0}},	{0,{335,0,0,0}},	{0,{335,335,335,335}},
{0,{335,335,335,0}},	{0,{335,335,335,335}},	{0,{335,0,0,336}},
{0,{334,0,0,0}},	{0,{335,0,0,334}},	{0,{335,0,0,333}},
{0,{334,0,0,0}},	{0,{334,0,0,0}},	{0,{0,0,0,330}},
{0,{333,0,0,0}},	{0,{333,334,0,0}},	{0,{329,0,334,0}},
{0,{334,0,335,0}},	{0,{333,0,0,0}},	{0,{334,0,0,0}},
{0,{333,334,0,0}},	{0,{334,0,0,0}},	{0,{0,0,334,0}},
{0,{334,334,334,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,334,334,335}},	{0,{335,335,335,336}},
{0,{336,0,0,0}},	{0,{336,0,0,0}},	{0,{336,336,336,336}},
{0,{336,336,336,336}},	{0,{336,0,0,0}},	{0,{336,336,0,0}},
{0,{336,336,336,336}},	{0,{336,336,337,337}},	{0,{337,337,337,337}},
{0,{337,337,337,337}},	{0,{337,337,337,337}},	{0,{337,337,337,337}},
{0,{337,337,337,337}},	{0,{337,337,337,337}},	{0,{337,337,337,337}},
{0,{337,337,337,337}},	{0,{337,337,337,337}},	{0,{337,337,337,337}},
{40,{308,308,308,308}},	{40,{308,308,308,308}},	{40,{0,0,0,0}},
{40,{320,320,0,0}},	{40,{320,320,320,320}},	{0,{332,333,333,333}},
{0,{333,333,333,333}},	{50,{333,333,333,333}},	{0,{0,0,333,0}},
{53,{0,0,0,0}},	{50,{332,332,332,332}},	{0,{302,302,332,302}},
{0,{326,326,326,326}},	{0,{302,302,302,302}},	{0,{303,303,303,303}},
{0,{311,311,311,311}},	{0,{0,0,328,0}},	{0,{290,328,290,290}},
{0,{328,0,0,0}},	{0,{328,0,0,0}},	{0,{328,328,328,328}},
{0,{328,328,328,328}},	{0,{328,328,328,328}},	{0,{328,328,328,328}},
{0,{328,329,329,329}},	{0,{328,328,328,328}},	{0,{328,329,328,328}},
{0,{329,330,329,330}},	{0,{330,330,330,330}},	{0,{330,330,330,330}},
{93,{327,327,327,327}},	{93,{0,0,0,0}},	{93,{328,328,328,328}},
{0,{328,328,328,328}},	{0,{327,327,328,327}},	{0,{328,328,328,328}},
{0,{328,328,328,328}},	{0,{328,322,322,322}},	{0,{319,319,319,319}},
{0,{315,315,315,315}},	{0,{296,326,296,296}},	{0,{326,326,326,0}},
{0,{326,0,326,0}},	{0,{0,0,326,0}},	{0,{326,0,0,0}},
{0,{326,0,0,0}},	{0,{326,326,326,0}},	{0,{326,326,326,326}},
{0,{326,326,326,0}},	{0,{326,327,0,0}},	{0,{327,326,0,0}},
{0,{0,325,0,0}},	{0,{326,0,0,0}},	{0,{326,0,0,0}},
{0,{326,0,0,0}},	{0,{326,326,326,326}},	{0,{326,317,326,317}},
{0,{0,326,327,0}},	{0,{0,0,327,0}},	{0,{327,0,0,0}},
{0,{0,327,0,0}},	{0,{327,0,0,0}},	{0,{0,0,327,0}},
{0,{327,318,327,318}},	{0,{0,327,0,0}},	{0,{327,327,0,0}},
{0,{327,328,327,0}},	{0,{326,328,326,0}},	{0,{325,326,328,0}},
{0,{328,0,0,0}},	{0,{0,328,0,0}},	{0,{328,328,328,0}},
{0,{328,0,0,0}},	{0,{328,329,330,330}},	{0,{330,331,332,332}},
{0,{332,333,333,333}},	{0,{333,334,334,334}},	{0,{334,334,335,335}},
{0,{335,335,335,335}},	{0,{335,335,335,335}},	{0,{335,335,336,335}},
{0,{336,336,337,336}},	{0,{337,337,337,337}},	{0,{337,337,338,337}},
{0,{338,338,338,338}},	{0,{338,338,338,338}},	{0,{329,329,329,329}},
{0,{337,337,337,337}},	{0,{337,337,337,337}},	{0,{337,0,0,0}},
{0,{337,337,337,337}},	{0,{337,337,337,337}},	{0,{337,337,337,337}},
{0,{337,338,339,339}},	{0,{338,338,338,338}},	{0,{338,337,337,337}},
{0,{336,336,338,336}},	{0,{0,0,338,0}},	{0,{338,339,340,339}},
{0,{340,340,341,340}},	{0,{339,339,341,339}},	{0,{338,338,341,338}},
{0,{341,341,341,341}},	{0,{341,341,341,341}},	{0,{341,341,341,341}},
{0,{341,340,340,340}},	{0,{341,341,341,341}},	{0,{341,341,341,341}},
{0,{341,342,341,342}},	{0,{0,0,342,0}},	{0,{340,340,340,340}},
{226,{341,341,341,341}},	{226,{0,0,0,0}},	{0,{0,340,0,0}},
{0,{340,341,340,340}},	{0,{0,338,341,0}},	{226,{341,0,0,0}},
{0,{341,341,341,341}},	{0,{0,0,341,0}},	{0,{341,341,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{300,300,342,300}},	{0,{291,291,342,291}},	{0,{342,342,342,342}},
{0,{342,313,314,313}},	{0,{342,312,313,312}},	{0,{340,311,313,311}},
{0,{339,310,313,310}},	{0,{340,340,340,340}},	{0,{340,0,341,0}},
{0,{341,341,341,341}},	{252,{0,0,0,0}},	{0,{338,0,338,0}},
{0,{339,339,0,0}},	{256,{0,0,0,0}},	{0,{338,339,340,340}},
{0,{340,341,340,340}},	{0,{281,281,281,281}},	{0,{340,340,340,340}},
{0,{296,296,297,296}},	{0,{339,339,339,339}},	{0,{339,339,339,339}},
{0,{339,306,339,306}},	{0,{305,305,339,305}},	{226,{339,0,340,0}},
{0,{340,306,340,0}},	{0,{267,267,340,267}},	{0,{0,0,340,0}},
{0,{340,252,253,253}},	{0,{255,254,255,255}},	{0,{256,256,256,256}},
{0,{257,257,257,257}},	{0,{337,263,264,263}},	{0,{267,337,338,267}},
{0,{275,275,276,276}},	{0,{280,280,280,280}},	{0,{281,281,281,281}},
{0,{280,280,335,280}},	{0,{279,279,335,279}},	{0,{0,335,0,0}},
{0,{335,336,288,288}},	{0,{336,337,0,0}},	{0,{0,289,337,0}},
{0,{337,257,257,257}},	{0,{337,338,337,263}},	{0,{338,338,339,0}},
{0,{339,339,340,305}},	{252,{336,336,336,0}},	{0,{0,0,339,0}},
{0,{339,339,251,251}},	{0,{339,0,0,0}},	{0,{339,0,339,0}},
{0,{339,228,229,229}},	{0,{262,262,339,262}},	{0,{263,263,339,263}},
{0,{339,0,0,0}},	{0,{244,339,244,244}},	{226,{0,0,307,0}},
{0,{223,223,223,223}},	{0,{225,225,225,225}},	{0,{230,230,230,230}},
{0,{234,234,234,234}},	{0,{270,270,270,270}},	{0,{276,276,276,276}},
{0,{0,0,0,332}},	{0,{290,290,290,290}},	{0,{290,290,290,290}},
{0,{330,330,331,330}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{330,330,331,330}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{233,233,331,233}},
{0,{232,331,232,232}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{0,331,0,0}},	{0,{305,305,305,305}},	{0,{330,330,330,0}},
{0,{330,315,315,315}},	{0,{330,330,330,330}},	{0,{330,330,330,330}},
{0,{330,330,330,330}},	{0,{330,330,330,330}},	{0,{330,330,330,330}},
{0,{330,330,330,330}},	{0,{330,330,330,330}},	{0,{330,330,330,330}},
{0,{330,330,330,330}},	{0,{330,330,330,330}},	{0,{330,330,330,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{352,{0,0,0,0}},	{0,{330,330,330,330}},
{0,{312,312,312,312}},	{0,{329,329,329,220}},	{0,{329,330,330,0}},
{0,{330,0,0,0}},	{0,{330,0,0,0}},	{0,{326,327,330,0}},
{0,{0,0,330,0}},	{0,{330,0,0,0}},	{0,{0,0,330,0}},
{0,{330,330,330,330}},	{0,{0,0,330,0}},	{0,{330,0,0,0}},
{0,{330,330,331,330}},	{0,{331,331,331,0}},	{0,{331,0,0,0}},
{0,{331,317,317,0}},	{0,{330,316,319,0}},	{0,{325,325,325,325}},
{0,{329,0,0,0}},	{0,{329,313,313,0}},	{0,{329,0,0,0}},
{0,{329,0,0,0}},	{0,{0,0,329,0}},	{0,{329,0,0,0}},
{0,{329,329,329,329}},	{0,{329,329,329,329}},	{0,{329,0,0,0}},
{0,{0,0,329,0}},	{0,{329,329,329,0}},	{0,{329,0,0,0}},
{0,{329,329,329,0}},	{0,{329,329,329,308}},	{0,{329,329,329,0}},
{0,{329,329,329,329}},	{0,{305,305,329,305}},	{0,{329,329,329,0}},
{0,{329,329,329,329}},	{0,{329,329,329,330}},	{0,{330,330,330,0}},
{0,{330,330,330,0}},	{0,{330,331,332,0}},	{0,{332,0,0,0}},
{0,{332,0,332,0}},	{0,{329,328,329,0}},	{0,{0,331,0,0}},
{0,{331,0,331,0}},	{0,{326,325,331,0}},	{0,{0,0,331,0}},
{0,{0,0,331,0}},	{0,{0,0,331,0}},	{0,{0,0,331,0}},
{0,{331,320,321,0}},	{0,{0,0,331,0}},	{0,{331,0,0,0}},
{0,{331,0,0,0}},	{0,{331,332,0,0}},	{0,{331,331,0,0}},
{0,{331,0,0,0}},	{0,{330,0,331,0}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,0}},	{0,{331,331,331,0}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,0}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{293,331,293,293}},	{0,{331,331,331,331}},	{0,{0,0,0,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,332,332,332}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{325,325,325,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,0,331,0}},	{0,{331,0,331,0}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,330,330,330}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{0,0,0,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,0,0}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,0,0}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,0,0,0}},	{0,{331,331,331,331}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{331,332,331,333}},
{0,{333,333,333,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,335}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,0,0,0}},	{0,{334,334,334,334}},	{0,{334,334,334,334}},
{0,{334,334,334,334}},	{0,{334,335,335,336}},	{0,{334,334,334,335}},
{0,{334,334,334,334}},	{0,{334,333,333,333}},	{0,{334,334,334,334}},
{0,{334,335,334,334}},	{0,{335,335,335,335}},	{0,{335,335,335,335}},
{0,{335,335,335,335}},	{0,{335,335,335,335}},	{0,{335,335,335,335}},
{0,{335,335,335,335}},	{0,{335,335,335,335}},	{0,{335,335,335,335}},
{0,{335,335,335,335}},	{0,{335,335,335,335}},	{0,{335,334,334,334}},
{0,{335,335,335,335}},	{0,{335,335,335,335}},	{0,{335,335,335,336}},
{0,{335,335,335,335}},	{0,{0,0,335,0}},	{0,{335,335,335,335}},
{0,{335,335,335,335}},	{0,{335,335,335,335}},	{0,{335,335,335,335}},
{0,{335,335,335,335}},	{0,{335,335,335,335}},	{0,{335,335,335,335}},
{0,{335,335,335,335}},	{0,{335,335,335,336}},	{0,{335,335,335,335}},
{0,{335,335,335,335}},	{0,{335,335,335,335}},	{0,{335,335,335,335}},
{0,{335,335,335,335}},	{0,{335,335,335,335}},	{0,{335,335,335,335}},
{0,{335,306,306,306}},	{0,{334,305,305,335}},	{0,{335,335,335,335}},
{0,{335,335,335,336}},	{0,{336,336,336,0}},	{0,{336,336,336,336}},
{0,{0,336,0,0}},	{0,{336,336,336,337}},	{0,{337,337,337,338}},
{0,{335,335,335,335}},	{0,{337,337,337,337}},	{0,{337,337,337,337}},
{0,{337,337,337,337}},	{0,{337,337,337,337}},	{0,{337,337,337,337}},
{0,{337,337,337,338}},	{0,{338,338,338,338}},	{0,{338,338,338,338}},
{0,{338,338,338,338}},	{0,{338,338,338,338}},	{0,{338,339,261,261}},
{0,{339,339,339,339}},	{0,{339,339,339,340}},	{0,{340,340,340,260}},
{0,{340,340,340,340}},	{0,{263,340,263,263}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,0,0,0}},	{0,{340,340,340,340}},
{0,{340,340,340,224}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{0,0,0,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{0,0,340,0}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,340,340,340}},	{0,{340,340,340,340}},
{0,{340,340,340,340}},	{0,{340,341,341,342}},	{0,{342,342,342,0}},
{0,{342,343,343,343}},	{0,{343,344,345,0}},	{0,{345,345,345,346}},
{0,{345,345,345,345}},	{0,{345,0,0,0}},	{0,{345,0,0,0}},
{0,{345,345,345,345}},	{0,{345,345,345,345}},	{0,{336,0,338,0}},
{0,{344,344,344,344}},	{0,{344,344,344,344}},	{0,{344,344,344,344}},
{0,{344,345,344,345}},	{0,{326,326,326,327}},	{0,{329,329,329,329}},
{374,{324,324,324,325}},	{374,{0,0,0,0}},	{0,{341,341,341,341}},
{0,{341,341,341,341}},	{0,{341,341,341,341}},	{0,{341,341,341,341}},
{0,{341,341,341,341}},	{0,{341,341,342,341}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,343}},	{0,{343,343,343,343}},
{0,{340,340,340,340}},	{0,{342,0,342,0}},	{0,{0,0,0,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,331}},	{0,{342,342,342,342}},
{0,{342,342,342,0}},	{0,{342,342,342,342}},	{0,{342,343,342,342}},
{0,{341,341,341,341}},	{0,{342,0,342,0}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,343,343}},	{0,{342,342,342,342}},	{0,{342,342,343,343}},
{0,{342,342,342,342}},	{0,{342,0,342,0}},	{0,{342,0,342,0}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,0,342,0}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,343,342}},
{0,{341,341,341,341}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{0,0,342,0}},	{0,{342,342,342,342}},	{0,{312,312,312,342}},
{0,{342,343,342,0}},	{0,{304,304,343,304}},	{0,{343,0,343,0}},
{0,{343,0,0,0}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,344,344,344}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,342,342,342}},
{0,{343,343,343,344}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,342,343,342}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,337,337,337}},	{0,{343,312,343,312}},	{0,{343,0,0,0}},
{0,{0,0,343,0}},	{0,{0,0,343,0}},	{0,{343,0,0,0}},
{0,{343,0,343,0}},	{0,{343,0,343,0}},	{0,{343,343,343,343}},
{0,{343,343,343,0}},	{0,{0,343,0,0}},	{0,{343,343,343,0}},
{0,{0,343,0,0}},	{0,{0,343,0,0}},	{0,{0,343,0,0}},
{0,{0,343,0,0}},	{0,{343,343,343,343}},	{0,{334,334,343,334}},
{0,{343,0,0,0}},	{0,{0,343,0,0}},	{0,{0,0,343,0}},
{0,{0,0,343,0}},	{0,{343,343,343,0}},	{0,{0,343,0,0}},
{0,{343,343,343,0}},	{0,{343,343,343,334}},	{0,{343,343,343,0}},
{0,{0,343,0,0}},	{0,{343,343,343,0}},	{0,{343,342,342,0}},
{0,{343,341,341,0}},	{0,{343,340,340,0}},	{0,{343,0,0,0}},
{0,{343,0,0,0}},	{0,{343,343,343,0}},	{0,{0,343,0,0}},
{0,{343,344,344,345}},	{0,{342,345,343,344}},	{0,{345,343,343,343}},
{0,{345,345,345,342}},	{0,{345,345,345,341}},	{0,{340,340,340,340}},
{0,{344,345,345,345}},	{0,{345,345,345,344}},	{0,{343,343,343,343}},
{0,{344,345,345,345}},	{0,{344,344,344,344}},	{0,{344,345,345,345}},
{0,{344,344,344,344}},	{0,{344,344,344,345}},	{0,{344,344,344,344}},
{0,{344,344,344,344}},	{0,{344,344,344,344}},	{0,{344,344,344,344}},
{0,{344,344,344,343}},	{0,{344,344,344,344}},	{0,{344,344,344,343}},
{0,{344,344,344,344}},	{0,{344,344,344,344}},	{0,{344,344,344,343}},
{0,{344,344,344,344}},	{0,{344,344,344,344}},	{0,{344,344,344,344}},
{0,{344,344,344,344}},	{0,{344,0,0,0}},	{0,{344,344,344,344}},
{0,{344,344,344,344}},	{0,{344,344,344,344}},	{0,{344,344,344,345}},
{0,{345,345,345,346}},	{0,{345,345,345,345}},	{0,{342,342,342,342}},
{0,{344,344,344,343}},	{0,{344,0,0,0}},	{0,{343,344,0,0}},
{0,{344,345,345,345}},	{0,{344,344,344,344}},	{0,{344,344,344,344}},
{0,{344,344,344,344}},	{0,{344,344,344,344}},	{0,{344,344,344,343}},
{0,{344,344,344,342}},	{0,{344,344,344,344}},	{0,{344,344,344,344}},
{0,{344,344,344,344}},	{0,{344,343,343,343}},	{0,{344,344,344,344}},
{0,{344,344,344,344}},	{0,{344,344,344,345}},	{0,{344,344,344,344}},
{0,{344,0,0,0}},	{0,{344,344,344,344}},	{0,{344,344,344,0}},
{0,{344,344,344,344}},	{0,{344,344,344,343}},	{0,{344,344,344,0}},
{0,{0,0,344,0}},	{0,{344,344,344,344}},	{0,{344,344,344,0}},
{0,{344,344,344,345}},	{0,{344,344,344,344}},	{0,{344,344,344,344}},
{0,{344,344,344,344}},	{0,{344,344,344,344}},	{0,{344,344,344,301}},
{0,{344,344,344,292}},	{0,{344,344,344,344}},	{0,{344,315,315,315}},
{0,{344,344,314,314}},	{0,{344,344,344,344}},	{0,{0,344,345,0}},
{0,{0,343,0,0}},	{0,{0,0,343,0}},	{0,{343,343,343,343}},
{0,{0,343,0,0}},	{0,{343,343,343,344}},	{0,{343,343,343,343}},
{0,{343,343,343,342}},	{0,{343,343,343,341}},	{0,{343,343,343,343}},
{0,{343,343,343,342}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,309}},	{0,{343,343,343,308}},
{0,{343,343,343,307}},	{0,{0,0,343,0}},	{0,{343,343,343,0}},
{0,{343,343,343,0}},	{0,{267,267,267,343}},	{0,{266,266,266,343}},
{0,{0,0,0,343}},	{0,{343,247,343,248}},	{0,{343,247,343,247}},
{0,{264,343,264,264}},	{0,{268,343,268,268}},	{0,{267,267,343,267}},
{0,{343,343,343,284}},	{0,{343,343,343,283}},	{0,{0,343,0,0}},
{0,{343,343,343,292}},	{0,{343,343,343,291}},	{0,{343,343,343,0}},
{0,{343,343,343,0}},	{0,{0,343,0,0}},	{0,{343,343,343,258}},
{0,{343,343,343,264}},	{0,{343,343,343,263}},	{0,{0,0,343,0}},
{0,{343,343,344,0}},	{0,{305,305,344,305}},	{0,{344,344,343,304}},
{0,{344,344,0,0}},	{0,{344,344,344,250}},	{0,{0,0,344,0}},
{0,{344,344,344,0}},	{0,{223,223,223,224}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,0}},	{0,{343,343,343,243}},
{0,{0,0,0,343}},	{0,{343,343,343,343}},	{0,{343,343,343,342}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,342}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,241}},	{0,{343,343,343,240}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{0,0,343,0}},
{0,{343,343,343,0}},	{0,{343,343,343,328}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,344}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,230,230,230}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,0,344,0}},	{0,{343,0,343,0}},	{0,{343,0,0,0}},
{0,{0,0,343,0}},	{0,{343,0,0,0}},	{0,{343,343,343,337}},
{0,{343,343,343,0}},	{0,{343,343,343,343}},	{0,{343,0,0,0}},
{0,{343,343,343,343}},	{0,{0,0,343,0}},	{0,{343,343,343,343}},
{0,{342,342,343,342}},	{0,{0,0,343,0}},	{0,{343,344,0,0}},
{0,{342,0,0,0}},	{0,{343,343,343,0}},	{0,{343,343,343,0}},
{0,{343,343,0,0}},	{0,{343,343,343,343}},	{0,{343,0,0,0}},
{0,{343,343,343,0}},	{0,{343,343,343,0}},	{0,{343,0,343,0}},
{0,{343,343,343,0}},	{0,{343,343,343,0}},	{0,{0,0,343,0}},
{0,{325,325,343,325}},	{0,{0,0,343,0}},	{0,{343,343,343,343}},
{0,{343,322,322,322}},	{0,{0,0,343,0}},	{0,{343,343,343,343}},
{0,{343,343,338,0}},	{0,{342,342,0,0}},	{0,{342,0,339,0}},
{0,{0,0,342,0}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{0,0,342,0}},	{0,{342,0,0,0}},
{0,{342,0,342,0}},	{0,{0,0,342,0}},	{0,{342,342,342,335}},
{0,{342,342,342,0}},	{0,{342,342,342,342}},	{0,{342,342,342,0}},
{0,{342,342,0,0}},	{0,{342,342,342,342}},	{0,{342,342,342,0}},
{0,{342,342,342,342}},	{0,{342,342,342,0}},	{0,{342,0,0,0}},
{0,{342,0,0,0}},	{0,{342,0,0,0}},	{0,{342,0,0,0}},
{0,{342,342,342,342}},	{0,{342,342,342,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,344,343,0}},	{0,{344,343,344,0}},	{0,{344,0,344,0}},
{0,{344,0,344,0}},	{0,{344,344,344,0}},	{0,{344,344,344,344}},
{0,{344,344,344,344}},	{0,{344,344,344,344}},	{0,{344,344,344,0}},
{0,{344,344,344,344}},	{0,{344,344,344,344}},	{0,{344,344,344,344}},
{0,{344,344,344,344}},	{0,{344,344,344,344}},	{0,{344,344,344,344}},
{0,{344,0,344,0}},	{0,{344,344,344,344}},	{0,{317,317,317,317}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{322,322,322,0}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,0,342,0}},	{0,{342,342,342,342}},	{0,{313,313,313,342}},
{0,{0,0,0,342}},	{0,{342,0,0,0}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,342,342,342}},	{0,{342,342,342,343}},
{0,{343,343,343,0}},	{0,{343,343,343,343}},	{0,{340,340,340,340}},
{0,{342,343,343,343}},	{0,{342,342,342,342}},	{0,{342,342,342,342}},
{0,{342,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,343}},	{0,{343,343,343,343}},	{0,{343,343,343,343}},
{0,{343,343,343,0}},	{0,{343,344,344,345}},	{0,{345,345,345,345}},
{0,{345,345,345,345}},	{0,{337,337,345,337}},	{0,{345,345,291,0}},
{0,{345,0,345,0}},	{0,{0,0,0,345}},	{0,{0,0,345,0}},
{0,{0,0,0,345}},	{0,{345,345,345,345}},	{0,{345,0,0,0}},
{0,{345,345,345,345}},	{0,{345,345,345,345}},	{0,{345,345,346,345}},
{0,{346,346,346,346}},	{0,{346,346,346,346}},	{0,{346,346,346,346}},
{0,{346,346,346,346}},	{0,{346,345,346,345}},	{0,{0,346,0,0}},
{0,{346,346,346,336}},	{0,{0,0,0,346}},	{0,{346,346,0,0}},
{0,{346,346,346,346}},	{138,{0,0,0,0}},	{0,{345,345,345,345}},
{140,{0,0,0,0}},	{0,{344,344,344,344}},	{142,{0,337,0,0}},
{143,{0,0,0,0}},	{0,{342,0,0,0}},	{0,{0,0,342,0}},
{0,{342,0,341,0}},	{147,{0,0,340,0}},	{0,{0,0,339,341}},
{0,{341,341,341,341}},	{0,{341,0,0,0}},	{0,{341,341,341,341}},
{0,{341,341,341,341}},	{0,{341,342,343,344}},	{0,{344,341,342,343}},
{0,{344,345,346,347}},	{0,{347,339,340,341}},	{0,{347,343,344,345}},
{0,{347,337,338,339}},	{0,{347,341,342,343}},	{0,{347,348,349,350}},
{0,{350,347,348,349}},	{0,{350,346,347,348}},	{0,{350,351,351,352}},
{0,{352,350,350,351}},	{0,{352,353,353,353}},	{0,{353,352,352,352}},
{0,{353,353,353,354}},	{0,{354,354,354,354}},	{0,{354,354,354,354}},
{0,{354,354,354,354}},	{0,{354,354,354,354}},	{0,{354,354,354,354}},
{0,{354,354,354,354}},	{0,{354,354,354,354}},	{0,{354,355,354,355}},
{0,{355,355,355,355}},	{186,{355,355,355,355}},	{0,{355,355,355,355}},
{0,{355,355,355,355}},	{0,{355,356,356,357}},	{0,{357,358,358,359}},
{0,{359,359,359,359}},	{0,{359,360,361,360}},	{0,{358,359,359,359}},
{0,{358,358,358,358}},	{0,{359,359,359,360}},	{0,{360,360,360,360}},
{0,{360,360,360,361}},	{0,{361,361,361,361}},	{186,{360,360,360,360}},
{0,{360,0,0,0}},	{0,{360,0,360,0}},	{0,{360,360,361,362}},
{0,{359,359,359,361}},	{0,{361,361,361,362}},	{0,{359,359,359,359}},
{0,{360,360,360,360}},	{0,{360,360,360,360}},	{211,{359,359,359,359}},
{0,{359,359,359,360}},	{0,{360,360,360,359}},	{0,{357,357,357,357}},
{0,{359,359,359,359}},	{0,{359,359,359,360}},	{0,{360,360,360,360}},
{0,{360,360,360,360}},	{0,{360,360,360,360}},	{0,{0,0,0,360}},
{0,{0,360,361,0}},	{0,{361,361,361,361}},	{0,{361,361,361,361}},
{0,{361,361,361,361}},	{0,{361,361,361,361}},	{0,{0,0,361,0}},
{0,{0,361,0,362}},	{0,{362,362,362,362}},	{0,{362,362,362,363}},
{0,{363,363,363,316}},	{0,{363,363,363,363}},	{0,{363,363,363,363}},
{0,{363,363,363,363}},	{0,{363,363,363,363}},	{186,{363,363,363,363}},
{0,{363,363,363,363}},	{0,{363,363,363,363}},	{0,{363,363,363,363}},
{0,{363,363,363,363}},	{0,{363,363,363,363}},	{0,{363,363,363,363}},
{0,{363,363,363,363}},	{0,{0,0,363,0}},	{0,{363,363,363,364}},
{0,{364,364,364,294}},	{0,{364,361,361,362}},	{0,{364,362,362,292}},
{0,{364,365,366,294}},	{0,{366,364,365,293}},	{0,{366,366,366,0}},
{0,{322,322,322,320}},	{0,{365,365,365,366}},	{0,{366,366,366,366}},
{0,{366,366,366,366}},	{0,{366,366,366,366}},	{0,{0,366,0,0}},
{0,{366,0,366,0}},	{0,{366,366,366,366}},	{0,{278,278,278,366}},
{0,{277,277,277,366}},	{0,{0,0,0,366}},	{0,{366,245,246,247}},
{0,{366,249,250,251}},	{0,{275,366,275,275}},	{0,{366,366,366,366}},
{0,{279,279,366,279}},	{0,{366,366,366,366}},	{211,{365,365,365,365}},
{0,{365,365,365,365}},	{0,{365,365,365,365}},	{0,{365,365,365,365}},
{0,{365,365,365,365}},	{0,{365,365,365,365}},	{0,{0,365,0,0}},
{0,{365,365,365,365}},	{0,{365,365,365,365}},	{0,{365,365,365,365}},
{279,{0,0,0,0}},	{0,{364,364,364,364}},	{279,{363,363,363,363}},
{279,{324,324,324,324}},	{0,{362,362,362,362}},	{0,{362,362,362,0}},
{0,{362,362,362,362}},	{0,{362,362,362,362}},	{0,{362,362,362,362}},
{0,{362,362,362,363}},	{0,{362,362,362,362}},	{0,{362,362,362,362}},
{0,{362,362,362,255}},	{0,{0,362,0,0}},	{0,{362,362,362,362}},
{0,{362,362,361,361}},	{0,{362,362,362,362}},	{0,{362,362,362,362}},
{0,{362,362,362,362}},	{0,{362,362,362,362}},	{0,{362,363,363,364}},
{0,{364,365,365,366}},	{0,{366,367,368,367}},	{0,{365,366,366,366}},
{0,{367,367,367,367}},	{0,{364,364,367,364}},	{0,{367,367,367,367}},
{0,{0,0,367,0}},	{0,{367,367,367,367}},	{0,{311,311,311,311}},
{0,{0,0,274,0}},	{0,{365,365,365,365}},	{0,{365,365,257,257}},
{0,{365,365,365,365}},	{0,{365,365,365,366}},	{0,{366,366,366,365}},
{0,{353,353,353,353}},	{0,{365,366,365,367}},	{0,{302,302,302,366}},
{0,{366,366,366,366}},	{0,{366,366,366,366}},	{0,{366,366,366,366}},
{0,{366,366,366,367}},	{0,{367,367,367,368}},	{0,{368,368,368,365}},
{0,{368,368,368,369}},	{0,{369,369,369,370}},	{0,{370,370,371,372}},
{0,{372,372,373,367}},	{0,{366,366,366,366}},	{0,{372,372,372,372}},
{0,{372,372,372,372}},	{0,{372,372,372,373}},	{0,{371,371,371,373}},
{0,{373,373,373,373}},	{0,{373,373,373,373}},	{0,{373,373,373,374}},
{0,{374,375,0,0}},	{0,{375,376,376,376}},	{0,{372,0,0,0}},
{0,{374,374,374,374}},	{0,{374,374,374,375}},	{0,{348,348,348,374}},
{0,{374,374,374,374}},	{0,{344,374,344,348}},	{0,{345,374,345,345}},
{0,{346,374,346,346}},	{0,{210,374,210,210}},	{0,{374,374,374,358}},
{0,{373,373,373,374}},	{0,{374,374,374,374}},	{0,{250,250,250,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{360,{374,374,0,0}},	{360,{0,0,0,0}},
{0,{372,372,0,0}},	{0,{372,372,372,372}},	{0,{372,372,372,0}},
{0,{372,372,372,372}},	{0,{372,372,372,372}},	{0,{372,372,372,372}},
{0,{372,0,0,0}},	{0,{372,0,0,0}},	{0,{0,0,0,372}},
{0,{0,0,0,372}},	{0,{0,0,0,372}},	{371,{0,0,0,0}},
{0,{371,371,371,371}},	{0,{371,371,371,371}},	{0,{371,371,371,371}},
{0,{371,371,371,371}},	{0,{371,371,371,0}},	{0,{371,0,0,0}},
{382,{0,0,0,0}},	{383,{0,0,0,0}},	{383,{369,369,369,369}},
{0,{369,369,369,369}},	{0,{369,369,369,369}},	{0,{369,369,369,369}},
{0,{0,0,0,369}},	{0,{354,0,0,369}},	{0,{0,0,0,369}},
{0,{0,369,0,0}},	{0,{351,0,0,369}},	{0,{0,0,0,369}},
{0,{369,369,369,369}},	{395,{0,0,0,0}},	{0,{0,0,0,368}},
{0,{0,0,0,368}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{0,0,0,368}},
{0,{368,0,0,367}},	{0,{368,368,368,368}},	{421,{0,0,0,0}},
{0,{367,368,368,369}},	{0,{369,367,367,370}},	{0,{370,366,366,369}},
{0,{370,0,0,0}},	{0,{370,0,0,0}},	{0,{370,0,0,371}},
{0,{371,371,371,371}},	{0,{371,370,370,372}},	{0,{372,372,372,372}},
{0,{0,0,0,367}},	{0,{371,372,372,373}},	{0,{0,0,0,373}},
{0,{370,370,370,371}},	{0,{368,369,369,369}},	{0,{368,368,368,368}},
{0,{370,370,370,370}},	{0,{370,370,370,370}},	{0,{370,370,370,370}},
{0,{370,370,370,370}},	{0,{370,370,370,370}},	{0,{370,370,370,370}},
{0,{370,370,370,370}},	{0,{370,370,370,370}},	{0,{370,370,370,370}},
{0,{370,370,370,370}},	{0,{370,370,370,370}},	{0,{0,0,0,370}},
{0,{0,0,0,370}},	{0,{370,370,370,370}},	{0,{370,370,370,370}},
{0,{370,368,368,371}},	{0,{371,371,371,371}},	{0,{0,0,0,371}},
{0,{0,0,0,371}},	{0,{0,0,0,371}},	{0,{0,0,0,371}},
{0,{0,0,0,371}},	{0,{0,0,0,371}},	{0,{0,0,0,371}},
{0,{0,0,0,371}},	{0,{0,0,0,371}},	{0,{371,372,372,372}},
{0,{372,372,372,372}},	{0,{372,373,372,372}},	{0,{373,0,0,374}},
{0,{329,0,0,373}},	{0,{373,0,0,0}},	{0,{373,347,347,347}},
{0,{373,373,373,374}},	{0,{372,372,372,374}},	{0,{371,371,371,374}},
{0,{370,370,370,374}},	{0,{369,369,369,374}},	{0,{374,375,375,375}},
{0,{375,374,374,374}},	{0,{375,375,375,375}},	{0,{365,365,365,365}},
{0,{374,374,374,374}},	{0,{0,0,0,374}},	{0,{0,0,0,374}},
{0,{0,0,0,374}},	{0,{0,0,0,374}},	{0,{359,359,359,374}},
{0,{358,358,358,374}},	{0,{374,374,374,374}},	{0,{374,0,0,319}},
{0,{0,0,0,374}},	{0,{0,0,0,374}},	{0,{0,0,0,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{0,0,0,374}},	{0,{0,0,0,374}},	{0,{0,0,0,374}},
{0,{0,0,0,374}},	{0,{0,0,0,374}},	{0,{0,0,0,374}},
{0,{0,0,0,374}},	{0,{0,0,0,374}},	{0,{0,0,0,374}},
{0,{0,0,0,374}},	{0,{0,0,0,374}},	{135,{0,0,0,0}},
{0,{373,373,373,373}},	{0,{0,0,0,373}},	{0,{373,373,373,373}},
{0,{0,0,0,373}},	{0,{373,0,0,0}},	{0,{373,373,373,373}},
{0,{373,373,373,373}},	{0,{0,0,0,373}},	{0,{373,373,373,373}},
{0,{0,0,0,373}},	{0,{0,0,0,373}},	{0,{0,0,0,373}},
{0,{373,374,375,376}},	{0,{376,377,377,375}},	{0,{377,376,376,374}},
{0,{377,378,378,379}},	{0,{379,374,371,372}},	{0,{379,380,381,371}},
{0,{381,379,379,370}},	{0,{381,378,378,369}},	{0,{381,377,377,374}},
{0,{374,369,366,381}},	{0,{381,382,376,366}},	{0,{372,367,364,382}},
{0,{372,373,374,381}},	{0,{381,379,373,382}},	{0,{382,371,371,383}},
{0,{383,370,370,384}},	{0,{384,369,369,385}},	{0,{385,368,369,378}},
{0,{384,367,368,385}},	{0,{385,373,367,363}},	{0,{378,365,365,362}},
{0,{379,364,364,361}},	{0,{376,363,364,360}},	{0,{382,383,384,385}},
{0,{385,384,384,384}},	{0,{384,383,382,383}},	{0,{384,385,385,386}},
{0,{386,387,387,385}},	{0,{387,388,388,384}},	{0,{388,356,388,356}},
{0,{355,355,355,388}},	{0,{354,354,354,354}},	{0,{387,387,387,387}},
{0,{387,352,352,349}},	{0,{386,351,351,387}},	{0,{350,350,350,387}},
{0,{349,349,349,365}},	{0,{348,348,348,345}},	{0,{347,347,347,383}},
{0,{384,384,384,384}},	{0,{380,345,345,345}},	{0,{383,384,385,386}},
{0,{386,0,387,388}},	{0,{385,0,0,387}},	{0,{387,388,389,390}},
{0,{390,391,392,393}},	{0,{389,390,390,392}},	{0,{392,392,392,392}},
{0,{392,393,393,393}},	{0,{392,392,392,392}},	{0,{391,391,391,392}},
{0,{392,392,392,393}},	{0,{393,393,393,392}},	{0,{391,391,391,391}},
{0,{392,392,392,393}},	{0,{393,393,393,392}},	{0,{391,391,391,391}},
{0,{392,392,392,392}},	{0,{392,392,392,392}},	{0,{392,392,392,392}},
{0,{392,392,392,392}},	{0,{392,392,392,392}},	{0,{392,392,392,392}},
{0,{392,392,392,392}},	{0,{391,391,391,392}},	{0,{392,392,392,392}},
{0,{392,392,392,392}},	{0,{390,390,390,392}},	{0,{392,392,392,392}},
{0,{392,392,392,392}},	{0,{392,392,392,392}},	{0,{392,392,392,392}},
{0,{0,0,0,392}},	{0,{0,0,0,392}},	{0,{0,0,0,392}},
{0,{0,0,0,392}},	{0,{0,0,0,392}},	{0,{0,0,0,392}},
{0,{0,0,0,392}},	{0,{0,0,0,392}},	{0,{0,0,0,392}},
{0,{392,392,392,392}},	{0,{0,0,0,392}},	{0,{0,0,0,392}},
{0,{0,0,0,392}},	{0,{392,293,293,300}},	{0,{392,295,295,299}},
{0,{392,298,298,298}},	{0,{297,297,297,392}},	{0,{392,392,392,392}},
{0,{327,295,327,390}},	{0,{329,294,294,391}},	{0,{293,293,293,390}},
{0,{348,348,390,348}},	{0,{390,390,390,390}},	{0,{390,390,390,390}},
{0,{390,390,390,390}},	{0,{0,0,0,390}},	{0,{390,390,390,390}},
{0,{0,0,0,390}},	{0,{0,0,0,390}},	{0,{376,277,277,275}},
{0,{376,279,279,280}},	{0,{376,282,282,273}},	{0,{373,274,274,289}},
{0,{374,280,280,288}},	{0,{279,279,279,289}},	{0,{278,278,278,290}},
{0,{277,277,277,291}},	{0,{276,276,276,294}},	{0,{0,0,319,0}},
{0,{380,380,380,380}},	{0,{380,380,380,380}},	{0,{0,0,0,380}},
{0,{0,0,0,380}},	{0,{0,0,0,380}},	{0,{0,0,0,380}},
{0,{0,0,0,380}},	{0,{0,0,0,380}},	{0,{380,266,266,266}},
{0,{380,265,265,265}},	{0,{0,0,0,380}},	{0,{261,256,253,380}},
{0,{261,262,263,379}},	{0,{296,261,261,379}},	{0,{298,298,298,379}},
{0,{297,297,297,379}},	{0,{326,326,326,379}},	{0,{0,0,0,379}},
{0,{0,0,0,379}},	{0,{0,0,0,379}},	{0,{0,0,0,379}},
{0,{0,0,0,379}},	{0,{0,0,0,379}},	{0,{379,379,379,379}},
{0,{379,379,379,379}},	{0,{379,379,379,379}},	{0,{0,0,0,379}},
{0,{0,0,0,379}},	{0,{0,0,0,379}},	{0,{283,283,283,379}},
{0,{379,379,379,379}},	{0,{0,0,0,379}},	{0,{379,379,379,379}},
{0,{379,379,379,379}},	{0,{0,0,0,379}},	{0,{277,277,277,379}},
{0,{379,379,379,379}},	{0,{379,379,379,379}},	{0,{378,378,378,379}},
{0,{379,379,379,379}},	{0,{379,379,379,379}},	{0,{379,379,379,379}},
{0,{379,379,379,300}},	{0,{271,271,272,273}},	{0,{0,0,274,275}},
{0,{0,0,0,274}},	{0,{275,275,276,277}},	{0,{278,278,279,280}},
{0,{277,277,277,279}},	{0,{373,374,374,375}},	{0,{373,373,373,374}},
{0,{372,372,372,374}},	{0,{371,371,371,0}},	{0,{373,373,373,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{0,0,0,374}},	{0,{284,284,284,374}},	{0,{283,283,283,374}},
{0,{374,374,374,375}},	{0,{375,373,373,376}},	{0,{372,372,372,375}},
{0,{318,318,318,375}},	{0,{317,317,317,375}},	{0,{375,375,375,375}},
{0,{0,0,0,375}},	{0,{375,375,375,375}},	{0,{375,375,375,375}},
{0,{375,376,377,378}},	{0,{378,378,379,380}},	{0,{374,374,375,0}},
{0,{376,376,377,379}},	{0,{372,372,373,374}},	{0,{0,0,372,378}},
{0,{378,378,374,379}},	{0,{0,0,370,0}},	{0,{376,376,372,376}},
{0,{0,0,368,377}},	{0,{0,0,367,377}},	{0,{0,0,366,367}},
{0,{0,0,365,376}},	{0,{0,0,364,376}},	{0,{0,0,376,0}},
{0,{376,376,376,376}},	{0,{376,376,376,376}},	{0,{376,376,376,377}},
{0,{375,375,375,375}},	{0,{376,376,376,376}},	{0,{376,376,376,376}},
{0,{376,376,376,376}},	{0,{376,376,376,376}},	{0,{0,0,0,376}},
{0,{0,0,0,376}},	{0,{0,0,0,376}},	{0,{0,0,0,376}},
{0,{348,349,350,0}},	{0,{351,351,352,356}},	{0,{374,374,374,374}},
{0,{345,346,347,374}},	{0,{345,345,346,374}},	{0,{344,344,345,372}},
{0,{228,228,228,373}},	{0,{373,373,373,373}},	{0,{358,358,358,373}},
{0,{0,0,0,373}},	{0,{224,224,266,373}},	{0,{373,373,373,373}},
{0,{373,373,373,373}},	{0,{373,373,373,373}},	{0,{373,373,373,373}},
{0,{373,373,373,373}},	{0,{373,373,373,373}},	{0,{373,373,373,373}},
{0,{369,369,369,373}},	{0,{0,0,0,373}},	{0,{373,373,373,373}},
{0,{373,373,373,0}},	{0,{373,373,373,373}},	{0,{0,0,0,373}},
{0,{0,0,0,373}},	{0,{0,0,0,373}},	{0,{373,373,373,373}},
{0,{373,373,373,373}},	{0,{0,0,0,373}},	{0,{0,0,0,373}},
{0,{373,373,373,373}},	{0,{0,0,0,373}},	{0,{373,373,373,373}},
{0,{373,373,373,373}},	{0,{373,373,373,373}},	{0,{0,0,0,373}},
{0,{0,0,0,373}},	{0,{0,0,0,373}},	{390,{0,0,0,0}},
{0,{0,0,0,372}},	{0,{0,0,0,372}},	{0,{0,0,0,372}},
{0,{0,0,0,372}},	{0,{0,0,0,372}},	{0,{0,0,0,372}},
{0,{0,0,0,372}},	{0,{372,372,372,373}},	{0,{373,373,373,373}},
{0,{373,373,373,373}},	{0,{373,373,373,373}},	{0,{373,373,373,373}},
{0,{373,373,373,373}},	{0,{0,0,0,373}},	{0,{0,0,0,373}},
{0,{0,0,0,373}},	{0,{0,0,0,373}},	{0,{0,0,0,373}},
{0,{0,0,0,373}},	{0,{0,0,0,373}},	{0,{0,0,0,373}},
{0,{0,0,0,373}},	{417,{0,0,0,0}},	{0,{372,372,372,372}},
{0,{372,372,372,372}},	{0,{372,0,0,0}},	{0,{372,0,0,0}},
{0,{372,0,0,0}},	{0,{372,0,0,0}},	{0,{372,0,0,0}},
{0,{372,0,0,0}},	{0,{372,0,0,0}},	{0,{372,0,0,0}},
{0,{372,0,0,0}},	{0,{372,0,0,0}},	{0,{372,373,0,0}},
{0,{373,372,0,0}},	{0,{373,371,0,0}},	{0,{373,0,0,0}},
{0,{373,374,0,0}},	{0,{0,373,0,0}},	{0,{373,372,0,0}},
{0,{372,0,0,0}},	{0,{0,0,372,0}},	{0,{0,372,0,0}},
{0,{372,373,374,373}},	{0,{374,0,375,0}},	{0,{375,375,375,0}},
{0,{375,0,375,0}},	{0,{375,0,0,0}},	{0,{375,358,376,0}},
{0,{357,357,376,0}},	{0,{356,356,0,0}},	{0,{375,355,0,0}},
{0,{375,0,375,0}},	{0,{0,0,0,375}},	{0,{375,352,0,0}},
{0,{375,351,0,0}},	{0,{375,350,0,0}},	{0,{375,349,0,0}},
{0,{375,0,0,0}},	{0,{0,0,0,375}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{0,0,0,375}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{375,0,0,0}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,0,0,0}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{329,0,375,0}},	{0,{375,0,0,0}},	{0,{0,0,373,0}},
{0,{374,330,0,0}},	{0,{374,375,374,0}},	{0,{375,374,373,0}},
{0,{375,373,372,0}},	{0,{375,372,371,0}},	{0,{375,371,370,0}},
{0,{375,370,369,0}},	{0,{375,369,368,0}},	{0,{375,368,367,0}},
{0,{375,367,366,0}},	{0,{375,0,0,0}},	{0,{364,365,375,0}},
{0,{0,0,0,375}},	{0,{0,0,0,375}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{375,360,359,0}},	{0,{375,359,358,0}},
{0,{357,358,375,0}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,375,0,0}},	{0,{375,0,0,0}},	{0,{375,375,375,375}},
{0,{375,375,375,375}},	{0,{375,0,375,0}},	{0,{0,0,0,375}},
{0,{375,0,0,0}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,0,0,0}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,0,0,0}},	{0,{375,0,0,0}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{375,375,375,375}},	{0,{0,0,0,375}},
{0,{375,375,375,0}},	{0,{0,0,0,375}},	{0,{375,0,0,0}},
{0,{375,375,375,375}},	{0,{375,375,375,375}},	{0,{0,0,0,375}},
{0,{375,375,375,375}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,0,0,0}},	{0,{375,0,376,0}},	{0,{376,0,375,0}},
{0,{376,377,374,0}},	{0,{377,0,373,0}},	{0,{377,0,372,0}},
{0,{373,0,371,0}},	{0,{376,0,370,0}},	{0,{376,0,369,0}},
{0,{376,0,368,0}},	{0,{376,0,367,0}},	{0,{376,0,366,0}},
{0,{376,0,365,0}},	{0,{0,0,364,0}},	{0,{0,366,363,0}},
{0,{374,0,362,0}},	{0,{374,0,361,0}},	{0,{374,0,360,0}},
{0,{374,0,359,0}},	{0,{374,0,358,0}},	{0,{374,0,357,0}},
{0,{374,0,356,0}},	{0,{374,0,355,0}},	{0,{374,0,354,0}},
{0,{374,0,353,0}},	{0,{374,0,352,0}},	{0,{374,0,351,0}},
{0,{374,0,350,0}},	{0,{374,0,349,0}},	{0,{374,0,348,0}},
{0,{374,0,347,0}},	{0,{374,0,346,0}},	{0,{374,0,345,0}},
{0,{374,0,375,0}},	{0,{375,0,374,0}},	{0,{375,345,373,0}},
{0,{374,0,372,0}},	{0,{374,0,371,0}},	{0,{374,0,339,0}},
{0,{374,0,338,0}},	{0,{374,0,337,0}},	{0,{374,0,336,0}},
{0,{374,0,335,0}},	{0,{374,0,334,0}},	{0,{374,0,333,0}},
{0,{374,0,332,0}},	{0,{374,0,331,0}},	{0,{374,0,330,0}},
{0,{374,0,329,0}},	{0,{374,0,328,0}},	{0,{374,0,327,0}},
{0,{0,0,357,0}},	{0,{373,374,0,0}},	{0,{373,373,0,0}},
{0,{373,373,374,0}},	{0,{374,371,0,0}},	{0,{346,0,0,0}},
{0,{371,371,371,0}},	{0,{372,0,0,0}},	{0,{372,367,0,0}},
{0,{372,366,0,0}},	{0,{372,366,367,0}},	{0,{372,364,0,0}},
{0,{348,0,0,0}},	{0,{346,0,0,0}},	{0,{370,363,363,0}},
{0,{370,0,0,0}},	{0,{370,370,370,370}},	{0,{370,0,0,0}},
{0,{370,0,0,0}},	{0,{370,0,0,0}},	{0,{370,371,372,0}},
{0,{370,370,371,0}},	{0,{371,369,370,0}},	{0,{305,0,369,0}},
{0,{0,0,368,0}},	{0,{309,0,367,0}},	{0,{0,368,0,0}},
{0,{368,368,0,0}},	{0,{368,0,369,0}},	{0,{369,370,368,0}},
{0,{0,0,370,0}},	{0,{370,371,366,0}},	{0,{370,370,368,0}},
{0,{370,369,367,0}},	{0,{370,0,0,0}},	{0,{370,371,371,371}},
{0,{371,0,0,0}},	{0,{371,349,349,349}},	{0,{371,372,373,372}},
{0,{373,371,374,371}},	{0,{374,0,0,0}},	{0,{0,0,0,374}},
{0,{0,0,0,374}},	{0,{0,0,0,374}},	{0,{0,0,0,374}},
{0,{0,0,0,374}},	{0,{0,0,0,374}},	{0,{0,0,0,374}},
{0,{0,0,0,374}},	{0,{0,0,0,374}},	{0,{0,0,0,374}},
{0,{0,0,0,374}},	{0,{0,0,0,374}},	{0,{0,0,0,374}},
{0,{374,0,272,0}},	{0,{374,0,271,0}},	{0,{374,0,270,0}},
{0,{374,0,269,0}},	{0,{374,0,299,0}},	{0,{374,0,267,0}},
{0,{328,0,374,0}},	{0,{374,0,375,0}},	{0,{375,0,338,0}},
{0,{375,0,376,0}},	{0,{0,0,0,376}},	{0,{376,376,376,376}},
{0,{0,0,0,376}},	{0,{0,0,0,376}},	{0,{376,0,328,0}},
{0,{376,0,0,0}},	{0,{0,0,0,376}},	{0,{0,0,0,376}},
{0,{0,0,0,376}},	{0,{0,0,0,376}},	{0,{0,0,0,376}},
{0,{0,0,0,376}},	{0,{376,0,250,0}},	{0,{376,0,249,0}},
{0,{0,0,0,376}},	{0,{376,0,247,0}},	{0,{376,0,246,0}},
{0,{376,0,276,0}},	{0,{376,0,275,0}},	{0,{350,0,317,0}},
{0,{375,0,0,0}},	{0,{0,0,0,375}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{0,0,0,375}},	{0,{0,0,0,375}},
{0,{0,0,375,0}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{0,0,0,375}},	{0,{0,0,0,375}},	{0,{0,0,0,375}},
{0,{375,0,261,0}},	{0,{375,0,0,0}},	{0,{0,0,0,375}},
{0,{375,303,298,0}},	{0,{375,302,300,0}},	{0,{0,0,0,375}},
{0,{375,0,255,0}},	{0,{375,0,375,0}},	{0,{0,0,375,0}},
{0,{375,0,374,0}},	{0,{253,0,373,0}},	{0,{0,374,293,0}},
{0,{262,373,292,0}},	{0,{373,0,291,0}},	{0,{373,374,374,0}},
{0,{373,373,373,0}},	{0,{0,0,373,0}},	{0,{373,0,372,0}},
{0,{373,373,373,374}},	{0,{373,373,374,373}},	{0,{0,0,374,0}},
{0,{371,371,371,371}},	{0,{373,373,374,0}},	{0,{0,0,0,374}},
{0,{360,0,280,0}},	{0,{373,0,279,0}},	{0,{373,362,362,0}},
{0,{373,0,374,0}},	{0,{371,360,374,0}},	{0,{371,0,360,0}},
{0,{373,0,0,0}},	{0,{373,0,0,0}},	{0,{373,0,0,0}},
{0,{0,0,0,373}},	{0,{373,373,373,0}},	{0,{373,0,359,0}},
{0,{373,0,0,0}},	{0,{373,0,0,0}},	{0,{373,0,0,0}},
{0,{200,0,0,0}},	{0,{370,372,0,0}},	{0,{370,371,0,0}},
{0,{197,371,372,0}},	{0,{0,370,371,0}},	{0,{371,0,0,0}},
{0,{0,367,0,0}},	{0,{0,366,368,0}},	{0,{369,370,0,0}},
{0,{191,369,0,0}},	{0,{369,368,0,0}},	{0,{0,367,0,0}},
{0,{368,0,0,0}},	{0,{0,0,368,0}},	{0,{247,368,247,0}},
{0,{0,368,0,0}},	{0,{368,367,0,0}},	{0,{0,0,368,0}},
{0,{0,0,368,0}},	{0,{368,363,369,0}},	{0,{369,0,370,0}},
{0,{0,0,0,370}},	{0,{0,0,0,370}},	{0,{0,0,0,370}},
{0,{0,0,0,370}},	{0,{0,0,370,0}},	{0,{370,0,0,0}},
{0,{370,0,0,0}},	{0,{370,0,0,0}},	{0,{232,0,232,0}},
{0,{0,369,0,0}},	{0,{0,0,0,369}},	{0,{369,0,0,0}},
{0,{369,369,369,369}},	{0,{369,369,369,369}},	{0,{369,369,369,369}},
{0,{369,369,369,369}},	{0,{369,369,369,369}},	{0,{369,0,0,0}},
{0,{369,369,369,369}},	{0,{369,365,365,365}},	{0,{257,0,0,0}},
{0,{368,368,368,368}},	{0,{368,368,368,0}},	{0,{368,368,368,368}},
{0,{0,0,0,368}},	{0,{0,0,0,368}},	{0,{0,0,0,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{0,0,0,368}},
{0,{0,368,0,0}},	{0,{368,0,368,0}},	{0,{0,0,0,368}},
{0,{368,368,368,368}},	{0,{368,0,0,0}},	{0,{368,0,368,0}},
{0,{368,0,0,0}},	{0,{0,368,0,0}},	{0,{0,368,0,0}},
{0,{0,0,0,368}},	{0,{0,0,0,368}},	{0,{368,0,0,0}},
{0,{0,0,0,368}},	{0,{0,368,0,0}},	{0,{0,368,0,0}},
{0,{0,0,368,0}},	{0,{0,368,0,0}},	{0,{0,367,366,0}},
{0,{0,0,367,0}},	{0,{367,367,367,367}},	{0,{367,367,367,367}},
{0,{367,0,0,0}},	{0,{367,367,367,367}},	{0,{367,0,360,0}},
{0,{367,0,0,0}},	{0,{367,0,0,0}},	{0,{0,0,0,367}},
{0,{0,0,0,367}},	{0,{367,0,355,0}},	{0,{367,0,0,0}},
{0,{0,0,0,367}},	{0,{0,0,0,367}},	{0,{367,367,367,367}},
{0,{367,367,367,367}},	{0,{367,368,369,0}},	{0,{368,0,368,0}},
{0,{368,0,367,0}},	{0,{368,369,370,0}},	{0,{370,371,372,371}},
{0,{372,367,368,0}},	{0,{372,0,0,0}},	{0,{361,361,0,0}},
{0,{364,364,371,0}},	{0,{366,366,366,366}},	{0,{370,371,370,0}},
{0,{370,370,370,0}},	{0,{370,371,372,0}},	{0,{372,373,372,362}},
{0,{0,0,373,0}},	{0,{373,0,0,0}},	{0,{373,0,0,0}},
{0,{373,0,0,0}},	{0,{373,0,0,0}},	{0,{373,373,373,0}},
{0,{373,373,373,374}},	{0,{373,373,373,373}},	{0,{373,373,373,372}},
{0,{373,373,373,0}},	{0,{373,373,373,0}},	{0,{373,0,0,0}},
{0,{373,373,373,373}},	{0,{373,373,373,373}},	{0,{373,373,373,371}},
{0,{373,370,373,370}},	{0,{373,0,373,0}},	{0,{373,373,373,369}},
{0,{373,0,0,0}},	{0,{0,0,0,373}},	{0,{373,347,374,0}},
{0,{345,346,373,0}},	{0,{373,347,374,0}},	{0,{374,349,375,338}},
{0,{0,0,375,0}},	{0,{0,0,0,375}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{0,0,0,375}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{330,330,330,375}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{330,0,375,0}},	{0,{0,0,374,0}},
{0,{374,374,374,0}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,0,0,0}},	{0,{374,0,0,0}},	{0,{374,326,326,0}},
{0,{374,0,374,0}},	{0,{374,0,374,0}},	{0,{374,0,372,0}},
{0,{374,0,371,0}},	{0,{374,0,370,0}},	{0,{374,0,369,0}},
{0,{374,0,368,0}},	{0,{374,375,376,375}},	{0,{376,374,376,374}},
{0,{374,373,374,373}},	{0,{372,372,372,372}},	{0,{374,375,363,0}},
{0,{0,0,0,375}},	{0,{0,0,0,375}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{375,0,358,0}},	{0,{375,0,357,0}},
{0,{356,0,375,0}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,0,0,0}},	{0,{375,0,0,0}},	{0,{375,375,375,375}},
{0,{375,375,375,375}},	{0,{375,0,0,0}},	{0,{0,0,0,375}},
{0,{375,0,0,0}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,0,0,0}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,0,375,0}},	{0,{375,0,374,0}},	{0,{0,0,0,375}},
{0,{0,0,0,375}},	{0,{375,375,375,375}},	{0,{0,0,0,375}},
{0,{375,375,375,0}},	{0,{0,0,0,375}},	{0,{375,0,0,0}},
{0,{375,375,375,375}},	{0,{375,375,375,375}},	{0,{0,0,0,375}},
{0,{375,375,375,375}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,0,375,0}},	{0,{375,376,377,377}},	{167,{0,0,0,0}},
{0,{376,377,0,0}},	{0,{376,376,0,0}},	{0,{376,0,0,0}},
{0,{376,0,0,0}},	{0,{376,370,371,371}},	{0,{376,369,370,370}},
{0,{376,377,369,369}},	{0,{377,377,0,0}},	{0,{377,0,0,0}},
{0,{377,365,366,366}},	{0,{377,365,365,365}},	{0,{377,364,364,364}},
{0,{377,363,363,363}},	{0,{377,362,362,362}},	{0,{377,0,0,0}},
{0,{377,360,360,360}},	{0,{377,0,0,0}},	{0,{377,0,0,0}},
{0,{377,0,0,0}},	{0,{377,378,378,0}},	{0,{378,0,0,0}},
{0,{378,379,379,0}},	{0,{379,0,0,0}},	{0,{379,374,374,0}},
{0,{379,0,0,0}},	{0,{375,375,375,0}},	{0,{378,0,0,0}},
{0,{378,370,370,0}},	{0,{378,0,0,0}},	{0,{378,379,0,0}},
{167,{379,0,379,0}},	{0,{362,377,0,0}},	{0,{0,376,0,0}},
{0,{370,375,0,0}},	{0,{376,340,341,341}},	{0,{376,342,0,0}},
{0,{376,0,0,0}},	{0,{376,346,338,338}},	{0,{376,346,0,0}},
{0,{376,336,336,336}},	{0,{376,0,0,0}},	{0,{376,376,0,0}},
{0,{376,0,0,0}},	{0,{376,0,0,0}},	{0,{331,331,331,331}},
{0,{375,0,376,0}},	{0,{351,351,351,0}},	{0,{375,0,0,0}},
{0,{375,0,0,0}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,0,0,0}},	{0,{375,0,0,0}},	{0,{369,355,0,0}},
{0,{369,354,0,0}},	{0,{369,353,0,0}},	{0,{370,352,0,0}},
{0,{368,351,0,0}},	{0,{369,350,0,0}},	{0,{369,369,369,369}},
{0,{369,370,370,0}},	{0,{369,369,369,0}},	{0,{369,368,368,0}},
{0,{369,369,370,370}},	{0,{369,369,369,369}},	{203,{0,0,0,0}},
{0,{368,368,367,367}},	{0,{368,368,0,0}},	{0,{368,0,0,0}},
{0,{368,0,368,0}},	{201,{367,0,367,0}},	{0,{367,0,366,0}},
{0,{367,0,0,0}},	{201,{0,0,0,0}},	{209,{363,0,363,0}},
{209,{0,0,0,0}},	{209,{345,0,345,0}},	{0,{0,363,0,0}},
{0,{363,362,0,0}},	{0,{362,0,0,0}},	{0,{362,360,0,0}},
{0,{347,362,347,347}},	{216,{362,0,363,0}},	{0,{0,0,363,0}},
{0,{360,0,361,0}},	{216,{362,363,361,0}},	{0,{361,362,360,0}},
{220,{0,0,0,0}},	{0,{0,0,0,361}},	{0,{0,0,0,361}},
{0,{0,0,0,361}},	{0,{0,0,0,361}},	{0,{0,0,0,361}},
{0,{0,0,0,361}},	{0,{0,0,0,361}},	{0,{0,0,0,361}},
{0,{0,0,0,361}},	{0,{361,361,361,361}},	{0,{0,0,0,361}},
{0,{0,0,0,361}},	{0,{0,0,0,361}},	{0,{361,273,274,274}},
{0,{281,281,273,273}},	{0,{360,272,272,272}},	{0,{360,0,0,0}},
{0,{0,0,360,0}},	{0,{315,0,315,0}},	{0,{359,0,0,0}},
{242,{0,0,0,0}},	{243,{0,0,0,0}},	{0,{357,357,357,0}},
{216,{357,0,357,0}},	{0,{356,0,356,0}},	{0,{0,0,0,356}},
{0,{356,356,356,356}},	{0,{0,0,0,356}},	{0,{0,0,0,356}},
{216,{320,0,320,0}},	{216,{0,0,0,0}},	{0,{0,0,0,354}},
{0,{0,0,0,354}},	{0,{0,0,0,354}},	{0,{0,0,0,354}},
{0,{0,0,0,354}},	{0,{0,0,0,354}},	{0,{0,0,0,354}},
{0,{0,0,0,354}},	{0,{0,0,0,354}},	{0,{354,0,0,0}},
{0,{354,0,0,0}},	{0,{354,0,0,0}},	{0,{0,0,354,0}},
{0,{354,354,354,0}},	{0,{0,0,0,354}},	{0,{0,0,0,354}},
{0,{0,0,0,354}},	{0,{0,0,0,354}},	{0,{0,0,0,354}},
{167,{271,0,354,0}},	{0,{354,291,355,0}},	{0,{353,290,355,0}},
{0,{0,0,0,355}},	{0,{0,0,0,355}},	{0,{0,0,0,355}},
{0,{355,0,355,0}},	{0,{0,355,0,0}},	{0,{0,0,0,355}},
{209,{355,356,355,356}},	{209,{355,355,355,355}},	{0,{0,0,0,355}},
{0,{355,0,0,0}},	{0,{0,355,0,0}},	{201,{355,355,0,0}},
{0,{355,0,0,0}},	{0,{355,355,355,0}},	{0,{355,0,355,0}},
{0,{355,356,356,0}},	{0,{355,355,355,0}},	{0,{355,0,0,0}},
{0,{355,0,0,0}},	{0,{355,355,355,356}},	{0,{355,355,355,355}},
{0,{355,354,354,354}},	{304,{0,0,0,0}},	{0,{354,354,0,0}},
{201,{353,353,0,0}},	{0,{0,0,0,353}},	{0,{353,0,0,0}},
{0,{353,344,344,0}},	{0,{353,0,0,0}},	{0,{353,0,0,0}},
{0,{353,341,341,0}},	{216,{353,0,0,0}},	{216,{353,0,0,0}},
{216,{0,0,353,0}},	{0,{0,0,0,353}},	{0,{0,353,0,0}},
{0,{353,353,0,0}},	{0,{353,0,0,0}},	{0,{353,0,0,0}},
{0,{353,354,353,353}},	{0,{354,0,0,0}},	{0,{354,0,0,0}},
{0,{354,0,0,0}},	{0,{354,0,0,0}},	{0,{354,0,0,0}},
{0,{354,0,0,0}},	{0,{354,0,0,0}},	{0,{345,345,345,345}},
{0,{0,0,353,0}},	{0,{353,0,353,0}},	{0,{353,0,353,0}},
{0,{353,0,0,0}},	{0,{353,353,353,0}},	{0,{353,353,353,0}},
{216,{249,0,242,0}},	{0,{248,0,241,0}},	{216,{250,251,0,0}},
{0,{249,250,0,0}},	{0,{0,0,0,349}},	{0,{0,0,0,349}},
{0,{0,0,0,349}},	{0,{0,0,0,349}},	{0,{349,349,349,0}},
{0,{349,0,350,0}},	{0,{350,0,349,0}},	{0,{350,224,224,0}},
{0,{350,0,337,0}},	{0,{0,0,0,350}},	{0,{350,221,221,0}},
{0,{350,350,350,350}},	{0,{350,350,350,350}},	{0,{350,350,350,350}},
{0,{350,350,350,350}},	{0,{350,350,350,350}},	{0,{350,350,350,0}},
{0,{350,350,350,350}},	{0,{350,346,350,346}},	{0,{350,350,350,350}},
{0,{350,350,0,0}},	{0,{350,350,350,350}},	{0,{0,0,0,350}},
{0,{0,0,0,350}},	{0,{0,0,0,350}},	{0,{350,350,350,350}},
{0,{350,350,350,350}},	{0,{0,0,0,350}},	{0,{350,0,350,0}},
{0,{0,350,0,0}},	{0,{0,0,0,350}},	{0,{350,350,350,350}},
{0,{350,0,350,0}},	{0,{350,0,350,0}},	{0,{350,0,0,0}},
{0,{350,0,0,0}},	{0,{350,0,0,0}},	{0,{0,0,0,350}},
{0,{0,0,0,350}},	{0,{0,350,0,0}},	{0,{0,0,0,350}},
{0,{350,0,0,0}},	{0,{0,350,0,0}},	{0,{350,350,350,350}},
{0,{350,350,350,350}},	{0,{350,350,350,350}},	{0,{350,350,350,350}},
{0,{350,350,350,350}},	{0,{350,0,0,0}},	{0,{350,350,350,350}},
{0,{350,0,0,0}},	{0,{350,0,0,0}},	{0,{350,350,350,350}},
{0,{0,0,0,350}},	{0,{0,0,0,350}},	{0,{350,350,350,350}},
{0,{0,350,0,0}},	{0,{0,0,0,350}},	{0,{0,0,0,350}},
{0,{350,350,350,350}},	{0,{350,350,350,350}},	{0,{350,350,351,350}},
{0,{0,0,351,0}},	{0,{0,0,351,0}},	{0,{0,0,351,0}},
{0,{351,346,352,346}},	{0,{352,0,353,0}},	{0,{351,0,353,0}},
{0,{353,0,347,0}},	{0,{352,0,0,0}},	{0,{351,0,344,0}},
{0,{351,340,346,340}},	{0,{339,339,339,339}},	{0,{345,0,350,0}},
{0,{0,0,350,0}},	{0,{0,0,350,0}},	{0,{350,0,351,0}},
{0,{341,0,351,0}},	{0,{340,0,351,0}},	{0,{342,0,345,0}},
{0,{341,0,345,0}},	{0,{0,0,0,349}},	{0,{349,349,349,349}},
{0,{349,349,349,349}},	{0,{349,349,349,0}},	{0,{349,349,349,0}},
{0,{349,349,349,0}},	{21,{0,0,349,0}},	{0,{0,0,348,0}},
{23,{0,0,347,0}},	{21,{0,0,0,0}},	{23,{0,0,0,0}},
{0,{345,0,345,0}},	{0,{345,0,0,0}},	{0,{345,0,0,0}},
{0,{343,0,330,0}},	{0,{344,345,0,0}},	{0,{344,344,0,0}},
{0,{341,0,327,0}},	{0,{343,343,343,343}},	{0,{343,343,0,0}},
{0,{343,0,344,0}},	{37,{0,0,322,0}},	{0,{343,0,344,0}},
{37,{314,0,325,0}},	{0,{343,0,340,0}},	{37,{315,0,318,0}},
{36,{0,0,0,323}},	{0,{0,0,341,0}},	{0,{341,0,340,0}},
{0,{0,0,341,0}},	{0,{341,0,0,0}},	{0,{341,341,341,341}},
{0,{341,330,0,0}},	{0,{307,0,341,0}},	{0,{341,0,0,0}},
{0,{341,0,0,0}},	{0,{0,0,0,341}},	{64,{0,0,0,0}},
{0,{0,0,0,340}},	{0,{0,0,0,340}},	{0,{340,340,340,340}},
{0,{0,0,340,0}},	{0,{340,340,341,0}},	{71,{0,0,0,0}},
{72,{0,0,0,0}},	{71,{339,0,340,0}},	{71,{0,0,339,0}},
{71,{339,0,338,0}},	{71,{339,0,337,0}},	{71,{339,0,336,0}},
{71,{0,0,0,339}},	{0,{0,0,0,339}},	{71,{0,0,0,339}},
{71,{0,0,0,339}},	{71,{0,0,0,339}},	{0,{0,0,0,338}},
{0,{0,0,338,0}},	{0,{338,0,337,0}},	{0,{338,0,336,0}},
{0,{337,0,0,0}},	{71,{0,0,337,0}},	{71,{337,0,336,0}},
{71,{337,337,337,337}},	{0,{337,0,0,0}},	{0,{337,337,337,337}},
{0,{0,0,337,0}},	{0,{0,0,0,337}},	{0,{337,337,337,0}},
{0,{337,337,337,0}},	{0,{337,337,337,337}},	{0,{337,0,0,0}},
{0,{337,0,0,0}},	{0,{337,0,0,0}},	{0,{337,0,0,0}},
{129,{0,0,0,0}},	{0,{336,0,0,0}},	{0,{336,0,0,0}},
{131,{0,0,0,0}},	{131,{335,0,0,0}},	{0,{335,335,335,335}},
{0,{335,0,0,0}},	{0,{335,335,335,335}},	{0,{0,0,335,0}},
{0,{335,0,335,0}},	{0,{0,0,335,0}},	{0,{335,0,0,0}},
{0,{335,335,335,335}},	{0,{335,335,335,335}},	{0,{0,335,0,0}},
{0,{0,0,0,335}},	{0,{335,0,0,0}},	{151,{0,0,0,0}},
{0,{334,0,0,0}},	{0,{334,335,336,336}},	{0,{336,0,0,0}},
{0,{336,0,0,0}},	{0,{336,337,337,337}},	{0,{337,0,0,0}},
{0,{337,337,337,337}},	{0,{337,338,0,0}},	{0,{338,339,340,340}},
{0,{340,338,339,339}},	{0,{340,338,338,338}},	{0,{340,0,0,0}},
{0,{340,0,0,0}},	{0,{331,0,0,0}},	{0,{332,339,334,334}},
{0,{339,338,333,333}},	{0,{338,331,332,332}},	{0,{338,330,331,331}},
{0,{338,330,330,330}},	{0,{338,326,0,0}},	{0,{338,316,317,317}},
{0,{320,320,320,320}},	{0,{337,323,0,0}},	{0,{337,313,314,314}},
{0,{337,338,0,0}},	{0,{336,0,0,0}},	{0,{337,321,322,322}},
{0,{337,318,0,0}},	{0,{336,0,0,0}},	{0,{318,318,319,319}},
{0,{331,315,0,0}},	{0,{317,317,317,317}},	{0,{331,321,316,316}},
{0,{332,329,0,0}},	{0,{332,332,303,303}},	{0,{302,302,302,302}},
{0,{0,0,0,331}},	{0,{0,0,0,331}},	{0,{331,0,0,0}},
{0,{331,0,0,0}},	{0,{331,0,332,0}},	{0,{332,0,0,0}},
{0,{332,0,0,0}},	{0,{332,0,0,0}},	{0,{332,0,0,0}},
{0,{332,0,0,0}},	{0,{332,0,326,0}},	{0,{0,0,0,332}},
{0,{332,0,0,0}},	{0,{332,0,0,0}},	{0,{332,332,332,332}},
{0,{332,332,332,332}},	{0,{332,332,332,332}},	{0,{332,332,332,332}},
{190,{329,329,329,329}},	{190,{0,0,0,0}},	{0,{330,330,330,330}},
{196,{330,330,330,330}},	{196,{0,0,0,0}},	{196,{329,329,0,0}},
{0,{329,0,0,0}},	{0,{329,0,0,0}},	{0,{329,0,0,0}},
{0,{329,329,329,329}},	{0,{329,329,329,329}},	{0,{329,329,329,329}},
{0,{329,329,329,329}},	{0,{329,329,329,329}},	{213,{0,0,0,0}},
{0,{328,328,328,328}},	{0,{0,0,0,328}},	{213,{315,315,315,315}},
{217,{322,322,322,322}},	{218,{321,321,321,321}},	{218,{0,0,0,0}},
{217,{0,0,0,0}},	{0,{323,323,323,323}},	{0,{323,324,0,0}},
{0,{0,323,0,0}},	{0,{323,0,0,0}},	{0,{323,323,323,323}},
{0,{0,0,0,323}},	{0,{323,0,0,0}},	{0,{323,323,0,0}},
{0,{323,323,0,0}},	{0,{0,323,0,0}},	{0,{0,0,0,323}},
{0,{323,0,323,0}},	{0,{323,0,323,0}},	{0,{323,0,0,0}},
{0,{323,0,0,0}},	{0,{323,0,0,0}},	{0,{323,323,0,0}},
{0,{0,0,0,323}},	{0,{323,323,323,323}},	{0,{323,323,323,323}},
{245,{0,0,0,0}},	{0,{322,0,0,0}},	{0,{322,0,0,0}},
{0,{322,0,0,0}},	{0,{322,0,0,0}},	{0,{322,300,0,0}},
{0,{322,299,0,0}},	{0,{322,298,0,0}},	{0,{322,322,322,322}},
{0,{322,322,322,322}},	{0,{322,0,0,0}},	{0,{0,0,322,0}},
{0,{0,0,322,0}},	{0,{322,0,322,0}},	{0,{322,235,0,0}},
{0,{322,0,0,0}},	{0,{0,0,0,322}},	{0,{0,0,0,322}},
{0,{322,0,0,0}},	{0,{322,286,0,0}},	{0,{322,285,0,0}},
{0,{320,0,0,0}},	{0,{321,0,0,0}},	{0,{321,0,0,0}},
{0,{0,0,0,321}},	{196,{0,0,0,321}},	{196,{0,0,0,321}},
{196,{0,0,0,321}},	{0,{321,321,0,0}},	{0,{321,0,0,0}},
{0,{321,321,0,0}},	{0,{0,0,0,321}},	{0,{0,0,0,321}},
{0,{321,0,0,0}},	{0,{264,264,264,321}},	{0,{0,0,0,321}},
{0,{321,0,0,0}},	{0,{0,0,0,321}},	{0,{0,321,0,0}},
{292,{0,0,0,0}},	{0,{0,320,0,0}},	{294,{0,0,0,0}},
{0,{0,0,0,319}},	{301,{248,248,248,248}},	{301,{0,0,0,0}},
{302,{0,0,0,0}},	{0,{246,246,0,0}},	{301,{315,315,315,315}},
{0,{314,314,314,314}},	{302,{313,313,313,313}},	{305,{0,0,0,0}},
{0,{312,312,0,0}},	{310,{0,0,0,0}},	{313,{0,0,0,0}},
{311,{0,0,0,0}},	{302,{0,309,0,0}},	{301,{309,309,309,309}},
{0,{0,309,0,0}},	{0,{0,309,0,0}},	{318,{0,0,0,0}},
{0,{0,0,0,308}},	{321,{0,0,0,0}},	{0,{307,0,307,0}},
{0,{307,0,308,0}},	{0,{0,0,307,0}},	{0,{307,307,307,307}},
{327,{306,306,306,306}},	{0,{306,306,306,306}},	{0,{305,305,306,305}},
{0,{306,306,306,306}},	{0,{0,0,0,306}},	{0,{177,0,306,0}},
{0,{0,0,306,0}},	{0,{0,0,304,0}},	{0,{0,0,0,305}},
{0,{305,305,305,305}},	{0,{305,305,305,305}},	{0,{305,305,305,305}},
{0,{305,0,0,0}},	{0,{0,0,305,0}},	{0,{305,305,305,305}},
{0,{305,0,305,0}},	{0,{305,303,303,303}},	{0,{305,0,0,0}},
{0,{305,0,0,0}},	{0,{163,0,305,0}},	{0,{0,305,0,0}},
{349,{0,0,0,0}},	{196,{0,304,0,0}},	{0,{292,292,304,292}},
{0,{0,304,0,0}},	{196,{304,0,304,0}},	{0,{304,305,305,0}},
{0,{305,0,0,0}},	{0,{305,0,0,0}},	{0,{305,0,0,0}},
{0,{0,0,0,305}},	{0,{0,0,0,305}},	{0,{0,0,0,305}},
{0,{305,0,0,0}},	{0,{297,297,297,0}},	{0,{304,0,0,0}},
{0,{304,304,304,304}},	{0,{0,0,304,0}},	{0,{304,0,304,0}},
{0,{303,0,304,0}},	{0,{304,304,304,304}},	{0,{304,304,304,304}},
{0,{304,0,0,0}},	{376,{0,0,0,0}},	{0,{303,303,303,303}},
{0,{303,303,0,0}},	{0,{0,0,0,303}},	{0,{303,0,0,0}},
{386,{0,0,0,0}},	{387,{0,0,0,0}},	{0,{0,0,301,0}},
{0,{0,0,301,0}},	{0,{0,0,301,0}},	{0,{0,301,0,0}},
{0,{301,301,301,0}},	{0,{301,0,0,0}},	{0,{0,0,301,0}},
{397,{0,0,0,0}},	{0,{300,0,0,0}},	{0,{300,0,0,0}},
{0,{300,0,0,0}},	{0,{0,0,0,300}},	{0,{0,300,0,0}},
{0,{300,0,0,0}},	{0,{300,0,0,0}},	{0,{300,0,0,0}},
{0,{0,0,300,0}},	{0,{0,300,0,0}},	{0,{300,0,0,0}},
{0,{0,300,0,0}},	{0,{300,0,0,0}},	{0,{0,0,300,0}},
{0,{300,0,0,0}},	{0,{300,0,0,0}},	{0,{300,300,300,300}},
{0,{300,300,300,300}},	{0,{300,300,300,300}},	{0,{300,300,300,300}},
{0,{300,300,300,300}},	{0,{300,300,300,300}},	{0,{300,300,300,300}},
{0,{300,300,300,300}},	{0,{300,300,300,300}},	{0,{300,300,300,300}},
{0,{300,300,300,300}},	{0,{300,300,300,300}},	{0,{300,300,300,300}},
{0,{294,294,294,300}},	{0,{300,300,300,300}},	{11,{290,290,290,290}},
{11,{0,0,0,0}},	{0,{298,298,298,298}},	{11,{298,298,298,298}},
{11,{295,295,295,295}},	{11,{291,291,291,291}},	{0,{296,296,296,296}},
{0,{296,0,296,0}},	{0,{296,0,296,0}},	{0,{296,296,296,0}},
{0,{296,296,296,0}},	{0,{296,296,296,296}},	{22,{0,0,0,0}},
{0,{295,295,295,0}},	{0,{295,295,295,295}},	{0,{295,295,295,295}},
{0,{295,295,295,295}},	{0,{295,295,295,295}},	{0,{295,0,0,0}},
{33,{0,0,0,0}},	{34,{0,0,0,0}},	{35,{269,269,269,269}},
{34,{278,278,278,278}},	{35,{278,278,278,278}},	{34,{273,273,273,273}},
{47,{0,0,0,0}},	{0,{288,288,288,288}},	{49,{0,0,0,0}},
{51,{0,0,0,0}},	{0,{0,0,286,0}},	{58,{0,0,0,0}},
{0,{0,0,0,285}},	{60,{0,0,0,0}},	{0,{284,0,0,0}},
{0,{284,284,284,284}},	{0,{284,284,284,284}},	{0,{284,284,284,284}},
{0,{284,0,0,0}},	{0,{284,284,284,284}},	{0,{284,284,284,284}},
{11,{283,283,283,283}},	{0,{283,0,0,0}},	{0,{283,283,283,283}},
{0,{283,283,283,283}},	{0,{283,284,284,284}},	{0,{283,283,283,283}},
{0,{283,283,283,283}},	{0,{283,283,283,283}},	{0,{283,283,283,283}},
{0,{283,283,283,283}},	{0,{283,283,283,283}},	{0,{283,0,0,0}},
{96,{283,0,0,0}},	{96,{0,0,0,0}},	{0,{282,282,282,282}},
{0,{282,282,282,282}},	{0,{0,0,282,0}},	{0,{282,0,0,0}},
{0,{282,0,0,0}},	{0,{0,0,0,282}},	{0,{0,0,282,0}},
{0,{0,0,0,282}},	{0,{282,282,282,282}},	{0,{282,0,0,0}},
{0,{282,282,282,282}},	{0,{282,282,282,282}},	{126,{282,282,282,282}},
{126,{282,281,281,281}},	{126,{0,0,0,0}},	{0,{281,281,281,281}},
{0,{281,0,0,0}},	{0,{281,0,0,0}},	{0,{274,274,281,274}},
{0,{281,0,0,0}},	{137,{0,0,0,0}},	{0,{280,280,280,280}},
{141,{0,0,0,0}},	{0,{279,0,0,0}},	{0,{0,0,279,0}},
{0,{0,279,0,0}},	{148,{0,0,0,0}},	{0,{278,278,278,278}},
{0,{278,0,0,0}},	{0,{278,278,278,278}},	{0,{278,279,280,280}},
{0,{280,281,282,283}},	{0,{283,282,282,282}},	{0,{283,283,284,284}},
{0,{284,284,284,284}},	{0,{284,285,286,286}},	{0,{286,0,0,0}},
{0,{283,283,284,284}},	{0,{285,0,0,0}},	{0,{285,285,285,285}},
{0,{0,0,285,0}},	{0,{285,268,269,269}},	{0,{285,285,272,272}},
{0,{271,271,271,271}},	{0,{284,265,266,266}},	{0,{265,265,265,265}},
{0,{271,271,271,271}},	{0,{274,274,274,274}},	{0,{264,264,265,266}},
{0,{280,281,282,282}},	{0,{282,280,281,281}},	{0,{280,280,280,280}},
{0,{281,272,272,272}},	{0,{281,277,278,278}},	{0,{281,270,270,270}},
{0,{281,272,259,259}},	{0,{281,282,281,282}},	{0,{282,0,268,0}},
{0,{282,269,256,256}},	{0,{279,279,279,279}},	{0,{281,278,277,278}},
{0,{281,266,253,253}},	{0,{281,281,281,281}},	{0,{281,281,281,281}},
{0,{281,281,282,282}},	{0,{282,282,283,283}},	{0,{283,283,283,283}},
{0,{283,283,283,283}},	{0,{278,278,278,278}},	{0,{279,279,279,279}},
{0,{281,281,281,281}},	{0,{281,281,281,281}},	{0,{281,281,281,281}},
{0,{281,281,281,281}},	{0,{281,281,281,281}},	{0,{281,281,281,281}},
{0,{281,281,281,281}},	{0,{281,237,237,237}},	{0,{281,0,0,0}},
{0,{281,282,282,0}},	{0,{281,281,281,0}},	{0,{281,281,281,281}},
{0,{281,0,0,0}},	{0,{281,0,0,0}},	{0,{281,281,282,282}},
{0,{282,282,282,282}},	{0,{280,280,280,280}},	{0,{281,0,0,0}},
{0,{281,0,281,0}},	{0,{0,281,0,0}},	{0,{281,280,0,0}},
{0,{280,0,0,0}},	{0,{0,0,0,280}},	{0,{0,0,280,0}},
{0,{0,0,0,280}},	{0,{280,280,280,280}},	{224,{0,0,0,0}},
{0,{0,0,0,279}},	{0,{279,0,0,0}},	{0,{0,0,279,0}},
{229,{0,0,0,0}},	{230,{0,0,0,0}},	{230,{277,277,277,277}},
{0,{277,277,277,277}},	{0,{0,277,0,0}},	{0,{277,0,0,0}},
{235,{0,0,0,0}},	{0,{276,276,276,276}},	{0,{208,276,209,209}},
{0,{209,276,209,209}},	{0,{276,276,276,276}},	{0,{276,276,276,276}},
{0,{276,276,276,276}},	{0,{276,276,276,276}},	{0,{276,276,276,276}},
{0,{276,276,276,276}},	{250,{0,0,0,0}},	{0,{275,0,0,0}},
{0,{275,275,275,275}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{0,275,0,0}},	{0,{0,0,275,0}},	{0,{275,275,275,275}},
{0,{0,0,0,275}},	{0,{0,0,0,275}},	{0,{0,0,0,275}},
{0,{275,197,197,197}},	{0,{275,196,196,196}},	{0,{275,275,275,275}},
{0,{275,275,275,0}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{275,275,275,275}},	{229,{274,274,274,274}},	{0,{0,274,0,0}},
{0,{274,274,274,274}},	{0,{274,274,274,274}},	{0,{274,274,274,274}},
{0,{274,274,274,274}},	{280,{0,0,0,0}},	{250,{273,273,273,273}},
{0,{273,0,273,0}},	{0,{273,273,273,273}},	{0,{273,273,273,273}},
{285,{0,0,0,0}},	{0,{272,273,272,272}},	{0,{271,271,271,271}},
{0,{272,272,272,272}},	{0,{0,0,272,0}},	{0,{0,272,0,0}},
{0,{272,0,0,0}},	{0,{272,272,272,272}},	{0,{272,0,0,0}},
{306,{0,0,0,0}},	{0,{0,271,0,0}},	{0,{0,0,0,271}},
{0,{271,272,0,0}},	{0,{0,271,0,0}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{0,271,0,0}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{0,0,0,271}},	{0,{0,0,0,271}},
{0,{0,0,0,271}},	{0,{0,0,271,0}},	{0,{0,271,0,0}},
{0,{271,271,271,0}},	{0,{271,271,271,271}},	{0,{271,0,271,0}},
{0,{0,0,0,271}},	{0,{0,0,0,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,0,0,0}},	{0,{271,0,0,0}},
{344,{269,0,0,0}},	{344,{0,0,0,0}},	{0,{269,269,269,269}},
{0,{0,0,269,0}},	{0,{0,0,269,0}},	{0,{0,0,269,0}},
{0,{0,0,0,269}},	{353,{0,0,0,0}},	{0,{0,0,0,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,0,0}},
{0,{268,268,268,268}},	{0,{268,268,268,0}},	{0,{268,268,268,268}},
{0,{268,0,0,0}},	{0,{268,0,0,0}},	{366,{0,0,0,0}},
{367,{0,0,0,0}},	{369,{0,0,0,0}},	{0,{265,265,265,265}},
{0,{265,265,265,265}},	{0,{265,265,265,265}},	{0,{0,265,0,0}},
{0,{265,0,0,0}},	{0,{265,265,265,265}},	{0,{265,265,265,265}},
{0,{0,0,0,265}},	{0,{0,0,0,265}},	{0,{265,0,0,0}},
{392,{0,0,0,0}},	{0,{0,0,0,264}},	{394,{0,0,0,0}},
{0,{0,0,0,263}},	{0,{263,263,263,263}},	{0,{263,263,263,263}},
{0,{263,263,263,263}},	{0,{263,263,263,263}},	{0,{263,263,263,263}},
{0,{263,263,263,263}},	{0,{263,263,263,263}},	{0,{263,263,263,263}},
{0,{263,263,263,263}},	{0,{263,263,263,263}},	{0,{263,263,263,263}},
{411,{0,0,0,0}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,0,0,0}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{0,0,0,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,0,0,0}},
{0,{262,262,262,262}},	{0,{260,0,0,262}},	{0,{0,0,0,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{52,{0,0,0,0}},
{0,{260,260,260,260}},	{0,{260,261,261,261}},	{0,{0,0,0,261}},
{0,{0,0,0,261}},	{0,{0,0,0,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{0,0,0,261}},	{0,{0,0,0,261}},
{0,{0,0,0,261}},	{0,{0,0,0,261}},	{0,{0,0,0,261}},
{95,{0,0,0,0}},	{0,{260,260,260,260}},	{0,{260,260,260,260}},
{0,{260,260,260,260}},	{0,{260,260,260,260}},	{0,{260,260,260,260}},
{0,{260,260,260,260}},	{0,{260,260,260,260}},	{0,{0,0,0,260}},
{0,{260,260,260,260}},	{0,{260,260,260,260}},	{0,{260,260,260,260}},
{0,{260,0,260,0}},	{0,{260,260,260,260}},	{0,{260,260,260,260}},
{0,{260,260,260,260}},	{0,{260,260,260,260}},	{0,{260,260,260,260}},
{133,{0,0,0,0}},	{0,{259,260,259,260}},	{136,{0,0,0,0}},
{0,{259,259,259,259}},	{0,{259,259,0,0}},	{145,{0,0,0,0}},
{0,{258,258,258,258}},	{0,{0,0,0,258}},	{0,{258,258,258,258}},
{0,{258,258,258,258}},	{0,{258,259,260,261}},	{0,{261,262,262,263}},
{0,{263,264,264,265}},	{0,{265,265,265,266}},	{0,{266,266,266,267}},
{0,{266,266,266,266}},	{0,{260,260,260,260}},	{0,{265,265,265,265}},
{0,{265,0,0,0}},	{0,{265,0,0,0}},	{0,{265,0,0,0}},
{0,{265,266,266,266}},	{0,{266,0,0,0}},	{0,{266,0,0,0}},
{0,{263,263,263,263}},	{0,{265,265,265,265}},	{0,{265,265,265,0}},
{0,{265,265,265,265}},	{0,{265,266,245,249}},	{0,{244,244,244,247}},
{0,{242,243,243,247}},	{0,{264,263,242,246}},	{0,{264,241,241,242}},
{0,{264,243,243,244}},	{0,{262,239,239,243}},	{0,{256,256,256,263}},
{0,{263,233,234,235}},	{0,{263,263,254,0}},	{0,{231,231,232,244}},
{0,{262,262,262,263}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{252,252,231,234}},	{0,{261,261,258,259}},	{0,{226,226,226,238}},
{0,{0,0,0,260}},	{0,{0,0,0,260}},	{0,{236,0,0,260}},
{0,{236,0,0,259}},	{0,{239,0,0,258}},	{0,{239,0,0,257}},
{0,{257,257,257,258}},	{0,{258,258,258,258}},	{0,{232,0,0,254}},
{0,{0,0,0,253}},	{0,{256,256,256,256}},	{0,{252,252,252,252}},
{0,{0,0,0,255}},	{0,{233,233,233,255}},	{0,{0,0,0,254}},
{0,{254,254,254,254}},	{0,{254,254,254,254}},	{0,{254,254,254,254}},
{0,{254,254,254,254}},	{0,{254,254,254,254}},	{0,{254,254,254,254}},
{0,{254,254,254,254}},	{0,{254,0,0,0}},	{0,{254,0,0,0}},
{0,{254,0,0,0}},	{0,{254,254,254,254}},	{0,{254,254,254,254}},
{207,{0,0,0,0}},	{0,{253,253,253,253}},	{0,{253,253,253,253}},
{0,{0,0,0,253}},	{0,{253,253,253,253}},	{0,{253,253,253,254}},
{0,{254,254,254,254}},	{227,{0,0,0,0}},	{228,{0,0,0,0}},
{0,{252,252,252,252}},	{0,{252,252,252,252}},	{0,{0,0,0,252}},
{234,{0,0,0,0}},	{0,{251,0,0,0}},	{0,{197,0,0,251}},
{0,{198,0,0,250}},	{0,{250,250,250,250}},	{0,{0,0,0,250}},
{0,{250,250,250,250}},	{0,{250,250,250,250}},	{0,{250,250,250,250}},
{0,{250,250,250,250}},	{0,{250,0,0,0}},	{0,{235,235,235,250}},
{0,{0,0,0,250}},	{0,{250,250,250,250}},	{260,{0,0,0,0}},
{261,{0,0,0,0}},	{0,{248,0,0,246}},	{0,{248,248,248,248}},
{0,{248,248,248,248}},	{0,{248,248,248,248}},	{0,{248,187,187,0}},
{0,{186,186,186,248}},	{0,{0,0,0,248}},	{0,{248,248,248,248}},
{0,{0,0,0,248}},	{0,{248,248,248,248}},	{0,{248,247,248,247}},
{273,{0,0,0,0}},	{0,{0,0,0,247}},	{0,{0,0,0,247}},
{0,{0,0,0,247}},	{0,{0,0,0,247}},	{0,{247,247,247,247}},
{282,{0,0,0,0}},	{0,{0,0,0,246}},	{0,{0,0,0,246}},
{0,{0,0,0,246}},	{207,{0,0,0,245}},	{0,{245,245,245,246}},
{0,{0,0,0,246}},	{0,{0,0,0,246}},	{0,{246,246,246,246}},
{0,{0,0,0,246}},	{303,{0,0,0,0}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{0,{245,245,245,245}},	{0,{0,0,0,203}},
{0,{244,244,244,244}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{244,244,244,244}},	{0,{244,244,244,244}},	{0,{0,0,0,244}},
{0,{244,244,244,0}},	{0,{244,244,244,244}},	{0,{0,0,0,244}},
{337,{0,0,0,0}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{343,{0,0,0,0}},	{0,{242,242,242,242}},	{0,{242,242,242,0}},
{0,{242,242,242,242}},	{0,{242,242,242,242}},	{0,{242,242,242,242}},
{0,{242,242,242,242}},	{0,{242,243,243,244}},	{0,{242,242,242,242}},
{0,{243,0,0,244}},	{0,{244,0,0,0}},	{0,{0,0,0,242}},
{0,{0,0,0,243}},	{0,{0,0,0,243}},	{0,{0,0,0,243}},
{0,{0,0,0,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{0,0,0,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{0,0,0,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{391,{0,0,0,0}},	{0,{242,242,242,242}},	{0,{242,242,242,242}},
{0,{0,0,0,242}},	{0,{242,242,242,242}},	{0,{242,242,243,242}},
{0,{0,0,0,243}},	{0,{243,0,0,0}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{0,0,0,243}},	{0,{0,0,0,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{0,0,0,243}},
{0,{0,0,0,243}},	{0,{0,0,0,243}},	{0,{0,0,0,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{0,0,0,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,0,0,0}},	{0,{0,0,243,0}},	{0,{243,0,0,0}},
{0,{243,0,0,0}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{0,243,0,0}},	{0,{0,243,0,0}},
{0,{243,0,244,0}},	{0,{244,0,0,0}},	{0,{0,0,0,244}},
{0,{0,0,0,244}},	{0,{0,0,0,244}},	{0,{244,244,244,244}},
{0,{244,244,244,244}},	{0,{244,244,244,244}},	{0,{244,0,244,0}},
{0,{244,244,244,244}},	{0,{244,244,244,244}},	{0,{244,245,244,243}},
{0,{242,244,242,242}},	{0,{0,0,0,244}},	{0,{0,0,0,244}},
{0,{0,0,0,244}},	{0,{0,0,0,244}},	{0,{0,0,0,244}},
{0,{244,244,244,0}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{0,0,0,244}},	{0,{244,244,244,0}},	{0,{244,244,244,244}},
{0,{244,244,244,0}},	{0,{0,0,0,244}},	{0,{0,244,0,0}},
{0,{244,0,0,0}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{244,244,244,0}},	{0,{244,244,244,0}},	{0,{244,244,244,0}},
{0,{244,244,0,0}},	{0,{244,244,244,0}},	{0,{244,238,244,238}},
{0,{244,0,244,0}},	{0,{244,0,244,0}},	{0,{244,244,0,0}},
{0,{244,244,244,244}},	{0,{0,0,0,244}},	{0,{0,244,0,0}},
{0,{244,244,244,0}},	{0,{244,244,245,245}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{0,{245,245,245,245}},	{0,{245,245,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,247,247}},
{0,{247,247,247,247}},	{0,{247,247,247,247}},	{0,{247,247,247,247}},
{0,{247,247,247,247}},	{0,{247,247,247,247}},	{0,{247,247,247,247}},
{0,{247,247,247,247}},	{0,{247,247,248,248}},	{0,{248,248,247,247}},
{0,{246,246,246,246}},	{0,{247,247,248,248}},	{0,{247,247,247,247}},
{0,{247,247,0,0}},	{0,{247,247,0,0}},	{0,{247,247,247,247}},
{0,{247,247,247,247}},	{0,{247,247,247,247}},	{0,{247,247,248,248}},
{0,{248,248,248,248}},	{0,{246,246,246,246}},	{0,{222,222,222,222}},
{0,{225,225,225,225}},	{0,{245,0,0,0}},	{0,{214,214,214,214}},
{0,{244,244,238,238}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{244,244,244,244}},	{0,{244,244,241,241}},	{0,{0,0,0,244}},
{0,{0,0,0,244}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{244,244,244,244}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{0,0,0,244}},	{0,{244,0,244,0}},	{0,{244,244,244,244}},
{0,{244,244,244,244}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{244,244,244,244}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{244,214,0,0}},	{0,{244,214,0,0}},	{0,{244,0,0,0}},
{0,{244,244,244,244}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{244,244,244,244}},	{0,{0,0,0,244}},	{0,{244,244,244,244}},
{0,{244,0,0,0}},	{0,{244,0,0,0}},	{0,{244,244,244,0}},
{0,{244,0,0,0}},	{0,{244,0,244,0}},	{0,{0,0,0,244}},
{0,{244,244,244,0}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{0,0,0,244}},	{0,{244,244,244,244}},	{0,{244,244,244,244}},
{0,{0,0,244,0}},	{0,{244,0,244,0}},	{0,{244,244,0,0}},
{0,{244,0,245,0}},	{0,{244,0,244,0}},	{0,{244,0,244,0}},
{0,{244,0,0,0}},	{0,{0,244,0,0}},	{0,{0,244,0,0}},
{0,{244,0,244,0}},	{0,{244,186,186,186}},	{0,{244,0,0,0}},
{0,{0,0,0,244}},	{0,{244,244,244,244}},	{0,{244,0,0,0}},
{0,{244,244,0,0}},	{0,{244,244,245,0}},	{0,{0,0,0,245}},
{0,{0,0,0,245}},	{0,{0,0,0,245}},	{0,{0,0,0,245}},
{0,{0,245,0,0}},	{0,{0,0,0,245}},	{0,{0,0,0,245}},
{0,{0,0,0,245}},	{0,{0,0,245,0}},	{0,{245,0,244,0}},
{0,{0,0,0,245}},	{0,{0,0,0,245}},	{0,{245,245,245,0}},
{0,{0,0,0,245}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{245,0,245,0}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{0,0,0,245}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{0,0,0,245}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{0,{245,245,245,245}},	{0,{245,245,245,0}},
{0,{245,0,0,0}},	{0,{245,0,0,0}},	{359,{244,0,0,0}},
{0,{244,0,0,0}},	{359,{0,0,0,0}},	{0,{243,0,0,0}},
{0,{0,0,0,243}},	{0,{0,0,0,243}},	{0,{0,0,0,243}},
{359,{149,0,149,0}},	{0,{0,242,0,0}},	{0,{242,242,242,242}},
{0,{242,0,242,0}},	{0,{242,0,0,0}},	{0,{242,0,0,0}},
{0,{242,242,242,242}},	{0,{242,242,242,242}},	{0,{0,0,0,242}},
{0,{0,242,0,0}},	{0,{242,242,242,0}},	{0,{242,242,242,0}},
{0,{242,242,242,0}},	{0,{242,242,242,0}},	{0,{242,0,242,0}},
{0,{242,0,0,0}},	{0,{242,242,242,0}},	{0,{241,241,242,0}},
{0,{0,0,0,242}},	{0,{242,0,0,0}},	{0,{242,0,0,0}},
{0,{242,0,0,0}},	{0,{242,0,0,0}},	{0,{242,0,0,0}},
{0,{242,242,242,0}},	{0,{242,0,243,0}},	{0,{0,0,243,0}},
{0,{0,0,243,0}},	{0,{243,0,0,0}},	{0,{243,0,0,0}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{13,{0,0,0,0}},
{0,{242,242,242,242}},	{0,{242,242,242,242}},	{0,{242,242,242,242}},
{0,{242,242,242,0}},	{0,{242,0,0,0}},	{0,{242,242,242,0}},
{0,{242,242,242,242}},	{0,{242,242,242,242}},	{0,{242,242,242,242}},
{0,{242,242,242,242}},	{48,{0,0,0,0}},	{0,{241,241,241,241}},
{0,{241,241,241,241}},	{0,{241,241,241,241}},	{0,{241,241,241,241}},
{0,{241,0,0,0}},	{65,{0,0,0,0}},	{65,{0,0,0,240}},
{0,{240,240,240,240}},	{0,{240,240,240,240}},	{0,{240,240,240,240}},
{0,{0,0,240,0}},	{0,{240,240,240,240}},	{0,{240,240,240,240}},
{0,{240,240,240,240}},	{0,{240,240,240,240}},	{86,{240,240,240,240}},
{90,{0,0,0,0}},	{86,{239,239,239,239}},	{86,{0,0,0,0}},
{94,{0,0,0,0}},	{0,{237,237,237,237}},	{0,{237,237,237,237}},
{0,{237,237,237,237}},	{0,{0,0,0,237}},	{0,{237,237,237,237}},
{0,{237,237,237,237}},	{0,{237,237,237,237}},	{0,{237,237,237,237}},
{0,{237,0,237,0}},	{0,{237,0,237,0}},	{0,{237,237,237,237}},
{0,{237,237,237,237}},	{0,{237,237,237,237}},	{0,{237,237,237,237}},
{0,{237,237,237,237}},	{0,{237,237,237,237}},	{0,{237,237,237,0}},
{134,{231,231,231,231}},	{134,{0,0,0,0}},	{139,{0,0,0,0}},
{0,{234,234,234,0}},	{0,{234,234,234,234}},	{0,{234,0,0,0}},
{0,{234,234,234,234}},	{0,{234,234,234,234}},	{0,{234,234,235,235}},
{0,{234,234,234,234}},	{0,{234,234,234,234}},	{0,{234,234,234,234}},
{0,{234,234,234,234}},	{0,{234,234,235,235}},	{0,{234,234,234,234}},
{0,{234,234,234,234}},	{0,{234,234,234,234}},	{0,{234,234,235,235}},
{0,{234,234,234,234}},	{0,{234,234,234,234}},	{0,{234,234,234,234}},
{0,{234,234,234,234}},	{0,{234,234,234,234}},	{0,{234,234,234,234}},
{0,{234,234,234,234}},	{0,{234,234,234,234}},	{0,{234,234,235,235}},
{0,{234,234,234,234}},	{0,{234,234,233,233}},	{0,{234,234,235,235}},
{0,{234,234,234,234}},	{0,{234,234,0,0}},	{0,{234,234,0,0}},
{0,{234,234,234,234}},	{0,{234,234,234,234}},	{0,{234,234,234,234}},
{0,{234,234,235,235}},	{0,{234,234,234,234}},	{0,{234,234,234,234}},
{0,{234,0,0,0}},	{0,{234,234,234,234}},	{0,{234,234,234,234}},
{0,{234,234,234,234}},	{0,{234,234,234,234}},	{0,{234,234,234,234}},
{177,{0,0,0,0}},	{178,{0,0,0,0}},	{0,{232,232,232,232}},
{0,{232,232,232,232}},	{0,{232,232,232,232}},	{0,{232,232,232,232}},
{0,{232,232,232,232}},	{184,{0,0,0,0}},	{0,{231,231,231,231}},
{0,{231,231,231,231}},	{0,{231,231,231,231}},	{0,{231,231,231,231}},
{0,{231,231,231,231}},	{0,{231,0,0,0}},	{0,{231,231,231,231}},
{0,{231,231,231,231}},	{0,{231,204,0,0}},	{0,{231,204,0,0}},
{0,{231,0,0,0}},	{0,{231,231,231,231}},	{0,{231,231,231,0}},
{0,{231,231,231,231}},	{0,{231,231,231,231}},	{0,{231,231,231,231}},
{0,{231,231,231,231}},	{222,{0,0,0,0}},	{223,{0,0,0,0}},
{0,{0,229,0,0}},	{231,{0,0,0,0}},	{232,{0,0,0,0}},
{0,{227,227,227,227}},	{0,{227,227,227,227}},	{0,{227,227,227,227}},
{0,{227,227,227,227}},	{238,{0,0,0,0}},	{0,{226,226,226,226}},
{0,{0,0,0,226}},	{248,{0,0,0,0}},	{249,{0,0,0,0}},
{0,{224,224,0,0}},	{257,{0,0,0,0}},	{258,{0,0,0,0}},
{259,{0,0,0,0}},	{0,{221,221,221,221}},	{0,{0,221,0,0}},
{0,{0,0,221,0}},	{265,{0,0,0,0}},	{0,{220,220,220,220}},
{0,{220,220,0,0}},	{268,{0,0,0,0}},	{0,{0,219,0,0}},
{0,{219,219,219,219}},	{271,{0,0,0,0}},	{271,{218,218,218,218}},
{0,{217,217,217,217}},	{274,{0,0,0,0}},	{275,{0,0,0,0}},
{276,{0,0,0,0}},	{278,{0,0,0,0}},	{281,{0,0,0,0}},
{283,{0,0,0,0}},	{0,{211,0,0,0}},	{287,{0,0,0,0}},
{288,{0,0,0,0}},	{289,{0,0,0,0}},	{0,{208,208,208,208}},
{0,{0,0,0,208}},	{0,{208,208,208,208}},	{0,{208,208,208,208}},
{0,{208,208,208,208}},	{0,{208,208,208,208}},	{0,{208,208,208,208}},
{0,{208,208,208,208}},	{0,{208,0,208,0}},	{0,{208,208,208,208}},
{0,{208,208,208,208}},	{0,{208,208,208,208}},	{0,{208,208,208,208}},
{0,{208,208,208,208}},	{0,{208,208,208,208}},	{0,{208,208,208,208}},
{0,{208,208,208,208}},	{0,{208,208,208,208}},	{336,{0,0,0,0}},
{0,{207,207,207,207}},	{0,{207,207,207,207}},	{0,{207,207,207,207}},
{0,{207,207,207,207}},	{0,{207,207,207,207}},	{0,{207,207,207,207}},
{0,{207,207,207,207}},	{0,{207,207,207,207}},	{0,{207,207,207,207}},
{0,{207,207,207,207}},	{0,{207,207,207,207}},	{356,{207,208,208,0}},
{0,{208,0,0,0}},	{356,{206,206,206,0}},	{356,{0,0,0,0}},
{0,{206,0,0,0}},	{0,{0,206,0,0}},	{0,{206,0,0,0}},
{0,{206,0,0,0}},	{0,{206,206,206,206}},	{372,{0,0,0,0}},
{0,{205,205,205,0}},	{375,{0,0,0,0}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{0,0,204,0}},	{385,{0,0,0,0}},
{0,{203,203,203,203}},	{0,{203,203,203,203}},	{0,{203,203,203,203}},
{0,{203,203,203,203}},	{0,{203,203,203,203}},	{0,{0,0,0,203}},
{0,{203,203,203,203}},	{0,{203,203,203,203}},	{0,{203,0,0,0}},
{0,{0,0,0,203}},	{0,{203,203,203,203}},	{405,{0,0,0,0}},
{0,{202,202,202,202}},	{0,{202,202,202,202}},	{0,{202,202,202,202}},
{409,{0,0,0,0}},	{410,{0,0,0,0}},	{0,{0,0,200,0}},
{0,{200,200,200,200}},	{0,{0,0,200,0}},	{416,{0,0,0,0}},
{0,{199,0,0,0}},	{0,{199,0,199,0}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{66,{0,0,0,0}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{0,{198,198,198,198}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{0,{198,198,198,198}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{0,{198,198,198,198}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{0,{198,198,198,198}},
{0,{198,198,198,198}},	{0,{0,0,0,198}},	{0,{198,198,198,198}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{0,{198,198,198,198}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{0,{198,198,198,198}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{0,{198,198,198,198}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{0,{198,198,198,198}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{0,{198,0,198,0}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{0,{198,198,198,199}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{199,199,199,200}},	{0,{200,200,200,200}},
{0,{200,200,200,200}},	{0,{200,200,200,200}},	{0,{200,200,200,201}},
{0,{200,200,200,200}},	{0,{200,200,200,200}},	{0,{200,200,200,200}},
{0,{200,200,200,200}},	{0,{200,200,200,200}},	{0,{200,200,200,200}},
{0,{200,200,200,200}},	{0,{200,200,200,200}},	{0,{200,200,200,201}},
{0,{201,201,201,201}},	{0,{201,201,201,200}},	{0,{201,201,201,202}},
{0,{202,202,202,202}},	{0,{202,202,202,203}},	{0,{203,203,203,0}},
{0,{203,203,203,203}},	{0,{203,203,203,203}},	{0,{203,203,203,203}},
{0,{203,203,203,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,0}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,175,175,176}},	{0,{204,176,176,0}},
{0,{204,0,0,0}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{0,0,0,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,0,0}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{0,0,0,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{0,{204,204,204,204}},
{0,{204,204,204,204}},	{0,{204,204,204,204}},	{357,{0,0,0,204}},
{357,{0,0,0,0}},	{0,{0,0,0,202}},	{0,{202,202,202,202}},
{0,{202,202,202,202}},	{0,{202,202,202,202}},	{0,{0,0,0,202}},
{0,{202,202,202,202}},	{0,{202,202,202,202}},	{0,{202,202,202,202}},
{0,{202,202,202,202}},	{384,{0,0,0,0}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{0,0,0,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{0,0,0,201}},	{0,{0,0,0,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,0}},	{0,{201,201,201,0}},	{0,{201,201,201,0}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{0,0,0,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,0,0,0}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,0,0,0}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{0,0,0,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,0}},	{0,{201,201,201,0}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,0,0,0}},
{0,{201,0,0,0}},	{0,{201,201,201,201}},	{0,{201,0,201,0}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,202}},
{0,{202,202,202,201}},	{0,{200,200,200,200}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,202}},
{0,{202,202,202,201}},	{0,{200,200,200,200}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,202}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,202}},	{0,{202,202,202,201}},
{0,{200,200,200,200}},	{0,{201,201,201,199}},	{0,{201,201,201,202}},
{0,{202,202,202,201}},	{0,{200,200,200,200}},	{0,{201,201,201,0}},
{0,{201,201,201,0}},	{0,{201,201,201,0}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,202}},
{0,{202,202,202,201}},	{0,{200,200,200,200}},	{0,{201,201,201,201}},
{0,{201,0,0,0}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,0,0,0}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,202}},	{0,{202,202,202,201}},
{0,{200,200,200,200}},	{0,{201,201,201,201}},	{0,{201,201,0,0}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,0,0,0}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{0,0,0,201}},	{0,{201,201,0,0}},
{0,{201,201,201,201}},	{0,{0,0,0,201}},	{0,{0,0,0,201}},
{0,{201,201,201,201}},	{0,{201,201,201,0}},	{0,{201,201,201,0}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{0,201,0,0}},
{0,{201,201,201,201}},	{0,{0,0,0,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,0}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{0,0,201,0}},	{0,{0,0,201,0}},	{0,{201,0,0,0}},
{0,{201,0,0,0}},	{0,{201,201,201,201}},	{0,{201,201,201,0}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{0,0,0,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,0,201,0}},	{0,{0,0,0,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,0,0,0}},	{0,{201,0,201,0}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{195,195,195,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,0}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,0}},	{19,{0,0,0,0}},	{0,{200,200,200,0}},
{0,{200,200,200,200}},	{0,{200,200,200,200}},	{0,{200,200,200,200}},
{0,{200,200,200,200}},	{0,{0,0,0,200}},	{0,{200,200,201,0}},
{0,{200,200,200,0}},	{0,{200,200,0,0}},	{63,{0,0,0,0}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,0}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,198}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{0,0,199,0}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{0,{0,0,199,0}},	{0,{199,199,199,0}},
{0,{199,0,199,0}},	{0,{0,0,0,199}},	{0,{199,199,199,0}},
{0,{0,0,0,199}},	{0,{199,199,199,199}},	{0,{199,0,0,0}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{198,199,198,198}},	{0,{199,199,199,199}},	{0,{199,0,0,0}},
{0,{199,0,0,0}},	{0,{199,0,0,0}},	{0,{199,199,199,199}},
{0,{199,0,0,0}},	{0,{199,199,199,199}},	{0,{199,200,200,201}},
{0,{201,202,202,202}},	{0,{202,203,203,201}},	{0,{203,204,204,204}},
{0,{204,205,205,205}},	{0,{205,206,206,206}},	{0,{206,206,206,207}},
{0,{207,207,207,207}},	{0,{207,207,207,206}},	{0,{200,200,200,200}},
{0,{206,206,206,206}},	{0,{206,206,206,206}},	{0,{206,206,206,206}},
{0,{206,206,206,206}},	{0,{197,197,197,197}},	{0,{205,206,206,206}},
{0,{206,207,207,207}},	{0,{204,204,204,204}},	{0,{205,205,205,205}},
{0,{205,200,200,200}},	{0,{205,205,205,206}},	{0,{206,206,206,206}},
{0,{206,206,206,205}},	{0,{203,203,203,203}},	{0,{205,206,206,207}},
{0,{207,0,0,0}},	{0,{207,208,208,0}},	{0,{203,203,203,204}},
{0,{206,206,206,0}},	{0,{202,202,202,202}},	{0,{205,205,205,205}},
{0,{205,205,205,205}},	{0,{205,205,205,205}},	{0,{167,167,167,168}},
{0,{169,169,169,169}},	{0,{170,170,170,168}},	{0,{171,171,171,171}},
{0,{201,0,0,0}},	{0,{201,198,198,198}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,198,198,198}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{0,{201,201,201,201}},	{0,{201,201,201,201}},
{0,{201,201,201,201}},	{193,{0,0,0,0}},	{0,{200,200,200,200}},
{0,{200,200,200,200}},	{0,{200,200,200,201}},	{0,{201,201,201,201}},
{0,{199,199,199,199}},	{0,{200,0,0,0}},	{0,{200,200,200,0}},
{0,{200,200,0,0}},	{0,{0,0,0,200}},	{0,{200,200,200,200}},
{0,{0,0,0,200}},	{225,{0,0,0,0}},	{0,{199,0,199,0}},
{0,{199,199,199,199}},	{0,{199,199,199,199}},	{0,{199,199,199,199}},
{0,{199,199,199,199}},	{244,{0,0,0,0}},	{0,{198,198,198,0}},
{0,{198,198,198,198}},	{0,{0,0,0,198}},	{0,{0,0,0,198}},
{0,{160,160,198,160}},	{0,{198,0,0,0}},	{0,{198,198,198,0}},
{0,{198,198,198,198}},	{0,{198,198,198,198}},	{284,{0,0,0,0}},
{0,{197,197,197,0}},	{0,{0,0,0,197}},	{0,{197,197,197,0}},
{0,{197,197,197,197}},	{0,{197,197,197,197}},	{0,{0,0,0,197}},
{0,{197,197,197,197}},	{0,{197,197,197,197}},	{319,{0,0,0,0}},
{0,{196,196,196,196}},	{0,{196,196,196,196}},	{0,{196,196,196,196}},
{0,{0,0,0,196}},	{0,{0,0,0,196}},	{0,{0,0,0,196}},
{0,{196,196,196,196}},	{0,{196,196,196,196}},	{0,{196,196,196,196}},
{0,{0,0,0,196}},	{0,{0,0,0,196}},	{0,{196,196,196,196}},
{0,{196,196,196,196}},	{0,{196,196,196,196}},	{0,{196,196,196,196}},
{0,{196,196,196,196}},	{0,{196,196,196,196}},	{0,{196,196,196,196}},
{0,{0,0,0,196}},	{0,{0,0,0,196}},	{0,{196,196,196,196}},
{0,{0,196,0,0}},	{362,{0,0,0,0}},	{0,{0,0,195,0}},
{0,{195,0,0,0}},	{0,{195,195,195,195}},	{373,{0,0,0,0}},
{0,{194,194,194,0}},	{0,{194,194,194,194}},	{0,{0,0,0,194}},
{0,{0,0,0,194}},	{0,{0,0,0,194}},	{0,{0,0,0,194}},
{0,{194,194,194,194}},	{0,{194,194,194,194}},	{0,{194,194,194,194}},
{0,{194,194,194,194}},	{402,{0,0,0,0}},	{0,{193,193,193,193}},
{0,{193,193,193,193}},	{0,{193,193,193,193}},	{0,{193,193,193,193}},
{0,{193,193,193,193}},	{0,{193,193,193,193}},	{0,{193,193,193,193}},
{0,{193,193,193,193}},	{0,{193,0,0,0}},	{420,{0,0,0,0}},
{0,{192,192,192,192}},	{0,{192,192,192,192}},	{0,{192,192,192,192}},
{0,{192,192,192,192}},	{0,{192,192,192,192}},	{0,{192,192,192,192}},
{0,{192,192,192,192}},	{0,{192,192,192,192}},	{0,{192,192,192,192}},
{0,{192,192,192,192}},	{0,{192,192,192,192}},	{0,{186,186,186,192}},
{0,{192,192,192,192}},	{0,{192,192,192,192}},	{0,{192,192,192,192}},
{0,{192,192,192,192}},	{0,{192,192,192,192}},	{0,{192,192,192,192}},
{0,{192,192,192,192}},	{0,{192,192,192,192}},	{0,{192,192,192,192}},
{0,{192,192,192,192}},	{0,{192,192,192,192}},	{0,{192,192,192,192}},
{0,{0,0,0,192}},	{61,{192,192,192,192}},	{0,{191,191,191,191}},
{61,{0,0,0,0}},	{0,{190,190,190,190}},	{0,{190,190,190,190}},
{0,{190,190,190,190}},	{0,{190,190,190,190}},	{0,{190,190,190,190}},
{0,{190,190,190,190}},	{0,{190,190,190,190}},	{0,{190,190,190,190}},
{0,{190,190,190,190}},	{0,{190,190,190,190}},	{97,{0,0,0,0}},
{0,{189,189,189,189}},	{0,{189,189,189,189}},	{101,{0,0,0,0}},
{0,{188,188,188,188}},	{0,{188,0,188,0}},	{0,{0,0,0,188}},
{0,{188,188,188,188}},	{0,{0,0,0,188}},	{0,{188,188,188,188}},
{0,{0,0,0,188}},	{0,{188,188,188,188}},	{0,{188,188,188,188}},
{0,{188,188,188,188}},	{0,{188,188,188,188}},	{0,{188,188,188,188}},
{0,{188,188,188,188}},	{0,{0,0,0,188}},	{146,{0,0,0,0}},
{0,{187,187,187,187}},	{0,{187,187,187,187}},	{0,{187,187,187,187}},
{0,{187,187,188,189}},	{0,{189,189,187,188}},	{0,{189,189,190,191}},
{0,{191,191,192,193}},	{0,{193,193,191,192}},	{0,{193,193,194,195}},
{0,{195,195,193,194}},	{0,{195,195,196,197}},	{0,{197,197,195,196}},
{0,{197,197,194,195}},	{0,{193,193,193,194}},	{0,{196,196,197,197}},
{0,{196,196,196,196}},	{0,{175,175,175,176}},	{0,{178,178,178,179}},
{0,{180,180,180,181}},	{0,{183,183,183,184}},	{0,{192,192,192,192}},
{0,{175,175,175,175}},	{0,{177,177,177,177}},	{0,{184,184,184,184}},
{0,{189,185,182,183}},	{0,{189,181,181,182}},	{0,{189,190,181,181}},
{0,{190,180,180,180}},	{0,{188,188,179,179}},	{0,{189,189,189,189}},
{0,{189,189,189,189}},	{0,{189,189,189,189}},	{0,{189,189,189,189}},
{0,{189,189,190,190}},	{0,{189,189,189,189}},	{0,{189,189,189,189}},
{0,{189,189,0,0}},	{0,{189,189,190,190}},	{0,{189,189,189,189}},
{0,{0,0,0,189}},	{0,{189,189,189,189}},	{0,{189,189,189,189}},
{0,{189,189,189,189}},	{0,{186,186,186,189}},	{0,{189,189,189,189}},
{0,{189,189,189,189}},	{0,{0,0,0,189}},	{0,{186,186,186,189}},
{0,{189,189,189,189}},	{0,{189,189,189,189}},	{0,{189,189,189,189}},
{0,{189,189,189,189}},	{0,{189,189,189,189}},	{0,{189,189,189,189}},
{0,{153,153,153,189}},	{0,{0,0,0,189}},	{0,{189,189,189,190}},
{0,{188,188,188,188}},	{0,{189,189,0,0}},	{0,{189,189,189,189}},
{0,{189,189,189,189}},	{0,{189,189,189,189}},	{0,{189,189,189,189}},
{204,{0,0,0,0}},	{0,{188,188,188,188}},	{0,{188,188,188,188}},
{0,{0,0,0,188}},	{0,{188,188,188,188}},	{0,{0,0,0,188}},
{233,{0,0,0,0}},	{0,{187,187,187,187}},	{0,{187,187,187,187}},
{0,{187,187,187,187}},	{0,{187,187,187,187}},	{0,{187,187,187,187}},
{0,{187,187,187,187}},	{0,{0,0,0,187}},	{0,{0,0,0,187}},
{0,{187,187,187,187}},	{0,{187,187,187,187}},	{269,{0,0,0,0}},
{0,{186,186,186,186}},	{0,{186,186,186,186}},	{0,{186,186,186,186}},
{0,{186,186,186,186}},	{0,{186,186,186,186}},	{0,{186,186,186,186}},
{0,{186,186,186,186}},	{0,{0,0,0,186}},	{0,{186,186,186,186}},
{0,{186,186,186,186}},	{0,{186,186,186,186}},	{0,{186,186,186,186}},
{0,{186,186,186,186}},	{0,{0,0,0,186}},	{0,{0,0,0,186}},
{0,{0,0,0,186}},	{0,{186,186,186,186}},	{0,{186,186,186,186}},
{0,{186,186,186,186}},	{0,{0,0,0,186}},	{0,{0,0,0,186}},
{0,{186,186,186,186}},	{0,{186,186,186,186}},	{0,{0,186,0,0}},
{0,{186,186,186,186}},	{0,{186,186,186,186}},	{0,{186,186,186,186}},
{0,{186,186,186,186}},	{0,{0,0,0,186}},	{0,{0,0,0,186}},
{0,{186,186,186,186}},	{361,{0,0,0,0}},	{363,{0,0,0,0}},
{0,{0,0,0,184}},	{0,{0,0,0,184}},	{378,{0,0,0,0}},
{0,{183,183,0,0}},	{0,{0,0,0,183}},	{0,{0,0,0,183}},
{0,{0,0,0,183}},	{0,{0,0,0,183}},	{0,{183,183,183,183}},
{0,{183,183,183,183}},	{0,{183,183,183,183}},	{0,{183,183,183,183}},
{0,{183,183,183,183}},	{0,{183,183,183,183}},	{0,{183,183,183,183}},
{0,{183,183,183,183}},	{0,{183,183,183,183}},	{0,{183,183,183,183}},
{0,{183,183,183,183}},	{0,{183,183,183,183}},	{0,{0,0,0,183}},
{0,{183,183,183,183}},	{0,{183,183,183,184}},	{0,{0,0,0,184}},
{0,{184,184,184,184}},	{0,{183,183,183,184}},	{0,{184,184,184,178}},
{0,{184,184,184,179}},	{0,{184,184,184,0}},	{0,{184,184,184,178}},
{0,{184,184,184,178}},	{0,{0,0,0,184}},	{0,{178,178,178,184}},
{0,{180,180,180,0}},	{0,{178,178,178,183}},	{0,{179,179,179,183}},
{0,{183,183,183,183}},	{0,{183,183,183,183}},	{0,{0,0,0,183}},
{0,{183,183,183,183}},	{0,{183,183,183,183}},	{0,{183,183,183,183}},
{0,{183,183,183,183}},	{0,{183,183,183,183}},	{0,{0,0,0,183}},
{0,{0,0,0,183}},	{0,{0,0,0,183}},	{0,{0,0,0,183}},
{0,{0,0,0,183}},	{0,{0,0,0,183}},	{0,{0,0,0,183}},
{0,{0,0,0,183}},	{0,{0,0,0,183}},	{0,{0,0,0,183}},
{0,{0,0,0,183}},	{0,{183,183,183,183}},	{0,{183,183,183,183}},
{0,{0,0,0,183}},	{0,{0,0,0,183}},	{0,{183,183,183,183}},
{0,{0,0,0,183}},	{0,{0,0,0,183}},	{0,{0,0,0,183}},
{121,{0,0,0,0}},	{0,{182,182,182,182}},	{0,{182,182,182,182}},
{0,{0,0,0,182}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{182,182,182,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{182,183,182,184}},	{0,{184,185,184,186}},
{0,{184,184,184,185}},	{0,{185,186,185,187}},	{0,{187,188,187,186}},
{0,{188,189,188,182}},	{0,{188,188,188,181}},	{0,{188,189,188,177}},
{0,{189,190,189,179}},	{0,{189,189,189,178}},	{0,{189,190,189,180}},
{0,{190,191,190,173}},	{0,{191,192,191,175}},	{0,{191,191,191,174}},
{0,{191,192,191,176}},	{0,{180,181,180,181}},	{0,{181,182,181,182}},
{0,{181,181,181,181}},	{0,{181,182,181,182}},	{0,{188,189,188,189}},
{0,{189,189,189,188}},	{0,{189,189,189,177}},	{0,{189,189,189,190}},
{0,{190,191,190,191}},	{0,{191,192,191,192}},	{0,{189,189,189,189}},
{0,{182,182,182,182}},	{0,{189,189,189,189}},	{0,{189,189,189,190}},
{0,{190,190,190,189}},	{0,{0,0,0,188}},	{0,{189,189,189,187}},
{0,{189,189,189,190}},	{0,{184,184,184,0}},	{0,{185,185,185,0}},
{0,{187,187,187,187}},	{0,{187,187,187,186}},	{0,{183,183,183,0}},
{0,{186,186,186,186}},	{0,{0,0,0,186}},	{0,{0,0,0,186}},
{0,{0,0,0,186}},	{0,{0,0,0,186}},	{0,{0,0,0,186}},
{0,{0,0,0,186}},	{0,{0,0,0,186}},	{0,{0,0,0,186}},
{0,{186,186,186,186}},	{0,{0,0,0,186}},	{0,{184,184,184,186}},
{0,{0,0,0,186}},	{0,{186,186,186,186}},	{0,{0,0,0,186}},
{0,{186,186,186,186}},	{0,{186,186,186,186}},	{0,{186,186,186,186}},
{0,{186,186,186,186}},	{0,{0,0,0,186}},	{0,{0,0,0,186}},
{0,{186,186,186,187}},	{0,{187,187,187,186}},	{0,{185,185,185,185}},
{0,{186,186,186,186}},	{0,{186,186,186,186}},	{214,{0,0,0,0}},
{0,{0,0,0,185}},	{219,{0,0,0,0}},	{0,{0,0,0,184}},
{0,{184,184,184,184}},	{0,{0,0,0,184}},	{0,{184,184,184,184}},
{0,{0,0,0,184}},	{0,{0,0,0,184}},	{0,{0,0,0,184}},
{0,{0,0,0,184}},	{0,{0,0,0,184}},	{0,{0,0,0,184}},
{0,{0,0,0,184}},	{0,{0,0,0,184}},	{0,{0,0,0,184}},
{0,{184,184,184,184}},	{0,{0,0,0,184}},	{0,{184,184,184,184}},
{0,{0,0,0,184}},	{0,{0,0,0,184}},	{0,{0,0,0,184}},
{0,{0,0,0,184}},	{0,{184,184,184,184}},	{0,{184,184,184,184}},
{0,{184,184,184,184}},	{329,{0,0,0,0}},	{329,{0,0,0,183}},
{331,{0,0,0,0}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{338,{0,0,0,0}},	{339,{0,0,0,0}},
{0,{180,180,180,180}},	{0,{180,180,180,180}},	{0,{0,0,0,180}},
{0,{180,180,180,180}},	{0,{0,0,0,180}},	{0,{0,0,0,180}},
{0,{180,180,180,180}},	{338,{0,0,0,180}},	{0,{0,0,0,180}},
{0,{180,180,180,180}},	{0,{180,180,180,180}},	{365,{0,0,0,0}},
{0,{0,0,0,179}},	{0,{0,0,0,179}},	{0,{0,0,0,179}},
{0,{0,0,0,179}},	{0,{0,0,0,179}},	{0,{0,0,0,179}},
{0,{179,179,179,179}},	{0,{179,179,179,179}},	{0,{179,179,179,179}},
{0,{179,179,179,179}},	{0,{179,179,179,179}},	{0,{0,0,0,179}},
{0,{0,0,0,179}},	{0,{0,0,0,179}},	{0,{0,0,0,179}},
{0,{0,0,0,179}},	{0,{179,179,179,179}},	{0,{179,179,179,179}},
{0,{179,0,0,0}},	{0,{179,180,180,180}},	{0,{180,179,179,179}},
{0,{180,0,0,0}},	{0,{177,177,177,177}},	{0,{176,176,176,179}},
{0,{179,0,0,0}},	{0,{179,174,174,174}},	{0,{179,0,0,0}},
{0,{179,0,0,0}},	{0,{179,171,171,171}},	{0,{0,0,0,179}},
{0,{179,0,0,0}},	{0,{179,0,0,0}},	{0,{179,167,167,167}},
{0,{179,179,0,0}},	{0,{179,179,179,179}},	{0,{0,0,0,179}},
{0,{179,179,179,179}},	{0,{179,179,179,179}},	{0,{179,179,179,179}},
{0,{179,179,179,179}},	{0,{179,179,179,179}},	{0,{0,0,0,179}},
{0,{0,0,0,179}},	{0,{0,0,0,179}},	{0,{179,0,0,0}},
{0,{0,0,0,179}},	{0,{179,0,0,0}},	{0,{0,0,0,179}},
{0,{0,0,0,179}},	{0,{0,0,0,179}},	{0,{0,0,0,179}},
{0,{0,0,0,179}},	{0,{179,0,0,0}},	{0,{179,0,0,0}},
{0,{0,0,0,179}},	{0,{0,0,0,179}},	{0,{179,0,0,0}},
{0,{0,0,0,179}},	{0,{0,0,0,179}},	{0,{0,0,0,179}},
{0,{179,179,179,179}},	{0,{179,179,179,179}},	{0,{0,0,0,179}},
{0,{0,0,0,179}},	{0,{0,0,0,179}},	{0,{0,0,0,179}},
{0,{0,0,0,179}},	{0,{0,0,0,179}},	{0,{179,0,0,0}},
{0,{179,179,179,179}},	{0,{0,0,0,179}},	{0,{0,0,0,179}},
{0,{179,180,181,0}},	{0,{181,179,180,0}},	{0,{181,182,0,0}},
{0,{182,183,178,0}},	{0,{177,182,177,0}},	{0,{182,183,0,0}},
{0,{183,180,175,0}},	{0,{183,179,174,0}},	{0,{183,180,0,0}},
{0,{183,184,185,0}},	{0,{185,183,184,0}},	{0,{185,182,183,0}},
{0,{182,181,182,0}},	{0,{184,171,0,0}},	{0,{184,170,0,0}},
{0,{184,173,0,0}},	{0,{0,172,0,0}},	{0,{183,171,0,0}},
{0,{183,170,0,0}},	{0,{183,184,185,0}},	{0,{185,183,184,0}},
{0,{185,186,183,0}},	{0,{182,185,182,0}},	{0,{185,184,181,0}},
{0,{185,183,180,0}},	{0,{185,159,0,0}},	{0,{185,158,0,0}},
{0,{185,157,0,0}},	{0,{185,160,0,0}},	{0,{185,159,0,0}},
{0,{185,158,0,0}},	{0,{185,186,187,187}},	{0,{187,185,186,186}},
{0,{187,188,185,185}},	{0,{184,187,184,184}},	{0,{146,146,146,0}},
{0,{151,0,0,0}},	{0,{157,157,157,0}},	{0,{166,166,166,0}},
{0,{183,183,142,0}},	{0,{171,171,0,0}},	{0,{182,182,163,0}},
{0,{182,182,182,0}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{182,182,182,182}},	{0,{0,0,0,182}},	{0,{180,180,180,182}},
{0,{0,0,0,182}},	{0,{182,0,182,0}},	{0,{0,0,0,182}},
{0,{182,183,182,182}},	{0,{181,181,181,181}},	{0,{182,0,182,0}},
{0,{182,179,182,179}},	{0,{182,0,0,0}},	{0,{0,0,0,182}},
{0,{182,182,182,183}},	{0,{182,182,182,182}},	{0,{182,182,182,181}},
{0,{182,182,182,182}},	{0,{182,182,182,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{145,0,0,0}},	{0,{0,0,0,181}},
{0,{181,181,181,0}},	{0,{0,0,0,181}},	{0,{0,0,0,181}},
{0,{0,0,181,0}},	{0,{0,0,181,0}},	{0,{0,0,0,181}},
{0,{0,0,0,181}},	{0,{0,0,0,181}},	{0,{0,0,0,181}},
{0,{0,0,0,181}},	{0,{181,181,181,181}},	{0,{0,0,0,181}},
{0,{181,0,0,0}},	{0,{0,0,0,181}},	{0,{181,0,0,0}},
{0,{0,0,0,181}},	{0,{0,0,0,181}},	{0,{181,181,181,181}},
{0,{181,0,0,0}},	{0,{0,0,181,0}},	{0,{0,0,0,181}},
{0,{0,0,0,181}},	{0,{0,0,0,181}},	{0,{0,0,0,181}},
{0,{181,181,181,181}},	{0,{181,181,181,181}},	{0,{0,0,0,181}},
{0,{181,181,181,181}},	{0,{0,0,0,181}},	{0,{0,0,0,181}},
{0,{0,0,0,181}},	{0,{0,0,0,181}},	{0,{0,0,0,181}},
{0,{181,181,181,181}},	{0,{181,181,181,0}},	{0,{0,0,0,181}},
{0,{0,0,0,181}},	{0,{0,0,0,181}},	{0,{0,0,0,181}},
{0,{0,0,0,181}},	{0,{0,0,0,181}},	{0,{181,181,181,181}},
{0,{181,181,181,181}},	{0,{181,181,181,181}},	{0,{181,181,181,181}},
{0,{181,181,181,181}},	{0,{0,0,0,181}},	{0,{0,0,0,181}},
{0,{0,0,0,181}},	{0,{0,0,0,181}},	{0,{0,0,0,181}},
{0,{181,181,181,181}},	{0,{181,181,181,181}},	{0,{0,0,181,0}},
{0,{181,181,182,181}},	{0,{180,180,180,180}},	{0,{181,181,182,179}},
{0,{182,182,182,0}},	{0,{177,177,177,182}},	{0,{182,182,183,0}},
{0,{183,183,184,175}},	{0,{180,180,180,0}},	{0,{183,183,183,0}},
{0,{180,180,180,172}},	{0,{0,0,0,182}},	{0,{182,0,169,0}},
{0,{182,0,0,0}},	{0,{182,168,168,168}},	{0,{182,182,0,0}},
{0,{182,182,182,182}},	{0,{0,0,0,182}},	{0,{182,182,182,182}},
{0,{182,182,182,182}},	{0,{182,182,182,182}},	{0,{182,182,182,182}},
{0,{182,182,182,182}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{182,0,0,0}},	{0,{0,0,0,182}},
{0,{182,0,0,0}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{182,0,183,0}},	{0,{182,0,182,0}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{182,0,0,0}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{0,0,0,182}},	{0,{182,182,182,182}},
{0,{182,182,182,182}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{0,0,0,182}},	{0,{0,0,0,182}},
{0,{0,0,0,182}},	{0,{182,0,0,0}},	{0,{182,182,182,182}},
{0,{0,0,0,182}},	{0,{0,0,0,182}},	{0,{182,183,184,0}},
{0,{182,182,184,0}},	{0,{182,182,182,0}},	{0,{183,180,181,0}},
{0,{183,184,185,185}},	{0,{185,185,186,0}},	{0,{186,178,178,0}},
{0,{177,177,178,0}},	{0,{181,181,181,181}},	{0,{0,0,182,0}},
{0,{183,174,174,0}},	{0,{183,173,173,0}},	{0,{183,177,177,177}},
{0,{183,184,184,0}},	{0,{183,183,184,0}},	{0,{182,182,182,0}},
{0,{183,181,181,0}},	{0,{183,180,180,0}},	{0,{183,172,0,0}},
{0,{183,171,0,0}},	{0,{183,0,0,0}},	{0,{183,0,0,0}},
{0,{183,0,0,0}},	{0,{183,184,185,0}},	{0,{183,183,185,0}},
{0,{183,183,183,0}},	{0,{184,181,182,0}},	{0,{184,181,181,0}},
{0,{180,180,181,0}},	{0,{183,179,179,0}},	{0,{183,178,178,0}},
{0,{183,159,0,0}},	{0,{158,158,0,0}},	{0,{182,157,0,0}},
{0,{182,0,0,0}},	{0,{182,0,0,0}},	{0,{182,0,0,0}},
{0,{182,153,0,0}},	{0,{182,152,153,0}},	{0,{182,0,0,0}},
{0,{180,150,0,0}},	{0,{181,0,0,0}},	{0,{179,0,149,0}},
{0,{140,140,141,0}},	{0,{163,163,164,0}},	{0,{178,0,0,0}},
{0,{0,0,0,178}},	{0,{0,0,0,178}},	{0,{0,0,0,178}},
{0,{0,0,0,178}},	{0,{0,0,0,178}},	{0,{0,0,0,178}},
{0,{0,0,0,178}},	{0,{0,0,0,178}},	{0,{178,178,178,178}},
{0,{0,0,0,178}},	{0,{176,176,176,178}},	{0,{0,0,0,178}},
{0,{178,0,178,0}},	{0,{0,0,0,178}},	{0,{178,178,178,178}},
{0,{177,177,178,177}},	{0,{178,0,178,0}},	{0,{178,175,178,175}},
{0,{178,0,0,0}},	{0,{0,0,0,178}},	{0,{178,178,178,179}},
{0,{178,178,178,178}},	{0,{178,178,178,177}},	{0,{178,178,178,178}},
{0,{178,178,178,178}},	{0,{0,0,0,178}},	{0,{0,0,0,178}},
{0,{0,0,0,178}},	{0,{0,0,178,0}},	{0,{0,0,0,178}},
{0,{0,0,0,178}},	{0,{0,0,0,178}},	{0,{0,0,0,178}},
{0,{0,0,0,178}},	{0,{0,0,0,178}},	{0,{0,0,0,178}},
{0,{0,0,0,178}},	{0,{0,0,0,178}},	{0,{178,178,178,178}},
{0,{0,0,0,178}},	{0,{178,0,178,0}},	{0,{0,0,0,178}},
{0,{178,0,0,0}},	{0,{0,0,0,178}},	{0,{0,0,0,178}},
{0,{178,178,178,178}},	{0,{178,178,0,0}},	{325,{0,0,0,0}},
{0,{0,0,0,177}},	{0,{0,0,0,177}},	{0,{0,0,0,177}},
{0,{0,0,0,177}},	{0,{177,177,177,177}},	{0,{177,177,177,177}},
{0,{0,0,0,177}},	{0,{177,177,177,177}},	{0,{0,0,0,177}},
{0,{0,0,0,177}},	{0,{177,177,177,177}},	{0,{0,0,0,177}},
{0,{0,0,0,177}},	{0,{177,177,177,177}},	{0,{177,177,0,0}},
{0,{0,0,0,177}},	{0,{0,0,0,177}},	{0,{0,0,0,177}},
{0,{0,0,0,177}},	{0,{0,0,0,177}},	{0,{0,0,0,177}},
{0,{177,177,177,177}},	{0,{177,177,177,177}},	{0,{177,177,177,177}},
{0,{177,177,177,177}},	{0,{177,177,177,177}},	{0,{0,0,0,177}},
{0,{0,0,0,177}},	{0,{0,0,0,177}},	{0,{0,0,0,177}},
{0,{0,0,0,177}},	{0,{177,177,177,177}},	{0,{177,177,177,177}},
{1,{0,0,0,0}},	{0,{0,176,0,0}},	{1,{0,175,0,0}},
{0,{175,174,0,0}},	{1,{174,173,0,0}},	{0,{173,0,0,0}},
{0,{173,171,0,0}},	{0,{173,0,0,0}},	{1,{172,0,0,0}},
{0,{172,168,0,0}},	{1,{171,167,0,0}},	{0,{170,0,0,0}},
{0,{170,0,0,0}},	{0,{170,170,0,0}},	{0,{170,0,0,0}},
{0,{169,162,0,0}},	{0,{169,169,169,169}},	{0,{169,169,169,169}},
{0,{169,0,0,0}},	{0,{169,0,169,0}},	{0,{169,0,169,0}},
{0,{0,0,169,0}},	{0,{169,170,0,0}},	{0,{170,170,0,0}},
{0,{170,170,170,170}},	{0,{170,0,0,0}},	{0,{0,0,0,170}},
{67,{0,0,0,0}},	{0,{151,0,0,0}},	{0,{168,0,0,0}},
{0,{168,0,0,0}},	{0,{168,0,168,0}},	{0,{168,0,0,0}},
{0,{168,0,0,0}},	{0,{168,0,0,0}},	{0,{0,0,0,168}},
{0,{0,0,0,168}},	{0,{168,0,168,0}},	{0,{168,0,0,0}},
{0,{168,0,0,0}},	{0,{168,168,168,168}},	{0,{0,0,168,0}},
{0,{168,168,168,168}},	{0,{168,168,168,168}},	{0,{168,168,168,168}},
{0,{0,0,0,168}},	{0,{168,0,0,0}},	{0,{168,0,0,0}},
{0,{168,0,0,0}},	{0,{168,0,0,0}},	{0,{168,0,0,0}},
{0,{168,0,0,0}},	{0,{0,0,0,168}},	{0,{168,0,0,0}},
{0,{168,0,0,0}},	{0,{168,169,170,170}},	{0,{170,169,169,169}},
{0,{170,0,0,0}},	{159,{169,0,0,0}},	{0,{169,166,166,166}},
{0,{169,165,165,165}},	{0,{169,164,164,164}},	{0,{169,0,0,0}},
{0,{162,162,162,162}},	{159,{0,0,0,0}},	{0,{167,168,0,0}},
{0,{168,167,0,0}},	{0,{168,0,0,0}},	{0,{168,0,0,0}},
{0,{168,164,0,0}},	{0,{168,0,0,0}},	{159,{167,0,0,0}},
{0,{167,0,0,0}},	{0,{167,160,0,0}},	{0,{167,150,151,151}},
{0,{167,150,150,150}},	{0,{157,157,0,0}},	{0,{166,156,0,0}},
{0,{166,0,0,0}},	{0,{166,145,146,146}},	{0,{166,145,145,145}},
{0,{166,0,0,0}},	{159,{165,0,0,0}},	{0,{165,142,142,142}},
{0,{165,149,0,0}},	{0,{165,148,0,0}},	{0,{165,0,0,0}},
{0,{137,137,138,138}},	{0,{164,137,137,137}},	{0,{164,0,0,0}},
{0,{164,0,0,0}},	{0,{164,0,0,0}},	{0,{164,164,133,133}},
{0,{164,164,132,132}},	{0,{164,164,0,0}},	{0,{164,164,0,0}},
{0,{164,164,164,164}},	{0,{164,0,0,0}},	{0,{164,0,0,0}},
{0,{164,0,0,0}},	{0,{164,0,0,0}},	{0,{164,0,0,0}},
{0,{164,0,0,0}},	{0,{164,0,0,0}},	{0,{164,0,0,0}},
{0,{164,0,0,0}},	{0,{164,0,165,0}},	{0,{165,0,164,0}},
{0,{163,0,163,0}},	{0,{164,0,0,0}},	{0,{164,0,0,0}},
{0,{164,164,164,164}},	{159,{163,163,163,163}},	{0,{163,163,163,163}},
{0,{163,163,163,163}},	{0,{163,163,163,163}},	{0,{163,0,0,0}},
{0,{163,164,0,0}},	{0,{163,163,0,0}},	{0,{163,162,0,0}},
{0,{163,163,163,163}},	{0,{163,163,163,163}},	{0,{163,163,163,163}},
{0,{0,0,0,163}},	{0,{163,0,0,0}},	{241,{0,0,0,0}},
{0,{0,0,0,162}},	{0,{0,0,0,162}},	{0,{0,0,162,0}},
{0,{0,0,162,0}},	{0,{162,0,0,0}},	{0,{162,0,0,0}},
{0,{162,0,0,0}},	{0,{0,0,0,162}},	{0,{162,162,162,162}},
{0,{0,0,162,0}},	{0,{162,0,0,0}},	{295,{0,0,0,0}},
{0,{161,161,161,0}},	{315,{0,0,0,0}},	{0,{0,160,0,0}},
{0,{160,160,160,0}},	{0,{160,0,160,0}},	{0,{0,0,160,0}},
{0,{0,0,160,0}},	{0,{160,160,160,160}},	{0,{160,0,0,0}},
{0,{160,0,160,0}},	{0,{160,0,0,0}},	{0,{160,0,0,0}},
{0,{0,0,0,160}},	{0,{160,0,160,0}},	{0,{160,0,0,0}},
{0,{160,0,0,0}},	{0,{160,0,0,0}},	{0,{160,0,0,0}},
{0,{160,0,0,0}},	{0,{160,160,160,160}},	{0,{160,160,160,0}},
{0,{0,0,0,160}},	{0,{160,0,0,0}},	{0,{160,0,0,0}},
{0,{0,0,160,0}},	{0,{0,0,160,0}},	{0,{0,160,0,0}},
{0,{160,0,0,0}},	{0,{160,0,160,0}},	{0,{160,0,160,0}},
{0,{160,160,160,160}},	{0,{160,0,160,0}},	{0,{160,0,0,0}},
{0,{160,0,0,0}},	{0,{160,0,0,0}},	{0,{160,0,0,0}},
{0,{160,0,0,0}},	{0,{160,160,160,160}},	{0,{160,160,160,160}},
{2,{0,0,0,0}},	{0,{159,159,159,159}},	{4,{0,0,0,0}},
{0,{158,158,158,158}},	{0,{158,158,158,158}},	{8,{0,0,0,0}},
{0,{0,0,0,157}},	{0,{157,157,157,157}},	{0,{157,0,157,0}},
{0,{157,0,157,0}},	{0,{157,0,0,0}},	{0,{157,157,157,0}},
{0,{157,157,157,0}},	{0,{157,157,157,157}},	{26,{0,0,0,0}},
{27,{0,0,0,0}},	{0,{155,155,155,155}},	{0,{155,0,0,0}},
{59,{0,0,0,0}},	{0,{0,0,0,154}},	{0,{154,154,154,154}},
{0,{154,0,0,0}},	{75,{0,0,0,0}},	{79,{0,0,0,0}},
{79,{152,0,0,0}},	{84,{0,0,0,0}},	{0,{151,151,151,151}},
{0,{151,151,151,151}},	{74,{0,0,0,0}},	{100,{0,0,0,0}},
{0,{149,0,0,0}},	{0,{149,0,0,0}},	{118,{0,0,0,0}},
{0,{0,0,148,0}},	{0,{148,148,148,148}},	{0,{148,0,0,0}},
{0,{0,0,0,148}},	{125,{0,0,0,0}},	{127,{0,0,0,0}},
{127,{146,0,0,0}},	{130,{0,0,0,0}},	{0,{145,0,0,0}},
{0,{145,0,0,0}},	{0,{145,145,145,145}},	{0,{145,0,0,0}},
{152,{0,0,0,0}},	{0,{144,145,146,146}},	{0,{146,147,0,0}},
{0,{147,0,0,0}},	{0,{147,148,143,143}},	{0,{147,147,142,142}},
{0,{147,146,141,141}},	{0,{147,148,148,148}},	{0,{148,147,147,147}},
{0,{146,146,146,146}},	{0,{136,136,137,137}},	{0,{138,138,0,0}},
{0,{145,134,135,135}},	{0,{145,139,134,134}},	{0,{145,141,141,141}},
{0,{145,146,132,132}},	{0,{131,131,131,131}},	{0,{145,130,130,130}},
{0,{143,143,129,129}},	{0,{144,130,0,0}},	{0,{144,0,0,0}},
{0,{144,128,0,0}},	{0,{144,0,0,0}},	{0,{144,145,0,0}},
{0,{145,146,0,0}},	{0,{145,145,0,0}},	{0,{145,144,0,0}},
{0,{141,141,0,0}},	{0,{144,140,0,0}},	{0,{144,141,0,0}},
{0,{144,145,145,145}},	{0,{144,144,144,144}},	{0,{144,144,143,143}},
{0,{144,144,0,0}},	{0,{144,145,146,0}},	{0,{146,145,145,0}},
{0,{144,144,144,0}},	{0,{142,142,143,0}},	{0,{144,0,0,0}},
{0,{144,144,144,144}},	{0,{144,0,144,0}},	{0,{144,0,0,0}},
{0,{144,141,141,141}},	{173,{144,144,144,0}},	{173,{0,0,0,0}},
{0,{143,0,0,0}},	{173,{143,141,141,0}},	{0,{143,143,143,143}},
{181,{0,0,0,0}},	{182,{0,0,0,0}},	{181,{140,140,140,140}},
{0,{140,140,140,140}},	{185,{0,0,0,0}},	{0,{139,0,0,0}},
{0,{139,139,139,0}},	{0,{139,138,138,0}},	{0,{139,0,0,0}},
{0,{139,0,0,0}},	{0,{139,139,140,140}},	{0,{140,140,140,140}},
{0,{138,138,138,138}},	{0,{139,0,139,0}},	{0,{0,139,0,0}},
{0,{139,0,139,0}},	{0,{0,0,0,139}},	{237,{0,0,0,0}},
{0,{0,0,0,138}},	{0,{0,0,0,138}},	{263,{0,0,0,0}},
{0,{0,0,0,137}},	{0,{137,113,113,113}},	{0,{137,0,0,0}},
{270,{0,0,0,0}},	{0,{0,0,0,136}},	{0,{136,0,136,0}},
{0,{136,136,0,0}},	{0,{136,0,0,0}},	{0,{136,0,0,0}},
{0,{136,0,0,0}},	{0,{136,0,0,0}},	{322,{0,0,0,0}},
{323,{0,0,0,0}},	{330,{0,0,0,0}},	{0,{0,0,133,0}},
{0,{133,0,0,0}},	{0,{133,0,133,0}},	{340,{0,0,0,0}},
{341,{0,0,0,0}},	{0,{0,0,0,131}},	{345,{0,0,0,0}},
{0,{130,0,0,0}},	{0,{130,0,0,0}},	{0,{130,0,0,0}},
{351,{0,0,0,0}},	{354,{0,0,0,0}},	{0,{128,128,128,128}},
{0,{128,128,0,0}},	{0,{0,0,0,128}},	{388,{0,0,0,0}},
{389,{0,0,0,0}},	{393,{0,0,0,0}},	{396,{0,0,0,0}},
{398,{0,0,0,0}},	{399,{0,0,0,0}},	{400,{0,0,0,0}},
{400,{121,121,121,121}},	{0,{121,121,121,121}},	{404,{0,0,0,0}},
{406,{0,0,0,0}},	{407,{0,0,0,0}},	{408,{0,0,0,0}},
{412,{0,0,0,0}},	{413,{0,0,0,0}},	{0,{115,115,115,115}},
{0,{115,115,115,115}},	{0,{115,115,115,115}},	{0,{115,115,115,115}},
{0,{115,115,115,115}},	{0,{115,115,115,115}},	{0,{115,115,115,115}},
{14,{0,0,0,0}},	{15,{0,0,0,0}},	{16,{0,0,0,0}},
{0,{112,112,112,112}},	{0,{112,112,112,112}},	{0,{112,0,0,0}},
{0,{0,0,0,112}},	{29,{0,0,0,0}},	{0,{0,0,111,0}},
{0,{111,111,111,111}},	{0,{111,111,111,111}},	{80,{0,0,0,0}},
{0,{0,0,0,110}},	{0,{0,0,0,110}},	{0,{110,110,110,110}},
{0,{110,110,110,110}},	{119,{0,0,0,0}},	{0,{109,109,109,109}},
{0,{109,109,109,109}},	{0,{109,0,0,0}},	{128,{0,0,0,0}},
{0,{108,108,108,108}},	{0,{0,108,0,0}},	{0,{0,0,0,108}},
{150,{0,0,0,0}},	{0,{107,108,109,109}},	{0,{109,110,0,0}},
{0,{110,0,0,0}},	{0,{105,105,106,106}},	{0,{107,107,0,0}},
{0,{104,104,104,104}},	{0,{107,103,103,103}},	{0,{107,0,0,0}},
{0,{107,101,101,101}},	{0,{107,100,100,100}},	{0,{107,0,0,0}},
{0,{107,98,98,98}},	{0,{107,99,0,0}},	{0,{107,0,0,0}},
{0,{107,0,0,0}},	{0,{107,96,0,0}},	{0,{107,95,0,0}},
{0,{107,0,0,0}},	{0,{107,90,91,91}},	{0,{107,90,90,90}},
{0,{107,91,0,0}},	{0,{107,0,0,0}},	{0,{107,86,87,87}},
{0,{107,88,0,0}},	{0,{107,85,85,85}},	{0,{107,0,0,0}},
{0,{107,83,83,83}},	{0,{107,84,0,0}},	{0,{107,0,0,0}},
{0,{80,80,80,107}},	{0,{0,0,0,107}},	{0,{0,0,0,107}},
{0,{0,0,0,107}},	{0,{107,107,108,108}},	{0,{108,108,109,109}},
{0,{108,108,108,108}},	{0,{105,105,105,105}},	{0,{107,107,107,107}},
{0,{0,107,0,0}},	{170,{0,0,0,0}},	{0,{0,0,0,106}},
{0,{106,104,0,0}},	{174,{0,0,106,0}},	{176,{0,0,0,0}},
{174,{103,0,104,0}},	{0,{0,0,0,104}},	{0,{104,104,104,104}},
{0,{104,104,104,104}},	{0,{104,104,104,104}},	{0,{104,104,104,104}},
{0,{104,104,104,104}},	{198,{0,0,0,0}},	{0,{103,0,0,0}},
{0,{103,0,0,0}},	{0,{103,0,0,0}},	{205,{0,0,0,0}},
{208,{0,0,0,0}},	{215,{0,0,0,0}},	{0,{0,100,0,0}},
{0,{100,0,0,0}},	{0,{100,0,0,0}},	{0,{100,100,100,100}},
{0,{100,83,0,0}},	{0,{100,100,100,100}},	{0,{100,0,0,0}},
{290,{0,0,0,0}},	{0,{0,0,0,99}},	{293,{0,0,0,0}},
{314,{0,0,0,0}},	{316,{0,0,0,0}},	{317,{0,0,0,0}},
{332,{0,0,0,0}},	{0,{94,94,94,0}},	{335,{0,0,0,0}},
{0,{93,93,93,93}},	{0,{0,93,0,0}},	{348,{0,0,0,0}},
{350,{0,0,0,0}},	{0,{91,91,91,91}},	{0,{91,91,91,91}},
{0,{91,91,91,91}},	{0,{91,0,0,0}},	{0,{91,91,91,91}},
{0,{0,0,0,91}},	{0,{91,91,91,91}},	{0,{91,91,91,91}},
{0,{91,91,91,91}},	{0,{91,91,91,91}},	{0,{0,0,0,91}},
{0,{91,91,91,91}},	{0,{91,91,91,91}},	{0,{91,91,91,91}},
{0,{91,91,91,91}},	{0,{91,91,91,91}},	{0,{91,91,91,91}},
{0,{91,91,91,91}},	{0,{91,91,91,91}},	{0,{91,91,91,91}},
{0,{91,91,91,91}},	{0,{91,91,91,91}},	{0,{91,0,0,0}},
{0,{91,91,91,91}},	{0,{0,0,0,91}},	{0,{91,91,91,91}},
{0,{91,91,91,91}},	{0,{0,0,0,91}},	{0,{91,91,91,91}},
{0,{91,91,92,92}},	{0,{92,92,0,0}},	{0,{92,92,0,0}},
{0,{92,92,89,89}},	{0,{92,92,0,0}},	{0,{92,92,92,92}},
{0,{92,92,86,86}},	{0,{85,85,85,85}},	{0,{91,91,84,84}},
{0,{91,91,92,92}},	{0,{91,91,91,91}},	{0,{91,91,90,90}},
{0,{91,91,80,80}},	{0,{91,91,79,79}},	{0,{91,91,87,87}},
{0,{91,91,82,82}},	{0,{91,91,81,81}},	{0,{91,91,80,80}},
{0,{91,91,0,0}},	{0,{91,91,0,0}},	{0,{91,91,0,0}},
{0,{91,91,0,0}},	{0,{91,91,92,92}},	{0,{92,92,91,91}},
{0,{92,92,90,90}},	{0,{89,89,89,89}},	{0,{91,91,88,88}},
{0,{91,91,87,87}},	{0,{91,91,86,86}},	{0,{91,91,92,92}},
{0,{91,91,91,91}},	{0,{91,91,91,91}},	{0,{91,91,91,91}},
{0,{91,91,92,0}},	{0,{92,92,91,0}},	{0,{92,92,90,0}},
{0,{89,89,89,0}},	{0,{0,0,0,91}},	{0,{91,91,91,91}},
{0,{91,91,91,91}},	{0,{0,0,0,91}},	{175,{0,0,0,0}},
{0,{90,90,90,90}},	{0,{90,90,90,90}},	{0,{0,0,0,90}},
{0,{90,90,90,90}},	{0,{89,89,89,90}},	{0,{90,90,0,0}},
{0,{90,90,90,90}},	{0,{90,90,90,90}},	{0,{90,90,90,90}},
{236,{0,0,0,0}},	{254,{0,0,0,0}},	{0,{88,88,88,88}},
{0,{0,0,0,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{88,88,88,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{88,0,0,0}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{0,0,0,88}},	{0,{0,88,0,0}},	{0,{88,88,88,88}},
{0,{88,88,88,88}},	{0,{88,88,88,88}},	{0,{0,0,0,88}},
{0,{88,88,88,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{88,88,88,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{88,88,88,88}},	{0,{0,0,0,88}},	{0,{0,0,0,88}},
{0,{88,88,88,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{0,0,0,88}},	{0,{0,0,0,88}},	{0,{88,88,88,88}},
{0,{88,88,88,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{88,0,88,0}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{0,0,0,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{88,88,88,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{88,88,88,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{88,88,88,88}},	{0,{88,88,88,89}},	{0,{0,0,0,89}},
{0,{80,80,80,89}},	{0,{89,89,89,89}},	{0,{89,89,89,89}},
{0,{89,89,89,90}},	{0,{90,90,90,90}},	{0,{90,90,90,90}},
{0,{90,90,90,90}},	{0,{90,90,90,90}},	{0,{78,78,78,78}},
{0,{89,89,89,89}},	{0,{82,82,82,82}},	{0,{88,88,88,88}},
{0,{88,88,88,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{88,88,88,88}},	{0,{88,88,88,88}},	{0,{88,88,88,88}},
{0,{62,62,62,88}},	{0,{0,0,0,88}},	{0,{0,0,0,88}},
{0,{0,0,0,88}},	{164,{57,57,57,57}},	{164,{0,0,0,0}},
{164,{56,56,56,56}},	{164,{57,57,57,57}},	{0,{84,84,84,84}},
{0,{84,84,84,84}},	{0,{0,0,0,84}},	{0,{84,84,84,84}},
{0,{0,0,0,84}},	{0,{84,84,84,84}},	{0,{84,84,84,84}},
{0,{84,84,84,84}},	{0,{84,84,84,84}},	{0,{84,84,84,84}},
{0,{84,84,84,84}},	{0,{84,84,84,84}},	{0,{84,84,84,84}},
{0,{84,84,84,84}},	{0,{84,84,84,84}},	{0,{84,84,84,84}},
{0,{84,84,84,84}},	{0,{84,84,84,84}},	{0,{0,0,0,84}},
{0,{84,84,84,84}},	{342,{0,0,0,0}},	{0,{83,83,83,83}},
{0,{83,83,83,83}},	{0,{83,83,83,83}},	{380,{0,0,0,0}},
{0,{82,82,82,82}},	{0,{82,82,82,82}},	{0,{0,0,0,82}},
{0,{82,82,82,82}},	{0,{82,82,82,82}},	{0,{82,82,82,82}},
{0,{82,82,82,82}},	{0,{82,82,82,82}},	{0,{82,82,82,82}},
{0,{82,82,82,82}},	{0,{82,82,82,82}},	{0,{82,0,0,0}},
{0,{0,0,0,82}},	{0,{82,0,82,0}},	{0,{82,82,82,82}},
{0,{82,82,82,82}},	{0,{0,0,0,82}},	{0,{0,0,0,82}},
{0,{82,82,82,82}},	{0,{82,82,82,82}},	{0,{82,82,82,82}},
{0,{82,82,82,82}},	{0,{82,82,82,82}},	{0,{82,82,82,82}},
{0,{82,82,82,0}},	{0,{0,0,0,82}},	{0,{82,82,82,83}},
{0,{83,83,83,0}},	{0,{83,83,83,83}},	{0,{83,83,83,83}},
{0,{83,83,83,84}},	{0,{83,83,83,83}},	{0,{83,83,83,0}},
{0,{83,83,83,79}},	{0,{83,83,83,84}},	{0,{83,83,83,83}},
{0,{83,83,83,83}},	{0,{83,83,83,83}},	{0,{83,83,83,83}},
{0,{83,83,83,84}},	{0,{84,84,84,85}},	{0,{84,84,84,84}},
{0,{84,84,84,84}},	{0,{84,84,84,80}},	{0,{84,84,84,70}},
{0,{84,84,84,80}},	{0,{63,63,63,63}},	{0,{76,76,76,76}},
{0,{82,82,82,61}},	{0,{82,82,82,0}},	{0,{82,82,82,64}},
{0,{82,82,82,61}},	{0,{82,82,82,66}},	{0,{82,82,82,70}},
{0,{82,82,82,71}},	{0,{57,57,57,82}},	{0,{0,0,0,82}},
{0,{0,0,0,82}},	{0,{0,0,0,82}},	{0,{82,82,82,82}},
{0,{82,82,82,82}},	{0,{0,0,0,82}},	{0,{82,82,0,0}},
{0,{0,0,0,82}},	{0,{82,82,82,82}},	{0,{82,82,82,82}},
{0,{82,82,82,82}},	{0,{82,82,82,82}},	{0,{82,82,82,82}},
{0,{82,41,41,0}},	{0,{82,45,45,0}},	{0,{82,0,0,0}},
{0,{0,82,0,0}},	{0,{82,82,82,82}},	{0,{82,82,82,0}},
{0,{0,0,0,82}},	{0,{82,0,82,0}},	{0,{0,0,0,82}},
{0,{82,82,82,82}},	{0,{82,82,82,82}},	{0,{82,82,82,82}},
{0,{82,82,82,82}},	{0,{0,82,0,0}},	{0,{82,0,0,0}},
{0,{0,0,0,82}},	{0,{82,82,82,82}},	{0,{82,82,82,82}},
{0,{82,82,82,82}},	{0,{82,82,82,82}},	{0,{82,82,82,82}},
{0,{82,82,82,82}},	{0,{82,82,82,0}},	{0,{82,82,82,0}},
{0,{82,82,82,82}},	{28,{0,0,0,0}},	{62,{0,0,0,0}},
{0,{80,80,80,80}},	{0,{80,0,0,0}},	{0,{0,0,0,80}},
{0,{0,0,0,80}},	{0,{80,80,80,80}},	{0,{80,80,80,80}},
{0,{80,0,80,0}},	{0,{80,80,80,80}},	{0,{80,80,80,80}},
{0,{80,80,80,0}},	{0,{80,80,80,0}},	{0,{0,0,0,80}},
{0,{80,80,81,81}},	{0,{80,80,80,80}},	{0,{80,80,0,0}},
{0,{80,80,80,80}},	{0,{80,80,80,80}},	{0,{80,80,81,81}},
{0,{80,80,80,80}},	{0,{80,80,0,0}},	{0,{80,80,76,76}},
{0,{80,80,81,81}},	{0,{80,80,80,80}},	{0,{80,80,80,80}},
{0,{80,80,80,80}},	{0,{80,80,80,80}},	{0,{80,80,81,81}},
{0,{80,80,80,80}},	{0,{80,80,81,81}},	{0,{80,80,80,80}},
{0,{80,80,80,80}},	{0,{80,80,76,76}},	{0,{80,80,66,66}},
{0,{80,80,76,76}},	{0,{80,80,59,59}},	{0,{80,80,0,0}},
{0,{80,80,62,62}},	{0,{80,80,59,59}},	{0,{80,80,64,64}},
{0,{80,80,68,68}},	{0,{80,80,69,69}},	{0,{80,80,80,80}},
{0,{80,80,80,80}},	{0,{80,80,80,80}},	{0,{80,80,80,80}},
{0,{80,80,80,80}},	{0,{80,80,80,80}},	{0,{80,0,0,0}},
{0,{80,80,80,80}},	{179,{0,0,0,0}},	{0,{79,79,79,79}},
{0,{79,79,79,79}},	{0,{79,79,79,79}},	{0,{79,79,79,79}},
{0,{79,79,79,79}},	{0,{79,39,0,0}},	{0,{79,43,0,0}},
{0,{79,0,0,0}},	{262,{0,0,0,0}},	{0,{0,78,0,0}},
{0,{78,78,78,78}},	{0,{78,78,0,0}},	{272,{0,0,0,0}},
{0,{0,0,0,77}},	{0,{77,77,77,77}},	{0,{77,77,77,77}},
{0,{77,0,0,0}},	{0,{77,0,0,0}},	{0,{77,77,77,77}},
{0,{0,0,0,77}},	{0,{0,0,77,0}},	{0,{77,77,77,77}},
{0,{77,77,77,77}},	{0,{77,77,77,77}},	{0,{77,77,77,77}},
{0,{77,77,77,77}},	{0,{77,77,77,77}},	{0,{77,77,77,77}},
{0,{77,77,77,77}},	{0,{77,77,77,77}},	{0,{77,77,77,77}},
{73,{0,0,0,0}},	{88,{0,0,0,0}},	{89,{0,0,0,0}},
{0,{74,74,74,74}},	{0,{74,74,74,74}},	{122,{0,0,0,0}},
{0,{73,73,73,73}},	{0,{73,73,73,73}},	{132,{0,0,0,0}},
{0,{72,72,72,72}},	{0,{72,0,0,0}},	{0,{72,72,72,73}},
{0,{73,73,73,73}},	{0,{73,73,73,74}},	{0,{74,74,74,74}},
{0,{74,74,74,74}},	{0,{74,74,74,75}},	{0,{75,75,75,75}},
{0,{75,75,75,0}},	{0,{75,75,75,76}},	{0,{76,76,76,77}},
{0,{77,77,77,77}},	{0,{77,77,77,77}},	{0,{77,77,77,77}},
{0,{77,77,77,77}},	{0,{77,77,77,78}},	{0,{78,78,78,78}},
{0,{78,78,78,79}},	{0,{79,79,79,79}},	{0,{79,79,79,79}},
{0,{79,79,79,74}},	{0,{79,79,79,61}},	{0,{79,79,79,75}},
{0,{51,51,51,51}},	{0,{53,53,53,53}},	{0,{56,56,56,56}},
{0,{59,59,59,59}},	{0,{60,60,60,60}},	{0,{65,65,65,65}},
{0,{67,67,67,67}},	{0,{72,72,72,72}},	{0,{72,72,72,72}},
{0,{72,72,72,72}},	{0,{72,72,72,72}},	{0,{72,72,72,72}},
{0,{72,72,72,72}},	{0,{72,72,0,0}},	{0,{72,72,72,72}},
{0,{72,72,72,72}},	{0,{72,72,72,72}},	{0,{72,72,72,72}},
{0,{72,72,72,72}},	{0,{72,72,72,72}},	{0,{72,33,33,34}},
{0,{72,39,39,0}},	{0,{72,0,0,0}},	{0,{0,72,0,0}},
{0,{72,72,72,72}},	{0,{72,72,72,72}},	{0,{0,0,0,72}},
{0,{72,72,72,72}},	{0,{72,72,72,72}},	{0,{0,0,0,72}},
{0,{0,0,0,72}},	{0,{72,72,72,72}},	{0,{0,0,0,72}},
{415,{0,0,0,0}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{264,{0,0,0,0}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{291,{0,0,0,0}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,0,69,0}},	{0,{69,69,69,70}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,70}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,70}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,0}},
{0,{69,69,69,70}},	{0,{69,69,69,69}},	{0,{69,69,69,70}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,70}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,70}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,64}},	{0,{69,69,69,51}},	{0,{69,69,69,65}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,0}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,70}},	{0,{70,70,70,71}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{0,0,0,70}},
{0,{0,0,0,70}},	{0,{70,70,70,70}},	{0,{0,0,0,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{0,0,0,70}},	{0,{70,70,70,70}},
{0,{70,70,70,0}},	{0,{70,70,70,0}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,0,0,0}},
{149,{0,0,0,0}},	{0,{69,69,69,70}},	{0,{70,70,70,71}},
{0,{70,70,70,70}},	{0,{70,70,70,71}},	{0,{71,71,71,0}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{71,71,71,72}},
{0,{72,72,72,73}},	{0,{72,72,72,72}},	{0,{64,64,64,64}},
{0,{71,71,71,72}},	{0,{72,72,72,65}},	{0,{72,72,72,73}},
{0,{73,73,73,74}},	{0,{73,73,73,73}},	{0,{73,73,73,73}},
{0,{73,73,73,73}},	{0,{73,73,73,73}},	{0,{73,73,73,74}},
{0,{74,74,74,75}},	{0,{74,74,74,74}},	{0,{74,74,74,75}},
{0,{75,75,75,76}},	{0,{75,75,75,75}},	{0,{75,75,75,75}},
{0,{67,67,67,67}},	{0,{52,52,52,52}},	{0,{69,69,69,69}},
{0,{72,72,72,72}},	{0,{72,72,72,72}},	{0,{72,72,72,72}},
{0,{72,72,72,72}},	{0,{72,72,72,72}},	{0,{72,72,72,72}},
{0,{72,0,0,0}},	{0,{72,72,72,72}},	{0,{72,72,72,72}},
{0,{72,72,72,72}},	{0,{72,72,72,72}},	{0,{72,72,72,72}},
{0,{72,72,72,72}},	{0,{72,72,72,73}},	{0,{73,73,73,74}},
{0,{71,71,71,71}},	{0,{72,72,72,72}},	{0,{72,72,72,72}},
{0,{72,72,72,0}},	{0,{72,72,72,72}},	{0,{72,72,72,72}},
{358,{0,0,0,0}},	{0,{71,0,0,0}},	{0,{71,71,71,71}},
{0,{0,0,0,71}},	{0,{71,0,0,0}},	{0,{71,71,71,71}},
{0,{71,71,71,71}},	{0,{71,71,71,71}},	{0,{0,0,0,71}},
{0,{71,71,71,71}},	{18,{0,0,0,0}},	{24,{0,0,0,0}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,0,69,0}},	{0,{0,0,0,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{153,{69,69,70,70}},	{0,{68,68,69,69}},
{153,{69,69,70,70}},	{0,{68,68,69,69}},	{153,{69,69,69,69}},
{0,{68,68,68,68}},	{153,{0,0,0,0}},	{0,{67,67,68,68}},
{0,{68,68,0,0}},	{153,{68,68,68,68}},	{0,{67,67,67,67}},
{153,{64,64,64,64}},	{0,{63,63,63,63}},	{153,{65,65,60,60}},
{0,{64,64,59,59}},	{153,{61,61,0,0}},	{153,{63,63,64,64}},
{0,{62,62,63,63}},	{153,{63,63,64,64}},	{0,{62,62,63,63}},
{0,{63,63,64,64}},	{0,{64,64,64,64}},	{0,{64,64,63,63}},
{153,{47,47,47,47}},	{0,{46,46,46,46}},	{153,{47,47,47,47}},
{0,{46,46,46,46}},	{153,{53,53,53,53}},	{0,{52,52,52,52}},
{153,{53,53,53,53}},	{0,{52,52,52,52}},	{0,{53,53,53,53}},
{0,{55,55,56,56}},	{0,{55,55,55,55}},	{0,{55,55,55,55}},
{0,{55,55,55,55}},	{0,{0,0,0,55}},	{0,{55,55,55,55}},
{0,{55,55,55,55}},	{0,{0,0,0,55}},	{0,{55,55,55,55}},
{0,{0,0,0,55}},	{0,{55,55,55,55}},	{0,{54,54,54,55}},
{0,{55,55,55,55}},	{153,{55,55,55,55}},	{0,{54,54,54,54}},
{153,{54,54,54,54}},	{0,{53,53,53,53}},	{0,{53,53,53,53}},
{267,{0,0,0,0}},	{0,{52,52,52,52}},	{0,{52,52,52,52}},
{0,{0,0,0,52}},	{0,{52,52,52,52}},	{403,{0,0,0,0}},
{0,{0,0,0,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{0,0,0,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{0,0,0,51}},	{0,{51,51,51,51}},
{0,{0,0,0,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{51,51,51,51}},	{0,{0,0,0,51}},
{0,{51,51,51,51}},	{0,{51,51,51,51}},	{0,{0,0,0,51}},
{0,{51,51,51,51}},	{0,{0,0,0,51}},	{0,{51,51,51,51}},
{0,{50,50,50,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{51,51,51,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{0,0,0,51}},	{0,{51,51,51,51}},
{0,{0,0,0,51}},	{0,{0,0,0,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{0,0,0,51}},	{0,{51,51,51,51}},
{0,{51,51,51,51}},	{0,{0,0,0,51}},	{0,{51,51,51,51}},
{0,{0,0,0,51}},	{123,{0,0,0,0}},	{0,{0,0,0,50}},
{0,{0,0,0,50}},	{0,{50,50,50,50}},	{0,{50,50,50,50}},
{0,{50,50,50,50}},	{0,{50,50,50,50}},	{0,{50,50,50,50}},
{0,{50,50,50,50}},	{0,{50,50,50,50}},	{0,{50,50,50,50}},
{0,{50,50,50,50}},	{0,{50,50,50,50}},	{0,{50,50,50,50}},
{0,{50,50,50,50}},	{0,{50,50,50,50}},	{0,{50,50,50,50}},
{0,{48,48,48,50}},	{0,{48,48,48,50}},	{0,{0,0,0,50}},
{0,{40,40,40,50}},	{0,{50,50,50,50}},	{0,{50,50,50,50}},
{0,{50,50,50,50}},	{0,{50,50,50,50}},	{0,{50,50,50,50}},
{0,{0,0,0,50}},	{0,{0,0,0,50}},	{0,{0,0,0,50}},
{0,{50,50,50,50}},	{188,{0,0,0,0}},	{0,{49,49,49,49}},
{188,{48,48,48,48}},	{0,{0,0,0,48}},	{0,{48,48,48,48}},
{0,{48,48,48,48}},	{0,{0,0,0,48}},	{0,{0,0,0,48}},
{0,{0,0,0,48}},	{0,{48,48,48,48}},	{0,{48,48,48,48}},
{419,{0,0,0,0}},	{0,{0,0,0,47}},	{0,{47,47,47,0}},
{0,{47,47,47,0}},	{0,{0,0,0,47}},	{0,{47,47,47,47}},
{0,{47,47,47,47}},	{0,{0,0,0,47}},	{0,{47,47,47,47}},
{0,{0,0,0,47}},	{0,{0,0,0,47}},	{0,{0,0,0,47}},
{0,{47,48,47,48}},	{0,{48,49,48,49}},	{0,{49,50,49,50}},
{0,{50,51,50,51}},	{0,{51,51,51,51}},	{0,{51,52,51,52}},
{0,{52,0,52,0}},	{0,{50,50,50,50}},	{0,{51,47,51,47}},
{0,{51,51,51,51}},	{0,{38,38,38,38}},	{0,{39,39,39,39}},
{0,{40,40,40,40}},	{0,{41,41,41,41}},	{0,{38,38,38,47}},
{0,{39,39,39,47}},	{0,{0,0,0,47}},	{0,{40,40,40,47}},
{0,{47,47,47,47}},	{0,{47,47,47,47}},	{0,{47,47,47,47}},
{0,{47,47,47,47}},	{0,{47,47,47,47}},	{0,{0,0,0,47}},
{0,{0,0,0,47}},	{0,{0,0,0,47}},	{0,{47,47,47,47}},
{0,{47,47,47,47}},	{0,{0,0,0,47}},	{0,{47,47,47,47}},
{0,{47,47,47,47}},	{0,{0,0,0,47}},	{0,{0,0,0,47}},
{0,{0,0,0,47}},	{0,{47,47,47,47}},	{0,{47,47,47,47}},
{0,{0,0,0,47}},	{0,{47,47,47,0}},	{0,{47,47,47,0}},
{0,{0,0,0,47}},	{0,{0,0,0,47}},	{0,{47,47,47,47}},
{0,{0,0,0,47}},	{0,{47,47,47,47}},	{0,{0,0,0,47}},
{0,{0,0,0,47}},	{0,{0,0,0,47}},	{0,{47,48,47,49}},
{0,{47,47,47,48}},	{0,{48,49,48,50}},	{0,{48,48,48,49}},
{0,{49,45,49,45}},	{0,{44,44,44,44}},	{0,{48,46,48,46}},
{0,{45,45,45,45}},	{0,{47,47,47,0}},	{0,{47,48,47,48}},
{0,{47,47,47,47}},	{0,{47,0,47,0}},	{0,{47,43,47,0}},
{0,{47,47,47,44}},	{0,{35,35,35,47}},	{0,{37,37,37,47}},
{0,{0,0,0,47}},	{0,{40,40,40,47}},	{0,{47,47,47,47}},
{0,{47,47,47,47}},	{0,{47,47,47,47}},	{0,{47,47,47,47}},
{0,{47,47,47,47}},	{0,{0,0,0,47}},	{0,{0,0,0,47}},
{0,{0,0,0,47}},	{0,{47,47,47,47}},	{0,{47,47,47,47}},
{0,{0,0,0,47}},	{0,{47,47,47,48}},	{0,{47,47,47,47}},
{0,{0,0,0,47}},	{0,{0,0,0,47}},	{0,{0,0,0,47}},
{0,{47,47,47,47}},	{0,{47,47,47,47}},	{0,{47,0,0,0}},
{0,{0,47,0,0}},	{0,{0,47,0,0}},	{0,{47,0,0,0}},
{0,{47,0,0,0}},	{0,{47,47,47,47}},	{0,{47,0,0,0}},
{0,{47,0,0,0}},	{0,{0,0,0,47}},	{0,{0,0,0,47}},
{0,{47,0,0,0}},	{0,{47,48,48,49}},	{0,{49,48,48,48}},
{0,{49,50,50,50}},	{0,{50,51,51,52}},	{0,{52,51,51,51}},
{0,{52,0,0,0}},	{0,{52,53,53,46}},	{0,{53,54,54,0}},
{0,{47,47,47,47}},	{0,{50,50,50,43}},	{0,{42,42,42,42}},
{0,{50,50,50,0}},	{0,{42,42,42,43}},	{0,{36,36,36,36}},
{0,{48,38,38,38}},	{0,{48,0,0,0}},	{0,{48,0,0,0}},
{0,{48,35,35,35}},	{0,{48,34,34,34}},	{0,{48,0,0,0}},
{0,{48,0,0,0}},	{0,{48,0,0,0}},	{0,{48,48,48,48}},
{0,{0,0,0,48}},	{0,{0,0,0,48}},	{0,{0,0,0,48}},
{0,{48,0,48,0}},	{0,{48,48,48,48}},	{0,{48,48,48,48}},
{0,{48,48,48,48}},	{0,{48,48,48,48}},	{0,{0,0,0,48}},
{0,{0,0,0,48}},	{0,{0,0,0,48}},	{0,{48,48,48,0}},
{0,{48,48,48,48}},	{3,{0,0,0,0}},	{6,{0,0,0,0}},
{5,{0,0,0,0}},	{0,{0,0,0,45}},	{12,{0,0,0,0}},
{0,{44,44,44,44}},	{68,{0,0,0,0}},	{0,{43,0,0,0}},
{0,{0,0,0,43}},	{0,{0,0,0,43}},	{0,{43,0,0,0}},
{0,{43,44,45,46}},	{0,{43,43,44,45}},	{0,{45,45,44,44}},
{0,{45,44,43,43}},	{0,{45,46,0,0}},	{0,{45,45,0,0}},
{0,{45,39,39,40}},	{0,{38,38,38,39}},	{0,{38,38,38,38}},
{0,{43,37,37,37}},	{0,{43,0,0,0}},	{0,{43,44,45,0}},
{0,{43,43,44,0}},	{0,{44,43,43,0}},	{0,{42,42,42,0}},
{0,{43,44,45,45}},	{0,{45,44,44,44}},	{0,{43,43,43,43}},
{0,{41,41,42,42}},	{0,{43,43,44,44}},	{0,{43,43,43,43}},
{0,{43,43,42,42}},	{0,{43,43,0,0}},	{0,{43,0,0,0}},
{0,{0,0,0,43}},	{0,{0,0,0,43}},	{0,{0,0,0,43}},
{183,{0,0,0,0}},	{0,{42,0,42,0}},	{0,{42,0,0,0}},
{0,{42,42,42,42}},	{0,{42,42,42,42}},	{0,{0,0,0,42}},
{0,{0,0,0,42}},	{0,{0,0,0,42}},	{0,{42,42,0,0}},
{0,{42,42,42,42}},	{9,{0,0,0,0}},	{0,{41,0,0,0}},
{116,{0,0,0,0}},	{0,{40,40,40,40}},	{0,{0,0,0,40}},
{0,{40,0,0,0}},	{0,{40,41,42,42}},	{0,{42,40,41,41}},
{0,{42,43,0,0}},	{0,{43,0,0,0}},	{0,{43,38,38,38}},
{0,{43,37,37,37}},	{0,{43,36,36,36}},	{0,{35,35,35,35}},
{0,{42,37,0,0}},	{0,{42,0,0,0}},	{0,{42,0,0,0}},
{0,{42,30,31,31}},	{0,{29,29,30,30}},	{0,{32,32,0,0}},
{0,{40,31,0,0}},	{0,{40,27,27,27}},	{0,{40,26,26,26}},
{0,{40,0,0,0}},	{0,{40,0,0,0}},	{0,{23,23,23,40}},
{0,{0,0,0,40}},	{0,{0,0,0,40}},	{0,{0,0,0,40}},
{168,{0,0,0,0}},	{0,{39,39,0,0}},	{0,{0,0,0,39}},
{0,{39,0,0,0}},	{189,{0,0,0,0}},	{0,{38,38,38,38}},
{0,{38,39,0,0}},	{0,{38,38,0,0}},	{0,{38,0,0,0}},
{0,{38,0,38,0}},	{0,{38,0,0,0}},	{364,{0,0,0,0}},
{0,{37,0,37,0}},	{0,{37,37,37,37}},	{0,{37,0,0,0}},
{0,{0,0,0,37}},	{0,{0,0,0,37}},	{0,{37,37,38,38}},
{0,{38,38,0,0}},	{0,{38,38,0,0}},	{0,{38,38,35,35}},
{0,{38,38,34,34}},	{0,{38,38,0,0}},	{0,{32,32,32,32}},
{0,{37,37,31,31}},	{0,{37,37,30,30}},	{0,{37,37,0,0}},
{0,{37,37,28,28}},	{0,{37,37,27,27}},	{0,{37,37,0,0}},
{0,{37,37,0,0}},	{0,{37,37,0,0}},	{0,{37,37,38,38}},
{0,{38,38,37,37}},	{0,{36,36,36,36}},	{0,{37,37,35,35}},
{0,{37,37,38,38}},	{0,{37,37,37,37}},	{0,{37,37,37,37}},
{0,{37,37,37,37}},	{169,{0,0,0,0}},	{0,{36,36,36,36}},
{172,{0,0,0,0}},	{0,{35,0,0,0}},	{0,{35,35,35,35}},
{0,{35,35,35,35}},	{266,{0,0,0,0}},	{334,{0,0,0,0}},
{347,{0,0,0,0}},	{401,{0,0,0,0}},	{0,{0,0,0,31}},
{117,{0,0,0,0}},	{0,{30,0,0,0}},	{0,{30,30,30,30}},
{154,{30,30,30,30}},	{0,{30,30,30,30}},	{154,{30,30,30,30}},
{0,{29,29,29,29}},	{154,{29,29,29,29}},	{154,{26,26,26,26}},
{154,{0,0,0,0}},	{0,{26,26,26,26}},	{0,{22,22,22,22}},
{0,{25,25,25,25}},	{154,{25,25,25,25}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{154,{21,21,21,21}},	{154,{22,22,22,22}},
{0,{19,19,19,22}},	{0,{0,0,0,22}},	{0,{15,15,15,22}},
{0,{18,18,18,22}},	{0,{13,13,13,22}},	{0,{0,0,0,22}},
{0,{0,0,0,22}},	{0,{0,0,0,22}},	{0,{0,0,0,22}},
{0,{22,22,22,22}},	{0,{22,22,22,22}},	{0,{22,22,22,22}},
{0,{22,22,22,22}},	{124,{0,0,0,0}},	{0,{0,0,0,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{0,0,0,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{18,18,18,21}},	{0,{0,0,0,21}},
{0,{14,14,14,21}},	{0,{17,17,17,21}},	{0,{12,12,12,21}},
{0,{0,0,0,21}},	{0,{0,0,0,21}},	{0,{0,0,0,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{0,0,0,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{18,18,18,21}},	{0,{0,0,0,21}},
{0,{14,14,14,21}},	{0,{17,17,17,21}},	{0,{12,12,12,21}},
{0,{0,0,0,21}},	{0,{0,0,0,21}},	{0,{0,0,0,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{25,{0,0,0,0}},	{0,{20,20,20,0}},
{0,{20,20,20,21}},	{0,{21,21,21,0}},	{0,{21,21,21,21}},
{0,{21,21,21,20}},	{0,{17,17,17,17}},	{0,{20,20,20,21}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{12,12,12,20}},
{0,{0,0,0,20}},	{0,{0,0,0,20}},	{0,{0,0,0,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,5,5,0}},
{0,{20,0,0,0}},	{0,{20,20,20,20}},	{0,{20,20,20,21}},
{0,{20,20,20,20}},	{0,{20,20,20,0}},	{0,{20,20,20,20}},
{0,{20,20,20,19}},	{0,{20,20,20,21}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{161,{12,12,12,12}},	{161,{0,0,0,0}},
{162,{0,0,0,0}},	{163,{0,0,0,0}},	{0,{16,16,0,0}},
{0,{16,16,16,16}},	{0,{16,5,5,0}},	{0,{16,0,0,0}},
{0,{16,16,16,16}},	{155,{16,16,16,16}},	{0,{15,15,15,15}},
{155,{0,0,0,0}},	{0,{14,14,14,14}},	{155,{13,13,13,13}},
{155,{13,13,13,13}},	{0,{12,12,12,12}},	{0,{12,12,12,12}},
{0,{12,12,12,12}},	{0,{12,12,12,12}},	{0,{12,12,12,12}},
{0,{12,12,12,12}},	{0,{12,12,12,12}},	{155,{12,12,12,12}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,0}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{0,0,0,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{0,{11,11,11,11}},	{0,{11,11,11,11}},	{0,{11,11,11,11}},
{171,{0,0,0,0}},	{0,{10,10,10,10}},	{0,{10,10,10,10}},
{0,{0,0,0,10}},	{0,{10,10,10,10}},	{0,{10,10,10,10}},
{0,{10,10,10,10}},	{0,{10,10,10,10}},	{0,{10,10,10,10}},
{0,{10,10,10,10}},	{0,{10,10,10,10}},	{0,{10,10,10,10}},
{0,{10,10,10,10}},	{0,{0,0,0,10}},	{0,{10,10,10,10}},
{0,{10,10,10,10}},	{0,{10,10,10,10}},	{0,{10,10,10,10}},
{0,{10,10,10,10}},	{0,{10,10,10,10}},	{0,{10,10,10,10}},
{0,{10,10,10,10}},	{0,{10,10,10,10}},	{0,{0,0,0,10}},
{0,{10,10,10,10}},	{0,{10,10,10,10}},	{0,{10,10,10,10}},
{0,{7,7,7,10}},	{0,{0,0,0,10}},	{0,{6,6,6,10}},
{0,{6,6,6,10}},	{0,{0,0,0,10}},	{0,{10,10,10,10}},
{0,{0,0,0,10}},	{0,{10,10,10,10}},	{0,{10,10,10,10}},
{0,{10,10,10,10}},	{0,{7,7,7,10}},	{0,{0,0,0,10}},
{0,{6,6,6,10}},	{0,{6,6,6,10}},	{0,{0,0,0,10}},
{0,{10,10,10,10}},	{0,{0,0,0,10}},	{0,{10,10,10,10}},
{0,{10,10,10,10}},	{0,{10,10,10,10}},	{0,{7,7,7,10}},
{0,{0,0,0,10}},	{0,{6,6,6,10}},	{0,{6,6,6,10}},
{0,{0,0,0,10}},	{0,{10,10,10,10}},	{0,{0,0,0,10}},
{0,{10,10,10,10}},	{0,{10,10,10,10}},	{0,{10,10,10,10}},
{0,{7,7,7,10}},	{0,{0,0,0,10}},	{0,{6,6,6,10}},
{0,{6,6,6,10}},	{0,{0,0,0,10}},	{0,{10,10,10,10}},
{0,{0,0,0,10}},	{0,{10,10,10,10}},	{0,{10,10,10,10}},
{0,{10,10,10,10}},	{0,{7,7,7,10}},	{0,{0,0,0,10}},
{0,{6,6,6,10}},	{0,{6,6,6,10}},	{0,{0,0,0,10}},
{0,{10,10,10,10}},	{0,{10,0,0,0}},	{0,{10,11,11,11}},
{0,{10,10,10,10}},	{0,{10,0,0,0}},	{0,{10,8,8,8}},
{0,{10,0,0,0}},	{0,{10,6,6,6}},	{0,{10,0,0,0}},
{0,{10,10,10,10}},	{0,{10,10,10,10}},	{144,{0,0,0,0}},
{0,{9,9,0,0}},	{0,{9,9,0,0}},	{0,{9,9,0,0}},
{160,{6,6,0,0}},	{160,{0,0,0,0}},	{160,{5,5,0,0}},
{160,{5,5,0,0}},	{0,{5,0,0,0}},	{0,{5,5,5,5}},
{157,{0,0,0,0}},	{156,{0,0,0,0}},	{158,{0,0,0,0}},
{197,{0,0,0,0}},	{0,{1,1,1,1}},	{0,{1,1,1,1}},
{0,{1,1,1,1}},	{0,{1,1,1,1}},	{0,{1,1,1,1}},
{0,{1,1,1,1}},	{0,{1,1,1,1}},	{0,{1,0,0,0}},
{200,{0,0,0,0}},	};

static const attrib_rt_t idx_owl_attackpat[422] = {
{-1,0},	{60,0},	{102,0},	{35,0},
{59,0},	{282,0},	{283,5},	{25,0},
{48,7},	{362,0},	{104,0},	{103,10},
{15,0},	{115,0},	{83,0},	{82,0},
{20,0},	{220,0},	{257,0},	{175,0},
{242,0},	{243,20},	{289,0},	{245,0},
{258,0},	{68,0},	{233,0},	{108,26},
{31,0},	{53,0},	{268,0},	{269,30},
{230,31},	{231,32},	{84,0},	{84,11},
{79,0},	{80,36},	{251,0},	{249,38},
{250,0},	{249,0},	{262,0},	{261,42},
{249,43},	{239,0},	{288,45},	{240,46},
{256,0},	{240,45},	{280,0},	{222,0},
{348,0},	{280,40},	{73,0},	{268,54},
{269,55},	{230,56},	{231,57},	{325,0},
{193,0},	{125,0},	{126,0},	{119,0},
{36,0},	{315,0},	{316,0},	{63,0},
{61,0},	{270,0},	{271,0},	{272,70},
{272,0},	{1,0},	{50,0},	{51,74},
{42,0},	{40,76},	{41,77},	{114,78},
{0,0},	{43,76},	{40,81},	{41,82},
{114,83},	{57,0},	{54,85},	{72,0},
{56,87},	{56,0},	{54,0},	{216,0},
{217,91},	{58,0},	{110,0},	{152,0},
{179,0},	{181,0},	{40,0},	{41,98},
{114,99},	{340,0},	{218,0},	{219,102},
{140,0},	{224,104},	{224,0},	{216,106},
{217,107},	{286,0},	{287,109},	{284,110},
{285,111},	{192,0},	{191,113},	{220,106},
{279,0},	{291,0},	{345,0},	{341,0},
{293,0},	{5,0},	{290,0},	{37,0},
{227,0},	{49,0},	{44,0},	{6,0},
{4,0},	{24,0},	{12,0},	{247,0},
{255,0},	{184,0},	{52,0},	{195,0},
{107,0},	{112,0},	{305,0},	{273,0},
{149,0},	{381,0},	{194,0},	{338,0},
{301,0},	{171,0},	{98,0},	{246,0},
{343,0},	{55,0},	{18,0},	{23,0},
{248,0},	{91,0},	{93,0},	{90,0},
{235,0},	{94,156},	{94,0},	{234,0},
{361,0},	{9,0},	{13,161},	{13,0},
{87,0},	{266,0},	{267,165},	{264,166},
{16,0},	{75,0},	{117,0},	{331,0},
{318,0},	{26,0},	{27,0},	{28,0},
{154,0},	{30,0},	{368,0},	{62,0},
{109,0},	{120,180},	{120,0},	{97,0},
{121,0},	{335,0},	{209,0},	{363,0},
{11,0},	{238,0},	{69,0},	{274,0},
{244,191},	{85,0},	{162,0},	{164,194},
{163,0},	{17,0},	{206,0},	{364,0},
{92,0},	{264,0},	{99,201},	{100,202},
{86,0},	{88,0},	{159,0},	{172,0},
{237,0},	{232,0},	{208,0},	{209,210},
{186,0},	{236,0},	{116,0},	{339,0},
{160,0},	{81,0},	{187,0},	{178,0},
{161,0},	{46,0},	{45,221},	{45,0},
{131,0},	{320,0},	{150,0},	{133,0},
{202,0},	{19,0},	{153,0},	{67,0},
{177,0},	{383,0},	{134,0},	{312,0},
{380,0},	{71,0},	{223,0},	{275,0},
{276,239},	{165,0},	{96,0},	{96,201},
{188,0},	{170,0},	{139,0},	{136,246},
{182,0},	{147,0},	{141,0},	{129,0},
{150,251},	{137,0},	{47,0},	{306,0},
{150,255},	{351,223},	{351,0},	{207,0},
{322,0},	{311,0},	{127,0},	{357,0},
{358,0},	{347,0},	{7,0},	{333,0},
{353,0},	{360,0},	{332,0},	{33,0},
{34,0},	{377,0},	{145,178},	{369,0},
{373,0},	{375,0},	{373,277},	{263,0},
{70,0},	{203,0},	{74,0},	{319,0},
{367,0},	{142,0},	{204,0},	{205,286},
{144,0},	{302,0},	{317,0},	{346,0},
{95,0},	{253,0},	{265,0},	{128,0},
{296,0},	{297,296},	{212,297},	{213,298},
{214,0},	{215,300},	{382,0},	{277,0},
{241,201},	{221,0},	{180,0},	{294,0},
{295,307},	{38,0},	{39,309},	{298,0},
{214,311},	{215,312},	{372,0},	{330,0},
{376,0},	{371,0},	{174,0},	{356,0},
{366,0},	{365,320},	{101,0},	{166,0},
{228,0},	{229,324},	{106,0},	{105,326},
{32,0},	{29,328},	{321,0},	{329,0},
{308,0},	{226,0},	{210,0},	{211,0},
{111,0},	{169,0},	{118,0},	{303,0},
{176,0},	{173,0},	{132,0},	{130,0},
{138,0},	{167,0},	{135,246},	{379,0},
{378,0},	{146,0},	{350,0},	{344,0},
{201,0},	{352,0},	{198,0},	{76,0},
{77,355},	{78,0},	{3,0},	{122,0},
{10,0},	{299,0},	{185,0},	{8,0},
{334,0},	{64,0},	{310,0},	{313,0},
{314,0},	{313,368},	{113,0},	{225,0},
{155,0},	{156,0},	{183,0},	{342,0},
{336,0},	{252,0},	{292,0},	{151,0},
{254,0},	{151,377},	{158,0},	{327,0},
{190,0},	{278,0},	{260,0},	{200,0},
{196,0},	{197,0},	{328,0},	{124,0},
{323,0},	{199,0},	{300,0},	{22,0},
{281,0},	{337,0},	{355,0},	{66,0},
{157,0},	{168,0},	{354,0},	{65,0},
{259,0},	{123,0},	{324,0},	{326,0},
{148,0},	{370,0},	{374,0},	{143,0},
{349,0},	{359,0},	{307,0},	{309,414},
{304,0},	{21,0},	{14,0},	{2,418},
{89,0},	{189,0},	};

static dfa_rt_t dfa_owl_attackpat = {
 "owl_attackpat",
state_owl_attackpat,
idx_owl_attackpat};

struct pattern_db owl_attackpat_db = {
  -1,
  0,
  owl_attackpat
 ,& dfa_owl_attackpat
};
