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

static struct patval owl_defendpat0[] = {
  {684,2},	{685,2}
};

static struct patval owl_defendpat1[] = {
  {684,2},	{647,4}
};

static struct patval owl_defendpat2[] = {
  {648,2}
};

static struct patval owl_defendpat3[] = {
  {684,2},	{683,4}
};

static struct patval owl_defendpat4[] = {
  {684,2}
};

static struct patval owl_defendpat5[] = {
  {684,2},	{685,2}
};

static struct patval owl_defendpat6[] = {
  {685,2},	{648,2}
};

static struct patval owl_defendpat7[] = {
  {685,2},	{683,2},	{648,2}
};

static struct patval owl_defendpat8[] = {
  {757,2},	{684,2}
};

static struct patval owl_defendpat9[] = {
  {684,2},	{757,2},	{683,2}
};

static struct patval owl_defendpat10[] = {
  {684,2},	{723,2},	{722,2},	{758,4}
};

static struct patval owl_defendpat11[] = {
  {684,2},	{648,2},	{611,2}
};

static struct patval owl_defendpat12[] = {
  {758,2}
};

static struct patval owl_defendpat13[] = {
  {757,2},	{684,2}
};

static struct patval owl_defendpat14[] = {
  {684,2},	{757,2}
};

static struct patval owl_defendpat15[] = {
  {684,2},	{759,2},	{796,2},	{758,4}
};

static struct patval owl_defendpat16[] = {
  {648,2}
};

static struct patval owl_defendpat17[] = {
  {684,2},	{833,4},	{870,4},	{685,4},
  {871,4},	{683,4}
};

static struct patval owl_defendpat18[] = {
  {684,2}
};

static struct patval owl_defendpat19[] = {
  {686,2}
};

static struct patval owl_defendpat20[] = {
  {649,2},	{760,4}
};

static struct patval owl_defendpat21[] = {
  {684,2},	{649,2}
};

static struct patval owl_defendpat22[] = {
  {684,2},	{759,2},	{611,4}
};

static struct patval owl_defendpat23[] = {
  {684,2},	{722,2}
};

static struct patval owl_defendpat24[] = {
  {720,2},	{757,2},	{684,2}
};

static struct patval owl_defendpat25[] = {
  {684,2},	{648,4}
};

static struct patval owl_defendpat26[] = {
  {832,2}
};

static struct patval owl_defendpat27[] = {
  {684,2},	{683,2}
};

static struct patval owl_defendpat28[] = {
  {684,2},	{686,2},	{649,2},	{683,4}
};

static struct patval owl_defendpat29[] = {
  {647,2},	{684,2},	{759,4},	{758,4},
  {760,4}
};

static struct patval owl_defendpat30[] = {
  {723,2},	{610,4},	{611,4},	{721,4}
};

static struct patval owl_defendpat31[] = {
  {684,2},	{718,2},	{793,4},	{792,4},
  {755,4},	{756,4}
};

static struct patval owl_defendpat32[] = {
  {686,2},	{646,2},	{724,4},	{719,4},
  {682,4},	{608,4},	{645,4},	{687,4}
};

static struct patval owl_defendpat33[] = {
  {647,2},	{684,2}
};

static struct patval owl_defendpat34[] = {
  {684,2},	{647,2}
};

static struct patval owl_defendpat35[] = {
  {684,2},	{647,2}
};

static struct patval owl_defendpat36[] = {
  {648,2}
};

static struct patval owl_defendpat37[] = {
  {684,2}
};

static struct patval owl_defendpat38[] = {
  {684,2},	{648,2}
};

static struct patval owl_defendpat39[] = {
  {684,2},	{647,4}
};

static struct patval owl_defendpat40[] = {
  {684,2},	{649,4},	{648,4}
};

static struct patval owl_defendpat41[] = {
  {687,2},	{650,4}
};

static struct patval owl_defendpat42[] = {
  {757,2},	{720,2}
};

static struct patval owl_defendpat43[] = {
  {757,2},	{720,2}
};

static struct patval owl_defendpat44[] = {
  {684,2},	{610,4},	{611,4}
};

static struct patval owl_defendpat45[] = {
  {721,2},	{684,2},	{759,2}
};

static struct patval owl_defendpat46[] = {
  {684,2},	{757,2},	{720,2}
};

static struct patval owl_defendpat47[] = {
  {684,2},	{648,2},	{646,2},	{759,4}
};

static struct patval owl_defendpat48[] = {
  {684,2}
};

static struct patval owl_defendpat49[] = {
  {684,2},	{647,4}
};

static struct patval owl_defendpat50[] = {
  {758,2},	{721,2}
};

static struct patval owl_defendpat51[] = {
  {722,2},	{684,2}
};

static struct patval owl_defendpat52[] = {
  {684,2},	{683,4}
};

static struct patval owl_defendpat53[] = {
  {684,2}
};

static struct patval owl_defendpat54[] = {
  {684,2},	{683,2},	{794,2}
};

static struct patval owl_defendpat55[] = {
  {684,2},	{683,2},	{796,4}
};

static struct patval owl_defendpat56[] = {
  {684,2},	{759,2},	{796,2},	{758,4}
};

static struct patval owl_defendpat57[] = {
  {684,2},	{647,4},	{720,4},	{683,4}
};

static struct patval owl_defendpat58[] = {
  {684,2},	{720,4},	{683,4}
};

static struct patval owl_defendpat59[] = {
  {684,2},	{685,2},	{683,4},	{720,4}
};

static struct patval owl_defendpat60[] = {
  {685,2},	{648,2}
};

static struct patval owl_defendpat61[] = {
  {757,2},	{684,2},	{611,4},	{610,4}
};

static struct patval owl_defendpat62[] = {
  {684,2},	{683,4},	{720,4}
};

static struct patval owl_defendpat63[] = {
  {684,2},	{610,2},	{573,2},	{685,2}
};

static struct patval owl_defendpat64[] = {
  {649,2},	{721,2},	{686,4},	{648,4}
};

static struct patval owl_defendpat65[] = {
  {646,2},	{722,2},	{721,2},	{723,4}
};

static struct patval owl_defendpat66[] = {
  {648,2},	{647,2},	{720,2},	{722,2},
  {649,4}
};

static struct patval owl_defendpat67[] = {
  {647,2},	{685,2},	{645,4},	{646,4},
  {682,4}
};

static struct patval owl_defendpat68[] = {
  {721,2},	{684,2},	{759,4}
};

static struct patval owl_defendpat69[] = {
  {684,2},	{759,4},	{757,4},	{758,4},
  {683,4},	{720,4}
};

static struct patval owl_defendpat70[] = {
  {720,2},	{684,2},	{758,2},	{722,2}
};

static struct patval owl_defendpat71[] = {
  {684,2},	{647,4},	{610,4},	{574,4},
  {611,4},	{612,4},	{649,4},	{573,4},
  {575,4}
};

static struct patval owl_defendpat72[] = {
  {721,2},	{720,4}
};

static struct patval owl_defendpat73[] = {
  {684,2}
};

static struct patval owl_defendpat74[] = {
  {684,2},	{721,2}
};

static struct patval owl_defendpat75[] = {
  {722,2}
};

static struct patval owl_defendpat76[] = {
  {683,2},	{684,2}
};

static struct patval owl_defendpat77[] = {
  {648,2},	{647,2}
};

static struct patval owl_defendpat78[] = {
  {759,2}
};

static struct patval owl_defendpat79[] = {
  {687,2},	{650,4}
};

static struct patval owl_defendpat80[] = {
  {685,2},	{759,2}
};

static struct patval owl_defendpat81[] = {
  {684,2},	{686,4}
};

static struct patval owl_defendpat82[] = {
  {648,2},	{723,4},	{722,4},	{721,4}
};

static struct patval owl_defendpat83[] = {
  {648,2},	{723,4},	{722,4},	{721,4}
};

static struct patval owl_defendpat84[] = {
  {648,2}
};

static struct patval owl_defendpat85[] = {
  {684,2},	{720,2},	{648,4},	{685,4},
  {682,4}
};

static struct patval owl_defendpat86[] = {
  {684,2},	{720,2},	{648,4},	{685,4},
  {682,4}
};

static struct patval owl_defendpat87[] = {
  {647,2},	{722,2}
};

static struct patval owl_defendpat88[] = {
  {684,2}
};

static struct patval owl_defendpat89[] = {
  {647,2},	{610,2},	{685,2}
};

static struct patval owl_defendpat90[] = {
  {647,2},	{648,2},	{684,2},	{723,4},
  {686,4},	{649,4}
};

static struct patval owl_defendpat91[] = {
  {684,2},	{686,2}
};

static struct patval owl_defendpat92[] = {
  {648,2},	{647,2}
};

static struct patval owl_defendpat93[] = {
  {646,2},	{683,2},	{647,2},	{685,2},
  {720,4}
};

static struct patval owl_defendpat94[] = {
  {647,2},	{685,2},	{648,4}
};

static struct patval owl_defendpat95[] = {
  {684,2},	{646,2},	{720,4},	{610,4}
};

static struct patval owl_defendpat96[] = {
  {684,2}
};

static struct patval owl_defendpat97[] = {
  {684,2}
};

static struct patval owl_defendpat98[] = {
  {684,2}
};

static struct patval owl_defendpat99[] = {
  {722,2},	{686,2}
};

static struct patval owl_defendpat100[] = {
  {649,2},	{686,4}
};

static struct patval owl_defendpat101[] = {
  {684,2},	{648,4},	{647,4}
};

static struct patval owl_defendpat102[] = {
  {721,2},	{684,2},	{647,4},	{610,4}
};

static struct patval owl_defendpat103[] = {
  {722,2},	{759,2},	{684,2}
};

static struct patval owl_defendpat104[] = {
  {684,2},	{720,2},	{646,4},	{683,4}
};

static struct patval owl_defendpat105[] = {
  {684,2},	{647,4}
};

static struct patval owl_defendpat106[] = {
  {720,2},	{757,2},	{684,2}
};

static struct patval owl_defendpat107[] = {
  {757,2},	{684,2},	{758,2}
};

static struct patval owl_defendpat108[] = {
  {722,2},	{647,2},	{684,2}
};

static struct patval owl_defendpat109[] = {
  {684,2},	{722,2}
};

static struct patval owl_defendpat110[] = {
  {684,2},	{647,2},	{722,2}
};

static struct patval owl_defendpat111[] = {
  {684,2},	{722,2}
};

static struct patval owl_defendpat112[] = {
  {721,2},	{684,2},	{609,4}
};

static struct patval owl_defendpat113[] = {
  {610,2},	{684,2},	{721,2},	{609,4}
};

static struct patval owl_defendpat114[] = {
  {648,2},	{684,2}
};

static struct patval owl_defendpat115[] = {
  {721,2},	{647,2},	{685,2}
};

static struct patval owl_defendpat116[] = {
  {721,2},	{720,2},	{685,2},	{649,2},
  {646,4}
};

static struct patval owl_defendpat117[] = {
  {684,2},	{720,2}
};

static struct patval owl_defendpat118[] = {
  {684,2},	{720,2},	{796,4},	{795,4},
  {794,4},	{797,4}
};

static struct patval owl_defendpat119[] = {
  {723,2},	{722,2},	{684,2},	{649,4}
};

static struct patval owl_defendpat120[] = {
  {684,2},	{611,2},	{647,2},	{722,2}
};

static struct patval owl_defendpat121[] = {
  {722,2},	{758,2},	{684,2},	{759,4},
  {757,4}
};

static struct patval owl_defendpat122[] = {
  {758,2},	{684,2},	{722,2},	{759,4},
  {757,4}
};

static struct patval owl_defendpat123[] = {
  {722,2},	{723,2},	{684,2},	{686,2}
};

static struct patval owl_defendpat124[] = {
  {722,2},	{686,2},	{684,2}
};

static struct patval owl_defendpat125[] = {
  {684,2},	{721,2},	{647,4}
};

static struct patval owl_defendpat126[] = {
  {721,2},	{758,2},	{684,2},	{647,2},
  {610,2}
};

static struct patval owl_defendpat127[] = {
  {686,2},	{611,2},	{722,2},	{684,2},
  {721,4},	{647,4}
};

static struct patval owl_defendpat128[] = {
  {722,2},	{684,2},	{686,2}
};

static struct patval owl_defendpat129[] = {
  {721,2},	{647,2}
};

static struct patval owl_defendpat130[] = {
  {721,2},	{684,2},	{647,4}
};

static struct patval owl_defendpat131[] = {
  {684,2},	{683,4},	{682,4}
};

static struct patval owl_defendpat132[] = {
  {684,2},	{686,2}
};

static struct patval owl_defendpat133[] = {
  {758,2},	{720,2},	{684,2},	{722,2},
  {647,2},	{683,4},	{610,4}
};

static struct patval owl_defendpat134[] = {
  {758,2},	{685,2},	{684,2},	{720,2},
  {757,4}
};

static struct patval owl_defendpat135[] = {
  {683,2},	{646,2},	{758,2},	{759,2},
  {720,2},	{611,2},	{610,2}
};

static struct patval owl_defendpat136[] = {
  {684,2},	{683,2},	{723,2},	{760,2},
  {756,2},	{685,2},	{719,2}
};

static struct patval owl_defendpat137[] = {
  {686,2},	{684,2},	{722,2},	{647,4},
  {721,4}
};

static struct patval owl_defendpat138[] = {
  {684,2},	{721,2},	{759,2},	{723,2},
  {758,4},	{611,4},	{647,4},	{610,4}
};

static struct patval owl_defendpat139[] = {
  {648,2},	{723,2},	{686,2},	{684,2},
  {647,4}
};

static struct patval owl_defendpat140[] = {
  {758,2},	{684,2},	{720,2},	{722,2},
  {646,4},	{759,4}
};

static struct patval owl_defendpat141[] = {
  {722,2},	{720,2},	{758,2},	{684,2},
  {683,4},	{796,4}
};

static struct patval owl_defendpat142[] = {
  {758,2},	{722,2},	{684,2},	{720,2},
  {759,4},	{646,4},	{796,4}
};

static struct patval owl_defendpat143[] = {
  {684,2},	{722,2},	{758,2},	{720,2},
  {759,4}
};

static struct patval owl_defendpat144[] = {
  {721,2},	{683,2},	{685,2},	{722,4}
};

static struct patval owl_defendpat145[] = {
  {720,2},	{758,2},	{722,2},	{684,2},
  {759,2},	{683,4}
};

static struct patval owl_defendpat146[] = {
  {682,2},	{648,2},	{720,2},	{646,2},
  {684,2},	{647,4}
};

static struct patval owl_defendpat147[] = {
  {683,2},	{647,2},	{721,2},	{758,4}
};

static struct patval owl_defendpat148[] = {
  {757,2},	{722,2},	{684,2},	{720,2}
};

static struct patval owl_defendpat149[] = {
  {757,2},	{758,2},	{684,2},	{759,4}
};

static struct patval owl_defendpat150[] = {
  {684,2},	{720,2},	{646,4}
};

static struct patval owl_defendpat151[] = {
  {647,2},	{684,2}
};

static struct patval owl_defendpat152[] = {
  {720,2},	{684,2},	{759,2},	{758,2}
};

static struct patval owl_defendpat153[] = {
  {684,2},	{721,2},	{686,2}
};

static struct patval owl_defendpat154[] = {
  {684,2},	{648,2},	{647,2},	{649,2},
  {650,2}
};

static struct patval owl_defendpat155[] = {
  {647,2},	{722,2}
};

static struct patval owl_defendpat156[] = {
  {648,2},	{649,2},	{647,2},	{646,2},
  {722,2}
};

static struct patval owl_defendpat157[] = {
  {683,2},	{721,2},	{647,2},	{648,2},
  {646,2}
};

static struct patval owl_defendpat158[] = {
  {794,2},	{757,2},	{647,2},	{683,2},
  {795,2},	{684,2},	{720,4}
};

static struct patval owl_defendpat159[] = {
  {647,2}
};

static struct patval owl_defendpat160[] = {
  {684,2},	{647,2},	{722,2},	{612,2},
  {723,2},	{611,2}
};

static struct patval owl_defendpat161[] = {
  {721,2},	{684,2},	{758,2}
};

static struct patval owl_defendpat162[] = {
  {684,2},	{722,2}
};

static struct patval owl_defendpat163[] = {
  {684,2},	{648,2},	{722,2},	{683,4},
  {721,4}
};

static struct patval owl_defendpat164[] = {
  {684,2},	{647,4}
};

static struct patval owl_defendpat165[] = {
  {684,2},	{722,2},	{573,4}
};

static struct patval owl_defendpat166[] = {
  {683,2},	{758,2},	{720,2}
};

static struct patval owl_defendpat167[] = {
  {684,2},	{648,4}
};

static struct patval owl_defendpat168[] = {
  {684,2},	{648,2},	{683,2},	{647,4},
  {720,4}
};

static struct patval owl_defendpat169[] = {
  {648,2},	{649,2},	{683,2},	{684,2},
  {720,4}
};

static struct patval owl_defendpat170[] = {
  {723,2},	{685,2},	{684,2},	{760,2},
  {686,4},	{683,4}
};

static struct patval owl_defendpat171[] = {
  {686,2},	{722,2},	{684,2},	{723,4},
  {721,4}
};

static struct patval owl_defendpat172[] = {
  {722,2},	{684,2},	{686,2}
};

static struct patval owl_defendpat173[] = {
  {684,2},	{722,2},	{686,2}
};

static struct patval owl_defendpat174[] = {
  {684,2},	{722,2},	{648,4},	{686,4}
};

static struct patval owl_defendpat175[] = {
  {684,2},	{722,2},	{648,4},	{721,4}
};

static struct patval owl_defendpat176[] = {
  {722,2},	{684,2},	{721,4}
};

static struct patval owl_defendpat177[] = {
  {684,2},	{759,4}
};

static struct patval owl_defendpat178[] = {
  {684,2},	{722,2},	{648,4},	{686,4}
};

static struct patval owl_defendpat179[] = {
  {684,2},	{759,2},	{758,2},	{685,2},
  {760,4},	{686,4}
};

static struct patval owl_defendpat180[] = {
  {723,2},	{684,2},	{721,2},	{686,2},
  {610,2},	{609,4},	{646,4},	{647,4}
};

static struct patval owl_defendpat181[] = {
  {647,2},	{722,2},	{648,2},	{721,2},
  {720,4}
};

static struct patval owl_defendpat182[] = {
  {721,2},	{722,2},	{648,2},	{684,2},
  {649,2}
};

static struct patval owl_defendpat183[] = {
  {684,2}
};

static struct patval owl_defendpat184[] = {
  {722,2}
};

static struct patval owl_defendpat185[] = {
  {723,2},	{684,2},	{721,2},	{686,2},
  {759,2}
};

static struct patval owl_defendpat186[] = {
  {684,2},	{649,2},	{722,2},	{686,2},
  {611,2}
};

static struct patval owl_defendpat187[] = {
  {684,2}
};

static struct patval owl_defendpat188[] = {
  {684,2},	{720,2}
};

static struct patval owl_defendpat189[] = {
  {722,2},	{684,2},	{686,2},	{723,4}
};

static struct patval owl_defendpat190[] = {
  {649,2},	{650,2},	{684,2},	{723,2},
  {722,4},	{687,4}
};

static struct patval owl_defendpat191[] = {
  {721,2},	{646,2},	{683,2},	{685,2},
  {720,4}
};

static struct patval owl_defendpat192[] = {
  {684,2},	{758,2},	{686,2},	{759,2}
};

static struct patval owl_defendpat193[] = {
  {684,2},	{722,2},	{610,4},	{611,4}
};

static struct patval owl_defendpat194[] = {
  {649,2},	{647,2},	{723,2},	{684,2},
  {648,4},	{686,4}
};

static struct patval owl_defendpat195[] = {
  {648,2},	{722,2},	{686,2},	{684,2}
};

static struct patval owl_defendpat196[] = {
  {684,2}
};

static struct patval owl_defendpat197[] = {
  {684,2}
};

static struct patval owl_defendpat198[] = {
  {684,2},	{721,4}
};

static struct patval owl_defendpat199[] = {
  {684,2}
};

static struct patval owl_defendpat200[] = {
  {647,2},	{684,2},	{721,2}
};

static struct patval owl_defendpat201[] = {
  {684,2},	{721,2}
};

static struct patval owl_defendpat202[] = {
  {721,2},	{758,2},	{684,2}
};

static struct patval owl_defendpat203[] = {
  {759,2},	{684,2},	{721,2},	{647,4},
  {760,4}
};

static struct patval owl_defendpat204[] = {
  {647,2},	{684,2},	{721,4},	{610,4},
  {612,4},	{611,4}
};

static struct patval owl_defendpat205[] = {
  {611,2},	{684,2},	{612,4},	{721,4}
};

static struct patval owl_defendpat206[] = {
  {758,2},	{721,2}
};

static struct patval owl_defendpat207[] = {
  {758,2},	{721,2}
};

static struct patval owl_defendpat208[] = {
  {758,2},	{721,2},	{759,2}
};

static struct patval owl_defendpat209[] = {
  {758,2},	{721,2},	{759,2}
};

static struct patval owl_defendpat210[] = {
  {684,2},	{610,4},	{647,4}
};

static struct patval owl_defendpat211[] = {
  {683,2},	{684,2},	{757,4},	{758,4},
  {647,4},	{720,4}
};

static struct patval owl_defendpat212[] = {
  {684,2},	{648,2},	{686,4},	{649,4}
};

static struct patval owl_defendpat213[] = {
  {648,2},	{684,2},	{720,4},	{683,4}
};

static struct patval owl_defendpat214[] = {
  {684,2}
};

static struct patval owl_defendpat215[] = {
  {647,2},	{683,2},	{649,2},	{684,2},
  {648,2}
};

static struct patval owl_defendpat216[] = {
  {685,2},	{720,2},	{683,2},	{648,2},
  {684,2}
};

static struct patval owl_defendpat217[] = {
  {646,2},	{682,2},	{719,2}
};

static struct patval owl_defendpat218[] = {
  {646,2},	{682,2},	{719,2}
};

static struct patval owl_defendpat219[] = {
  {648,2},	{684,2},	{683,2}
};

static struct patval owl_defendpat220[] = {
  {648,2},	{684,2},	{683,2}
};

static struct patval owl_defendpat221[] = {
  {722,2},	{684,2},	{647,2},	{649,4},
  {648,4}
};

static struct patval owl_defendpat222[] = {
  {684,2},	{648,2},	{646,4},	{683,4}
};

static struct patval owl_defendpat223[] = {
  {684,2},	{648,2},	{720,2},	{646,4}
};

static struct patval owl_defendpat224[] = {
  {684,2},	{720,2},	{648,2},	{758,4},
  {757,4},	{649,4},	{686,4}
};

static struct patval owl_defendpat225[] = {
  {684,2},	{686,2},	{647,2},	{683,2},
  {649,4}
};

static struct patval owl_defendpat226[] = {
  {723,2},	{757,2},	{758,2},	{686,2},
  {759,2},	{647,2},	{649,2}
};

static struct patval owl_defendpat227[] = {
  {719,2},	{682,2},	{756,2},	{759,2},
  {757,2},	{647,2},	{645,2},	{758,2}
};

static struct patval owl_defendpat228[] = {
  {720,2},	{684,2},	{760,2},	{758,2},
  {648,2},	{646,2},	{683,2},	{759,2}
};

static struct patval owl_defendpat229[] = {
  {646,2},	{684,2},	{720,4},	{683,4}
};

static struct patval owl_defendpat230[] = {
  {684,2},	{611,4},	{609,4},	{610,4},
  {646,4}
};

static struct patval owl_defendpat231[] = {
  {647,2},	{722,2},	{684,2},	{759,2},
  {797,4}
};

static struct patval owl_defendpat232[] = {
  {685,2},	{684,2},	{611,4},	{610,4},
  {648,4}
};

static struct patval owl_defendpat233[] = {
  {719,2},	{682,2},	{684,2},	{646,2}
};

static struct patval owl_defendpat234[] = {
  {611,2},	{720,2},	{684,2},	{646,2},
  {610,2},	{683,4}
};

static struct patval owl_defendpat235[] = {
  {760,2},	{759,2},	{721,2},	{683,2},
  {648,2},	{646,2},	{758,4},	{720,4}
};

static struct patval owl_defendpat236[] = {
  {684,2},	{720,2},	{647,4}
};

static struct patval owl_defendpat237[] = {
  {719,2},	{683,2},	{685,2},	{757,2},
  {684,2},	{686,4}
};

static struct patval owl_defendpat238[] = {
  {683,2},	{719,2},	{757,2},	{684,2},
  {685,2}
};

static struct patval owl_defendpat239[] = {
  {647,2}
};

static struct patval owl_defendpat240[] = {
  {684,2}
};

static struct patval owl_defendpat241[] = {
  {719,2},	{611,2},	{646,2},	{682,4},
  {610,4}
};

static struct patval owl_defendpat242[] = {
  {686,2},	{648,2},	{647,2},	{722,2}
};

static struct patval owl_defendpat243[] = {
  {683,2},	{720,2},	{722,2},	{721,2},
  {759,4},	{760,4}
};

static struct patval owl_defendpat244[] = {
  {757,2},	{683,2},	{722,2},	{649,2},
  {686,2},	{721,2},	{758,2}
};

static struct patval owl_defendpat245[] = {
  {684,2},	{682,2},	{683,2}
};

static struct patval owl_defendpat246[] = {
  {720,2},	{647,2},	{684,2}
};

static struct patval owl_defendpat247[] = {
  {685,2},	{684,2},	{683,2},	{682,2},
  {686,2},	{756,2},	{719,2}
};

static struct patval owl_defendpat248[] = {
  {646,2},	{684,2},	{611,4}
};

static struct patval owl_defendpat249[] = {
  {684,2}
};

static struct patval owl_defendpat250[] = {
  {684,2}
};

static struct patval owl_defendpat251[] = {
  {684,2}
};

static struct patval owl_defendpat252[] = {
  {721,2}
};

static struct patval owl_defendpat253[] = {
  {683,2},	{646,2},	{649,2}
};

static struct patval owl_defendpat254[] = {
  {683,2},	{646,2},	{649,2}
};

static struct patval owl_defendpat255[] = {
  {649,2},	{611,2},	{683,2},	{646,2},
  {610,2}
};

static struct patval owl_defendpat256[] = {
  {684,2}
};

static struct patval owl_defendpat257[] = {
  {647,2},	{645,4}
};

static struct patval owl_defendpat258[] = {
  {647,2},	{645,4}
};

static struct patval owl_defendpat259[] = {
  {608,4},	{644,4},	{682,4},	{719,4},
  {607,4},	{645,4}
};

static struct patval owl_defendpat260[] = {
  {722,2},	{684,2}
};

static struct patval owl_defendpat261[] = {
  {684,2}
};

static struct patval owl_defendpat262[] = {
  {722,2},	{684,2}
};

static struct patval owl_defendpat263[] = {
  {722,2},	{757,2},	{684,2},	{720,2},
  {794,4}
};

static struct patval owl_defendpat264[] = {
  {722,2},	{684,2}
};

static struct patval owl_defendpat265[] = {
  {684,2},	{722,2},	{647,4},	{646,4}
};

static struct patval owl_defendpat266[] = {
  {685,2},	{723,2},	{684,2}
};

static struct patval owl_defendpat267[] = {
  {685,2},	{684,2},	{723,2},	{759,4},
  {758,4},	{757,4},	{760,4},	{683,4}
};

static struct patval owl_defendpat268[] = {
  {722,2},	{684,2}
};

static struct patval owl_defendpat269[] = {
  {647,2},	{721,2}
};

static struct patval owl_defendpat270[] = {
  {647,2},	{721,2}
};

static struct patval owl_defendpat271[] = {
  {647,2},	{721,2}
};

static struct patval owl_defendpat272[] = {
  {685,2}
};

static struct patval owl_defendpat273[] = {
  {685,2}
};

static struct patval owl_defendpat274[] = {
  {648,2}
};

static struct patval owl_defendpat275[] = {
  {648,2}
};

static struct patval owl_defendpat276[] = {
  {648,2}
};

static struct patval owl_defendpat277[] = {
  {720,2},	{647,2},	{683,2}
};

static struct patval owl_defendpat278[] = {
  {684,2},	{687,2},	{648,4},	{649,4}
};

static struct patval owl_defendpat279[] = {
  {685,2},	{648,2},	{758,4},	{720,4},
  {759,4}
};

static struct patval owl_defendpat280[] = {
  {647,2},	{759,2}
};

static struct patval owl_defendpat281[] = {
  {722,2},	{684,2}
};

static struct patval owl_defendpat282[] = {
  {685,2},	{758,2},	{722,2}
};

static struct patval owl_defendpat283[] = {
  {758,2},	{647,2},	{685,2},	{722,2}
};

static struct patval owl_defendpat284[] = {
  {648,2}
};

static struct patval owl_defendpat285[] = {
  {721,2},	{683,2},	{720,2}
};

static struct patval owl_defendpat286[] = {
  {720,2},	{645,2},	{683,2},	{758,2},
  {757,4}
};

static struct patval owl_defendpat287[] = {
  {647,2},	{683,2},	{758,2},	{720,2},
  {757,4}
};

static struct patval owl_defendpat288[] = {
  {685,2},	{610,2},	{648,2},	{721,2},
  {646,2},	{611,4}
};

static struct patval owl_defendpat289[] = {
  {685,2},	{648,2},	{721,2},	{646,2},
  {645,2},	{610,2},	{611,4}
};

static struct patval owl_defendpat290[] = {
  {685,2},	{686,2},	{648,2},	{609,4}
};

static struct patval owl_defendpat291[] = {
  {683,2},	{647,2},	{646,4}
};

static struct patval owl_defendpat292[] = {
  {646,2},	{683,2}
};

static struct patval owl_defendpat293[] = {
  {758,2},	{720,2},	{757,2}
};

static struct patval owl_defendpat294[] = {
  {647,2},	{685,2},	{721,2},	{645,4},
  {719,4},	{682,4}
};

static struct patval owl_defendpat295[] = {
  {649,2},	{612,4},	{720,4}
};

static struct patval owl_defendpat296[] = {
  {722,2},	{760,4},	{723,4},	{646,4}
};

static struct patval owl_defendpat297[] = {
  {684,2},	{721,2},	{646,4},	{760,4},
  {683,4}
};

static struct patval owl_defendpat298[] = {
  {686,2},	{797,4},	{720,4},	{757,4},
  {794,4},	{796,4},	{723,4},	{683,4},
  {795,4}
};

static struct patval owl_defendpat299[] = {
  {684,2},	{647,2},	{724,4},	{761,4},
  {759,4},	{758,4},	{687,4},	{650,4},
  {760,4}
};

static struct patval owl_defendpat300[] = {
  {647,2},	{650,4},	{760,4},	{761,4},
  {687,4},	{759,4},	{758,4},	{724,4}
};

static struct patval owl_defendpat301[] = {
  {684,2}
};

static struct patval owl_defendpat302[] = {
  {720,2},	{684,2},	{683,2},	{649,4},
  {646,4}
};

static struct patval owl_defendpat303[] = {
  {647,2},	{721,2}
};

static struct patval owl_defendpat304[] = {
  {722,2},	{721,2},	{611,4},	{610,4},
  {646,4},	{612,4}
};

static struct patval owl_defendpat305[] = {
  {721,2}
};

static struct patval owl_defendpat306[] = {
  {647,2},	{686,2},	{683,2},	{646,4}
};

static struct patval owl_defendpat307[] = {
  {683,2},	{646,2},	{721,2},	{609,4}
};

static struct patval owl_defendpat308[] = {
  {684,2},	{648,2},	{723,2},	{686,2},
  {760,4}
};

static struct patval owl_defendpat309[] = {
  {684,2},	{646,2},	{722,2}
};

static struct patval owl_defendpat310[] = {
  {647,2},	{722,2}
};

static struct patval owl_defendpat311[] = {
  {686,2},	{720,2},	{721,2}
};

static struct patval owl_defendpat312[] = {
  {648,2},	{686,2},	{649,4},	{758,4}
};

static struct patval owl_defendpat313[] = {
  {648,2},	{723,2},	{647,2}
};

static struct patval owl_defendpat314[] = {
  {684,2}
};

static struct patval owl_defendpat315[] = {
  {760,2},	{759,2},	{758,2}
};

static struct patval owl_defendpat316[] = {
  {721,2},	{611,4},	{612,4},	{650,4},
  {687,4}
};

static struct patval owl_defendpat317[] = {
  {685,2}
};

static struct patval owl_defendpat318[] = {
  {685,2},	{721,2}
};

static struct patval owl_defendpat319[] = {
  {721,2}
};

static struct patval owl_defendpat320[] = {
  {722,2},	{721,2}
};

static struct patval owl_defendpat321[] = {
  {684,2},	{722,2}
};

static struct patval owl_defendpat322[] = {
  {757,2},	{758,2},	{684,2},	{722,2},
  {759,4}
};

static struct patval owl_defendpat323[] = {
  {647,2},	{721,2}
};

static struct patval owl_defendpat324[] = {
  {647,2},	{721,2}
};

static struct patval owl_defendpat325[] = {
  {648,2},	{685,2}
};

static struct patval owl_defendpat326[] = {
  {684,2},	{722,2},	{723,4},	{686,4},
  {721,4},	{649,4}
};

static struct patval owl_defendpat327[] = {
  {684,2},	{722,2},	{686,4},	{723,4},
  {721,4}
};

static struct patval owl_defendpat328[] = {
  {684,2},	{685,2},	{682,4},	{719,4}
};

static struct patval owl_defendpat329[] = {
  {684,2},	{721,2}
};

static struct patval owl_defendpat330[] = {
  {721,2},	{684,2},	{647,4}
};

static struct patval owl_defendpat331[] = {
  {684,2},	{686,2}
};

static struct patval owl_defendpat332[] = {
  {685,2},	{683,2},	{721,2},	{722,4},
  {720,4}
};

static struct patval owl_defendpat333[] = {
  {723,2},	{684,2}
};

static struct patval owl_defendpat334[] = {
  {723,2},	{684,2}
};

static struct patval owl_defendpat335[] = {
  {759,2},	{648,2}
};

static struct patval owl_defendpat336[] = {
  {759,2},	{648,2},	{723,4},	{721,4}
};

static struct patval owl_defendpat337[] = {
  {647,2},	{722,2}
};

static struct patval owl_defendpat338[] = {
  {722,2},	{757,4},	{683,4},	{797,4},
  {720,4},	{795,4},	{794,4},	{796,4}
};

static struct patval owl_defendpat339[] = {
  {722,2},	{793,4},	{830,4},	{719,4},
  {756,4},	{832,4},	{834,4},	{831,4},
  {682,4},	{833,4}
};

static struct patval owl_defendpat340[] = {
  {684,2},	{722,2},	{612,4},	{609,4},
  {610,4},	{611,4}
};

static struct patval owl_defendpat341[] = {
  {686,2},	{648,2},	{609,4},	{646,4}
};

static struct patval owl_defendpat342[] = {
  {684,2},	{648,2},	{756,4},	{719,4},
  {757,4}
};

static struct patval owl_defendpat343[] = {
  {684,2},	{720,4},	{757,4},	{794,4},
  {683,4},	{795,4}
};

static struct patval owl_defendpat344[] = {
  {684,2},	{683,4},	{720,4},	{832,4},
  {831,4}
};

static struct patval owl_defendpat345[] = {
  {832,2},	{684,2},	{719,4},	{683,4},
  {756,4},	{793,4},	{831,4}
};

static struct patval owl_defendpat346[] = {
  {722,2},	{719,4},	{757,4},	{794,4},
  {720,4},	{793,4},	{758,4},	{795,4},
  {756,4}
};

static struct patval owl_defendpat347[] = {
  {684,2},	{794,4},	{757,4},	{796,4},
  {759,4},	{760,4},	{797,4},	{795,4},
  {723,4}
};

static struct patval owl_defendpat348[] = {
  {721,2},	{725,4},	{762,4},	{688,4},
  {611,4},	{651,4},	{614,4},	{613,4},
  {612,4}
};

static struct patval owl_defendpat349[] = {
  {721,2},	{684,2}
};

static struct patval owl_defendpat350[] = {
  {686,2},	{684,2},	{647,4},	{649,4}
};

static struct patval owl_defendpat351[] = {
  {684,2},	{686,2},	{649,4},	{647,4},
  {797,4},	{796,4}
};

static struct patval owl_defendpat352[] = {
  {684,2},	{722,2}
};

static struct patval owl_defendpat353[] = {
  {684,2},	{722,2}
};

static struct patval owl_defendpat354[] = {
  {684,2},	{650,4},	{724,4},	{687,4}
};

static struct patval owl_defendpat355[] = {
  {684,2}
};

static struct patval owl_defendpat356[] = {
  {684,2},	{683,4},	{645,4},	{682,4},
  {719,4},	{721,4},	{646,4},	{647,4},
  {720,4}
};

static struct patval owl_defendpat357[] = {
  {684,2},	{686,2}
};

static struct patval owl_defendpat358[] = {
  {684,2},	{686,2}
};

static struct patval owl_defendpat359[] = {
  {684,2},	{686,2}
};

static struct patval owl_defendpat360[] = {
  {684,2},	{686,2},	{723,2}
};

static struct patval owl_defendpat361[] = {
  {684,2},	{686,2},	{723,2}
};

static struct patval owl_defendpat362[] = {
  {685,2},	{722,2},	{683,2}
};

static struct patval owl_defendpat363[] = {
  {684,2},	{686,2}
};

static struct patval owl_defendpat364[] = {
  {684,2},	{722,2}
};

static struct patval owl_defendpat365[] = {
  {684,2},	{686,2},	{723,2}
};

static struct patval owl_defendpat366[] = {
  {685,2},	{722,2},	{683,2}
};

static struct patval owl_defendpat367[] = {
  {684,2},	{686,2}
};

static struct patval owl_defendpat368[] = {
  {684,2},	{686,2},	{723,2}
};

static struct patval owl_defendpat369[] = {
  {685,2},	{722,2},	{683,2}
};

static struct patval owl_defendpat370[] = {
  {684,2},	{721,4},	{647,4}
};

static struct patval owl_defendpat371[] = {
  {684,2},	{687,4},	{650,4},	{613,4},
  {724,4}
};

static struct patval owl_defendpat372[] = {
  {684,2},	{647,2},	{758,4},	{757,4},
  {759,4},	{760,4}
};

static struct patval owl_defendpat373[] = {
  {683,2},	{722,2},	{684,2},	{723,4},
  {760,4},	{649,4},	{686,4}
};

static struct patval owl_defendpat374[] = {
  {684,2},	{648,2},	{683,2},	{649,4},
  {723,4},	{686,4}
};

static struct patval owl_defendpat375[] = {
  {683,2},	{686,2},	{684,2},	{648,2}
};

static struct patval owl_defendpat376[] = {
  {721,2},	{685,2},	{647,2},	{720,4},
  {646,4}
};

static struct patval owl_defendpat377[] = {
  {649,2},	{685,2},	{721,2},	{609,4},
  {646,4},	{610,4}
};

static struct patval owl_defendpat378[] = {
  {685,2},	{683,2},	{721,2},	{646,4},
  {722,4}
};

static struct patval owl_defendpat379[] = {
  {684,2},	{721,2},	{724,4},	{687,4},
  {650,4},	{761,4}
};

static struct patval owl_defendpat380[] = {
  {647,2},	{648,2},	{721,2},	{759,4},
  {757,4},	{758,4},	{760,4}
};

static struct patval owl_defendpat381[] = {
  {648,2},	{722,2},	{647,4},	{649,4}
};

static struct patval owl_defendpat382[] = {
  {758,2},	{647,2},	{646,4}
};

static struct patval owl_defendpat383[] = {
  {684,2},	{687,4},	{650,4},	{724,4}
};

static struct patval owl_defendpat384[] = {
  {646,2},	{647,2},	{648,4}
};

static struct patval owl_defendpat385[] = {
  {758,2},	{649,4},	{724,4},	{648,4},
  {687,4},	{650,4}
};

static struct patval owl_defendpat386[] = {
  {758,2},	{687,4},	{721,4},	{724,4},
  {649,4},	{648,4},	{650,4},	{759,4}
};

static struct patval owl_defendpat387[] = {
  {758,2},	{649,4},	{687,4},	{759,4},
  {648,4},	{650,4},	{724,4},	{721,4}
};

static struct patval owl_defendpat388[] = {
  {758,2},	{649,4},	{687,4},	{724,4},
  {648,4},	{650,4}
};

static struct patval owl_defendpat389[] = {
  {684,2},	{683,4},	{650,4},	{720,4},
  {687,4}
};

static struct patval owl_defendpat390[] = {
  {721,2},	{647,2}
};

static struct patval owl_defendpat391[] = {
  {684,2},	{687,4},	{650,4},	{613,4},
  {724,4}
};

static struct patval owl_defendpat392[] = {
  {646,2},	{684,2}
};

static struct patval owl_defendpat393[] = {
  {684,2},	{723,2}
};

static struct patval owl_defendpat394[] = {
  {684,2},	{723,2}
};

static struct patval owl_defendpat395[] = {
  {684,2},	{723,2}
};

static struct patval owl_defendpat396[] = {
  {684,2},	{760,2}
};

static struct patval owl_defendpat397[] = {
  {685,2},	{683,2}
};

static struct patval owl_defendpat398[] = {
  {684,2},	{723,4}
};

static struct patval owl_defendpat399[] = {
  {722,2},	{684,2},	{682,2}
};

static struct patval owl_defendpat400[] = {
  {683,2}
};

static struct patval owl_defendpat401[] = {
  {684,2},	{683,2},	{685,2}
};

static struct patval owl_defendpat402[] = {
  {647,2},	{758,2},	{685,2}
};

static struct patval owl_defendpat403[] = {
  {684,2},	{721,4},	{647,4}
};

static struct patval owl_defendpat404[] = {
  {684,2},	{721,4},	{647,4}
};

static struct patval owl_defendpat405[] = {
  {684,2},	{685,4}
};

static struct patval owl_defendpat406[] = {
  {647,2},	{611,2},	{721,2},	{612,2},
  {613,4},	{761,4},	{758,4}
};

static struct patval owl_defendpat407[] = {
  {684,2},	{796,2},	{685,2}
};

static struct patval owl_defendpat408[] = {
  {685,2},	{723,2},	{686,4}
};

static struct patval owl_defendpat409[] = {
  {684,2},	{686,2}
};

static struct patval owl_defendpat410[] = {
  {684,2},	{649,4}
};

static struct patval owl_defendpat411[] = {
  {684,2}
};

static struct patval owl_defendpat412[] = {
  {684,2},	{685,4}
};

static struct patval owl_defendpat413[] = {
  {685,2},	{686,2},	{610,2},	{609,4}
};

static struct patval owl_defendpat414[] = {
  {683,2},	{758,2},	{721,2}
};

static struct patval owl_defendpat415[] = {
  {684,2},	{647,2},	{722,2},	{720,2}
};

static struct patval owl_defendpat416[] = {
  {720,2},	{758,2},	{722,2},	{759,2},
  {610,4},	{646,4}
};

static struct patval owl_defendpat417[] = {
  {684,2},	{685,2}
};

static struct patval owl_defendpat418[] = {
  {685,2},	{649,2},	{686,4}
};

static struct patval owl_defendpat419[] = {
  {759,2},	{648,4},	{649,4}
};

static struct patval owl_defendpat420[] = {
  {684,2},	{687,2},	{647,4},	{721,4}
};

static struct patval owl_defendpat421[] = {
  {647,2},	{722,2}
};

static struct patval owl_defendpat422[] = {
  {683,2},	{686,4}
};

static struct patval owl_defendpat423[] = {
  {685,2},	{721,4},	{573,4},	{536,4}
};

static struct patval owl_defendpat424[] = {
  {685,2},	{647,2},	{757,2}
};

static struct patval owl_defendpat425[] = {
  {648,2},	{758,2},	{721,4}
};

static struct patval owl_defendpat426[] = {
  {721,2},	{685,2},	{574,4},	{573,4}
};

static struct patval owl_defendpat427[] = {
  {684,2}
};

static struct patval owl_defendpat428[] = {
  {684,2}
};

static struct patval owl_defendpat429[] = {
  {684,2}
};

static struct patval owl_defendpat430[] = {
  {647,2},	{722,2}
};

static struct patval owl_defendpat431[] = {
  {647,2},	{722,2}
};

static struct patval owl_defendpat432[] = {
  {684,2},	{721,4}
};

static struct patval owl_defendpat433[] = {
  {684,2},	{760,2}
};

static struct patval owl_defendpat434[] = {
  {611,2},	{722,2}
};

static struct patval owl_defendpat435[] = {
  {647,2},	{759,2},	{648,4}
};

static struct patval owl_defendpat436[] = {
  {647,2},	{759,2},	{648,4}
};

static struct patval owl_defendpat437[] = {
  {685,2},	{719,4},	{646,4},	{722,4}
};

static struct patval owl_defendpat438[] = {
  {685,2},	{647,2},	{719,4},	{646,4},
  {722,4}
};

static struct patval owl_defendpat439[] = {
  {647,2},	{758,2}
};

static struct patval owl_defendpat440[] = {
  {647,2},	{793,2},	{646,4}
};

static struct patval owl_defendpat441[] = {
  {684,2},	{686,2},	{720,2}
};

static struct patval owl_defendpat442[] = {
  {722,2},	{758,2},	{684,2}
};

static struct patval owl_defendpat443[] = {
  {722,2},	{758,2},	{684,2}
};

static struct patval owl_defendpat444[] = {
  {722,2},	{758,2},	{684,2}
};

static struct patval owl_defendpat445[] = {
  {648,2},	{684,2}
};

static struct patval owl_defendpat446[] = {
  {648,2},	{684,2}
};

static struct patval owl_defendpat447[] = {
  {646,2},	{683,2},	{721,2}
};

static struct patval owl_defendpat448[] = {
  {646,2},	{721,2},	{683,2},	{720,4}
};

static struct patval owl_defendpat449[] = {
  {646,2},	{685,2},	{683,2},	{720,4}
};

static struct patval owl_defendpat450[] = {
  {646,2},	{721,2},	{683,2},	{720,4}
};

static struct patval owl_defendpat451[] = {
  {682,2},	{646,2},	{684,2}
};

static struct patval owl_defendpat452[] = {
  {611,2},	{647,2},	{721,2},	{685,2}
};

static struct patval owl_defendpat453[] = {
  {721,2},	{685,2},	{647,2}
};

static struct patval owl_defendpat454[] = {
  {646,2},	{611,2},	{610,2},	{683,2},
  {684,2},	{720,4}
};

static struct patval owl_defendpat455[] = {
  {647,2},	{685,2}
};

static struct patval owl_defendpat456[] = {
  {647,2},	{685,2},	{648,4}
};

static struct patval owl_defendpat457[] = {
  {648,2},	{684,2},	{683,2},	{722,2}
};

static struct patval owl_defendpat458[] = {
  {684,2},	{647,2},	{720,2}
};

static struct patval owl_defendpat459[] = {
  {721,2},	{685,2},	{684,2},	{720,2},
  {719,4},	{756,4},	{612,4},	{611,4}
};

static struct patval owl_defendpat460[] = {
  {722,2}
};

static struct patval owl_defendpat461[] = {
  {686,2}
};

static struct patval owl_defendpat462[] = {
  {722,2}
};

static struct patval owl_defendpat463[] = {
  {686,2}
};

static struct patval owl_defendpat464[] = {
  {758,2},	{684,2},	{720,2},	{722,2},
  {759,4}
};

static struct patval owl_defendpat465[] = {
  {758,2},	{720,2},	{684,2},	{722,2},
  {759,4}
};

static struct patval owl_defendpat466[] = {
  {647,2}
};

static struct patval owl_defendpat467[] = {
  {721,2},	{723,2},	{685,2},	{647,2},
  {758,2},	{649,2}
};

static struct patval owl_defendpat468[] = {
  {683,2},	{649,2},	{684,2},	{720,2},
  {685,2},	{648,2}
};

static struct patval owl_defendpat469[] = {
  {684,2},	{720,2},	{683,4},	{647,4},
  {722,4}
};

static struct patval owl_defendpat470[] = {
  {721,2}
};

static struct patval owl_defendpat471[] = {
  {721,2}
};

static struct patval owl_defendpat472[] = {
  {646,2},	{647,2}
};

static struct patval owl_defendpat473[] = {
  {684,2},	{723,2},	{760,2},	{686,2}
};

static struct patval owl_defendpat474[] = {
  {684,2},	{723,2},	{686,2},	{649,2},
  {760,4}
};

static struct patval owl_defendpat475[] = {
  {684,2},	{722,2}
};

static struct patval owl_defendpat476[] = {
  {721,2},	{684,2}
};

static struct patval owl_defendpat477[] = {
  {722,2},	{684,2},	{720,2},	{758,2},
  {757,4}
};

static struct patval owl_defendpat478[] = {
  {684,2},	{683,2}
};

static struct pattern owl_defendpat[480];

static int
autohelperowl_defendpat0(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);

  return  play_attack_defend_n(color, 1, 4, move, a, b, c, c);
}

static int
autohelperowl_defendpat8(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);

  return ATTACK_MACRO(a) && !play_attack_defend_n(color, 1, 1, move, a);
}

static int
autohelperowl_defendpat9(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(573, trans, move);

  return ATTACK_MACRO(a) && !play_attack_defend_n(color, 1, 1, move, a);
}

static int
autohelperowl_defendpat20(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return  !play_attack_defend_n(color, 0, 3, move, a, b, a);
}

static int
autohelperowl_defendpat21(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);

  return countlib(a) >= 4;
}

static int
autohelperowl_defendpat22(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(796, trans, move);

  return countlib(a) >= 4;
}

static int
autohelperowl_defendpat23(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);

  return countlib(a)>1;
}

static int
autohelperowl_defendpat27(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_defendpat29(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(648, trans, move);

  return play_attack_defend_n(color, 1, 3, move, a, b, c) && !ATTACK_MACRO(c);
}

static int
autohelperowl_defendpat30(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(609, trans, move);
  b = AFFINE_TRANSFORM(610, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat37(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(682, trans, move);

  return !somewhere(OTHER_COLOR(color), 0, 1, A) || !DEFEND_MACRO(A);
}

static int
autohelperowl_defendpat43(int trans, int move, int color, int action)
{
  int B;
  UNUSED(color);
  UNUSED(action);

  B = AFFINE_TRANSFORM(646, trans, move);

  return  play_attack_defend_n(color, 1, 1, move, B);
}

static int
autohelperowl_defendpat48(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(682, trans, move);

  return play_attack_defend2_n(color, 1, 4, move, a, b, c, a, c);
}

static int
autohelperowl_defendpat52(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(611, trans, move);

  return  play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat53(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(648, trans, move);

  return  !play_attack_defend_n(color, 0, 1, move, A);
}

static int
autohelperowl_defendpat57(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(572, trans, move);
  b = AFFINE_TRANSFORM(609, trans, move);
  c = AFFINE_TRANSFORM(573, trans, move);

  return  somewhere(color, 0, 3, a, b, c);
}

static int
autohelperowl_defendpat61(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  b = AFFINE_TRANSFORM(757, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);

  return play_attack_defend_n(OTHER_COLOR(color), 1, 2, a, b, c) && !play_attack_defend_n(color, 1, 3, move, a, b, c);
}

static int
autohelperowl_defendpat64(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(611, trans, move);

  return owl_goal_dragon(a) && owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat65(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(757, trans, move);

  return owl_goal_dragon(a) && !play_attack_defend_n(color, 1, 1, move, a);
}

static int
autohelperowl_defendpat66(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(573, trans, move);

  return owl_goal_dragon(a) && !play_attack_defend_n(color, 1, 1, move, a);
}

static int
autohelperowl_defendpat67(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);

  return owl_eyespace(a);
}

static int
autohelperowl_defendpat68(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(794, trans, move);

  return play_connect_n(color, 1, 2, move, a, move, b);
}

static int
autohelperowl_defendpat69(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(610, trans, move);
  d = AFFINE_TRANSFORM(572, trans, move);
  e = AFFINE_TRANSFORM(573, trans, move);

  return  safe_move(move, color) || ((owl_escape_value(c) > 0 || owl_escape_value(d) >0 || owl_escape_value(e)>0)  && play_attack_defend_n(color, 1, 3, move, a, b, a));
}

static int
autohelperowl_defendpat70(int trans, int move, int color, int action)
{
  int a, b, c, d, e, F;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(610, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(537, trans, move);
  d = AFFINE_TRANSFORM(574, trans, move);
  e = AFFINE_TRANSFORM(648, trans, move);
  F = AFFINE_TRANSFORM(685, trans, move);

  return countlib(F)>=3 && owl_topological_eye(a, board[b])<=2 && !play_attack_defend_n(OTHER_COLOR(color), 1, 3, c, d, e, c);
}

static int
autohelperowl_defendpat72(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(686, trans, move);
  C = AFFINE_TRANSFORM(683, trans, move);

  return play_connect_n(color, 0, 2, move, a, a, C) && play_connect_n(color, 0, 2, move, b, b, C);
}

static int
autohelperowl_defendpat73(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(686, trans, move);

  return owl_escape_value(a) > 1;
}

static int
autohelperowl_defendpat74(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);

  return owl_escape_value(a) > 1;
}

static int
autohelperowl_defendpat77(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return  does_attack(move, a);
}

static int
autohelperowl_defendpat79(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(686, trans, move);
  d = AFFINE_TRANSFORM(647, trans, move);

  return play_attack_defend2_n(color, 1, 4, move, a, b, c, a, c) && play_attack_defend2_n(color, 1, 4, move, b, a, d, b, d);
}

static int
autohelperowl_defendpat80(int trans, int move, int color, int action)
{
  int b, c, D;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(610, trans, move);
  D = AFFINE_TRANSFORM(611, trans, move);

  return  play_attack_defend_n(color, 1, 4, move, NO_MOVE, c, b, D);
}

static int
autohelperowl_defendpat81(int trans, int move, int color, int action)
{
  int b, c;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(647, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, b, b) && play_attack_defend_n(color, 1, 2, move, c, c) && safe_move(move, OTHER_COLOR(color));
}

static int
autohelperowl_defendpat82(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(color, 1, 1, move, b) && play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_defendpat83(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, a, a) && !obvious_false_eye(a, color);
}

static int
autohelperowl_defendpat84(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return play_attack_defend_n(color, 1, 2, move, a, a) && play_attack_defend_n(color, 1, 2, move, b, b);
}

static int
autohelperowl_defendpat85(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);

  return  countlib(a)>1 && safe_move(b, OTHER_COLOR(color)) && play_attack_defend_n(color, 1, 2, move, b, b);
}

static int
autohelperowl_defendpat86(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(722, trans, move);

  return  countlib(a)>2 && countlib(c)>2 && safe_move(b, OTHER_COLOR(color)) && play_attack_defend_n(color, 1, 2, move, b, b);
}

static int
autohelperowl_defendpat87(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_defendpat90(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_defendpat91(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_defendpat92(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(646, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);

  return does_attack(move, A) && does_defend(move, b);
}

static int
autohelperowl_defendpat93(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(646, trans, move);

  return  does_attack(move, A);
}

static int
autohelperowl_defendpat94(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(610, trans, move);

  return  countlib(A)>1;
}

static int
autohelperowl_defendpat96(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(646, trans, move);

  return !ATTACK_MACRO(A);
}

static int
autohelperowl_defendpat97(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)==1;
}

static int
autohelperowl_defendpat101(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(645, trans, move);
  d = AFFINE_TRANSFORM(647, trans, move);

  return  somewhere(color, 0, 2, b, c)||!play_attack_defend_n(color, 0, 5, move, a, b, c, d, c);
}

static int
autohelperowl_defendpat108(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(719, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, a, a) && !play_attack_defend2_n(OTHER_COLOR(color), 1, 1, a, a, c) && play_attack_defend_n(color, 1, 3, move, b, a, b);
}

static int
autohelperowl_defendpat109(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(686, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(648, trans, move);

  return  countlib(a)>1 && safe_move(b, OTHER_COLOR(color)) && !obvious_false_eye(b, color) && play_attack_defend_n(color, 1, 2, move, b, b) && does_attack(b, c);
}

static int
autohelperowl_defendpat110(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(682, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);
  d = AFFINE_TRANSFORM(646, trans, move);

  return  countlib(a)>1 && safe_move(b, OTHER_COLOR(color)) && play_attack_defend_n(color, 1, 3, move, d, b, d) && play_attack_defend_n(OTHER_COLOR(color), 0, 1, b, c) != WIN;
}

static int
autohelperowl_defendpat111(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(682, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);
  d = AFFINE_TRANSFORM(646, trans, move);

  return  countlib(a)>1 && safe_move(b, OTHER_COLOR(color)) && play_attack_defend_n(color, 1, 2, move, b, b) && does_attack(b, c) && play_attack_defend_n(color, 1, 2, move, d, d);
}

static int
autohelperowl_defendpat112(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);

  return does_defend(move, a);
}

static int
autohelperowl_defendpat113(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(759, trans, move);

  return does_defend(move, a);
}

static int
autohelperowl_defendpat114(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);

  return does_defend(move, a);
}

static int
autohelperowl_defendpat115(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);

  return does_defend(move, a);
}

static int
autohelperowl_defendpat116(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(756, trans, move);

  return  !play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat119(int trans, int move, int color, int action)
{
  int c, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(759, trans, move);
  A = AFFINE_TRANSFORM(720, trans, move);
  B = AFFINE_TRANSFORM(758, trans, move);

  return countlib(A)>1 && countlib(B)>1 && countlib(c)==2;
}

static int
autohelperowl_defendpat120(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);

  return !play_attack_defend_n(color, 0, 3, move, a, b, a);
}

static int
autohelperowl_defendpat123(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);

  return play_attack_defend_n(color, 1, 2, move, a, a) && play_attack_defend_n(color, 1, 2, move, b, b);
}

static int
autohelperowl_defendpat124(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(759, trans, move);

  return play_attack_defend_n(color, 1, 2, move, a, a) && play_attack_defend_n(color, 1, 2, move, b, b) && play_attack_defend_n(color, 1, 2, move, c, c);
}

static int
autohelperowl_defendpat125(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(647, trans, move);
  A = AFFINE_TRANSFORM(720, trans, move);

  return (!obvious_false_eye(b, color) || play_attack_defend_n(color, 1, 1, move, A))&& !play_attack_defend_n(OTHER_COLOR(color), 1, 1, move, A);
}

static int
autohelperowl_defendpat126(int trans, int move, int color, int action)
{
  int b, A, C;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(647, trans, move);
  A = AFFINE_TRANSFORM(610, trans, move);
  C = AFFINE_TRANSFORM(573, trans, move);

  return  !play_attack_defend_n(color, 0, 3, move, A, b, C);
}

static int
autohelperowl_defendpat128(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(685, trans, move);

  return countlib(a) == 1 && !obvious_false_eye(b, color) && !obvious_false_eye(c, color);
}

static int
autohelperowl_defendpat129(int trans, int move, int color, int action)
{
  int A, B, C;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);
  C = AFFINE_TRANSFORM(647, trans, move);

  return countlib(A)==1 && countlib(B)==1 && countlib(C)==2;
}

static int
autohelperowl_defendpat130(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return does_attack(move, A);
}

static int
autohelperowl_defendpat131(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(682, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return owl_eyespace(a) && does_attack(move, B);
}

static int
autohelperowl_defendpat133(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(832, trans, move);

  return accuratelib(a, color, MAX_LIBERTIES, NULL)==1;
}

static int
autohelperowl_defendpat134(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);

  return countlib(A) == 2;
}

static int
autohelperowl_defendpat137(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(685, trans, move);

  return play_attack_defend_n(color, 0, 1, move, A) != WIN;
}

static int
autohelperowl_defendpat139(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(683, trans, move);
  A = AFFINE_TRANSFORM(649, trans, move);

  return countlib(A)==2 && play_attack_defend_n(OTHER_COLOR(color), 1, 2, move, b, b);
}

static int
autohelperowl_defendpat140(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return accuratelib(move, OTHER_COLOR(color), MAX_LIBERTIES, NULL)>1;
}

static int
autohelperowl_defendpat141(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return accuratelib(move, OTHER_COLOR(color), MAX_LIBERTIES, NULL)>1;
}

static int
autohelperowl_defendpat142(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)<=2;
}

static int
autohelperowl_defendpat143(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(795, trans, move);

  return countlib(A)<=2;
}

static int
autohelperowl_defendpat145(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(795, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return countlib(a)==2 && countlib(B)==3;
}

static int
autohelperowl_defendpat147(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(686, trans, move);
  A = AFFINE_TRANSFORM(758, trans, move);

  return !ATTACK_MACRO(A) && play_attack_defend_n(color, 1, 2, move, b, b);
}

static int
autohelperowl_defendpat148(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(611, trans, move);
  b = AFFINE_TRANSFORM(609, trans, move);

  return  !somewhere(OTHER_COLOR(color), 0, 1, a) || !somewhere(OTHER_COLOR(color), 0, 1, b);
}

static int
autohelperowl_defendpat150(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);

  return countlib(a)==1 && !obvious_false_eye(b, color);
}

static int
autohelperowl_defendpat152(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(646, trans, move);

  return  play_attack_defend_n(color, 0, 1, move, A)  && play_attack_defend_n(color, 1, 2, move, B, A);
}

static int
autohelperowl_defendpat153(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(685, trans, move);

  return  !play_attack_defend_n(OTHER_COLOR(color), 1, 1, move, move) && play_attack_defend_n(color, 1, 2, move, A, A);
}

static int
autohelperowl_defendpat155(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return  DEFEND_MACRO(A) && play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat156(int trans, int move, int color, int action)
{
  int A, B, C;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(686, trans, move);
  C = AFFINE_TRANSFORM(648, trans, move);

  return  play_attack_defend_n(color, 1, 1, move, C) && play_attack_defend_n(color, 0, 2, move, A, move) && play_attack_defend_n(color, 0, 2, move, B, move);
}

static int
autohelperowl_defendpat157(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return  play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat159(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(646, trans, move);
  B = AFFINE_TRANSFORM(720, trans, move);

  return  countlib(A) < 4 && play_attack_defend_n(color, 1, 1, move, B);
}

static int
autohelperowl_defendpat160(int trans, int move, int color, int action)
{
  int a, c, e, B, D, F;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(648, trans, move);
  e = AFFINE_TRANSFORM(685, trans, move);
  B = AFFINE_TRANSFORM(646, trans, move);
  D = AFFINE_TRANSFORM(611, trans, move);
  F = AFFINE_TRANSFORM(647, trans, move);

  return  !play_attack_defend_n(color, 0, 7, move, a, B, c, D, e, F, a);
}

static int
autohelperowl_defendpat161(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return  play_attack_defend_n(color, 1, 3, move, a, B, a);
}

static int
autohelperowl_defendpat162(int trans, int move, int color, int action)
{
  int b, d, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(720, trans, move);
  d = AFFINE_TRANSFORM(647, trans, move);
  A = AFFINE_TRANSFORM(721, trans, move);

  return  is_ko_point(b) && owl_topological_eye(move, board[A]) > 2 && !obvious_false_eye(d, color);
}

static int
autohelperowl_defendpat164(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(611, trans, move);

  return !play_attack_defend_n(color, 0, 1, move, A);
}

static int
autohelperowl_defendpat165(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return !obvious_false_eye(a, color) && !play_attack_defend_n(color, 1, 2, b, move, move);
}

static int
autohelperowl_defendpat166(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);

  return !obvious_false_eye(a, color) || !obvious_false_eye(b, color);
}

static int
autohelperowl_defendpat167(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  C = AFFINE_TRANSFORM(721, trans, move);

  return !obvious_false_eye(a, color)&& play_attack_defend_n(color, 1, 2, move, b, C) && !ATTACK_MACRO(C);
}

static int
autohelperowl_defendpat172(int trans, int move, int color, int action)
{
  int a, b, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(759, trans, move);
  B = AFFINE_TRANSFORM(722, trans, move);

  return  (owl_topological_eye(a, board[B])>=2) && (owl_topological_eye(b, board[B])==2);
}

static int
autohelperowl_defendpat173(int trans, int move, int color, int action)
{
  int a, b, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return  (owl_topological_eye(a, board[B])==2) && ((owl_topological_eye(b, board[B])==2) || (owl_topological_eye(b, board[B])==3));
}

static int
autohelperowl_defendpat174(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return owl_topological_eye(a, board[B])==3 && does_attack(move, B);
}

static int
autohelperowl_defendpat175(int trans, int move, int color, int action)
{
  int a, b, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(682, trans, move);

  return  owl_topological_eye(a, board[B])==3 && safe_move(b, OTHER_COLOR(color)) && safe_move(move, OTHER_COLOR(color)) && play_attack_defend_n(color, 1, 2, move, b, b);
}

static int
autohelperowl_defendpat176(int trans, int move, int color, int action)
{
  int b, c;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(757, trans, move);

  return  (safe_move(b, OTHER_COLOR(color)) || safe_move(move, OTHER_COLOR(color))) && play_attack_defend_n(color, 1, 2, move, b, b) && (somewhere(color, 0, 1, c) || !safe_move(c, OTHER_COLOR(color)));
}

static int
autohelperowl_defendpat177(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return  does_attack(move, a);
}

static int
autohelperowl_defendpat178(int trans, int move, int color, int action)
{
  int a, b, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);
  B = AFFINE_TRANSFORM(647, trans, move);

  return  countlib(a)==2 && owl_topological_eye(b, board[B])==3;
}

static int
autohelperowl_defendpat179(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(646, trans, move);

  return  play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat180(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);

  return  play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat181(int trans, int move, int color, int action)
{
  int a, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);

  return accuratelib(a, color, MAX_LIBERTIES, NULL)<=2 && does_attack(move, A);
}

static int
autohelperowl_defendpat182(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return !owl_big_eyespace(a) && !obvious_false_eye(a, color);
}

static int
autohelperowl_defendpat183(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return countlib(A)==1 && countstones(A)>=3;
}

static int
autohelperowl_defendpat184(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)==1 && countstones(A)>=3;
}

static int
autohelperowl_defendpat185(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  B = AFFINE_TRANSFORM(795, trans, move);

  return owl_topological_eye(a, board[B])==3;
}

static int
autohelperowl_defendpat187(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return  countlib(a)==2 && accuratelib(move, OTHER_COLOR(color), MAX_LIBERTIES, NULL)>1 && owl_big_eyespace(move);
}

static int
autohelperowl_defendpat188(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);

  return accuratelib(a, OTHER_COLOR(color), MAX_LIBERTIES, NULL)>1 && owl_big_eyespace(a) && play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_defendpat189(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(719, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return countlib(a)==2 && countlib(B)==3 && owl_big_eyespace(move);
}

static int
autohelperowl_defendpat190(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);

  return owl_eyespace(a) && !owl_big_eyespace(a);
}

static int
autohelperowl_defendpat191(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(720, trans, move);

  return !play_attack_defend_n(color, 0, 1, move, A);
}

static int
autohelperowl_defendpat193(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return owl_proper_eye(a);
}

static int
autohelperowl_defendpat195(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(648, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);

  return !obvious_false_eye(b, color) && play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat200(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);

  return !obvious_false_eye(a, color);
}

static int
autohelperowl_defendpat201(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);

  return countlib(a) > 2;
}

static int
autohelperowl_defendpat206(int trans, int move, int color, int action)
{
  int a, b, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);

  return ATTACK_MACRO(A) && !play_attack_defend_n(color, 0, 3, move, a, b, A);
}

static int
autohelperowl_defendpat207(int trans, int move, int color, int action)
{
  int a, b, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);

  return ATTACK_MACRO(A) && play_attack_defend_n(color, 0, 3, move, a, b, A) != WIN;
}

static int
autohelperowl_defendpat208(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return does_attack(move, A);
}

static int
autohelperowl_defendpat209(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat210(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);

  return !play_attack_defend_n(color, 0, 2, move, a, a);
}

static int
autohelperowl_defendpat218(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(609, trans, move);

  return ATTACK_MACRO(a) && ! play_attack_defend_n(color, 1, 1, move, a);
}

static int
autohelperowl_defendpat219(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(color, 0, 1, move, A) != WIN;
}

static int
autohelperowl_defendpat220(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(612, trans, move);

  return countlib(a) == 2;
}

static int
autohelperowl_defendpat223(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(645, trans, move);

  return !play_attack_defend_n(color, 0, 1, move, A);
}

static int
autohelperowl_defendpat225(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(719, trans, move);

  return countlib(A)==1;
}

static int
autohelperowl_defendpat229(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  B = AFFINE_TRANSFORM(647, trans, move);

  return !play_attack_defend_n(color, 1, 1, move, a) && play_attack_defend_n(color, 1, 1, move, B);
}

static int
autohelperowl_defendpat230(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_defendpat233(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(755, trans, move);

  return countlib(a)==2;
}

static int
autohelperowl_defendpat234(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(573, trans, move);

  return countlib(a)==2;
}

static int
autohelperowl_defendpat236(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return play_attack_defend_n(color, 0, 1, move, A) != WIN;
}

static int
autohelperowl_defendpat240(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, A, A);
}

static int
autohelperowl_defendpat242(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(685, trans, move);

  return play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat243(int trans, int move, int color, int action)
{
  int b, c, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(682, trans, move);
  A = AFFINE_TRANSFORM(720, trans, move);

  return does_attack(move, A) && play_attack_defend_n(OTHER_COLOR(color), 1, 3, b, move, c, A);
}

static int
autohelperowl_defendpat248(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);

  return play_attack_defend_n(color, 1, 1, move, a)!=WIN;
}

static int
autohelperowl_defendpat249(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return  does_attack(move, A);
}

static int
autohelperowl_defendpat250(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(720, trans, move);

  return  does_attack(move, A);
}

static int
autohelperowl_defendpat251(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return  does_attack(move, A);
}

static int
autohelperowl_defendpat252(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);

  return  does_attack(move, A);
}

static int
autohelperowl_defendpat255(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);

  return play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_defendpat256(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return countlib(a)==1 && owl_eyespace(move) && accuratelib(move, color, MAX_LIBERTIES, NULL) > 0;
}

static int
autohelperowl_defendpat258(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(686, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);

  return play_attack_defend_n(OTHER_COLOR(color), 1, 3, a, move, b, b);
}

static int
autohelperowl_defendpat259(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);
  d = AFFINE_TRANSFORM(720, trans, move);

  return  somewhere(color, 0, 4, a, b, c, d);
}

static int
autohelperowl_defendpat260(int trans, int move, int color, int action)
{
  int a, B, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  B = AFFINE_TRANSFORM(647, trans, move);
  C = AFFINE_TRANSFORM(685, trans, move);

  return  (countstones(B) > 1 && countstones(C) > 1)  && safe_move(move, OTHER_COLOR(color)) && !play_attack_defend_n(OTHER_COLOR(color), 1, 1, move, a);
}

static int
autohelperowl_defendpat261(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return  countlib(A) == 1 && countstones(A) > 2;
}

static int
autohelperowl_defendpat262(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);

  return !ATTACK_MACRO(a) || (countstones(a)<=2 && does_attack(move, a));
}

static int
autohelperowl_defendpat264(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);

  return  !ATTACK_MACRO(a) && accuratelib(move, OTHER_COLOR(color), MAX_LIBERTIES, NULL) > 1;
}

static int
autohelperowl_defendpat265(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(686, trans, move);
  c = AFFINE_TRANSFORM(649, trans, move);

  return countlib(b)>1 && play_attack_defend_n(color, 1, 2, move, a, a) && !play_attack_defend2_n(OTHER_COLOR(color), 1, 3, move, NO_MOVE, a, a, c);
}

static int
autohelperowl_defendpat266(int trans, int move, int color, int action)
{
  int a, b, c, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(686, trans, move);
  c = AFFINE_TRANSFORM(649, trans, move);
  D = AFFINE_TRANSFORM(722, trans, move);

  return (countlib(b)>1 && play_attack_defend_n(color, 1, 2, move, a, a) && !play_attack_defend2_n(OTHER_COLOR(color), 1, 3, move, NO_MOVE, a, a, c))&& (!somewhere(OTHER_COLOR(color), 0, 1, D) || play_attack_defend_n(color, 1, 2, move, a, D))&& (!is_legal(D, OTHER_COLOR(color)) || play_attack_defend_n(color, 1, 2, move, D, D));
}

static int
autohelperowl_defendpat269(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(720, trans, move);
  C = AFFINE_TRANSFORM(683, trans, move);

  return countlib(a)>1 && countlib(b)>1 && !ATTACK_MACRO(C);
}

static int
autohelperowl_defendpat270(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(720, trans, move);

  return (owl_escape_value(a)>0 || owl_escape_value(b)>0) && countlib(a)>1 && countlib(b)>1;
}

static int
autohelperowl_defendpat271(int trans, int move, int color, int action)
{
  int b, c, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A) == 2 && countlib(b)>1 && countlib(c)>1 && !ATTACK_MACRO(A) && !play_connect_n(color, 0, 1, move, b, c);
}

static int
autohelperowl_defendpat272(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return vital_chain(A) && vital_chain(B) && !play_attack_defend2_n(color, 0, 1, move, A, B);
}

static int
autohelperowl_defendpat273(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return vital_chain(A)>1 && vital_chain(B)>1 && !play_attack_defend2_n(color, 0, 1, move, A, B);
}

static int
autohelperowl_defendpat274(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(685, trans, move);

  return  play_break_through_n(color, 2, move, a, b, a, c) == WIN;
}

static int
autohelperowl_defendpat275(int trans, int move, int color, int action)
{
  int c, d, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(720, trans, move);
  d = AFFINE_TRANSFORM(722, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return (countlib(A)<=3 && accuratelib(c, color, MAX_LIBERTIES, NULL)>2) || (countlib(B)<=3 && accuratelib(d, color, MAX_LIBERTIES, NULL)>2);
}

static int
autohelperowl_defendpat277(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(610, trans, move);

  return play_attack_defend2_n(color, 1, 2, move, a, B, a);
}

static int
autohelperowl_defendpat278(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);

  return  does_attack(move, a);
}

static int
autohelperowl_defendpat280(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, a, B);
}

static int
autohelperowl_defendpat282(int trans, int move, int color, int action)
{
  int a, e, f, B, C, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(757, trans, move);
  e = AFFINE_TRANSFORM(796, trans, move);
  f = AFFINE_TRANSFORM(648, trans, move);
  B = AFFINE_TRANSFORM(794, trans, move);
  C = AFFINE_TRANSFORM(758, trans, move);
  D = AFFINE_TRANSFORM(685, trans, move);

  return  !play_attack_defend2_n(color, 0, 3, move, f, a, B, C) && play_attack_defend_n(color, 1, 1, move, D) && !safe_move(e, OTHER_COLOR(color));
}

static int
autohelperowl_defendpat283(int trans, int move, int color, int action)
{
  int a, B, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(686, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);
  C = AFFINE_TRANSFORM(685, trans, move);

  return owl_goal_dragon(a) && !play_attack_defend2_n(color, 0, 1, move, B, C);
}

static int
autohelperowl_defendpat284(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return  play_attack_defend_n(color, 1, 1, move, A) && play_attack_defend_n(color, 1, 1, move, B);
}

static int
autohelperowl_defendpat285(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return  play_attack_defend_n(color, 1, 2, move, a, B);
}

static int
autohelperowl_defendpat286(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g, h, i;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(759, trans, move);
  c = AFFINE_TRANSFORM(722, trans, move);
  d = AFFINE_TRANSFORM(760, trans, move);
  e = AFFINE_TRANSFORM(797, trans, move);
  f = AFFINE_TRANSFORM(723, trans, move);
  g = AFFINE_TRANSFORM(685, trans, move);
  h = AFFINE_TRANSFORM(720, trans, move);
  i = AFFINE_TRANSFORM(795, trans, move);

  return owl_goal_dragon(h) && countlib(i)>1 && play_attack_defend_n(color, 1, 8, move, a, b, c, d, e, f, g, e);
}

static int
autohelperowl_defendpat287(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(722, trans, move);
  d = AFFINE_TRANSFORM(648, trans, move);
  e = AFFINE_TRANSFORM(610, trans, move);
  f = AFFINE_TRANSFORM(645, trans, move);
  g = AFFINE_TRANSFORM(720, trans, move);

  return owl_goal_dragon(f) && countlib(g)>1 && play_attack_defend_n(color, 1, 6, move, a, b, c, d, e, c);
}

static int
autohelperowl_defendpat288(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(759, trans, move);
  d = AFFINE_TRANSFORM(724, trans, move);
  e = AFFINE_TRANSFORM(649, trans, move);

  return owl_goal_dragon(d) && countlib(e)>1 && play_attack_defend_n(color, 1, 4, move, a, b, c, a);
}

static int
autohelperowl_defendpat289(int trans, int move, int color, int action)
{
  int a, c, d, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(687, trans, move);
  d = AFFINE_TRANSFORM(612, trans, move);
  B = AFFINE_TRANSFORM(611, trans, move);

  return owl_goal_dragon(c) && countlib(d)>1 && play_attack_defend_n(color, 1, 2, move, a, B);
}

static int
autohelperowl_defendpat291(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);

  return play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_defendpat292(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return play_attack_defend_n(color, 1, 2, move, a, B);
}

static int
autohelperowl_defendpat293(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(760, trans, move);

  return play_attack_defend_n(color, 1, 2, move, a, B) && countstones(B) > 2;
}

static int
autohelperowl_defendpat295(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(681, trans, move);
  b = AFFINE_TRANSFORM(795, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat296(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(718, trans, move);
  b = AFFINE_TRANSFORM(610, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat300(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend2_n(color, 1, 2, move, a, a, B);
}

static int
autohelperowl_defendpat301(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return play_attack_defend_n(color, 1, 1, move, A) || play_attack_defend_n(color, 1, 1, move, B);
}

static int
autohelperowl_defendpat302(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(color, 1, 2, move, a, B);
}

static int
autohelperowl_defendpat303(int trans, int move, int color, int action)
{
  int c, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(646, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return countlib(A)==2 && owl_escape_value(c)>0 && !play_attack_defend2_n(color, 0, 1, move, A, B);
}

static int
autohelperowl_defendpat304(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(611, trans, move);
  b = AFFINE_TRANSFORM(610, trans, move);
  c = AFFINE_TRANSFORM(609, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat305(int trans, int move, int color, int action)
{
  int b, c, A, B;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return countlib(c)>1 && play_attack_defend_n(color, 1, 1, move, A) && play_attack_defend_n(color, 1, 2, move, b, B);
}

static int
autohelperowl_defendpat306(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);

  return countlib(a)>1;
}

static int
autohelperowl_defendpat309(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);

  return  !safe_move(a, OTHER_COLOR(color)) && countlib(b)>1;
}

static int
autohelperowl_defendpat310(int trans, int move, int color, int action)
{
  int a, b, C, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  C = AFFINE_TRANSFORM(647, trans, move);
  D = AFFINE_TRANSFORM(683, trans, move);

  return owl_goal_dragon(a) && owl_escape_value(b)>0&& play_attack_defend_n(color, 1, 1, move, C) && play_attack_defend_n(color, 1, 1, move, D);
}

static int
autohelperowl_defendpat311(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return  play_attack_defend2_n(color, 1, 1, move, A, B);
}

static int
autohelperowl_defendpat312(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return owl_escape_value(a)>0;
}

static int
autohelperowl_defendpat314(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  B = AFFINE_TRANSFORM(720, trans, move);

  return  owl_escape_value(a)>0 && play_attack_defend_n(color, 1, 2, move, a, B);
}

static int
autohelperowl_defendpat316(int trans, int move, int color, int action)
{
  int a, c, d, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(611, trans, move);
  d = AFFINE_TRANSFORM(649, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return countlib(B)<=4 && owl_escape_value(c) + owl_escape_value(d) > 0&& play_attack_defend2_n(color, 1, 2, move, a, a, B);
}

static int
autohelperowl_defendpat317(int trans, int move, int color, int action)
{
  int d, e, f, A, B, C;
  UNUSED(color);
  UNUSED(action);

  d = AFFINE_TRANSFORM(722, trans, move);
  e = AFFINE_TRANSFORM(609, trans, move);
  f = AFFINE_TRANSFORM(683, trans, move);
  A = AFFINE_TRANSFORM(611, trans, move);
  B = AFFINE_TRANSFORM(647, trans, move);
  C = AFFINE_TRANSFORM(685, trans, move);

  return  countlib(C) == 2 && (owl_escape_value(e) > 0 || vital_chain(A)) && (owl_escape_value(f) > 0 || vital_chain(C)) && accuratelib(move, color, MAX_LIBERTIES, NULL) > 1 && play_attack_defend2_n(color, 1, 2, move, d, B, A);
}

static int
autohelperowl_defendpat318(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);

  return  (owl_escape_value(move) > 0) && !play_attack_defend2_n(color, 0, 1, move, a, b);
}

static int
autohelperowl_defendpat319(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(648, trans, move);
  d = AFFINE_TRANSFORM(685, trans, move);

  return (owl_escape_value(b) > 0 || owl_escape_value(c) > 0 || owl_escape_value(d) > 0)&& play_attack_defend_n(color, 1, 1, move, a);
}

static int
autohelperowl_defendpat320(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);

  return  countlib(a) == 2 || play_attack_defend_n(color, 1, 1, move, a);
}

static int
autohelperowl_defendpat321(int trans, int move, int color, int action)
{
  int A, B, C;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(759, trans, move);
  C = AFFINE_TRANSFORM(720, trans, move);

  return  does_defend(move, A) && !play_attack_defend_n(color, 1, 1, move, B) && !same_string(B, C) && vital_chain(B) && vital_chain(C) && (play_attack_defend_n(color, 1, 1, move, B) || play_attack_defend_n(color, 1, 1, move, C)) && !play_connect_n(color, 1, 1, move, B, C);
}

static int
autohelperowl_defendpat322(int trans, int move, int color, int action)
{
  int c, d, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(758, trans, move);
  d = AFFINE_TRANSFORM(723, trans, move);
  A = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(648, trans, move);

  return countlib(A)==2 && countlib(c)>1 && countlib(d)>1 && play_attack_defend_n(color, 1, 1, move, B);
}

static int
autohelperowl_defendpat323(int trans, int move, int color, int action)
{
  int b, c, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);
  A = AFFINE_TRANSFORM(721, trans, move);

  return  countlib(A) == 1 && (owl_escape_value(b) > 0 || owl_escape_value(c) > 0);
}

static int
autohelperowl_defendpat324(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);

  return  countlib(A) == 1;
}

static int
autohelperowl_defendpat326(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return  countlib(A)==2;
}

static int
autohelperowl_defendpat327(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return  countlib(A)==2 && !play_attack_defend2_n(color, 0, 1, move, A, B);
}

static int
autohelperowl_defendpat328(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(685, trans, move);
  B = AFFINE_TRANSFORM(646, trans, move);

  return countlib(A) <= 2 && (somewhere(color, 0, 1, B) || !ATTACK_MACRO(A) || DEFEND_MACRO(A));
}

static int
autohelperowl_defendpat329(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(646, trans, move);

  return !ATTACK_MACRO(A) && play_attack_defend_n(color, 1, 1, move, A) && !obvious_false_eye(b, color);
}

static int
autohelperowl_defendpat330(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(647, trans, move);

  return countstones(A)>=3 && !ATTACK_MACRO(A) && play_attack_defend_n(color, 1, 1, move, A) && !obvious_false_eye(b, color);
}

static int
autohelperowl_defendpat331(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);

  return play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat332(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(685, trans, move);

  return  play_attack_defend_n(color, 1, 1, move, A);
}

static int
autohelperowl_defendpat333(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);
  c = AFFINE_TRANSFORM(646, trans, move);

  return owl_escape_value(c)>0 && play_attack_defend2_n(color, 1, 2, move, a, a, b);
}

static int
autohelperowl_defendpat334(int trans, int move, int color, int action)
{
  int a, c, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return owl_escape_value(c)>0 && play_attack_defend2_n(color, 1, 2, move, a, a, B);
}

static int
autohelperowl_defendpat335(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);
  d = AFFINE_TRANSFORM(759, trans, move);
  e = AFFINE_TRANSFORM(685, trans, move);
  f = AFFINE_TRANSFORM(647, trans, move);
  g = AFFINE_TRANSFORM(758, trans, move);

  return (!owl_goal_dragon(f) || !owl_goal_dragon(g))&& (play_attack_defend_n(color, 1, 6, move, a, b, c, d, e, e) || play_attack_defend_n(color, 1, 6, move, a, b, c, e, d, d));
}

static int
autohelperowl_defendpat336(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);

  return (!owl_goal_dragon(a) || !owl_goal_dragon(b))&& !play_connect_n(color, 0, 1, move, a, b);
}

static int
autohelperowl_defendpat337(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);
  d = AFFINE_TRANSFORM(685, trans, move);
  e = AFFINE_TRANSFORM(722, trans, move);

  return !(somewhere(color, 0, 1, d) && somewhere(color, 0, 1, e))&& (!owl_goal_dragon(b) || !owl_goal_dragon(c)) && play_attack_defend_n(color, 1, 2, move, a, a);
}

static int
autohelperowl_defendpat338(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat339(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(719, trans, move);
  b = AFFINE_TRANSFORM(756, trans, move);
  c = AFFINE_TRANSFORM(757, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat340(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(646, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat341(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_defendpat342(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(a) > 0;
}

static int
autohelperowl_defendpat343(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_defendpat344(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_defendpat345(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(759, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_defendpat346(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(682, trans, move);
  b = AFFINE_TRANSFORM(719, trans, move);
  c = AFFINE_TRANSFORM(757, trans, move);
  d = AFFINE_TRANSFORM(645, trans, move);
  e = AFFINE_TRANSFORM(646, trans, move);

  return (!somewhere(OTHER_COLOR(color), 0, 1, e) && !somewhere(OTHER_COLOR(color), 0, 1, d) && (owl_escape_value(a) > 0))|| owl_escape_value(b) > 0|| owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat347(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(758, trans, move);
  b = AFFINE_TRANSFORM(759, trans, move);
  c = AFFINE_TRANSFORM(723, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat348(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(650, trans, move);
  b = AFFINE_TRANSFORM(613, trans, move);
  c = AFFINE_TRANSFORM(575, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat349(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_defendpat350(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return owl_escape_value(move) > 0;
}

static int
autohelperowl_defendpat351(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);

  return  owl_escape_value(a) > 0 || owl_escape_value(b) > 0;
}

static int
autohelperowl_defendpat352(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);

  return !owl_goal_dragon(a);
}

static int
autohelperowl_defendpat353(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);

  return owl_strong_dragon(a);
}

static int
autohelperowl_defendpat354(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(686, trans, move);

  return owl_escape_value(a)>0;
}

static int
autohelperowl_defendpat355(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(723, trans, move);
  b = AFFINE_TRANSFORM(760, trans, move);
  c = AFFINE_TRANSFORM(759, trans, move);
  d = AFFINE_TRANSFORM(686, trans, move);
  e = AFFINE_TRANSFORM(758, trans, move);

  return owl_escape_value(a) > 0 || owl_escape_value(b) > 0|| owl_escape_value(c) > 0 || owl_escape_value(d) > 0|| owl_escape_value(e) > 0;
}

static int
autohelperowl_defendpat357(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);

  return !owl_goal_dragon(a) || !owl_goal_dragon(b);
}

static int
autohelperowl_defendpat358(int trans, int move, int color, int action)
{
  int c, d, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(720, trans, move);
  d = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return  (!owl_goal_dragon(A) || !owl_goal_dragon(B)) && !play_attack_defend2_n(OTHER_COLOR(color), 1, 3, move, d, c, c, move);
}

static int
autohelperowl_defendpat359(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);

  return owl_strong_dragon(a) || owl_strong_dragon(b);
}

static int
autohelperowl_defendpat360(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(686, trans, move);

  return !owl_goal_dragon(a) || !owl_goal_dragon(b);
}

static int
autohelperowl_defendpat361(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(686, trans, move);

  return owl_strong_dragon(a) || owl_strong_dragon(b);
}

static int
autohelperowl_defendpat362(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  C = AFFINE_TRANSFORM(647, trans, move);

  return (!owl_goal_dragon(a) || !owl_goal_dragon(b)) && countlib(C) <= 2;
}

static int
autohelperowl_defendpat363(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat364(int trans, int move, int color, int action)
{
  int d, A, B, C;
  UNUSED(color);
  UNUSED(action);

  d = AFFINE_TRANSFORM(647, trans, move);
  A = AFFINE_TRANSFORM(682, trans, move);
  B = AFFINE_TRANSFORM(645, trans, move);
  C = AFFINE_TRANSFORM(646, trans, move);

  return (owl_escape_value(A) > 0 || owl_escape_value(B) > 0 || owl_escape_value(C) > 0)&& play_attack_defend_n(color, 1, 1, move, d);
}

static int
autohelperowl_defendpat365(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(686, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat366(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  C = AFFINE_TRANSFORM(647, trans, move);

  return (owl_escape_value(a)>0 || owl_escape_value(b)>0) && countlib(C) <= 2;
}

static int
autohelperowl_defendpat367(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat368(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(686, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat369(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  C = AFFINE_TRANSFORM(647, trans, move);

  return (owl_escape_value(a)>0 || owl_escape_value(b)>0) && countlib(C) <= 2;
}

static int
autohelperowl_defendpat371(int trans, int move, int color, int action)
{
  int a, b, c, d, f, E;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);
  c = AFFINE_TRANSFORM(647, trans, move);
  d = AFFINE_TRANSFORM(722, trans, move);
  f = AFFINE_TRANSFORM(686, trans, move);
  E = AFFINE_TRANSFORM(721, trans, move);

  return owl_escape_value(f)>0 && !play_attack_defend2_n(color, 0, 5, move, a, b, c, d, a, E);
}

static int
autohelperowl_defendpat372(int trans, int move, int color, int action)
{
  int a, b, e, C, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  e = AFFINE_TRANSFORM(720, trans, move);
  C = AFFINE_TRANSFORM(645, trans, move);
  D = AFFINE_TRANSFORM(683, trans, move);

  return owl_escape_value(e)>0 && !play_attack_defend2_n(color, 0, 3, move, a, b, C, D);
}

static int
autohelperowl_defendpat373(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(649, trans, move);

  return owl_escape_value(a)>0;
}

static int
autohelperowl_defendpat374(int trans, int move, int color, int action)
{
  int c, d, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(648, trans, move);
  d = AFFINE_TRANSFORM(646, trans, move);
  A = AFFINE_TRANSFORM(683, trans, move);
  B = AFFINE_TRANSFORM(647, trans, move);

  return owl_escape_value(c)>0 && owl_goal_dragon(d) && !play_attack_defend2_n(color, 0, 1, move, A, B);
}

static int
autohelperowl_defendpat375(int trans, int move, int color, int action)
{
  int c, d;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(648, trans, move);
  d = AFFINE_TRANSFORM(646, trans, move);

  return owl_escape_value(c)>0 && owl_goal_dragon(d);
}

static int
autohelperowl_defendpat376(int trans, int move, int color, int action)
{
  UNUSED(trans);
  UNUSED(color);
  UNUSED(action);

  UNUSED(move);

  return owl_escape_value(move)>0;
}

static int
autohelperowl_defendpat377(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);

  return owl_escape_value(a)>0 && owl_goal_dragon(b) && countlib(b)>1;
}

static int
autohelperowl_defendpat378(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return  owl_escape_value(a)>0;
}

static int
autohelperowl_defendpat379(int trans, int move, int color, int action)
{
  int a, b, c, d, f, E;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(647, trans, move);
  d = AFFINE_TRANSFORM(610, trans, move);
  f = AFFINE_TRANSFORM(648, trans, move);
  E = AFFINE_TRANSFORM(609, trans, move);

  return owl_escape_value(f)>0 && !play_attack_defend2_n(color, 0, 5, move, a, b, c, d, c, E);
}

static int
autohelperowl_defendpat380(int trans, int move, int color, int action)
{
  int a, b, d, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);
  d = AFFINE_TRANSFORM(758, trans, move);
  C = AFFINE_TRANSFORM(685, trans, move);

  return owl_escape_value(d)>0 && !play_attack_defend2_n(color, 0, 3, move, a, b, a, C);
}

static int
autohelperowl_defendpat381(int trans, int move, int color, int action)
{
  int d;
  UNUSED(color);
  UNUSED(action);

  d = AFFINE_TRANSFORM(647, trans, move);

  return owl_escape_value(d)>0;
}

static int
autohelperowl_defendpat382(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(610, trans, move);
  d = AFFINE_TRANSFORM(721, trans, move);

  return (owl_escape_value(c)>0 || owl_escape_value(d)>0) && play_attack_defend_n(color, 1, 2, move, a, a)&& !play_attack_defend2_n(color, 1, 3, move, b, a, move, a) && !play_attack_defend2_n(color, 1, 3, move, b, a, c, a);
}

static int
autohelperowl_defendpat383(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(686, trans, move);

  return owl_escape_value(a)>0;
}

static int
autohelperowl_defendpat385(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(649, trans, move);
  b = AFFINE_TRANSFORM(611, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_defendpat386(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(611, trans, move);
  b = AFFINE_TRANSFORM(649, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_defendpat387(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(610, trans, move);
  c = AFFINE_TRANSFORM(682, trans, move);
  d = AFFINE_TRANSFORM(720, trans, move);

  return somewhere(color, 0, 2, c, d) && (owl_escape_value(a) + owl_escape_value(b) > 0);
}

static int
autohelperowl_defendpat388(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(610, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_defendpat389(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(686, trans, move);

  return owl_escape_value(a)>0;
}

static int
autohelperowl_defendpat390(int trans, int move, int color, int action)
{
  int a, b, c, e, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(647, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);
  e = AFFINE_TRANSFORM(646, trans, move);
  D = AFFINE_TRANSFORM(683, trans, move);

  return countlib(D)==2 && countlib(c)>1 && countlib(e)>1&& (owl_escape_value(c)>0 || owl_escape_value(e)>0)&& play_attack_defend_n(color, 1, 4, move, NO_MOVE, a, b, b);
}

static int
autohelperowl_defendpat391(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(723, trans, move);
  b = AFFINE_TRANSFORM(686, trans, move);
  c = AFFINE_TRANSFORM(649, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat392(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(610, trans, move);

  return !play_attack_defend_n(color, 0, 1, move, A);
}

static int
autohelperowl_defendpat393(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat394(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);

  return owl_strong_dragon(a) || owl_strong_dragon(b);
}

static int
autohelperowl_defendpat395(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);

  return (owl_strong_dragon(a) || owl_strong_dragon(b)) && !play_connect_n(color, 0, 1, move, a, b);
}

static int
autohelperowl_defendpat396(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(722, trans, move);

  return owl_strong_dragon(a) || owl_strong_dragon(b);
}

static int
autohelperowl_defendpat397(int trans, int move, int color, int action)
{
  int b, c, d, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(686, trans, move);
  d = AFFINE_TRANSFORM(649, trans, move);
  A = AFFINE_TRANSFORM(647, trans, move);

  return countlib(A) == 1&& (owl_escape_value(b) + owl_escape_value(c) + owl_escape_value(d)) > 0;
}

static int
autohelperowl_defendpat398(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);

  return owl_escape_value(a)>0;
}

static int
autohelperowl_defendpat399(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);
  c = AFFINE_TRANSFORM(683, trans, move);
  d = AFFINE_TRANSFORM(682, trans, move);

  return !owl_goal_dragon(a) && play_attack_defend2_n(OTHER_COLOR(color), 1, 3, b, c, d, b, d);
}

static int
autohelperowl_defendpat401(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat402(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(609, trans, move);
  b = AFFINE_TRANSFORM(720, trans, move);

  return countlib(a)>1 && countlib(b)>1;
}

static int
autohelperowl_defendpat403(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(648, trans, move);
  d = AFFINE_TRANSFORM(682, trans, move);

  return  (owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0) && !play_connect_n(color, 0, 1, move, d, move);
}

static int
autohelperowl_defendpat404(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(648, trans, move);
  d = AFFINE_TRANSFORM(682, trans, move);

  return  (owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0) && play_connect_n(color, 0, 1, move, d, move);
}

static int
autohelperowl_defendpat405(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(685, trans, move);
  c = AFFINE_TRANSFORM(573, trans, move);

  return  (owl_escape_value(a) + owl_escape_value(move) + owl_escape_value(b) > 0) && !play_connect_n(color, 0, 1, move, c, move);
}

static int
autohelperowl_defendpat406(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(760, trans, move);
  b = AFFINE_TRANSFORM(759, trans, move);
  c = AFFINE_TRANSFORM(758, trans, move);

  return  owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat407(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(609, trans, move);
  c = AFFINE_TRANSFORM(647, trans, move);
  d = AFFINE_TRANSFORM(646, trans, move);
  e = AFFINE_TRANSFORM(683, trans, move);

  return (owl_escape_value(a) > 0 || owl_escape_value(b) > 0)&& play_attack_defend2_n(color, 1, 4, move, c, d, e, c, e);
}

static int
autohelperowl_defendpat408(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(757, trans, move);
  b = AFFINE_TRANSFORM(719, trans, move);
  c = AFFINE_TRANSFORM(682, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat409(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(a) + owl_escape_value(b) + owl_escape_value(c) > 0;
}

static int
autohelperowl_defendpat410(int trans, int move, int color, int action)
{
  int A, B, C;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(720, trans, move);
  B = AFFINE_TRANSFORM(722, trans, move);
  C = AFFINE_TRANSFORM(647, trans, move);

  return !same_string(A, B) && (countlib(A) <= 4 || countlib(B) <= 4 || countlib(C) <= 4);
}

static int
autohelperowl_defendpat411(int trans, int move, int color, int action)
{
  int A, B, C;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(720, trans, move);
  B = AFFINE_TRANSFORM(722, trans, move);
  C = AFFINE_TRANSFORM(647, trans, move);

  return !same_string(A, B) && (countlib(A) <= 4 || countlib(B) <= 4 || countlib(C) <= 4)&& !play_connect_n(color, 1, 1, move, A, C);
}

static int
autohelperowl_defendpat416(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(757, trans, move);

  return owl_goal_dragon(a);
}

static int
autohelperowl_defendpat418(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(686, trans, move);
  b = AFFINE_TRANSFORM(646, trans, move);

  return countlib(a)>1 && owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat419(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(611, trans, move);
  b = AFFINE_TRANSFORM(648, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat420(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(682, trans, move);

  return owl_escape_value(a)>0;
}

static int
autohelperowl_defendpat421(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return owl_escape_value(a)>0 && !ATTACK_MACRO(B);
}

static int
autohelperowl_defendpat422(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  B = AFFINE_TRANSFORM(683, trans, move);

  return owl_escape_value(a)>0 && does_attack(move, B);
}

static int
autohelperowl_defendpat423(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(572, trans, move);
  b = AFFINE_TRANSFORM(609, trans, move);

  return somewhere(color, 0, 2, a, b) && owl_escape_value(a) + owl_escape_value(b) > 0;
}

static int
autohelperowl_defendpat424(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return  DEFEND_MACRO(A);
}

static int
autohelperowl_defendpat425(int trans, int move, int color, int action)
{
  int a, b, c, d, E;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  b = AFFINE_TRANSFORM(757, trans, move);
  c = AFFINE_TRANSFORM(721, trans, move);
  d = AFFINE_TRANSFORM(720, trans, move);
  E = AFFINE_TRANSFORM(683, trans, move);

  return  (owl_escape_value(a) > 0 || owl_escape_value(b) > 0) && ((somewhere(color, 0, 1, d) && play_attack_defend2_n(color, 1, 2, move, c, c, E))     || (!somewhere(color, 0, 1, d) && !play_attack_defend2_n(color, 0, 3, move, c, d, c, E)));
}

static int
autohelperowl_defendpat426(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);

  return DEFEND_MACRO(A);
}

static int
autohelperowl_defendpat427(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(647, trans, move);

  return  vital_chain(A) && vital_chain(B) && play_attack_defend2_n(color, 1, 1, move, A, B) && !play_connect_n(color, 1, 1, move, A, B);
}

static int
autohelperowl_defendpat428(int trans, int move, int color, int action)
{
  int d, e, A, B, C;
  UNUSED(color);
  UNUSED(action);

  d = AFFINE_TRANSFORM(721, trans, move);
  e = AFFINE_TRANSFORM(647, trans, move);
  A = AFFINE_TRANSFORM(648, trans, move);
  B = AFFINE_TRANSFORM(610, trans, move);
  C = AFFINE_TRANSFORM(611, trans, move);

  return  (owl_escape_value(A) > 0 || owl_escape_value(B) > 0 || owl_escape_value(C) > 0) && !ATTACK_MACRO(d) && play_attack_defend_n(color, 1, 2, move, A, d) && play_attack_defend_n(color, 1, 2, move, e, d);
}

static int
autohelperowl_defendpat429(int trans, int move, int color, int action)
{
  int A, B, C;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(722, trans, move);
  C = AFFINE_TRANSFORM(685, trans, move);

  return  owl_escape_value(A) + owl_escape_value(B) + owl_escape_value(C) > 3;
}

static int
autohelperowl_defendpat430(int trans, int move, int color, int action)
{
  int a, B, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(646, trans, move);
  C = AFFINE_TRANSFORM(683, trans, move);

  return  (owl_escape_value(B) > 0 || owl_escape_value(a) > 0) && play_attack_defend2_n(color, 1, 2, move, a, a, C);
}

static int
autohelperowl_defendpat431(int trans, int move, int color, int action)
{
  int c, d, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(647, trans, move);
  d = AFFINE_TRANSFORM(683, trans, move);
  A = AFFINE_TRANSFORM(646, trans, move);
  B = AFFINE_TRANSFORM(721, trans, move);

  return  (owl_escape_value(A) > 0 || owl_escape_value(B) > 0) && play_attack_defend_n(color, 1, 2, move, c, d);
}

static int
autohelperowl_defendpat432(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  B = AFFINE_TRANSFORM(682, trans, move);

  return (owl_escape_value(a) > 0) && !play_connect_n(color, 0, 1, move, move, B);
}

static int
autohelperowl_defendpat433(int trans, int move, int color, int action)
{
  int c, d, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(685, trans, move);
  d = AFFINE_TRANSFORM(721, trans, move);
  A = AFFINE_TRANSFORM(646, trans, move);
  B = AFFINE_TRANSFORM(722, trans, move);

  return  (owl_escape_value(A) > 0 || owl_escape_value(B) > 0) && (!somewhere(OTHER_COLOR(color), 0, 1, c) || play_attack_defend2_n(color, 1, 2, move, d, c, d));
}

static int
autohelperowl_defendpat434(int trans, int move, int color, int action)
{
  int c, d, e, f, A, B;
  UNUSED(color);
  UNUSED(action);

  c = AFFINE_TRANSFORM(647, trans, move);
  d = AFFINE_TRANSFORM(646, trans, move);
  e = AFFINE_TRANSFORM(683, trans, move);
  f = AFFINE_TRANSFORM(609, trans, move);
  A = AFFINE_TRANSFORM(721, trans, move);
  B = AFFINE_TRANSFORM(610, trans, move);

  return  (owl_escape_value(A) > 0 || owl_escape_value(B) > 0) && (play_attack_defend_n(color, 1, 4, move, c, d, f, e) && play_attack_defend_n(color, 1, 4, move, c, d, f, f));
}

static int
autohelperowl_defendpat435(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);

  return owl_strong_dragon(a) || owl_strong_dragon(b);
}

static int
autohelperowl_defendpat436(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);

  return owl_escape_value(a)>0 || owl_escape_value(b)>0;
}

static int
autohelperowl_defendpat437(int trans, int move, int color, int action)
{
  int a, c, d, e, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  c = AFFINE_TRANSFORM(756, trans, move);
  d = AFFINE_TRANSFORM(719, trans, move);
  e = AFFINE_TRANSFORM(793, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);

  return (owl_escape_value(c)>0 || owl_escape_value(d)>0 || owl_escape_value(e)>0)&& countlib(B)==2 && accuratelib(move, color, MAX_LIBERTIES, NULL)>=2 && !play_attack_defend_n(color, 1, 1, move, a);
}

static int
autohelperowl_defendpat438(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(648, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  c = AFFINE_TRANSFORM(645, trans, move);
  d = AFFINE_TRANSFORM(719, trans, move);

  return (owl_escape_value(b)>0 || owl_escape_value(c)>0 || owl_escape_value(d)>0)&& !play_attack_defend_n(color, 1, 1, move, a);
}

static int
autohelperowl_defendpat439(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(646, trans, move);
  b = AFFINE_TRANSFORM(757, trans, move);

  return (owl_strong_dragon(a) || owl_strong_dragon(b)) && !play_connect_n(color, 0, 1, move, a, b);
}

static int
autohelperowl_defendpat440(int trans, int move, int color, int action)
{
  int a, b, c, d, A, B, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  b = AFFINE_TRANSFORM(721, trans, move);
  c = AFFINE_TRANSFORM(758, trans, move);
  d = AFFINE_TRANSFORM(757, trans, move);
  A = AFFINE_TRANSFORM(648, trans, move);
  B = AFFINE_TRANSFORM(685, trans, move);
  C = AFFINE_TRANSFORM(794, trans, move);

  return  owl_escape_value(d) > 0 && play_attack_defend2_n(color, 1, 5, move, a, b, c, d, B, c) && play_connect_n(color, 1, 6, move, a, b, c, d, NO_MOVE, A, C);
}

static int
autohelperowl_defendpat441(int trans, int move, int color, int action)
{
  int a, b, d, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(685, trans, move);
  b = AFFINE_TRANSFORM(682, trans, move);
  d = AFFINE_TRANSFORM(719, trans, move);
  C = AFFINE_TRANSFORM(720, trans, move);

  return owl_escape_value(a) > 0 && play_attack_defend_n(color, 1, 2, move, b, C) && !play_connect_n(OTHER_COLOR(color), 1, 1, move, a, d);
}

static int
autohelperowl_defendpat442(int trans, int move, int color, int action)
{
  int A, B, C;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(610, trans, move);
  B = AFFINE_TRANSFORM(648, trans, move);
  C = AFFINE_TRANSFORM(646, trans, move);

  return countlib(A)>1 && countlib(B)>1 && countlib(C)>1;
}

static int
autohelperowl_defendpat443(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return countlib(A)==1;
}

static int
autohelperowl_defendpat444(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(611, trans, move);
  B = AFFINE_TRANSFORM(649, trans, move);

  return  (countlib(A)>1) && (countlib(B)>1);
}

static int
autohelperowl_defendpat445(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(609, trans, move);
  B = AFFINE_TRANSFORM(646, trans, move);

  return  (is_legal(move, color) && owl_topological_eye(a, board[B])==3) || (!is_legal(move, color) && owl_topological_eye(a, board[B])==2);
}

static int
autohelperowl_defendpat447(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(color, 0, 1, move, A) != WIN;
}

static int
autohelperowl_defendpat448(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(color, 0, 1, move, A) != WIN;
}

static int
autohelperowl_defendpat449(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return play_attack_defend_n(color, 0, 1, move, A) != WIN;
}

static int
autohelperowl_defendpat455(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return ATTACK_MACRO(A) != 0;
}

static int
autohelperowl_defendpat456(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(647, trans, move);

  return play_attack_defend_n(color, 0, 1, move, A) != WIN;
}

static int
autohelperowl_defendpat458(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(756, trans, move);

  return countlib(a) > 1;
}

static int
autohelperowl_defendpat460(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)==1 && finish_ko_helper(A);
}

static int
autohelperowl_defendpat461(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)==1 && finish_ko_helper(A);
}

static int
autohelperowl_defendpat462(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)==2 && accuratelib(move, color, MAX_LIBERTIES, NULL)>1 && squeeze_ko_helper(A);
}

static int
autohelperowl_defendpat463(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(683, trans, move);

  return countlib(A)==2 && accuratelib(move, color, MAX_LIBERTIES, NULL)>1 && squeeze_ko_helper(A);
}

static int
autohelperowl_defendpat464(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(795, trans, move);

  return ATTACK_MACRO(A);
}

static int
autohelperowl_defendpat465(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(795, trans, move);

  return !safe_move(a, OTHER_COLOR(color));
}

static int
autohelperowl_defendpat466(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(683, trans, move);

  return play_attack_defend_n(OTHER_COLOR(color), 0, 1, move, a) != WIN && play_attack_defend_n(color, 1, 1, move, a) == 0;
}

static int
autohelperowl_defendpat467(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(646, trans, move);

  return countlib(A)==1;
}

static int
autohelperowl_defendpat470(int trans, int move, int color, int action)
{
  int a, b, c, d, A;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(609, trans, move);
  b = AFFINE_TRANSFORM(610, trans, move);
  c = AFFINE_TRANSFORM(611, trans, move);
  d = AFFINE_TRANSFORM(647, trans, move);
  A = AFFINE_TRANSFORM(646, trans, move);

  return  somewhere(color, 0, 3, a, b, c) && vital_chain(A) && !play_attack_defend_n(color, 0, 3, move, NO_MOVE, d, A);
}

static int
autohelperowl_defendpat471(int trans, int move, int color, int action)
{
  int a, b, c, d, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(609, trans, move);
  b = AFFINE_TRANSFORM(610, trans, move);
  c = AFFINE_TRANSFORM(611, trans, move);
  d = AFFINE_TRANSFORM(647, trans, move);
  B = AFFINE_TRANSFORM(648, trans, move);

  return  somewhere(color, 0, 3, a, b, c) && vital_chain(B) && !play_attack_defend_n(color, 0, 3, move, NO_MOVE, d, B);
}

static int
autohelperowl_defendpat472(int trans, int move, int color, int action)
{
  int b, A, B;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(719, trans, move);
  A = AFFINE_TRANSFORM(645, trans, move);
  B = AFFINE_TRANSFORM(682, trans, move);

  return  countlib(A) >= 3 && countlib(B) == 3 && accuratelib(b, color, MAX_LIBERTIES, NULL) > 2;
}

static int
autohelperowl_defendpat475(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(722, trans, move);
  b = AFFINE_TRANSFORM(758, trans, move);

  return  somewhere(color, 0, 1, b) || (somewhere(OTHER_COLOR(color), 0, 1, b) ? !play_attack_defend_n(color, 0, 1, move, b) : !play_attack_defend_n(color, 0, 2, move, b, b));
}

static int
autohelperowl_defendpat476(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(721, trans, move);
  b = AFFINE_TRANSFORM(683, trans, move);

  return  somewhere(color, 0, 1, b) || (somewhere(OTHER_COLOR(color), 0, 1, b) ? !play_attack_defend_n(color, 0, 1, move, b) : !play_attack_defend_n(color, 0, 2, move, b, b));
}

static int
autohelperowl_defendpat478(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(757, trans, move);
  B = AFFINE_TRANSFORM(682, trans, move);

  return  owl_proper_eye(a) && !ATTACK_MACRO(B);
}

static struct pattern_attribute attributes[] = {
#ifdef HAVE_TRANSPARENT_UNIONS
  {LAST_ATTRIBUTE,{.offset=0}},
  {THREATENS_TO_CAPTURE,{.offset=646}},
  {LAST_ATTRIBUTE,{.offset=0}},
  {THREATENS_TO_CAPTURE,{.offset=648}},
  {LAST_ATTRIBUTE,{.offset=0}},
  {THREATENS_TO_CAPTURE,{.offset=645}},
  {LAST_ATTRIBUTE,{.offset=0}},
  {THREATENS_EYE,{.offset=685}},
  {LAST_ATTRIBUTE,{.offset=0}},
  {THREATENS_EYE,{.offset=648}},
  {LAST_ATTRIBUTE,{.offset=0}},
  {THREATENS_EYE,{.offset=722}},
  {LAST_ATTRIBUTE,{.offset=0}},
  {THREATENS_EYE,{.offset=721}},
  {LAST_ATTRIBUTE,{.offset=0}},
  {THREATENS_EYE,{.offset=609}},
  {LAST_ATTRIBUTE,{.offset=0}},
  {REVERSE_SENTE,{.offset=757}},
  {LAST_ATTRIBUTE,{.offset=0}}
#else
  {LAST_ATTRIBUTE,0.0,0},
  {THREATENS_TO_CAPTURE,0.0,646},
  {LAST_ATTRIBUTE,0.0,0},
  {THREATENS_TO_CAPTURE,0.0,648},
  {LAST_ATTRIBUTE,0.0,0},
  {THREATENS_TO_CAPTURE,0.0,645},
  {LAST_ATTRIBUTE,0.0,0},
  {THREATENS_EYE,0.0,685},
  {LAST_ATTRIBUTE,0.0,0},
  {THREATENS_EYE,0.0,648},
  {LAST_ATTRIBUTE,0.0,0},
  {THREATENS_EYE,0.0,722},
  {LAST_ATTRIBUTE,0.0,0},
  {THREATENS_EYE,0.0,721},
  {LAST_ATTRIBUTE,0.0,0},
  {THREATENS_EYE,0.0,609},
  {LAST_ATTRIBUTE,0.0,0},
  {REVERSE_SENTE,0.0,757},
  {LAST_ATTRIBUTE,0.0,0}
#endif
};

static struct pattern owl_defendpat[] = {
  {owl_defendpat0,2,8, "D1",-2,0,2,3,4,3,0x2,759,
    { 0x3f3f3f0f, 0x00ffffff, 0xf0f0f0f0, 0xfffc0000, 0xffff0000, 0x3f3f3f3f, 0x00fcffff, 0xf0f0f0c0},
    { 0x00101008, 0x00500000, 0x10100000, 0x02140000, 0x00500000, 0x10100000, 0x00140200, 0x00101080}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat0,0,1.000000},
  {owl_defendpat1,2,8, "D2",-2,-2,2,1,4,3,0x2,720,
    { 0xffbfffff, 0xefffffff, 0xfcf8fcfc, 0xffffef00, 0xffffef00, 0xffbfffff, 0xefffffff, 0xfcf8fcfc},
    { 0x20100000, 0x00180000, 0x00102000, 0x00900000, 0x00180000, 0x00102000, 0x00900000, 0x20100000}
   , 0x0,55.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat2,1,8, "D3",0,-2,4,1,4,3,0x2,685,
    { 0x003fffff, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3f0000, 0x0f3f3f3f, 0x00f0fcfc},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x0,77.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat3,2,8, "D4",-1,-1,3,2,4,3,0x2,685,
    { 0xecfcfcfc, 0xfcf8fc00, 0xffffef00, 0xffbfffff, 0xfcf8fcfc, 0xfcfcec00, 0xffbfff00, 0xefffffff},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x0,83.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat4,1,8, "D100",-1,-1,2,2,3,3,0x2,721,
    { 0x3c3fffff, 0xc0fcfcf0, 0xfcf0f000, 0xffff0f00, 0xfcfcc000, 0xff3f3c00, 0x0fffff3f, 0xf0f0fcfc},
    { 0x28100000, 0x00180800, 0x0010a000, 0x80900000, 0x08180000, 0x00102800, 0x00908000, 0xa0100000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat5,2,8, "D101",-1,-1,3,3,4,4,0x2,645,
    { 0xf4fcf000, 0xffff3400, 0x3fff7f3f, 0x70fcfcfc, 0x34ffffff, 0xf0fcf4f0, 0xfcfc7000, 0x7fff3f00},
    { 0x00181000, 0x00502000, 0x10900000, 0x20140000, 0x20500000, 0x10180000, 0x00142000, 0x00901000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat6,2,8, "D102",-1,-1,2,2,3,3,0x2,721,
    { 0x1cffffff, 0xf0f4fcf0, 0xfcfcd000, 0xff7f3f00, 0xfcf4f000, 0xffff1c00, 0x3f7fff3f, 0xd0fcfcfc},
    { 0x00a05000, 0x60600000, 0x14280000, 0x00242400, 0x00606000, 0x50a00000, 0x24240000, 0x00281400}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat7,3,8, "D103",-1,-1,2,2,3,3,0x2,721,
    { 0x3cffffff, 0xf0fcfcf0, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xffff3c00, 0x3fffff3f, 0xf0fcfcfc},
    { 0x10a05000, 0x60640000, 0x14281000, 0x00642400, 0x00646000, 0x50a01000, 0x24640000, 0x10281400}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat8,2,8, "D104",-1,-1,1,2,2,3,0x2,720,
    { 0x0fffff00, 0xf0f0fcfc, 0xfcfcc000, 0xfc3c3c00, 0xfcf0f000, 0xffff0f00, 0x3c3cfcfc, 0xc0fcfc00},
    { 0x01900000, 0x20100004, 0x00180000, 0x00102000, 0x00102000, 0x00900100, 0x20100040, 0x00180000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat8,0,1.600000},
  {owl_defendpat9,3,8, "D104b",-1,-1,1,3,2,4,0x2,794,
    { 0x3fffff00, 0xf0fcfcfc, 0xfcfcf000, 0xfcfc3c00, 0xfcfcf000, 0xffff3f00, 0x3cfcfcfc, 0xf0fcfc00},
    { 0x11900000, 0x20140004, 0x00181000, 0x00502000, 0x00142000, 0x00901100, 0x20500040, 0x10180000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat9,0,1.600000},
  {owl_defendpat10,4,8, "D105",-2,-1,1,2,3,3,0x8,720,
    { 0xfcfefcfc, 0xfcfcfc20, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xfcfefc00, 0xffffff20, 0xfcfcfcfc},
    { 0x00180404, 0x00106000, 0x40900000, 0x25100000, 0x60100000, 0x04180000, 0x00102500, 0x00904040}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat11,3,8, "D106",0,-2,3,2,3,4,0x2,722,
    { 0x00ffffff, 0xf0f0f0f0, 0xfffc0000, 0x3f3f3f0f, 0xf0f0f0c0, 0xffff0000, 0x3f3f3f3f, 0x00fcffff},
    { 0x00924000, 0x60100020, 0x05180000, 0x00102404, 0x00106040, 0x40920000, 0x24100020, 0x00180500}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat12,1,8, "D107",-1,-1,3,2,4,3,0x2,685,
    { 0x3dffffff, 0xf0fcfcf4, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xffff3d00, 0x3fffff7f, 0xf0fcfcfc},
    { 0x00210000, 0x00200010, 0x00200000, 0x00200000, 0x00200000, 0x00210000, 0x00200010, 0x00200000}
   , 0x200,70.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat13,2,8, "D108",-2,-1,2,2,4,3,0x2,721,
    { 0xffffffff, 0xfcfffffd, 0xfcfcfcf0, 0xffffff00, 0xfffffc00, 0xffffff3d, 0xffffffff, 0xfcfcfcfc},
    { 0x21900000, 0x20180004, 0x00182000, 0x00902000, 0x00182000, 0x00902100, 0x20900040, 0x20180000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat14,2,8, "D109",-2,-1,2,2,4,3,0x2,647,
    { 0xffffffff, 0xfcfffffd, 0xfcfcfcf0, 0xffffff00, 0xfffffc00, 0xffffff3d, 0xffffffff, 0xfcfcfcfc},
    { 0x21100000, 0x00180004, 0x00102000, 0x00900000, 0x00180000, 0x00102100, 0x00900040, 0x20100000}
   , 0x800,95.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat15,4,8, "D110",-1,-3,2,3,3,6,0x2,610,
    { 0xfffeffff, 0xfcfcfcec, 0xffffff00, 0xffffffff, 0xfcfcfcfc, 0xfffeff00, 0xffffffef, 0xffffffff},
    { 0x02100100, 0x00100048, 0x00100000, 0x00100000, 0x00100000, 0x01100200, 0x00100084, 0x00100000}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat16,1,8, "D111",0,-1,3,1,3,2,0x2,685,
    { 0x007cfcfc, 0xd0f0f000, 0xfcf40000, 0x3f3f1f00, 0xf0f0d000, 0xfc7c0000, 0x1f3f3f00, 0x00f4fcfc},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x0,79.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat17,6,8, "D112",-1,0,2,5,3,5,0x2,795,
    { 0x2f3f2f3f, 0x00b8fcfc, 0xe0f0e000, 0xffbb0000, 0xfcb80000, 0x2f3f2f00, 0x00bbffff, 0xe0f0e0f0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat18,1,8, "D113",-1,-2,2,2,3,4,0x2,647,
    { 0xf4ffffff, 0xfcfcf4f0, 0xffff7f00, 0x7fffffff, 0xf4fcfcfc, 0xfffff400, 0xffff7f3f, 0x7fffffff},
    { 0x20120000, 0x00180020, 0x00102000, 0x00900000, 0x00180000, 0x00122000, 0x00900020, 0x20100000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat19,1,8, "D114",-1,0,2,2,3,2,0x2,685,
    { 0x00ffffff, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3f, 0x00fcfcfc},
    { 0x00200090, 0x00200000, 0x00200000, 0x00210200, 0x00200000, 0x00200000, 0x02210000, 0x00200018}
   , 0x0,77.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat20,2,8, "D115",0,-1,3,2,3,3,0x2,722,
    { 0x003c3ffe, 0x00f0f0c0, 0xf0f00000, 0x3f3f0300, 0xf0f00000, 0x3f3c0000, 0x033f3f0e, 0x00f0f0fc},
    { 0x00200040, 0x00200000, 0x00200000, 0x00200100, 0x00200000, 0x00200000, 0x01200000, 0x00200004}
   , 0x0,76.000000,attributes+0,1,NULL,autohelperowl_defendpat20,3,1.000000},
  {owl_defendpat21,2,8, "D116",-1,-2,1,0,2,2,0x2,648,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00900040, 0x20100000, 0x00180000, 0x00102100, 0x00102000, 0x00900000, 0x21100000, 0x00180004}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat21,0,0.010000},
  {owl_defendpat22,3,8, "D117",0,-2,2,2,2,4,0x2,647,
    { 0x00ffffff, 0xf0f0f0f0, 0xfefc0000, 0x3f3f3f08, 0xf0f0f080, 0xffff0000, 0x3f3f3f3f, 0x00fcfefc},
    { 0x00120100, 0x00100060, 0x00100000, 0x00100000, 0x00100000, 0x01120000, 0x00100024, 0x00100000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat22,0,0.010000},
  {owl_defendpat23,2,8, "D118",0,-1,3,2,3,3,0x2,648,
    { 0x00f0fcfc, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0f, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0x003cffff},
    { 0x00900400, 0x20104000, 0x40180000, 0x04102000, 0x40102000, 0x04900000, 0x20100400, 0x00184000}
   , 0x0,81.000000,attributes+0,1,NULL,autohelperowl_defendpat23,0,0.010000},
  {owl_defendpat24,3,8, "D119",-1,-2,2,2,3,4,0x2,647,
    { 0x3fffffff, 0xf0fcfcfc, 0xfffff000, 0xffff3f3f, 0xfcfcf0f0, 0xffff3f00, 0x3fffffff, 0xf0ffffff},
    { 0x25100000, 0x00180404, 0x00106000, 0x40900000, 0x04180000, 0x00102500, 0x00904040, 0x60100000}
   , 0x0,81.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat25,2,8, "D120",-1,-1,3,4,4,5,0x2,759,
    { 0x053fbfff, 0x80f0f4f4, 0xf8f04000, 0x7f3f0b00, 0xf4f08000, 0xbf3f0500, 0x0b3f7f7f, 0x40f0f8fc},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,82.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat26,1,8, "D121",-1,-4,2,1,3,5,0x2,758,
    { 0xffffffff, 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xffffff00, 0xffffffff, 0xfcfcfcfc},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,40.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat27,2,8, "D122",-2,-1,2,3,4,4,0x2,648,
    { 0xffffffff, 0xfcfcfcfc, 0xfffcfc00, 0xffffff0f, 0xfcfcfcc0, 0xffffff00, 0xffffffff, 0xfcfcffff},
    { 0x90900000, 0x28140000, 0x00181800, 0x0050a000, 0x00142800, 0x00909000, 0xa0500000, 0x18180000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat27,0,1.000000},
  {owl_defendpat28,4,8, "D123",-2,-1,1,3,3,4,0x2,648,
    { 0x203cfcfc, 0xc0f8f000, 0xfdf02000, 0x3fbf0f04, 0xf0f8c040, 0xfc3c2000, 0x0fbf3f00, 0x20f0fdfc},
    { 0x00100050, 0x00100000, 0x00100000, 0x00110100, 0x00100000, 0x00100000, 0x01110000, 0x00100014}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat29,5,8, "D124",-1,-2,2,1,3,3,0x2,721,
    { 0xfcfe7efe, 0x7cfcfca0, 0xf4fcfc00, 0xfffff700, 0xfcfc7c00, 0x7efefc00, 0xf7ffff2a, 0xfcfcf4fc},
    { 0x08502000, 0x10900800, 0x20148000, 0x80181000, 0x08901000, 0x20500800, 0x10188000, 0x80142000}
   , 0x0,81.000000,attributes+0,1,NULL,autohelperowl_defendpat29,0,1.600000},
  {owl_defendpat30,4,8, "D125",-2,-1,2,2,4,3,0x2,685,
    { 0xfffbffff, 0xfcfcecfc, 0xfebefc00, 0xefffff28, 0xecfcfca0, 0xfffbff00, 0xffffefff, 0xfcbefefc},
    { 0x00200084, 0x00200000, 0x00200000, 0x01200200, 0x00200000, 0x00200000, 0x02200100, 0x00200048}
   , 0x0,77.000000,attributes+0,1,NULL,autohelperowl_defendpat30,3,0.016000},
  {owl_defendpat31,6,8, "D126",-3,-2,2,3,5,5,0xa,758,
    { 0xffffffff, 0xfffffffe, 0xffffffff, 0xffffffff, 0xffffffff, 0xfffffffe, 0xffffffff, 0xffffffff},
    { 0x08100000, 0x02120800, 0x00108028, 0x80100000, 0x08120200, 0x001008a0, 0x00108000, 0x80100000}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat32,8,8, "D127",-2,-3,1,2,3,5,0x2,647,
    { 0xfcfcfcfc, 0xfefefe00, 0xfcffffaa, 0xfffffff0, 0xfefefe3e, 0xfcfcfca8, 0xffffff00, 0xfffffcfc},
    { 0x40200010, 0x04200000, 0x00200400, 0x00214000, 0x00200400, 0x00204000, 0x40210000, 0x04200010}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat33,2,8, "D200",-1,-1,2,3,3,4,0x2,759,
    { 0x3cffffff, 0xf0fcfcf0, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xffff3c00, 0x3fffff3f, 0xf0fcfcfc},
    { 0x28500000, 0x10180800, 0x0014a000, 0x80901000, 0x08181000, 0x00502800, 0x10908000, 0xa0140000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat34,2,8, "D201",-1,-1,2,3,3,4,0x2,759,
    { 0x3cffffff, 0xf0fcfcf0, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xffff3c00, 0x3fffff3f, 0xf0fcfcfc},
    { 0x28500000, 0x10180800, 0x0014a000, 0x80901000, 0x08181000, 0x00502800, 0x10908000, 0xa0140000}
   , 0x0,81.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat35,2,8, "D202",-1,-1,2,2,3,3,0x2,722,
    { 0x3fffffff, 0xf0fcfcfc, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xffff3f00, 0x3fffffff, 0xf0fcfcfc},
    { 0x20580000, 0x10182000, 0x00942000, 0x20901000, 0x20181000, 0x00582000, 0x10902000, 0x20940000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat36,1,8, "D203",0,-1,2,2,2,3,0x2,685,
    { 0x00ffffff, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3f, 0x00fcfcfc},
    { 0x00a04000, 0x60200000, 0x04280000, 0x00202400, 0x00206000, 0x40a00000, 0x24200000, 0x00280400}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat37,1,8, "D204",-1,-1,1,2,2,3,0x2,685,
    { 0x003cf43c, 0xc0f07000, 0x7cf00000, 0x373f0c00, 0x70f0c000, 0xf43c0000, 0x0c3f3700, 0x00f07cf0},
    { 0x00108000, 0x80100000, 0x08100000, 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x00100800}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat37,0,0.610000},
  {owl_defendpat38,2,8, "D205",-1,-1,2,1,3,2,0x2,722,
    { 0x303cfcfc, 0xc0fcf000, 0xfcf03000, 0x3fff0f00, 0xf0fcc000, 0xfc3c3000, 0x0fff3f00, 0x30f0fcfc},
    { 0x20184000, 0x40182000, 0x04902000, 0x20900400, 0x20184000, 0x40182000, 0x04902000, 0x20900400}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat39,2,8, "D206",-1,-1,1,3,2,4,0x2,721,
    { 0x37bc3f00, 0x20fcf4cc, 0xf0f87000, 0x7cfc2000, 0xf4fc2000, 0x3fbc3700, 0x20fc7ccc, 0x70f8f000},
    { 0x22100000, 0x00180008, 0x00102000, 0x00900000, 0x00180000, 0x00102200, 0x00900080, 0x20100000}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat40,3,8, "D207",0,-1,2,2,2,3,0x2,722,
    { 0x003fbdbf, 0x80f0f070, 0xf8f00000, 0x3f3f0a00, 0xf0f08000, 0xbd3f0000, 0x0a3f3f37, 0x00f0f8f8},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x0,66.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat41,2,8, "D208",-1,0,2,3,3,3,0x2,722,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat42,2,8, "D209",-1,0,1,2,2,2,0x2,721,
    { 0x0f3f3f00, 0x00f0fcfc, 0xf0f0c000, 0xfc3c0000, 0xfcf00000, 0x3f3f0f00, 0x003cfcfc, 0xc0f0f000},
    { 0x05200000, 0x00200404, 0x00204000, 0x40200000, 0x04200000, 0x00200500, 0x00204040, 0x40200000}
   , 0x20,70.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat43,2,8, "D209a",-1,0,1,2,2,2,0x2,722,
    { 0x0f3f3f00, 0x00f0fcfc, 0xf0f0c000, 0xfc3c0000, 0xfcf00000, 0x3f3f0f00, 0x003cfcfc, 0xc0f0f000},
    { 0x05200000, 0x00200404, 0x00204000, 0x40200000, 0x04200000, 0x00200500, 0x00204040, 0x40200000}
   , 0x20,35.000000,attributes+0,1,NULL,autohelperowl_defendpat43,3,1.000000},
  {owl_defendpat44,3,8, "D209b",0,-1,2,2,2,3,0x2,685,
    { 0x00f0fcfc, 0xf0f0c000, 0xfe3e0000, 0x0f3f3f2b, 0xc0f0f0a0, 0xfcf00000, 0x3f3f0f00, 0x003efeff},
    { 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x80100000, 0x08100000, 0x00100800, 0x00108000}
   , 0x20,70.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat45,3,8, "D210",0,-1,2,2,2,3,0x2,685,
    { 0x003cffff, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0f, 0x00f0fcfc},
    { 0x00148100, 0x80101040, 0x08500000, 0x10100800, 0x10108000, 0x81140000, 0x08101004, 0x00500800}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat46,3,8, "D211",-2,-1,2,1,4,2,0x8,647,
    { 0x7fffff00, 0xf4fcfcfc, 0xfffdf400, 0xfcfc7c1c, 0xfcfcf4d0, 0xffff7f00, 0x7cfcfcfc, 0xf4fdff00},
    { 0x25100000, 0x00180404, 0x00106000, 0x40900000, 0x04180000, 0x00102500, 0x00904040, 0x60100000}
   , 0x0,71.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat47,4,8, "D212",-1,-3,1,2,2,5,0x2,722,
    { 0xc0fcfe00, 0xfcf0f080, 0xffff0c00, 0x3c3cfc3c, 0xf0f0fcf0, 0xfefcc000, 0xfc3c3c08, 0x0cffff00},
    { 0x40186000, 0x44902000, 0x26900400, 0x20184408, 0x20904480, 0x60184000, 0x44182000, 0x04902600}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat48,1,8, "D213",-1,0,2,3,3,3,0x2,723,
    { 0x003f3fff, 0x00f0f0f0, 0xf0f00000, 0x3f3f0300, 0xf0f00000, 0x3f3f0000, 0x033f3f3f, 0x00f0f0fc},
    { 0x00100080, 0x00100000, 0x00100000, 0x00100200, 0x00100000, 0x00100000, 0x02100000, 0x00100008}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat48,0,3.000000},
  {owl_defendpat49,2,8, "D214",0,-1,2,1,2,2,0x2,685,
    { 0x00b4fcfc, 0xe0f0d000, 0xfc780000, 0x1f3f2f00, 0xd0f0e000, 0xfcb40000, 0x2f3f1f00, 0x0078fcfc},
    { 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x80100000, 0x08100000, 0x00100800, 0x00108000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat50,2,8, "D215",-2,-1,2,2,4,3,0x2,685,
    { 0xffffffff, 0xfcfcffff, 0xfcfcfcc0, 0xffffff00, 0xfffcfc00, 0xffffff0f, 0xffffffff, 0xfcfcfcfc},
    { 0x0a250000, 0x00201818, 0x00608000, 0x90200000, 0x18200000, 0x00250a00, 0x00209090, 0x80600000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat51,2,8, "D216",0,-1,2,2,2,3,0x2,648,
    { 0x00fcfcfc, 0xf0f0f000, 0xfffc0000, 0x3f3f3f0f, 0xf0f0f0c0, 0xfcfc0000, 0x3f3f3f00, 0x00fcffff},
    { 0x00100400, 0x00104000, 0x40100000, 0x04100000, 0x40100000, 0x04100000, 0x00100400, 0x00104000}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat52,2,8, "D217",-1,0,1,3,2,3,0x2,758,
    { 0x2f3f1700, 0x00787cfc, 0x50f0e000, 0xf4b40000, 0x7c780000, 0x173f2f00, 0x00b4f4fc, 0xe0f05000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat52,0,1.000000},
  {owl_defendpat53,1,8, "D217a",-1,0,1,3,2,3,0x2,758,
    { 0x0f3f3700, 0x00f07cfc, 0x70f0c000, 0xf43c0000, 0x7cf00000, 0x373f0f00, 0x003cf4fc, 0xc0f07000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat53,0,1.000000},
  {owl_defendpat54,3,8, "D217b",-1,0,1,3,2,3,0x2,758,
    { 0x3f3f3f00, 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc, 0xf0f0f000},
    { 0x12100000, 0x00140008, 0x00101000, 0x00500000, 0x00140000, 0x00101200, 0x00500080, 0x10100000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat55,3,8, "D217c",-1,0,1,3,2,3,0x2,758,
    { 0x3f3f3700, 0x00fc7cfc, 0x70f0f000, 0xf4fc0000, 0x7cfc0000, 0x373f3f00, 0x00fcf4fc, 0xf0f07000},
    { 0x12100000, 0x00140008, 0x00101000, 0x00500000, 0x00140000, 0x00101200, 0x00500080, 0x10100000}
   , 0x10,10.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat56,4,8, "D218",-1,-3,2,3,3,6,0x2,611,
    { 0xfffeffff, 0xfcfcfcec, 0xfffffd00, 0xffffff7f, 0xfcfcfcf4, 0xfffeff00, 0xffffffef, 0xfdffffff},
    { 0x02100100, 0x00100048, 0x00100000, 0x00100000, 0x00100000, 0x01100200, 0x00100084, 0x00100000}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat57,4,8, "D220",-1,-1,1,3,2,4,0x2,758,
    { 0x2bbfff00, 0xe0f8f8fc, 0xfcf8a000, 0xbcbc2c00, 0xf8f8e000, 0xffbf2b00, 0x2cbcbcfc, 0xa0f8fc00},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,40.000000,attributes+0,1,NULL,autohelperowl_defendpat57,0,0.010000},
  {owl_defendpat58,3,8, "D221",-1,0,1,3,2,3,0x2,758,
    { 0x283f3f00, 0x00f8f8f0, 0xf0f0a000, 0xbcbc0000, 0xf8f80000, 0x3f3f2800, 0x00bcbc3c, 0xa0f0f000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat59,4,8, "D221b",-1,0,1,3,2,3,0x2,758,
    { 0x283f3f00, 0x00f8f8f0, 0xf0f0a000, 0xbcbc0000, 0xf8f80000, 0x3f3f2800, 0x00bcbc3c, 0xa0f0f000},
    { 0x00101000, 0x00500000, 0x10100000, 0x00140000, 0x00500000, 0x10100000, 0x00140000, 0x00101000}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat60,2,8, "D222",-1,-1,2,2,3,3,0x2,722,
    { 0x007cfff7, 0xd0f0f0c0, 0xfcf40000, 0x3d3f1f00, 0xf0f0d000, 0xff7c0000, 0x1f3f3d0f, 0x00f4fc7c},
    { 0x00205000, 0x40600000, 0x14200000, 0x00240400, 0x00604000, 0x50200000, 0x04240000, 0x00201400}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat61,4,8, "D223",-1,-2,1,2,2,4,0x2,647,
    { 0xffffff00, 0xfcfcfcfc, 0xfefefc00, 0xfcfcfc28, 0xfcfcfca0, 0xffffff00, 0xfcfcfcfc, 0xfcfefe00},
    { 0xa1100000, 0x08180004, 0x00102800, 0x00908000, 0x00180800, 0x0010a100, 0x80900040, 0x28100000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat61,0,1.600000},
  {owl_defendpat62,3,8, "D224",-1,-1,1,2,2,3,0x2,685,
    { 0x283c7cfc, 0x40f8f800, 0xf4f0a000, 0xbfbf0700, 0xf8f84000, 0x7c3c2800, 0x07bfbf00, 0xa0f0f4fc},
    { 0x00100080, 0x00100000, 0x00100000, 0x00100200, 0x00100000, 0x00100000, 0x02100000, 0x00100008}
   , 0x0,30.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat63,4,8, "D225",-1,-1,2,3,3,4,0x2,648,
    { 0xc0fcfcfc, 0xfcf0f000, 0xffff0c00, 0x3f3fff3f, 0xf0f0fcf0, 0xfcfcc000, 0xff3f3f00, 0x0cffffff},
    { 0x80101820, 0x08508000, 0x90110800, 0x08168010, 0x80500810, 0x18108000, 0x80160800, 0x08119020}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat64,4,8, "D226",-1,0,2,2,3,2,0x2,722,
    { 0x003fbfef, 0x80f0f0f0, 0xf8f00000, 0x3f3e0b00, 0xf0f08000, 0xbf3f0000, 0x0b3e3f3f, 0x00f0f8ec},
    { 0x00240048, 0x00201000, 0x00600000, 0x12200100, 0x10200000, 0x00240000, 0x01201200, 0x00600084}
   , 0x2000,45.000000,attributes+0,1,NULL,autohelperowl_defendpat64,3,0.016000},
  {owl_defendpat65,4,8, "D227",-1,-1,2,2,3,3,0x2,648,
    { 0xfcfcfcf8, 0xfcfcfc00, 0xffffff00, 0xfeffffff, 0xfcfcfcfc, 0xfcfcfc00, 0xfffffe00, 0xffffffbf},
    { 0x48240400, 0x04205800, 0x40608400, 0x94204000, 0x58200400, 0x04244800, 0x40209400, 0x84604000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat65,3,0.610000},
  {owl_defendpat66,5,8, "D228",-1,-1,2,2,3,3,0x2,758,
    { 0xffffffbf, 0xfcfcfcfc, 0xfcfcfc00, 0xfffffe00, 0xfcfcfc00, 0xffffff00, 0xfeffffff, 0xfcfcfcf8},
    { 0x84684400, 0x58206400, 0x44a44800, 0x64209400, 0x64205800, 0x44688400, 0x94206400, 0x48a44400}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat66,3,0.610000},
  {owl_defendpat67,5,8, "D229",-1,-1,1,2,2,3,0x2,683,
    { 0xbcfcfc00, 0xfafeff00, 0xfcfcf8e8, 0xfcfcbc00, 0xfffefa00, 0xfcfcbcac, 0xbcfcfc00, 0xf8fcfc00},
    { 0x00609000, 0x90600000, 0x18240000, 0x00241800, 0x00609000, 0x90600000, 0x18240000, 0x00241800}
   , 0x0,76.000000,attributes+0,1,NULL,autohelperowl_defendpat67,3,0.010000},
  {owl_defendpat68,3,8, "D230",0,-2,2,4,2,6,0x2,574,
    { 0x00fcfefc, 0xf0f0f080, 0xffff0000, 0x3f3f3f3f, 0xf0f0f0f0, 0xfefc0000, 0x3f3f3f08, 0x00ffffff},
    { 0x00140000, 0x00101000, 0x00500000, 0x10100000, 0x10100000, 0x00140000, 0x00101000, 0x00500000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat68,0,10.000000},
  {owl_defendpat69,6,8, "D231",-2,-2,2,1,4,3,0x1,723,
    { 0x2a3efeff, 0xc0f8f8a8, 0xfcf0a000, 0xbfbf0f00, 0xf8f8c000, 0xfe3e2a00, 0x0fbfbfab, 0xa0f0fcfc},
    { 0x00100020, 0x00100000, 0x00100000, 0x00120000, 0x00100000, 0x00100000, 0x00120000, 0x00100020}
   , 0x2810,70.000000,attributes+0,1,NULL,autohelperowl_defendpat69,0,1.141360},
  {owl_defendpat70,4,8, "D232",-1,-1,1,3,2,4,0x2,795,
    { 0x0cffff00, 0xf0f0fcf0, 0xfcfcc000, 0xfc3c3c00, 0xfcf0f000, 0xffff0c00, 0x3c3cfc3c, 0xc0fcfc00},
    { 0x04910400, 0x20104410, 0x40184000, 0x44102000, 0x44102000, 0x04910400, 0x20104410, 0x40184000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_defendpat70,0,0.376000},
  {owl_defendpat71,9,8, "D233",0,-3,2,1,2,4,0x2,685,
    { 0x00b0fcbc, 0xe0f0c000, 0xfe3a0000, 0x0f3f2e2a, 0xc0f0e0a0, 0xfcb00000, 0x2e3f0f00, 0x003afefa},
    { 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x80100000, 0x08100000, 0x00100800, 0x00108000}
   , 0x20,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat72,2,8, "D234",-1,-3,1,1,2,4,0x2,685,
    { 0x087cfcfc, 0xd0f0f800, 0xfcf48000, 0xbf3f1f00, 0xf8f0d000, 0xfc7c0800, 0x1f3fbf00, 0x80f4fcfc},
    { 0x00240000, 0x00201000, 0x00600000, 0x10200000, 0x10200000, 0x00240000, 0x00201000, 0x00600000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat72,3,16.000000},
  {owl_defendpat73,1,8, "D300",-1,0,1,4,2,4,0x0,685,
    { 0x007cfcfc, 0xd0f0f000, 0xfcf40000, 0x3f3f1f00, 0xf0f0d000, 0xfc7c0000, 0x1f3f3f00, 0x00f4fcfc},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x2000,80.000000,attributes+0,1,NULL,autohelperowl_defendpat73,0,0.010000},
  {owl_defendpat74,2,8, "D301",-1,0,1,3,2,3,0x0,686,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00940000, 0x20101000, 0x00580000, 0x10102000, 0x10102000, 0x00940000, 0x20101000, 0x00580000}
   , 0x2000,80.000000,attributes+0,1,NULL,autohelperowl_defendpat74,0,0.010000},
  {owl_defendpat75,1,8, "D302",0,-1,2,2,2,3,0x0,685,
    { 0x00fcfcf0, 0xf0f0f000, 0xfffc0000, 0x3c3f3f0c, 0xf0f0f0c0, 0xfcfc0000, 0x3f3f3c00, 0x00fcff3c},
    { 0x00280400, 0x00206000, 0x40a00000, 0x24200000, 0x60200000, 0x04280000, 0x00202400, 0x00a04000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat76,2,8, "D303",-1,-1,2,2,3,3,0x0,722,
    { 0xf0fcff3c, 0xfcfcf0c0, 0xfcfc3c00, 0x3ffffc00, 0xf0fcfc00, 0xfffcf000, 0xfcff3f0c, 0x3cfcfcf0},
    { 0x90902000, 0x28940000, 0x20181800, 0x0058a000, 0x00942800, 0x20909000, 0xa0580000, 0x18182000}
   , 0x800,70.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat77,2,8, "D304",-1,0,1,2,2,2,0x0,721,
    { 0x00fcfc0c, 0xf0f0f000, 0xfcfc0000, 0x3f3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3f00, 0x00fcfcc0},
    { 0x00604000, 0x50200000, 0x04240000, 0x00201400, 0x00205000, 0x40600000, 0x14200000, 0x00240400}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat77,3,1.000000},
  {owl_defendpat78,1,8, "D305",-1,-2,2,1,3,3,0x0,685,
    { 0x30ffffff, 0xf0fcf0f0, 0xfcfc3000, 0x3fff3f00, 0xf0fcf000, 0xffff3000, 0x3fff3f3f, 0x30fcfcfc},
    { 0x00200100, 0x00200040, 0x00200000, 0x00200000, 0x00200000, 0x01200000, 0x00200004, 0x00200000}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat79,2,8, "D306",-1,0,2,3,3,3,0x0,722,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat79,3,4.800000},
  {owl_defendpat80,2,8, "D307",-1,-2,1,2,2,4,0x0,721,
    { 0x30ffff00, 0xf0fcf0f0, 0xfcff3000, 0x3cfc3c30, 0xf0fcf030, 0xffff3000, 0x3cfc3c3c, 0x30fffc00},
    { 0x00209100, 0x80600040, 0x18200000, 0x00240800, 0x00608000, 0x91200000, 0x08240004, 0x00201800}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat80,3,1.000000},
  {owl_defendpat81,2,8, "D308",0,-2,1,0,1,2,0x0,722,
    { 0x003c3c2c, 0x00f0f000, 0xf0f00000, 0x3f3e0000, 0xf0f00000, 0x3c3c0000, 0x003e3f00, 0x00f0f0e0},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x830,77.000000,attributes+0,1,NULL,autohelperowl_defendpat81,0,1.960000},
  {owl_defendpat82,4,8, "D309",-1,0,1,2,2,2,0x0,685,
    { 0x0038f838, 0xc0f0a000, 0xbcb00000, 0x2a3f0c00, 0xa0f0c000, 0xf8380000, 0x0c3f2a00, 0x00b0bcb0},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat82,3,1.600000},
  {owl_defendpat83,4,8, "D309a",-1,0,1,2,2,2,0x0,685,
    { 0x0038f838, 0xc0f0a000, 0xbcb00000, 0x2a3f0c00, 0xa0f0c000, 0xf8380000, 0x0c3f2a00, 0x00b0bcb0},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x800,60.000000,attributes+0,1,NULL,autohelperowl_defendpat83,3,1.006000},
  {owl_defendpat84,1,8, "D309b",-1,0,2,2,3,2,0x0,722,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x0,61.000000,attributes+0,1,NULL,autohelperowl_defendpat84,3,1.600000},
  {owl_defendpat85,5,8, "D310a",-2,-1,1,1,3,2,0x0,646,
    { 0xfcfca000, 0xbcbe3c00, 0x28fcfc20, 0xf0f8f800, 0x3cbebc00, 0xa0fcfc20, 0xf8f8f000, 0xfcfc2800},
    { 0x04180000, 0x00102400, 0x00904000, 0x60100000, 0x24100000, 0x00180400, 0x00106000, 0x40900000}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_defendpat85,0,0.970000},
  {owl_defendpat86,5,8, "D310b",-2,-1,1,1,3,2,0x0,646,
    { 0xfcfca000, 0xbcbe3c00, 0x28fcfc20, 0xf0f8f800, 0x3cbebc00, 0xa0fcfc20, 0xf8f8f000, 0xfcfc2800},
    { 0x04180000, 0x00102400, 0x00904000, 0x60100000, 0x24100000, 0x00180400, 0x00106000, 0x40900000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat86,0,0.592000},
  {owl_defendpat87,2,8, "D311",0,-1,2,1,2,2,0x0,685,
    { 0x00f0fcc0, 0xf0f0c000, 0xfc3c0000, 0x0c3c3f00, 0xc0f0f000, 0xfcf00000, 0x3f3c0c00, 0x003cfc0c},
    { 0x00600400, 0x10204000, 0x40240000, 0x04201000, 0x40201000, 0x04600000, 0x10200400, 0x00244000}
   , 0x20,60.000000,attributes+0,1,NULL,autohelperowl_defendpat87,3,1.000000},
  {owl_defendpat88,1,8, "D313",-1,-2,2,0,3,2,0x0,685,
    { 0x00fffffc, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3c, 0x00fcfcfc},
    { 0x00920200, 0x201000a0, 0x00180000, 0x00102000, 0x00102000, 0x02920000, 0x20100028, 0x00180000}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat89,3,8, "D314",-1,-2,2,2,3,4,0x0,722,
    { 0xf0ffffff, 0xfcfcf0f0, 0xffff3f00, 0x3fffffff, 0xf0fcfcfc, 0xfffff000, 0xffff3f3f, 0x3fffffff},
    { 0x80681000, 0x18602000, 0x10a50a00, 0x20249090, 0x20601818, 0x10688000, 0x90242000, 0x0aa51000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat90,6,8, "D315",-1,0,1,2,2,2,0x0,722,
    { 0x00fcfca8, 0xf0f0f000, 0xfcfc0000, 0x3e3e3e00, 0xf0f0f000, 0xfcfc0000, 0x3e3e3e00, 0x00fcfca8},
    { 0x00584000, 0x50102000, 0x04940000, 0x20101400, 0x20105000, 0x40580000, 0x14102000, 0x00940400}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat90,0,1.000000},
  {owl_defendpat91,2,8, "D316",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00108010, 0x80100000, 0x08100000, 0x00110800, 0x00108000, 0x80100000, 0x08110000, 0x00100810}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat91,0,1.000000},
  {owl_defendpat92,2,8, "D317",-1,0,1,2,2,2,0x0,685,
    { 0x00fcfc0c, 0xf0f0f000, 0xfcfc0000, 0x3f3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3f00, 0x00fcfcc0},
    { 0x00604000, 0x50200000, 0x04240000, 0x00201400, 0x00205000, 0x40600000, 0x14200000, 0x00240400}
   , 0x0,95.000000,attributes+0,1,NULL,autohelperowl_defendpat92,3,1.600000},
  {owl_defendpat93,5,8, "D318",-1,-1,1,2,2,3,0x0,722,
    { 0xf8fcfc7c, 0xfcfcf800, 0xfcfcbc00, 0xbffffd00, 0xf8fcfc00, 0xfcfcf800, 0xfdffbf00, 0xbcfcfcf4},
    { 0x50609020, 0x94640000, 0x18241400, 0x00665800, 0x00649400, 0x90605000, 0x58660000, 0x14241820}
   , 0x0,82.000000,attributes+0,1,NULL,autohelperowl_defendpat93,3,1.000000},
  {owl_defendpat94,3,8, "D319",-1,-2,1,1,2,3,0x0,721,
    { 0xffffbf00, 0xbcfcfcfc, 0xf8fcfc00, 0xfcfcf800, 0xfcfcbc00, 0xbfffff00, 0xf8fcfcfc, 0xfcfcf800},
    { 0x80601200, 0x18600080, 0x10240800, 0x00249000, 0x00601800, 0x12608000, 0x90240008, 0x08241000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat94,3,0.010000},
  {owl_defendpat95,4,8, "D320",-2,-1,1,2,3,3,0x0,686,
    { 0xf8fcfcfc, 0xfcfcf800, 0xfcfebc00, 0xbfffff20, 0xf8fcfc20, 0xfcfcf800, 0xffffbf00, 0xbcfefcfc},
    { 0x40180000, 0x04102000, 0x00900400, 0x20104000, 0x20100400, 0x00184000, 0x40102000, 0x04900000}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat96,1,8, "D400",-1,0,1,1,2,1,0x5,685,
    { 0x00fc7c00, 0x70f0f000, 0xf4fc0000, 0x3c3c3400, 0xf0f07000, 0x7cfc0000, 0x343c3c00, 0x00fcf400},
    { 0x00900000, 0x20100000, 0x00180000, 0x00102000, 0x00102000, 0x00900000, 0x20100000, 0x00180000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat96,0,1.000000},
  {owl_defendpat97,1,8, "D401",-1,0,1,1,2,1,0x5,648,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00900000, 0x20100000, 0x00180000, 0x00102000, 0x00102000, 0x00900000, 0x20100000, 0x00180000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat97,0,0.010000},
  {owl_defendpat98,1,8, "D402",0,-2,3,2,3,4,0x6,719,
    { 0x3f3f3f3f, 0x00ffffff, 0xf0f0f0f0, 0xffff0000, 0xffff0000, 0x3f3f3f3f, 0x00ffffff, 0xf0f0f0f0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat99,2,8, "D403",-2,-1,1,2,3,3,0xa,721,
    { 0xfffffdf0, 0xfcfcfc7c, 0xfcfcfc00, 0xfcffff00, 0xfcfcfc00, 0xfdffff00, 0xfffffcf4, 0xfcfcfc3c},
    { 0x00200410, 0x00204000, 0x40200000, 0x04210000, 0x40200000, 0x04200000, 0x00210400, 0x00204010}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat100,2,8, "D404",-1,0,3,3,4,3,0x6,722,
    { 0x003fffef, 0xc0f0f0f0, 0xfcf00000, 0x3f3e0f00, 0xf0f0c000, 0xff3f0000, 0x0f3e3f3f, 0x00f0fcec},
    { 0x00200040, 0x00200000, 0x00200000, 0x00200100, 0x00200000, 0x00200000, 0x01200000, 0x00200004}
   , 0x0,90.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat101,3,8, "D405",0,-1,4,2,4,3,0x6,686,
    { 0x00b0bcfc, 0xa0f0c000, 0xfb3b0000, 0x0f3f2b3f, 0xc0f0a0f0, 0xbcb00000, 0x2b3f0f00, 0x003bfbff},
    { 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x80100000, 0x08100000, 0x00100800, 0x00108000}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_defendpat101,0,0.610000},
  {owl_defendpat102,4,8, "D406",0,-2,3,2,3,4,0xa,723,
    { 0x00bcfcfd, 0xe0f0f000, 0xfffa0000, 0x3f3f2f2f, 0xf0f0e0e0, 0xfcbc0000, 0x2f3f3f01, 0x00faffff},
    { 0x00140000, 0x00101000, 0x00500000, 0x10100000, 0x10100000, 0x00140000, 0x00101000, 0x00500000}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat103,3,8, "D407",-1,-2,2,2,3,4,0xa,647,
    { 0xf0fcffff, 0xfcfcf0c0, 0xffff3f00, 0x3fffffff, 0xf0fcfcfc, 0xfffcf000, 0xffff3f0f, 0x3fffffff},
    { 0x20180500, 0x00186040, 0x40902000, 0x24900000, 0x60180000, 0x05182000, 0x00902404, 0x20904000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat104,4,8, "D408",-1,-1,1,2,2,3,0xa,721,
    { 0xacffff00, 0xf8f8fcf0, 0xfcfce800, 0xfcbcbc00, 0xfcf8f800, 0xffffac00, 0xbcbcfc3c, 0xe8fcfc00},
    { 0x04120000, 0x00100420, 0x00104000, 0x40100000, 0x04100000, 0x00120400, 0x00104020, 0x40100000}
   , 0x0,30.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat105,2,8, "D409",0,-1,3,3,3,4,0x6,722,
    { 0x00bfffff, 0xe0f0f0f0, 0xfcf80000, 0x3f3f2f00, 0xf0f0e000, 0xffbf0000, 0x2f3f3f3f, 0x00f8fcfc},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat106,3,8, "D500",-1,-1,1,2,2,3,0x2,685,
    { 0x7fffff00, 0xf4fcfcfc, 0xfcfcf400, 0xfcfc7c00, 0xfcfcf400, 0xffff7f00, 0x7cfcfcfc, 0xf4fcfc00},
    { 0x25900000, 0x20180404, 0x00186000, 0x40902000, 0x04182000, 0x00902500, 0x20904040, 0x60180000}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat107,3,8, "D502",-1,-1,1,2,2,3,0x2,685,
    { 0x3fffff00, 0xf0fcfcfc, 0xfcfcf000, 0xfcfc3c00, 0xfcfcf000, 0xffff3f00, 0x3cfcfcfc, 0xf0fcfc00},
    { 0x21910000, 0x20180014, 0x00182000, 0x00902000, 0x00182000, 0x00912100, 0x20900050, 0x20180000}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat108,3,8, "D503",-1,-2,1,0,2,2,0x8,686,
    { 0x00fcfcf0, 0xf0f0f000, 0xfcfc0000, 0x3c3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3c00, 0x00fcfc3c},
    { 0x00580400, 0x10106000, 0x40940000, 0x24101000, 0x60101000, 0x04580000, 0x10102400, 0x00944000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat108,0,3.160000},
  {owl_defendpat109,2,8, "D504",-1,-2,0,1,1,3,0x0,720,
    { 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000},
    { 0x00102400, 0x00904000, 0x60100000, 0x04180000, 0x40900000, 0x24100000, 0x00180400, 0x00106000}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_defendpat109,0,0.959200},
  {owl_defendpat110,3,8, "D505",0,-1,2,1,2,2,0x2,686,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00580400, 0x10106000, 0x40940000, 0x24101000, 0x60101000, 0x04580000, 0x10102400, 0x00944000}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_defendpat110,0,1.186000},
  {owl_defendpat111,2,8, "D506",0,-1,2,1,2,2,0x2,686,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00180400, 0x00106000, 0x40900000, 0x24100000, 0x60100000, 0x04180000, 0x00102400, 0x00904000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat111,0,1.315600},
  {owl_defendpat112,3,8, "D507",-1,-2,1,2,2,4,0x2,647,
    { 0xfcfffc00, 0xfcfcfc30, 0xfffffe00, 0xfcfcfcbc, 0xfcfcfcf8, 0xfcfffc00, 0xfcfcfc30, 0xfeffff00},
    { 0x28160000, 0x00181820, 0x0050a000, 0x90900000, 0x18180000, 0x00162800, 0x00909020, 0xa0500000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat112,0,1.000000},
  {owl_defendpat113,4,8, "D508",-1,-2,1,2,2,4,0x2,646,
    { 0xfcfffc00, 0xfcfcfc30, 0xfffffe00, 0xfcfcfcbc, 0xfcfcfcf8, 0xfcfffc00, 0xfcfcfc30, 0xfeffff00},
    { 0x28160000, 0x00181820, 0x0051a000, 0x90900010, 0x18180010, 0x00162800, 0x00909020, 0xa0510000}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_defendpat113,0,1.000000},
  {owl_defendpat114,2,8, "D509",0,-1,1,1,1,2,0x2,722,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00186000, 0x40902000, 0x24900000, 0x20180400, 0x20904000, 0x60180000, 0x04182000, 0x00902400}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_defendpat114,0,1.000000},
  {owl_defendpat115,3,8, "D510",-1,-1,1,1,2,2,0x0,683,
    { 0x30fcf000, 0xf0fc3000, 0x3cfc3000, 0x30fc3c00, 0x30fcf000, 0xf0fc3000, 0x3cfc3000, 0x30fc3c00},
    { 0x00649000, 0x90601000, 0x18640000, 0x10241800, 0x10609000, 0x90640000, 0x18241000, 0x00641800}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat115,3,1.000000},
  {owl_defendpat116,5,8, "D511",-1,-1,2,1,3,2,0x0,648,
    { 0xbcfcfcf4, 0xf8fcfc00, 0xfcfcf800, 0xfdffbf00, 0xfcfcf800, 0xfcfcbc00, 0xbffffd00, 0xf8fcfc7c},
    { 0x04241860, 0x00609400, 0x90604000, 0x58260100, 0x94600000, 0x18240400, 0x01265800, 0x40609024}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat116,3,1.000000},
  {owl_defendpat117,2,8, "D512",-2,-2,2,2,4,4,0x2,682,
    { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    { 0x24900000, 0x20180400, 0x00186200, 0x40902080, 0x04182008, 0x00902400, 0x20904000, 0x62180000}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat118,6,8, "D513",-2,-1,2,3,4,4,0x2,721,
    { 0xffffffff, 0xfcfcffff, 0xfcfcfcc0, 0xffffff00, 0xfffcfc00, 0xffffff0f, 0xffffffff, 0xfcfcfcfc},
    { 0xa4900000, 0x28180400, 0x00186800, 0x4090a000, 0x04182800, 0x0090a400, 0xa0904000, 0x68180000}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat119,4,8, "D514",-1,-1,1,2,2,3,0x0,647,
    { 0x30fcfcbc, 0xf0fcf000, 0xfcfc3000, 0x3fff3e00, 0xf0fcf000, 0xfcfc3000, 0x3eff3f00, 0x30fcfcf8},
    { 0x20180404, 0x00186000, 0x40902000, 0x25900000, 0x60180000, 0x04182000, 0x00902500, 0x20904040}
   , 0x0,76.000000,attributes+0,1,NULL,autohelperowl_defendpat119,0,0.019600},
  {owl_defendpat120,4,8, "D515",0,-2,2,2,2,4,0x2,649,
    { 0x00fcffff, 0xf0f0f0c0, 0xfffc0000, 0x3f3f3f0f, 0xf0f0f0c0, 0xfffc0000, 0x3f3f3f0f, 0x00fcffff},
    { 0x00580600, 0x10106080, 0x41940000, 0x24101004, 0x60101040, 0x06580000, 0x10102408, 0x00944100}
   , 0x0,61.000000,attributes+0,1,NULL,autohelperowl_defendpat120,0,1.000000},
  {owl_defendpat121,5,8, "D600",-1,-2,1,1,2,3,0x2,720,
    { 0xfef73e00, 0x3cfcdcb8, 0xf07cfc00, 0xdcfcf000, 0xdcfc3c00, 0x3ef7fe00, 0xf0fcdcb8, 0xfc7cf000},
    { 0x00912400, 0x20904010, 0x60180000, 0x04182000, 0x40902000, 0x24910000, 0x20180410, 0x00186000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat122,5,8, "D600a",-1,-2,1,2,2,4,0x2,683,
    { 0xfef73e00, 0x3cfcdcb8, 0xf07cff00, 0xdcfcf0c0, 0xdcfc3c0c, 0x3ef7fe00, 0xf0fcdcb8, 0xff7cf000},
    { 0x00912400, 0x20904010, 0x60180200, 0x04182080, 0x40902008, 0x24910000, 0x20180410, 0x02186000}
   , 0x0,81.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat123,4,8, "D602",-1,0,1,2,2,2,0x2,648,
    { 0x00f0fcfc, 0xf0f0c000, 0xfc3c0000, 0x0f3f3f00, 0xc0f0f000, 0xfcf00000, 0x3f3f0f00, 0x003cfcfc},
    { 0x00100414, 0x00104000, 0x40100000, 0x05110000, 0x40100000, 0x04100000, 0x00110500, 0x00104050}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat123,0,1.600000},
  {owl_defendpat124,3,8, "D603",-1,0,1,2,2,2,0x2,648,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00180410, 0x00106000, 0x40900000, 0x24110000, 0x60100000, 0x04180000, 0x00112400, 0x00904010}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat124,0,1.960000},
  {owl_defendpat125,3,8, "D604",0,-1,1,2,1,3,0x2,722,
    { 0x00bf3d00, 0x20f0f070, 0xf0f80000, 0x3c3c2000, 0xf0f02000, 0x3dbf0000, 0x203c3c34, 0x00f8f000},
    { 0x00160000, 0x00101020, 0x00500000, 0x10100000, 0x10100000, 0x00160000, 0x00101020, 0x00500000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat125,0,0.970000},
  {owl_defendpat126,5,8, "D604a",0,-2,1,3,1,5,0x2,759,
    { 0x00ffff00, 0xf0f0f0f0, 0xffff0000, 0x3c3c3c3c, 0xf0f0f0f0, 0xffff0000, 0x3c3c3c3c, 0x00ffff00},
    { 0x00558000, 0x90101010, 0x0a550000, 0x10101818, 0x10109090, 0x80550000, 0x18101010, 0x00550a00}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat126,0,1.000000},
  {owl_defendpat127,6,8, "D605",0,-1,2,2,2,3,0x2,648,
    { 0x00b8fcfc, 0xe0f0e000, 0xffb80000, 0x2f3f2f0f, 0xe0f0e0c0, 0xfcb80000, 0x2f3f2f00, 0x00b8ffff},
    { 0x00100418, 0x00104000, 0x41100000, 0x06110004, 0x40100040, 0x04100000, 0x00110600, 0x00104190}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat128,3,8, "D606",-1,0,1,2,2,2,0x2,648,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00180418, 0x00106000, 0x40900000, 0x26110000, 0x60100000, 0x04180000, 0x00112600, 0x00904090}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat128,0,0.019600},
  {owl_defendpat129,2,8, "D607",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00648800, 0x90209000, 0x88640000, 0x18201800, 0x90209000, 0x88640000, 0x18201800, 0x00648800}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat129,3,0.019600},
  {owl_defendpat130,3,8, "D608",0,-1,1,2,1,3,0x2,722,
    { 0x00bfff00, 0xe0f0f0f0, 0xfcf80000, 0x3c3c2c00, 0xf0f0e000, 0xffbf0000, 0x2c3c3c3c, 0x00f8fc00},
    { 0x00162000, 0x00901020, 0x20500000, 0x10180000, 0x10900000, 0x20160000, 0x00181020, 0x00502000}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat130,0,1.000000},
  {owl_defendpat131,3,8, "D608b",0,-2,1,2,1,4,0x2,721,
    { 0x2c3c3c3c, 0x00faff00, 0xf0f0e0e0, 0xffbf0000, 0xfffa0000, 0x3c3c2c2c, 0x00bfff00, 0xe0f0f0f0},
    { 0x08100020, 0x00100800, 0x00108000, 0x80120000, 0x08100000, 0x00100800, 0x00128000, 0x80100020}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat131,0,0.610000},
  {owl_defendpat132,2,8, "D609",-1,0,1,2,2,2,0x2,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00108010, 0x80100000, 0x08100000, 0x00110800, 0x00108000, 0x80100000, 0x08110000, 0x00100810}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat133,7,8, "D610",-1,-2,1,2,2,4,0x2,611,
    { 0x2fffff00, 0xf0f8fcfc, 0xfffee000, 0xfcbc3c2c, 0xfcf8f0e0, 0xffff2f00, 0x3cbcfcfc, 0xe0feff00},
    { 0x0651a400, 0x90904418, 0x68144000, 0x44181800, 0x44909000, 0xa4510600, 0x18184490, 0x40146800}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_defendpat133,0,0.050000},
  {owl_defendpat134,5,8, "D611",-1,-1,1,2,2,3,0x2,722,
    { 0x7effff00, 0xf4fcfcf8, 0xfcfcf400, 0xfcfc7c00, 0xfcfcf400, 0xffff7e00, 0x7cfcfcbc, 0xf4fcfc00},
    { 0x24911200, 0x20580490, 0x10186000, 0x40942000, 0x04582000, 0x12912400, 0x20944018, 0x60181000}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat134,0,0.010000},
  {owl_defendpat135,7,8, "D612",-1,-2,1,2,2,4,0x2,685,
    { 0xfcffff00, 0xfcfcfcf0, 0xfffffc00, 0xfcfcfc3c, 0xfcfcfcf0, 0xfffffc00, 0xfcfcfc3c, 0xfcffff00},
    { 0x54210100, 0x04240450, 0x01215400, 0x40604014, 0x04240450, 0x01215400, 0x40604014, 0x54210100}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat136,7,8, "D613",0,-2,2,2,2,4,0x2,721,
    { 0x3f3f3f0f, 0x00fcffff, 0xf0f0f0c0, 0xfffc0000, 0xfffc0000, 0x3f3f3f0f, 0x00fcffff, 0xf0f0f0c0},
    { 0x10121005, 0x00540121, 0x10101040, 0x01540000, 0x01540000, 0x10121005, 0x00540121, 0x10101040}
   , 0x0,50.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat137,5,8, "D614",0,-1,2,1,2,2,0x2,648,
    { 0x00b8fcfc, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0x00b8fcfc},
    { 0x00100498, 0x00104000, 0x40100000, 0x06110200, 0x40100000, 0x04100000, 0x02110600, 0x00104098}
   , 0x0,30.000000,attributes+0,1,NULL,autohelperowl_defendpat137,0,1.000000},
  {owl_defendpat138,8,8, "D614b",0,-2,2,2,2,4,0x2,649,
    { 0x00beffff, 0xe0f0f0e0, 0xfefa0000, 0x3f3f2f2b, 0xf0f0e0a0, 0xffbe0000, 0x2f3f3f2f, 0x00fafeff},
    { 0x00140126, 0x00101040, 0x00500000, 0x11120000, 0x10100000, 0x01140000, 0x00121106, 0x00500060}
   , 0x0,31.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat139,5,8, "D615",-1,-2,1,1,2,3,0x2,721,
    { 0x0cbcfcfc, 0xe0f0fc00, 0xfcf8c000, 0xff3f2f00, 0xfcf0e000, 0xfcbc0c00, 0x2f3fff00, 0xc0f8fcfc},
    { 0x00104094, 0x40100000, 0x04100000, 0x01110600, 0x00104000, 0x40100000, 0x06110100, 0x00100458}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat139,0,0.610000},
  {owl_defendpat140,6,8, "D616",-1,-2,1,2,2,4,0x2,757,
    { 0xbfff3e00, 0x38fcfcbc, 0xf0fcfb00, 0xfcfcb0c0, 0xfcfc380c, 0x3effbf00, 0xb0fcfcf8, 0xfbfcf000},
    { 0x04912400, 0x20904410, 0x60184200, 0x44182080, 0x44902008, 0x24910400, 0x20184410, 0x42186000}
   , 0x0,25.000000,attributes+0,1,NULL,autohelperowl_defendpat140,0,0.050000},
  {owl_defendpat141,6,8, "D616a",-1,-2,1,4,2,6,0x2,685,
    { 0x2fffff00, 0xf0f8fcfc, 0xfffce000, 0xfcbc3c0c, 0xfcf8f0c0, 0xffff2f00, 0x3cbcfcfc, 0xe0fcff00},
    { 0x06118400, 0x80104418, 0x48104000, 0x44100800, 0x44108000, 0x84110600, 0x08104490, 0x40104800}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_defendpat141,0,0.050000},
  {owl_defendpat142,7,8, "D617",-1,-3,1,2,2,5,0x2,795,
    { 0xbfff3e00, 0x38fcfcbc, 0xf0fcfb00, 0xfcfcb0c0, 0xfcfc380c, 0x3effbf00, 0xb0fcfcf8, 0xfbfcf000},
    { 0x06912400, 0x20904418, 0x60184200, 0x44182080, 0x44902008, 0x24910600, 0x20184490, 0x42186000}
   , 0x0,25.000000,attributes+0,1,NULL,autohelperowl_defendpat142,0,0.010000},
  {owl_defendpat143,5,8, "D618",-1,-2,1,2,2,4,0x2,646,
    { 0xffff3e00, 0x3cfcfcbc, 0xf0fcff00, 0xfcfcf0c0, 0xfcfc3c0c, 0x3effff00, 0xf0fcfcf8, 0xfffcf000},
    { 0x26912400, 0x20984418, 0x60186200, 0x44982080, 0x44982008, 0x24912600, 0x20984490, 0x62186000}
   , 0x0,25.000000,attributes+0,1,NULL,autohelperowl_defendpat143,0,0.010000},
  {owl_defendpat144,4,8, "D619",-1,-1,1,1,2,2,0x2,647,
    { 0xfcfcf800, 0xfcfcbc00, 0xbcfcfc00, 0xf8fcfc00, 0xbcfcfc00, 0xf8fcfc00, 0xfcfcf800, 0xfcfcbc00},
    { 0x90249000, 0x88641000, 0x18601800, 0x10648800, 0x10648800, 0x90249000, 0x88641000, 0x18601800}
   , 0x0,39.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat145,6,8, "D620",-1,-2,1,1,2,3,0x2,647,
    { 0x2fffff00, 0xf0f8fcfc, 0xfcfce000, 0xfcbc3c00, 0xfcf8f000, 0xffff2f00, 0x3cbcfcfc, 0xe0fcfc00},
    { 0x06118500, 0x80104458, 0x48104000, 0x44100800, 0x44108000, 0x85110600, 0x08104494, 0x40104800}
   , 0x0,72.000000,attributes+0,1,NULL,autohelperowl_defendpat145,0,0.016000},
  {owl_defendpat146,6,8, "D621",-2,-1,1,2,3,3,0x2,721,
    { 0xfcbffc00, 0xecfffc30, 0xfcf8fc30, 0xfcfcec00, 0xfcffec00, 0xfcbffc30, 0xecfcfc30, 0xfcf8fc00},
    { 0x44124000, 0x44110420, 0x04104410, 0x40104400, 0x04114400, 0x40124410, 0x44104020, 0x44100400}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat147,4,8, "D622",-1,-1,1,2,2,3,0x2,646,
    { 0xfcfeff00, 0xfcfcfce0, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfffefc00, 0xfcfcfc2c, 0xfcfcfc00},
    { 0x18640000, 0x10241800, 0x00649000, 0x90601000, 0x18241000, 0x00641800, 0x10609000, 0x90640000}
   , 0x20,45.000000,attributes+0,1,NULL,autohelperowl_defendpat147,3,1.600000},
  {owl_defendpat148,4,8, "D623",-1,-2,1,3,2,5,0x2,758,
    { 0xdfffdf00, 0xfc74fcfc, 0xdffcdc00, 0xfc74fc0c, 0xfc74fcc0, 0xdfffdf00, 0xfc74fcfc, 0xdcfcdf00},
    { 0x85900400, 0x28104404, 0x40184800, 0x4410a000, 0x44102800, 0x04908500, 0xa0104440, 0x48184000}
   , 0x10,95.000000,attributes+0,1,NULL,autohelperowl_defendpat148,0,0.016000},
  {owl_defendpat149,4,8, "D624",-1,-2,1,1,2,3,0x2,685,
    { 0x0fff3600, 0x30f07cbc, 0x70fcc000, 0xf43c3000, 0x7cf03000, 0x36ff0f00, 0x303cf4f8, 0xc0fc7000},
    { 0x01910000, 0x20100014, 0x00180000, 0x00102000, 0x00102000, 0x00910100, 0x20100050, 0x00180000}
   , 0x0,40.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat150,3,8, "D625",-1,-1,0,1,1,2,0x2,683,
    { 0xbcfc0000, 0x383c3c00, 0x00fcf800, 0xf0f0b000, 0x3c3c3800, 0x00fcbc00, 0xb0f0f000, 0xf8fc0000},
    { 0x04180000, 0x00102400, 0x00904000, 0x60100000, 0x24100000, 0x00180400, 0x00106000, 0x40900000}
   , 0x20,45.000000,attributes+0,1,NULL,autohelperowl_defendpat150,0,0.016000},
  {owl_defendpat151,2,8, "D626",0,-1,1,2,1,3,0x6,648,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00580200, 0x10102080, 0x00940000, 0x20101000, 0x20101000, 0x02580000, 0x10102008, 0x00940000}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat152,4,8, "D627",-1,0,2,2,3,2,0x8,723,
    { 0x3f3f3f3f, 0x00fcfcfc, 0xf0f0f000, 0xffff0000, 0xfcfc0000, 0x3f3f3f00, 0x00ffffff, 0xf0f0f0f0},
    { 0x06110120, 0x00100458, 0x00104000, 0x40120000, 0x04100000, 0x01110600, 0x00124094, 0x40100020}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_defendpat152,0,1.600000},
  {owl_defendpat153,3,8, "D628",0,0,2,1,2,1,0x8,722,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00140010, 0x00101000, 0x00500000, 0x10110000, 0x10100000, 0x00140000, 0x00111000, 0x00500010}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat153,0,1.600000},
  {owl_defendpat154,5,8, "D629",-1,-1,4,1,5,2,0x8,722,
    { 0x34fcfcfc, 0xf0fcf400, 0xfcfc7000, 0x7fff3f00, 0xf4fcf000, 0xfcfc3400, 0x3fff7f00, 0x70fcfcfc},
    { 0x20504040, 0x50180000, 0x04142000, 0x00901500, 0x00185000, 0x40502000, 0x15900000, 0x20140404}
   , 0x10,65.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat155,2,8, "D630",-1,-1,1,1,2,2,0x2,685,
    { 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00},
    { 0x00600400, 0x10204000, 0x40240000, 0x04201000, 0x40201000, 0x04600000, 0x10200400, 0x00244000}
   , 0x800,65.000000,attributes+0,1,NULL,autohelperowl_defendpat155,3,1.600000},
  {owl_defendpat156,5,8, "D631",-1,-1,1,2,2,3,0x2,721,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfcfc},
    { 0x40606440, 0x54a04000, 0x64240400, 0x04285500, 0x40a05400, 0x64604000, 0x55280400, 0x04246404}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_defendpat156,3,1.960000},
  {owl_defendpat157,5,8, "D632",-1,-1,1,2,2,3,0x2,759,
    { 0xfcffff00, 0xfcfcfcf0, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc3c, 0xfcfcfc00},
    { 0x58666000, 0x54a41820, 0x24649400, 0x90685400, 0x18a45400, 0x60665800, 0x54689020, 0x94642400}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat157,3,1.000000},
  {owl_defendpat158,7,8, "D633",-1,-3,1,1,2,4,0x2,722,
    { 0x3bffff00, 0xf0fcf8fc, 0xfcfcb000, 0xbcfc3c00, 0xf8fcf000, 0xffff3b00, 0x3cfcbcfc, 0xb0fcfc00},
    { 0x11500000, 0x10140004, 0x00141000, 0x00501000, 0x00141000, 0x00501100, 0x10500040, 0x10140000}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat159,1,8, "D634",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00680000, 0x10202000, 0x00a40000, 0x20201000, 0x20201000, 0x00680000, 0x10202000, 0x00a40000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat159,3,0.610000},
  {owl_defendpat160,6,8, "D635",0,-1,3,2,3,3,0x2,686,
    { 0x00f0fcfc, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0f, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0x003cffff},
    { 0x00500404, 0x10104000, 0x41140000, 0x05101005, 0x40101040, 0x04500000, 0x10100500, 0x00144141}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat160,0,1.000000},
  {owl_defendpat161,3,8, "D636",0,-2,1,2,1,4,0x2,648,
    { 0x00ffff00, 0xf0f0f0f0, 0xffff0000, 0x3c3c3c3c, 0xf0f0f0f0, 0xffff0000, 0x3c3c3c3c, 0x00ffff00},
    { 0x00150000, 0x00101010, 0x00520000, 0x10100020, 0x10100020, 0x00150000, 0x00101010, 0x00520000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat161,0,1.000000},
  {owl_defendpat162,2,8, "D637",-1,-1,0,1,1,2,0x0,685,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00180400, 0x00106000, 0x40900000, 0x24100000, 0x60100000, 0x04180000, 0x00102400, 0x00904000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat162,0,0.019600},
  {owl_defendpat163,5,8, "D638",-1,-1,1,2,2,3,0x2,610,
    { 0xe0f8fc00, 0xfcf8e000, 0xffbf2d00, 0x2cbcfc7c, 0xe0f8fcf4, 0xfcf8e000, 0xfcbc2c00, 0x2dbfff00},
    { 0x00904400, 0x60104000, 0x44180000, 0x04102400, 0x40106000, 0x44900000, 0x24100400, 0x00184400}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat164,2,8, "D639",0,-1,1,2,1,3,0x2,721,
    { 0x00bfff00, 0xe0f0f0f0, 0xfcf80000, 0x3c3c2c00, 0xf0f0e000, 0xffbf0000, 0x2c3c3c3c, 0x00f8fc00},
    { 0x0012a000, 0x80900020, 0x28100000, 0x00180800, 0x00908000, 0xa0120000, 0x08180020, 0x00102800}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat164,0,1.000000},
  {owl_defendpat165,3,8, "D640",0,-1,1,3,1,4,0x2,647,
    { 0x00f0fc00, 0xf0f0c000, 0xff3f0000, 0x0c3c3c3c, 0xc0f0f0f0, 0xfcf00000, 0x3c3c0c00, 0x003fff00},
    { 0x00100400, 0x00104000, 0x40100000, 0x04100000, 0x40100000, 0x04100000, 0x00100400, 0x00104000}
   , 0x0,56.000000,attributes+0,1,NULL,autohelperowl_defendpat165,0,0.610000},
  {owl_defendpat166,3,8, "D641",-1,-2,1,2,2,4,0x2,721,
    { 0xffffff00, 0xfcfcfcfc, 0xfffffd00, 0xfcfcfc7c, 0xfcfcfcf4, 0xffffff00, 0xfcfcfcfc, 0xfdffff00},
    { 0x94210000, 0x08240410, 0x00205800, 0x40608000, 0x04240800, 0x00219400, 0x80604010, 0x58200000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat166,3,0.016000},
  {owl_defendpat167,2,8, "D642",0,-2,1,1,1,3,0x2,721,
    { 0x003fbc00, 0x80f0f030, 0xf8f00000, 0x3c3c0800, 0xf0f08000, 0xbc3f0000, 0x083c3c30, 0x00f0f800},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat167,0,0.970000},
  {owl_defendpat168,5,8, "D643",-1,-1,1,1,2,2,0x2,722,
    { 0x38bcfc00, 0xe0fcf800, 0xfcf8b000, 0xbcfc2c00, 0xf8fce000, 0xfcbc3800, 0x2cfcbc00, 0xb0f8fc00},
    { 0x10104000, 0x40140000, 0x04101000, 0x00500400, 0x00144000, 0x40101000, 0x04500000, 0x10100400}
   , 0x0,40.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat169,5,8, "D643b",-1,-1,1,2,2,3,0x2,722,
    { 0x383cfcfc, 0xc0fcf800, 0xfcf0b000, 0xbfff0f00, 0xf8fcc000, 0xfc3c3800, 0x0fffbf00, 0xb0f0fcfc},
    { 0x10104040, 0x40140000, 0x04101000, 0x00500500, 0x00144000, 0x40101000, 0x05500000, 0x10100404}
   , 0x0,40.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat170,6,8, "D644",0,-1,2,2,2,3,0x2,721,
    { 0x2f3f3f2f, 0x00f8fcfc, 0xf0f0e000, 0xffbe0000, 0xfcf80000, 0x3f3f2f00, 0x00beffff, 0xe0f0f0e0},
    { 0x02101005, 0x00500008, 0x10100000, 0x01140000, 0x00500000, 0x10100200, 0x00140181, 0x00101040}
   , 0x0,30.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat171,5,4, "D700",-1,0,1,2,2,2,0x0,648,
    { 0x00f8fcf8, 0xf0f0e000, 0xfcbc0000, 0x2e3f3f00, 0xe0f0f000, 0xfcf80000, 0x3f3f2e00, 0x00bcfcbc},
    { 0x00100410, 0x00104000, 0x40100000, 0x04110000, 0x40100000, 0x04100000, 0x00110400, 0x00104010}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat172,3,8, "D701",-1,0,1,2,2,2,0x0,648,
    { 0x0030fc3c, 0xc0f0c000, 0xfc300000, 0x0f3f0c00, 0xc0f0c000, 0xfc300000, 0x0c3f0f00, 0x0030fcf0},
    { 0x00100410, 0x00104000, 0x40100000, 0x04110000, 0x40100000, 0x04100000, 0x00110400, 0x00104010}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat172,0,0.016000},
  {owl_defendpat173,3,8, "D702",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00108410, 0x80104000, 0x48100000, 0x04110800, 0x40108000, 0x84100000, 0x08110400, 0x00104810}
   , 0x20,70.000000,attributes+0,1,NULL,autohelperowl_defendpat173,0,0.019600},
  {owl_defendpat174,4,8, "D703",0,-1,2,1,2,2,0x0,721,
    { 0x003cbc20, 0x80f0f000, 0xf8f00000, 0x3c3e0800, 0xf0f08000, 0xbc3c0000, 0x083e3c00, 0x00f0f820},
    { 0x00100400, 0x00104000, 0x40100000, 0x04100000, 0x40100000, 0x04100000, 0x00100400, 0x00104000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat174,0,0.610000},
  {owl_defendpat175,4,8, "D704",-1,0,1,2,2,2,0x0,686,
    { 0x0038bc3c, 0x80f0e000, 0xf8b00000, 0x2f3f0800, 0xe0f08000, 0xbc380000, 0x083f2f00, 0x00b0f8f0},
    { 0x00100400, 0x00104000, 0x40100000, 0x04100000, 0x40100000, 0x04100000, 0x00100400, 0x00104000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat175,0,1.186000},
  {owl_defendpat176,3,8, "D704b",0,-1,1,2,1,3,0x2,648,
    { 0x00f8fc00, 0xf0f0e000, 0xfcbc0000, 0x2c3c3c00, 0xe0f0f000, 0xfcf80000, 0x3c3c2c00, 0x00bcfc00},
    { 0x00100400, 0x00104000, 0x40100000, 0x04100000, 0x40100000, 0x04100000, 0x00100400, 0x00104000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat176,0,2.091760},
  {owl_defendpat177,2,8, "D705",0,0,1,2,1,2,0x2,722,
    { 0x003f3e00, 0x00f0f0b0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3e3f0000, 0x003c3c38, 0x00f0f000},
    { 0x00122000, 0x00900020, 0x20100000, 0x00180000, 0x00900000, 0x20120000, 0x00180020, 0x00102000}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_defendpat177,0,1.000000},
  {owl_defendpat178,4,8, "D706",0,-1,2,1,2,2,0x0,721,
    { 0x003cbc20, 0x80f0f000, 0xf8f00000, 0x3c3e0800, 0xf0f08000, 0xbc3c0000, 0x083e3c00, 0x00f0f820},
    { 0x00100400, 0x00104000, 0x40100000, 0x04100000, 0x40100000, 0x04100000, 0x00100400, 0x00104000}
   , 0x20,35.000000,attributes+0,1,NULL,autohelperowl_defendpat178,0,0.016000},
  {owl_defendpat179,6,8, "D707",-1,0,2,2,3,2,0x0,721,
    { 0x3c3f3f22, 0x00fcfcf0, 0xf0f0f000, 0xfcfe0000, 0xfcfc0000, 0x3f3f3c00, 0x00fefc3e, 0xf0f0f020},
    { 0x28111100, 0x00580850, 0x1010a000, 0x80940000, 0x08580000, 0x11112800, 0x00948014, 0xa0101000}
   , 0x0,77.000000,attributes+0,1,NULL,autohelperowl_defendpat179,0,1.000000},
  {owl_defendpat180,8,8, "D708",-2,-2,2,1,4,3,0x0,722,
    { 0x80bcff3c, 0xe8f0f0c0, 0xfcfb0a00, 0x3f3facb0, 0xf0f0e838, 0xffbc8000, 0xac3f3f0c, 0x0afbfcf0},
    { 0x00140214, 0x00101080, 0x00510000, 0x11110010, 0x10100010, 0x02140000, 0x00111108, 0x00510050}
   , 0x0,77.000000,attributes+0,1,NULL,autohelperowl_defendpat180,0,1.000000},
  {owl_defendpat181,5,8, "D709",-1,-1,1,2,2,3,0x0,685,
    { 0x38fcfc74, 0xf0fcf800, 0xfcfcb000, 0xbdff3d00, 0xf8fcf000, 0xfcfc3800, 0x3dffbd00, 0xb0fcfc74},
    { 0x00644400, 0x50205000, 0x44640000, 0x14201400, 0x50205000, 0x44640000, 0x14201400, 0x00644400}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat181,3,0.650000},
  {owl_defendpat182,5,8, "D710",-1,0,1,2,2,2,0x0,723,
    { 0x003cfcfc, 0xc0f0f000, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xfc3c0000, 0x0f3f3f00, 0x00f0fcfc},
    { 0x00144440, 0x40105000, 0x44500000, 0x14100500, 0x50104000, 0x44140000, 0x05101400, 0x00504404}
   , 0x0,30.000000,attributes+0,1,NULL,autohelperowl_defendpat182,0,0.016000},
  {owl_defendpat183,1,8, "D711",0,0,1,1,1,1,0x0,722,
    { 0x00303c00, 0x00f0c000, 0xf0300000, 0x0c3c0000, 0xc0f00000, 0x3c300000, 0x003c0c00, 0x0030f000},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x0,25.000000,attributes+0,1,NULL,autohelperowl_defendpat183,0,0.016000},
  {owl_defendpat184,1,8, "D712",-1,0,0,1,1,1,0x0,685,
    { 0x00303c00, 0x00f0c000, 0xf0300000, 0x0c3c0000, 0xc0f00000, 0x3c300000, 0x003c0c00, 0x0030f000},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x0,25.000000,attributes+0,1,NULL,autohelperowl_defendpat184,3,0.016000},
  {owl_defendpat185,5,4, "D713",0,-1,2,2,2,3,0x0,648,
    { 0x00fcfffc, 0xf0f0f0c0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfffc0000, 0x3f3f3f0c, 0x00fcfcfc},
    { 0x00140114, 0x00101040, 0x00500000, 0x11110000, 0x10100000, 0x01140000, 0x00111104, 0x00500050}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat185,0,0.010000},
  {owl_defendpat186,5,8, "D714",0,-1,2,2,2,3,0x0,647,
    { 0x00f0fcfc, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0c, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0x003cfffc},
    { 0x00100450, 0x00104000, 0x41100000, 0x04110104, 0x40100040, 0x04100000, 0x01110400, 0x00104114}
   , 0x20,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat187,1,4, "D715",0,0,0,1,0,1,0x0,685,
    { 0x00303000, 0x00f00000, 0x30300000, 0x003c0000, 0x00f00000, 0x30300000, 0x003c0000, 0x00303000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat187,0,0.043600},
  {owl_defendpat188,2,8, "D715b",-1,-1,0,1,1,2,0x2,646,
    { 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000, 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000, 0xfcfc0000},
    { 0x04180000, 0x00102400, 0x00904000, 0x60100000, 0x24100000, 0x00180400, 0x00106000, 0x40900000}
   , 0x0,36.000000,attributes+0,1,NULL,autohelperowl_defendpat188,0,0.416000},
  {owl_defendpat189,4,8, "D715c",-1,0,1,2,2,2,0x0,649,
    { 0x00fcfcf8, 0xf0f0f000, 0xfcfc0000, 0x3e3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3e00, 0x00fcfcbc},
    { 0x00188410, 0x80106000, 0x48900000, 0x24110800, 0x60108000, 0x84180000, 0x08112400, 0x00904810}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat189,0,0.019600},
  {owl_defendpat190,6,8, "D716",-1,0,1,3,2,3,0x0,648,
    { 0x0030f8fc, 0xc0f08000, 0xbc300000, 0x0b3f0f00, 0x80f0c000, 0xf8300000, 0x0f3f0b00, 0x0030bcfc},
    { 0x00100044, 0x00100000, 0x00100000, 0x01100100, 0x00100000, 0x00100000, 0x01100100, 0x00100044}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat190,0,0.016000},
  {owl_defendpat191,5,8, "D717",-1,-1,1,2,2,3,0x0,648,
    { 0xf8fcfc54, 0xfcfcf800, 0xfcfcbc00, 0xbdfdfd00, 0xf8fcfc00, 0xfcfcf800, 0xfdfdbd00, 0xbcfcfc54},
    { 0x50241800, 0x04649000, 0x90601400, 0x18644000, 0x90640400, 0x18245000, 0x40641800, 0x14609000}
   , 0x0,81.000000,attributes+0,1,NULL,autohelperowl_defendpat191,3,1.000000},
  {owl_defendpat192,4,8, "D718",-1,0,2,2,3,2,0x0,685,
    { 0x003fff3f, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xff3f0000, 0x0c3f3f3f, 0x00f0fcf0},
    { 0x00118110, 0x80100050, 0x08100000, 0x00110800, 0x00108000, 0x81110000, 0x08110014, 0x00100810}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat193,4,8, "D720",0,-1,1,2,1,3,0x0,648,
    { 0x00f0fc00, 0xf0f0c000, 0xfe3e0000, 0x0c3c3c28, 0xc0f0f0a0, 0xfcf00000, 0x3c3c0c00, 0x003efe00},
    { 0x00100400, 0x00104000, 0x40100000, 0x04100000, 0x40100000, 0x04100000, 0x00100400, 0x00104000}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_defendpat193,0,0.010000},
  {owl_defendpat194,6,8, "D721",-1,-2,1,0,2,2,0x0,722,
    { 0x00fcbcec, 0xb0f0f000, 0xf8fc0000, 0x3f3e3b00, 0xf0f0b000, 0xbcfc0000, 0x3b3e3f00, 0x00fcf8ec},
    { 0x00580044, 0x10102000, 0x00940000, 0x21101100, 0x20101000, 0x00580000, 0x11102100, 0x00940044}
   , 0x0,55.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat195,4,8, "D722",-1,-2,1,1,2,3,0x0,721,
    { 0x0c3cfc30, 0xc0f0fc00, 0xfcf0c000, 0xfc3f0c00, 0xfcf0c000, 0xfc3c0c00, 0x0c3ffc00, 0xc0f0fc30},
    { 0x08104410, 0x40104800, 0x44108000, 0x84110400, 0x48104000, 0x44100800, 0x04118400, 0x80104410}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat195,0,0.610000},
  {owl_defendpat196,1,8, "D800",0,0,3,3,3,3,0x6,722,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat197,1,8, "D801",0,-1,1,1,1,2,0x6,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00900000, 0x20100000, 0x00180000, 0x00102000, 0x00102000, 0x00900000, 0x20100000, 0x00180000}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat198,2,8, "D802",0,0,1,2,1,2,0x6,722,
    { 0x003b3f00, 0x00f0e0f0, 0xf0b00000, 0x2c3c0000, 0xe0f00000, 0x3f3b0000, 0x003c2c3c, 0x00b0f000},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat199,1,8, "D803",0,-1,1,1,1,2,0x6,721,
    { 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000},
    { 0x08100000, 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x00100800, 0x00108000, 0x80100000}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat200,3,8, "D804",0,-1,1,1,1,2,0x6,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00540000, 0x10101000, 0x00540000, 0x10101000, 0x10101000, 0x00540000, 0x10101000, 0x00540000}
   , 0x0,25.000000,attributes+0,1,NULL,autohelperowl_defendpat200,0,0.010000},
  {owl_defendpat201,2,8, "D804a",0,-1,1,1,1,2,0xa,685,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00148000, 0x80101000, 0x08500000, 0x10100800, 0x10108000, 0x80140000, 0x08101000, 0x00500800}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat201,0,0.010000},
  {owl_defendpat202,3,8, "D804b",0,-1,1,2,1,3,0x6,685,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00958000, 0xa0101010, 0x08580000, 0x10102800, 0x1010a000, 0x80950000, 0x28101010, 0x00580800}
   , 0x0,26.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat203,5,8, "D805",0,-1,2,2,2,3,0xa,686,
    { 0x00bcfffe, 0xe0f0f0c0, 0xfcf80000, 0x3f3f2f00, 0xf0f0e000, 0xffbc0000, 0x2f3f3f0e, 0x00f8fcfc},
    { 0x00140100, 0x00101040, 0x00500000, 0x10100000, 0x10100000, 0x01140000, 0x00101004, 0x00500000}
   , 0x0,98.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat204,6,8, "D805a",0,-1,2,2,2,3,0xa,686,
    { 0x00f8fcfc, 0xf0f0e000, 0xfebe0000, 0x2f3f3f2a, 0xe0f0f0a0, 0xfcf80000, 0x3f3f2f00, 0x00befefe},
    { 0x00500000, 0x10100000, 0x00140000, 0x00101000, 0x00101000, 0x00500000, 0x10100000, 0x00140000}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat205,4,8, "D805b",0,-1,2,2,2,3,0xa,685,
    { 0x00f8fcfc, 0xf0f0e000, 0xffbc0000, 0x2f3f3f0e, 0xe0f0f0c0, 0xfcf80000, 0x3f3f2f00, 0x00bcfffe},
    { 0x00100000, 0x00100000, 0x01100000, 0x00100004, 0x00100040, 0x00100000, 0x00100000, 0x00100100}
   , 0x0,30.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat206,2,8, "D806",0,-1,1,2,1,3,0xa,685,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00250000, 0x00201010, 0x00600000, 0x10200000, 0x10200000, 0x00250000, 0x00201010, 0x00600000}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat206,3,1.600000},
  {owl_defendpat207,2,8, "D807",0,-1,1,2,1,3,0xa,685,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00250000, 0x00201010, 0x00600000, 0x10200000, 0x10200000, 0x00250000, 0x00201010, 0x00600000}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat207,3,1.600000},
  {owl_defendpat208,3,8, "D808",0,-1,1,2,1,3,0xa,685,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00250100, 0x00201050, 0x00600000, 0x10200000, 0x10200000, 0x01250000, 0x00201014, 0x00600000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat208,3,1.000000},
  {owl_defendpat209,3,8, "D809",0,-1,1,2,1,3,0xa,685,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00250100, 0x00201050, 0x00600000, 0x10200000, 0x10200000, 0x01250000, 0x00201014, 0x00600000}
   , 0x0,25.000000,attributes+0,1,NULL,autohelperowl_defendpat209,3,1.000000},
  {owl_defendpat210,3,8, "D810",0,-2,1,2,1,4,0xa,722,
    { 0x00bfff00, 0xe0f0f0f0, 0xfffa0000, 0x3c3c2c2c, 0xf0f0e0e0, 0xffbf0000, 0x2c3c3c3c, 0x00faff00},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_defendpat210,0,1.000000},
  {owl_defendpat211,6,8, "D811",-1,-2,1,1,2,3,0xa,722,
    { 0x3abeff00, 0xe0fcf8e8, 0xfcf8b000, 0xbcfc2c00, 0xf8fce000, 0xffbe3a00, 0x2cfcbcac, 0xb0f8fc00},
    { 0x10100000, 0x00140000, 0x00101000, 0x00500000, 0x00140000, 0x00101000, 0x00500000, 0x10100000}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat212,4,8, "D811a",-1,-2,1,1,2,3,0xa,722,
    { 0x003cfcac, 0xc0f0f000, 0xfcf00000, 0x3f3e0e00, 0xf0f0c000, 0xfc3c0000, 0x0e3e3f00, 0x00f0fce8},
    { 0x00104000, 0x40100000, 0x04100000, 0x00100400, 0x00104000, 0x40100000, 0x04100000, 0x00100400}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat213,4,8, "D812",-1,-1,1,1,2,2,0xa,722,
    { 0x28fcfc00, 0xf0f8f800, 0xfcfca000, 0xbcbc3c00, 0xf8f8f000, 0xfcfc2800, 0x3cbcbc00, 0xa0fcfc00},
    { 0x00906000, 0x60900000, 0x24180000, 0x00182400, 0x00906000, 0x60900000, 0x24180000, 0x00182400}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat214,1,8, "D813",0,-1,1,1,1,2,0xa,685,
    { 0x00fc3c00, 0x30f0f000, 0xf0fc0000, 0x3c3c3000, 0xf0f03000, 0x3cfc0000, 0x303c3c00, 0x00fcf000},
    { 0x00900000, 0x20100000, 0x00180000, 0x00102000, 0x00102000, 0x00900000, 0x20100000, 0x00180000}
   , 0x0,30.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat215,5,8, "D814",-1,-1,3,1,4,2,0xa,686,
    { 0x3cfcfcfc, 0xf0fcfc00, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xfcfc3c00, 0x3fffff00, 0xf0fcfcfc},
    { 0x10504040, 0x50140000, 0x04141000, 0x00501500, 0x00145000, 0x40501000, 0x15500000, 0x10140404}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat216,5,8, "D815",-1,-2,2,1,3,3,0xa,759,
    { 0x3f3fffff, 0xc0fcfcfc, 0xfcf0f000, 0xffff0f00, 0xfcfcc000, 0xff3f3f00, 0x0fffffff, 0xf0f0fcfc},
    { 0x14105000, 0x40540400, 0x14105000, 0x40540400, 0x04544000, 0x50101400, 0x04544000, 0x50101400}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat217,3,8, "D816",-1,0,2,2,3,2,0xa,721,
    { 0xffff0000, 0x3f3f3f3f, 0x00fcfcfc, 0xf0f0f000, 0x3f3f3f00, 0x00ffffff, 0xf0f0f0f0, 0xfcfc0000},
    { 0x40200000, 0x06210100, 0x00200458, 0x00204000, 0x01210600, 0x00204094, 0x40200000, 0x04200000}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat218,3,8, "D817",-1,0,2,2,3,2,0xa,721,
    { 0xffff0000, 0x3f3f3f3f, 0x00fcfcfc, 0xf0f0f000, 0x3f3f3f00, 0x00ffffff, 0xf0f0f0f0, 0xfcfc0000},
    { 0x40200000, 0x06210100, 0x00200458, 0x00204000, 0x01210600, 0x00204094, 0x40200000, 0x04200000}
   , 0x10,45.000000,attributes+0,1,NULL,autohelperowl_defendpat218,3,1.600000},
  {owl_defendpat219,3,8, "D818",-1,-1,1,1,2,2,0xa,722,
    { 0x3c3cfc00, 0xc0fcfc00, 0xfcf0f000, 0xfcfc0c00, 0xfcfcc000, 0xfc3c3c00, 0x0cfcfc00, 0xf0f0fc00},
    { 0x10184000, 0x40142000, 0x04901000, 0x20500400, 0x20144000, 0x40181000, 0x04502000, 0x10900400}
   , 0x10,75.000000,attributes+0,1,NULL,autohelperowl_defendpat219,0,1.000000},
  {owl_defendpat220,3,8, "D818b",-1,-1,1,1,2,2,0xa,720,
    { 0x3c3cfc00, 0xc0fcfc00, 0xfcf0f000, 0xfcfc0c00, 0xfcfcc000, 0xfc3c3c00, 0x0cfcfc00, 0xf0f0fc00},
    { 0x10184000, 0x40142000, 0x04901000, 0x20500400, 0x20144000, 0x40181000, 0x04502000, 0x10900400}
   , 0x10,76.000000,attributes+0,1,NULL,autohelperowl_defendpat220,0,0.010000},
  {owl_defendpat221,5,8, "D819",-1,-2,1,0,2,2,0xa,686,
    { 0x00fcbcbc, 0xb0f0f000, 0xf8fc0000, 0x3f3f3a00, 0xf0f0b000, 0xbcfc0000, 0x3a3f3f00, 0x00fcf8f8},
    { 0x00500400, 0x10104000, 0x40140000, 0x04101000, 0x40101000, 0x04500000, 0x10100400, 0x00144000}
   , 0x0,30.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat222,4,8, "D820",-1,-1,1,2,2,3,0xa,722,
    { 0xa0fcff00, 0xf8f8f0c0, 0xfcfc2800, 0x3cbcbc00, 0xf0f8f800, 0xfffca000, 0xbcbc3c0c, 0x28fcfc00},
    { 0x00186200, 0x40902080, 0x24900000, 0x20180400, 0x20904000, 0x62180000, 0x04182008, 0x00902400}
   , 0x10,40.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat223,4,8, "D820b",-1,-1,1,2,2,3,0xa,722,
    { 0xbcfcff00, 0xf8fcfcc0, 0xfcfcf800, 0xfcfcbc00, 0xfcfcf800, 0xfffcbc00, 0xbcfcfc0c, 0xf8fcfc00},
    { 0x24186200, 0x40982480, 0x24906000, 0x60980400, 0x24984000, 0x62182400, 0x04986008, 0x60902400}
   , 0x10,40.000000,attributes+0,1,NULL,autohelperowl_defendpat223,0,1.000000},
  {owl_defendpat224,7,8, "D821",-1,-2,2,1,3,3,0xa,722,
    { 0x0e3effaf, 0xc0f0fce8, 0xfcf0c000, 0xff3e0e00, 0xfcf0c000, 0xff3e0e00, 0x0e3effaf, 0xc0f0fce8},
    { 0x04104000, 0x40100400, 0x04104000, 0x40100400, 0x04104000, 0x40100400, 0x04104000, 0x40100400}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat225,5,8, "D822",-1,-2,1,1,2,3,0xa,685,
    { 0x3cfcfcbc, 0xf0fcfc00, 0xfcfcf000, 0xffff3e00, 0xfcfcf000, 0xfcfc3c00, 0x3effff00, 0xf0fcfcf8},
    { 0x18500810, 0x10148800, 0x80149000, 0x88511000, 0x88141000, 0x08501800, 0x10518800, 0x90148010}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat225,0,0.010000},
  {owl_defendpat226,7,8, "D823a",-2,-1,1,2,3,3,0xa,685,
    { 0xd7fffffc, 0xfcf4f4fc, 0xfcfc5c00, 0x7f7fff00, 0xf4f4fc00, 0xffffd700, 0xff7f7ffc, 0x5cfcfcfc},
    { 0x01690154, 0x10202054, 0x00a40000, 0x21211100, 0x20201000, 0x01690100, 0x11212154, 0x00a40054}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat227,8,8, "D823b",-2,-1,1,2,3,3,0xa,646,
    { 0xd7fff700, 0xfff777ff, 0x7cfc5cfc, 0x747cfc00, 0x77f7ff00, 0xf7ffd7ff, 0xfc7c74fc, 0x5cfc7c00},
    { 0x01692100, 0x11a12155, 0x20a40054, 0x20281000, 0x21a11100, 0x21690155, 0x10282054, 0x00a42000}
   , 0x0,46.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat228,8,8, "D824",-1,-1,2,2,3,3,0xa,721,
    { 0xfcffffff, 0xfcfcfcf0, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xfffffc00, 0xffffff3f, 0xfcfcfcfc},
    { 0x54116921, 0x44948450, 0xa4105400, 0x485a4400, 0x84944400, 0x69115400, 0x445a4815, 0x5410a420}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat229,4,8, "D825",-1,-1,2,1,3,2,0xa,722,
    { 0xe8fcfcfc, 0xfcf8f800, 0xfcfcac00, 0xbfbfff00, 0xf8f8fc00, 0xfcfce800, 0xffbfbf00, 0xacfcfcfc},
    { 0x40902000, 0x24900000, 0x20180400, 0x00186000, 0x00902400, 0x20904000, 0x60180000, 0x04182000}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_defendpat229,0,1.600000},
  {owl_defendpat230,5,8, "D826",-2,-1,0,1,2,2,0xa,648,
    { 0x80f0f000, 0xf8f00000, 0x3e3e0a00, 0x003cbca8, 0x00f0f8a8, 0xf0f08000, 0xbc3c0000, 0x0a3e3e00},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,25.000000,attributes+0,1,NULL,autohelperowl_defendpat230,0,1.000000},
  {owl_defendpat231,5,8, "D827",-1,-2,2,3,3,5,0xa,648,
    { 0xf0ffffff, 0xfcfcf0f0, 0xffff3f00, 0x3fffffff, 0xf0fcfcfc, 0xfffff000, 0xffff3f3f, 0x3fffffff},
    { 0xa05a0500, 0x18186060, 0x40942800, 0x24909000, 0x60181800, 0x055aa000, 0x90902424, 0x28944000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat232,5,8, "D828",-1,-2,1,1,2,3,0xa,646,
    { 0xfcfcb000, 0xbcfc3c00, 0x3afeff00, 0xf0fcf8e8, 0x3cfcbcac, 0xb0fcfc00, 0xf8fcf000, 0xfffe3a00},
    { 0x20181000, 0x00582000, 0x10902000, 0x20940000, 0x20580000, 0x10182000, 0x00942000, 0x20901000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat233,4,8, "D829",-2,-1,1,2,3,3,0xa,648,
    { 0xfcfcfc00, 0xfcffff00, 0xfffffcf0, 0xfcfcfc3c, 0xfffffcf0, 0xfcfcfc3c, 0xfcfcfc00, 0xfcffff00},
    { 0x40100000, 0x04110100, 0x00100450, 0x00104000, 0x01110400, 0x00104014, 0x40100000, 0x04100000}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_defendpat233,0,0.010000},
  {owl_defendpat234,6,8, "D830",-2,-1,1,1,3,2,0xa,722,
    { 0xecfcfc00, 0xfcf8fc00, 0xffffec00, 0xfcbcfc3c, 0xfcf8fcf0, 0xfcfcec00, 0xfcbcfc00, 0xecffff00},
    { 0x44102000, 0x04900400, 0x21114400, 0x40184014, 0x04900450, 0x20104400, 0x40184000, 0x44112100}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_defendpat234,0,0.010000},
  {owl_defendpat235,8,8, "D831",-1,-1,2,2,3,3,0xa,686,
    { 0xf8fefff7, 0xfcfcf8e0, 0xfcfcbc00, 0xbdffff00, 0xf8fcfc00, 0xfffef800, 0xffffbd2f, 0xbcfcfc7c},
    { 0x50246901, 0x44a49040, 0xa4601400, 0x18684400, 0x90a44400, 0x69245000, 0x44681805, 0x1460a400}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat236,3,8, "D832",-1,-1,1,1,2,2,0xa,722,
    { 0x0cbcfc00, 0xe0f0fc00, 0xfcf8c000, 0xfc3c2c00, 0xfcf0e000, 0xfcbc0c00, 0x2c3cfc00, 0xc0f8fc00},
    { 0x0410a000, 0x80900400, 0x28104000, 0x40180800, 0x04908000, 0xa0100400, 0x08184000, 0x40102800}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_defendpat236,0,1.000000},
  {owl_defendpat237,6,8, "D833",-2,0,2,2,4,2,0x6,759,
    { 0x3f3d3f2f, 0x00fcffdc, 0xf0f0f0c0, 0xfffe0000, 0xfffc0000, 0x3f3d3f0c, 0x00feffdf, 0xf0f0f0e0},
    { 0x11101000, 0x00540104, 0x10101040, 0x00540000, 0x01540000, 0x10101104, 0x00540040, 0x10101000}
   , 0x0,40.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat238,5,8, "D834",-2,0,2,2,4,2,0x6,722,
    { 0x3f3f3f3f, 0x00fcfffc, 0xf0f0f0c0, 0xffff0000, 0xfffc0000, 0x3f3f3f0c, 0x00ffffff, 0xf0f0f0f0},
    { 0x11101200, 0x00540184, 0x10101040, 0x00540000, 0x01540000, 0x12101104, 0x00540048, 0x10101000}
   , 0x0,40.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat239,1,8, "D835",-1,-1,2,1,3,2,0xa,683,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfcfc},
    { 0x00600000, 0x10200000, 0x00240000, 0x00201000, 0x00201000, 0x00600000, 0x10200000, 0x00240000}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat240,1,8, "D836",0,0,1,1,1,1,0xa,722,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat240,0,1.000000},
  {owl_defendpat241,5,8, "D837",-2,-2,2,2,4,4,0x6,722,
    { 0xffffffff, 0xfcfeffff, 0xfffefce0, 0xffffff2f, 0xfffefce0, 0xffffff2f, 0xffffffff, 0xfcfeffff},
    { 0x40200000, 0x04200100, 0x01200440, 0x00204004, 0x01200440, 0x00204004, 0x40200000, 0x04200100}
   , 0x0,55.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat242,4,8, "D838",-1,-1,2,1,3,2,0xa,683,
    { 0x3cfcfc3c, 0xf0fcfc00, 0xfcfcf000, 0xffff3c00, 0xfcfcf000, 0xfcfc3c00, 0x3cffff00, 0xf0fcfcf0},
    { 0x00606410, 0x50a04000, 0x64240000, 0x04291400, 0x40a05000, 0x64600000, 0x14290400, 0x00246410}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_defendpat242,3,1.000000},
  {owl_defendpat243,6,8, "D839",-2,-1,2,2,4,3,0xa,648,
    { 0xfcfcfefe, 0xfffffc80, 0xfcfcfc3c, 0xffffff00, 0xfcffff00, 0xfefcfcf0, 0xffffff0a, 0xfcfcfcfc},
    { 0x14242400, 0x00a65400, 0x60605020, 0x54680000, 0x54a60000, 0x24241420, 0x00685400, 0x50606000}
   , 0x0,88.000000,attributes+0,1,NULL,autohelperowl_defendpat243,3,1.600000},
  {owl_defendpat244,7,8, "D840",-2,-1,1,2,3,3,0xa,685,
    { 0xfffffcf0, 0xfcfcfc3c, 0xfcfcfc00, 0xfcffff00, 0xfcfcfc00, 0xfcffff00, 0xfffffcf0, 0xfcfcfc3c},
    { 0x11a50450, 0x20245014, 0x40681000, 0x14612100, 0x50242000, 0x04a51100, 0x21611450, 0x10684014}
   , 0x0,25.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat245,3,8, "D841",-2,-2,2,1,4,3,0xa,722,
    { 0x3fffffff, 0xf0ffffff, 0xfcfcf0f0, 0xffff3f00, 0xfffff000, 0xffff3f3f, 0x3fffffff, 0xf0fcfcfc},
    { 0x10900000, 0x20150000, 0x00181010, 0x00502000, 0x00152000, 0x00901010, 0x20500000, 0x10180000}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat246,3,8, "D842",-2,-2,2,2,4,4,0x6,722,
    { 0xffffffff, 0xfcfcffff, 0xfffffcc0, 0xffffff3f, 0xfffcfcf0, 0xffffff0f, 0xffffffff, 0xfcffffff},
    { 0xa4500000, 0x18180600, 0x00166880, 0x40909020, 0x06181820, 0x0050a408, 0x90904000, 0x68160000}
   , 0x0,76.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat247,7,8, "D843",0,-2,2,2,2,4,0xa,721,
    { 0x3f3f3f3f, 0x00ffffff, 0xf0f0f0f0, 0xffff0000, 0xffff0000, 0x3f3f3f3f, 0x00ffffff, 0xf0f0f0f0},
    { 0x10101210, 0x00550181, 0x10101050, 0x00550000, 0x01550000, 0x12101015, 0x00550008, 0x10101010}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat248,3,8, "D900",-1,-1,1,2,2,3,0x2,648,
    { 0xc0fcf400, 0xfcf07000, 0x7efc0c00, 0x343cfc08, 0x70f0fc80, 0xf4fcc000, 0xfc3c3400, 0x0cfc7e00},
    { 0x40182000, 0x04902000, 0x20900400, 0x20184000, 0x20900400, 0x20184000, 0x40182000, 0x04902000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat248,0,1.000000},
  {owl_defendpat249,1,8, "D902",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00188000, 0x80102000, 0x08900000, 0x20100800, 0x20108000, 0x80180000, 0x08102000, 0x00900800}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat249,0,1.000000},
  {owl_defendpat250,1,8, "D903",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00980000, 0x20102000, 0x00980000, 0x20102000, 0x20102000, 0x00980000, 0x20102000, 0x00980000}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_defendpat250,0,1.000000},
  {owl_defendpat251,1,8, "D904",0,-1,1,1,1,2,0x2,648,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00980000, 0x20102000, 0x00980000, 0x20102000, 0x20102000, 0x00980000, 0x20102000, 0x00980000}
   , 0x0,84.000000,attributes+0,1,NULL,autohelperowl_defendpat251,0,1.000000},
  {owl_defendpat252,1,8, "D905",0,-1,1,2,1,3,0x2,647,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00260000, 0x00201020, 0x00600000, 0x10200000, 0x10200000, 0x00260000, 0x00201020, 0x00600000}
   , 0x0,86.000000,attributes+0,1,NULL,autohelperowl_defendpat252,3,1.000000},
  {owl_defendpat253,3,8, "D906",-1,-2,1,2,2,4,0x2,720,
    { 0xfcfcfcfc, 0xfcffff00, 0xfcfcfcf0, 0xffffff00, 0xfffffc00, 0xfcfcfc3c, 0xffffff00, 0xfcfcfcfc},
    { 0x50200040, 0x04260000, 0x00201420, 0x00604100, 0x00260400, 0x00205020, 0x41600000, 0x14200004}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat254,3,8, "D907",-1,-2,1,2,2,4,0x2,685,
    { 0xfcfcfcfc, 0xfcffff00, 0xfcfcfcf0, 0xffffff00, 0xfffffc00, 0xfcfcfc3c, 0xffffff00, 0xfcfcfcfc},
    { 0x50200040, 0x04260000, 0x00201420, 0x00604100, 0x00260400, 0x00205020, 0x41600000, 0x14200004}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat255,5,8, "D908",-2,-2,1,2,3,4,0x2,685,
    { 0xfcfcfcfc, 0xfcffff00, 0xfffffcf0, 0xffffff3c, 0xfffffcf0, 0xfcfcfc3c, 0xffffff00, 0xfcfffffc},
    { 0x50200040, 0x04260000, 0x01211420, 0x00604114, 0x00260450, 0x00205020, 0x41600000, 0x14210104}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat255,3,1.000000},
  {owl_defendpat256,1,4, "D909",0,0,0,1,0,1,0x0,685,
    { 0x00303000, 0x00f00000, 0x30300000, 0x003c0000, 0x00f00000, 0x30300000, 0x003c0000, 0x00303000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_defendpat256,0,0.034000},
  {owl_defendpat257,2,8, "D910a",-1,-2,1,2,2,4,0x2,683,
    { 0xfcfcfcfc, 0xfeffff00, 0xfcfcfcf8, 0xffffff00, 0xfffffe00, 0xfcfcfcbc, 0xffffff00, 0xfcfcfcfc},
    { 0x00600080, 0x10200000, 0x00240000, 0x00201200, 0x00201000, 0x00600000, 0x12200000, 0x00240008}
   , 0x0,65.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat258,2,8, "D910b",-1,-2,1,2,2,4,0x2,683,
    { 0xfcfcfcfc, 0xfeffff00, 0xfcfcfcf8, 0xffffff00, 0xfffffe00, 0xfcfcfcbc, 0xffffff00, 0xfcfcfcfc},
    { 0x00600080, 0x10200000, 0x00240000, 0x00201200, 0x00201000, 0x00600000, 0x12200000, 0x00240008}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat258,3,1.000000},
  {owl_defendpat259,6,8, "D911",-3,-2,0,3,3,5,0x2,646,
    { 0xffff0000, 0x3e3e3e3c, 0x00ffffaa, 0xf0f0f0f0, 0x3e3e3e3e, 0x00ffffa8, 0xf0f0f0f0, 0xffff0000},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat259,3,0.010000},
  {owl_defendpat260,2,4, "D1000",0,0,1,1,1,1,0x0,721,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00102400, 0x00904000, 0x60100000, 0x04180000, 0x40900000, 0x24100000, 0x00180400, 0x00106000}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat260,0,0.592000},
  {owl_defendpat261,1,4, "D1000a",0,0,0,1,0,1,0x0,685,
    { 0x00303000, 0x00f00000, 0x30300000, 0x003c0000, 0x00f00000, 0x30300000, 0x003c0000, 0x00303000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,95.000000,attributes+0,1,NULL,autohelperowl_defendpat261,0,0.016000},
  {owl_defendpat262,2,8, "D1001",-1,-1,0,1,1,2,0x0,685,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00188400, 0x80106000, 0x48900000, 0x24100800, 0x60108000, 0x84180000, 0x08102400, 0x00904800}
   , 0x20,70.000000,attributes+0,1,NULL,autohelperowl_defendpat262,0,1.366000},
  {owl_defendpat263,5,8, "D1001b",-1,-1,1,3,2,4,0x2,795,
    { 0x3fff7f00, 0x70fcfcfc, 0xf4fcf000, 0xfcfc3400, 0xfcfc7000, 0x7fff3f00, 0x34fcfcfc, 0xf0fcf400},
    { 0x25920400, 0x20184424, 0x40186000, 0x44902000, 0x44182000, 0x04922500, 0x20904460, 0x60184000}
   , 0x20,71.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat264,2,8, "D1002",-1,-1,0,1,1,2,0x0,685,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00188400, 0x80106000, 0x48900000, 0x24100800, 0x60108000, 0x84180000, 0x08102400, 0x00904800}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat264,0,1.030000},
  {owl_defendpat265,4,8, "D1003",-2,-2,1,1,3,3,0x0,720,
    { 0xbcbc3c00, 0x28fcfc00, 0xf0f8f800, 0xfcfca000, 0xfcfc2800, 0x3cbcbc00, 0xa0fcfc00, 0xf8f8f000},
    { 0x00102400, 0x00904000, 0x60100000, 0x04180000, 0x40900000, 0x24100000, 0x00180400, 0x00106000}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_defendpat265,0,1.690000},
  {owl_defendpat266,3,8, "D1004",-2,-1,0,2,2,3,0x0,721,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00101024, 0x00500000, 0x10100000, 0x01160000, 0x00500000, 0x10100000, 0x00160100, 0x00101060}
   , 0x20,69.000000,attributes+0,1,NULL,autohelperowl_defendpat266,0,1.872304},
  {owl_defendpat267,8,8, "D1004b",-2,-1,0,2,2,3,0x1,721,
    { 0x2e3e3e3e, 0x00f8fca8, 0xf0f0e000, 0xffbf0000, 0xfcf80000, 0x3e3e2e00, 0x00bfffaa, 0xe0f0f0f0},
    { 0x00101024, 0x00500000, 0x10100000, 0x01160000, 0x00500000, 0x10100000, 0x00160100, 0x00101060}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat268,2,8, "D1005",-1,-2,1,1,2,3,0x0,721,
    { 0xffff7f00, 0x7cfcfcfc, 0xf4fcfc00, 0xfcfcf400, 0xfcfc7c00, 0x7fffff00, 0xf4fcfcfc, 0xfcfcf400},
    { 0x00902400, 0x20904000, 0x60180000, 0x04182000, 0x40902000, 0x24900000, 0x20180400, 0x00186000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat269,2,4, "D1006",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00640000, 0x10201000, 0x00640000, 0x10201000, 0x10201000, 0x00640000, 0x10201000, 0x00640000}
   , 0x20,60.000000,attributes+0,1,NULL,autohelperowl_defendpat269,3,0.376000},
  {owl_defendpat270,2,4, "D1006b",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00640000, 0x10201000, 0x00640000, 0x10201000, 0x10201000, 0x00640000, 0x10201000, 0x00640000}
   , 0x2020,80.000000,attributes+0,1,NULL,autohelperowl_defendpat270,3,0.021760},
  {owl_defendpat271,2,4, "D1007",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00640000, 0x10201000, 0x00640000, 0x10201000, 0x10201000, 0x00640000, 0x10201000, 0x00640000}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_defendpat271,3,1.531600},
  {owl_defendpat272,1,4, "D1100",0,0,1,1,1,1,0x0,721,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00201800, 0x00608000, 0x90200000, 0x08240000, 0x80600000, 0x18200000, 0x00240800, 0x00209000}
   , 0x800,88.000000,attributes+0,1,NULL,autohelperowl_defendpat272,3,1.160000},
  {owl_defendpat273,1,4, "D1100b",0,0,1,1,1,1,0x0,721,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00201800, 0x00608000, 0x90200000, 0x08240000, 0x80600000, 0x18200000, 0x00240800, 0x00209000}
   , 0x800,92.000000,attributes+0,1,NULL,autohelperowl_defendpat273,3,1.160000},
  {owl_defendpat274,1,4, "D1101",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00204020, 0x40200000, 0x04200000, 0x00220400, 0x00204000, 0x40200000, 0x04220000, 0x00200420}
   , 0x0,95.000000,attributes+0,1,NULL,autohelperowl_defendpat274,3,5.000000},
  {owl_defendpat275,1,4, "D1102",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00204020, 0x40200000, 0x04200000, 0x00220400, 0x00204000, 0x40200000, 0x04220000, 0x00200420}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat275,3,0.054400},
  {owl_defendpat276,1,4, "D1102a",-1,-1,1,3,2,4,0x0,685,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfcfc},
    { 0x00204020, 0x40200000, 0x04200000, 0x00220400, 0x00204000, 0x40200000, 0x04220000, 0x00200420}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat277,3,8, "D1103",-1,-1,2,2,3,3,0x2,758,
    { 0x3fff3fff, 0x30fcfcfc, 0xf0fcf000, 0xffff3300, 0xfcfc3000, 0x3fff3f00, 0x33ffffff, 0xf0fcf0fc},
    { 0x14680000, 0x10242400, 0x00a45000, 0x60601000, 0x24241000, 0x00681400, 0x10606000, 0x50a40000}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_defendpat277,3,3.000000},
  {owl_defendpat278,4,8, "D1104",-1,-1,2,3,3,4,0x2,723,
    { 0x3f3fbfbf, 0x80fcfcfc, 0xf8f0f000, 0xffff0a00, 0xfcfc8000, 0xbf3f3f00, 0x0affffff, 0xf0f0f8f8},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,100.000000,attributes+0,1,NULL,autohelperowl_defendpat278,0,1.000000},
  {owl_defendpat279,5,8, "D1105",-1,-1,2,2,3,3,0x2,721,
    { 0x083efeff, 0xc0f0f8a0, 0xfcf08000, 0xbf3f0f00, 0xf8f0c000, 0xfe3e0800, 0x0f3fbf2b, 0x80f0fcfc},
    { 0x00205800, 0x40608000, 0x94200000, 0x08240400, 0x80604000, 0x58200000, 0x04240800, 0x00209400}
   , 0x800,35.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat280,2,8, "D1106",-2,0,1,2,3,2,0x0,685,
    { 0x00fffffc, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3c, 0x00fcfcfc},
    { 0x00600180, 0x10200040, 0x00240000, 0x00201200, 0x00201000, 0x01600000, 0x12200004, 0x00240008}
   , 0x0,77.000000,attributes+0,1,NULL,autohelperowl_defendpat280,3,1.000000},
  {owl_defendpat281,2,8, "D1107",0,-1,1,2,1,3,0x2,648,
    { 0x00fdff00, 0xf0f0f0d0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfffd0000, 0x3c3c3c1c, 0x00fcfc00},
    { 0x00982400, 0x20906000, 0x60980000, 0x24182000, 0x60902000, 0x24980000, 0x20182400, 0x00986000}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat282,3,8, "D1108",-1,-2,2,2,3,4,0x0,647,
    { 0xffffffff, 0xfcfcfcfc, 0xffffff00, 0xffffffff, 0xfcfcfcfc, 0xffffff00, 0xffffffff, 0xffffffff},
    { 0x02299400, 0x80606018, 0x58a00000, 0x24240800, 0x60608000, 0x94290200, 0x08242490, 0x00a05800}
   , 0x200,95.000000,attributes+0,1,NULL,autohelperowl_defendpat282,3,3.960000},
  {owl_defendpat283,4,8, "D1108b",-1,-2,2,2,3,4,0x0,720,
    { 0xffffffff, 0xfcfcfcfc, 0xffffff00, 0xffffffff, 0xfcfcfcfc, 0xffffff00, 0xffffffff, 0xffffffff},
    { 0x02699400, 0x90606018, 0x5aa40000, 0x24241808, 0x60609080, 0x94690200, 0x18242490, 0x00a45a00}
   , 0x200,95.000000,attributes+0,1,NULL,autohelperowl_defendpat283,3,1.810000},
  {owl_defendpat284,1,8, "D1109",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00204820, 0x40208000, 0x84200000, 0x08220400, 0x80204000, 0x48200000, 0x04220800, 0x00208420}
   , 0x0,60.000000,attributes+0,1,NULL,autohelperowl_defendpat284,3,1.600000},
  {owl_defendpat285,3,8, "D1110",-1,-1,1,2,2,3,0x0,685,
    { 0xfcfcfc3c, 0xfcfcfc00, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcffff00, 0xfcfcfcf0},
    { 0x94240800, 0x08249400, 0x80605800, 0x58608000, 0x94240800, 0x08249400, 0x80605800, 0x58608000}
   , 0x800,75.000000,attributes+0,1,NULL,autohelperowl_defendpat285,3,1.000000},
  {owl_defendpat286,5,8, "D1111",-2,-2,2,2,4,4,0x0,647,
    { 0xfeffff3f, 0xfffcfcf8, 0xfcffff0c, 0xfffffcf0, 0xfcfcff3c, 0xfffffec0, 0xfcffffbf, 0xfffffcf0},
    { 0x94290200, 0x09242490, 0x00a05804, 0x60608000, 0x24240900, 0x02299440, 0x80606018, 0x58a00000}
   , 0x210,90.000000,attributes+0,1,NULL,autohelperowl_defendpat286,3,0.376000},
  {owl_defendpat287,5,8, "D1112",-1,-2,2,2,3,4,0x0,722,
    { 0x3effff3f, 0xf0fcfcf8, 0xfcfcf000, 0xffff3c00, 0xfcfcf000, 0xffff3e00, 0x3cffffbf, 0xf0fcfcf0},
    { 0x14690200, 0x10242490, 0x00a45000, 0x60601000, 0x24241000, 0x02691400, 0x10606018, 0x50a40000}
   , 0x200,90.000000,attributes+0,1,NULL,autohelperowl_defendpat287,3,0.376000},
  {owl_defendpat288,6,8, "D1113",-1,-2,2,2,3,4,0x0,645,
    { 0xfcfcf000, 0xffff3c00, 0x3effff3f, 0xf0fcfcf8, 0x3cffffbf, 0xf0fcfcf0, 0xfcfcf000, 0xffff3e00},
    { 0x60a45000, 0x64681000, 0x14692600, 0x10a46490, 0x10686418, 0x50a46000, 0x64a41000, 0x26691400}
   , 0x200,90.000000,attributes+0,1,NULL,autohelperowl_defendpat288,3,0.376000},
  {owl_defendpat289,7,8, "D1114",-1,-2,2,2,3,4,0x0,682,
    { 0xfcfcf000, 0xffff3c00, 0x3effff3f, 0xf0fcfcf8, 0x3cffffbf, 0xf0fcfcf0, 0xfcfcf000, 0xffff3e00},
    { 0x60a45000, 0x65681000, 0x14692606, 0x10a46490, 0x1068651a, 0x50a46040, 0x64a41000, 0x26691400}
   , 0x200,90.000000,attributes+0,1,NULL,autohelperowl_defendpat289,3,0.376000},
  {owl_defendpat290,4,8, "D1115",-2,-1,1,2,3,3,0x0,647,
    { 0xf0fcfcf0, 0xfcfcf000, 0xffff3e00, 0x3cffffbc, 0xf0fcfcf8, 0xfcfcf000, 0xffff3c00, 0x3effff3c},
    { 0x00205890, 0x40608000, 0x96200000, 0x08250608, 0x80604080, 0x58200000, 0x06250800, 0x00209618}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat291,3,8, "D1116",-1,-2,1,1,2,3,0x2,721,
    { 0xbfffff00, 0xf8fcfcfc, 0xfcfcf800, 0xfcfcbc00, 0xfcfcf800, 0xffffbf00, 0xbcfcfcfc, 0xf8fcfc00},
    { 0x1a608000, 0x90240808, 0x08249000, 0x80601800, 0x08249000, 0x80601a00, 0x18608080, 0x90240800}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat291,3,1.000000},
  {owl_defendpat292,2,8, "D1117",-2,-2,1,1,3,3,0x2,647,
    { 0xf4f4fcfc, 0xfcfcd400, 0xfd7f7c00, 0x5fffff37, 0xd4fcfc70, 0xfcf4f400, 0xffff5f00, 0x7c7ffdff},
    { 0x50200000, 0x04240000, 0x00221400, 0x00604020, 0x00240420, 0x00205000, 0x40600000, 0x14220000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat292,3,1.000000},
  {owl_defendpat293,3,8, "D1117a",-2,-1,1,2,3,3,0x2,683,
    { 0xfffff700, 0xfffd7ffc, 0x7cfcfcdc, 0xf4fcfc00, 0x7ffdff00, 0xf7ffffdc, 0xfcfcf4fc, 0xfcfc7c00},
    { 0x05290200, 0x00202694, 0x00a04080, 0x60200000, 0x26200000, 0x02290508, 0x00206058, 0x40a00000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat293,3,1.006000},
  {owl_defendpat294,6,8, "D1118",-2,-1,1,2,3,3,0x0,683,
    { 0xfcfcf000, 0xfefe3e00, 0x3cfffca8, 0xf0fcfc30, 0x3efefe30, 0xf0fcfca8, 0xfcfcf000, 0xfcff3c00},
    { 0x88641000, 0x18601800, 0x10668800, 0x90249020, 0x18601820, 0x10648800, 0x90249000, 0x88661000}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat295,3,8, "D1119",-2,-2,2,2,4,4,0x0,648,
    { 0xf8fcfcfc, 0xfcfcf800, 0xfcffbf00, 0xbffffff2, 0xf8fcfc3c, 0xfcfcf800, 0xffffbf00, 0xbffffcfe},
    { 0x00200060, 0x00200000, 0x00220000, 0x00220120, 0x00200020, 0x00200000, 0x01220000, 0x00220024}
   , 0x2000,70.000000,attributes+0,1,NULL,autohelperowl_defendpat295,3,0.016000},
  {owl_defendpat296,4,8, "D1120",-2,-2,2,2,4,4,0x0,685,
    { 0xbffffcfa, 0xf8fcfc3c, 0xfcfcf800, 0xfeffbf00, 0xfcfcf800, 0xfcffbf00, 0xbffffef2, 0xf8fcfcbc},
    { 0x00220420, 0x00204020, 0x40200000, 0x04220000, 0x40200000, 0x04220000, 0x00220420, 0x00204020}
   , 0x2000,81.000000,attributes+0,1,NULL,autohelperowl_defendpat296,3,0.016000},
  {owl_defendpat297,5,8, "D1120b",-1,-1,2,2,3,3,0x0,685,
    { 0xaf3ffffe, 0xc8f8fcfc, 0xfcf0e800, 0xffbf8f00, 0xfcf8c800, 0xff3faf00, 0x8fbffffe, 0xe8f0fcfc},
    { 0x08168800, 0x80109820, 0x88508000, 0x98100800, 0x98108000, 0x88160800, 0x08109820, 0x80508800}
   , 0x0,81.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat298,9,8, "D1121a",-2,0,1,3,3,3,0x0,722,
    { 0x2a3f3f3b, 0x00f8f8f8, 0xf0f0a000, 0xbebf0000, 0xf8f80000, 0x3f3f2a00, 0x00bfbebf, 0xa0f0f0b0},
    { 0x00200012, 0x00200000, 0x00200000, 0x00210000, 0x00200000, 0x00200000, 0x00210002, 0x00200010}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat299,9,8, "D1121b",0,-1,3,2,3,3,0x0,685,
    { 0x00fefefe, 0xf0f0f0a0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfefe0000, 0x3f3f3f2a, 0x00fcfcfc},
    { 0x00588080, 0x90102000, 0x08940000, 0x20101a00, 0x20109000, 0x80580000, 0x1a102000, 0x00940808}
   , 0x0,70.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat300,8,8, "D1121c",-1,0,2,3,3,3,0x0,685,
    { 0x00fefefe, 0xf0f0f0a0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfefe0000, 0x3f3f3f2a, 0x00fcfcfc},
    { 0x00680080, 0x10202000, 0x00a40000, 0x20201200, 0x20201000, 0x00680000, 0x12202000, 0x00a40008}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat300,3,3.000000},
  {owl_defendpat301,1,4, "D1122",0,-1,1,1,1,2,0x2,685,
    { 0x0030fc00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0x0030fc00},
    { 0x00108800, 0x80108000, 0x88100000, 0x08100800, 0x80108000, 0x88100000, 0x08100800, 0x00108800}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_defendpat301,0,1.600000},
  {owl_defendpat302,5,8, "D1123",-1,-1,2,2,3,3,0x0,648,
    { 0xbfffffbc, 0xf8fcfcfc, 0xfcfcf800, 0xffffbe00, 0xfcfcf800, 0xffffbf00, 0xbefffffc, 0xf8fcfcf8},
    { 0x16982000, 0x20942408, 0x20985000, 0x60582000, 0x24942000, 0x20981600, 0x20586080, 0x50982000}
   , 0x800,86.000000,attributes+0,1,NULL,autohelperowl_defendpat302,0,1.000000},
  {owl_defendpat303,2,8, "D1124",0,-1,1,1,1,2,0x0,685,
    { 0x00fc3c00, 0x30f0f000, 0xf0fc0000, 0x3c3c3000, 0xf0f03000, 0x3cfc0000, 0x303c3c00, 0x00fcf000},
    { 0x00640800, 0x10209000, 0x80640000, 0x18201000, 0x90201000, 0x08640000, 0x10201800, 0x00648000}
   , 0x2800,90.000000,attributes+0,1,NULL,autohelperowl_defendpat303,3,1.096000},
  {owl_defendpat304,6,8, "D1125",-2,-2,1,1,3,3,0x0,685,
    { 0xbcfcfcf0, 0xf8fcfc00, 0xfefef800, 0xfcffbf2a, 0xfcfcf8a0, 0xfcfcbc00, 0xbffffc00, 0xf8fefe3e},
    { 0x08240400, 0x00205800, 0x40608000, 0x94200000, 0x58200000, 0x04240800, 0x00209400, 0x80604000}
   , 0x2000,79.000000,attributes+0,1,NULL,autohelperowl_defendpat304,3,0.019600},
  {owl_defendpat305,1,8, "D1126",-1,0,1,2,2,2,0x0,685,
    { 0x00fcfc3c, 0xf0f0f000, 0xfcfc0000, 0x3f3f3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3f3f00, 0x00fcfcf0},
    { 0x00240800, 0x00209000, 0x80600000, 0x18200000, 0x90200000, 0x08240000, 0x00201800, 0x00608000}
   , 0x800,82.000000,attributes+0,1,NULL,autohelperowl_defendpat305,3,0.970000},
  {owl_defendpat306,4,8, "D1127",-2,-1,1,1,3,2,0x0,685,
    { 0xb0fcfcfc, 0xf8fcf000, 0xfcfc3800, 0x3fffbf00, 0xf0fcf800, 0xfcfcb000, 0xbfff3f00, 0x38fcfcfc},
    { 0x10608810, 0x90248000, 0x88241000, 0x08611800, 0x80249000, 0x88601000, 0x18610800, 0x10248810}
   , 0x800,35.000000,attributes+0,1,NULL,autohelperowl_defendpat306,3,0.010000},
  {owl_defendpat307,4,8, "D1128",-2,-2,1,1,3,3,0x0,685,
    { 0xf0fcfcf0, 0xfcfcf000, 0xffff3e00, 0x3cffffbf, 0xf0fcfcf8, 0xfcfcf000, 0xffff3c00, 0x3effff3f},
    { 0x50240800, 0x04249000, 0x80601400, 0x18604000, 0x90240400, 0x08245000, 0x40601800, 0x14608000}
   , 0x200,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat308,5,8, "D1129",-2,-1,1,2,3,3,0x0,759,
    { 0x3fffff3e, 0xf0fcfcfc, 0xfcfcf000, 0xffff3c00, 0xfcfcf000, 0xffff3f00, 0x3cfffffe, 0xf0fcfcf0},
    { 0x00906814, 0x60908000, 0xa4180000, 0x09192400, 0x80906000, 0x68900000, 0x24190900, 0x0018a450}
   , 0x200,77.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat309,3,8, "D1130",-1,-1,1,2,2,3,0x0,721,
    { 0xf0ff7c00, 0x7cfcf030, 0xf4fc3c00, 0x3cfcf400, 0xf0fc7c00, 0x7cfff000, 0xf4fc3c30, 0x3cfcf400},
    { 0x40922400, 0x24904020, 0x60180400, 0x04186000, 0x40902400, 0x24924000, 0x60180420, 0x04186000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat309,0,1.006000},
  {owl_defendpat310,2,8, "D1131",-1,0,1,1,2,1,0x0,685,
    { 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00},
    { 0x00608400, 0x90204000, 0x48240000, 0x04201800, 0x40209000, 0x84600000, 0x18200400, 0x00244800}
   , 0x2000,90.000000,attributes+0,1,NULL,autohelperowl_defendpat310,3,0.592000},
  {owl_defendpat311,3,8, "D1132",0,-1,1,2,1,3,0x0,685,
    { 0x0c3c3c3c, 0x00f0fc00, 0xf0f0c000, 0xff3f0000, 0xfcf00000, 0x3c3c0c00, 0x003fff00, 0xc0f0f0f0},
    { 0x04240810, 0x00209400, 0x80604000, 0x58210000, 0x94200000, 0x08240400, 0x00215800, 0x40608010}
   , 0x800,45.000000,attributes+0,1,NULL,autohelperowl_defendpat311,3,3.000000},
  {owl_defendpat312,4,8, "D1133",0,-1,2,2,2,3,0x2,722,
    { 0x003edfbf, 0xc070f0e0, 0xdcf00000, 0x3f370e00, 0xf070c000, 0xdf3e0000, 0x0e373f2f, 0x00f0dcf8},
    { 0x00204010, 0x40200000, 0x04200000, 0x00210400, 0x00204000, 0x40200000, 0x04210000, 0x00200410}
   , 0x2000,65.000000,attributes+0,1,NULL,autohelperowl_defendpat312,3,0.010000},
  {owl_defendpat313,3,8, "D1134",-2,-1,1,1,3,2,0x0,685,
    { 0x3cfcfcfc, 0xf0fcfc00, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xfcfc3c00, 0x3fffff00, 0xf0fcfcfc},
    { 0x006048a4, 0x50208000, 0x84240000, 0x09221600, 0x80205000, 0x48600000, 0x16220900, 0x00248468}
   , 0x800,5.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat314,1,8, "D1135",0,0,1,2,1,2,0x0,685,
    { 0x003c3c30, 0x00f0f000, 0xf0f00000, 0x3c3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3c00, 0x00f0f030},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x2000,35.000000,attributes+0,1,NULL,autohelperowl_defendpat314,0,0.610000},
  {owl_defendpat315,3,8, "D1136",-2,0,1,2,3,2,0x0,685,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00210109, 0x00200050, 0x00200000, 0x02200000, 0x00200000, 0x01210000, 0x00200215, 0x00200080}
   , 0x800,5.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat316,5,8, "D1137",-2,0,1,3,3,3,0x0,685,
    { 0x003cfcf0, 0xc0f0f000, 0xfef00000, 0x3c3f0f0a, 0xf0f0c080, 0xfc3c0000, 0x0f3f3c00, 0x00f0fe3e},
    { 0x00240000, 0x00201000, 0x00600000, 0x10200000, 0x10200000, 0x00240000, 0x00201000, 0x00600000}
   , 0x2200,65.000000,attributes+0,1,NULL,autohelperowl_defendpat316,3,0.667600},
  {owl_defendpat317,1,8, "D1138",-1,-1,1,2,2,3,0x0,721,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00209800, 0x80608000, 0x98200000, 0x08240800, 0x80608000, 0x98200000, 0x08240800, 0x00209800}
   , 0x2810,85.000000,attributes+0,1,NULL,autohelperowl_defendpat317,3,0.186496},
  {owl_defendpat318,2,8, "D1139",-1,0,1,1,2,1,0x0,648,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00241800, 0x00609000, 0x90600000, 0x18240000, 0x90600000, 0x18240000, 0x00241800, 0x00609000}
   , 0x2820,75.000000,attributes+0,1,NULL,autohelperowl_defendpat318,3,1.810000},
  {owl_defendpat319,1,8, "D1140",0,-1,2,1,2,2,0x0,685,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00240000, 0x00201000, 0x00600000, 0x10200000, 0x10200000, 0x00240000, 0x00201000, 0x00600000}
   , 0x2800,70.000000,attributes+0,1,NULL,autohelperowl_defendpat319,3,0.235600},
  {owl_defendpat320,2,8, "D1141",-2,-1,1,1,3,2,0x0,683,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfc00, 0xfcfcfc00, 0xffffff00, 0xfcfcfcfc},
    { 0x08248400, 0x80205800, 0x48608000, 0x94200800, 0x58208000, 0x84240800, 0x08209400, 0x80604800}
   , 0x0,45.000000,attributes+0,1,NULL,autohelperowl_defendpat320,3,0.610000},
  {owl_defendpat321,2,4, "D1142",-1,-1,1,1,2,2,0x0,647,
    { 0x30fc3c00, 0x30fcf000, 0xf0fc3000, 0x3cfc3000, 0xf0fc3000, 0x3cfc3000, 0x30fc3c00, 0x30fcf000},
    { 0x20182400, 0x00986000, 0x60902000, 0x24980000, 0x60980000, 0x24182000, 0x00982400, 0x20906000}
   , 0x800,30.000000,attributes+0,1,NULL,autohelperowl_defendpat321,0,2.025232},
  {owl_defendpat322,5,8, "D1143",-1,-1,1,2,2,3,0x2,683,
    { 0xfffffe00, 0xfcfcfcbc, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfeffff00, 0xfcfcfcf8, 0xfcfcfc00},
    { 0x09990400, 0x20106814, 0x40988000, 0xa4102000, 0x68102000, 0x04990900, 0x2010a450, 0x80984000}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat322,0,0.235600},
  {owl_defendpat323,2,8, "D1144",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00640800, 0x10209000, 0x80640000, 0x18201000, 0x90201000, 0x08640000, 0x10201800, 0x00648000}
   , 0x0,82.000000,attributes+0,1,NULL,autohelperowl_defendpat323,3,0.019600},
  {owl_defendpat324,2,8, "D1144b",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00640800, 0x10209000, 0x80640000, 0x18201000, 0x90201000, 0x08640000, 0x10201800, 0x00648000}
   , 0x0,40.000000,attributes+0,1,NULL,autohelperowl_defendpat324,3,0.010000},
  {owl_defendpat325,2,8, "D1200",-1,-2,2,2,3,4,0x6,647,
    { 0xffffffff, 0xfcfcfcfc, 0xffffff00, 0xffffffff, 0xfcfcfcfc, 0xffffff00, 0xffffffff, 0xffffffff},
    { 0x80205800, 0x48608000, 0x94200800, 0x08248400, 0x80604800, 0x58208000, 0x84240800, 0x08209400}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat326,6,8, "D1201a",0,-1,2,1,2,2,0x0,648,
    { 0x00f8fca8, 0xf0f0e000, 0xfcbc0000, 0x2e3e3e00, 0xe0f0f000, 0xfcf80000, 0x3e3e2e00, 0x00bcfca8},
    { 0x00900400, 0x20104000, 0x40180000, 0x04102000, 0x40102000, 0x04900000, 0x20100400, 0x00184000}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat326,0,0.010000},
  {owl_defendpat327,5,8, "D1201b",0,-1,2,1,2,2,0x0,648,
    { 0x00f8fce8, 0xf0f0e000, 0xfcbc0000, 0x2e3e3f00, 0xe0f0f000, 0xfcf80000, 0x3f3e2e00, 0x00bcfcac},
    { 0x00900480, 0x20104000, 0x40180000, 0x04102200, 0x40102000, 0x04900000, 0x22100400, 0x00184008}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat327,0,1.810000},
  {owl_defendpat328,4,8, "D1202",-1,-2,1,1,2,3,0x2,720,
    { 0xfcfcf000, 0xfffe3e00, 0x3cfcfcac, 0xf0fcfc00, 0x3efeff00, 0xf0fcfce8, 0xfcfcf000, 0xfcfc3c00},
    { 0x00181000, 0x00502000, 0x10900000, 0x20140000, 0x20500000, 0x10180000, 0x00142000, 0x00901000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat328,0,0.592000},
  {owl_defendpat329,2,8, "D1203",0,-1,1,1,1,2,0x2,685,
    { 0x00fc7c00, 0x70f0f000, 0xf4fc0000, 0x3c3c3400, 0xf0f07000, 0x7cfc0000, 0x343c3c00, 0x00fcf400},
    { 0x00940000, 0x20101000, 0x00580000, 0x10102000, 0x10102000, 0x00940000, 0x20101000, 0x00580000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat329,0,1.603600},
  {owl_defendpat330,3,8, "D1204",0,-1,1,1,1,2,0x2,685,
    { 0x00bcfc00, 0xe0f0f000, 0xfcf80000, 0x3c3c2c00, 0xf0f0e000, 0xfcbc0000, 0x2c3c3c00, 0x00f8fc00},
    { 0x00148000, 0x80101000, 0x08500000, 0x10100800, 0x10108000, 0x80140000, 0x08101000, 0x00500800}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_defendpat330,0,0.972160},
  {owl_defendpat331,2,4, "D1205",-1,0,1,2,2,2,0x0,685,
    { 0x0030fc30, 0xc0f0c000, 0xfc300000, 0x0c3f0c00, 0xc0f0c000, 0xfc300000, 0x0c3f0c00, 0x0030fc30},
    { 0x00108810, 0x80108000, 0x88100000, 0x08110800, 0x80108000, 0x88100000, 0x08110800, 0x00108810}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat331,0,1.000000},
  {owl_defendpat332,5,8, "D1206",-1,-1,1,1,2,2,0x0,647,
    { 0x38fcf800, 0xf0fcb800, 0xbcfcb000, 0xb8fc3c00, 0xb8fcf000, 0xf8fc3800, 0x3cfcb800, 0xb0fcbc00},
    { 0x10249000, 0x80641000, 0x18601000, 0x10640800, 0x10648000, 0x90241000, 0x08641000, 0x10601800}
   , 0x0,40.000000,attributes+0,1,NULL,autohelperowl_defendpat332,3,1.000000},
  {owl_defendpat333,2,8, "D1300",0,0,2,1,2,1,0x0,722,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00180024, 0x00102000, 0x00900000, 0x21120000, 0x20100000, 0x00180000, 0x00122100, 0x00900060}
   , 0x2000,90.000000,attributes+0,1,NULL,autohelperowl_defendpat333,0,1.810000},
  {owl_defendpat334,2,8, "D1300b",0,0,2,1,2,1,0x0,685,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00180024, 0x00102000, 0x00900000, 0x21120000, 0x20100000, 0x00180000, 0x00122100, 0x00900060}
   , 0x2000,89.000000,attributes+0,1,NULL,autohelperowl_defendpat334,0,1.810000},
  {owl_defendpat335,2,8, "D1301",0,-1,2,2,2,3,0x0,685,
    { 0x003cffff, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0f, 0x00f0fcfc},
    { 0x00204100, 0x40200040, 0x04200000, 0x00200400, 0x00204000, 0x41200000, 0x04200004, 0x00200400}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_defendpat335,3,0.592000},
  {owl_defendpat336,4,8, "D1301b",0,-1,2,2,2,3,0x0,685,
    { 0x0038ffd8, 0xc0f0e0c0, 0xfcb00000, 0x2e3d0f00, 0xe0f0c000, 0xff380000, 0x0f3d2e0c, 0x00b0fc9c},
    { 0x00204100, 0x40200040, 0x04200000, 0x00200400, 0x00204000, 0x41200000, 0x04200004, 0x00200400}
   , 0x0,90.000000,attributes+0,1,NULL,autohelperowl_defendpat336,3,3.616000},
  {owl_defendpat337,2,8, "D1302",0,-1,2,1,2,2,0x0,685,
    { 0x00f0fcc0, 0xf0f0c000, 0xfc3c0000, 0x0c3c3f00, 0xc0f0f000, 0xfcf00000, 0x3f3c0c00, 0x003cfc0c},
    { 0x00600400, 0x10204000, 0x40240000, 0x04201000, 0x40201000, 0x04600000, 0x10200400, 0x00244000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat337,3,0.151360},
  {owl_defendpat338,8,4, "D1303",-2,0,2,4,4,4,0x0,758,
    { 0x2a3f0f03, 0x0038f8f8, 0xc0f0a000, 0xbcb00000, 0xf8380000, 0x0f3f2a00, 0x00b0bcbf, 0xa0f0c000},
    { 0x00200402, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200402, 0x00204000}
   , 0x2000,80.000000,attributes+0,1,NULL,autohelperowl_defendpat338,3,0.019600},
  {owl_defendpat339,10,4, "D1304",-2,0,2,4,4,4,0x0,758,
    { 0x3f3f0f03, 0x003efefe, 0xc0f0f0a0, 0xfcf00000, 0xfe3e0000, 0x0f3f3f2a, 0x00f0fcff, 0xf0f0c000},
    { 0x00200402, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200402, 0x00204000}
   , 0x2000,80.000000,attributes+0,1,NULL,autohelperowl_defendpat339,3,0.019600},
  {owl_defendpat340,6,8, "D1305",-3,-2,1,1,4,3,0x0,647,
    { 0xdcfcfcf0, 0xfcf4fc00, 0xfefede00, 0xfc7fffaa, 0xfcf4fca8, 0xfcfcdc00, 0xff7ffc00, 0xdefefe3e},
    { 0x08100420, 0x00104800, 0x40108000, 0x84120000, 0x48100000, 0x04100800, 0x00128400, 0x80104020}
   , 0x2000,75.000000,attributes+0,1,NULL,autohelperowl_defendpat340,0,0.019600},
  {owl_defendpat341,4,8, "D1306",-1,-1,2,2,3,3,0x0,647,
    { 0x80f4fcf0, 0xf8f0d000, 0xff7f0a00, 0x1c3fbfbf, 0xd0f0f8f8, 0xfcf48000, 0xbf3f1c00, 0x0a7fff3f},
    { 0x00204810, 0x40208000, 0x84200000, 0x08210402, 0x80204000, 0x48200000, 0x04210800, 0x00208412}
   , 0x2000,79.000000,attributes+0,1,NULL,autohelperowl_defendpat341,3,0.016000},
  {owl_defendpat342,5,8, "D1307",-2,-2,1,2,3,4,0x0,720,
    { 0x3efcfc34, 0xf0fcfe0a, 0xfcfcf080, 0xfdff3c00, 0xfefcf000, 0xfcfc3e0a, 0x3cfffd80, 0xf0fcfc70},
    { 0x00104820, 0x40108000, 0x84100000, 0x08120400, 0x80104000, 0x48100000, 0x04120800, 0x00108420}
   , 0x2000,80.000000,attributes+0,1,NULL,autohelperowl_defendpat342,0,0.010000},
  {owl_defendpat343,6,8, "D1308",-1,0,2,4,3,4,0x2,758,
    { 0x2a3f3f3f, 0x00f8f8f8, 0xf0f0a000, 0xbfbf0000, 0xf8f80000, 0x3f3f2a00, 0x00bfbfbf, 0xa0f0f0f0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x2000,75.000000,attributes+0,1,NULL,autohelperowl_defendpat343,0,0.016000},
  {owl_defendpat344,5,8, "D1309",-1,0,2,4,3,4,0x2,795,
    { 0x2b3f3f3f, 0x00f8f8fc, 0xf0f0a000, 0xbfbf0000, 0xf8f80000, 0x3f3f2b00, 0x00bfbfff, 0xa0f0f0f0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x2000,81.000000,attributes+0,1,NULL,autohelperowl_defendpat344,0,0.016000},
  {owl_defendpat345,7,8, "D1309b",-2,0,2,4,4,4,0x2,757,
    { 0x2f3f3f3f, 0x00f8fefe, 0xf0f0e080, 0xffbf0000, 0xfef80000, 0x3f3f2f0a, 0x00bfffff, 0xe0f0f0f0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x2000,82.000000,attributes+0,1,NULL,autohelperowl_defendpat345,0,0.016000},
  {owl_defendpat346,9,8, "D1310",-2,0,1,3,3,3,0x0,721,
    { 0x0a3e0f00, 0x0030faea, 0xc0f08080, 0xbc300000, 0xfa300000, 0x0f3e0a0a, 0x0030bcac, 0x80f0c000},
    { 0x00200600, 0x00204080, 0x40200000, 0x04200000, 0x40200000, 0x06200000, 0x00200408, 0x00204000}
   , 0x2000,80.000000,attributes+0,1,NULL,autohelperowl_defendpat346,3,0.023056},
  {owl_defendpat347,9,8, "D1311",-3,-1,0,2,3,3,0x0,721,
    { 0x1e3f3e0a, 0x00f4fcb8, 0xf0f0d000, 0xfe7c0000, 0xfcf40000, 0x3e3f1e00, 0x007cfeba, 0xd0f0f080},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x2000,80.000000,attributes+0,1,NULL,autohelperowl_defendpat347,0,0.019600},
  {owl_defendpat348,9,8, "D1312",-4,-2,0,2,4,4,0x0,722,
    { 0x003cffff, 0xc0f0f0c0, 0xfef00000, 0x3f3f0f0a, 0xf0f0c080, 0xff3c0000, 0x0f3f3f0f, 0x00f0fefe},
    { 0x00240200, 0x00201080, 0x00600000, 0x10200000, 0x10200000, 0x02240000, 0x00201008, 0x00600000}
   , 0x2000,80.000000,attributes+0,1,NULL,autohelperowl_defendpat348,3,0.019600},
  {owl_defendpat349,2,8, "D1313",-1,0,2,3,3,3,0x0,686,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00140000, 0x00101000, 0x00500000, 0x10100000, 0x10100000, 0x00140000, 0x00101000, 0x00500000}
   , 0x2000,55.000000,attributes+0,1,NULL,autohelperowl_defendpat349,0,0.016000},
  {owl_defendpat350,4,8, "D1314",-1,-2,4,1,5,3,0x0,796,
    { 0x3fbfffbf, 0xe0fcfcfc, 0xfcf8f000, 0xffff2e00, 0xfcfce000, 0xffbf3f00, 0x2effffff, 0xf0f8fcf8},
    { 0x00100010, 0x00100000, 0x00100000, 0x00110000, 0x00100000, 0x00100000, 0x00110000, 0x00100010}
   , 0x2000,55.000000,attributes+0,1,NULL,autohelperowl_defendpat350,0,0.010000},
  {owl_defendpat351,6,8, "D1315",-1,0,3,2,4,2,0x0,759,
    { 0x00bfffbf, 0xe0f0f0f0, 0xfcf80000, 0x3f3f2e00, 0xf0f0e000, 0xffbf0000, 0x2e3f3f3f, 0x00f8fcf8},
    { 0x00100010, 0x00100000, 0x00100000, 0x00110000, 0x00100000, 0x00100000, 0x00110000, 0x00100010}
   , 0x2000,50.000000,attributes+0,1,NULL,autohelperowl_defendpat351,0,0.016000},
  {owl_defendpat352,2,8, "D1316",0,0,1,1,1,1,0x0,721,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00102400, 0x00904000, 0x60100000, 0x04180000, 0x40900000, 0x24100000, 0x00180400, 0x00106000}
   , 0x20,35.000000,attributes+0,1,NULL,autohelperowl_defendpat352,0,0.010000},
  {owl_defendpat353,2,8, "D1316b",0,0,1,1,1,1,0x0,721,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00102400, 0x00904000, 0x60100000, 0x04180000, 0x40900000, 0x24100000, 0x00180400, 0x00106000}
   , 0x20,90.000000,attributes+0,1,NULL,autohelperowl_defendpat353,0,0.010000},
  {owl_defendpat354,4,8, "D1317",-1,-3,2,0,3,3,0x0,685,
    { 0x00fffffc, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3c, 0x00fcfcfc},
    { 0x00920200, 0x201000a0, 0x00180000, 0x00102000, 0x00102000, 0x02920000, 0x20100028, 0x00180000}
   , 0x2000,90.000000,attributes+0,1,NULL,autohelperowl_defendpat354,0,0.010000},
  {owl_defendpat355,1,8, "D1318",-3,-5,0,0,3,5,0x0,722,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat355,0,0.023056},
  {owl_defendpat356,9,8, "D1319",-4,-1,2,1,6,2,0x2,686,
    { 0xa8b8fcfc, 0xeafaea00, 0xfcb8a8a8, 0xafbfaf00, 0xeafaea00, 0xfcb8a8a8, 0xafbfaf00, 0xa8b8fcfc},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,82.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat357,2,2, "D1320",0,0,0,2,0,2,0x0,685,
    { 0x00303030, 0x00f00000, 0x30300000, 0x003f0000, 0x00f00000, 0x30300000, 0x003f0000, 0x00303030},
    { 0x00100010, 0x00100000, 0x00100000, 0x00110000, 0x00100000, 0x00100000, 0x00110000, 0x00100010}
   , 0x20,35.000000,attributes+0,1,NULL,autohelperowl_defendpat357,0,0.016000},
  {owl_defendpat358,2,8, "D1320a",-1,0,1,2,2,2,0x0,685,
    { 0x003cfc3c, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0x00f0fcf0},
    { 0x00108010, 0x80100000, 0x08100000, 0x00110800, 0x00108000, 0x80100000, 0x08110000, 0x00100810}
   , 0x20,70.000000,attributes+0,1,NULL,autohelperowl_defendpat358,0,1.096000},
  {owl_defendpat359,2,2, "D1320b",0,0,0,2,0,2,0x0,685,
    { 0x00303030, 0x00f00000, 0x30300000, 0x003f0000, 0x00f00000, 0x30300000, 0x003f0000, 0x00303030},
    { 0x00100010, 0x00100000, 0x00100000, 0x00110000, 0x00100000, 0x00100000, 0x00110000, 0x00100010}
   , 0x20,90.000000,attributes+0,1,NULL,autohelperowl_defendpat359,0,0.016000},
  {owl_defendpat360,3,8, "D1321",-1,0,0,2,1,2,0x0,721,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00100014, 0x00100000, 0x00100000, 0x01110000, 0x00100000, 0x00100000, 0x00110100, 0x00100050}
   , 0x20,36.000000,attributes+0,1,NULL,autohelperowl_defendpat360,0,0.016000},
  {owl_defendpat361,3,8, "D1321b",-1,0,0,2,1,2,0x0,721,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00100014, 0x00100000, 0x00100000, 0x01110000, 0x00100000, 0x00100000, 0x00110100, 0x00100050}
   , 0x20,91.000000,attributes+0,1,NULL,autohelperowl_defendpat361,0,0.016000},
  {owl_defendpat362,3,8, "D1322",-1,-1,0,1,1,2,0x0,721,
    { 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000},
    { 0x10201400, 0x00644000, 0x50201000, 0x04640000, 0x40640000, 0x14201000, 0x00640400, 0x10205000}
   , 0x20,36.000000,attributes+0,1,NULL,autohelperowl_defendpat362,3,0.019600},
  {owl_defendpat363,2,2, "D1323",0,0,0,2,0,2,0x0,685,
    { 0x00303030, 0x00f00000, 0x30300000, 0x003f0000, 0x00f00000, 0x30300000, 0x003f0000, 0x00303030},
    { 0x00100010, 0x00100000, 0x00100000, 0x00110000, 0x00100000, 0x00100000, 0x00110000, 0x00100010}
   , 0x2020,35.000000,attributes+0,1,NULL,autohelperowl_defendpat363,0,0.016000},
  {owl_defendpat364,2,8, "D1323a",-1,-1,1,1,2,2,0x0,685,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00108400, 0x80104000, 0x48100000, 0x04100800, 0x40108000, 0x84100000, 0x08100400, 0x00104800}
   , 0x2020,55.000000,attributes+0,1,NULL,autohelperowl_defendpat364,0,0.235600},
  {owl_defendpat365,3,8, "D1324",-1,0,0,2,1,2,0x0,721,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00100014, 0x00100000, 0x00100000, 0x01110000, 0x00100000, 0x00100000, 0x00110100, 0x00100050}
   , 0x2020,86.000000,attributes+0,1,NULL,autohelperowl_defendpat365,0,0.016000},
  {owl_defendpat366,3,8, "D1325",-1,-1,0,1,1,2,0x0,721,
    { 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000},
    { 0x10201400, 0x00644000, 0x50201000, 0x04640000, 0x40640000, 0x14201000, 0x00640400, 0x10205000}
   , 0x2020,86.000000,attributes+0,1,NULL,autohelperowl_defendpat366,3,0.019600},
  {owl_defendpat367,2,2, "D1326",0,0,0,2,0,2,0x0,685,
    { 0x00303030, 0x00f00000, 0x30300000, 0x003f0000, 0x00f00000, 0x30300000, 0x003f0000, 0x00303030},
    { 0x00100010, 0x00100000, 0x00100000, 0x00110000, 0x00100000, 0x00100000, 0x00110000, 0x00100010}
   , 0x2000,35.000000,attributes+0,1,NULL,autohelperowl_defendpat367,0,0.016000},
  {owl_defendpat368,3,8, "D1327",-1,0,0,2,1,2,0x0,721,
    { 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0},
    { 0x00100014, 0x00100000, 0x00100000, 0x01110000, 0x00100000, 0x00100000, 0x00110100, 0x00100050}
   , 0x2000,36.000000,attributes+0,1,NULL,autohelperowl_defendpat368,0,0.016000},
  {owl_defendpat369,3,8, "D1328",-1,-1,0,1,1,2,0x0,721,
    { 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000},
    { 0x10201400, 0x00644000, 0x50201000, 0x04640000, 0x40640000, 0x14201000, 0x00640400, 0x10205000}
   , 0x2000,36.000000,attributes+0,1,NULL,autohelperowl_defendpat369,3,0.019600},
  {owl_defendpat370,3,8, "D1329",-1,0,1,4,2,4,0x0,686,
    { 0x00b8fcfc, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0x00b8fcfc},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat371,5,8, "D1330",0,-1,3,2,3,3,0x0,685,
    { 0x00f0fcfc, 0xf0f0c000, 0xff3d0000, 0x0f3f3f1f, 0xc0f0f0d0, 0xfcf00000, 0x3f3f0f00, 0x003dffff},
    { 0x00100800, 0x00108000, 0x82100000, 0x08100008, 0x80100080, 0x08100000, 0x00100800, 0x00108200}
   , 0x2000,90.000000,attributes+0,1,NULL,autohelperowl_defendpat371,0,1.810000},
  {owl_defendpat372,6,8, "D1331",-1,-1,2,2,3,3,0x0,722,
    { 0x3efefe7e, 0xf0fcfca8, 0xfcfcf000, 0xffff3d00, 0xfcfcf000, 0xfefe3e00, 0x3dffffaa, 0xf0fcfcf4},
    { 0x20580020, 0x10182000, 0x00942000, 0x20921000, 0x20181000, 0x00582000, 0x10922000, 0x20940020}
   , 0x2200,90.000000,attributes+0,1,NULL,autohelperowl_defendpat372,0,1.810000},
  {owl_defendpat373,7,8, "D1332",-1,-1,2,2,3,3,0x0,721,
    { 0x31ff7faa, 0x70fcf0f4, 0xf4fc3000, 0x3efe3600, 0xf0fc7000, 0x7fff3100, 0x36fe3e7e, 0x30fcf4a8},
    { 0x10922400, 0x20944020, 0x60181000, 0x04582000, 0x40942000, 0x24921000, 0x20580420, 0x10186000}
   , 0x2000,95.000000,attributes+0,1,NULL,autohelperowl_defendpat373,0,0.010000},
  {owl_defendpat374,6,8, "D1333",-1,-1,2,1,3,2,0x0,722,
    { 0x30fcfca8, 0xf0fcf000, 0xfcfc3000, 0x3efe3e00, 0xf0fcf000, 0xfcfc3000, 0x3efe3e00, 0x30fcfca8},
    { 0x10986000, 0x60942000, 0x24981000, 0x20582400, 0x20946000, 0x60981000, 0x24582000, 0x10982400}
   , 0x2200,90.000000,attributes+0,1,NULL,autohelperowl_defendpat374,0,1.096000},
  {owl_defendpat375,4,8, "D1333b",-1,-1,2,1,3,2,0x0,722,
    { 0x30fcfc30, 0xf0fcf000, 0xfcfc3000, 0x3cff3c00, 0xf0fcf000, 0xfcfc3000, 0x3cff3c00, 0x30fcfc30},
    { 0x10986010, 0x60942000, 0x24981000, 0x20592400, 0x20946000, 0x60981000, 0x24592000, 0x10982410}
   , 0x2000,90.000000,attributes+0,1,NULL,autohelperowl_defendpat375,0,0.016000},
  {owl_defendpat376,5,4, "D1334",-1,-1,1,1,2,2,0x0,683,
    { 0xb8fcfc00, 0xf8fcf800, 0xfcfcb800, 0xbcfcbc00, 0xf8fcf800, 0xfcfcb800, 0xbcfcbc00, 0xb8fcfc00},
    { 0x00649800, 0x90609000, 0x98640000, 0x18241800, 0x90609000, 0x98640000, 0x18241800, 0x00649800}
   , 0x2000,95.000000,attributes+0,1,NULL,autohelperowl_defendpat376,3,0.010000},
  {owl_defendpat377,6,4, "D1335",-1,-1,2,2,3,3,0x0,647,
    { 0xb0fcf0c0, 0xf8fc3000, 0x3ffe3a00, 0x30fcbfac, 0x30fcf8e8, 0xf0fcb000, 0xbffc3000, 0x3afe3f0c},
    { 0x00249040, 0x80601000, 0x18600000, 0x10240900, 0x10608000, 0x90240000, 0x09241000, 0x00601804}
   , 0x2200,95.000000,attributes+0,1,NULL,autohelperowl_defendpat377,3,0.019600},
  {owl_defendpat378,5,8, "D1336",-1,-1,1,1,2,2,0x0,647,
    { 0xbcfcf800, 0xf8fcbc00, 0xbcfcf800, 0xf8fcbc00, 0xbcfcf800, 0xf8fcbc00, 0xbcfcf800, 0xf8fcbc00},
    { 0x18249000, 0x80641800, 0x18609000, 0x90640800, 0x18648000, 0x90241800, 0x08649000, 0x90601800}
   , 0x2000,95.000000,attributes+0,1,NULL,autohelperowl_defendpat378,3,0.010000},
  {owl_defendpat379,6,8, "D1337",0,-1,3,2,3,3,0x0,723,
    { 0x003cffff, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0f, 0x00f0fcfc},
    { 0x00148200, 0x80101080, 0x08500000, 0x10100800, 0x10108000, 0x82140000, 0x08101008, 0x00500800}
   , 0x2200,90.000000,attributes+0,1,NULL,autohelperowl_defendpat379,0,1.810000},
  {owl_defendpat380,7,8, "D1338",-1,-2,2,1,3,3,0x0,685,
    { 0x3efefe3e, 0xf0fcfca8, 0xfcfcf000, 0xffff3c00, 0xfcfcf000, 0xfefe3e00, 0x3cffffaa, 0xf0fcfcf0},
    { 0x20644020, 0x50281000, 0x04642000, 0x10a21400, 0x10285000, 0x40642000, 0x14a21000, 0x20640420}
   , 0x2000,90.000000,attributes+0,1,NULL,autohelperowl_defendpat380,3,1.810000},
  {owl_defendpat381,4,4, "D1339",-1,0,1,2,2,2,0x0,685,
    { 0x00b0fcb0, 0xe0f0c000, 0xfc380000, 0x0c3f2e00, 0xc0f0e000, 0xfcb00000, 0x2e3f0c00, 0x0038fc38},
    { 0x00204420, 0x40204000, 0x44200000, 0x04220400, 0x40204000, 0x44200000, 0x04220400, 0x00204420}
   , 0x2000,93.000000,attributes+0,1,NULL,autohelperowl_defendpat381,3,0.010000},
  {owl_defendpat382,3,8, "D1340",-1,-1,1,2,2,3,0x2,721,
    { 0xbcffff00, 0xf8fcfcf0, 0xfcfcf800, 0xfcfcbc00, 0xfcfcf800, 0xffffbc00, 0xbcfcfc3c, 0xf8fcfc00},
    { 0x08610000, 0x10200810, 0x00248000, 0x80201000, 0x08201000, 0x00610800, 0x10208010, 0x80240000}
   , 0x2000,85.000000,attributes+0,1,NULL,autohelperowl_defendpat382,3,1.412800},
  {owl_defendpat383,4,8, "D1341",0,-1,3,2,3,3,0x0,685,
    { 0x0030fcfc, 0xc0f0c000, 0xff300000, 0x0f3f0f0c, 0xc0f0c0c0, 0xfc300000, 0x0f3f0f00, 0x0030fffc},
    { 0x00100800, 0x00108000, 0x82100000, 0x08100008, 0x80100080, 0x08100000, 0x00100800, 0x00108200}
   , 0x2000,60.000000,attributes+0,1,NULL,autohelperowl_defendpat383,0,0.010000},
  {owl_defendpat384,3,8, "D1342",-2,-1,1,2,3,3,0x2,683,
    { 0xfcffbf00, 0xbffffff0, 0xf8fcfcfc, 0xfcfcf800, 0xffffbf00, 0xbffffcfc, 0xf8fcfc3c, 0xfcfcf800},
    { 0x48600000, 0x16200800, 0x00248408, 0x80205000, 0x08201600, 0x00604880, 0x50208000, 0x84240000}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat385,6,8, "D1343a",-1,-3,2,0,3,3,0x0,722,
    { 0x003fbfbd, 0x80f0f0f0, 0xf8f00000, 0x3f3f0a00, 0xf0f08000, 0xbf3f0000, 0x0a3f3f3d, 0x00f0f8f8},
    { 0x00210000, 0x00200010, 0x00200000, 0x00200000, 0x00200000, 0x00210000, 0x00200010, 0x00200000}
   , 0x2000,77.000000,attributes+0,1,NULL,autohelperowl_defendpat385,3,0.016000},
  {owl_defendpat386,8,8, "D1343b",-3,-1,0,2,3,3,0x0,722,
    { 0x003bbebf, 0x80f0e0b0, 0xf8b00000, 0x2f3f0a00, 0xe0f08000, 0xbe3b0000, 0x0a3f2f3b, 0x00b0f8f8},
    { 0x00210002, 0x00200010, 0x00200000, 0x00200000, 0x00200000, 0x00210000, 0x00200012, 0x00200000}
   , 0x2000,60.000000,attributes+0,1,NULL,autohelperowl_defendpat386,3,0.016000},
  {owl_defendpat387,8,8, "D1343c",-1,-3,2,0,3,3,0x0,723,
    { 0x003bbebf, 0x80f0e0b0, 0xf8b00000, 0x2f3f0a00, 0xe0f08000, 0xbe3b0000, 0x0a3f2f3b, 0x00b0f8f8},
    { 0x00210000, 0x00200010, 0x00200000, 0x00200000, 0x00200000, 0x00210000, 0x00200010, 0x00200000}
   , 0x2000,60.000000,attributes+0,1,NULL,autohelperowl_defendpat387,3,0.019600},
  {owl_defendpat388,6,8, "D1343d",-1,-3,2,0,3,3,0x0,723,
    { 0x003fbfbf, 0x80f0f0f0, 0xf8f00000, 0x3f3f0a00, 0xf0f08000, 0xbf3f0000, 0x0a3f3f3f, 0x00f0f8f8},
    { 0x00210000, 0x00200010, 0x00200000, 0x00200000, 0x00200000, 0x00210000, 0x00200010, 0x00200000}
   , 0x2200,55.000000,attributes+0,1,NULL,autohelperowl_defendpat388,3,0.016000},
  {owl_defendpat389,5,8, "D1344",-1,-1,1,3,2,4,0x2,685,
    { 0x28fcfc3c, 0xf0f8f800, 0xfcfca000, 0xbfbf3c00, 0xf8f8f000, 0xfcfc2800, 0x3cbfbf00, 0xa0fcfcf0},
    { 0x00908000, 0xa0100000, 0x08180000, 0x00102800, 0x0010a000, 0x80900000, 0x28100000, 0x00180800}
   , 0x2000,85.000000,attributes+0,1,NULL,autohelperowl_defendpat389,0,0.010000},
  {owl_defendpat390,2,8, "D1345",0,-1,1,1,1,2,0x0,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00640000, 0x10201000, 0x00640000, 0x10201000, 0x10201000, 0x00640000, 0x10201000, 0x00640000}
   , 0x2800,85.000000,attributes+0,1,NULL,autohelperowl_defendpat390,3,0.100816},
  {owl_defendpat391,5,8, "D1346",0,-1,3,2,3,3,0x0,648,
    { 0x00f0fcf4, 0xf0f0c000, 0xff3f0000, 0x0d3f3f3f, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0d00, 0x003fff7f},
    { 0x00100800, 0x00108000, 0x80120000, 0x08100020, 0x80100020, 0x08100000, 0x00100800, 0x00128000}
   , 0x2000,65.000000,attributes+0,1,NULL,autohelperowl_defendpat391,0,0.019600},
  {owl_defendpat392,2,8, "D1347",-1,-1,1,1,2,2,0x2,721,
    { 0xf0fcfc00, 0xfcfcf000, 0xfcfc3c00, 0x3cfcfc00, 0xf0fcfc00, 0xfcfcf000, 0xfcfc3c00, 0x3cfcfc00},
    { 0x60900000, 0x24180000, 0x00182400, 0x00906000, 0x00182400, 0x00906000, 0x60900000, 0x24180000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat392,0,1.000000},
  {owl_defendpat393,2,8, "D1348",0,0,1,2,1,2,0x0,722,
    { 0x003c3c0c, 0x00f0f000, 0xf0f00000, 0x3f3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3f00, 0x00f0f0c0},
    { 0x00100004, 0x00100000, 0x00100000, 0x01100000, 0x00100000, 0x00100000, 0x00100100, 0x00100040}
   , 0x2020,36.000000,attributes+0,1,NULL,autohelperowl_defendpat393,0,0.016000},
  {owl_defendpat394,2,8, "D1348b",0,0,1,2,1,2,0x0,722,
    { 0x003c3c0c, 0x00f0f000, 0xf0f00000, 0x3f3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3f00, 0x00f0f0c0},
    { 0x00100004, 0x00100000, 0x00100000, 0x01100000, 0x00100000, 0x00100000, 0x00100100, 0x00100040}
   , 0x2020,90.000000,attributes+0,1,NULL,autohelperowl_defendpat394,0,0.016000},
  {owl_defendpat395,2,8, "D1348c",0,0,1,2,1,2,0x0,722,
    { 0x003c1c1c, 0x0070f000, 0xd0f00000, 0x3f350000, 0xf0700000, 0x1c3c0000, 0x00353f00, 0x00f0d0d0},
    { 0x00100004, 0x00100000, 0x00100000, 0x01100000, 0x00100000, 0x00100000, 0x00100100, 0x00100040}
   , 0x2020,90.000000,attributes+0,1,NULL,autohelperowl_defendpat395,0,3.616000},
  {owl_defendpat396,2,8, "D1348d",0,0,2,2,2,2,0x0,722,
    { 0x003c3f0f, 0x00f0f0c0, 0xf0f00000, 0x3f3c0000, 0xf0f00000, 0x3f3c0000, 0x003c3f0f, 0x00f0f0c0},
    { 0x00100001, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100001, 0x00100000}
   , 0x2020,90.000000,attributes+0,1,NULL,autohelperowl_defendpat396,0,0.016000},
  {owl_defendpat397,2,8, "D1350",-1,-1,0,2,1,3,0x0,721,
    { 0x303c3c3c, 0x00fcf000, 0xf0f03000, 0x3fff0000, 0xf0fc0000, 0x3c3c3000, 0x00ff3f00, 0x30f0f0f0},
    { 0x10201000, 0x00640000, 0x10201000, 0x00640000, 0x00640000, 0x10201000, 0x00640000, 0x10201000}
   , 0x2000,85.000000,attributes+0,1,NULL,autohelperowl_defendpat397,3,0.021760},
  {owl_defendpat398,2,8, "D1351",0,-1,2,1,2,2,0x0,685,
    { 0x003cfc38, 0xc0f0f000, 0xfcf00000, 0x3e3f0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3f3e00, 0x00f0fcb0},
    { 0x00188000, 0x80102000, 0x08900000, 0x20100800, 0x20108000, 0x80180000, 0x08102000, 0x00900800}
   , 0x2000,65.000000,attributes+0,1,NULL,autohelperowl_defendpat398,0,0.010000},
  {owl_defendpat399,3,8, "D1352",0,-2,1,1,1,3,0x0,721,
    { 0x3c3c3c00, 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00, 0xf0f0f000},
    { 0x00102400, 0x00914000, 0x60100010, 0x04180000, 0x40910000, 0x24100010, 0x00180400, 0x00106000}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat399,0,1.810000},
  {owl_defendpat400,1,8, "D1353",-2,-1,1,2,3,3,0x2,647,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xffffffff, 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xffffffff},
    { 0x10200000, 0x00240000, 0x00201200, 0x00600080, 0x00240008, 0x00201000, 0x00600000, 0x12200000}
   , 0x0,80.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat401,3,8, "D1354",-3,-2,0,2,3,4,0x0,758,
    { 0x3f3f3f0c, 0x00fcfdfc, 0xf0f0f040, 0xfffc0000, 0xfdfc0000, 0x3f3f3f04, 0x00fcfffc, 0xf0f0f0c0},
    { 0x10101008, 0x00540000, 0x10101000, 0x02540000, 0x00540000, 0x10101000, 0x00540200, 0x10101080}
   , 0x2000,65.000000,attributes+0,1,NULL,autohelperowl_defendpat401,0,0.019600},
  {owl_defendpat402,3,8, "D1355",0,-1,1,2,1,3,0x2,722,
    { 0x00ffff00, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0x00fcfc00},
    { 0x00691000, 0x10602010, 0x10a40000, 0x20241000, 0x20601000, 0x10690000, 0x10242010, 0x00a41000}
   , 0x0,70.000000,attributes+0,1,NULL,autohelperowl_defendpat402,3,0.016000},
  {owl_defendpat403,3,4, "D1356",-1,0,1,4,2,4,0x0,686,
    { 0x00b8fcfc, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0x00b8fcfc},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x2000,90.000000,attributes+0,1,NULL,autohelperowl_defendpat403,0,2.179600},
  {owl_defendpat404,3,4, "D1356a",-1,0,1,4,2,4,0x0,686,
    { 0x00b8fcfc, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0x00b8fcfc},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x2200,80.000000,attributes+0,1,NULL,autohelperowl_defendpat404,0,2.179600},
  {owl_defendpat405,2,8, "D1356b",-1,0,2,4,3,4,0x2,795,
    { 0x0f3f2f3f, 0x00b0fcfc, 0xe0f0c000, 0xff3b0000, 0xfcb00000, 0x2f3f0f00, 0x003bffff, 0xc0f0e0f0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x2000,91.000000,attributes+0,1,NULL,autohelperowl_defendpat405,0,2.179600},
  {owl_defendpat406,7,8, "D1357",-3,-2,0,2,3,4,0x0,685,
    { 0x00feffff, 0xf0f0f0e0, 0xfffc0000, 0x3f3f3f0f, 0xf0f0f0c0, 0xfffe0000, 0x3f3f3f2f, 0x00fcffff},
    { 0x00640000, 0x10201000, 0x01640000, 0x10201005, 0x10201040, 0x00640000, 0x10201000, 0x00640101}
   , 0x2000,61.000000,attributes+0,1,NULL,autohelperowl_defendpat406,3,0.019600},
  {owl_defendpat407,3,8, "D1358",0,0,1,3,1,3,0x0,759,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00101000, 0x00500000, 0x10100000, 0x00140000, 0x00500000, 0x10100000, 0x00140000, 0x00101000}
   , 0x2000,61.000000,attributes+0,1,NULL,autohelperowl_defendpat407,0,1.096000},
  {owl_defendpat408,3,8, "D1359",-2,-3,2,1,4,4,0x0,721,
    { 0xffffff2f, 0xfcffffff, 0xfcfcfcf0, 0xfffefc00, 0xfffffc00, 0xffffff3f, 0xfcfeffff, 0xfcfcfce0},
    { 0x00209004, 0x80600000, 0x18200000, 0x01240800, 0x00608000, 0x90200000, 0x08240100, 0x00201840}
   , 0x2000,65.000000,attributes+0,1,NULL,autohelperowl_defendpat408,3,0.019600},
  {owl_defendpat409,2,8, "D1360",-2,-1,2,2,4,3,0x0,720,
    { 0xfffffdfd, 0xfcfcff7f, 0xfcfcfcc0, 0xffffff00, 0xfffcfc00, 0xfdffff0f, 0xfffffff5, 0xfcfcfcfc},
    { 0x00100010, 0x00100000, 0x00100000, 0x00110000, 0x00100000, 0x00100000, 0x00110000, 0x00100010}
   , 0x2000,65.000000,attributes+0,1,NULL,autohelperowl_defendpat409,0,0.019600},
  {owl_defendpat410,2,8, "D1361a",-1,0,1,2,2,2,0x0,685,
    { 0x003cfcbc, 0xc0f0f000, 0xfcf00000, 0x3f3f0e00, 0xf0f0c000, 0xfc3c0000, 0x0e3f3f00, 0x00f0fcf8},
    { 0x00188008, 0x80102000, 0x08900000, 0x22100800, 0x20108000, 0x80180000, 0x08102200, 0x00900880}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat410,0,0.021760},
  {owl_defendpat411,1,8, "D1361b",-1,0,1,2,2,2,0x0,685,
    { 0x003cfcfc, 0xc0f0f000, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xfc3c0000, 0x0f3f3f00, 0x00f0fcfc},
    { 0x00188088, 0x80102000, 0x08900000, 0x22100a00, 0x20108000, 0x80180000, 0x0a102200, 0x00900888}
   , 0x0,65.000000,attributes+0,1,NULL,autohelperowl_defendpat411,0,1.317760},
  {owl_defendpat412,2,8, "D1362",-2,0,2,3,4,3,0x2,757,
    { 0x0f3f2f3f, 0x00b0ffff, 0xe0f0c0c0, 0xff3b0000, 0xffb00000, 0x2f3f0f0f, 0x003bffff, 0xc0f0e0f0},
    { 0x00100000, 0x00100200, 0x00100080, 0x00100000, 0x02100000, 0x00100008, 0x00100000, 0x00100000}
   , 0x0,85.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat413,4,8, "D1363",-2,-1,2,2,4,3,0x0,647,
    { 0xfcffff3f, 0xfcfcfcf0, 0xfffffe00, 0xfffffcbc, 0xfcfcfcf8, 0xfffffc00, 0xfcffff3f, 0xfefffff0},
    { 0x00201810, 0x00608000, 0x92210000, 0x08250018, 0x80600090, 0x18200000, 0x00250800, 0x00219210}
   , 0x200,75.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat414,3,8, "D1364",-1,-1,2,2,3,3,0x0,685,
    { 0xfcffff3f, 0xfcfcfcf0, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc00, 0xfffffc00, 0xfcffff3f, 0xfcfcfcf0},
    { 0x18250800, 0x00249810, 0x80609000, 0x98600000, 0x98240000, 0x08251800, 0x00609810, 0x90608000}
   , 0x200,85.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat415,4,8, "D1365",-1,-1,2,1,3,2,0x0,648,
    { 0x3cfcfcfc, 0xf0fcfc00, 0xfcfcf000, 0xffff3f00, 0xfcfcf000, 0xfcfc3c00, 0x3fffff00, 0xf0fcfcfc},
    { 0x24582400, 0x10986400, 0x60946000, 0x64981000, 0x64981000, 0x24582400, 0x10986400, 0x60946000}
   , 0x200,85.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat416,6,8, "D1366",-2,-1,2,2,4,3,0x0,685,
    { 0xbfffffd0, 0xf8fcfcfc, 0xfffef800, 0xfcfdbf2f, 0xfcfcf8e0, 0xffffbf00, 0xbffdfcfc, 0xf8feff1f},
    { 0x06290500, 0x00206458, 0x40a04000, 0x64200000, 0x64200000, 0x05290600, 0x00206494, 0x40a04000}
   , 0x0,85.000000,attributes+0,1,NULL,autohelperowl_defendpat416,3,0.010000},
  {owl_defendpat417,2,8, "D1367",-3,-1,0,2,3,3,0x0,758,
    { 0x0f3f3f0c, 0x00f0fcfc, 0xf0f0c000, 0xff3c0000, 0xfcf00000, 0x3f3f0f00, 0x003cfffc, 0xc0f0f0c0},
    { 0x00101008, 0x00500000, 0x10100000, 0x02140000, 0x00500000, 0x10100000, 0x00140200, 0x00101080}
   , 0x0,60.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat418,3,8, "D1368",-1,-2,2,1,3,3,0x0,647,
    { 0xf0f0fce0, 0xfcfcc000, 0xff3f3f00, 0x0cfeffff, 0xc0fcfcfc, 0xfcf0f000, 0xfffe0c00, 0x3f3fff2f},
    { 0x00201840, 0x00608000, 0x90200000, 0x08240102, 0x80600000, 0x18200000, 0x01240800, 0x00209006}
   , 0x2000,70.000000,attributes+0,1,NULL,autohelperowl_defendpat418,3,0.016000},
  {owl_defendpat419,3,8, "D1370",-1,-2,2,0,3,2,0x0,722,
    { 0x003cbfbf, 0x80f0f0c0, 0xf8f00000, 0x3f3f0a00, 0xf0f08000, 0xbf3c0000, 0x0a3f3f0f, 0x00f0f8f8},
    { 0x00200102, 0x00200040, 0x00200000, 0x00200000, 0x00200000, 0x01200000, 0x00200006, 0x00200000}
   , 0x2000,75.000000,attributes+0,1,NULL,autohelperowl_defendpat419,3,0.016000},
  {owl_defendpat420,4,8, "D1371",0,-1,3,1,3,2,0x0,686,
    { 0x00b8fcfc, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0x00b8fcfc},
    { 0x00100008, 0x00100000, 0x00100000, 0x02100000, 0x00100000, 0x00100000, 0x00100200, 0x00100080}
   , 0x2800,85.000000,attributes+0,1,NULL,autohelperowl_defendpat420,0,0.010000},
  {owl_defendpat421,2,8, "D1372",0,-1,1,1,1,2,0x2,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00600400, 0x10204000, 0x40240000, 0x04201000, 0x40201000, 0x04600000, 0x10200400, 0x00244000}
   , 0x2000,85.000000,attributes+0,1,NULL,autohelperowl_defendpat421,3,0.610000},
  {owl_defendpat422,2,4, "D1373",0,-2,0,1,0,3,0x0,685,
    { 0x30303020, 0x00fc0000, 0x30303000, 0x00fe0000, 0x00fc0000, 0x30303000, 0x00fe0000, 0x30303020},
    { 0x10200000, 0x00240000, 0x00201000, 0x00600000, 0x00240000, 0x00201000, 0x00600000, 0x10200000}
   , 0x2800,85.000000,attributes+0,1,NULL,autohelperowl_defendpat422,3,0.610000},
  {owl_defendpat423,4,8, "D1374",0,-4,1,1,1,5,0x2,648,
    { 0x00f8fc00, 0xf0f0e000, 0xffbf0000, 0x2c3c3c3c, 0xe0f0f0f0, 0xfcf80000, 0x3c3c2c00, 0x00bfff00},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x2000,55.000000,attributes+0,1,NULL,autohelperowl_defendpat423,3,0.019600},
  {owl_defendpat424,3,8, "D1375",-1,-2,1,1,2,3,0x0,721,
    { 0x33ffff00, 0xf0fcf0fc, 0xfcfc3000, 0x3cfc3c00, 0xf0fcf000, 0xffff3300, 0x3cfc3cfc, 0x30fcfc00},
    { 0x01601000, 0x10600004, 0x10240000, 0x00241000, 0x00601000, 0x10600100, 0x10240040, 0x00241000}
   , 0x0,75.000000,attributes+0,1,NULL,autohelperowl_defendpat424,3,1.000000},
  {owl_defendpat425,3,8, "D1376",0,-2,1,1,1,3,0x2,685,
    { 0x003bfd00, 0xc0f0e070, 0xfcb00000, 0x2c3c0c00, 0xe0f0c000, 0xfd3b0000, 0x0c3c2c34, 0x00b0fc00},
    { 0x00214000, 0x40200010, 0x04200000, 0x00200400, 0x00204000, 0x40210000, 0x04200010, 0x00200400}
   , 0x2000,75.000000,attributes+0,1,NULL,autohelperowl_defendpat425,3,0.902176},
  {owl_defendpat426,4,8, "D1377",-1,-1,1,3,2,4,0x2,647,
    { 0x00fcfc00, 0xf0f0f000, 0xffff0000, 0x3c3c3c3c, 0xf0f0f0f0, 0xfcfc0000, 0x3c3c3c00, 0x00ffff00},
    { 0x00241000, 0x00601000, 0x10600000, 0x10240000, 0x10600000, 0x10240000, 0x00241000, 0x00601000}
   , 0x0,50.000000,attributes+0,1,NULL,autohelperowl_defendpat426,3,1.000000},
  {owl_defendpat427,1,4, "D1378",-1,-1,0,1,1,2,0x0,685,
    { 0x0030fc00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0x0030fc00},
    { 0x00108800, 0x80108000, 0x88100000, 0x08100800, 0x80108000, 0x88100000, 0x08100800, 0x00108800}
   , 0x0,55.000000,attributes+0,1,NULL,autohelperowl_defendpat427,0,3.320000},
  {owl_defendpat428,1,8, "D1379",-2,0,1,2,3,2,0x0,685,
    { 0x0070fcf0, 0xd0f0c000, 0xfc340000, 0x0c3f1f00, 0xc0f0d000, 0xfc700000, 0x1f3f0c00, 0x0034fc3c},
    { 0x00100820, 0x00108000, 0x80100000, 0x08120000, 0x80100000, 0x08100000, 0x00120800, 0x00108020}
   , 0x2000,65.000000,attributes+0,1,NULL,autohelperowl_defendpat428,0,0.442960},
  {owl_defendpat429,1,8, "D1380",-2,0,0,2,2,2,0x0,722,
    { 0x003c3f0f, 0x00f0f0c0, 0xf0f00000, 0x3f3c0000, 0xf0f00000, 0x3f3c0000, 0x003c3f0f, 0x00f0f0c0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x2000,65.000000,attributes+0,1,NULL,autohelperowl_defendpat429,0,0.019600},
  {owl_defendpat430,2,8, "D1381",-1,-1,0,1,1,2,0x0,685,
    { 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00},
    { 0x00600400, 0x10204000, 0x40240000, 0x04201000, 0x40201000, 0x04600000, 0x10200400, 0x00244000}
   , 0x2000,70.000000,attributes+0,1,NULL,autohelperowl_defendpat430,3,1.096000},
  {owl_defendpat431,2,8, "D1382",-1,-1,1,0,2,1,0x0,685,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00600400, 0x10204000, 0x40240000, 0x04201000, 0x40201000, 0x04600000, 0x10200400, 0x00244000}
   , 0x2000,70.000000,attributes+0,1,NULL,autohelperowl_defendpat431,3,0.376000},
  {owl_defendpat432,2,8, "D1383",0,-1,3,1,3,2,0x0,686,
    { 0x0038fc3c, 0xc0f0e000, 0xfcb00000, 0x2f3f0c00, 0xe0f0c000, 0xfc380000, 0x0c3f2f00, 0x00b0fcf0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x2810,71.000000,attributes+0,1,NULL,autohelperowl_defendpat432,0,6.010000},
  {owl_defendpat433,2,8, "D1384",0,0,2,2,2,2,0x0,722,
    { 0x003c3f33, 0x00f0f0c0, 0xf0f00000, 0x3c3f0000, 0xf0f00000, 0x3f3c0000, 0x003f3c0f, 0x00f0f030},
    { 0x00100001, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100001, 0x00100000}
   , 0x2000,65.000000,attributes+0,1,NULL,autohelperowl_defendpat433,0,0.667600},
  {owl_defendpat434,2,8, "D1385",-2,0,1,1,3,1,0x0,685,
    { 0x00f0fc00, 0xf0f0c000, 0xff3f0000, 0x0c3c3c3c, 0xc0f0f0f0, 0xfcf00000, 0x3c3c0c00, 0x003fff00},
    { 0x00200400, 0x00204000, 0x41200000, 0x04200004, 0x40200040, 0x04200000, 0x00200400, 0x00204100}
   , 0x2000,75.000000,attributes+0,1,NULL,autohelperowl_defendpat434,3,0.592000},
  {owl_defendpat435,3,8, "D1386a",0,-1,1,2,1,3,0x2,685,
    { 0x00fdbf00, 0xb0f0f0d0, 0xf8fc0000, 0x3c3c3800, 0xf0f0b000, 0xbffd0000, 0x383c3c1c, 0x00fcf800},
    { 0x00600100, 0x10200040, 0x00240000, 0x00201000, 0x00201000, 0x01600000, 0x10200004, 0x00240000}
   , 0x2800,90.000000,attributes+0,1,NULL,autohelperowl_defendpat435,3,0.016000},
  {owl_defendpat436,3,8, "D1386b",0,-1,1,2,1,3,0x2,685,
    { 0x00fdbf00, 0xb0f0f0d0, 0xf8fc0000, 0x3c3c3800, 0xf0f0b000, 0xbffd0000, 0x383c3c1c, 0x00fcf800},
    { 0x00600100, 0x10200040, 0x00240000, 0x00201000, 0x00201000, 0x01600000, 0x10200004, 0x00240000}
   , 0x2800,35.000000,attributes+0,1,NULL,autohelperowl_defendpat436,3,0.016000},
  {owl_defendpat437,4,8, "D1387",-2,-1,1,2,3,3,0x0,647,
    { 0xbffff800, 0xf8fcbe3c, 0xbcfcf880, 0xf8fcbc00, 0xbefcf800, 0xf8ffbf08, 0xbcfcf8f0, 0xf8fcbc00},
    { 0x00229000, 0x80600020, 0x18200000, 0x00240800, 0x00608000, 0x90220000, 0x08240020, 0x00201800}
   , 0x2200,75.000000,attributes+0,1,NULL,autohelperowl_defendpat437,3,0.106000},
  {owl_defendpat438,5,8, "D1388",-2,-1,1,2,3,3,0x0,721,
    { 0xbfff3800, 0x38fcbe3c, 0xb0fcf880, 0xf8fcb000, 0xbefc3800, 0x38ffbf08, 0xb0fcf8f0, 0xf8fcb000},
    { 0x00621000, 0x10600020, 0x10240000, 0x00241000, 0x00601000, 0x10620000, 0x10240020, 0x00241000}
   , 0x2800,75.000000,attributes+0,1,NULL,autohelperowl_defendpat438,3,0.235600},
  {owl_defendpat439,2,8, "D1389",0,-1,1,2,1,3,0x2,685,
    { 0x00ff3c00, 0x30f0f030, 0xf0fc0000, 0x3c3c3000, 0xf0f03000, 0x3cff0000, 0x303c3c30, 0x00fcf000},
    { 0x00610000, 0x10200010, 0x00240000, 0x00201000, 0x00201000, 0x00610000, 0x10200010, 0x00240000}
   , 0x2000,84.000000,attributes+0,1,NULL,autohelperowl_defendpat439,3,3.616000},
  {owl_defendpat440,3,8, "D1390",-2,-1,1,3,3,4,0x2,683,
    { 0xbfff1c00, 0x387cfc3f, 0xd0fcf800, 0xfcf4b000, 0xfc7c3800, 0x1cffbf03, 0xb0f4fcf0, 0xf8fcd000},
    { 0x00600000, 0x10200000, 0x00240000, 0x00201000, 0x00201000, 0x00600000, 0x10200000, 0x00240000}
   , 0x800,80.000000,attributes+0,1,NULL,autohelperowl_defendpat440,3,5.410000},
  {owl_defendpat441,3,8, "D1391",0,-1,1,2,1,3,0x0,685,
    { 0x3c3c3c3c, 0x00fcfc00, 0xf0f0f000, 0xffff0000, 0xfcfc0000, 0x3c3c3c00, 0x00ffff00, 0xf0f0f0f0},
    { 0x04180810, 0x0010a400, 0x80904000, 0x68110000, 0xa4100000, 0x08180400, 0x00116800, 0x40908010}
   , 0x0,80.000000,attributes+0,1,NULL,autohelperowl_defendpat441,0,4.210000},
  {owl_defendpat442,3,8, "D1400",-1,-2,1,1,2,3,0x1,721,
    { 0x3fff3c00, 0x30fcfc3c, 0xf0fcf000, 0xfcfc3000, 0xfcfc3000, 0x3cff3f00, 0x30fcfcf0, 0xf0fcf000},
    { 0x20912400, 0x20984010, 0x60182000, 0x04982000, 0x40982000, 0x24912000, 0x20980410, 0x20186000}
   , 0x0,95.000000,attributes+0,1,NULL,autohelperowl_defendpat442,0,0.019600},
  {owl_defendpat443,3,8, "D1400b",-1,-2,1,1,2,3,0x1,720,
    { 0x3fff3c00, 0x30fcfc3c, 0xf0fcf000, 0xfcfc3000, 0xfcfc3000, 0x3cff3f00, 0x30fcfcf0, 0xf0fcf000},
    { 0x20912400, 0x20984010, 0x60182000, 0x04982000, 0x40982000, 0x24912000, 0x20980410, 0x20186000}
   , 0x0,95.000000,attributes+0,1,NULL,autohelperowl_defendpat443,0,0.010000},
  {owl_defendpat444,3,8, "D1401",-1,-2,1,1,2,3,0x1,720,
    { 0x3fff3c00, 0x30fcfc3c, 0xf0fcf000, 0xfcfc3000, 0xfcfc3000, 0x3cff3f00, 0x30fcfcf0, 0xf0fcf000},
    { 0x20912400, 0x20984010, 0x60182000, 0x04982000, 0x40982000, 0x24912000, 0x20980410, 0x20186000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat444,0,0.016000},
  {owl_defendpat445,2,8, "D1402",0,-1,1,2,1,3,0x2,722,
    { 0x00fcff00, 0xf0f0f0c0, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfffc0000, 0x3c3c3c0c, 0x00fcfc00},
    { 0x00186200, 0x40902080, 0x24900000, 0x20180400, 0x20904000, 0x62180000, 0x04182008, 0x00902400}
   , 0x10,45.000000,attributes+0,1,NULL,autohelperowl_defendpat445,0,0.076160},
  {owl_defendpat446,2,8, "D1403",0,-1,1,1,1,2,0xa,722,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00186000, 0x40902000, 0x24900000, 0x20180400, 0x20904000, 0x60180000, 0x04182000, 0x00902400}
   , 0x10,30.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat447,3,8, "D1404",-1,-1,1,1,2,2,0xa,685,
    { 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00},
    { 0x58240000, 0x04241800, 0x00609400, 0x90604000, 0x18240400, 0x00245800, 0x40609000, 0x94600000}
   , 0x10,80.000000,attributes+0,1,NULL,autohelperowl_defendpat447,3,1.000000},
  {owl_defendpat448,4,8, "D1405",-1,-1,1,1,2,2,0xa,685,
    { 0xf8fcf400, 0xfcfc7800, 0x7cfcbc00, 0xb4fcfc00, 0x78fcfc00, 0xf4fcf800, 0xfcfcb400, 0xbcfc7c00},
    { 0x50248000, 0x84241000, 0x08601400, 0x10604800, 0x10248400, 0x80245000, 0x48601000, 0x14600800}
   , 0x10,80.000000,attributes+0,1,NULL,autohelperowl_defendpat448,3,1.000000},
  {owl_defendpat449,4,8, "D1405b",-1,-1,1,1,2,2,0xa,721,
    { 0xf8fcfc00, 0xfcfcf800, 0xfcfcbc00, 0xbcfcfc00, 0xf8fcfc00, 0xfcfcf800, 0xfcfcbc00, 0xbcfcfc00},
    { 0x50209000, 0x84640000, 0x18201400, 0x00644800, 0x00648400, 0x90205000, 0x48640000, 0x14201800}
   , 0x10,80.000000,attributes+0,1,NULL,autohelperowl_defendpat449,3,1.000000},
  {owl_defendpat450,4,8, "D1406",-1,-1,1,1,2,2,0xa,647,
    { 0xf8fcfc00, 0xfcfcf800, 0xfcfcbc00, 0xbcfcfc00, 0xf8fcfc00, 0xfcfcf800, 0xfcfcbc00, 0xbcfcfc00},
    { 0x50248000, 0x84241000, 0x08601400, 0x10604800, 0x10248400, 0x80245000, 0x48601000, 0x14600800}
   , 0x0,55.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat451,3,8, "D1407",-2,-1,1,2,3,3,0xa,647,
    { 0xfcfcfc00, 0xffffff00, 0xfffffcfc, 0xfcfcfc3c, 0xfffffff0, 0xfcfcfcfc, 0xfcfcfc00, 0xfcffff00},
    { 0x40100000, 0x06110000, 0x00120418, 0x00104020, 0x00110620, 0x00104090, 0x40100000, 0x04120000}
   , 0x0,75.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat452,4,8, "D1408",-2,-1,1,2,3,3,0x0,683,
    { 0xfcfcf000, 0xfcff3c00, 0x3ffffc30, 0xf0fcfc3c, 0x3cfffcf0, 0xf0fcfc30, 0xfcfcf000, 0xfcff3f00},
    { 0x88641000, 0x18621800, 0x11668820, 0x90249024, 0x18621860, 0x10648820, 0x90249000, 0x88661100}
   , 0x10,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat453,3,8, "D1409",-2,-1,1,1,3,2,0x4,683,
    { 0xfcfcf000, 0xfcff3c00, 0x3cfcfc30, 0xf0fcfc00, 0x3cfffc00, 0xf0fcfc30, 0xfcfcf000, 0xfcfc3c00},
    { 0x88641000, 0x18621800, 0x10648820, 0x90249000, 0x18621800, 0x10648820, 0x90249000, 0x88641000}
   , 0x10,45.000000,attributes+0,0,NULL,NULL,3,0.000000},
  {owl_defendpat454,6,8, "D1410",-2,-1,1,1,3,2,0x6,722,
    { 0xf8fcfc00, 0xfcfcf800, 0xffffbc00, 0xbcfcfc3c, 0xf8fcfcf0, 0xfcfcf800, 0xfcfcbc00, 0xbcffff00},
    { 0x5010a000, 0x84940000, 0x29111400, 0x00584814, 0x00948450, 0xa0105000, 0x48580000, 0x14112900}
   , 0x10,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat455,2,8, "D1411",0,-1,1,1,1,2,0xa,721,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00601800, 0x10608000, 0x90240000, 0x08241000, 0x80601000, 0x18600000, 0x10240800, 0x00249000}
   , 0x10,45.000000,attributes+0,1,NULL,autohelperowl_defendpat455,3,1.000000},
  {owl_defendpat456,3,8, "D1411b",0,-1,1,1,1,2,0xa,721,
    { 0x00fcbc00, 0xb0f0f000, 0xf8fc0000, 0x3c3c3800, 0xf0f0b000, 0xbcfc0000, 0x383c3c00, 0x00fcf800},
    { 0x00601800, 0x10608000, 0x90240000, 0x08241000, 0x80601000, 0x18600000, 0x10240800, 0x00249000}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_defendpat456,3,1.000000},
  {owl_defendpat457,4,8, "D1412",-1,-1,1,1,2,2,0xa,720,
    { 0x3c3cfc00, 0xc0fcfc00, 0xfcf0f000, 0xfcfc0c00, 0xfcfcc000, 0xfc3c3c00, 0x0cfcfc00, 0xf0f0fc00},
    { 0x10184400, 0x40146000, 0x44901000, 0x24500400, 0x60144000, 0x44181000, 0x04502400, 0x10904400}
   , 0x0,35.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat458,3,8, "D1413",-1,-1,1,1,2,2,0xa,648,
    { 0x0cfcfc00, 0xf0f0fc00, 0xfcfcc000, 0xfc3c3c00, 0xfcf0f000, 0xfcfc0c00, 0x3c3cfc00, 0xc0fcfc00},
    { 0x04582000, 0x10902400, 0x20944000, 0x60181000, 0x24901000, 0x20580400, 0x10186000, 0x40942000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat458,0,0.010000},
  {owl_defendpat459,8,8, "D1414",-2,-2,2,2,4,4,0xa,648,
    { 0x0f3fffff, 0xc0f0fefe, 0xfef0c080, 0xff3f0f0a, 0xfef0c080, 0xff3f0f0a, 0x0f3fffff, 0xc0f0fefe},
    { 0x04161822, 0x00509420, 0x90504000, 0x58160000, 0x94500000, 0x18160400, 0x00165822, 0x40509020}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat460,1,8, "D1415",-1,0,0,1,1,1,0x0,685,
    { 0x00303c00, 0x00f0c000, 0xf0300000, 0x0c3c0000, 0xc0f00000, 0x3c300000, 0x003c0c00, 0x0030f000},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat460,3,0.040000},
  {owl_defendpat461,1,4, "D1416",0,0,0,2,0,2,0x0,685,
    { 0x00303030, 0x00f00000, 0x30300000, 0x003f0000, 0x00f00000, 0x30300000, 0x003f0000, 0x00303030},
    { 0x00200010, 0x00200000, 0x00200000, 0x00210000, 0x00200000, 0x00200000, 0x00210000, 0x00200010}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat461,3,0.040000},
  {owl_defendpat462,1,8, "D1417",-1,0,0,1,1,1,0x0,685,
    { 0x00303c00, 0x00f0c000, 0xf0300000, 0x0c3c0000, 0xc0f00000, 0x3c300000, 0x003c0c00, 0x0030f000},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat462,3,0.050800},
  {owl_defendpat463,1,4, "D1418",0,0,0,2,0,2,0x0,685,
    { 0x00303030, 0x00f00000, 0x30300000, 0x003f0000, 0x00f00000, 0x30300000, 0x003f0000, 0x00303030},
    { 0x00200010, 0x00200000, 0x00200000, 0x00210000, 0x00200000, 0x00200000, 0x00210000, 0x00200010}
   , 0x0,35.000000,attributes+0,1,NULL,autohelperowl_defendpat463,3,0.050800},
  {owl_defendpat464,5,8, "D1419",-1,-2,1,1,2,3,0x2,646,
    { 0xffff3e00, 0x3cfcfcbc, 0xf0fcfc00, 0xfcfcf000, 0xfcfc3c00, 0x3effff00, 0xf0fcfcf8, 0xfcfcf000},
    { 0x26912400, 0x20984418, 0x60186000, 0x44982000, 0x44982000, 0x24912600, 0x20984490, 0x60186000}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_defendpat464,0,1.000000},
  {owl_defendpat465,5,8, "D1420",-1,-2,1,1,2,3,0x2,646,
    { 0xffff3e00, 0x3cfcfcbc, 0xf0fcfc00, 0xfcfcf000, 0xfcfc3c00, 0x3effff00, 0xf0fcfcf8, 0xfcfcf000},
    { 0x24912400, 0x20984410, 0x60186000, 0x44982000, 0x44982000, 0x24912400, 0x20984410, 0x60186000}
   , 0x10,35.000000,attributes+0,1,NULL,autohelperowl_defendpat465,0,1.000000},
  {owl_defendpat466,1,8, "D1421",0,-1,1,1,1,2,0x2,648,
    { 0x00f4fc00, 0xf0f0d000, 0xfc7c0000, 0x1c3c3c00, 0xd0f0f000, 0xfcf40000, 0x3c3c1c00, 0x007cfc00},
    { 0x00600800, 0x10208000, 0x80240000, 0x08201000, 0x80201000, 0x08600000, 0x10200800, 0x00248000}
   , 0x10,25.000000,attributes+0,1,NULL,autohelperowl_defendpat466,3,1.600000},
  {owl_defendpat467,6,8, "D1422",-1,-1,2,2,3,3,0xa,760,
    { 0xf0ffffff, 0xfcfcf0f0, 0xfcfc3c00, 0x3fffff00, 0xf0fcfc00, 0xfffff000, 0xffff3f3f, 0x3cfcfcfc},
    { 0xa0651a44, 0x18689090, 0x90642800, 0x19a49100, 0x90681800, 0x1a65a000, 0x91a41918, 0x28649044}
   , 0x10,25.000000,attributes+0,1,NULL,autohelperowl_defendpat467,3,0.010000},
  {owl_defendpat468,6,8, "D1423",-1,-1,2,1,3,2,0xa,723,
    { 0x3c3cfcfc, 0xc0fcfc00, 0xfcf0f000, 0xffff0f00, 0xfcfcc000, 0xfc3c3c00, 0x0fffff00, 0xf0f0fcfc},
    { 0x14105840, 0x40548400, 0x94105000, 0x48540500, 0x84544000, 0x58101400, 0x05544800, 0x50109404}
   , 0x10,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat469,5,8, "D1424",-1,-1,1,1,2,2,0xa,648,
    { 0x2cbcf800, 0xe0f8bc00, 0xbcf8e000, 0xf8bc2c00, 0xbcf8e000, 0xf8bc2c00, 0x2cbcf800, 0xe0f8bc00},
    { 0x04102000, 0x00900400, 0x20104000, 0x40180000, 0x04900000, 0x20100400, 0x00184000, 0x40102000}
   , 0x0,45.000000,attributes+0,0,NULL,NULL,0,0.000000},
  {owl_defendpat470,1,8, "DC01a",-1,0,1,2,2,2,0x0,722,
    { 0x003c3c30, 0x00f0f000, 0xf0f00000, 0x3c3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3c00, 0x00f0f030},
    { 0x00240020, 0x00201000, 0x00600000, 0x10220000, 0x10200000, 0x00240000, 0x00221000, 0x00600020}
   , 0x100,35.000000,attributes+1,1,NULL,autohelperowl_defendpat470,3,0.400000},
  {owl_defendpat471,1,8, "DC01b",-1,0,1,2,2,2,0x0,722,
    { 0x003c3c30, 0x00f0f000, 0xf0f00000, 0x3c3f0000, 0xf0f00000, 0x3c3c0000, 0x003f3c00, 0x00f0f030},
    { 0x00240020, 0x00201000, 0x00600000, 0x10220000, 0x10200000, 0x00240000, 0x00221000, 0x00600020}
   , 0x100,35.000000,attributes+3,1,NULL,autohelperowl_defendpat471,3,0.400000},
  {owl_defendpat472,2,8, "DC02",-1,-1,1,2,2,3,0x2,685,
    { 0xfcffff00, 0xfcfcfcf0, 0xfcfcfc00, 0xfcfcfc00, 0xfcfcfc00, 0xfffffc00, 0xfcfcfc3c, 0xfcfcfc00},
    { 0x60600000, 0x14280000, 0x00242400, 0x00a05000, 0x00281400, 0x00606000, 0x50a00000, 0x24240000}
   , 0x100,35.000000,attributes+5,1,NULL,autohelperowl_defendpat472,3,0.034000},
  {owl_defendpat473,4,8, "DE01a",0,-1,2,2,2,3,0x0,721,
    { 0x003cff7f, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0d00, 0xf0f0c000, 0xff3c0000, 0x0d3f3f0f, 0x00f0fcf4},
    { 0x00100015, 0x00100000, 0x00100000, 0x01110000, 0x00100000, 0x00100000, 0x00110101, 0x00100050}
   , 0x100,30.000000,attributes+7,0,NULL,NULL,0,0.000000},
  {owl_defendpat474,5,8, "DE01b",0,-1,2,2,2,3,0x0,721,
    { 0x003cfffe, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0e, 0x00f0fcfc},
    { 0x00100054, 0x00100000, 0x00100000, 0x01110100, 0x00100000, 0x00100000, 0x01110100, 0x00100054}
   , 0x100,30.000000,attributes+9,0,NULL,NULL,0,0.000000},
  {owl_defendpat475,2,8, "DE02",0,-1,1,1,1,2,0x2,647,
    { 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00},
    { 0x00100400, 0x00104000, 0x40100000, 0x04100000, 0x40100000, 0x04100000, 0x00100400, 0x00104000}
   , 0x100,30.000000,attributes+11,1,NULL,autohelperowl_defendpat475,0,0.592000},
  {owl_defendpat476,2,8, "DE03",0,-1,1,1,1,2,0x2,648,
    { 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00},
    { 0x00140000, 0x00101000, 0x00500000, 0x10100000, 0x10100000, 0x00140000, 0x00101000, 0x00500000}
   , 0x100,30.000000,attributes+13,1,NULL,autohelperowl_defendpat476,0,0.592000},
  {owl_defendpat477,5,8, "DE04",-1,-1,1,3,2,4,0x2,796,
    { 0x7effff00, 0xf4fcfcf8, 0xfcfcf400, 0xfcfc7c00, 0xfcfcf400, 0xffff7e00, 0x7cfcfcbc, 0xf4fcfc00},
    { 0x24918600, 0xa0184490, 0x48186000, 0x44902800, 0x4418a000, 0x86912400, 0x28904418, 0x60184800}
   , 0x100,30.000000,attributes+15,0,NULL,NULL,0,0.000000},
  {owl_defendpat478,2,8, "DR01",-1,-2,1,2,2,4,0x2,648,
    { 0xfcffff00, 0xfcfcfcf0, 0xfffdfc00, 0xfcfcfc1c, 0xfcfcfcd0, 0xfffffc00, 0xfcfcfc3c, 0xfcfdff00},
    { 0x90900000, 0x28140000, 0x00181800, 0x0050a000, 0x00142800, 0x00909000, 0xa0500000, 0x18180000}
   , 0x100,30.000000,attributes+17,1,NULL,autohelperowl_defendpat478,0,0.610000},
  {NULL, 0,0,NULL,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},0,0.0,NULL,0,NULL,NULL,0,0.0}
};

#include "dfa-mkpat.h"
static const state_rt_t state_owl_defendpat[10994] = {
{0,{0,0,0,0}},	{0,{0,1,2,0}},	{0,{2,3,4,5}},
{0,{5,6,7,8}},	{3,{8,9,10,11}},	{0,{11,12,13,0}},
{0,{13,14,15,0}},	{0,{0,0,15,0}},	{0,{15,16,17,18}},
{0,{18,19,20,0}},	{0,{20,21,22,0}},	{0,{22,0,0,0}},
{0,{22,23,24,25}},	{0,{25,25,26,27}},	{0,{27,28,29,30}},
{0,{30,30,30,31}},	{0,{31,32,33,34}},	{0,{34,34,34,0}},
{0,{34,0,35,0}},	{0,{35,36,37,38}},	{0,{38,38,38,38}},
{0,{38,39,40,41}},	{0,{41,0,0,0}},	{0,{41,42,43,44}},
{0,{44,45,46,47}},	{0,{47,48,49,50}},	{0,{50,51,50,50}},
{0,{51,52,53,54}},	{0,{54,55,56,57}},	{0,{57,58,58,58}},
{0,{58,59,60,61}},	{0,{0,61,0,0}},	{0,{61,0,61,0}},
{0,{61,0,0,0}},	{0,{61,62,63,64}},	{0,{64,65,66,67}},
{0,{67,68,69,70}},	{0,{70,71,72,73}},	{0,{73,74,75,76}},
{0,{76,77,78,75}},	{0,{78,79,77,74}},	{0,{79,80,81,82}},
{0,{82,83,84,85}},	{0,{85,86,87,84}},	{0,{87,88,89,83}},
{0,{89,90,90,90}},	{0,{89,89,89,89}},	{0,{89,90,90,90}},
{0,{90,91,91,92}},	{0,{92,93,94,93}},	{0,{94,94,94,94}},
{0,{94,94,94,0}},	{0,{94,0,0,0}},	{0,{94,0,0,0}},
{0,{94,95,96,97}},	{0,{97,98,99,100}},	{0,{100,100,101,102}},
{0,{102,102,103,103}},	{0,{103,103,104,104}},	{0,{104,105,106,107}},
{0,{103,104,107,106}},	{0,{107,108,109,105}},	{0,{109,110,108,104}},
{0,{110,0,0,0}},	{0,{110,111,112,113}},	{0,{113,114,115,116}},
{0,{116,117,118,119}},	{0,{119,120,121,122}},	{0,{122,123,124,125}},
{0,{125,126,127,128}},	{0,{128,129,122,123}},	{0,{129,130,131,118}},
{0,{131,132,117,117}},	{0,{132,133,134,134}},	{0,{134,135,115,115}},
{0,{135,136,114,114}},	{0,{136,136,136,136}},	{0,{136,136,136,136}},
{0,{136,137,138,139}},	{0,{139,140,141,142}},	{0,{142,143,144,145}},
{0,{145,146,147,147}},	{0,{147,148,149,0}},	{0,{149,148,148,0}},
{0,{149,150,151,0}},	{0,{151,146,146,0}},	{0,{151,152,0,0}},
{0,{0,152,0,0}},	{0,{152,153,152,154}},	{0,{154,154,154,155}},
{0,{155,155,155,156}},	{0,{156,156,156,0}},	{0,{156,157,0,0}},
{0,{0,157,0,0}},	{0,{157,0,0,0}},	{0,{157,158,159,160}},
{0,{160,161,162,163}},	{0,{163,164,165,166}},	{0,{166,167,168,169}},
{0,{169,170,171,172}},	{0,{172,173,174,175}},	{0,{175,160,161,176}},
{0,{176,163,177,178}},	{0,{178,179,180,181}},	{0,{181,182,183,184}},
{0,{184,185,186,187}},	{0,{187,159,188,189}},	{0,{189,190,191,192}},
{0,{192,193,194,195}},	{0,{195,196,197,198}},	{0,{198,155,184,199}},
{0,{199,200,201,202}},	{0,{202,203,204,205}},	{0,{205,206,207,208}},
{0,{0,208,0,0}},	{0,{208,196,197,209}},	{0,{209,199,200,201}},
{0,{209,202,203,210}},	{0,{205,210,194,195}},	{0,{206,210,197,198}},
{0,{210,211,212,213}},	{0,{213,214,215,216}},	{0,{216,217,218,219}},
{0,{219,220,221,0}},	{0,{221,222,223,224}},	{0,{209,224,211,225}},
{0,{212,225,214,226}},	{0,{215,226,217,0}},	{0,{226,218,219,227}},
{0,{227,220,228,208}},	{0,{228,221,210,229}},	{0,{229,215,216,224}},
{0,{202,217,204,205}},	{0,{205,218,207,226}},	{0,{0,227,0,228}},
{0,{0,226,0,0}},	{0,{227,228,229,230}},	{0,{226,227,230,229}},
{0,{230,231,232,228}},	{0,{229,230,232,227}},	{0,{232,229,231,226}},
{0,{232,233,234,235}},	{0,{231,232,235,234}},	{0,{230,231,234,235}},
{0,{232,232,232,232}},	{0,{0,0,234,0}},	{0,{234,234,234,234}},
{0,{234,234,234,234}},	{0,{234,235,234,236}},	{0,{236,234,233,237}},
{0,{237,238,239,240}},	{0,{240,241,240,242}},	{0,{242,243,244,245}},
{0,{241,242,241,245}},	{0,{245,246,240,247}},	{0,{239,240,239,247}},
{0,{247,248,247,249}},	{0,{249,250,249,251}},	{0,{245,246,245,251}},
{0,{235,236,235,251}},	{0,{234,235,234,249}},	{0,{250,250,250,251}},
{0,{249,249,249,251}},	{0,{248,248,248,251}},	{0,{247,247,247,251}},
{0,{251,251,251,252}},	{0,{245,245,245,245}},	{0,{251,252,244,253}},
{0,{253,253,253,254}},	{0,{254,242,242,246}},	{0,{241,241,241,250}},
{0,{240,240,240,253}},	{0,{239,239,239,253}},	{0,{0,0,0,253}},
{0,{253,254,255,256}},	{0,{256,257,258,259}},	{0,{259,260,261,262}},
{0,{262,263,262,264}},	{0,{264,265,266,267}},	{0,{267,268,269,270}},
{0,{270,271,272,258}},	{0,{272,273,274,260}},	{0,{274,275,276,248}},
{0,{276,277,278,279}},	{0,{279,280,281,254}},	{0,{281,282,281,256}},
{0,{282,283,284,285}},	{0,{285,286,287,288}},	{0,{288,289,290,291}},
{0,{291,292,291,291}},	{0,{292,293,294,295}},	{0,{295,296,297,298}},
{0,{298,299,300,287}},	{0,{287,300,287,287}},	{0,{300,301,290,302}},
{0,{302,303,293,304}},	{0,{304,305,296,283}},	{0,{305,306,283,283}},
{0,{306,285,286,287}},	{0,{306,288,307,290}},	{0,{307,308,284,285}},
{0,{308,309,310,311}},	{0,{311,312,290,277}},	{0,{312,313,314,315}},
{0,{315,316,317,318}},	{0,{318,319,320,321}},	{0,{321,322,315,316}},
{0,{295,322,273,273}},	{0,{322,308,317,318}},	{0,{322,311,312,313}},
{0,{320,322,315,316}},	{0,{322,323,324,325}},	{0,{0,325,0,0}},
{0,{325,326,0,0}},	{0,{326,327,328,329}},	{0,{329,330,330,331}},
{0,{331,332,332,333}},	{0,{331,331,331,332}},	{0,{332,333,333,334}},
{0,{334,335,336,337}},	{0,{337,334,334,338}},	{0,{338,333,333,337}},
{0,{338,339,339,340}},	{0,{340,326,326,341}},	{0,{341,325,325,325}},
{0,{324,324,324,324}},	{0,{340,340,340,341}},	{0,{339,339,339,341}},
{0,{338,338,338,338}},	{0,{340,340,341,342}},	{0,{342,342,342,342}},
{0,{342,342,342,342}},	{0,{342,343,342,344}},	{0,{340,340,340,338}},
{0,{343,339,339,339}},	{0,{343,343,343,338}},	{0,{337,337,337,343}},
{0,{343,344,0,0}},	{0,{344,0,0,345}},	{0,{0,0,0,344}},
{0,{344,345,344,346}},	{0,{346,347,343,348}},	{0,{342,342,342,344}},
{0,{347,348,347,343}},	{0,{346,346,346,342}},	{0,{341,347,341,341}},
{0,{340,340,340,340}},	{0,{0,346,0,0}},	{0,{346,0,0,0}},
{0,{0,0,0,346}},	{0,{0,0,0,346}},	{0,{0,0,0,346}},
{0,{346,347,348,0}},	{61,{348,349,350,0}},	{0,{350,351,352,0}},
{0,{352,353,354,0}},	{0,{354,355,356,0}},	{61,{356,357,346,0}},
{0,{346,357,358,0}},	{0,{358,356,350,0}},	{0,{358,359,360,0}},
{61,{360,361,342,0}},	{0,{342,353,361,0}},	{0,{361,362,363,0}},
{0,{363,0,0,0}},	{61,{363,0,0,0}},	{0,{363,0,0,0}},
{0,{363,0,364,0}},	{0,{364,331,332,0}},	{61,{364,333,334,0}},
{0,{364,365,353,0}},	{0,{365,337,366,0}},	{0,{366,339,340,0}},
{61,{360,341,366,0}},	{0,{360,341,342,0}},	{0,{365,340,362,0}},
{0,{365,343,344,0}},	{0,{365,366,367,0}},	{0,{367,0,0,0}},
{0,{367,0,0,0}},	{0,{367,0,368,0}},	{0,{368,318,319,0}},
{61,{368,320,321,0}},	{0,{368,322,340,0}},	{0,{368,369,370,0}},
{0,{370,326,327,0}},	{61,{364,328,317,0}},	{0,{364,328,329,0}},
{0,{368,327,366,0}},	{0,{368,330,331,0}},	{61,{368,332,313,0}},
{0,{360,324,332,0}},	{0,{367,368,369,0}},	{0,{369,0,0,0}},
{0,{357,0,0,0}},	{0,{368,0,369,0}},	{0,{369,370,371,0}},
{61,{371,372,306,0}},	{0,{353,372,325,0}},	{0,{372,373,374,0}},
{0,{374,375,376,0}},	{61,{367,376,302,0}},	{0,{349,0,314,0}},
{0,{368,0,370,0}},	{0,{374,375,376,0}},	{61,{376,377,298,0}},
{0,{345,0,317,0}},	{0,{376,0,366,0}},	{0,{376,0,0,0}},
{0,{376,0,0,0}},	{0,{376,377,378,0}},	{61,{378,379,292,0}},
{0,{379,358,311,0}},	{0,{379,359,360,0}},	{0,{379,380,381,0}},
{61,{381,382,288,0}},	{0,{375,0,300,0}},	{0,{381,0,356,0}},
{0,{381,382,383,0}},	{61,{0,383,284,0}},	{0,{0,0,303,0}},
{0,{382,383,352,0}},	{61,{383,0,0,0}},	{0,{383,364,384,0}},
{0,{384,348,349,0}},	{0,{384,369,385,0}},	{0,{373,374,354,0}},
{0,{376,0,346,0}},	{61,{383,362,275,0}},	{61,{0,368,274,0}},
{0,{382,383,384,0}},	{61,{384,385,386,0}},	{0,{386,387,388,0}},
{0,{388,389,390,0}},	{0,{390,391,342,0}},	{61,{391,392,393,0}},
{0,{393,394,280,0}},	{0,{394,393,336,0}},	{0,{394,395,342,0}},
{61,{395,388,389,0}},	{0,{389,390,283,0}},	{0,{394,395,332,0}},
{0,{395,0,0,0}},	{61,{391,0,395,0}},	{0,{385,0,0,0}},
{0,{394,395,322,0}},	{61,{388,395,257,0}},	{0,{382,395,276,0}},
{0,{395,396,325,0}},	{61,{377,378,254,0}},	{0,{395,396,323,0}},
{61,{383,376,252,0}},	{0,{395,394,321,0}},	{61,{381,0,0,0}},
{0,{394,395,313,0}},	{0,{395,396,318,0}},	{0,{396,397,320,0}},
{0,{397,373,259,0}},	{0,{390,375,322,0}},	{0,{376,371,314,0}},
{0,{372,380,307,0}},	{61,{0,0,0,0}},	{0,{0,0,0,393}},
{0,{393,0,0,0}},	{0,{393,0,0,0}},	{0,{393,0,394,0}},
{0,{394,0,0,0}},	{0,{391,0,0,0}},	{0,{393,0,394,0}},
{0,{394,0,0,0}},	{0,{394,0,389,0}},	{0,{393,0,0,0}},
{0,{393,0,0,0}},	{0,{393,0,0,0}},	{0,{393,0,0,0}},
{0,{393,0,384,0}},	{0,{393,0,0,0}},	{0,{391,0,0,0}},
{0,{392,0,0,0}},	{0,{0,0,392,0}},	{0,{392,392,392,0}},
{0,{392,392,392,0}},	{0,{392,393,0,0}},	{0,{393,392,0,0}},
{0,{393,394,395,0}},	{0,{395,390,0,0}},	{0,{395,396,393,0}},
{0,{396,397,0,0}},	{0,{388,396,397,0}},	{0,{385,395,0,0}},
{0,{396,397,389,0}},	{0,{383,397,0,0}},	{0,{384,396,0,0}},
{0,{396,395,386,0}},	{0,{396,397,0,0}},	{0,{397,396,0,0}},
{0,{394,395,397,0}},	{0,{397,398,382,0}},	{0,{383,398,381,0}},
{0,{398,399,0,0}},	{0,{392,398,0,0}},	{0,{385,390,378,0}},
{0,{387,389,377,0}},	{0,{371,388,0,0}},	{0,{372,387,0,0}},
{0,{394,386,0,0}},	{0,{368,394,0,0}},	{0,{369,393,0,0}},
{0,{393,394,0,0}},	{0,{392,382,0,0}},	{0,{393,381,0,0}},
{0,{381,0,0,0}},	{0,{392,0,0,0}},	{0,{392,0,0,0}},
{0,{392,0,393,0}},	{0,{393,0,0,0}},	{0,{376,393,0,0}},
{0,{393,394,0,0}},	{0,{394,0,0,0}},	{0,{394,0,0,0}},
{0,{390,394,0,0}},	{0,{371,394,0,0}},	{0,{394,393,385,0}},
{0,{369,394,0,0}},	{0,{394,0,0,0}},	{0,{385,0,0,0}},
{0,{0,0,0,393}},	{0,{393,394,0,0}},	{364,{394,395,396,0}},
{0,{396,397,398,0}},	{0,{398,399,0,0}},	{0,{399,400,0,0}},
{364,{400,401,0,0}},	{0,{401,402,403,0}},	{0,{403,404,405,0}},
{0,{405,406,0,0}},	{364,{406,407,0,0}},	{0,{407,406,390,0}},
{0,{390,407,0,0}},	{0,{0,404,0,0}},	{364,{406,403,0,0}},
{0,{406,404,0,0}},	{406,{406,407,0,0}},	{413,{407,408,381,0}},
{0,{400,408,383,0}},	{0,{408,384,0,0}},	{406,{408,409,0,0}},
{413,{385,409,410,0}},	{0,{386,410,379,0}},	{0,{410,389,390,0}},
{406,{390,410,0,0}},	{413,{391,410,0,0}},	{0,{392,409,375,0}},
{406,{0,408,0,0}},	{413,{392,407,0,0}},	{0,{0,406,0,0}},
{0,{406,407,0,0}},	{364,{407,372,367,0}},	{0,{386,407,369,0}},
{0,{395,407,0,0}},	{364,{407,408,0,0}},	{0,{373,408,366,0}},
{0,{408,376,377,0}},	{0,{377,408,0,0}},	{364,{408,381,0,0}},
{0,{379,380,362,0}},	{0,{0,379,0,0}},	{364,{0,378,0,0}},
{0,{394,405,0,0}},	{364,{395,405,0,0}},	{0,{374,405,357,0}},
{0,{405,403,0,0}},	{0,{382,405,0,0}},	{364,{394,405,0,0}},
{0,{360,405,353,0}},	{0,{405,406,364,0}},	{0,{364,406,0,0}},
{364,{395,406,0,0}},	{0,{366,405,349,0}},	{0,{397,404,0,0}},
{0,{0,403,0,0}},	{364,{0,402,0,0}},	{0,{402,403,404,0}},
{364,{404,391,405,0}},	{0,{405,391,0,0}},	{0,{405,389,0,0}},
{0,{405,406,407,0}},	{364,{407,408,409,0}},	{0,{409,410,405,0}},
{0,{410,411,412,0}},	{0,{412,392,0,0}},	{364,{396,392,397,0}},
{0,{397,391,0,0}},	{364,{0,390,395,0}},	{406,{408,379,409,0}},
{413,{392,379,393,0}},	{0,{408,378,409,0}},	{406,{394,409,396,0}},
{413,{396,397,398,0}},	{0,{408,401,402,0}},	{406,{402,382,0,0}},
{413,{386,407,387,0}},	{406,{0,381,0,0}},	{413,{0,380,385,0}},
{0,{398,369,382,0}},	{0,{386,401,388,0}},	{0,{403,392,387,0}},
{0,{403,366,379,0}},	{364,{379,366,0,0}},	{0,{382,402,384,0}},
{364,{384,402,383,0}},	{0,{386,402,382,0}},	{0,{387,402,389,0}},
{0,{397,369,0,0}},	{364,{373,369,0,0}},	{0,{0,400,0,0}},
{364,{0,358,308,0}},	{0,{0,399,0,0}},	{0,{399,356,399,0}},
{0,{399,400,0,0}},	{364,{400,375,0,0}},	{0,{0,377,0,0}},
{0,{399,378,317,0}},	{406,{399,400,0,0}},	{413,{0,350,300,0}},
{0,{0,350,0,0}},	{0,{0,348,0,0}},	{406,{397,368,0,0}},
{413,{0,367,0,0}},	{413,{0,354,0,0}},	{0,{0,393,0,0}},
{0,{387,364,0,0}},	{364,{0,342,0,0}},	{0,{385,379,0,0}},
{364,{0,378,0,0}},	{0,{0,378,0,0}},	{0,{385,378,303,0}},
{364,{0,0,0,0}},	{406,{0,0,0,0}},	{413,{0,0,0,0}},
{0,{385,386,387,0}},	{0,{387,385,388,0}},	{0,{388,384,389,0}},
{0,{389,390,388,0}},	{0,{390,391,392,0}},	{0,{389,390,392,0}},
{0,{388,392,393,0}},	{0,{393,394,389,0}},	{0,{0,393,389,0}},
{0,{0,393,388,0}},	{0,{393,394,395,0}},	{0,{0,393,380,0}},
{0,{394,395,379,0}},	{0,{395,391,383,0}},	{0,{0,390,383,0}},
{0,{394,389,382,0}},	{0,{0,391,383,0}},	{0,{393,387,379,0}},
{0,{0,389,379,0}},	{0,{389,385,378,0}},	{0,{391,382,385,0}},
{0,{0,381,370,0}},	{0,{390,380,369,0}},	{0,{0,379,373,0}},
{0,{0,378,375,0}},	{0,{375,377,371,0}},	{0,{0,0,371,0}},
{0,{385,0,370,0}},	{0,{0,0,371,0}},	{0,{384,384,385,0}},
{0,{383,383,385,0}},	{0,{385,0,386,0}},	{0,{386,386,387,0}},
{0,{0,0,384,0}},	{0,{386,386,387,0}},	{0,{385,385,382,0}},
{0,{386,384,381,0}},	{0,{0,0,386,0}},	{0,{386,386,387,0}},
{0,{373,0,378,0}},	{0,{0,386,387,0}},	{0,{0,0,386,0}},
{0,{386,387,0,0}},	{0,{387,0,0,0}},	{0,{0,357,0,0}},
{0,{386,356,0,0}},	{0,{0,356,0,0}},	{0,{0,385,0,0}},
{0,{383,385,0,0}},	{0,{385,353,0,0}},	{0,{0,385,0,0}},
{0,{380,384,0,0}},	{0,{379,350,0,0}},	{0,{378,0,0,0}},
{0,{0,382,383,0}},	{0,{383,0,0,0}},	{0,{383,0,383,0}},
{0,{0,0,0,383}},	{0,{383,384,385,386}},	{0,{386,387,388,0}},
{0,{388,389,390,0}},	{0,{390,391,392,393}},	{0,{393,394,395,0}},
{0,{0,0,395,0}},	{0,{395,396,396,396}},	{0,{396,0,382,0}},
{0,{396,397,398,0}},	{0,{398,399,400,400}},	{0,{400,0,401,0}},
{0,{401,401,402,401}},	{0,{402,372,373,374}},	{0,{402,403,376,0}},
{0,{403,377,378,0}},	{0,{403,379,380,381}},	{0,{403,382,383,0}},
{0,{0,0,372,0}},	{0,{0,0,388,0}},	{0,{401,389,390,390}},
{0,{401,402,403,366}},	{0,{403,367,368,0}},	{0,{403,0,370,0}},
{0,{403,404,372,373}},	{0,{404,374,375,0}},	{0,{379,0,381,0}},
{0,{403,404,405,383}},	{0,{405,406,362,0}},	{0,{406,406,407,384}},
{0,{357,357,357,357}},	{0,{366,366,366,366}},	{0,{371,371,371,405}},
{142,{377,377,377,377}},	{0,{379,379,379,379}},	{0,{403,404,405,406}},
{0,{406,407,360,361}},	{0,{365,407,366,366}},	{0,{407,0,352,0}},
{0,{407,408,409,409}},	{0,{409,409,410,409}},	{0,{410,411,399,400}},
{0,{411,0,359,0}},	{0,{411,404,405,405}},	{0,{411,412,413,397}},
{0,{413,414,415,403}},	{0,{415,388,344,0}},	{0,{415,415,416,402}},
{0,{393,393,393,393}},	{0,{354,354,354,354}},	{142,{398,398,398,398}},
{0,{398,398,398,398}},	{0,{412,413,414,415}},	{0,{415,342,343,344}},
{0,{415,415,415,415}},	{0,{415,416,417,418}},	{0,{355,0,334,0}},
{0,{416,416,417,416}},	{0,{417,418,408,409}},	{0,{412,412,413,414}},
{0,{417,418,406,407}},	{0,{418,367,335,336}},	{0,{418,419,420,411}},
{0,{420,0,421,0}},	{0,{421,421,422,409}},	{0,{402,402,402,402}},
{142,{407,407,407,407}},	{0,{406,406,406,406}},	{0,{419,420,421,422}},
{0,{319,320,0,0}},	{0,{321,322,337,0}},	{0,{397,326,325,326}},
{0,{326,419,420,0}},	{0,{372,0,0,0}},	{0,{419,419,0,0}},
{0,{336,0,0,0}},	{0,{0,0,418,0}},	{0,{418,411,412,413}},
{0,{338,339,0,0}},	{0,{339,313,328,0}},	{0,{340,411,412,0}},
{0,{415,416,408,409}},	{0,{343,307,0,0}},	{0,{343,0,324,0}},
{0,{395,313,312,313}},	{0,{344,406,407,0}},	{0,{412,413,414,0}},
{0,{403,403,403,403}},	{142,{0,0,0,0}},	{0,{412,0,413,0}},
{0,{413,414,0,0}},	{0,{414,301,415,0}},	{0,{415,0,0,0}},
{0,{415,0,0,0}},	{0,{415,0,0,0}},	{0,{415,416,417,0}},
{0,{417,0,406,0}},	{0,{417,407,0,0}},	{0,{417,294,408,0}},
{0,{417,0,0,0}},	{0,{417,0,0,0}},	{0,{417,410,418,0}},
{0,{418,0,400,0}},	{0,{418,401,0,0}},	{0,{322,0,402,0}},
{0,{417,0,0,0}},	{0,{417,0,418,0}},	{0,{0,327,0,0}},
{0,{0,0,0,417}},	{0,{417,0,393,0}},	{0,{395,282,297,0}},
{0,{416,400,401,0}},	{0,{416,0,390,0}},	{0,{402,279,294,0}},
{0,{415,0,0,0}},	{204,{415,416,417,418}},	{0,{418,419,420,0}},
{0,{420,421,290,0}},	{0,{413,413,415,415}},	{0,{420,416,421,0}},
{0,{421,421,422,423}},	{0,{423,423,424,424}},	{0,{424,413,414,0}},
{0,{424,412,284,0}},	{0,{424,411,425,0}},	{0,{425,410,411,0}},
{0,{409,409,368,0}},	{204,{424,425,426,406}},	{0,{426,0,408,0}},
{0,{426,423,404,404}},	{0,{426,0,406,0}},	{0,{412,412,411,412}},
{0,{413,413,413,413}},	{0,{424,0,403,0}},	{0,{424,0,0,0}},
{204,{424,398,397,398}},	{0,{424,0,400,0}},	{0,{396,396,396,396}},
{0,{423,0,0,0}},	{0,{423,0,397,0}},	{204,{393,393,393,393}},
{0,{402,402,402,402}},	{204,{421,391,390,391}},	{0,{421,0,393,0}},
{0,{421,0,396,0}},	{0,{421,0,391,0}},	{0,{421,422,403,0}},
{0,{422,423,389,0}},	{0,{410,420,0,0}},	{0,{408,421,387,0}},
{0,{411,418,0,0}},	{204,{408,420,381,382}},	{0,{420,0,384,0}},
{0,{414,0,396,0}},	{0,{415,0,382,0}},	{204,{418,419,398,378}},
{0,{419,0,380,0}},	{0,{419,388,388,388}},	{0,{419,0,0,0}},
{0,{419,419,419,419}},	{0,{419,419,419,419}},	{0,{419,419,419,419}},
{0,{419,0,0,0}},	{0,{419,419,419,419}},	{0,{419,420,419,419}},
{0,{0,420,0,0}},	{0,{420,420,420,420}},	{0,{420,420,420,420}},
{0,{415,415,415,415}},	{0,{419,419,419,419}},	{0,{419,419,419,419}},
{0,{419,419,419,419}},	{0,{419,419,419,419}},	{0,{419,418,418,418}},
{0,{419,0,0,0}},	{0,{419,360,0,0}},	{0,{419,419,0,0}},
{272,{419,419,419,419}},	{277,{419,419,419,420}},	{272,{420,420,420,420}},
{272,{420,421,422,421}},	{277,{422,416,416,417}},	{0,{422,422,422,422}},
{272,{422,413,422,413}},	{272,{422,417,418,417}},	{277,{418,412,422,413}},
{272,{422,410,410,410}},	{277,{422,423,422,411}},	{0,{0,423,0,0}},
{272,{412,423,412,412}},	{277,{423,420,419,408}},	{277,{407,407,407,407}},
{272,{409,409,409,409}},	{272,{421,421,421,421}},	{277,{0,0,0,0}},
{272,{0,0,0,0}},	{0,{0,419,0,0}},	{272,{403,404,419,404}},
{277,{419,0,0,0}},	{277,{418,0,419,0}},	{272,{419,414,414,414}},
{277,{419,0,419,0}},	{272,{419,419,420,419}},	{277,{420,420,420,0}},
{272,{417,417,417,417}},	{277,{419,418,418,0}},	{272,{415,415,419,415}},
{272,{419,420,420,420}},	{272,{419,419,419,419}},	{272,{419,420,0,0}},
{0,{418,0,0,0}},	{272,{419,420,0,0}},	{0,{420,420,420,0}},
{272,{0,418,0,0}},	{0,{419,418,418,0}},	{272,{419,420,0,0}},
{272,{0,420,0,0}},	{0,{420,0,0,0}},	{322,{0,0,0,0}},
{272,{409,419,0,0}},	{0,{419,0,0,0}},	{272,{0,419,0,0}},
{0,{0,0,0,419}},	{0,{419,420,421,0}},	{358,{421,422,423,423}},
{0,{423,424,425,425}},	{358,{425,421,421,421}},	{0,{0,425,0,0}},
{0,{425,426,0,0}},	{358,{426,427,418,418}},	{0,{0,427,0,0}},
{0,{427,428,427,427}},	{358,{428,429,429,429}},	{0,{429,430,411,0}},
{358,{430,412,431,413}},	{0,{431,432,415,415}},	{358,{428,411,429,411}},
{0,{0,431,0,0}},	{358,{426,418,427,409}},	{0,{0,430,0,0}},
{0,{430,431,432,418}},	{358,{432,420,433,420}},	{0,{433,0,0,0}},
{0,{433,434,401,0}},	{358,{403,402,403,403}},	{0,{421,404,405,405}},
{358,{401,401,401,401}},	{0,{0,431,0,0}},	{358,{413,413,413,413}},
{0,{401,401,401,401}},	{0,{408,408,408,408}},	{0,{428,392,393,0}},
{358,{428,429,430,430}},	{0,{430,396,397,397}},	{358,{426,428,428,428}},
{358,{425,429,427,427}},	{0,{429,403,402,402}},	{0,{429,406,387,0}},
{358,{429,423,430,424}},	{358,{428,423,429,423}},	{0,{0,0,429,0}},
{358,{426,423,427,421}},	{0,{428,429,430,396}},	{358,{419,418,419,419}},
{358,{418,418,418,418}},	{0,{411,378,379,0}},	{358,{394,427,395,395}},
{0,{427,428,0,0}},	{358,{392,428,393,393}},	{358,{428,424,405,392}},
{0,{428,429,0,0}},	{358,{426,390,403,390}},	{358,{425,424,402,389}},
{0,{427,418,428,385}},	{358,{387,419,387,387}},	{0,{423,420,0,0}},
{358,{426,427,0,0}},	{358,{425,0,0,0}},	{358,{424,426,0,0}},
{0,{0,426,0,0}},	{358,{426,423,427,0}},	{358,{425,0,426,0}},
{358,{424,422,425,0}},	{0,{425,426,427,0}},	{358,{427,0,423,0}},
{358,{0,418,0,0}},	{358,{0,0,0,0}},	{419,{425,426,0,0}},
{358,{426,415,427,0}},	{0,{427,0,0,0}},	{419,{427,427,0,0}},
{0,{427,427,427,427}},	{432,{0,427,0,0}},	{0,{427,412,0,0}},
{419,{427,419,0,0}},	{358,{427,428,412,0}},	{0,{428,428,428,0}},
{419,{428,420,0,0}},	{358,{424,0,409,0}},	{0,{427,427,427,419}},
{432,{427,419,0,0}},	{358,{421,403,406,0}},	{0,{426,403,0,0}},
{358,{426,0,404,0}},	{0,{426,420,427,0}},	{419,{427,408,0,0}},
{0,{427,0,0,0}},	{0,{427,398,428,0}},	{0,{0,0,428,0}},
{358,{413,394,398,0}},	{0,{427,395,0,0}},	{358,{427,0,0,0}},
{432,{415,427,0,0}},	{419,{427,400,0,0}},	{358,{427,389,393,0}},
{358,{426,0,392,0}},	{358,{425,388,391,0}},	{358,{425,0,390,0}},
{358,{425,0,0,0}},	{358,{425,385,0,0}},	{0,{425,0,0,0}},
{0,{425,0,0,0}},	{358,{400,425,385,0}},	{0,{425,0,0,0}},
{0,{425,0,0,0}},	{0,{425,0,0,0}},	{358,{425,0,0,0}},
{0,{425,426,426,0}},	{0,{0,426,427,0}},	{0,{318,318,427,318}},
{477,{427,428,429,0}},	{0,{0,0,424,0}},	{477,{428,429,427,0}},
{0,{0,0,429,0}},	{477,{0,0,425,0}},	{0,{428,0,427,0}},
{0,{325,325,428,325}},	{0,{428,429,430,0}},	{0,{430,430,430,309}},
{477,{0,430,0,0}},	{477,{0,0,0,0}},	{0,{429,429,429,320}},
{477,{429,430,0,0}},	{0,{0,430,0,0}},	{0,{303,303,303,303}},
{0,{316,316,316,316}},	{0,{428,429,428,428}},	{0,{429,429,429,429}},
{477,{0,421,411,0}},	{0,{414,0,428,0}},	{0,{428,428,428,428}},
{0,{423,423,423,423}},	{0,{0,0,427,0}},	{0,{421,427,421,421}},
{0,{0,400,0,0}},	{0,{408,0,0,0}},	{0,{0,0,425,0}},
{0,{425,0,424,0}},	{0,{425,0,423,0}},	{0,{425,0,0,0}},
{0,{425,0,0,0}},	{0,{425,0,426,0}},	{0,{426,0,427,0}},
{0,{0,0,427,0}},	{0,{427,0,0,0}},	{0,{419,0,425,0}},
{0,{426,0,0,0}},	{0,{0,426,0,0}},	{0,{417,425,0,0}},
{0,{0,0,425,0}},	{0,{387,0,0,0}},	{0,{424,0,0,0}},
{0,{0,0,424,0}},	{0,{424,0,0,0}},	{0,{0,321,0,0}},
{0,{272,423,272,272}},	{0,{271,423,271,271}},	{0,{423,423,423,0}},
{0,{304,304,304,304}},	{0,{422,0,0,0}},	{0,{0,422,0,0}},
{0,{0,422,0,0}},	{0,{422,0,0,0}},	{0,{0,0,0,422}},
{0,{422,423,424,425}},	{0,{425,426,427,428}},	{0,{428,429,429,430}},
{0,{430,428,428,431}},	{45,{431,431,431,431}},	{45,{431,431,431,431}},
{0,{431,431,431,431}},	{0,{431,431,431,431}},	{0,{431,431,431,431}},
{57,{0,0,0,431}},	{0,{431,432,432,433}},	{0,{433,433,434,435}},
{0,{435,436,435,437}},	{0,{432,432,432,437}},	{45,{437,437,437,437}},
{45,{437,437,437,437}},	{0,{437,437,437,437}},	{88,{0,0,0,0}},
{0,{436,436,437,438}},	{0,{436,436,436,437}},	{0,{437,437,437,437}},
{0,{437,437,437,437}},	{0,{437,437,437,0}},	{57,{0,0,0,0}},
{0,{436,0,437,438}},	{0,{438,0,439,440}},	{0,{437,0,0,439}},
{107,{439,439,439,439}},	{0,{409,439,409,409}},	{0,{439,0,0,0}},
{115,{438,0,0,0}},	{0,{438,439,440,441}},	{45,{441,441,441,442}},
{45,{403,403,403,442}},	{0,{442,442,442,442}},	{0,{442,407,407,408}},
{45,{442,442,442,442}},	{0,{423,0,442,428}},	{0,{442,443,444,445}},
{0,{387,388,445,390}},	{0,{390,391,391,445}},	{45,{445,445,445,445}},
{0,{445,445,445,445}},	{0,{399,399,399,400}},	{0,{400,400,401,444}},
{45,{444,444,444,444}},	{0,{444,445,433,446}},	{0,{416,444,432,446}},
{0,{415,443,0,446}},	{0,{446,447,0,0}},	{0,{447,447,447,447}},
{0,{417,440,0,0}},	{115,{416,439,0,0}},	{0,{402,445,402,403}},
{0,{445,416,370,371}},	{0,{445,372,373,446}},	{0,{446,375,375,376}},
{0,{446,374,374,377}},	{0,{446,384,384,385}},	{0,{385,385,386,446}},
{0,{395,395,395,446}},	{0,{446,446,446,446}},	{0,{446,447,399,0}},
{0,{447,0,416,448}},	{0,{446,0,0,0}},	{0,{447,0,0,0}},
{115,{446,0,0,0}},	{0,{432,403,404,405}},	{0,{432,359,360,445}},
{0,{0,0,0,445}},	{0,{445,439,409,0}},	{0,{445,410,411,412}},
{0,{428,355,412,445}},	{0,{429,358,358,412}},	{0,{444,417,405,445}},
{0,{435,416,404,445}},	{0,{434,415,0,445}},	{0,{0,419,0,0}},
{0,{434,413,0,0}},	{115,{433,412,0,0}},	{0,{442,443,444,445}},
{0,{445,346,347,348}},	{0,{445,349,349,446}},	{0,{446,348,348,351}},
{0,{420,358,358,366}},	{0,{370,370,370,349}},	{0,{444,445,446,0}},
{0,{446,444,445,0}},	{0,{445,443,443,0}},	{0,{445,0,0,0}},
{115,{444,0,0,0}},	{0,{444,432,445,446}},	{0,{434,335,336,446}},
{0,{446,388,389,447}},	{0,{432,333,390,335}},	{0,{347,347,347,355}},
{0,{445,446,447,448}},	{0,{437,394,382,423}},	{0,{436,393,0,423}},
{0,{396,397,446,0}},	{0,{337,446,447,337}},	{0,{433,390,0,0}},
{115,{432,389,0,0}},	{0,{445,420,446,422}},	{0,{446,327,324,330}},
{0,{445,326,326,329}},	{0,{445,325,325,328}},	{45,{0,0,0,0}},
{0,{444,444,444,444}},	{0,{0,0,370,0}},	{115,{0,0,0,0}},
{0,{437,412,425,426}},	{0,{441,369,370,428}},	{0,{437,318,371,321}},
{0,{0,0,365,405}},	{0,{0,0,364,405}},	{0,{0,0,0,405}},
{0,{437,437,437,438}},	{0,{438,438,438,0}},	{0,{438,438,438,438}},
{0,{438,438,438,438}},	{0,{438,438,438,438}},	{57,{0,0,438,0}},
{0,{438,438,438,0}},	{0,{327,327,327,327}},	{0,{437,437,0,0}},
{190,{0,437,438,0}},	{0,{0,0,437,0}},	{193,{0,0,436,437}},
{0,{437,437,437,438}},	{0,{343,343,343,343}},	{0,{437,437,437,437}},
{0,{437,437,437,0}},	{0,{345,345,345,345}},	{190,{0,0,430,436}},
{193,{0,436,429,430}},	{0,{436,436,436,436}},	{0,{349,349,349,349}},
{0,{351,351,351,351}},	{199,{0,0,0,0}},	{198,{0,433,0,425}},
{0,{433,433,433,433}},	{0,{433,433,433,434}},	{190,{0,420,434,0}},
{0,{434,434,434,435}},	{0,{435,435,435,0}},	{0,{435,435,435,435}},
{0,{435,435,435,435}},	{0,{435,435,435,435}},	{0,{435,435,435,435}},
{214,{435,435,436,436}},	{0,{436,436,436,436}},	{218,{0,0,0,0}},
{0,{435,435,435,435}},	{0,{435,435,435,435}},	{214,{435,435,435,435}},
{218,{435,435,435,435}},	{0,{435,435,435,435}},	{88,{435,435,435,435}},
{0,{434,434,434,434}},	{0,{434,434,434,434}},	{0,{434,434,434,434}},
{214,{434,434,434,434}},	{0,{434,434,434,434}},	{0,{434,423,423,423}},
{226,{0,0,0,0}},	{227,{433,433,433,433}},	{0,{433,433,433,433}},
{0,{433,433,433,433}},	{0,{433,433,414,414}},	{214,{433,433,433,434}},
{0,{434,434,434,434}},	{214,{434,434,434,434}},	{214,{0,0,0,0}},
{0,{433,0,0,0}},	{0,{433,433,433,433}},	{214,{433,433,433,433}},
{238,{0,0,0,0}},	{214,{0,432,0,0}},	{0,{432,432,432,432}},
{214,{432,432,432,432}},	{214,{432,432,432,432}},	{214,{325,325,325,325}},
{0,{431,0,0,0}},	{0,{0,0,0,431}},	{227,{431,431,431,431}},
{0,{0,0,0,431}},	{0,{431,431,431,431}},	{214,{431,431,431,432}},
{0,{432,411,411,411}},	{0,{432,432,432,432}},	{214,{412,412,432,413}},
{0,{432,432,403,403}},	{0,{0,0,0,432}},	{0,{432,0,0,0}},
{0,{432,0,0,0}},	{0,{432,433,434,0}},	{0,{434,434,434,434}},
{0,{434,0,0,0}},	{0,{434,0,435,0}},	{0,{435,0,434,0}},
{0,{0,0,0,435}},	{0,{435,0,432,0}},	{0,{435,426,436,0}},
{0,{436,437,0,0}},	{0,{437,436,0,0}},	{0,{437,424,424,0}},
{0,{437,0,0,0}},	{0,{436,437,0,0}},	{0,{0,0,437,0}},
{0,{437,437,437,437}},	{0,{437,437,437,437}},	{0,{437,438,438,438}},
{0,{438,438,438,439}},	{0,{438,438,438,438}},	{0,{438,0,0,0}},
{0,{438,0,439,440}},	{0,{437,0,438,0}},	{0,{436,0,439,440}},
{0,{432,432,432,440}},	{0,{440,0,0,0}},	{0,{440,441,429,429}},
{0,{432,0,433,441}},	{0,{428,441,428,429}},	{0,{425,426,426,441}},
{0,{441,442,443,427}},	{0,{426,441,426,426}},	{0,{442,0,0,0}},
{0,{426,0,427,442}},	{0,{442,438,439,423}},	{0,{420,420,420,420}},
{0,{0,441,0,0}},	{0,{422,0,425,441}},	{0,{0,0,0,430}},
{0,{0,440,0,0}},	{0,{440,440,440,430}},	{0,{0,0,440,0}},
{0,{440,0,418,0}},	{0,{439,0,419,420}},	{0,{0,439,0,0}},
{0,{255,438,0,0}},	{0,{436,0,416,0}},	{0,{435,0,437,0}},
{0,{434,0,0,0}},	{0,{436,436,436,436}},	{312,{436,436,436,437}},
{0,{0,0,0,437}},	{312,{0,0,0,435}},	{0,{0,436,0,0}},
{0,{436,435,436,0}},	{0,{436,0,0,0}},	{0,{436,436,436,436}},
{321,{435,435,435,435}},	{0,{432,0,432,0}},	{312,{434,434,434,428}},
{0,{434,434,434,434}},	{312,{434,434,434,426}},	{0,{434,434,434,434}},
{0,{434,435,436,0}},	{0,{436,437,438,439}},	{0,{439,440,441,0}},
{0,{441,442,443,443}},	{0,{443,444,445,445}},	{0,{445,446,0,0}},
{0,{446,0,0,447}},	{0,{447,448,0,0}},	{0,{448,0,0,0}},
{0,{448,436,437,437}},	{0,{448,448,448,448}},	{0,{448,448,448,0}},
{0,{448,448,448,449}},	{0,{431,432,449,433}},	{0,{449,450,451,451}},
{0,{451,451,451,451}},	{0,{451,0,0,0}},	{0,{450,451,0,0}},
{0,{427,427,428,428}},	{0,{432,432,0,0}},	{0,{449,450,416,451}},
{0,{451,452,453,454}},	{390,{454,455,456,456}},	{394,{427,428,0,0}},
{0,{455,0,0,0}},	{0,{455,456,457,457}},	{0,{457,457,457,458}},
{0,{458,458,458,458}},	{0,{458,459,460,0}},	{0,{457,460,459,0}},
{0,{460,461,0,0}},	{403,{461,461,462,462}},	{394,{419,419,0,0}},
{404,{0,0,0,0}},	{0,{460,436,402,0}},	{0,{460,403,404,405}},
{0,{460,460,460,461}},	{0,{457,433,399,461}},	{0,{461,407,408,408}},
{0,{461,409,410,410}},	{0,{461,411,0,0}},	{0,{411,0,0,0}},
{0,{460,422,423,423}},	{0,{424,460,0,0}},	{0,{425,426,392,0}},
{390,{459,432,433,433}},	{394,{455,405,0,0}},	{0,{458,458,458,458}},
{0,{458,443,440,0}},	{0,{457,440,439,0}},	{0,{457,441,0,0}},
{0,{397,397,398,398}},	{0,{456,0,0,0}},	{0,{402,402,0,0}},
{0,{410,410,411,411}},	{390,{422,422,423,423}},	{0,{453,0,0,0}},
{0,{424,424,425,425}},	{0,{452,433,430,0}},	{0,{408,432,0,0}},
{0,{386,386,386,386}},	{0,{388,388,388,388}},	{0,{403,403,403,403}},
{0,{0,405,0,0}},	{390,{447,447,447,447}},	{394,{0,0,0,0}},
{0,{422,425,422,0}},	{0,{421,422,421,0}},	{0,{0,423,0,0}},
{403,{0,0,0,0}},	{0,{442,443,444,445}},	{0,{445,446,447,378}},
{0,{447,447,447,447}},	{0,{447,447,447,447}},	{0,{447,447,447,447}},
{0,{447,0,0,0}},	{0,{447,447,447,447}},	{0,{447,447,447,0}},
{0,{0,447,448,0}},	{438,{448,449,435,450}},	{389,{398,398,398,398}},
{0,{449,449,449,449}},	{441,{0,0,0,0}},	{438,{439,0,0,0}},
{441,{439,439,439,439}},	{438,{0,0,0,0}},	{445,{0,0,0,0}},
{389,{406,406,406,406}},	{448,{0,0,0,0}},	{450,{0,0,0,0}},
{0,{441,442,424,425}},	{0,{442,443,442,442}},	{0,{0,433,434,443}},
{0,{0,0,0,443}},	{0,{0,0,0,443}},	{445,{443,443,0,0}},
{0,{0,443,0,0}},	{0,{443,443,427,0}},	{0,{433,434,416,431}},
{389,{412,412,412,412}},	{389,{0,0,0,0}},	{0,{440,441,440,440}},
{0,{344,441,344,344}},	{0,{0,441,0,0}},	{0,{441,441,0,0}},
{0,{441,0,0,0}},	{0,{0,441,0,0}},	{468,{0,0,0,0}},
{0,{0,440,0,441}},	{0,{432,432,432,432}},	{0,{440,441,0,0}},
{0,{441,0,0,0}},	{0,{441,441,441,0}},	{0,{441,0,442,0}},
{0,{336,337,441,0}},	{0,{441,441,441,441}},	{0,{441,442,0,0}},
{0,{442,442,442,0}},	{0,{442,438,438,438}},	{0,{442,442,442,442}},
{0,{442,0,435,0}},	{0,{442,442,442,442}},	{0,{329,329,433,0}},
{0,{441,0,442,0}},	{0,{442,0,441,0}},	{0,{0,0,440,442}},
{0,{324,325,439,0}},	{0,{431,431,0,0}},	{0,{323,323,437,0}},
{0,{0,0,0,439}},	{0,{0,0,0,439}},	{0,{439,422,422,0}},
{0,{439,439,439,439}},	{0,{439,439,439,438}},	{0,{439,440,441,441}},
{0,{0,0,0,441}},	{0,{438,438,439,439}},	{0,{440,440,440,440}},
{0,{440,434,434,433}},	{0,{440,440,440,440}},	{503,{416,416,416,416}},
{503,{439,439,439,439}},	{0,{439,439,439,439}},	{503,{0,0,0,0}},
{0,{438,438,438,438}},	{0,{438,438,438,438}},	{503,{436,436,436,436}},
{0,{437,437,437,437}},	{0,{437,437,437,437}},	{503,{437,437,437,437}},
{503,{0,437,0,0}},	{0,{437,437,437,437}},	{0,{0,437,0,0}},
{0,{437,0,0,0}},	{0,{0,437,0,0}},	{0,{0,437,0,0}},
{0,{294,295,0,437}},	{0,{293,294,0,437}},	{0,{437,0,0,0}},
{0,{437,437,437,0}},	{0,{437,437,0,0}},	{0,{0,0,437,0}},
{0,{0,437,0,0}},	{0,{437,0,0,0}},	{0,{437,438,439,440}},
{0,{440,441,442,442}},	{0,{442,442,443,443}},	{0,{443,443,444,444}},
{0,{444,445,446,447}},	{0,{447,448,447,447}},	{0,{448,448,448,448}},
{0,{448,448,448,449}},	{0,{449,450,443,443}},	{0,{443,443,443,443}},
{0,{449,449,450,446}},	{0,{450,451,452,452}},	{0,{444,444,444,444}},
{0,{451,451,451,451}},	{0,{451,451,451,451}},	{0,{451,451,451,0}},
{0,{451,451,451,451}},	{0,{451,451,451,451}},	{0,{451,451,451,0}},
{0,{451,452,452,452}},	{0,{452,452,452,452}},	{0,{452,452,452,453}},
{0,{453,454,453,453}},	{0,{452,452,452,452}},	{0,{453,454,454,450}},
{0,{454,454,454,454}},	{0,{454,454,454,454}},	{0,{454,454,454,454}},
{0,{446,446,446,446}},	{0,{453,453,453,453}},	{0,{0,0,453,0}},
{0,{453,453,453,454}},	{0,{454,454,455,455}},	{0,{454,454,454,454}},
{0,{422,422,454,422}},	{0,{454,454,455,454}},	{0,{455,455,455,455}},
{0,{455,0,0,0}},	{0,{455,456,0,0}},	{101,{0,456,0,0}},
{0,{456,0,457,0}},	{0,{457,458,0,0}},	{101,{0,458,0,0}},
{0,{0,0,454,0}},	{0,{457,457,457,457}},	{0,{421,457,421,0}},
{0,{457,0,0,0}},	{0,{457,391,458,393}},	{0,{394,394,395,395}},
{0,{457,457,458,458}},	{0,{458,458,459,459}},	{0,{459,459,459,459}},
{0,{459,459,459,459}},	{0,{459,459,459,459}},	{0,{459,459,459,459}},
{0,{459,416,416,416}},	{0,{459,459,459,459}},	{101,{0,0,0,0}},
{0,{458,459,460,461}},	{0,{461,461,461,461}},	{0,{461,461,461,461}},
{0,{461,461,462,462}},	{0,{462,462,462,462}},	{0,{462,462,397,393}},
{0,{462,462,462,462}},	{0,{462,462,462,462}},	{0,{412,412,412,408}},
{0,{461,461,461,461}},	{0,{461,431,0,0}},	{0,{461,0,0,0}},
{134,{0,0,427,0}},	{135,{0,0,426,0}},	{137,{0,0,425,0}},
{0,{0,458,0,0}},	{0,{0,458,0,0}},	{0,{458,458,458,0}},
{0,{411,458,411,411}},	{0,{458,361,428,363}},	{0,{458,371,372,373}},
{0,{458,458,376,377}},	{0,{458,378,371,371}},	{0,{458,381,382,382}},
{0,{389,389,389,389}},	{0,{457,458,395,391}},	{0,{458,458,404,372}},
{0,{404,404,404,404}},	{0,{457,458,0,0}},	{0,{458,458,0,0}},
{0,{458,411,0,0}},	{0,{458,458,0,0}},	{0,{458,0,0,0}},
{0,{458,446,364,365}},	{0,{0,0,458,0}},	{0,{458,459,0,0}},
{0,{459,423,424,425}},	{0,{459,459,360,361}},	{0,{459,403,0,0}},
{134,{0,0,0,0}},	{135,{0,0,0,0}},	{137,{0,0,0,0}},
{0,{456,457,458,340}},	{0,{342,342,342,342}},	{0,{457,343,457,343}},
{0,{344,344,344,344}},	{0,{456,457,346,347}},	{0,{457,346,346,346}},
{0,{354,354,354,350}},	{0,{456,356,356,356}},	{0,{456,457,458,0}},
{0,{457,0,457,0}},	{101,{456,0,456,0}},	{0,{456,0,455,0}},
{0,{456,0,0,0}},	{0,{456,457,458,327}},	{0,{393,393,393,393}},
{0,{394,394,394,394}},	{0,{456,339,456,340}},	{0,{456,457,458,402}},
{0,{405,405,405,405}},	{0,{457,458,459,0}},	{0,{459,458,458,0}},
{101,{457,457,457,0}},	{134,{456,456,456,0}},	{0,{0,457,0,0}},
{0,{342,457,342,0}},	{0,{341,457,341,0}},	{0,{314,314,314,314}},
{0,{318,318,318,318}},	{0,{323,323,323,323}},	{0,{334,334,334,334}},
{0,{355,355,355,355}},	{0,{388,388,388,388}},	{0,{451,451,452,452}},
{0,{452,452,453,453}},	{0,{453,453,453,453}},	{0,{453,453,453,453}},
{0,{453,453,453,453}},	{0,{453,453,453,453}},	{0,{0,0,453,0}},
{0,{453,453,453,454}},	{0,{454,454,454,454}},	{0,{454,454,454,454}},
{0,{454,454,454,454}},	{194,{0,0,0,0}},	{0,{453,453,454,454}},
{0,{454,454,455,455}},	{0,{455,455,455,455}},	{0,{455,455,455,0}},
{195,{0,0,0,0}},	{0,{454,454,454,454}},	{0,{454,454,454,454}},
{0,{454,454,454,454}},	{0,{454,454,454,454}},	{0,{431,431,431,431}},
{0,{432,432,432,432}},	{0,{441,441,452,441}},	{0,{442,442,442,442}},
{0,{443,443,443,443}},	{0,{435,435,435,435}},	{0,{449,450,451,451}},
{0,{451,452,451,451}},	{0,{452,452,452,452}},	{0,{449,449,449,449}},
{0,{451,452,453,453}},	{0,{452,451,452,452}},	{0,{0,452,0,0}},
{0,{301,452,301,301}},	{0,{301,452,301,301}},	{0,{452,453,452,452}},
{0,{453,453,453,453}},	{0,{0,453,0,0}},	{0,{0,453,0,0}},
{0,{453,454,453,453}},	{0,{452,452,452,452}},	{0,{315,453,315,315}},
{0,{316,453,316,316}},	{0,{453,454,453,453}},	{0,{454,455,454,454}},
{0,{455,455,455,455}},	{0,{455,455,455,455}},	{0,{455,455,455,455}},
{0,{455,455,455,455}},	{0,{455,455,455,455}},	{0,{455,455,455,455}},
{0,{455,455,455,455}},	{0,{455,455,455,455}},	{0,{424,424,424,424}},
{0,{454,454,454,454}},	{0,{0,0,454,0}},	{0,{454,421,421,421}},
{0,{426,426,426,426}},	{0,{429,429,429,429}},	{0,{437,437,437,437}},
{0,{451,0,0,0}},	{0,{437,437,437,437}},	{0,{450,0,0,0}},
{0,{450,450,450,415}},	{0,{450,450,450,419}},	{0,{450,450,450,418}},
{0,{450,434,434,434}},	{0,{450,450,450,434}},	{0,{450,450,450,435}},
{0,{450,423,423,423}},	{0,{0,0,0,450}},	{0,{450,451,451,451}},
{0,{451,450,450,450}},	{0,{451,452,452,449}},	{0,{452,453,453,0}},
{0,{452,452,452,0}},	{0,{452,452,452,0}},	{0,{452,452,445,445}},
{0,{452,444,444,444}},	{0,{452,0,0,0}},	{0,{450,452,442,442}},
{0,{0,452,0,0}},	{0,{452,440,440,440}},	{0,{452,442,442,439}},
{0,{452,443,443,0}},	{0,{452,437,437,437}},	{0,{0,0,452,0}},
{0,{452,435,435,435}},	{0,{452,437,437,434}},	{0,{433,433,433,433}},
{0,{0,451,0,0}},	{0,{0,451,0,0}},	{0,{451,392,452,0}},
{0,{452,0,0,0}},	{0,{452,453,453,453}},	{0,{452,452,452,452}},
{0,{452,0,0,0}},	{0,{452,0,0,0}},	{0,{452,0,0,0}},
{0,{452,453,453,453}},	{0,{453,453,453,453}},	{0,{0,453,0,0}},
{0,{453,453,453,453}},	{0,{0,453,0,0}},	{0,{445,453,0,0}},
{0,{453,0,0,0}},	{0,{440,441,453,441}},	{0,{440,440,452,440}},
{0,{0,449,0,0}},	{0,{439,451,0,0}},	{0,{451,451,437,437}},
{0,{451,0,0,0}},	{0,{451,452,0,0}},	{0,{452,453,453,0}},
{0,{453,0,0,0}},	{0,{453,453,0,0}},	{0,{446,282,0,0}},
{0,{0,452,0,0}},	{0,{452,453,0,0}},	{0,{0,441,0,0}},
{0,{452,452,452,427}},	{0,{452,452,452,0}},	{0,{430,430,430,430}},
{0,{451,452,0,0}},	{0,{452,452,452,452}},	{0,{452,452,452,0}},
{0,{452,452,452,453}},	{316,{0,0,0,0}},	{0,{0,452,0,0}},
{0,{452,0,0,0}},	{0,{452,452,452,452}},	{0,{0,452,0,0}},
{0,{452,452,452,0}},	{0,{452,453,452,446}},	{0,{0,453,0,0}},
{0,{444,444,444,444}},	{0,{0,452,0,0}},	{0,{452,453,453,454}},
{0,{454,455,455,455}},	{0,{455,455,455,455}},	{0,{455,455,455,455}},
{0,{455,455,455,455}},	{0,{455,455,455,455}},	{0,{455,455,455,455}},
{0,{455,455,455,455}},	{0,{455,455,455,455}},	{0,{455,455,455,455}},
{0,{455,456,457,457}},	{0,{457,457,456,456}},	{0,{455,455,455,455}},
{0,{456,457,458,458}},	{0,{458,458,457,457}},	{0,{456,456,456,456}},
{0,{457,458,0,0}},	{0,{458,458,0,0}},	{0,{458,458,459,459}},
{0,{459,0,0,0}},	{0,{459,459,460,460}},	{0,{459,459,459,459}},
{0,{459,459,0,0}},	{0,{459,443,444,444}},	{0,{459,459,459,0}},
{0,{459,459,0,0}},	{0,{459,460,460,460}},	{0,{460,461,461,461}},
{0,{461,439,439,439}},	{0,{461,462,463,463}},	{0,{463,463,462,462}},
{0,{461,461,461,461}},	{0,{462,462,462,462}},	{0,{0,462,0,0}},
{0,{462,462,462,462}},	{0,{462,462,462,462}},	{0,{420,420,420,420}},
{0,{461,0,0,0}},	{0,{461,461,461,461}},	{0,{461,461,461,461}},
{0,{461,461,461,461}},	{0,{461,461,461,461}},	{0,{461,462,463,464}},
{0,{464,464,462,463}},	{0,{461,461,461,462}},	{0,{463,463,464,464}},
{0,{464,464,465,465}},	{0,{464,464,464,464}},	{0,{464,464,464,464}},
{0,{464,464,464,464}},	{0,{464,464,464,464}},	{0,{464,443,443,443}},
{0,{464,465,466,467}},	{400,{0,0,467,0}},	{0,{465,465,465,465}},
{400,{441,441,441,441}},	{0,{465,439,0,0}},	{400,{0,0,0,0}},
{0,{464,464,465,0}},	{0,{464,464,464,0}},	{0,{394,394,394,394}},
{0,{463,463,463,463}},	{0,{424,424,424,424}},	{0,{425,425,425,425}},
{0,{461,0,462,0}},	{0,{401,401,402,402}},	{0,{404,404,405,405}},
{0,{407,407,0,0}},	{0,{423,423,424,424}},	{0,{0,458,0,0}},
{0,{434,434,435,436}},	{0,{457,457,457,0}},	{0,{447,445,447,447}},
{0,{0,422,456,0}},	{0,{403,403,403,403}},	{0,{434,434,434,434}},
{0,{454,441,443,443}},	{0,{429,429,429,429}},	{0,{453,454,454,454}},
{0,{454,454,455,454}},	{0,{455,455,455,455}},	{0,{455,455,456,456}},
{0,{456,456,456,456}},	{0,{456,456,456,456}},	{0,{456,456,456,456}},
{0,{382,382,456,382}},	{0,{0,0,456,0}},	{0,{456,456,456,456}},
{0,{456,456,456,456}},	{0,{0,456,0,0}},	{0,{456,456,456,456}},
{0,{456,456,456,456}},	{0,{456,456,456,456}},	{0,{456,456,456,456}},
{0,{456,456,456,456}},	{0,{442,442,442,442}},	{0,{455,455,375,375}},
{0,{435,435,435,435}},	{0,{435,435,435,435}},	{0,{453,454,453,444}},
{0,{452,453,454,443}},	{0,{0,0,454,0}},	{0,{454,454,0,0}},
{0,{454,454,0,0}},	{0,{0,0,454,0}},	{0,{454,0,0,0}},
{0,{454,440,440,440}},	{0,{454,454,454,454}},	{0,{453,454,453,453}},
{0,{358,454,358,358}},	{0,{0,454,0,0}},	{0,{454,454,454,454}},
{0,{0,454,0,0}},	{0,{454,0,454,0}},	{0,{0,454,0,0}},
{0,{411,0,411,0}},	{0,{449,453,449,449}},	{0,{448,453,448,448}},
{0,{0,453,0,0}},	{0,{453,453,453,0}},	{0,{453,454,454,0}},
{0,{454,0,0,0}},	{0,{454,454,454,0}},	{0,{454,455,0,0}},
{0,{454,454,0,0}},	{481,{0,0,0,0}},	{0,{453,450,450,0}},
{0,{453,453,453,0}},	{0,{446,446,446,0}},	{0,{452,452,452,452}},
{0,{452,453,453,0}},	{0,{453,0,0,0}},	{0,{453,0,0,0}},
{0,{453,0,0,0}},	{490,{0,0,0,0}},	{491,{0,0,0,0}},
{0,{451,436,436,0}},	{0,{451,451,451,0}},	{0,{451,451,451,0}},
{0,{451,335,0,0}},	{0,{451,335,0,0}},	{0,{451,0,0,0}},
{0,{451,451,0,0}},	{0,{451,451,0,0}},	{0,{451,445,445,0}},
{0,{451,451,451,0}},	{0,{0,451,0,0}},	{0,{451,451,451,434}},
{0,{0,0,451,0}},	{0,{451,451,451,0}},	{0,{451,451,450,0}},
{0,{451,452,453,0}},	{0,{453,453,0,0}},	{0,{453,453,453,0}},
{0,{453,0,0,0}},	{0,{453,0,0,0}},	{0,{453,453,453,0}},
{0,{453,0,0,0}},	{0,{453,453,453,453}},	{0,{453,0,0,0}},
{0,{453,0,0,0}},	{0,{360,0,0,0}},	{0,{0,452,0,0}},
{0,{452,452,0,0}},	{0,{0,0,452,0}},	{0,{452,0,452,0}},
{0,{452,0,0,0}},	{0,{452,453,454,455}},	{0,{455,455,456,456}},
{0,{456,456,457,456}},	{0,{457,457,457,457}},	{0,{457,457,458,458}},
{0,{458,458,459,459}},	{0,{458,458,458,458}},	{0,{458,458,459,459}},
{0,{458,458,458,458}},	{0,{458,458,459,459}},	{0,{459,459,459,459}},
{0,{459,460,460,461}},	{0,{461,461,461,461}},	{0,{461,461,461,461}},
{0,{461,461,461,461}},	{0,{461,461,461,461}},	{0,{461,461,461,461}},
{0,{461,461,461,461}},	{0,{461,461,461,461}},	{0,{461,461,461,461}},
{0,{461,462,462,463}},	{0,{463,463,463,463}},	{0,{463,463,463,463}},
{0,{463,463,463,463}},	{0,{463,464,464,465}},	{0,{465,465,465,465}},
{0,{465,465,465,465}},	{0,{465,465,465,465}},	{0,{465,465,465,465}},
{49,{0,0,0,0}},	{0,{464,464,464,464}},	{0,{464,464,464,464}},
{0,{464,464,464,464}},	{0,{464,464,464,465}},	{0,{465,465,465,465}},
{0,{465,465,465,465}},	{0,{465,465,465,465}},	{0,{465,465,465,465}},
{0,{465,465,465,465}},	{0,{465,465,465,465}},	{0,{465,465,465,465}},
{0,{465,465,465,465}},	{0,{465,465,465,465}},	{0,{465,465,465,465}},
{0,{465,465,465,465}},	{0,{465,465,465,465}},	{0,{465,465,465,465}},
{49,{465,465,465,465}},	{0,{464,464,464,464}},	{0,{464,464,464,464}},
{0,{464,464,464,464}},	{0,{464,464,429,429}},	{0,{464,464,464,464}},
{0,{464,464,464,464}},	{0,{464,464,464,464}},	{0,{464,464,464,0}},
{0,{464,464,464,464}},	{0,{464,464,464,464}},	{0,{464,464,464,464}},
{0,{0,464,0,0}},	{105,{0,0,0,0}},	{0,{463,463,463,463}},
{0,{463,463,463,463}},	{0,{0,463,0,0}},	{0,{463,463,463,463}},
{49,{463,463,463,463}},	{0,{463,463,463,463}},	{0,{463,464,465,466}},
{0,{390,390,390,390}},	{0,{465,465,466,466}},	{0,{465,465,465,465}},
{0,{465,465,466,466}},	{0,{466,466,466,466}},	{0,{466,466,466,466}},
{0,{466,466,466,466}},	{0,{466,466,466,466}},	{0,{466,466,466,466}},
{0,{421,421,421,421}},	{0,{465,465,465,465}},	{0,{465,466,466,467}},
{0,{467,467,467,467}},	{0,{467,467,467,467}},	{0,{467,467,467,467}},
{0,{467,467,467,467}},	{0,{467,467,467,467}},	{0,{467,467,467,467}},
{0,{467,467,467,467}},	{0,{467,467,467,467}},	{0,{467,467,467,467}},
{0,{467,467,467,467}},	{0,{467,467,467,467}},	{0,{467,467,467,467}},
{0,{467,467,467,467}},	{0,{467,467,467,467}},	{0,{467,467,467,467}},
{0,{467,467,467,467}},	{0,{467,467,467,467}},	{0,{467,467,467,467}},
{0,{467,467,468,469}},	{0,{469,469,469,470}},	{143,{470,470,470,470}},
{0,{381,381,381,382}},	{0,{386,386,386,387}},	{143,{402,402,402,402}},
{143,{402,402,402,402}},	{143,{375,375,375,375}},	{0,{465,465,465,465}},
{0,{465,465,465,465}},	{0,{465,465,465,465}},	{0,{465,465,465,465}},
{143,{0,0,0,0}},	{0,{464,464,464,464}},	{143,{464,464,464,464}},
{0,{464,464,464,464}},	{0,{464,464,464,464}},	{0,{464,464,464,464}},
{0,{464,465,464,466}},	{0,{453,453,453,453}},	{0,{465,465,465,465}},
{0,{465,466,466,467}},	{0,{467,467,467,467}},	{0,{467,467,467,467}},
{0,{467,467,467,467}},	{0,{467,467,467,468}},	{0,{468,468,468,468}},
{0,{468,468,468,469}},	{0,{469,469,469,470}},	{0,{470,470,470,470}},
{0,{470,470,470,470}},	{0,{470,470,470,470}},	{0,{470,470,470,470}},
{0,{470,470,470,470}},	{0,{470,453,453,454}},	{0,{470,470,470,327}},
{0,{470,470,470,470}},	{0,{470,470,470,470}},	{0,{470,471,471,472}},
{0,{472,473,473,412}},	{0,{473,473,473,473}},	{0,{473,473,473,473}},
{0,{473,473,473,473}},	{0,{473,473,473,473}},	{0,{473,473,473,473}},
{0,{473,473,473,473}},	{49,{473,473,473,473}},	{49,{471,471,471,471}},
{0,{472,472,473,473}},	{0,{472,472,472,472}},	{0,{472,472,473,473}},
{0,{472,472,472,472}},	{0,{472,472,472,472}},	{0,{472,472,472,472}},
{0,{472,472,472,472}},	{0,{472,472,472,472}},	{0,{472,472,472,472}},
{0,{472,472,472,472}},	{0,{472,472,472,472}},	{0,{472,472,472,472}},
{0,{472,472,472,472}},	{0,{472,472,472,472}},	{0,{472,472,473,473}},
{0,{472,472,472,472}},	{0,{472,472,473,473}},	{0,{472,472,472,472}},
{0,{472,472,472,472}},	{0,{472,472,472,472}},	{0,{472,472,472,472}},
{0,{472,472,472,472}},	{0,{472,472,472,472}},	{0,{472,472,472,472}},
{0,{472,472,472,472}},	{0,{472,472,472,472}},	{0,{472,472,473,473}},
{0,{473,473,473,473}},	{0,{473,473,473,473}},	{0,{473,473,472,472}},
{0,{473,473,473,473}},	{0,{473,473,473,473}},	{0,{473,473,474,474}},
{0,{473,473,473,473}},	{0,{473,473,0,0}},	{0,{473,473,313,313}},
{0,{473,473,313,313}},	{0,{473,473,473,473}},	{0,{473,473,472,472}},
{0,{473,473,473,473}},	{0,{473,473,474,474}},	{0,{473,473,473,473}},
{0,{473,473,473,473}},	{0,{473,473,472,472}},	{0,{473,473,326,326}},
{0,{473,473,327,327}},	{0,{473,473,473,473}},	{0,{473,473,472,472}},
{0,{473,473,473,473}},	{0,{473,473,472,472}},	{0,{473,473,473,473}},
{0,{473,473,473,473}},	{0,{473,473,473,473}},	{0,{473,473,473,473}},
{0,{473,473,473,473}},	{0,{473,473,473,473}},	{0,{473,473,473,473}},
{0,{473,473,473,473}},	{0,{473,473,473,473}},	{0,{473,473,473,473}},
{0,{473,473,473,473}},	{0,{473,473,473,473}},	{0,{473,473,473,473}},
{0,{473,473,473,473}},	{0,{473,473,473,473}},	{0,{473,473,473,473}},
{0,{473,473,473,473}},	{0,{473,473,473,473}},	{0,{473,473,473,473}},
{0,{473,473,473,473}},	{0,{473,473,473,473}},	{0,{473,474,474,475}},
{0,{475,475,475,475}},	{0,{475,476,476,476}},	{0,{476,477,477,477}},
{0,{477,477,477,477}},	{0,{477,477,477,477}},	{0,{477,477,477,477}},
{0,{477,477,477,477}},	{0,{477,477,477,477}},	{0,{477,477,477,466}},
{0,{477,477,477,0}},	{0,{477,477,477,477}},	{0,{477,477,477,477}},
{0,{477,478,477,465}},	{0,{478,478,478,466}},	{0,{478,478,478,468}},
{0,{478,478,478,479}},	{0,{479,479,479,479}},	{0,{479,479,479,479}},
{0,{479,479,479,479}},	{0,{479,479,479,479}},	{0,{479,479,479,0}},
{0,{479,480,0,0}},	{0,{480,0,0,0}},	{0,{0,0,0,480}},
{0,{480,480,480,480}},	{0,{480,480,480,480}},	{0,{480,481,480,0}},
{0,{481,482,481,0}},	{0,{482,482,482,482}},	{0,{482,482,482,482}},
{0,{482,482,482,482}},	{0,{482,482,482,482}},	{0,{482,482,482,482}},
{0,{482,482,482,482}},	{0,{482,482,482,482}},	{0,{482,482,482,482}},
{0,{482,482,482,482}},	{0,{482,482,482,482}},	{0,{482,482,482,482}},
{0,{482,482,482,482}},	{0,{482,483,482,484}},	{0,{467,468,467,484}},
{0,{0,0,0,484}},	{0,{484,485,484,486}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{0,0,0,485}},	{0,{0,0,0,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{0,0,0,466}},
{0,{484,484,484,484}},	{0,{484,484,484,484}},	{0,{484,484,484,484}},
{0,{484,484,484,484}},	{0,{484,484,484,484}},	{0,{484,484,484,484}},
{0,{484,484,484,484}},	{0,{484,484,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{485,485,486,487}},
{0,{485,485,485,486}},	{0,{485,485,485,485}},	{0,{485,485,485,484}},
{0,{485,485,486,487}},	{0,{485,485,485,486}},	{0,{485,485,485,485}},
{0,{485,485,485,484}},	{0,{485,485,486,0}},	{0,{485,485,485,0}},
{0,{485,485,485,0}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,0,0}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{468,468,469,485}},	{0,{485,485,485,485}},
{0,{485,485,485,0}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{485,485,485,463}},
{0,{485,485,486,487}},	{0,{485,485,485,486}},	{0,{485,485,485,485}},
{0,{485,485,485,484}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{485,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,487,488}},	{0,{486,486,486,487}},
{0,{487,487,487,486}},	{0,{486,486,486,486}},	{0,{486,486,486,484}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,487}},
{0,{487,487,487,487}},	{0,{487,485,485,485}},	{0,{484,484,484,484}},
{0,{486,486,486,486}},	{0,{486,486,486,0}},	{0,{438,438,438,486}},
{0,{0,0,0,485}},	{0,{485,485,485,485}},	{0,{485,485,486,485}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,485}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{0,0,0,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,0,486,0}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{0,0,0,486}},
{0,{486,486,486,0}},	{0,{486,486,486,486}},	{0,{486,486,486,481}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,487,487,487}},
{0,{486,486,486,486}},	{0,{486,486,486,0}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,0}},	{0,{486,486,486,486}},
{0,{486,486,0,0}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{497,{369,369,369,0}},	{497,{369,369,369,0}},
{497,{0,0,0,0}},	{0,{483,483,483,483}},	{0,{483,483,483,483}},
{0,{483,483,483,483}},	{0,{483,483,483,483}},	{0,{483,483,483,483}},
{0,{483,483,483,483}},	{0,{483,483,484,0}},	{509,{0,0,0,0}},
{509,{483,483,483,483}},	{0,{483,483,483,484}},	{0,{482,482,482,482}},
{0,{483,483,483,483}},	{0,{483,483,483,483}},	{0,{483,483,483,483}},
{0,{483,0,0,0}},	{0,{483,483,483,483}},	{0,{483,483,483,483}},
{0,{483,483,483,483}},	{0,{483,483,483,483}},	{0,{483,483,483,483}},
{0,{483,483,483,483}},	{0,{0,0,483,0}},	{0,{483,483,483,483}},
{0,{483,483,483,483}},	{0,{0,483,0,0}},	{0,{483,484,0,0}},
{0,{484,485,486,487}},	{0,{487,488,489,490}},	{0,{490,488,488,489}},
{0,{490,491,491,492}},	{0,{492,492,493,493}},	{0,{492,492,492,492}},
{0,{492,492,492,493}},	{0,{493,491,491,492}},	{0,{491,491,491,491}},
{0,{492,493,494,494}},	{0,{494,493,493,493}},	{0,{491,491,492,492}},
{0,{491,491,491,491}},	{0,{492,492,493,493}},	{0,{492,492,492,492}},
{0,{492,492,493,494}},	{0,{492,492,492,493}},	{0,{492,492,492,492}},
{0,{492,492,492,493}},	{0,{493,493,493,494}},	{0,{494,494,494,495}},
{0,{495,495,495,496}},	{0,{496,496,496,497}},	{0,{496,496,496,496}},
{0,{496,496,496,496}},	{0,{496,496,496,495}},	{0,{496,496,496,496}},
{0,{496,496,496,497}},	{0,{496,496,496,496}},	{0,{482,482,482,482}},
{0,{483,483,483,483}},	{0,{484,484,484,484}},	{0,{485,485,485,485}},
{0,{492,492,492,491}},	{0,{492,492,492,490}},	{0,{492,492,492,492}},
{0,{492,492,492,492}},	{0,{492,492,492,492}},	{0,{492,492,492,492}},
{0,{492,492,492,492}},	{0,{492,492,492,492}},	{0,{492,492,492,492}},
{0,{492,492,492,492}},	{0,{492,492,492,492}},	{0,{492,492,492,0}},
{0,{492,493,493,494}},	{0,{492,492,492,493}},	{0,{492,492,492,492}},
{0,{492,492,492,492}},	{0,{492,492,492,493}},	{0,{492,492,492,492}},
{0,{492,492,492,492}},	{0,{492,492,492,491}},	{0,{492,492,492,489}},
{0,{492,492,492,488}},	{0,{492,492,492,492}},	{0,{492,492,492,492}},
{0,{492,492,492,492}},	{0,{492,492,492,492}},	{0,{492,492,492,0}},
{0,{492,492,492,492}},	{0,{492,492,492,493}},	{0,{492,492,492,492}},
{0,{492,492,492,492}},	{0,{492,492,492,492}},	{0,{492,491,491,491}},
{0,{492,492,492,492}},	{0,{492,492,492,0}},	{0,{492,492,492,493}},
{0,{493,493,493,494}},	{0,{494,494,0,0}},	{0,{0,494,0,0}},
{0,{489,489,489,489}},	{0,{490,490,490,490}},	{0,{0,492,0,0}},
{0,{492,492,492,492}},	{0,{492,492,492,0}},	{0,{492,492,492,492}},
{0,{407,407,408,409}},	{0,{410,410,411,412}},	{0,{410,410,410,411}},
{0,{413,413,413,414}},	{0,{488,488,489,489}},	{0,{488,488,488,488}},
{0,{488,488,489,490}},	{0,{488,488,488,489}},	{0,{488,488,488,488}},
{0,{488,488,488,488}},	{0,{488,488,488,488}},	{0,{488,488,488,488}},
{0,{488,488,488,488}},	{0,{488,488,488,488}},	{0,{488,488,488,489}},
{0,{489,489,489,490}},	{0,{490,490,490,491}},	{0,{491,491,491,491}},
{0,{491,491,491,492}},	{0,{491,491,491,491}},	{0,{491,491,491,491}},
{0,{491,491,491,491}},	{0,{491,491,491,492}},	{0,{491,491,491,491}},
{0,{491,491,491,491}},	{0,{491,491,491,421}},	{0,{491,491,491,491}},
{0,{491,491,491,491}},	{0,{491,491,491,491}},	{0,{491,491,491,454}},
{0,{491,491,491,0}},	{0,{0,0,491,0}},	{0,{491,491,491,0}},
{0,{491,0,0,0}},	{0,{442,442,442,491}},	{0,{491,491,492,378}},
{0,{491,491,491,377}},	{0,{491,491,491,380}},	{0,{491,491,491,397}},
{0,{491,491,491,398}},	{0,{491,491,491,406}},	{0,{491,491,491,492}},
{0,{492,492,492,443}},	{0,{492,492,492,0}},	{0,{489,489,489,489}},
{0,{491,491,491,491}},	{0,{491,491,491,400}},	{0,{491,491,491,0}},
{0,{491,491,491,485}},	{0,{491,491,491,436}},	{0,{491,491,492,455}},
{0,{492,492,493,454}},	{0,{493,493,494,455}},	{0,{494,494,495,480}},
{0,{495,496,496,497}},	{0,{495,495,495,496}},	{0,{496,496,496,497}},
{0,{497,497,497,364}},	{0,{497,497,497,363}},	{0,{497,369,369,369}},
{0,{497,497,497,498}},	{0,{498,498,498,499}},	{0,{499,499,499,379}},
{0,{495,495,495,495}},	{0,{496,496,496,496}},	{0,{497,497,497,497}},
{0,{497,497,497,497}},	{0,{497,497,498,499}},	{0,{499,0,499,0}},
{0,{499,499,499,0}},	{0,{494,494,494,496}},	{0,{495,495,495,495}},
{0,{497,478,478,479}},	{0,{348,348,497,348}},	{0,{497,497,497,347}},
{0,{497,497,497,371}},	{0,{497,498,498,499}},	{0,{497,497,497,498}},
{0,{498,498,498,499}},	{0,{499,431,500,431}},	{0,{430,430,499,430}},
{0,{499,499,499,429}},	{0,{499,500,499,484}},	{0,{500,501,500,0}},
{0,{0,500,0,0}},	{0,{500,501,500,0}},	{0,{501,501,501,0}},
{0,{501,0,501,0}},	{0,{501,501,502,502}},	{0,{501,501,501,501}},
{0,{501,501,502,502}},	{0,{501,501,501,501}},	{0,{501,501,501,501}},
{0,{501,501,501,501}},	{0,{501,501,501,501}},	{0,{501,501,501,501}},
{0,{501,501,0,0}},	{0,{501,501,502,502}},	{0,{501,501,501,501}},
{0,{501,501,501,501}},	{0,{501,501,501,501}},	{0,{501,501,501,501}},
{0,{501,501,502,502}},	{0,{501,501,501,501}},	{0,{501,501,502,502}},
{0,{501,501,501,501}},	{0,{501,501,501,501}},	{0,{501,501,0,0}},
{0,{501,501,501,501}},	{0,{501,501,501,501}},	{0,{501,501,501,501}},
{0,{0,0,0,501}},	{0,{501,490,490,490}},	{0,{501,502,503,503}},
{0,{503,501,502,502}},	{0,{501,500,501,501}},	{0,{500,500,500,500}},
{0,{501,501,501,501}},	{0,{501,500,500,500}},	{0,{501,501,501,501}},
{0,{501,502,502,502}},	{0,{502,501,501,501}},	{0,{500,500,500,500}},
{0,{501,0,0,0}},	{0,{501,332,332,332}},	{0,{501,332,332,332}},
{0,{501,501,501,501}},	{0,{501,500,500,500}},	{0,{501,501,501,501}},
{0,{501,502,502,502}},	{0,{501,501,501,501}},	{0,{501,501,501,501}},
{0,{501,500,500,500}},	{0,{501,345,345,345}},	{0,{501,346,346,346}},
{0,{501,501,501,501}},	{0,{501,500,500,500}},	{0,{501,501,501,501}},
{0,{501,500,500,500}},	{0,{501,501,501,501}},	{0,{501,501,501,501}},
{0,{501,501,501,501}},	{0,{501,501,501,501}},	{0,{501,501,501,501}},
{0,{501,501,501,501}},	{0,{501,501,501,501}},	{0,{501,501,501,501}},
{0,{501,501,501,501}},	{0,{501,0,0,0}},	{0,{465,467,467,467}},
{0,{500,500,500,0}},	{0,{500,500,500,0}},	{0,{500,500,500,466}},
{0,{500,501,501,469}},	{0,{500,500,500,468}},	{0,{500,500,500,485}},
{0,{500,500,500,485}},	{0,{486,486,500,486}},	{0,{500,500,500,474}},
{0,{500,500,0,0}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{0,0,500,0}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,488}},	{0,{500,500,500,0}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,0,500,0}},	{0,{500,500,500,0}},	{0,{500,0,0,0}},
{0,{500,0,0,0}},	{0,{500,0,0,0}},	{0,{500,0,0,0}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{278,{500,500,0,0}},
{278,{500,500,501,501}},	{278,{0,0,0,0}},	{278,{499,499,499,499}},
{0,{499,499,499,499}},	{0,{499,499,499,499}},	{0,{499,499,499,499}},
{0,{499,499,499,499}},	{0,{499,500,499,0}},	{0,{500,500,500,500}},
{0,{500,500,500,0}},	{0,{496,496,496,0}},	{0,{499,499,499,499}},
{0,{499,486,486,486}},	{0,{499,499,499,0}},	{0,{484,499,484,484}},
{278,{499,0,0,0}},	{278,{499,485,485,485}},	{0,{497,0,0,0}},
{0,{498,0,0,0}},	{0,{498,498,0,0}},	{278,{0,498,0,0}},
{278,{480,498,480,480}},	{0,{0,496,0,0}},	{0,{497,497,497,0}},
{0,{497,497,497,0}},	{0,{0,497,0,0}},	{0,{0,497,0,0}},
{0,{482,497,482,0}},	{0,{470,470,497,470}},	{0,{497,497,497,0}},
{0,{497,497,497,0}},	{0,{497,0,0,0}},	{0,{497,497,497,497}},
{0,{0,497,0,0}},	{0,{497,498,499,499}},	{0,{498,498,498,498}},
{0,{498,498,498,0}},	{0,{498,498,498,498}},	{0,{498,498,0,0}},
{0,{498,498,498,0}},	{0,{493,498,493,493}},	{0,{498,499,492,492}},
{0,{499,499,499,0}},	{0,{499,500,0,0}},	{0,{500,501,502,503}},
{0,{499,501,501,502}},	{0,{500,500,500,501}},	{0,{500,500,500,500}},
{0,{500,500,500,501}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{0,500,0,0}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,485,485,485}},	{0,{500,500,0,0}},	{0,{500,0,0,0}},
{0,{500,501,501,501}},	{0,{500,500,500,500}},	{0,{500,501,501,501}},
{0,{500,500,500,500}},	{0,{500,500,478,478}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,0,0,0}},	{0,{500,0,0,0}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,501}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,478}},	{0,{500,500,501,501}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{498,500,498,498}},
{0,{500,500,0,0}},	{0,{500,500,0,0}},	{0,{500,500,500,0}},
{0,{500,500,500,500}},	{0,{500,501,0,0}},	{0,{499,501,0,0}},
{0,{0,499,0,0}},	{0,{0,500,501,0}},	{0,{501,501,0,0}},
{0,{501,501,0,0}},	{0,{487,501,487,487}},	{0,{501,502,502,502}},
{0,{501,501,501,501}},	{0,{501,501,501,501}},	{0,{501,500,500,500}},
{0,{501,501,501,501}},	{0,{501,501,501,502}},	{0,{501,501,501,501}},
{0,{501,501,501,501}},	{0,{501,501,501,501}},	{0,{501,501,501,501}},
{0,{501,502,425,425}},	{0,{502,0,0,0}},	{0,{502,502,502,502}},
{0,{502,502,502,502}},	{0,{502,502,502,502}},	{0,{502,502,502,502}},
{0,{502,502,502,502}},	{0,{502,502,502,502}},	{0,{502,502,502,502}},
{0,{502,502,502,502}},	{0,{502,502,502,419}},	{0,{493,502,493,493}},
{0,{492,501,502,492}},	{0,{502,500,491,491}},	{0,{0,502,0,0}},
{0,{0,502,0,0}},	{0,{0,502,0,0}},	{0,{502,0,0,0}},
{0,{502,0,0,0}},	{0,{502,502,502,488}},	{0,{502,502,502,502}},
{0,{502,502,501,501}},	{0,{502,502,403,403}},	{0,{502,0,0,0}},
{0,{502,502,502,502}},	{0,{0,0,502,0}},	{0,{502,0,0,0}},
{0,{0,0,502,0}},	{0,{502,502,502,498}},	{0,{502,502,502,497}},
{0,{502,502,502,0}},	{0,{502,502,502,0}},	{0,{502,503,503,0}},
{0,{502,502,502,0}},	{0,{502,502,0,0}},	{0,{502,0,0,0}},
{0,{502,502,503,0}},	{0,{501,501,501,0}},	{0,{502,0,0,0}},
{0,{502,0,0,0}},	{0,{502,502,502,502}},	{0,{502,502,503,0}},
{0,{501,501,501,0}},	{0,{502,502,0,0}},	{0,{0,0,502,0}},
{0,{502,502,0,0}},	{0,{502,502,502,0}},	{0,{502,502,502,502}},
{0,{502,502,502,501}},	{0,{0,502,0,0}},	{0,{0,502,0,0}},
{0,{502,502,502,498}},	{0,{502,502,0,0}},	{0,{502,502,0,0}},
{0,{502,502,502,488}},	{0,{0,0,502,0}},	{0,{0,0,502,0}},
{0,{502,502,0,0}},	{0,{502,502,502,0}},	{0,{501,501,502,0}},
{0,{502,502,0,0}},	{0,{0,502,0,0}},	{0,{0,0,502,0}},
{0,{0,502,0,0}},	{0,{502,0,0,0}},	{0,{0,0,502,0}},
{0,{502,0,0,0}},	{0,{502,502,502,502}},	{0,{0,502,0,0}},
{0,{502,502,502,0}},	{0,{502,0,0,0}},	{0,{0,502,0,0}},
{0,{0,502,0,0}},	{0,{502,0,0,0}},	{0,{502,0,0,0}},
{0,{501,502,0,0}},	{0,{502,503,503,503}},	{0,{502,502,502,502}},
{0,{502,502,502,502}},	{0,{502,502,502,502}},	{0,{502,503,503,503}},
{0,{502,502,502,502}},	{0,{502,502,502,502}},	{0,{502,502,502,502}},
{0,{502,500,500,500}},	{0,{502,503,503,503}},	{0,{502,502,502,502}},
{0,{502,502,502,502}},	{0,{502,502,502,502}},	{0,{502,502,502,502}},
{0,{502,502,502,502}},	{0,{502,502,502,502}},	{0,{502,500,500,500}},
{0,{502,503,503,503}},	{0,{502,502,502,502}},	{0,{502,502,502,502}},
{0,{502,501,501,501}},	{0,{502,502,502,503}},	{0,{503,503,503,504}},
{0,{504,504,504,505}},	{0,{505,505,505,506}},	{0,{506,506,506,507}},
{0,{507,507,507,507}},	{0,{507,507,507,507}},	{0,{507,507,507,507}},
{0,{507,507,507,507}},	{0,{507,507,507,507}},	{0,{507,507,507,507}},
{0,{507,507,507,507}},	{0,{507,507,507,507}},	{0,{507,507,507,507}},
{0,{507,507,507,507}},	{0,{507,507,507,507}},	{0,{507,507,507,507}},
{0,{507,507,507,507}},	{0,{507,507,507,507}},	{0,{507,507,507,507}},
{0,{507,507,507,507}},	{0,{507,507,507,507}},	{0,{507,507,507,507}},
{0,{507,507,507,507}},	{0,{507,507,507,507}},	{0,{507,507,507,507}},
{0,{507,507,507,507}},	{0,{507,507,508,509}},	{0,{509,509,509,509}},
{0,{509,510,511,512}},	{0,{512,0,0,0}},	{0,{512,512,512,512}},
{0,{512,512,512,512}},	{0,{512,512,512,512}},	{0,{512,512,512,512}},
{0,{512,512,512,512}},	{0,{512,512,512,513}},	{0,{512,512,512,512}},
{0,{512,512,512,512}},	{0,{512,512,512,512}},	{0,{512,512,512,512}},
{0,{512,512,512,512}},	{0,{512,512,512,512}},	{0,{512,512,512,512}},
{0,{512,512,512,512}},	{0,{512,512,513,514}},	{85,{0,0,0,0}},
{0,{513,513,513,513}},	{0,{513,513,513,514}},	{0,{513,513,513,513}},
{0,{513,513,513,513}},	{0,{513,513,0,0}},	{0,{513,513,0,0}},
{0,{513,513,513,0}},	{0,{513,513,513,513}},	{0,{513,513,513,513}},
{0,{513,513,513,513}},	{0,{513,513,513,513}},	{0,{513,513,513,513}},
{0,{0,0,0,513}},	{0,{513,0,514,0}},	{106,{0,0,0,0}},
{0,{513,514,515,0}},	{0,{515,515,515,516}},	{0,{516,516,516,516}},
{0,{438,438,438,438}},	{0,{439,439,439,439}},	{0,{514,514,440,440}},
{0,{514,514,441,441}},	{0,{514,514,442,442}},	{0,{514,514,514,466}},
{0,{514,514,514,515}},	{0,{515,515,515,515}},	{0,{515,516,517,468}},
{0,{517,517,517,518}},	{0,{518,518,518,518}},	{0,{518,518,518,518}},
{0,{518,518,518,518}},	{0,{518,518,518,518}},	{0,{518,518,518,518}},
{0,{518,518,518,518}},	{0,{518,518,518,518}},	{0,{518,518,518,518}},
{0,{518,518,518,518}},	{0,{518,518,518,518}},	{0,{518,518,518,518}},
{0,{518,518,518,518}},	{0,{518,518,518,518}},	{0,{518,518,518,436}},
{0,{518,518,518,518}},	{0,{518,518,518,519}},	{0,{519,519,519,0}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,0}},	{0,{519,519,519,519}},	{0,{519,0,0,0}},
{0,{464,464,464,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,518}},
{0,{519,519,519,519}},	{0,{519,519,519,518}},	{0,{519,519,519,519}},
{0,{519,519,519,518}},	{0,{519,519,519,519}},	{0,{519,518,519,518}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,369,369,369}},
{0,{519,519,519,519}},	{0,{519,375,375,376}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,518,518}},	{0,{519,519,519,519}},
{0,{519,0,519,0}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{353,353,519,353}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,450,450,450}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,519,519}},
{173,{518,518,518,518}},	{0,{518,518,518,518}},	{173,{0,0,0,0}},
{0,{517,517,517,517}},	{173,{516,516,516,516}},	{0,{516,516,516,516}},
{0,{516,516,516,516}},	{0,{516,517,518,519}},	{0,{519,520,521,522}},
{0,{522,522,522,523}},	{0,{523,523,523,524}},	{0,{524,524,524,524}},
{0,{524,524,369,369}},	{0,{524,524,524,524}},	{0,{524,525,526,0}},
{0,{526,526,526,526}},	{0,{526,527,526,526}},	{0,{525,525,525,525}},
{0,{526,526,0,0}},	{0,{0,0,526,0}},	{0,{526,526,526,526}},
{0,{526,526,511,505}},	{0,{526,526,512,508}},	{0,{526,526,509,509}},
{0,{526,526,510,510}},	{0,{526,527,430,0}},	{0,{0,527,0,0}},
{0,{0,527,0,0}},	{0,{527,527,527,527}},	{0,{527,527,527,527}},
{0,{0,0,0,527}},	{0,{527,528,515,515}},	{0,{528,529,529,529}},
{0,{529,529,528,528}},	{0,{527,527,527,527}},	{210,{526,526,526,526}},
{0,{527,527,527,527}},	{210,{526,526,526,526}},	{0,{526,526,526,526}},
{0,{526,526,527,528}},	{0,{525,525,526,526}},	{210,{524,524,525,525}},
{210,{0,0,0,0}},	{210,{340,341,342,343}},	{210,{343,0,0,0}},
{0,{523,523,524,525}},	{210,{522,522,523,524}},	{0,{524,524,524,524}},
{210,{524,524,524,524}},	{0,{523,523,523,523}},	{0,{523,523,523,523}},
{210,{522,522,522,522}},	{210,{357,357,0,0}},	{210,{358,358,358,0}},
{0,{520,520,0,0}},	{210,{519,519,0,0}},	{0,{519,353,0,0}},
{210,{518,352,0,0}},	{0,{518,518,518,518}},	{0,{518,518,518,518}},
{0,{518,518,518,518}},	{0,{518,518,518,519}},	{0,{519,519,519,518}},
{0,{519,519,519,519}},	{0,{519,519,519,519}},	{0,{519,519,520,520}},
{0,{520,520,520,521}},	{0,{521,521,521,521}},	{241,{0,0,0,0}},
{242,{0,0,0,0}},	{0,{519,519,519,519}},	{0,{519,520,521,521}},
{0,{519,519,520,520}},	{0,{520,520,520,520}},	{0,{520,520,520,520}},
{0,{520,504,504,505}},	{0,{520,520,520,520}},	{0,{520,520,0,0}},
{0,{520,520,520,520}},	{0,{520,520,520,520}},	{0,{520,520,520,520}},
{0,{520,520,520,520}},	{0,{520,520,520,520}},	{0,{520,520,520,520}},
{0,{520,520,520,520}},	{0,{520,520,520,520}},	{0,{520,520,520,520}},
{0,{520,520,520,520}},	{0,{520,520,520,520}},	{0,{0,520,0,0}},
{0,{520,520,520,520}},	{0,{520,520,520,520}},	{0,{520,520,520,520}},
{0,{520,520,520,520}},	{0,{520,520,520,520}},	{0,{520,520,520,520}},
{0,{520,520,520,520}},	{0,{520,520,520,520}},	{0,{520,520,520,520}},
{0,{520,520,520,520}},	{0,{520,520,520,520}},	{0,{520,520,520,520}},
{0,{520,520,520,520}},	{0,{520,520,520,520}},	{0,{520,520,520,520}},
{0,{520,520,520,0}},	{0,{520,0,0,521}},	{0,{0,0,0,520}},
{0,{518,0,0,0}},	{0,{519,519,0,0}},	{0,{519,519,519,519}},
{0,{519,519,519,519}},	{279,{0,0,0,0}},	{279,{518,518,518,518}},
{0,{517,517,517,517}},	{0,{517,517,517,517}},	{0,{517,517,517,517}},
{0,{517,517,517,517}},	{0,{517,517,517,517}},	{284,{0,0,0,0}},
{284,{0,516,0,0}},	{0,{516,516,516,516}},	{288,{0,0,0,0}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{515,515,0,0}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{515,515,515,516}},	{0,{516,516,516,0}},	{297,{0,0,0,0}},
{297,{499,499,499,499}},	{0,{514,514,514,514}},	{299,{0,0,0,0}},
{0,{0,0,0,513}},	{0,{0,513,0,0}},	{288,{0,512,0,0}},
{0,{512,512,512,512}},	{0,{512,512,512,512}},	{0,{512,512,512,512}},
{0,{512,512,512,513}},	{0,{513,513,513,513}},	{0,{513,513,513,0}},
{0,{513,513,513,514}},	{0,{514,512,512,513}},	{0,{511,511,511,511}},
{317,{0,0,0,0}},	{0,{512,512,512,512}},	{0,{512,512,512,512}},
{0,{512,512,512,512}},	{0,{508,506,506,506}},	{0,{505,505,505,511}},
{0,{506,504,504,510}},	{0,{510,510,510,510}},	{327,{0,0,0,0}},
{328,{0,0,0,0}},	{0,{508,508,509,509}},	{0,{509,509,510,510}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{509,509,509,509}},
{0,{509,510,510,510}},	{0,{510,511,511,511}},	{0,{511,0,0,0}},
{0,{511,512,512,512}},	{0,{512,512,512,512}},	{0,{512,512,512,512}},
{0,{512,512,512,512}},	{0,{512,512,512,512}},	{0,{502,502,502,502}},
{0,{503,503,503,503}},	{0,{505,505,505,505}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{0,{509,0,0,0}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{496,0,0,509}},
{0,{509,0,0,0}},	{0,{0,0,509,0}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{509,509,509,509}},
{0,{509,510,510,0}},	{0,{510,510,510,510}},	{0,{510,510,510,510}},
{0,{510,510,510,510}},	{0,{510,510,510,510}},	{0,{510,510,510,510}},
{0,{510,510,510,510}},	{0,{510,510,510,510}},	{0,{510,510,510,510}},
{0,{510,510,510,510}},	{0,{510,510,510,510}},	{0,{510,510,510,510}},
{0,{510,510,510,510}},	{0,{510,510,510,510}},	{0,{510,510,510,510}},
{0,{510,510,510,510}},	{0,{510,510,510,510}},	{393,{510,510,510,510}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{0,{509,509,509,509}},	{0,{509,509,509,509}},
{0,{509,509,509,509}},	{393,{0,0,0,0}},	{0,{508,508,508,508}},
{0,{508,0,0,0}},	{0,{0,0,508,0}},	{0,{508,509,510,508}},
{0,{0,510,0,0}},	{0,{510,0,0,0}},	{0,{510,510,510,510}},
{0,{510,510,510,510}},	{0,{510,510,510,510}},	{0,{510,510,511,512}},
{0,{510,510,510,511}},	{0,{511,511,511,512}},	{0,{512,512,512,513}},
{0,{513,513,513,0}},	{0,{513,513,513,514}},	{0,{514,514,514,0}},
{0,{514,514,514,514}},	{0,{514,514,514,514}},	{0,{514,514,514,514}},
{0,{514,515,0,0}},	{0,{515,514,0,0}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{498,498,498,498}},	{0,{514,514,514,514}},
{0,{514,514,514,514}},	{0,{0,0,0,514}},	{0,{514,514,514,514}},
{0,{514,514,514,493}},	{0,{514,514,514,494}},	{0,{514,514,514,514}},
{0,{514,506,506,506}},	{0,{514,514,514,514}},	{0,{514,514,514,514}},
{455,{0,0,0,0}},	{457,{0,0,0,0}},	{458,{0,0,0,0}},
{0,{511,511,511,511}},	{0,{0,0,0,511}},	{0,{511,511,511,511}},
{0,{511,512,512,0}},	{0,{512,513,511,0}},	{0,{513,514,0,0}},
{0,{514,514,514,514}},	{0,{514,514,514,514}},	{0,{514,514,514,514}},
{0,{0,0,0,514}},	{0,{514,0,0,0}},	{0,{514,514,514,514}},
{0,{514,514,514,514}},	{0,{514,514,514,514}},	{0,{514,514,514,514}},
{0,{514,515,515,515}},	{0,{515,0,0,0}},	{0,{515,515,515,515}},
{0,{515,0,0,0}},	{0,{515,515,515,515}},	{0,{515,514,514,514}},
{0,{512,515,0,0}},	{0,{515,0,0,0}},	{0,{515,0,0,0}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{498,{0,0,0,0}},
{0,{514,514,514,514}},	{0,{514,514,514,514}},	{0,{514,514,0,0}},
{0,{514,514,514,514}},	{0,{514,0,0,0}},	{0,{0,0,514,0}},
{0,{0,0,514,515}},	{510,{0,0,0,0}},	{511,{0,0,0,0}},
{512,{0,0,0,0}},	{513,{0,0,0,0}},	{0,{511,511,511,511}},
{0,{0,0,0,511}},	{0,{0,511,0,0}},	{0,{511,0,0,0}},
{0,{0,511,0,0}},	{0,{511,0,0,0}},	{0,{511,511,511,511}},
{0,{511,511,511,511}},	{0,{511,511,511,511}},	{0,{0,0,0,511}},
{0,{0,0,0,511}},	{0,{511,511,511,511}},	{0,{0,0,0,511}},
{0,{511,0,0,0}},	{0,{511,511,511,511}},	{0,{511,512,513,514}},
{0,{510,511,512,514}},	{0,{514,510,511,513}},	{0,{514,515,510,512}},
{0,{507,508,509,515}},	{0,{506,507,508,515}},	{0,{510,506,507,514}},
{0,{510,511,506,513}},	{0,{508,504,505,511}},	{0,{507,503,504,512}},
{0,{506,502,503,512}},	{0,{506,507,502,511}},	{0,{511,506,501,512}},
{0,{504,505,500,511}},	{0,{502,504,499,511}},	{0,{502,503,498,510}},
{0,{500,502,497,510}},	{0,{510,501,508,511}},	{0,{509,500,507,507}},
{0,{510,499,506,506}},	{0,{509,498,505,508}},	{0,{509,497,504,510}},
{0,{508,496,503,510}},	{0,{510,495,502,508}},	{0,{509,494,501,508}},
{0,{509,510,511,512}},	{0,{508,509,510,510}},	{0,{511,508,509,510}},
{0,{510,507,508,508}},	{0,{510,511,512,513}},	{0,{509,510,511,511}},
{0,{512,513,482,484}},	{0,{513,493,481,483}},	{0,{510,511,480,487}},
{0,{511,491,479,486}},	{0,{508,509,478,487}},	{0,{509,489,477,486}},
{0,{508,488,476,509}},	{0,{507,487,475,486}},	{0,{504,486,474,486}},
{0,{505,485,473,485}},	{0,{484,484,484,484}},	{0,{483,483,483,505}},
{0,{482,482,482,489}},	{0,{497,497,497,504}},	{0,{496,496,496,496}},
{0,{503,503,503,503}},	{0,{503,503,503,503}},	{0,{503,477,477,467}},
{0,{502,476,476,471}},	{0,{501,475,475,472}},	{0,{500,474,474,473}},
{0,{499,473,473,473}},	{0,{499,499,500,501}},	{0,{501,501,502,503}},
{0,{500,500,501,501}},	{0,{500,500,500,500}},	{0,{501,502,0,503}},
{0,{503,503,0,502}},	{0,{503,503,0,504}},	{0,{0,0,0,503}},
{0,{503,0,0,0}},	{0,{503,503,503,503}},	{0,{503,503,503,503}},
{0,{503,503,503,503}},	{0,{503,503,503,503}},	{0,{503,503,503,503}},
{0,{503,503,503,504}},	{0,{503,503,503,503}},	{0,{503,503,503,503}},
{0,{502,502,502,503}},	{0,{503,503,503,504}},	{0,{499,499,499,504}},
{0,{504,504,504,504}},	{0,{504,504,504,504}},	{0,{504,504,504,504}},
{0,{504,504,504,505}},	{0,{505,505,505,506}},	{0,{506,506,506,507}},
{0,{507,507,507,507}},	{0,{507,507,507,507}},	{0,{507,507,507,507}},
{0,{507,507,507,507}},	{0,{507,507,507,507}},	{0,{507,507,507,507}},
{0,{507,507,507,507}},	{0,{507,507,507,507}},	{0,{0,0,0,507}},
{0,{0,0,0,507}},	{0,{0,0,0,507}},	{0,{0,0,0,507}},
{0,{0,0,0,507}},	{0,{0,0,0,507}},	{0,{0,0,0,507}},
{108,{496,496,496,507}},	{108,{495,495,495,495}},	{108,{0,0,0,0}},
{0,{0,0,0,505}},	{0,{0,0,0,505}},	{0,{0,0,0,505}},
{0,{434,435,436,505}},	{0,{437,434,435,504}},	{0,{437,438,439,504}},
{0,{504,452,453,453}},	{0,{503,451,452,504}},	{0,{450,450,451,503}},
{0,{450,450,450,502}},	{0,{502,454,0,503}},	{0,{453,453,0,502}},
{0,{452,452,0,454}},	{0,{501,501,501,502}},	{0,{500,500,500,502}},
{0,{502,503,401,403}},	{0,{503,504,400,402}},	{0,{500,501,399,406}},
{0,{501,502,398,405}},	{0,{498,499,397,406}},	{0,{499,500,396,405}},
{0,{498,499,395,406}},	{0,{495,498,394,406}},	{0,{496,497,393,405}},
{0,{497,496,404,404}},	{0,{497,498,499,500}},	{0,{500,501,502,502}},
{0,{502,503,504,504}},	{0,{504,400,400,407}},	{0,{504,504,423,423}},
{0,{504,505,506,506}},	{0,{504,504,505,505}},	{0,{432,432,0,0}},
{0,{504,504,504,504}},	{0,{0,0,0,504}},	{0,{0,0,0,504}},
{0,{0,0,0,504}},	{0,{0,0,0,504}},	{0,{0,0,0,504}},
{0,{504,504,504,504}},	{0,{374,381,376,383}},	{0,{378,380,375,382}},
{0,{377,379,374,383}},	{0,{403,385,373,380}},	{0,{402,384,372,381}},
{0,{499,499,499,500}},	{0,{0,0,0,500}},	{0,{0,0,0,500}},
{0,{0,0,0,500}},	{0,{0,0,0,500}},	{0,{0,0,0,500}},
{0,{500,493,493,494}},	{0,{0,0,0,500}},	{0,{0,0,0,500}},
{0,{0,0,0,500}},	{0,{462,465,361,368}},	{0,{499,464,360,367}},
{0,{460,463,359,499}},	{0,{497,462,358,498}},	{0,{458,461,357,366}},
{0,{495,460,356,365}},	{0,{0,0,0,496}},	{0,{0,0,0,496}},
{0,{356,358,353,496}},	{0,{355,357,352,496}},	{0,{355,356,351,495}},
{0,{353,355,350,495}},	{0,{353,354,349,494}},	{0,{352,353,348,494}},
{0,{350,352,347,494}},	{0,{366,351,358,494}},	{0,{375,357,345,489}},
{0,{376,356,344,488}},	{0,{373,355,343,488}},	{0,{374,354,342,487}},
{0,{373,353,341,375}},	{0,{378,352,352,484}},	{0,{377,351,351,484}},
{0,{0,0,0,487}},	{0,{0,0,0,487}},	{0,{0,0,0,487}},
{0,{487,487,487,487}},	{0,{0,0,0,487}},	{0,{336,338,333,487}},
{0,{336,337,332,487}},	{0,{334,336,331,487}},	{0,{487,358,358,365}},
{0,{430,433,329,487}},	{0,{429,432,328,472}},	{0,{430,431,327,471}},
{0,{427,430,326,471}},	{0,{428,429,325,470}},	{0,{427,428,324,483}},
{0,{426,427,323,483}},	{0,{423,426,322,469}},	{0,{0,0,0,482}},
{0,{0,0,0,482}},	{0,{0,0,0,482}},	{0,{0,0,0,482}},
{0,{0,0,0,482}},	{0,{482,483,0,484}},	{0,{481,482,0,0}},
{0,{483,481,0,0}},	{0,{483,480,0,484}},	{0,{484,479,0,480}},
{0,{483,478,0,0}},	{0,{483,477,0,0}},	{0,{483,476,0,480}},
{0,{477,475,0,483}},	{0,{477,474,0,0}},	{0,{479,473,0,481}},
{0,{479,472,0,0}},	{0,{480,480,0,481}},	{0,{342,342,343,343}},
{0,{480,480,480,480}},	{0,{346,347,0,480}},	{0,{348,348,0,479}},
{0,{348,348,0,0}},	{0,{478,478,478,478}},	{0,{478,478,478,478}},
{0,{478,478,478,478}},	{0,{0,0,0,478}},	{0,{0,0,0,478}},
{0,{0,0,0,478}},	{0,{478,459,0,0}},	{0,{478,458,0,0}},
{0,{460,457,0,478}},	{0,{463,456,0,477}},	{0,{384,336,0,477}},
{0,{335,335,0,476}},	{0,{476,476,476,476}},	{0,{0,0,0,476}},
{0,{476,477,0,0}},	{0,{0,0,0,477}},	{0,{477,477,477,477}},
{0,{0,0,0,477}},	{0,{0,0,0,477}},	{0,{477,478,479,479}},
{0,{479,480,481,481}},	{0,{481,482,483,483}},	{0,{479,479,479,479}},
{0,{482,482,482,482}},	{0,{482,482,351,483}},	{0,{466,466,0,483}},
{0,{483,483,484,485}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{485,485,485,485}},	{0,{485,485,485,485}},
{0,{485,485,485,485}},	{0,{0,0,0,485}},	{0,{341,341,341,352}},
{0,{484,484,485,485}},	{0,{485,485,485,485}},	{0,{485,485,468,468}},
{0,{485,453,0,486}},	{0,{452,452,0,486}},	{0,{483,451,0,485}},
{0,{479,479,479,479}},	{0,{354,354,354,354}},	{0,{0,0,0,483}},
{0,{0,0,0,483}},	{0,{483,446,0,0}},	{0,{445,445,0,0}},
{0,{0,0,0,482}},	{0,{453,453,453,482}},	{0,{482,482,483,484}},
{0,{481,481,482,484}},	{0,{484,484,485,486}},	{0,{467,467,468,486}},
{0,{468,468,468,486}},	{0,{469,437,0,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,487}},	{0,{487,487,487,488}},
{0,{486,486,486,488}},	{0,{488,488,488,488}},	{0,{482,482,482,482}},
{0,{483,483,483,483}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{486,486,486,486}},	{0,{486,486,486,486}},	{0,{486,486,486,486}},
{0,{0,0,0,486}},	{0,{479,479,479,486}},	{0,{486,486,486,487}},
{0,{487,487,487,488}},	{0,{476,476,476,488}},	{0,{0,0,0,488}},
{0,{482,482,482,488}},	{0,{481,481,481,488}},	{0,{488,488,488,488}},
{0,{488,488,488,488}},	{0,{488,488,488,489}},	{0,{487,487,487,489}},
{0,{489,489,489,489}},	{0,{485,485,485,485}},	{0,{488,488,488,488}},
{0,{0,0,0,488}},	{0,{0,0,0,488}},	{0,{488,488,488,488}},
{0,{488,488,488,488}},	{0,{488,488,488,488}},	{0,{488,488,488,488}},
{0,{488,488,488,488}},	{0,{488,488,488,488}},	{0,{488,488,488,488}},
{0,{0,0,0,488}},	{0,{0,0,0,488}},	{0,{0,0,0,488}},
{0,{488,488,488,488}},	{0,{0,0,0,488}},	{0,{0,0,0,488}},
{0,{479,479,479,488}},	{0,{0,0,0,488}},	{0,{477,477,477,488}},
{0,{488,488,488,488}},	{0,{488,488,488,488}},	{0,{488,488,488,488}},
{0,{488,488,488,488}},	{0,{488,488,488,488}},	{0,{488,488,488,488}},
{0,{0,0,0,488}},	{0,{0,0,0,488}},	{0,{488,488,488,488}},
{0,{488,488,488,488}},	{0,{488,488,488,488}},	{0,{488,488,488,488}},
{0,{488,488,488,488}},	{0,{0,0,0,488}},	{0,{0,0,0,488}},
{0,{0,0,0,488}},	{0,{0,0,0,488}},	{0,{0,0,0,488}},
{0,{0,0,0,488}},	{0,{488,488,488,488}},	{0,{488,488,488,488}},
{0,{0,0,0,488}},	{0,{488,488,488,488}},	{0,{488,489,490,491}},
{0,{491,492,493,494}},	{0,{490,491,492,494}},	{0,{489,490,491,491}},
{0,{493,494,495,495}},	{0,{495,496,497,497}},	{0,{497,495,496,496}},
{0,{497,492,492,492}},	{0,{497,498,499,499}},	{0,{499,500,501,501}},
{0,{501,497,497,497}},	{0,{501,502,502,502}},	{0,{502,503,0,0}},
{0,{503,504,504,504}},	{0,{500,0,0,0}},	{0,{503,503,503,503}},
{0,{503,503,503,503}},	{0,{503,503,503,503}},	{0,{503,503,503,503}},
{0,{503,503,503,503}},	{0,{503,503,503,503}},	{0,{503,503,503,503}},
{0,{503,503,503,503}},	{0,{503,503,503,503}},	{0,{489,489,489,489}},
{0,{502,502,502,502}},	{0,{502,503,503,503}},	{0,{503,504,504,504}},
{0,{504,504,0,0}},	{0,{504,504,504,505}},	{0,{0,0,0,505}},
{0,{502,502,502,502}},	{0,{504,504,504,504}},	{0,{504,504,504,504}},
{0,{504,504,504,504}},	{0,{504,505,505,505}},	{0,{504,504,504,504}},
{0,{504,505,505,505}},	{0,{504,504,504,504}},	{0,{504,504,504,504}},
{0,{504,504,504,504}},	{0,{504,504,504,504}},	{0,{504,504,504,504}},
{0,{504,504,504,504}},	{0,{504,504,504,504}},	{0,{504,504,504,504}},
{0,{0,0,0,504}},	{0,{0,0,0,504}},	{0,{504,505,506,506}},
{0,{506,506,506,507}},	{0,{0,0,0,507}},	{0,{507,508,509,509}},
{0,{509,510,511,511}},	{0,{511,507,507,507}},	{0,{511,511,511,511}},
{0,{511,511,511,511}},	{0,{511,511,511,511}},	{0,{511,511,511,511}},
{0,{511,511,511,511}},	{0,{511,474,474,474}},	{0,{511,0,0,0}},
{0,{511,511,511,512}},	{0,{512,512,512,513}},	{0,{511,511,511,511}},
{0,{512,512,512,512}},	{0,{512,512,512,512}},	{0,{512,512,512,512}},
{0,{0,0,0,512}},	{0,{0,0,0,512}},	{0,{0,0,0,512}},
{0,{0,0,0,512}},	{0,{0,0,0,512}},	{0,{0,0,0,512}},
{0,{432,433,434,512}},	{0,{512,512,512,512}},	{0,{512,512,512,512}},
{0,{512,512,512,512}},	{0,{512,512,512,512}},	{0,{512,512,512,512}},
{0,{0,0,0,512}},	{0,{0,0,0,512}},	{0,{512,512,512,512}},
{0,{0,0,0,512}},	{0,{0,0,0,512}},	{0,{512,513,514,514}},
{0,{514,515,516,516}},	{0,{515,515,515,515}},	{0,{515,516,0,0}},
{0,{516,516,0,0}},	{0,{513,514,0,516}},	{0,{514,514,0,515}},
{0,{515,516,0,0}},	{0,{516,515,0,0}},	{0,{516,0,0,0}},
{0,{513,513,0,0}},	{0,{515,515,515,515}},	{0,{515,515,516,516}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{513,513,513,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{0,0,0,515}},
{0,{0,0,0,515}},	{0,{515,493,494,494}},	{0,{515,495,0,0}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{0,0,0,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{0,0,0,515}},	{0,{515,515,0,0}},
{0,{0,0,0,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{511,511,0,515}},	{0,{515,515,516,516}},	{0,{0,0,0,513}},
{0,{0,0,0,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{0,0,0,515}},	{0,{0,0,0,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{0,0,0,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{515,515,515,515}},
{0,{515,515,515,515}},	{0,{0,0,0,515}},	{0,{515,515,515,515}},
{0,{514,514,514,515}},	{0,{515,515,515,515}},	{0,{512,512,512,515}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{0,{0,0,0,515}},
{0,{515,515,515,515}},	{0,{515,515,515,515}},	{508,{0,0,0,0}},
{0,{514,514,514,514}},	{0,{0,0,0,514}},	{0,{514,514,514,514}},
{0,{514,514,514,514}},	{0,{514,514,514,514}},	{0,{514,514,514,514}},
{0,{0,0,0,514}},	{0,{514,514,514,514}},	{0,{0,0,0,514}},
{0,{0,0,0,514}},	{0,{0,0,0,514}},	{0,{0,0,0,514}},
{0,{0,0,0,514}},	{0,{0,0,0,514}},	{0,{0,0,0,514}},
{0,{514,515,516,0}},	{0,{516,514,517,0}},	{0,{517,518,514,0}},
{0,{518,517,513,0}},	{0,{518,516,512,0}},	{0,{518,510,511,0}},
{0,{518,509,510,0}},	{0,{518,508,511,0}},	{0,{518,512,508,0}},
{0,{518,511,507,0}},	{0,{518,510,506,0}},	{0,{518,509,505,0}},
{0,{518,503,504,0}},	{0,{518,507,503,0}},	{0,{511,506,502,0}},
{0,{517,505,501,0}},	{0,{517,499,500,0}},	{0,{517,503,499,0}},
{0,{517,497,498,0}},	{0,{517,496,497,0}},	{0,{517,500,496,0}},
{0,{517,499,495,0}},	{0,{517,493,494,0}},	{0,{517,518,0,0}},
{0,{518,517,519,0}},	{0,{517,519,0,0}},	{0,{519,518,0,0}},
{0,{519,514,0,0}},	{0,{519,513,0,0}},	{0,{0,512,514,0}},
{0,{0,514,0,0}},	{0,{517,513,0,0}},	{0,{517,488,484,0}},
{0,{484,487,483,0}},	{0,{516,486,482,0}},	{0,{516,485,481,0}},
{0,{516,484,480,0}},	{0,{516,507,0,0}},	{0,{516,506,0,0}},
{0,{516,505,0,0}},	{0,{516,480,476,0}},	{0,{516,517,518,518}},
{0,{515,517,517,517}},	{0,{517,516,516,516}},	{0,{517,518,0,0}},
{0,{516,0,0,0}},	{0,{517,0,0,0}},	{0,{517,0,0,0}},
{0,{517,0,0,0}},	{0,{517,0,0,0}},	{0,{517,0,0,0}},
{0,{517,0,518,0}},	{0,{518,0,0,0}},	{0,{518,0,0,0}},
{0,{501,0,0,0}},	{0,{517,518,0,0}},	{0,{518,517,0,0}},
{0,{518,516,0,0}},	{0,{518,515,0,0}},	{0,{518,519,0,0}},
{0,{0,518,0,0}},	{0,{515,517,0,0}},	{0,{517,516,0,0}},
{0,{0,517,0,0}},	{0,{489,516,0,0}},	{0,{488,513,0,0}},
{0,{515,512,0,0}},	{0,{515,511,0,0}},	{0,{515,510,0,0}},
{0,{515,516,490,490}},	{0,{514,515,516,489}},	{0,{516,517,0,0}},
{0,{515,516,517,0}},	{0,{517,518,0,0}},	{0,{516,517,518,0}},
{0,{518,0,0,0}},	{0,{518,468,0,0}},	{0,{499,467,0,0}},
{0,{517,466,0,0}},	{0,{480,480,480,480}},	{0,{516,516,516,479}},
{0,{516,516,516,0}},	{0,{516,0,516,0}},	{0,{0,0,0,516}},
{0,{0,0,0,516}},	{0,{0,0,0,516}},	{0,{0,0,0,516}},
{0,{0,0,0,516}},	{0,{0,0,0,516}},	{0,{0,0,0,516}},
{0,{469,469,469,516}},	{0,{0,0,0,516}},	{0,{0,0,0,516}},
{0,{0,0,0,516}},	{0,{516,450,0,0}},	{0,{516,449,0,0}},
{0,{465,516,0,0}},	{0,{516,0,0,0}},	{0,{516,0,0,0}},
{0,{516,0,0,0}},	{0,{516,0,0,0}},	{0,{515,0,488,0}},
{0,{514,0,490,0}},	{0,{514,412,413,0}},	{0,{413,411,412,0}},
{0,{513,410,411,0}},	{0,{419,409,410,0}},	{0,{512,408,409,0}},
{0,{512,407,408,0}},	{0,{512,406,407,0}},	{0,{512,410,406,0}},
{0,{512,409,405,0}},	{0,{512,429,0,0}},	{0,{512,428,0,0}},
{0,{511,430,0,0}},	{0,{511,426,0,0}},	{0,{511,425,0,0}},
{0,{510,427,0,0}},	{0,{510,402,398,0}},	{0,{510,425,0,0}},
{0,{510,511,0,0}},	{0,{511,510,0,0}},	{0,{510,511,0,0}},
{0,{511,510,0,0}},	{0,{0,0,0,511}},	{0,{0,0,0,511}},
{0,{0,0,0,511}},	{0,{0,0,0,511}},	{0,{0,0,0,511}},
{0,{511,415,0,0}},	{0,{511,414,0,0}},	{0,{511,413,0,0}},
{0,{0,0,0,511}},	{0,{0,0,0,511}},	{0,{0,0,0,511}},
{0,{0,0,0,511}},	{0,{0,0,0,511}},	{0,{511,407,0,0}},
{0,{511,0,0,0}},	{0,{0,0,0,511}},	{0,{0,0,0,511}},
{0,{511,374,375,0}},	{0,{511,378,374,0}},	{0,{0,0,0,511}},
{0,{0,0,0,511}},	{0,{511,375,371,0}},	{0,{511,374,370,0}},
{0,{511,373,369,0}},	{0,{511,372,368,0}},	{0,{511,371,367,0}},
{0,{511,370,366,0}},	{0,{0,0,0,511}},	{0,{0,0,0,511}},
{0,{0,0,0,511}},	{0,{511,511,511,511}},	{0,{0,0,0,511}},
{0,{511,364,360,0}},	{0,{511,363,359,0}},	{0,{511,362,358,0}},
{0,{511,385,0,0}},	{0,{511,360,356,0}},	{0,{511,359,355,0}},
{0,{511,358,354,0}},	{0,{0,0,0,511}},	{0,{0,0,0,511}},
{0,{0,0,0,511}},	{0,{0,0,0,511}},	{0,{0,0,0,511}},
{0,{511,394,0,0}},	{0,{0,393,374,0}},	{0,{510,0,0,0}},
{0,{510,391,0,0}},	{0,{510,390,0,0}},	{0,{510,0,0,0}},
{0,{510,388,0,0}},	{0,{510,387,0,0}},	{0,{371,386,0,0}},
{0,{371,0,0,0}},	{0,{508,0,0,0}},	{0,{508,0,0,0}},
{0,{508,0,0,0}},	{0,{508,0,0,0}},	{0,{508,0,0,0}},
{0,{0,508,0,0}},	{0,{0,508,0,0}},	{0,{0,508,0,0}},
{0,{0,0,0,508}},	{0,{0,0,0,508}},	{0,{508,374,0,0}},
{0,{508,373,0,0}},	{0,{421,0,0,0}},	{0,{507,0,0,0}},
{0,{0,507,0,0}},	{0,{0,0,0,507}},	{0,{507,368,0,0}},
{0,{0,367,0,0}},	{0,{0,0,0,506}},	{0,{506,0,0,0}},
{0,{0,0,0,506}},	{0,{0,0,0,506}},	{0,{506,362,0,0}},
{0,{506,361,0,0}},	{0,{505,0,0,0}},	{0,{505,359,0,0}},
{0,{505,358,0,0}},	{0,{504,0,0,0}},	{0,{504,356,0,0}},
{0,{504,355,0,0}},	{0,{503,0,0,0}},	{0,{503,504,505,0}},
{0,{349,348,349,349}},	{0,{504,348,348,348}},	{0,{504,0,0,0}},
{0,{0,504,0,0}},	{0,{0,504,0,0}},	{0,{501,503,0,0}},
{0,{503,343,343,343}},	{0,{503,0,0,0}},	{0,{503,504,505,0}},
{0,{505,505,0,0}},	{0,{505,0,0,0}},	{0,{0,505,0,0}},
{0,{0,0,0,505}},	{0,{486,505,0,0}},	{0,{485,505,0,0}},
{0,{505,506,0,0}},	{0,{506,487,488,0}},	{0,{0,385,0,0}},
{0,{505,506,506,0}},	{0,{506,505,505,0}},	{0,{0,0,0,506}},
{0,{0,0,0,506}},	{0,{506,330,0,0}},	{0,{0,0,0,506}},
{0,{506,0,0,0}},	{0,{324,506,324,324}},	{0,{323,506,323,323}},
{0,{506,505,322,322}},	{0,{477,504,321,321}},	{0,{0,505,0,0}},
{0,{0,505,0,0}},	{0,{475,504,0,0}},	{0,{504,487,0,0}},
{0,{504,488,0,0}},	{0,{504,490,490,0}},	{0,{504,481,0,0}},
{0,{0,0,0,504}},	{0,{504,505,506,504}},	{0,{506,504,505,503}},
{0,{502,503,506,502}},	{0,{504,502,505,501}},	{0,{505,501,504,500}},
{0,{499,499,499,499}},	{0,{498,504,500,498}},	{0,{497,503,501,497}},
{0,{496,503,496,496}},	{0,{0,503,0,0}},	{0,{0,503,0,0}},
{0,{503,0,0,0}},	{0,{492,492,492,503}},	{0,{491,492,503,491}},
{0,{503,491,502,490}},	{0,{0,503,0,0}},	{0,{503,502,0,0}},
{0,{503,487,487,487}},	{0,{503,0,0,0}},	{0,{503,486,497,485}},
{0,{503,485,496,484}},	{0,{483,489,495,483}},	{0,{0,502,0,0}},
{0,{481,481,485,481}},	{0,{501,480,484,480}},	{0,{501,479,483,479}},
{0,{501,501,501,0}},	{0,{477,484,481,477}},	{0,{0,0,0,500}},
{0,{500,0,0,0}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,501,0,0}},	{0,{0,501,0,0}},
{0,{501,501,501,501}},	{0,{497,497,0,0}},	{0,{0,0,0,500}},
{0,{0,0,0,500}},	{0,{0,0,0,500}},	{0,{0,0,0,500}},
{0,{0,0,0,500}},	{0,{0,0,0,500}},	{0,{500,492,0,0}},
{0,{0,0,0,500}},	{0,{500,490,0,0}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{500,500,500,500}},	{0,{0,500,0,0}},	{0,{500,0,0,0}},
{0,{0,0,0,500}},	{0,{500,481,0,0}},	{0,{500,500,0,0}},
{0,{500,500,500,500}},	{0,{500,500,500,500}},	{0,{500,500,500,500}},
{0,{0,0,0,500}},	{0,{0,0,0,500}},	{0,{0,0,0,500}},
{0,{0,0,0,500}},	{0,{0,0,0,500}},	{0,{0,0,0,500}},
{0,{500,0,0,0}},	{0,{500,500,0,0}},	{0,{0,0,0,500}},
{0,{500,0,0,0}},	{0,{500,501,0,0}},	{0,{501,500,0,0}},
{0,{501,499,0,0}},	{0,{501,498,0,0}},	{0,{496,0,0,0}},
{0,{497,0,0,0}},	{0,{497,0,0,0}},	{0,{497,0,0,0}},
{0,{497,0,0,0}},	{0,{497,0,0,0}},	{0,{497,0,0,0}},
{0,{497,0,0,0}},	{0,{497,0,498,0}},	{0,{498,0,497,0}},
{0,{494,0,496,0}},	{0,{497,0,495,0}},	{0,{497,0,0,0}},
{0,{497,498,0,0}},	{0,{498,497,0,0}},	{0,{498,496,0,0}},
{0,{498,495,490,0}},	{0,{498,494,489,0}},	{0,{495,493,488,0}},
{0,{497,492,0,0}},	{0,{497,498,0,0}},	{0,{497,497,0,0}},
{0,{497,0,0,0}},	{0,{497,0,0,0}},	{0,{495,0,482,0}},
{0,{0,0,481,0}},	{0,{495,495,495,496}},	{0,{496,496,496,497}},
{0,{497,497,497,494}},	{0,{497,497,497,495}},	{0,{497,497,497,497}},
{0,{491,491,491,491}},	{0,{492,492,492,492}},	{0,{495,495,490,491}},
{0,{495,495,492,490}},	{0,{495,495,489,489}},	{0,{495,496,0,0}},
{0,{496,495,0,0}},	{0,{496,0,0,0}},	{0,{496,0,0,0}},
{0,{496,0,0,0}},	{0,{491,491,0,0}},	{0,{495,490,0,0}},
{0,{495,0,0,0}},	{0,{495,495,495,0}},	{0,{495,495,495,0}},
{0,{495,0,0,0}},	{0,{495,496,0,0}},	{0,{496,495,0,0}},
{0,{496,0,0,0}},	{0,{496,0,0,0}},	{0,{496,496,476,476}},
{0,{496,496,0,0}},	{0,{496,496,496,497}},	{0,{497,497,497,496}},
{0,{497,497,497,497}},	{0,{494,494,494,494}},	{0,{496,0,0,0}},
{0,{0,0,0,496}},	{0,{0,0,0,496}},	{0,{496,0,0,0}},
{0,{496,0,0,0}},	{0,{496,0,0,0}},	{0,{496,0,0,0}},
{0,{496,0,0,0}},	{0,{496,0,0,0}},	{0,{496,445,0,0}},
{0,{496,444,0,0}},	{0,{496,443,0,0}},	{0,{496,442,437,0}},
{0,{496,441,436,0}},	{0,{493,440,435,0}},	{0,{495,439,0,0}},
{0,{495,445,0,0}},	{0,{495,495,495,450}},	{0,{495,495,495,449}},
{0,{495,495,495,0}},	{0,{495,495,495,447}},	{0,{495,454,0,0}},
{0,{495,0,0,0}},	{0,{495,452,0,0}},	{0,{495,451,0,0}},
{0,{495,0,0,0}},	{0,{495,0,0,0}},	{0,{495,459,0,0}},
{0,{495,0,0,0}},	{0,{467,495,0,0}},	{0,{0,0,0,495}},
{0,{0,0,0,495}},	{0,{0,0,0,495}},	{0,{0,0,0,495}},
{0,{0,0,0,495}},	{0,{0,0,0,495}},	{0,{495,418,0,0}},
{0,{495,0,0,0}},	{0,{495,0,0,0}},	{0,{495,0,0,0}},
{0,{495,0,0,0}},	{0,{495,0,0,0}},	{0,{0,0,0,495}},
{0,{0,0,0,495}},	{0,{495,0,0,0}},	{0,{0,0,0,495}},
{0,{0,0,0,495}},	{0,{495,496,497,0}},	{0,{497,495,496,0}},
{0,{0,391,497,0}},	{0,{492,495,494,0}},	{0,{494,494,493,0}},
{0,{0,0,494,0}},	{0,{494,492,492,0}},	{0,{494,491,491,0}},
{0,{494,0,0,0}},	{0,{494,0,0,0}},	{0,{485,488,488,0}},
{0,{487,487,487,0}},	{0,{492,486,486,0}},	{0,{492,0,0,0}},
{0,{393,393,485,0}},	{0,{491,392,0,0}},	{0,{391,391,0,0}},
{0,{490,490,490,406}},	{0,{490,490,490,0}},	{0,{490,490,488,404}},
{0,{490,0,0,0}},	{0,{490,0,0,0}},	{0,{490,0,0,0}},
{0,{416,416,0,0}},	{0,{0,0,0,489}},	{0,{0,0,0,489}},
{0,{489,472,471,0}},	{0,{489,471,471,0}},	{0,{489,386,490,0}},
{0,{490,491,491,0}},	{0,{491,0,0,0}},	{0,{491,0,0,0}},
{0,{0,0,0,491}},	{0,{491,491,491,0}},	{0,{491,405,0,0}},
{0,{491,491,491,388}},	{0,{491,491,491,0}},	{0,{491,491,491,386}},
{0,{491,491,491,0}},	{0,{491,491,491,384}},	{0,{491,491,491,0}},
{0,{0,0,0,491}},	{0,{491,0,0,0}},	{0,{491,0,0,0}},
{0,{0,491,0,0}},	{0,{491,0,0,0}},	{0,{491,0,0,0}},
{0,{491,0,0,0}},	{0,{491,0,0,0}},	{0,{491,0,491,0}},
{0,{491,492,491,491}},	{0,{0,492,0,0}},	{0,{489,489,489,489}},
{0,{491,491,491,491}},	{0,{491,491,491,0}},	{0,{491,0,0,0}},
{0,{491,0,0,0}},	{0,{491,0,0,0}},	{0,{491,491,491,0}},
{0,{0,0,0,491}},	{0,{491,491,491,491}},	{0,{491,491,491,491}},
{0,{491,491,491,491}},	{0,{491,491,491,491}},	{0,{491,491,491,491}},
{0,{491,0,475,0}},	{0,{491,0,0,0}},	{0,{491,0,473,0}},
{0,{491,0,0,0}},	{0,{491,0,471,0}},	{0,{491,491,491,491}},
{0,{491,0,491,0}},	{0,{0,0,0,491}},	{0,{491,491,491,491}},
{0,{491,491,491,491}},	{0,{491,0,491,0}},	{0,{0,491,0,0}},
{0,{491,491,491,0}},	{0,{491,0,0,0}},	{0,{491,0,0,0}},
{0,{491,0,0,0}},	{0,{0,0,0,491}},	{0,{491,0,0,0}},
{0,{491,0,0,0}},	{0,{491,0,0,0}},	{0,{491,0,491,0}},
{0,{0,0,0,491}},	{0,{0,0,0,491}},	{0,{0,0,0,491}},
{0,{0,0,0,491}},	{4,{491,492,493,492}},	{18,{493,494,493,493}},
{0,{492,492,492,492}},	{0,{493,493,494,494}},	{0,{494,490,490,490}},
{0,{492,492,494,492}},	{18,{488,488,488,488}},	{0,{493,494,494,494}},
{0,{493,493,493,493}},	{4,{493,483,484,483}},	{4,{493,482,483,482}},
{0,{486,486,486,486}},	{0,{492,493,493,493}},	{0,{492,492,492,492}},
{0,{492,493,493,493}},	{0,{492,492,492,492}},	{4,{492,476,477,476}},
{0,{492,492,492,492}},	{0,{492,479,479,479}},	{4,{492,478,478,478}},
{0,{492,477,477,477}},	{4,{492,476,476,476}},	{4,{492,475,475,475}},
{0,{492,493,474,474}},	{0,{492,492,473,473}},	{4,{492,472,472,472}},
{4,{492,0,493,0}},	{18,{0,493,0,0}},	{0,{0,0,491,0}},
{0,{492,0,0,0}},	{18,{0,0,0,0}},	{0,{491,0,488,0}},
{4,{491,0,487,0}},	{4,{490,0,0,0}},	{0,{488,0,0,0}},
{0,{489,457,458,457}},	{0,{456,456,457,456}},	{0,{488,488,472,472}},
{0,{488,488,459,459}},	{0,{488,488,0,0}},	{0,{488,488,489,488}},
{0,{487,487,487,487}},	{0,{450,450,450,450}},	{0,{487,487,487,488}},
{0,{487,488,487,487}},	{0,{486,486,486,486}},	{0,{487,484,484,485}},
{0,{487,487,487,0}},	{0,{0,472,0,0}},	{0,{486,485,485,0}},
{0,{486,0,0,0}},	{0,{486,0,0,0}},	{0,{486,487,0,0}},
{0,{487,0,0,0}},	{0,{487,0,0,0}},	{0,{487,0,0,0}},
{0,{487,0,0,0}},	{0,{487,0,0,0}},	{0,{487,488,489,489}},
{69,{489,490,489,0}},	{0,{486,486,487,487}},	{0,{489,489,486,486}},
{0,{485,485,485,485}},	{0,{0,488,0,0}},	{69,{0,0,0,0}},
{0,{487,487,482,482}},	{69,{0,0,487,0}},	{75,{480,480,480,480}},
{75,{486,486,486,479}},	{75,{486,486,486,486}},	{78,{486,487,461,461}},
{0,{485,460,460,460}},	{0,{486,459,487,459}},	{78,{487,488,0,0}},
{0,{486,0,0,0}},	{0,{487,0,488,0}},	{78,{484,0,0,0}},
{0,{487,0,0,0}},	{0,{0,0,485,0}},	{86,{0,0,0,0}},
{0,{485,467,467,467}},	{0,{485,485,485,485}},	{0,{485,449,449,449}},
{0,{485,0,0,0}},	{0,{485,485,485,0}},	{0,{0,0,0,485}},
{0,{0,0,0,485}},	{0,{0,0,0,485}},	{0,{0,0,0,485}},
{0,{0,0,0,485}},	{0,{0,0,0,485}},	{0,{0,0,0,485}},
{0,{439,439,439,485}},	{0,{0,0,0,485}},	{0,{0,0,0,485}},
{0,{0,0,0,485}},	{0,{485,0,423,0}},	{0,{484,0,0,0}},
{0,{484,422,0,0}},	{0,{484,484,435,0}},	{0,{484,0,0,0}},
{0,{484,438,0,0}},	{78,{0,0,0,0}},	{4,{421,389,390,389}},
{4,{388,388,389,388}},	{4,{392,392,392,392}},	{4,{480,391,391,391}},
{0,{479,390,390,390}},	{0,{479,389,389,389}},	{0,{479,407,388,388}},
{4,{0,479,409,0}},	{0,{0,478,408,0}},	{4,{0,477,0,0}},
{0,{0,476,0,0}},	{0,{476,383,383,383}},	{0,{476,476,477,413}},
{0,{477,478,479,0}},	{0,{479,480,481,0}},	{0,{476,476,477,0}},
{0,{477,477,479,0}},	{78,{476,476,478,0}},	{0,{0,0,0,478}},
{0,{0,0,0,478}},	{0,{0,0,0,478}},	{0,{0,0,0,478}},
{0,{0,0,0,478}},	{0,{421,421,421,478}},	{0,{0,478,0,0}},
{0,{399,478,0,0}},	{0,{0,0,0,478}},	{0,{0,0,0,478}},
{0,{0,0,0,478}},	{0,{0,0,0,478}},	{0,{0,0,0,478}},
{0,{0,478,0,0}},	{0,{478,478,0,0}},	{0,{0,0,0,478}},
{0,{0,0,0,478}},	{4,{478,354,355,354}},	{0,{478,366,366,366}},
{0,{0,0,0,478}},	{0,{0,0,0,478}},	{0,{478,479,479,479}},
{0,{478,478,478,478}},	{0,{478,478,478,478}},	{0,{478,352,352,352}},
{0,{478,351,351,351}},	{0,{478,369,350,350}},	{0,{0,0,0,478}},
{0,{0,0,0,478}},	{0,{0,0,0,478}},	{0,{0,0,0,478}},
{0,{0,0,0,478}},	{0,{478,468,468,468}},	{0,{478,343,343,343}},
{0,{478,342,342,342}},	{0,{0,478,0,0}},	{0,{478,464,464,464}},
{0,{478,339,339,339}},	{0,{478,338,338,338}},	{0,{0,0,0,478}},
{0,{0,0,0,478}},	{0,{0,0,0,478}},	{0,{0,0,0,478}},
{0,{0,0,0,478}},	{4,{478,0,0,0}},	{0,{478,0,0,0}},
{4,{478,0,0,0}},	{4,{350,0,0,0}},	{0,{477,0,0,0}},
{4,{477,0,0,0}},	{4,{477,0,0,0}},	{0,{477,0,0,0}},
{0,{477,0,0,0}},	{0,{360,477,360,0}},	{0,{477,364,0,0}},
{0,{477,0,0,0}},	{0,{477,0,0,0}},	{0,{477,478,478,0}},
{0,{478,0,0,0}},	{0,{0,0,0,478}},	{0,{0,0,0,478}},
{4,{478,0,0,0}},	{4,{478,0,0,0}},	{0,{355,355,0,0}},
{0,{471,471,471,0}},	{0,{0,0,0,476}},	{4,{476,0,0,0}},
{0,{0,0,0,476}},	{201,{0,0,0,0}},	{0,{0,0,0,475}},
{0,{0,0,0,475}},	{205,{475,0,0,0}},	{205,{475,0,0,0}},
{205,{475,0,0,0}},	{205,{0,0,0,0}},	{205,{474,0,0,0}},
{205,{474,0,0,0}},	{205,{474,474,474,0}},	{0,{473,473,473,0}},
{0,{473,473,474,0}},	{0,{474,330,330,330}},	{0,{474,0,0,0}},
{0,{474,317,0,0}},	{0,{473,0,0,0}},	{78,{326,352,326,326}},
{78,{0,355,0,0}},	{78,{471,0,0,0}},	{0,{471,0,0,0}},
{0,{471,0,0,0}},	{0,{471,0,0,0}},	{222,{0,0,0,0}},
{224,{0,0,0,0}},	{0,{0,0,0,469}},	{0,{0,469,0,0}},
{0,{0,469,0,0}},	{205,{469,469,0,0}},	{0,{468,469,0,0}},
{205,{454,454,469,0}},	{0,{469,0,0,0}},	{0,{469,0,0,0}},
{0,{469,0,0,0}},	{0,{0,0,0,469}},	{0,{0,0,0,469}},
{0,{469,0,0,0}},	{0,{0,0,0,469}},	{205,{469,0,0,0}},
{0,{469,470,304,304}},	{0,{468,468,303,303}},	{0,{469,302,302,302}},
{0,{469,470,0,0}},	{0,{468,468,0,0}},	{205,{469,0,0,0}},
{205,{469,452,0,0}},	{0,{469,0,0,0}},	{0,{469,0,469,0}},
{0,{469,469,469,469}},	{0,{469,469,469,469}},	{0,{469,469,469,469}},
{0,{469,469,469,469}},	{0,{469,469,469,469}},	{0,{469,469,469,469}},
{0,{469,469,469,469}},	{255,{469,469,469,469}},	{255,{462,462,462,462}},
{255,{468,468,468,468}},	{255,{0,0,0,0}},	{0,{467,0,0,0}},
{0,{458,458,458,467}},	{0,{467,467,467,467}},	{0,{467,467,467,467}},
{0,{467,467,467,467}},	{0,{467,467,467,467}},	{0,{467,453,453,453}},
{0,{0,467,0,0}},	{0,{467,467,467,467}},	{0,{467,467,467,467}},
{255,{461,461,461,461}},	{0,{466,466,466,466}},	{0,{466,466,466,466}},
{0,{466,466,466,466}},	{0,{0,0,0,466}},	{0,{466,0,0,0}},
{0,{466,466,466,466}},	{0,{466,466,466,466}},	{0,{466,466,466,466}},
{0,{466,466,466,466}},	{274,{465,465,465,465}},	{274,{0,0,0,0}},
{0,{464,464,464,464}},	{0,{0,0,0,464}},	{0,{0,0,0,464}},
{0,{0,0,0,464}},	{0,{464,464,464,464}},	{0,{0,0,0,464}},
{0,{0,0,0,464}},	{0,{464,0,0,0}},	{0,{0,0,0,464}},
{0,{464,0,0,0}},	{0,{464,464,464,464}},	{0,{464,464,464,464}},
{0,{464,464,464,464}},	{0,{464,464,464,464}},	{0,{464,464,464,464}},
{0,{464,464,464,0}},	{0,{464,0,0,0}},	{0,{0,0,0,464}},
{0,{464,464,464,464}},	{0,{464,464,0,0}},	{0,{464,464,464,464}},
{0,{464,464,464,464}},	{0,{464,464,464,464}},	{0,{0,0,0,464}},
{0,{0,0,0,464}},	{0,{0,0,0,464}},	{0,{0,0,0,464}},
{0,{0,0,0,464}},	{0,{0,0,0,464}},	{0,{464,464,0,0}},
{0,{464,464,0,0}},	{0,{0,0,0,464}},	{0,{464,0,0,0}},
{0,{464,465,0,0}},	{0,{0,0,465,0}},	{0,{465,466,467,0}},
{0,{461,467,0,0}},	{0,{467,466,0,0}},	{0,{467,465,0,0}},
{0,{464,459,0,0}},	{0,{461,461,462,0}},	{0,{462,462,0,0}},
{0,{464,465,0,0}},	{0,{465,465,465,0}},	{0,{465,465,0,0}},
{0,{464,462,0,0}},	{0,{457,464,0,0}},	{348,{464,465,466,466}},
{348,{466,0,0,0}},	{348,{466,467,468,464}},	{348,{468,469,463,463}},
{348,{469,470,462,462}},	{348,{470,471,461,461}},	{348,{471,459,460,460}},
{348,{471,0,0,0}},	{348,{0,0,0,0}},	{0,{0,470,0,0}},
{0,{445,445,445,0}},	{0,{469,469,469,469}},	{0,{469,469,469,469}},
{0,{469,469,469,469}},	{0,{469,469,469,469}},	{0,{469,469,469,469}},
{0,{469,469,469,469}},	{0,{469,469,469,469}},	{348,{464,464,464,464}},
{348,{466,466,466,466}},	{348,{463,463,463,463}},	{0,{466,467,468,466}},
{0,{465,465,465,465}},	{0,{464,464,466,464}},	{0,{0,466,467,0}},
{0,{0,0,466,0}},	{0,{466,0,0,0}},	{0,{466,466,460,460}},
{0,{466,466,0,0}},	{0,{466,0,0,0}},	{0,{466,0,0,0}},
{0,{0,466,0,0}},	{0,{466,467,467,0}},	{0,{434,0,0,0}},
{0,{466,465,465,0}},	{0,{466,464,464,0}},	{0,{463,463,463,0}},
{0,{465,449,449,449}},	{0,{465,0,0,0}},	{0,{465,465,443,443}},
{0,{465,465,443,443}},	{0,{465,465,444,444}},	{0,{465,465,0,0}},
{377,{0,0,0,0}},	{0,{0,0,0,464}},	{0,{0,0,0,464}},
{0,{410,405,464,0}},	{0,{407,407,464,0}},	{0,{408,408,462,0}},
{0,{0,0,463,0}},	{0,{463,0,462,0}},	{0,{462,0,0,0}},
{388,{462,413,414,414}},	{388,{415,416,417,413}},	{388,{417,418,412,412}},
{388,{420,419,411,411}},	{388,{419,420,410,410}},	{388,{414,408,409,409}},
{388,{0,0,0,0}},	{0,{456,423,423,423}},	{0,{456,425,425,425}},
{0,{456,0,0,0}},	{0,{456,421,421,421}},	{0,{424,425,424,424}},
{0,{0,426,0,0}},	{386,{422,422,422,422}},	{386,{427,427,421,421}},
{386,{0,0,0,0}},	{386,{426,426,0,0}},	{386,{431,430,430,0}},
{386,{429,429,429,0}},	{0,{0,0,448,0}},	{0,{0,0,0,448}},
{0,{0,0,0,448}},	{0,{0,0,0,448}},	{0,{0,0,0,448}},
{0,{0,0,0,448}},	{0,{0,0,0,448}},	{348,{448,394,388,388}},
{0,{448,0,0,0}},	{0,{448,0,0,0}},	{0,{0,448,0,0}},
{0,{0,448,0,0}},	{0,{445,446,0,0}},	{0,{0,0,0,447}},
{0,{0,0,0,447}},	{0,{447,0,0,0}},	{0,{0,0,0,447}},
{0,{0,0,0,447}},	{0,{447,0,0,0}},	{0,{447,0,362,0}},
{0,{446,447,0,0}},	{0,{445,0,0,0}},	{0,{0,445,0,0}},
{0,{445,446,0,0}},	{0,{446,445,0,0}},	{0,{444,444,0,0}},
{0,{445,0,0,0}},	{0,{445,0,0,0}},	{0,{445,0,0,0}},
{348,{445,440,0,0}},	{0,{445,385,385,385}},	{0,{445,0,0,0}},
{0,{445,383,383,383}},	{0,{445,0,0,0}},	{0,{445,445,445,0}},
{430,{0,0,0,0}},	{0,{0,0,0,444}},	{0,{0,0,0,444}},
{0,{444,0,0,0}},	{0,{444,430,0,0}},	{348,{444,0,444,0}},
{0,{443,0,443,0}},	{0,{443,437,437,0}},	{0,{443,0,0,0}},
{0,{443,443,443,0}},	{0,{443,443,443,0}},	{0,{0,0,0,443}},
{0,{0,443,0,0}},	{0,{443,444,444,0}},	{0,{444,366,366,366}},
{0,{444,0,0,0}},	{0,{444,364,364,364}},	{0,{444,0,0,0}},
{0,{444,362,362,362}},	{0,{444,0,0,0}},	{0,{0,0,0,444}},
{0,{0,0,444,0}},	{0,{444,444,0,0}},	{0,{0,444,0,0}},
{0,{444,444,444,0}},	{0,{444,0,0,0}},	{0,{444,444,445,0}},
{0,{443,443,443,0}},	{0,{444,0,0,0}},	{0,{444,444,444,444}},
{0,{444,444,444,443}},	{0,{444,444,444,0}},	{0,{444,444,444,444}},
{0,{0,444,0,0}},	{0,{444,0,0,0}},	{0,{444,0,0,0}},
{0,{444,444,444,0}},	{0,{0,0,444,0}},	{0,{0,0,0,444}},
{0,{444,444,444,444}},	{0,{444,444,444,444}},	{0,{444,444,444,444}},
{0,{444,444,444,444}},	{0,{444,444,444,444}},	{0,{444,0,0,0}},
{494,{0,0,0,0}},	{494,{426,0,0,0}},	{0,{442,0,442,0}},
{494,{442,0,0,0}},	{0,{0,442,0,0}},	{0,{0,442,0,0}},
{0,{0,0,0,442}},	{0,{442,442,442,442}},	{0,{442,442,442,442}},
{0,{442,0,442,0}},	{0,{0,442,0,0}},	{0,{442,442,442,0}},
{0,{442,0,0,0}},	{0,{442,0,0,0}},	{0,{442,0,0,0}},
{0,{0,0,0,442}},	{0,{0,442,0,0}},	{0,{442,442,442,0}},
{0,{442,0,0,0}},	{0,{442,0,0,0}},	{0,{0,0,0,442}},
{0,{0,0,0,442}},	{0,{0,0,0,442}},	{0,{0,0,0,442}},
{0,{442,443,443,443}},	{0,{443,0,0,0}},	{0,{443,0,0,0}},
{0,{443,0,0,0}},	{0,{443,444,444,444}},	{0,{444,0,0,0}},
{0,{444,0,0,0}},	{0,{444,445,445,445}},	{0,{445,0,0,0}},
{0,{445,446,0,0}},	{0,{444,0,0,0}},	{0,{445,446,446,446}},
{0,{446,445,445,445}},	{0,{446,442,0,0}},	{0,{445,0,0,0}},
{0,{445,440,0,0}},	{0,{444,0,0,0}},	{0,{444,426,426,426}},
{0,{444,0,0,0}},	{0,{444,0,0,0}},	{0,{444,423,423,423}},
{0,{429,434,0,0}},	{0,{443,435,435,435}},	{0,{443,420,420,420}},
{0,{443,444,445,0}},	{0,{442,0,444,0}},	{0,{444,431,431,431}},
{0,{416,416,416,416}},	{0,{0,0,0,443}},	{0,{419,419,419,419}},
{0,{422,422,422,422}},	{0,{0,0,0,441}},	{0,{425,425,425,425}},
{0,{440,0,0,0}},	{0,{440,0,0,0}},	{0,{440,0,0,0}},
{0,{0,0,0,440}},	{0,{0,0,0,440}},	{0,{0,0,0,440}},
{46,{440,440,440,440}},	{0,{439,439,439,439}},	{0,{439,439,439,439}},
{46,{439,439,439,439}},	{46,{0,0,0,0}},	{46,{438,438,438,438}},
{0,{438,438,438,438}},	{0,{438,438,438,438}},	{53,{438,438,438,438}},
{0,{438,438,438,438}},	{0,{438,438,438,438}},	{0,{438,438,438,438}},
{0,{438,438,438,438}},	{53,{0,0,0,0}},	{0,{437,437,437,437}},
{0,{437,0,438,0}},	{0,{438,0,0,0}},	{0,{438,0,0,0}},
{0,{438,0,0,0}},	{0,{438,0,0,0}},	{0,{438,0,0,0}},
{0,{0,0,0,438}},	{0,{438,0,0,0}},	{0,{0,0,0,438}},
{0,{431,438,0,0}},	{0,{0,0,0,438}},	{79,{414,414,414,414}},
{0,{437,437,437,437}},	{0,{437,437,437,437}},	{82,{411,411,411,411}},
{79,{0,0,0,0}},	{0,{435,435,435,435}},	{0,{435,435,435,435}},
{82,{0,0,0,0}},	{79,{434,434,434,434}},	{0,{434,435,0,0}},
{0,{0,0,0,435}},	{0,{435,435,435,435}},	{92,{0,0,0,0}},
{0,{434,434,434,0}},	{0,{434,0,0,0}},	{0,{434,0,0,0}},
{0,{434,0,0,0}},	{0,{434,0,0,0}},	{0,{434,0,0,0}},
{0,{0,0,0,434}},	{0,{0,0,0,434}},	{0,{434,434,434,434}},
{0,{434,435,0,0}},	{0,{0,434,0,0}},	{0,{434,0,0,0}},
{0,{0,0,0,434}},	{0,{434,434,434,434}},	{46,{0,0,0,434}},
{0,{434,434,434,434}},	{53,{392,392,392,392}},	{0,{355,0,433,0}},
{0,{354,0,433,0}},	{0,{370,0,433,0}},	{0,{0,0,0,433}},
{0,{433,0,0,0}},	{0,{0,0,0,433}},	{0,{0,0,0,433}},
{125,{433,433,433,433}},	{125,{0,0,0,0}},	{128,{0,0,0,0}},
{124,{0,0,0,0}},	{124,{342,342,342,342}},	{127,{0,0,0,0}},
{0,{428,0,0,0}},	{0,{428,428,0,0}},	{0,{428,0,0,0}},
{0,{428,0,0,0}},	{0,{428,428,428,428}},	{0,{381,428,0,0}},
{0,{0,0,0,428}},	{0,{0,0,0,428}},	{0,{428,0,0,0}},
{0,{428,0,0,0}},	{0,{428,0,0,0}},	{0,{428,0,0,0}},
{0,{428,0,0,0}},	{0,{0,0,0,428}},	{0,{0,0,0,428}},
{0,{428,0,0,0}},	{0,{428,0,0,0}},	{0,{428,0,0,0}},
{0,{428,0,0,0}},	{0,{428,0,0,0}},	{0,{428,0,0,0}},
{0,{428,0,0,0}},	{0,{428,0,0,0}},	{0,{428,0,0,0}},
{0,{428,0,0,0}},	{0,{428,0,0,0}},	{0,{428,334,335,0}},
{0,{428,0,0,0}},	{0,{428,0,0,0}},	{0,{428,0,0,0}},
{0,{428,0,0,0}},	{0,{428,0,0,0}},	{0,{428,0,0,0}},
{0,{428,0,0,0}},	{0,{428,0,0,0}},	{0,{0,0,0,428}},
{0,{428,0,0,0}},	{0,{428,0,0,0}},	{0,{428,0,0,0}},
{0,{428,0,0,0}},	{0,{428,0,0,0}},	{0,{428,388,0,0}},
{0,{428,0,0,0}},	{0,{0,0,428,0}},	{0,{428,428,428,429}},
{0,{429,429,0,0}},	{0,{427,427,427,427}},	{0,{0,428,0,0}},
{0,{428,428,428,429}},	{0,{428,428,428,428}},	{0,{0,0,428,0}},
{0,{0,428,0,0}},	{185,{0,0,0,0}},	{0,{324,324,324,324}},
{0,{426,0,0,0}},	{0,{0,426,0,0}},	{0,{0,425,426,0}},
{0,{0,0,425,0}},	{0,{0,425,0,0}},	{0,{425,0,0,0}},
{0,{425,0,425,0}},	{0,{425,425,425,274}},	{0,{425,425,425,287}},
{0,{425,0,0,0}},	{197,{0,0,0,0}},	{0,{424,0,0,0}},
{0,{424,425,424,0}},	{0,{425,426,425,0}},	{0,{426,426,426,426}},
{0,{426,426,426,426}},	{0,{426,426,426,426}},	{0,{426,426,426,426}},
{0,{426,426,426,426}},	{211,{0,0,0,0}},	{212,{0,0,0,0}},
{213,{0,0,0,0}},	{215,{295,295,295,295}},	{215,{0,0,0,0}},
{0,{421,421,421,0}},	{0,{421,421,421,421}},	{0,{319,319,319,319}},
{0,{420,420,420,420}},	{221,{0,0,0,0}},	{0,{419,0,0,0}},
{228,{256,256,256,256}},	{228,{0,0,0,0}},	{229,{0,0,0,0}},
{230,{0,0,0,0}},	{211,{415,415,0,0}},	{233,{0,0,415,0}},
{235,{0,0,0,0}},	{233,{0,0,0,0}},	{0,{410,0,413,0}},
{0,{0,0,412,0}},	{0,{333,333,333,333}},	{0,{411,411,0,0}},
{243,{0,0,0,0}},	{244,{274,274,274,274}},	{244,{274,274,274,274}},
{215,{272,408,272,272}},	{244,{0,0,0,0}},	{244,{239,239,239,239}},
{0,{406,0,0,0}},	{247,{0,0,0,0}},	{233,{0,405,400,0}},
{0,{405,405,0,0}},	{0,{0,0,0,405}},	{0,{405,0,0,0}},
{0,{405,0,0,0}},	{0,{405,0,0,0}},	{0,{405,0,0,0}},
{0,{405,0,0,0}},	{0,{405,0,0,0}},	{0,{405,406,0,0}},
{0,{405,405,0,0}},	{0,{405,405,405,405}},	{0,{405,0,0,0}},
{0,{405,0,0,0}},	{0,{405,0,406,0}},	{0,{406,0,0,0}},
{0,{406,0,0,0}},	{0,{406,0,0,0}},	{264,{0,0,0,0}},
{0,{405,0,0,0}},	{0,{404,0,405,0}},	{0,{405,0,0,0}},
{0,{405,0,0,0}},	{0,{0,405,0,0}},	{0,{0,0,405,0}},
{0,{405,0,0,0}},	{0,{405,405,405,405}},	{0,{405,405,405,405}},
{0,{405,405,405,405}},	{0,{405,405,0,0}},	{0,{405,405,405,405}},
{0,{405,0,0,0}},	{0,{405,0,0,0}},	{0,{405,405,0,0}},
{0,{0,0,0,405}},	{0,{405,403,0,0}},	{0,{405,0,0,0}},
{0,{405,405,0,0}},	{0,{405,0,0,0}},	{291,{0,0,0,0}},
{0,{404,0,0,0}},	{0,{404,394,394,394}},	{0,{404,404,0,0}},
{0,{404,404,0,0}},	{0,{404,404,0,0}},	{0,{404,0,0,0}},
{0,{0,404,0,0}},	{0,{0,0,0,404}},	{0,{404,0,0,0}},
{0,{404,0,0,0}},	{0,{404,404,404,0}},	{0,{404,404,0,0}},
{0,{404,404,0,0}},	{0,{404,0,0,0}},	{0,{404,404,404,404}},
{0,{0,0,404,0}},	{0,{0,0,404,0}},	{0,{404,404,402,0}},
{0,{404,0,0,0}},	{0,{404,0,0,0}},	{320,{0,0,0,0}},
{0,{0,0,403,0}},	{325,{0,0,0,0}},	{0,{0,402,0,0}},
{0,{402,403,0,0}},	{0,{403,0,0,0}},	{0,{403,399,0,0}},
{0,{402,400,0,0}},	{0,{401,0,0,0}},	{0,{0,398,0,0}},
{0,{400,395,0,0}},	{0,{400,394,0,0}},	{0,{400,401,0,0}},
{0,{401,400,0,0}},	{0,{0,401,0,0}},	{0,{401,398,0,0}},
{0,{401,391,0,0}},	{0,{401,402,403,404}},	{0,{404,405,406,0}},
{0,{405,405,405,0}},	{0,{0,405,0,0}},	{0,{405,406,403,0}},
{0,{404,401,402,0}},	{0,{403,401,401,0}},	{0,{400,403,400,0}},
{0,{399,398,399,0}},	{0,{402,403,394,395}},	{0,{403,404,397,0}},
{0,{404,405,396,0}},	{0,{403,402,395,0}},	{0,{390,389,390,391}},
{0,{390,390,390,390}},	{0,{385,0,0,0}},	{0,{401,402,403,402}},
{0,{401,401,402,401}},	{0,{402,0,403,0}},	{0,{0,0,402,0}},
{0,{402,398,399,398}},	{0,{402,0,400,0}},	{0,{396,396,396,396}},
{0,{401,0,0,0}},	{0,{401,0,0,0}},	{0,{401,0,0,0}},
{0,{401,0,0,0}},	{0,{401,0,0,0}},	{0,{0,0,0,401}},
{0,{401,0,0,0}},	{0,{401,0,0,0}},	{0,{401,0,401,0}},
{0,{401,401,401,401}},	{0,{401,401,401,0}},	{373,{401,402,401,401}},
{373,{0,0,0,0}},	{373,{0,372,0,0}},	{373,{398,398,398,398}},
{0,{399,399,399,380}},	{0,{399,399,399,0}},	{376,{380,0,381,0}},
{376,{0,0,380,0}},	{376,{381,0,379,0}},	{376,{0,0,0,0}},
{0,{395,0,0,0}},	{0,{395,0,395,0}},	{0,{0,395,0,0}},
{0,{345,394,0,0}},	{0,{0,0,0,394}},	{384,{0,0,0,0}},
{0,{393,360,357,0}},	{392,{369,0,370,0}},	{392,{371,0,369,0}},
{392,{0,0,0,0}},	{392,{0,0,367,0}},	{395,{0,0,0,0}},
{0,{388,389,388,0}},	{0,{0,389,0,0}},	{0,{381,388,0,0}},
{0,{388,387,0,0}},	{0,{388,0,0,0}},	{0,{383,383,383,0}},
{0,{387,348,345,0}},	{0,{0,0,0,387}},	{0,{0,0,0,387}},
{0,{0,0,0,387}},	{0,{0,0,0,387}},	{0,{0,387,0,0}},
{0,{387,0,0,0}},	{416,{0,0,0,0}},	{0,{386,0,0,0}},
{0,{386,375,0,0}},	{0,{386,386,387,386}},	{0,{385,385,385,385}},
{0,{386,0,0,0}},	{0,{386,386,384,383}},	{0,{386,386,0,0}},
{0,{384,384,381,381}},	{0,{385,0,0,0}},	{0,{379,379,379,385}},
{0,{0,0,0,385}},	{0,{381,385,0,0}},	{0,{385,385,385,385}},
{0,{385,385,385,385}},	{0,{385,385,385,385}},	{428,{0,0,0,0}},
{429,{0,0,0,0}},	{0,{383,384,0,0}},	{0,{384,0,0,0}},
{0,{384,369,370,369}},	{0,{384,371,369,368}},	{440,{0,0,0,0}},
{429,{383,383,383,383}},	{0,{382,382,382,382}},	{453,{0,0,0,0}},
{429,{381,0,0,0}},	{0,{381,0,0,0}},	{0,{381,381,381,0}},
{0,{381,382,0,0}},	{0,{380,380,0,0}},	{0,{381,381,381,381}},
{0,{381,381,381,381}},	{0,{379,381,379,379}},	{0,{379,381,379,379}},
{0,{314,381,314,314}},	{0,{0,381,0,0}},	{0,{0,0,381,0}},
{0,{381,381,0,0}},	{0,{381,0,0,0}},	{0,{0,381,0,0}},
{0,{0,0,381,0}},	{0,{381,0,0,0}},	{0,{0,0,381,0}},
{0,{375,375,380,0}},	{0,{380,0,0,0}},	{0,{0,380,0,0}},
{0,{380,379,0,0}},	{0,{379,0,0,0}},	{0,{379,379,379,0}},
{0,{379,379,379,379}},	{0,{379,379,0,0}},	{0,{379,378,0,0}},
{0,{379,0,0,0}},	{0,{379,379,379,379}},	{0,{379,379,379,379}},
{0,{379,0,0,0}},	{0,{378,0,379,0}},	{0,{379,379,379,0}},
{0,{0,0,377,0}},	{0,{0,0,0,378}},	{0,{378,0,0,0}},
{499,{0,0,0,0}},	{0,{377,0,0,0}},	{0,{377,377,377,377}},
{504,{0,0,0,0}},	{0,{376,376,376,376}},	{0,{376,376,376,376}},
{0,{376,376,376,376}},	{514,{0,0,0,0}},	{0,{0,0,375,0}},
{0,{375,375,375,375}},	{0,{375,0,0,0}},	{0,{375,0,0,0}},
{0,{375,0,0,0}},	{0,{375,0,0,0}},	{0,{0,0,0,375}},
{523,{0,0,0,0}},	{0,{374,374,0,0}},	{0,{0,374,0,0}},
{0,{374,0,0,0}},	{0,{0,374,0,0}},	{0,{0,0,0,374}},
{0,{0,0,0,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,0,0,0}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{0,{374,361,361,361}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,374,0,0}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{0,{0,374,0,0}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,374,374}},
{0,{374,374,374,374}},	{0,{374,374,374,374}},	{0,{374,374,0,0}},
{0,{374,374,342,342}},	{0,{374,372,0,0}},	{0,{374,0,0,0}},
{0,{374,0,375,0}},	{0,{0,0,374,0}},	{0,{374,374,0,0}},
{0,{374,374,0,0}},	{0,{0,0,374,0}},	{0,{374,0,370,0}},
{0,{373,0,0,0}},	{0,{367,0,0,0}},	{0,{372,372,372,372}},
{0,{372,372,372,372}},	{0,{372,372,372,372}},	{0,{372,372,372,372}},
{0,{372,372,372,372}},	{0,{372,372,372,372}},	{0,{372,372,372,372}},
{0,{372,0,372,0}},	{0,{372,372,372,372}},	{0,{372,372,372,372}},
{0,{372,372,372,372}},	{0,{372,372,372,372}},	{0,{350,372,0,0}},
{0,{349,372,0,0}},	{0,{0,372,0,0}},	{0,{0,372,0,0}},
{0,{0,0,0,372}},	{0,{372,372,372,358}},	{0,{372,372,372,0}},
{0,{372,372,372,372}},	{0,{372,372,0,0}},	{0,{372,372,372,372}},
{0,{372,372,372,372}},	{0,{372,372,372,372}},	{0,{372,372,372,372}},
{0,{372,372,372,372}},	{102,{0,0,0,0}},	{0,{371,0,0,0}},
{0,{371,0,0,0}},	{0,{371,333,0,0}},	{0,{371,0,0,0}},
{0,{371,371,371,371}},	{0,{371,371,371,371}},	{0,{371,371,0,0}},
{0,{0,371,0,0}},	{0,{371,371,371,371}},	{0,{330,0,334,0}},
{119,{370,370,370,370}},	{119,{0,0,0,0}},	{119,{313,313,313,313}},
{0,{368,368,368,368}},	{0,{292,368,292,292}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,0,0,0}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,0,0,0}},	{0,{368,368,368,368}},
{0,{368,0,0,0}},	{0,{0,0,0,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,294,294,294}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,367,367,367}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,264,264,264}},
{0,{368,368,368,368}},	{0,{368,279,279,279}},	{0,{368,368,368,368}},
{0,{368,368,367,367}},	{0,{368,368,368,368}},	{0,{368,0,0,0}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,255,255,255}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,251,251,251}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{0,{368,369,369,237}},	{0,{368,368,368,236}},
{0,{368,0,0,0}},	{0,{0,0,0,368}},	{0,{368,369,369,247}},
{0,{368,368,368,246}},	{0,{368,368,368,368}},	{0,{368,368,368,368}},
{0,{368,368,368,368}},	{187,{0,0,0,0}},	{0,{367,367,367,0}},
{0,{367,367,0,0}},	{0,{367,0,0,0}},	{192,{0,0,0,0}},
{0,{366,223,223,223}},	{0,{366,236,236,236}},	{0,{0,0,366,0}},
{0,{366,366,366,366}},	{192,{366,0,0,0}},	{0,{365,0,0,0}},
{192,{365,0,0,0}},	{0,{364,0,0,0}},	{0,{364,365,365,365}},
{0,{365,0,0,0}},	{0,{363,363,363,363}},	{0,{364,364,364,362}},
{0,{364,364,364,0}},	{0,{364,364,364,364}},	{0,{0,0,0,364}},
{0,{0,0,0,364}},	{0,{364,0,0,0}},	{0,{364,364,364,364}},
{0,{0,364,0,0}},	{0,{364,364,364,364}},	{0,{364,364,364,364}},
{0,{364,238,0,0}},	{0,{364,364,364,364}},	{0,{364,0,0,0}},
{0,{364,364,364,364}},	{0,{364,364,0,0}},	{0,{364,364,364,364}},
{0,{364,364,364,364}},	{0,{364,364,364,364}},	{0,{364,364,364,364}},
{0,{364,364,364,364}},	{0,{364,364,364,364}},	{0,{364,364,364,364}},
{0,{364,364,364,364}},	{0,{364,0,0,0}},	{0,{364,364,364,364}},
{0,{364,364,364,364}},	{0,{364,364,364,364}},	{0,{364,364,364,364}},
{0,{364,364,364,364}},	{0,{364,364,364,364}},	{0,{364,364,364,364}},
{0,{364,364,364,364}},	{0,{364,364,364,364}},	{0,{364,364,364,364}},
{0,{364,364,364,364}},	{0,{364,364,364,364}},	{0,{364,364,364,364}},
{0,{364,364,0,0}},	{0,{364,0,0,0}},	{0,{0,0,0,364}},
{0,{364,364,0,0}},	{0,{364,364,364,364}},	{0,{364,364,364,364}},
{0,{364,364,364,364}},	{0,{364,364,364,364}},	{283,{0,0,0,0}},
{0,{0,363,0,0}},	{287,{0,0,0,0}},	{0,{362,362,362,362}},
{0,{362,362,362,362}},	{0,{362,0,0,0}},	{0,{362,362,362,362}},
{0,{362,362,362,362}},	{0,{362,362,362,363}},	{0,{362,362,362,362}},
{0,{362,362,362,0}},	{0,{362,362,362,362}},	{0,{0,0,0,362}},
{0,{0,362,0,0}},	{0,{362,362,362,362}},	{0,{362,362,362,362}},
{0,{362,362,362,362}},	{0,{362,362,362,363}},	{0,{362,362,362,362}},
{310,{0,0,0,0}},	{0,{361,361,0,0}},	{313,{0,0,0,0}},
{314,{0,0,0,0}},	{0,{0,0,359,0}},	{318,{0,0,0,0}},
{0,{358,358,358,358}},	{324,{0,0,0,0}},	{0,{357,357,357,357}},
{0,{357,357,357,357}},	{0,{357,357,357,357}},	{0,{357,357,0,0}},
{0,{357,357,357,357}},	{0,{357,357,357,357}},	{0,{0,357,0,0}},
{0,{357,357,357,357}},	{0,{357,357,357,357}},	{0,{357,357,357,357}},
{0,{357,357,357,357}},	{0,{357,357,357,357}},	{0,{357,357,357,357}},
{349,{357,357,357,357}},	{353,{357,357,357,357}},	{349,{357,357,357,357}},
{0,{356,356,356,356}},	{349,{352,352,352,352}},	{349,{341,341,341,341}},
{349,{0,0,0,0}},	{352,{0,0,0,0}},	{349,{340,340,340,340}},
{353,{351,351,351,351}},	{349,{351,351,351,351}},	{353,{351,351,351,351}},
{349,{341,341,341,341}},	{349,{339,339,339,339}},	{349,{341,341,341,341}},
{353,{348,348,348,348}},	{0,{348,349,348,348}},	{0,{0,349,0,0}},
{0,{349,350,349,349}},	{0,{345,345,345,345}},	{0,{347,347,347,347}},
{0,{348,349,348,348}},	{0,{347,347,347,347}},	{0,{348,348,348,348}},
{0,{348,348,348,348}},	{0,{348,348,348,348}},	{0,{348,348,348,348}},
{0,{348,348,348,348}},	{0,{348,348,348,0}},	{0,{348,348,348,348}},
{0,{348,348,348,348}},	{0,{348,348,348,348}},	{0,{348,0,0,0}},
{0,{348,348,348,0}},	{0,{348,348,348,348}},	{352,{347,347,347,347}},
{0,{347,348,347,0}},	{0,{346,346,346,0}},	{0,{347,347,347,347}},
{380,{0,0,0,0}},	{381,{0,0,0,0}},	{0,{345,345,345,345}},
{349,{345,345,345,345}},	{0,{345,345,345,345}},	{398,{344,344,344,344}},
{398,{0,0,0,0}},	{0,{343,343,343,343}},	{401,{0,0,0,0}},
{349,{342,342,342,342}},	{0,{342,0,0,0}},	{0,{342,0,342,0}},
{0,{342,342,342,342}},	{0,{341,342,341,341}},	{0,{0,342,0,0}},
{0,{342,0,0,0}},	{0,{342,342,342,342}},	{418,{0,0,0,0}},
{0,{341,341,0,0}},	{0,{341,341,0,0}},	{0,{341,341,341,341}},
{0,{341,341,342,342}},	{0,{341,341,341,341}},	{0,{341,341,341,341}},
{0,{341,341,342,342}},	{0,{341,341,341,341}},	{352,{337,337,337,337}},
{0,{340,341,0,0}},	{0,{339,339,0,0}},	{0,{340,339,0,0}},
{434,{0,0,0,0}},	{436,{0,0,0,0}},	{437,{0,0,0,0}},
{0,{326,337,0,0}},	{0,{328,337,329,329}},	{0,{337,0,0,0}},
{0,{337,337,337,337}},	{459,{0,0,0,0}},	{0,{336,336,336,336}},
{0,{336,336,336,336}},	{352,{335,335,335,335}},	{0,{335,286,0,0}},
{0,{334,0,0,0}},	{0,{334,284,0,0}},	{0,{333,0,0,0}},
{0,{333,282,0,0}},	{0,{332,0,0,0}},	{0,{332,332,332,332}},
{0,{332,332,332,332}},	{0,{332,332,332,332}},	{0,{332,332,332,332}},
{0,{332,332,332,0}},	{0,{332,332,332,332}},	{0,{332,332,332,332}},
{0,{332,332,332,332}},	{0,{332,332,332,0}},	{0,{332,332,332,332}},
{0,{332,332,332,332}},	{0,{332,0,0,0}},	{0,{332,332,332,332}},
{0,{332,331,331,331}},	{0,{0,0,332,0}},	{0,{0,0,332,0}},
{0,{332,0,0,0}},	{0,{332,332,332,332}},	{0,{332,332,332,332}},
{0,{332,332,332,332}},	{0,{332,332,332,332}},	{0,{332,332,332,332}},
{0,{332,332,332,332}},	{0,{332,0,0,0}},	{0,{332,0,0,0}},
{0,{332,332,332,0}},	{0,{0,332,0,0}},	{0,{0,0,0,332}},
{0,{332,332,0,0}},	{0,{332,0,0,0}},	{0,{332,0,0,0}},
{0,{0,0,332,0}},	{521,{0,0,0,0}},	{0,{331,331,331,331}},
{0,{0,0,0,331}},	{0,{0,0,0,331}},	{526,{0,0,0,0}},
{0,{0,0,0,330}},	{0,{0,0,0,330}},	{0,{0,0,0,330}},
{0,{330,331,331,331}},	{0,{331,331,331,331}},	{0,{331,332,332,332}},
{0,{330,331,331,332}},	{0,{332,332,332,332}},	{0,{332,332,332,332}},
{0,{332,332,332,332}},	{0,{327,327,327,332}},	{0,{326,326,326,326}},
{0,{331,331,331,331}},	{0,{331,331,331,331}},	{0,{323,323,323,324}},
{0,{330,331,322,322}},	{0,{0,0,331,0}},	{0,{331,332,332,332}},
{0,{332,332,332,332}},	{0,{332,330,330,330}},	{0,{332,326,317,317}},
{0,{332,325,316,316}},	{0,{332,312,312,312}},	{0,{332,323,314,314}},
{0,{332,313,313,313}},	{0,{309,309,309,309}},	{0,{323,323,323,323}},
{0,{330,307,307,307}},	{0,{330,330,330,330}},	{0,{330,330,330,330}},
{0,{330,330,330,330}},	{0,{330,318,318,318}},	{0,{0,0,0,330}},
{0,{0,0,0,330}},	{0,{330,303,303,303}},	{0,{320,311,302,330}},
{0,{301,301,301,329}},	{0,{0,0,0,329}},	{0,{0,0,0,329}},
{0,{0,0,0,329}},	{47,{0,0,0,0}},	{47,{300,300,300,300}},
{47,{327,327,327,327}},	{0,{326,326,326,326}},	{0,{326,326,326,326}},
{0,{326,326,326,326}},	{0,{326,326,326,326}},	{0,{326,326,326,326}},
{0,{326,326,326,326}},	{0,{326,326,326,326}},	{0,{326,327,327,328}},
{0,{328,328,328,328}},	{0,{328,329,329,330}},	{0,{329,329,329,329}},
{0,{329,329,329,329}},	{0,{329,329,329,329}},	{0,{325,325,325,326}},
{0,{0,0,0,328}},	{0,{324,324,324,328}},	{0,{0,0,0,328}},
{0,{328,328,328,328}},	{0,{0,0,0,328}},	{80,{0,0,0,0}},
{47,{327,327,327,327}},	{83,{0,0,0,0}},	{0,{325,325,325,325}},
{0,{325,325,325,325}},	{0,{315,315,315,325}},	{0,{0,0,0,325}},
{0,{0,0,0,325}},	{47,{325,325,325,325}},	{0,{325,325,325,325}},
{0,{325,0,326,0}},	{0,{326,0,0,0}},	{0,{326,0,324,0}},
{0,{326,0,0,0}},	{0,{326,326,326,326}},	{0,{326,326,326,326}},
{47,{326,326,326,326}},	{0,{0,0,326,0}},	{0,{326,326,326,326}},
{0,{326,0,0,0}},	{0,{0,0,0,326}},	{0,{326,326,326,326}},
{0,{0,0,0,326}},	{0,{326,326,326,326}},	{0,{0,0,0,326}},
{0,{326,326,326,326}},	{0,{0,0,0,326}},	{0,{0,0,0,326}},
{0,{326,326,326,326}},	{0,{326,327,327,327}},	{0,{327,327,327,327}},
{0,{0,0,327,0}},	{0,{327,0,0,0}},	{0,{327,327,327,327}},
{0,{327,327,327,327}},	{0,{0,0,0,327}},	{0,{0,0,0,327}},
{0,{327,0,299,328}},	{0,{328,0,0,0}},	{0,{299,0,297,326}},
{0,{0,0,0,325}},	{0,{326,0,0,0}},	{0,{0,0,0,326}},
{0,{0,0,0,326}},	{0,{320,326,292,321}},	{0,{293,325,291,320}},
{0,{256,229,229,325}},	{0,{243,237,228,325}},	{0,{325,308,308,308}},
{156,{324,307,307,307}},	{0,{324,325,325,325}},	{0,{325,224,224,224}},
{0,{325,223,223,223}},	{0,{325,325,325,325}},	{0,{325,325,325,325}},
{0,{325,325,325,325}},	{0,{325,0,326,0}},	{0,{326,327,328,327}},
{0,{328,0,0,0}},	{0,{328,328,328,328}},	{0,{322,0,322,0}},
{0,{327,328,328,328}},	{0,{213,213,213,328}},	{0,{328,316,329,316}},
{0,{0,0,0,329}},	{0,{329,330,330,330}},	{0,{330,330,330,330}},
{0,{330,330,208,208}},	{0,{330,288,288,288}},	{0,{330,330,330,330}},
{0,{330,330,330,330}},	{0,{330,0,0,0}},	{0,{330,330,330,0}},
{0,{330,330,330,330}},	{0,{330,330,330,330}},	{0,{330,330,330,330}},
{0,{330,330,330,330}},	{0,{330,330,330,330}},	{0,{330,330,330,330}},
{0,{330,330,330,330}},	{0,{330,330,330,330}},	{0,{330,330,330,330}},
{0,{330,330,330,330}},	{0,{330,330,330,330}},	{191,{0,0,0,0}},
{0,{329,329,329,329}},	{0,{329,329,329,329}},	{0,{0,0,329,0}},
{0,{0,0,0,329}},	{0,{329,329,329,329}},	{0,{329,329,329,329}},
{0,{329,329,329,329}},	{0,{329,329,329,329}},	{0,{329,329,329,329}},
{0,{329,329,329,329}},	{0,{329,329,329,329}},	{0,{329,329,329,329}},
{0,{329,329,329,329}},	{0,{329,329,329,329}},	{0,{0,0,0,329}},
{0,{329,329,329,329}},	{0,{329,329,329,329}},	{0,{0,0,0,329}},
{0,{329,329,329,329}},	{47,{329,329,329,329}},	{0,{329,329,329,329}},
{0,{329,329,329,0}},	{0,{329,329,329,329}},	{0,{0,0,0,329}},
{0,{329,329,329,0}},	{0,{328,328,328,329}},	{0,{329,327,327,0}},
{0,{329,326,326,0}},	{0,{329,325,325,0}},	{0,{329,324,324,0}},
{0,{323,323,323,329}},	{0,{0,0,0,328}},	{0,{328,328,328,328}},
{0,{328,320,320,0}},	{0,{328,319,319,0}},	{0,{321,318,318,328}},
{0,{0,0,0,328}},	{0,{0,0,0,328}},	{0,{0,0,0,325}},
{0,{314,314,314,327}},	{0,{313,313,313,323}},	{0,{0,0,0,326}},
{0,{326,311,311,0}},	{0,{326,310,310,0}},	{0,{326,326,326,326}},
{0,{326,326,326,326}},	{0,{0,0,0,326}},	{0,{326,326,326,326}},
{0,{326,326,326,326}},	{0,{326,326,326,326}},	{0,{326,326,0,0}},
{0,{326,326,326,326}},	{0,{326,0,0,327}},	{0,{0,0,0,326}},
{0,{0,0,0,326}},	{0,{323,0,0,0}},	{0,{325,325,325,325}},
{0,{325,325,325,325}},	{0,{325,325,325,325}},	{0,{325,325,325,325}},
{0,{325,325,325,325}},	{0,{325,325,325,325}},	{0,{325,326,326,326}},
{0,{326,326,326,326}},	{0,{326,326,326,326}},	{0,{0,0,0,326}},
{0,{326,326,326,326}},	{0,{326,326,326,326}},	{0,{326,326,326,326}},
{0,{326,326,326,326}},	{0,{326,326,326,326}},	{311,{0,0,0,0}},
{0,{325,325,325,325}},	{0,{325,325,325,325}},	{0,{325,325,325,325}},
{0,{325,326,326,326}},	{0,{326,326,326,326}},	{0,{0,0,0,326}},
{0,{326,326,326,327}},	{0,{327,0,0,0}},	{0,{0,0,0,327}},
{0,{327,327,327,327}},	{0,{327,327,327,327}},	{0,{327,327,327,327}},
{0,{327,327,327,327}},	{0,{327,327,327,327}},	{0,{315,315,315,315}},
{0,{326,326,326,326}},	{0,{326,326,326,326}},	{0,{326,326,326,326}},
{0,{326,326,326,326}},	{0,{326,326,326,326}},	{0,{326,326,326,326}},
{0,{326,326,326,326}},	{0,{326,327,0,0}},	{361,{325,326,0,0}},
{361,{0,0,0,0}},	{0,{325,325,0,0}},	{361,{324,324,0,0}},
{0,{322,322,0,0}},	{361,{321,321,0,0}},	{0,{322,322,0,0}},
{0,{322,321,0,0}},	{0,{320,320,0,322}},	{0,{322,0,0,0}},
{0,{0,0,0,320}},	{0,{0,0,0,321}},	{0,{321,321,322,322}},
{0,{321,321,321,321}},	{0,{321,321,321,321}},	{0,{321,321,321,321}},
{0,{321,321,321,321}},	{0,{321,321,321,321}},	{0,{321,321,321,321}},
{361,{320,320,320,320}},	{0,{320,320,320,320}},	{0,{0,0,0,320}},
{0,{320,320,320,320}},	{0,{320,320,320,0}},	{0,{320,320,320,320}},
{0,{320,320,320,320}},	{0,{0,0,0,320}},	{0,{0,0,0,320}},
{0,{0,0,0,320}},	{0,{0,0,0,320}},	{414,{0,0,0,0}},
{0,{319,319,319,319}},	{0,{319,319,319,319}},	{0,{319,319,319,319}},
{0,{319,319,319,319}},	{0,{0,0,0,319}},	{0,{319,319,319,319}},
{0,{319,319,319,319}},	{0,{319,319,319,319}},	{0,{313,313,313,319}},
{0,{0,0,0,319}},	{0,{319,319,319,319}},	{361,{318,318,318,318}},
{0,{318,318,318,318}},	{0,{318,318,318,318}},	{0,{318,318,318,318}},
{0,{318,318,318,318}},	{0,{318,318,318,318}},	{0,{318,318,318,318}},
{0,{318,318,318,318}},	{462,{0,0,0,0}},	{462,{317,317,317,317}},
{0,{316,316,316,316}},	{0,{316,316,316,316}},	{0,{316,316,316,316}},
{0,{316,316,316,316}},	{0,{316,316,316,316}},	{0,{316,316,316,316}},
{0,{316,316,316,316}},	{0,{316,316,316,316}},	{0,{316,316,316,316}},
{473,{0,0,0,0}},	{0,{315,315,315,0}},	{0,{315,315,315,315}},
{0,{315,315,315,315}},	{0,{315,315,315,315}},	{0,{314,314,314,315}},
{0,{315,315,315,315}},	{0,{315,315,315,315}},	{0,{315,315,315,315}},
{0,{315,315,315,315}},	{0,{315,315,315,315}},	{0,{315,315,315,315}},
{0,{0,0,0,315}},	{0,{315,315,315,315}},	{0,{315,315,315,315}},
{0,{315,315,315,315}},	{0,{315,315,315,315}},	{0,{315,315,315,315}},
{507,{0,0,0,0}},	{0,{314,314,314,314}},	{0,{314,314,314,314}},
{0,{314,314,314,314}},	{0,{314,314,314,314}},	{0,{314,314,314,314}},
{0,{0,0,0,314}},	{0,{314,314,314,314}},	{0,{314,314,314,314}},
{0,{314,314,314,314}},	{0,{314,0,0,0}},	{0,{0,0,0,314}},
{0,{314,315,314,315}},	{0,{315,315,315,315}},	{0,{315,315,315,315}},
{0,{315,315,315,315}},	{0,{315,315,315,315}},	{0,{315,315,315,315}},
{0,{315,315,315,315}},	{0,{315,315,315,315}},	{0,{315,315,315,315}},
{0,{315,310,310,310}},	{0,{315,315,315,315}},	{0,{315,315,315,315}},
{0,{315,316,307,307}},	{0,{315,315,306,306}},	{0,{0,0,315,0}},
{0,{315,316,315,316}},	{0,{316,316,316,316}},	{0,{316,316,316,316}},
{0,{313,313,313,313}},	{0,{315,309,300,300}},	{0,{315,308,299,299}},
{0,{294,294,294,294}},	{0,{314,306,297,297}},	{0,{314,296,296,296}},
{0,{314,314,314,314}},	{0,{314,314,314,314}},	{0,{314,314,314,314}},
{0,{314,314,314,314}},	{0,{314,314,314,314}},	{0,{0,0,0,314}},
{0,{0,0,0,314}},	{0,{314,287,314,287}},	{0,{314,314,287,287}},
{0,{0,0,0,314}},	{0,{0,0,0,314}},	{0,{0,0,0,314}},
{0,{314,314,314,314}},	{0,{314,314,314,314}},	{0,{314,314,314,314}},
{0,{314,314,314,314}},	{0,{314,314,314,314}},	{0,{314,314,314,314}},
{0,{314,314,314,314}},	{0,{314,315,315,315}},	{0,{315,314,314,314}},
{0,{315,316,316,316}},	{0,{316,0,0,0}},	{0,{316,311,311,311}},
{0,{310,310,310,310}},	{0,{312,312,312,312}},	{0,{314,314,314,314}},
{0,{314,314,314,314}},	{0,{0,0,0,314}},	{0,{314,314,308,308}},
{0,{0,0,0,314}},	{0,{314,314,314,314}},	{0,{0,0,0,314}},
{0,{314,314,314,314}},	{0,{314,314,314,314}},	{0,{314,314,302,302}},
{0,{314,314,0,0}},	{0,{0,0,0,314}},	{0,{314,314,314,314}},
{0,{314,314,0,0}},	{0,{314,315,315,0}},	{0,{315,0,0,0}},
{0,{315,313,313,0}},	{0,{315,312,312,0}},	{0,{311,311,311,0}},
{0,{314,314,314,314}},	{0,{314,314,314,314}},	{0,{314,314,314,314}},
{0,{0,0,314,0}},	{0,{0,0,314,0}},	{0,{314,0,0,0}},
{0,{0,0,0,314}},	{0,{314,314,314,314}},	{0,{0,0,0,314}},
{0,{314,314,314,314}},	{0,{0,0,0,314}},	{0,{314,314,314,314}},
{0,{0,0,0,314}},	{0,{0,0,0,314}},	{0,{314,314,314,314}},
{0,{297,314,295,0}},	{0,{0,314,0,0}},	{0,{0,314,0,0}},
{0,{0,314,0,0}},	{0,{314,314,314,0}},	{0,{314,314,314,314}},
{0,{0,0,314,0}},	{0,{0,0,0,314}},	{0,{0,0,0,314}},
{0,{285,286,314,0}},	{0,{314,314,0,0}},	{0,{286,284,312,0}},
{0,{292,0,313,0}},	{0,{0,0,0,313}},	{0,{0,0,0,313}},
{0,{0,313,0,0}},	{0,{313,219,219,219}},	{0,{313,218,218,218}},
{0,{279,313,305,0}},	{0,{313,314,216,216}},	{0,{314,313,215,215}},
{0,{314,214,214,214}},	{0,{314,213,213,213}},	{0,{212,314,212,212}},
{0,{314,314,314,211}},	{0,{314,314,314,230}},	{0,{314,0,315,0}},
{0,{0,0,314,0}},	{0,{312,314,313,0}},	{0,{0,313,0,0}},
{0,{0,312,311,0}},	{0,{309,0,0,0}},	{0,{0,311,0,0}},
{0,{299,202,202,202}},	{0,{300,201,201,201}},	{0,{309,200,200,200}},
{0,{309,309,309,199}},	{0,{309,309,309,198}},	{0,{0,0,0,309}},
{0,{296,309,196,196}},	{0,{195,308,195,195}},	{0,{308,194,194,194}},
{0,{308,193,193,193}},	{0,{297,272,0,0}},	{0,{0,307,0,0}},
{0,{0,307,0,0}},	{0,{0,307,0,0}},	{0,{307,307,0,0}},
{0,{307,307,307,307}},	{0,{307,307,307,307}},	{0,{307,307,307,307}},
{0,{307,307,307,307}},	{0,{307,307,307,307}},	{0,{307,307,307,307}},
{0,{307,307,307,307}},	{0,{307,307,307,307}},	{0,{307,0,0,0}},
{0,{307,307,307,0}},	{0,{307,307,307,307}},	{0,{307,307,307,307}},
{0,{307,307,307,307}},	{0,{307,307,307,307}},	{200,{0,0,0,0}},
{0,{306,306,306,306}},	{0,{306,306,306,306}},	{0,{306,306,306,306}},
{0,{306,306,306,306}},	{0,{306,306,306,306}},	{0,{306,306,306,306}},
{0,{306,306,306,306}},	{0,{306,306,306,0}},	{0,{306,306,306,306}},
{0,{306,306,306,306}},	{225,{0,0,0,0}},	{0,{305,305,305,305}},
{0,{305,305,305,305}},	{236,{0,0,0,0}},	{0,{0,304,0,0}},
{0,{304,304,304,0}},	{0,{304,0,0,0}},	{0,{304,304,304,0}},
{0,{304,304,0,0}},	{0,{0,0,0,304}},	{0,{304,304,304,304}},
{0,{0,0,304,0}},	{0,{304,302,302,302}},	{0,{304,301,301,301}},
{0,{304,300,300,300}},	{0,{304,299,299,299}},	{0,{304,304,0,0}},
{0,{304,304,304,304}},	{0,{304,304,304,296}},	{0,{304,295,295,295}},
{0,{0,304,0,0}},	{0,{0,304,0,0}},	{0,{304,0,0,0}},
{0,{304,0,0,0}},	{0,{304,0,0,0}},	{0,{304,289,289,289}},
{0,{304,288,288,288}},	{0,{304,304,304,0}},	{0,{304,304,0,0}},
{0,{304,0,0,0}},	{0,{304,304,304,304}},	{0,{304,304,304,304}},
{0,{304,304,304,304}},	{0,{304,304,0,0}},	{0,{304,304,304,304}},
{0,{304,0,0,0}},	{282,{0,0,0,0}},	{0,{0,0,0,303}},
{0,{303,303,303,0}},	{0,{0,0,303,0}},	{0,{303,0,0,0}},
{0,{303,297,297,297}},	{0,{303,303,0,0}},	{0,{303,303,0,0}},
{0,{303,0,304,0}},	{0,{302,0,0,0}},	{0,{303,0,0,0}},
{0,{303,303,303,0}},	{0,{0,0,0,303}},	{0,{303,303,303,0}},
{0,{303,0,303,0}},	{0,{303,0,0,0}},	{0,{303,0,304,0}},
{0,{302,0,304,0}},	{0,{304,304,304,0}},	{0,{0,0,304,0}},
{0,{304,304,304,305}},	{0,{305,305,305,305}},	{0,{305,305,305,305}},
{0,{302,302,302,302}},	{0,{304,0,0,0}},	{0,{304,304,304,304}},
{0,{304,304,304,304}},	{0,{304,0,0,0}},	{0,{304,0,0,0}},
{0,{304,305,304,305}},	{0,{305,305,305,305}},	{0,{305,305,305,305}},
{0,{305,305,305,305}},	{0,{301,301,301,301}},	{0,{304,304,304,304}},
{0,{304,304,304,304}},	{0,{304,304,304,304}},	{0,{304,304,304,304}},
{0,{304,304,304,304}},	{0,{304,304,304,304}},	{0,{304,304,304,304}},
{0,{304,305,0,0}},	{0,{304,304,0,0}},	{0,{304,304,0,0}},
{0,{304,304,0,0}},	{0,{304,304,305,305}},	{0,{305,305,305,305}},
{0,{303,303,303,303}},	{0,{0,0,0,304}},	{0,{304,304,305,305}},
{0,{304,304,304,304}},	{0,{304,0,0,0}},	{0,{304,304,304,304}},
{0,{304,304,304,0}},	{0,{304,304,304,304}},	{0,{304,0,0,0}},
{0,{0,304,0,0}},	{0,{0,0,0,304}},	{0,{304,304,304,304}},
{0,{304,0,0,0}},	{0,{304,304,304,0}},	{0,{304,304,304,304}},
{0,{0,0,0,304}},	{0,{0,0,0,304}},	{0,{0,0,0,304}},
{0,{0,0,0,304}},	{0,{304,0,0,0}},	{0,{0,0,304,0}},
{0,{304,304,304,304}},	{0,{304,304,304,304}},	{0,{304,304,304,304}},
{0,{304,304,304,304}},	{0,{304,304,304,304}},	{0,{0,0,304,0}},
{0,{298,298,298,304}},	{0,{0,0,0,304}},	{0,{304,304,304,304}},
{0,{304,304,304,304}},	{0,{304,304,304,304}},	{0,{304,304,304,304}},
{0,{304,304,304,304}},	{0,{304,304,304,0}},	{0,{0,304,0,0}},
{0,{304,304,0,0}},	{0,{0,0,304,0}},	{0,{0,304,0,0}},
{0,{304,304,304,304}},	{0,{304,0,0,0}},	{0,{0,304,0,0}},
{0,{304,304,0,0}},	{0,{304,0,0,0}},	{0,{304,304,0,0}},
{0,{304,304,304,0}},	{0,{304,0,0,0}},	{0,{304,0,0,0}},
{0,{304,304,304,304}},	{0,{304,304,304,0}},	{0,{304,303,303,0}},
{0,{304,304,304,0}},	{0,{304,304,304,304}},	{0,{304,304,304,304}},
{0,{0,304,0,0}},	{0,{304,0,0,0}},	{0,{304,0,0,0}},
{0,{0,0,0,304}},	{0,{304,304,304,0}},	{0,{304,304,304,0}},
{0,{304,304,304,304}},	{0,{304,304,304,304}},	{0,{304,304,304,304}},
{0,{304,304,304,0}},	{0,{304,304,304,304}},	{0,{0,0,304,0}},
{0,{304,304,304,0}},	{0,{0,0,304,0}},	{0,{0,0,0,304}},
{0,{304,304,304,0}},	{0,{304,304,304,0}},	{0,{0,304,0,0}},
{0,{304,0,0,0}},	{0,{304,0,0,0}},	{0,{304,304,305,305}},
{0,{305,305,306,306}},	{0,{306,306,307,307}},	{0,{307,307,308,308}},
{0,{308,308,308,308}},	{0,{308,308,308,308}},	{0,{308,308,308,308}},
{0,{308,308,308,308}},	{0,{308,308,308,308}},	{0,{308,308,308,308}},
{0,{308,308,308,308}},	{0,{308,308,308,308}},	{0,{308,308,308,308}},
{0,{308,309,310,311}},	{0,{311,311,311,311}},	{0,{311,311,311,311}},
{0,{289,289,289,289}},	{0,{290,290,290,290}},	{0,{291,291,291,291}},
{0,{292,292,292,292}},	{0,{302,302,303,304}},	{0,{303,303,303,303}},
{0,{305,305,305,305}},	{0,{305,290,290,290}},	{0,{305,305,306,306}},
{0,{306,306,306,306}},	{0,{306,306,306,306}},	{0,{306,306,306,306}},
{0,{302,302,302,302}},	{38,{0,0,0,0}},	{0,{304,304,304,304}},
{0,{304,304,304,304}},	{0,{304,304,304,304}},	{41,{0,0,0,0}},
{42,{0,0,0,0}},	{43,{0,0,0,0}},	{0,{301,301,301,301}},
{0,{301,301,301,301}},	{0,{301,301,301,301}},	{0,{301,301,301,301}},
{0,{301,301,301,301}},	{0,{301,301,301,301}},	{0,{301,301,301,301}},
{0,{301,302,302,302}},	{0,{302,302,302,302}},	{0,{302,301,301,301}},
{0,{302,303,303,303}},	{0,{302,302,302,302}},	{0,{302,0,0,0}},
{0,{296,296,296,296}},	{0,{301,301,301,301}},	{0,{301,301,301,301}},
{72,{0,0,0,0}},	{0,{300,300,300,300}},	{73,{0,0,0,0}},
{0,{299,299,299,299}},	{77,{0,0,0,0}},	{0,{298,298,298,298}},
{0,{298,298,298,298}},	{0,{298,298,298,298}},	{0,{298,298,298,298}},
{0,{298,0,0,0}},	{0,{298,298,298,298}},	{0,{298,298,0,0}},
{0,{298,298,298,298}},	{0,{298,298,298,298}},	{0,{298,298,298,298}},
{0,{298,298,298,298}},	{0,{298,298,298,298}},	{0,{0,298,0,0}},
{0,{298,0,0,0}},	{0,{298,298,298,298}},	{0,{298,298,298,298}},
{111,{0,0,0,0}},	{0,{297,297,297,297}},	{0,{297,297,297,297}},
{0,{297,297,297,297}},	{118,{0,0,0,0}},	{0,{296,296,296,296}},
{121,{0,0,0,0}},	{0,{295,295,295,295}},	{42,{295,295,295,295}},
{43,{294,294,294,294}},	{0,{294,294,294,294}},	{129,{279,279,279,279}},
{129,{0,0,0,0}},	{130,{0,0,0,0}},	{0,{291,291,291,291}},
{0,{291,291,291,291}},	{0,{291,291,291,291}},	{0,{291,291,291,291}},
{144,{0,0,0,0}},	{145,{0,0,0,0}},	{0,{289,289,289,289}},
{148,{0,0,0,0}},	{0,{288,288,288,288}},	{144,{288,288,288,288}},
{150,{0,0,0,0}},	{0,{287,287,287,287}},	{0,{287,287,287,287}},
{0,{287,213,213,213}},	{129,{287,287,287,287}},	{0,{287,288,289,288}},
{0,{289,210,210,210}},	{0,{289,209,209,209}},	{0,{285,285,286,285}},
{0,{284,284,284,284}},	{0,{287,287,287,287}},	{0,{287,287,287,287}},
{0,{287,287,287,287}},	{0,{287,287,287,287}},	{0,{287,287,287,287}},
{0,{287,287,287,287}},	{0,{287,287,287,287}},	{0,{199,199,287,199}},
{0,{287,287,287,287}},	{0,{287,287,287,287}},	{0,{287,287,287,287}},
{0,{287,195,195,195}},	{0,{287,194,194,194}},	{0,{287,193,193,193}},
{174,{0,0,0,0}},	{176,{0,0,0,0}},	{0,{285,285,285,285}},
{0,{285,285,285,285}},	{0,{285,285,286,286}},	{0,{286,286,287,287}},
{0,{287,287,287,287}},	{0,{287,287,287,287}},	{0,{282,282,282,282}},
{0,{283,283,283,283}},	{0,{285,285,285,285}},	{0,{285,285,285,285}},
{0,{285,285,285,285}},	{0,{285,285,285,285}},	{0,{285,285,285,285}},
{0,{285,285,286,286}},	{0,{285,285,285,285}},	{0,{285,285,285,285}},
{0,{285,285,285,285}},	{0,{285,285,285,285}},	{0,{285,285,285,285}},
{0,{285,285,285,285}},	{0,{285,285,285,285}},	{0,{285,285,285,285}},
{0,{285,285,285,285}},	{0,{285,285,285,285}},	{0,{285,285,285,285}},
{0,{285,285,285,285}},	{0,{285,285,285,285}},	{0,{285,285,285,285}},
{239,{0,0,0,0}},	{0,{284,284,284,284}},	{0,{284,284,284,284}},
{0,{284,284,284,284}},	{0,{284,284,284,284}},	{0,{0,0,0,284}},
{0,{284,284,284,284}},	{0,{284,284,284,284}},	{0,{284,285,285,285}},
{0,{285,285,286,285}},	{0,{283,283,283,283}},	{0,{283,283,283,283}},
{0,{284,284,284,284}},	{0,{284,284,284,284}},	{0,{284,284,284,284}},
{0,{284,278,284,278}},	{0,{0,284,0,0}},	{0,{0,284,0,0}},
{0,{0,284,0,0}},	{0,{284,284,284,284}},	{0,{0,284,0,0}},
{0,{284,284,285,284}},	{0,{283,283,283,283}},	{0,{284,284,284,284}},
{267,{0,0,0,0}},	{0,{283,283,0,0}},	{0,{283,283,283,0}},
{0,{283,283,0,0}},	{0,{0,0,0,283}},	{0,{283,283,283,283}},
{0,{283,0,0,0}},	{0,{283,283,283,283}},	{0,{283,283,283,283}},
{0,{283,283,283,283}},	{290,{0,0,0,0}},	{292,{0,0,0,0}},
{292,{277,0,0,0}},	{0,{0,0,0,280}},	{0,{0,0,0,280}},
{0,{0,0,0,280}},	{0,{0,0,0,280}},	{0,{280,280,280,280}},
{0,{280,280,280,280}},	{301,{0,0,0,0}},	{302,{0,0,0,0}},
{0,{278,278,278,278}},	{0,{0,0,0,278}},	{0,{0,0,0,278}},
{0,{0,0,0,278}},	{0,{0,0,0,278}},	{0,{278,278,278,278}},
{319,{0,0,0,0}},	{0,{277,277,277,277}},	{0,{277,277,277,277}},
{0,{277,277,277,277}},	{0,{277,277,277,277}},	{0,{277,277,277,277}},
{0,{277,277,277,277}},	{0,{277,277,277,277}},	{0,{277,277,277,277}},
{0,{0,277,0,0}},	{0,{277,277,277,277}},	{0,{277,277,277,277}},
{0,{277,277,277,277}},	{0,{277,277,277,277}},	{0,{277,277,277,277}},
{0,{277,277,277,277}},	{0,{277,277,277,277}},	{0,{277,277,277,277}},
{0,{277,277,277,277}},	{0,{277,277,277,277}},	{0,{277,277,277,277}},
{0,{277,277,277,277}},	{0,{277,277,278,0}},	{0,{277,277,277,0}},
{0,{277,277,0,0}},	{0,{277,277,277,277}},	{0,{277,277,277,277}},
{0,{277,277,277,277}},	{0,{277,277,277,277}},	{0,{277,277,0,0}},
{0,{277,277,277,277}},	{0,{277,277,277,277}},	{0,{0,0,0,277}},
{0,{277,277,277,277}},	{0,{277,277,277,0}},	{0,{277,277,277,277}},
{0,{277,277,277,0}},	{379,{0,0,0,0}},	{0,{276,0,0,0}},
{0,{276,276,276,276}},	{0,{276,276,276,0}},	{0,{276,0,0,0}},
{0,{276,276,276,276}},	{0,{276,276,276,276}},	{0,{276,276,276,276}},
{0,{276,0,0,0}},	{0,{276,0,0,0}},	{0,{276,276,276,276}},
{417,{0,0,0,0}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{275,275,275,275}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{275,0,0,0}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{275,275,275,275}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{275,275,275,275}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{0,0,0,275}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{0,0,275,0}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{0,0,0,275}},	{0,{275,275,275,0}},	{0,{275,275,275,275}},
{0,{275,275,275,0}},	{0,{275,275,275,275}},	{0,{275,0,0,0}},
{0,{275,275,0,0}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{275,275,275,275}},	{0,{275,275,275,275}},	{0,{275,275,275,275}},
{0,{275,275,275,275}},	{485,{0,0,0,0}},	{486,{0,0,0,0}},
{0,{273,273,0,0}},	{0,{273,0,0,0}},	{0,{273,273,273,273}},
{0,{273,273,273,273}},	{0,{273,273,273,273}},	{0,{273,273,273,273}},
{0,{273,273,0,0}},	{0,{273,273,273,273}},	{0,{273,273,273,0}},
{0,{273,273,273,273}},	{0,{273,273,273,273}},	{0,{273,273,273,273}},
{522,{0,0,0,0}},	{0,{272,272,272,0}},	{0,{272,272,272,272}},
{0,{0,272,0,0}},	{0,{272,272,0,0}},	{0,{0,272,0,0}},
{0,{272,272,272,273}},	{0,{271,271,271,271}},	{0,{272,272,272,273}},
{0,{271,271,271,271}},	{0,{272,272,272,273}},	{0,{271,271,271,271}},
{0,{272,272,272,273}},	{0,{271,271,271,271}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,257}},	{0,{272,272,272,273}},	{0,{271,271,271,271}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{0,{272,272,272,272}},	{0,{272,272,272,272}},
{0,{272,272,272,272}},	{90,{0,0,0,0}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,272}},	{0,{270,270,270,270}},
{0,{271,271,271,272}},	{0,{270,270,270,270}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,272}},	{0,{270,270,270,270}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,272}},	{0,{270,270,270,270}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,271}},	{0,{271,271,271,271}},	{0,{271,271,271,271}},
{0,{271,271,271,0}},	{0,{271,271,271,271}},	{0,{0,0,0,271}},
{0,{271,271,271,271}},	{280,{0,0,0,0}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{0,0,0,270}},
{0,{0,0,0,270}},	{0,{0,0,0,270}},	{0,{0,0,0,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{0,0,0,270}},	{0,{0,0,0,270}},	{0,{0,0,0,270}},
{0,{0,0,0,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{0,0,0,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{0,0,0,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{0,0,0,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{475,{0,0,0,0}},
{0,{269,269,269,269}},	{0,{269,269,269,269}},	{0,{269,269,269,269}},
{0,{269,269,269,269}},	{0,{269,269,269,269}},	{0,{269,269,269,269}},
{487,{0,0,0,0}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,0}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,267,267}},	{0,{268,268,268,268}},	{0,{268,268,267,267}},
{0,{268,268,268,268}},	{0,{268,268,267,267}},	{0,{268,268,268,268}},
{0,{268,268,267,267}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{253,253,268,253}},
{0,{268,268,268,268}},	{0,{268,268,267,267}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,269}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,267}},	{0,{268,268,268,269}},	{0,{268,268,268,268}},
{0,{268,268,268,0}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,0}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,0}},	{0,{0,0,268,0}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{0,0,0,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,195}},	{0,{268,268,268,268}},	{0,{268,269,269,269}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,190}},
{0,{268,189,189,189}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,181}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,177}},	{0,{268,176,176,176}},	{0,{268,268,268,175}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,267,267}},	{0,{268,268,268,268}},	{0,{268,268,267,267}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,267,267}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,0}},	{0,{268,0,0,0}},	{0,{268,0,0,0}},
{0,{0,0,0,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{0,0,0,268}},
{0,{0,0,0,268}},	{0,{0,0,0,268}},	{0,{0,0,0,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{0,0,0,268}},	{0,{0,0,0,268}},	{0,{0,0,0,268}},
{0,{0,0,0,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,0}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,0,0}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{0,0,0,268}},	{0,{268,268,268,268}},	{0,{268,268,268,0}},
{0,{268,268,268,268}},	{0,{268,268,268,0}},	{0,{268,268,0,0}},
{0,{268,268,268,268}},	{0,{268,268,268,0}},	{0,{0,0,268,0}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,0}},	{0,{268,268,268,0}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,0}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{0,0,0,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,0,0,0}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{0,0,0,268}},
{0,{0,268,0,0}},	{0,{268,268,268,268}},	{0,{268,268,268,0}},
{0,{268,268,268,268}},	{0,{268,268,268,0}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,0,0}},
{0,{268,268,268,268}},	{0,{268,268,268,268}},	{0,{268,268,268,268}},
{0,{268,268,268,268}},	{0,{268,268,0,0}},	{0,{268,268,268,268}},
{0,{268,269,0,0}},	{0,{269,269,269,269}},	{0,{269,269,269,269}},
{0,{269,269,269,269}},	{0,{269,0,0,0}},	{0,{269,269,269,269}},
{0,{0,269,0,0}},	{0,{269,269,0,0}},	{0,{0,0,269,0}},
{0,{269,269,269,269}},	{0,{269,269,269,269}},	{0,{269,269,269,269}},
{0,{269,269,269,269}},	{0,{269,269,269,269}},	{0,{269,269,269,269}},
{0,{269,269,269,269}},	{0,{269,269,269,269}},	{0,{269,269,269,269}},
{0,{269,269,269,269}},	{0,{269,269,269,269}},	{0,{269,269,269,269}},
{0,{269,269,269,269}},	{0,{269,269,269,269}},	{0,{269,269,269,269}},
{0,{269,269,269,269}},	{0,{269,269,269,269}},	{0,{269,269,269,269}},
{0,{269,269,269,269}},	{0,{269,269,269,269}},	{0,{269,269,269,269}},
{0,{269,269,269,269}},	{0,{269,0,270,0}},	{0,{270,270,270,270}},
{0,{270,254,254,254}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{0,0,0,270}},	{0,{270,270,270,262}},
{0,{270,270,270,0}},	{0,{270,270,0,0}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,0}},
{0,{270,270,270,0}},	{0,{270,270,270,270}},	{0,{270,270,270,0}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,0}},	{0,{270,270,270,270}},
{0,{270,0,270,0}},	{0,{0,0,0,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,197}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,189}},
{0,{270,270,270,270}},	{0,{270,206,206,206}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,0}},	{0,{270,270,270,0}},
{0,{270,270,270,182}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{177,177,270,177}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{0,0,0,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,0,0}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,0,0}},
{0,{270,270,0,0}},	{0,{270,271,271,271}},	{0,{270,270,270,270}},
{0,{270,0,0,0}},	{0,{270,270,270,268}},	{0,{270,270,270,0}},
{0,{0,0,0,270}},	{0,{0,0,0,270}},	{0,{0,0,0,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,0,0,0}},
{0,{270,270,270,270}},	{0,{270,0,0,0}},	{0,{270,270,270,270}},
{0,{270,270,0,0}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,0}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,270}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,0}},	{0,{270,0,0,0}},
{0,{0,0,0,270}},	{0,{270,0,0,0}},	{0,{270,270,270,270}},
{0,{270,270,270,270}},	{0,{270,270,270,0}},	{0,{270,270,270,270}},
{293,{0,0,270,0}},	{293,{0,0,0,0}},	{0,{0,0,269,0}},
{0,{0,0,269,0}},	{0,{269,269,269,269}},	{0,{0,0,0,269}},
{0,{269,269,269,269}},	{306,{0,0,0,0}},	{307,{0,0,0,0}},
{308,{0,0,267,0}},	{308,{0,0,0,0}},	{0,{266,266,266,0}},
{0,{266,266,266,266}},	{0,{266,266,266,266}},	{0,{266,266,266,266}},
{0,{266,266,266,266}},	{0,{266,266,266,0}},	{0,{266,266,266,266}},
{0,{266,266,266,266}},	{0,{266,266,266,266}},	{0,{266,266,266,0}},
{0,{266,266,266,266}},	{0,{266,266,266,266}},	{0,{266,266,266,266}},
{0,{266,266,266,266}},	{0,{266,266,266,266}},	{0,{266,266,266,266}},
{0,{266,266,266,266}},	{0,{266,266,266,266}},	{0,{266,266,266,266}},
{0,{266,266,266,266}},	{0,{266,266,266,266}},	{0,{266,266,266,266}},
{0,{266,266,266,266}},	{0,{266,266,266,266}},	{0,{266,266,266,266}},
{0,{266,266,266,266}},	{0,{266,266,266,266}},	{0,{266,266,266,266}},
{0,{266,266,266,266}},	{0,{266,0,0,0}},	{0,{266,266,266,266}},
{0,{266,266,266,266}},	{0,{0,0,0,266}},	{0,{266,266,0,0}},
{0,{266,0,0,0}},	{0,{266,266,266,266}},	{0,{266,266,266,0}},
{383,{0,0,0,0}},	{0,{265,265,265,265}},	{0,{265,265,265,265}},
{399,{0,0,0,0}},	{0,{264,264,264,264}},	{0,{0,0,264,0}},
{0,{264,264,264,0}},	{410,{0,0,0,0}},	{410,{263,263,263,0}},
{0,{263,0,263,0}},	{0,{263,263,263,263}},	{0,{263,263,263,263}},
{0,{263,263,263,263}},	{0,{263,263,263,263}},	{0,{263,263,263,263}},
{0,{263,263,263,263}},	{0,{263,263,263,263}},	{0,{263,263,263,263}},
{0,{263,263,263,0}},	{0,{263,262,262,0}},	{0,{263,263,263,263}},
{0,{263,263,263,263}},	{0,{263,263,0,0}},	{0,{263,263,263,263}},
{0,{0,0,0,263}},	{0,{263,263,263,263}},	{0,{263,263,263,0}},
{464,{0,0,0,0}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{0,0,0,262}},	{0,{262,0,0,0}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,0,0,0}},	{0,{262,262,262,262}},	{0,{262,261,261,261}},
{0,{262,262,0,0}},	{0,{262,262,0,0}},	{0,{262,262,262,262}},
{488,{0,0,0,0}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,0,0}},	{0,{261,261,261,257}},	{0,{261,261,261,0}},
{0,{0,0,0,261}},	{0,{0,0,261,0}},	{0,{0,0,261,0}},
{0,{261,0,0,0}},	{0,{0,0,261,0}},	{0,{261,0,0,0}},
{0,{0,0,0,261}},	{0,{0,0,0,261}},	{0,{0,0,0,261}},
{0,{261,0,0,0}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,0,0,0}},	{0,{261,0,0,0}},	{0,{261,261,261,261}},
{0,{245,245,245,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{261,261,261,261}},	{0,{261,261,261,261}},
{0,{261,261,261,261}},	{0,{0,0,0,261}},	{0,{261,261,261,261}},
{0,{261,261,262,262}},	{0,{262,262,0,0}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{0,0,0,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,0}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{0,{262,262,262,262}},
{0,{262,262,262,262}},	{0,{262,262,262,262}},	{103,{0,0,0,0}},
{104,{0,0,0,0}},	{0,{260,260,0,0}},	{0,{260,260,260,260}},
{0,{260,260,260,260}},	{0,{260,260,260,260}},	{0,{260,260,260,260}},
{0,{260,260,260,260}},	{0,{260,260,260,260}},	{0,{260,260,260,260}},
{0,{260,260,260,260}},	{0,{260,260,260,260}},	{0,{260,260,260,260}},
{140,{0,0,0,0}},	{0,{0,0,0,259}},	{0,{259,259,259,259}},
{0,{259,259,259,259}},	{0,{259,259,259,259}},	{0,{259,259,259,259}},
{0,{259,259,259,259}},	{0,{259,259,259,259}},	{0,{259,259,259,259}},
{0,{259,259,259,259}},	{0,{259,259,259,259}},	{0,{259,259,259,259}},
{0,{259,259,259,259}},	{0,{259,259,259,259}},	{0,{259,259,259,259}},
{0,{259,259,259,259}},	{0,{259,259,259,259}},	{0,{259,259,259,259}},
{0,{259,259,259,259}},	{164,{0,0,0,0}},	{165,{0,0,0,0}},
{0,{257,257,257,257}},	{0,{257,257,257,257}},	{0,{257,257,257,257}},
{0,{257,257,257,257}},	{0,{257,257,257,257}},	{0,{257,257,257,257}},
{0,{257,257,257,257}},	{0,{257,257,257,257}},	{0,{257,257,257,257}},
{0,{257,257,257,258}},	{0,{258,258,258,259}},	{0,{255,255,255,255}},
{0,{256,256,256,256}},	{0,{257,0,0,0}},	{0,{0,0,0,257}},
{0,{257,257,257,257}},	{0,{257,257,257,257}},	{0,{257,257,257,257}},
{188,{0,0,0,0}},	{0,{256,256,256,256}},	{0,{150,150,150,256}},
{0,{150,150,150,256}},	{0,{256,256,256,256}},	{202,{0,0,0,0}},
{203,{0,0,0,0}},	{0,{254,255,255,255}},	{0,{254,254,254,254}},
{0,{254,0,0,0}},	{208,{252,252,252,252}},	{208,{0,0,0,0}},
{216,{0,0,0,0}},	{0,{0,0,0,251}},	{0,{0,0,0,251}},
{0,{251,251,251,251}},	{0,{251,251,251,251}},	{0,{0,0,0,251}},
{0,{251,251,251,251}},	{0,{0,0,0,251}},	{0,{251,251,251,251}},
{250,{0,0,0,0}},	{0,{250,250,250,250}},	{0,{250,250,250,250}},
{0,{250,250,250,250}},	{0,{250,250,250,250}},	{0,{250,250,250,250}},
{0,{250,250,250,250}},	{0,{250,250,250,250}},	{0,{0,250,0,0}},
{0,{250,250,250,250}},	{0,{250,250,250,250}},	{0,{250,250,250,250}},
{0,{250,250,250,250}},	{0,{250,250,250,250}},	{0,{250,250,250,250}},
{0,{250,250,250,250}},	{0,{250,250,250,250}},	{0,{250,250,250,250}},
{0,{250,250,250,250}},	{0,{250,250,250,250}},	{0,{250,0,0,0}},
{0,{0,0,0,250}},	{0,{0,0,0,250}},	{0,{250,250,250,250}},
{0,{250,250,250,250}},	{285,{0,0,0,0}},	{0,{249,249,249,249}},
{294,{0,0,0,0}},	{295,{0,0,0,0}},	{0,{247,247,247,247}},
{0,{247,247,247,247}},	{0,{0,0,0,247}},	{0,{247,247,247,247}},
{309,{0,0,0,0}},	{0,{246,246,246,0}},	{0,{246,246,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,246,246}},
{0,{246,246,246,246}},	{0,{246,246,246,246}},	{0,{246,246,246,246}},
{369,{0,0,0,0}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{0,{245,245,245,245}},	{0,{245,245,245,245}},
{0,{245,245,245,245}},	{411,{0,0,0,0}},	{415,{0,0,0,0}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{0,{243,243,243,243}},
{0,{243,243,243,243}},	{0,{243,243,243,243}},	{460,{0,0,0,0}},
{0,{242,242,242,242}},	{0,{242,242,242,242}},	{0,{242,242,242,242}},
{0,{242,242,242,242}},	{467,{0,0,0,0}},	{0,{241,241,241,241}},
{0,{241,241,241,241}},	{0,{241,241,241,241}},	{0,{241,241,241,241}},
{0,{241,241,241,241}},	{0,{241,241,241,241}},	{0,{241,241,241,241}},
{0,{241,241,241,241}},	{0,{241,241,241,241}},	{483,{0,0,0,0}},
{0,{240,240,0,0}},	{0,{240,240,240,240}},	{0,{240,240,240,240}},
{502,{0,0,0,0}},	{0,{239,239,0,0}},	{506,{0,0,0,0}},
{0,{0,0,0,238}},	{0,{238,238,238,238}},	{0,{238,238,238,238}},
{0,{238,238,238,238}},	{0,{238,238,238,238}},	{0,{238,238,238,238}},
{0,{0,0,0,238}},	{0,{0,0,0,238}},	{0,{0,0,0,238}},
{0,{238,238,238,238}},	{0,{238,238,238,238}},	{0,{238,239,239,240}},
{0,{240,238,238,239}},	{0,{236,237,237,240}},	{0,{238,236,236,239}},
{0,{239,240,240,240}},	{0,{240,239,239,239}},	{0,{240,0,0,0}},
{0,{240,0,0,0}},	{0,{231,231,231,234}},	{0,{235,235,235,235}},
{0,{238,238,238,238}},	{0,{238,238,238,238}},	{0,{238,238,238,238}},
{0,{238,238,238,238}},	{0,{238,238,238,238}},	{0,{238,238,238,238}},
{0,{238,238,238,238}},	{0,{227,227,227,238}},	{0,{226,226,226,238}},
{0,{225,225,225,238}},	{0,{224,224,224,238}},	{0,{223,223,223,238}},
{0,{0,0,0,238}},	{0,{0,0,0,238}},	{0,{220,220,220,238}},
{0,{219,219,219,238}},	{0,{217,218,218,238}},	{0,{218,217,217,237}},
{0,{216,216,216,237}},	{0,{0,0,0,237}},	{0,{0,0,0,237}},
{0,{0,0,0,237}},	{0,{207,207,207,208}},	{0,{211,211,211,236}},
{0,{0,0,0,236}},	{0,{236,0,0,0}},	{0,{236,236,236,236}},
{0,{0,0,0,236}},	{0,{0,0,0,236}},	{0,{0,0,0,236}},
{0,{236,236,236,236}},	{0,{236,236,236,236}},	{0,{236,236,236,236}},
{0,{236,236,236,236}},	{0,{236,236,236,236}},	{0,{236,236,236,236}},
{0,{236,236,236,236}},	{0,{236,236,236,236}},	{0,{236,236,236,236}},
{0,{236,236,236,236}},	{0,{236,236,236,236}},	{0,{232,232,232,236}},
{0,{236,236,236,236}},	{0,{0,0,0,236}},	{84,{0,0,0,0}},
{0,{235,235,235,235}},	{0,{235,235,235,235}},	{0,{235,235,235,235}},
{0,{235,235,235,235}},	{0,{0,0,0,235}},	{0,{0,0,0,235}},
{0,{0,0,0,235}},	{0,{0,0,0,235}},	{0,{0,0,0,235}},
{0,{0,0,0,235}},	{0,{0,0,0,235}},	{0,{0,0,0,235}},
{0,{0,0,0,235}},	{0,{0,0,0,235}},	{0,{235,235,235,235}},
{0,{174,174,174,235}},	{0,{235,235,235,235}},	{0,{0,0,0,235}},
{0,{0,0,0,235}},	{0,{0,0,0,235}},	{0,{235,235,235,235}},
{0,{0,0,0,235}},	{0,{0,0,0,235}},	{0,{0,0,0,235}},
{0,{0,0,0,235}},	{0,{235,235,235,235}},	{0,{163,163,163,235}},
{0,{0,0,0,235}},	{0,{161,161,161,235}},	{0,{160,160,160,235}},
{0,{159,159,159,235}},	{0,{158,158,158,235}},	{0,{157,157,157,235}},
{0,{156,156,156,235}},	{0,{155,155,155,235}},	{0,{154,154,154,235}},
{0,{0,0,0,235}},	{0,{0,0,0,235}},	{0,{151,151,151,235}},
{0,{150,150,150,235}},	{0,{149,149,149,235}},	{0,{0,0,235,0}},
{0,{147,147,147,235}},	{0,{146,146,146,235}},	{0,{145,145,145,235}},
{0,{0,0,0,235}},	{0,{0,0,0,235}},	{0,{235,236,236,236}},
{0,{234,235,235,236}},	{0,{236,234,234,234}},	{0,{235,233,233,234}},
{0,{0,0,0,235}},	{0,{0,0,0,235}},	{0,{235,235,235,235}},
{0,{0,0,0,235}},	{0,{235,235,235,235}},	{0,{0,0,0,235}},
{0,{134,0,0,235}},	{0,{134,0,0,234}},	{0,{0,0,0,234}},
{0,{234,234,234,235}},	{0,{235,235,235,0}},	{0,{233,233,233,233}},
{219,{0,0,0,0}},	{220,{0,0,0,0}},	{0,{232,232,232,232}},
{0,{0,0,0,232}},	{0,{0,0,0,232}},	{0,{0,0,0,232}},
{0,{0,0,0,232}},	{0,{232,232,232,232}},	{0,{232,232,232,232}},
{0,{232,232,232,232}},	{0,{232,232,232,232}},	{0,{232,232,232,232}},
{0,{228,228,228,232}},	{0,{227,227,227,232}},	{0,{232,232,232,232}},
{0,{0,0,0,232}},	{0,{224,224,224,232}},	{0,{232,232,232,232}},
{0,{0,0,0,232}},	{0,{0,0,0,232}},	{0,{232,232,232,232}},
{0,{0,0,0,232}},	{0,{232,232,232,232}},	{0,{217,217,217,232}},
{0,{216,216,216,232}},	{0,{232,232,232,232}},	{0,{0,0,0,232}},
{0,{232,232,232,232}},	{270,{0,0,0,0}},	{271,{0,0,0,0}},
{0,{230,230,230,230}},	{0,{0,0,0,230}},	{0,{0,0,0,230}},
{0,{230,230,230,230}},	{0,{230,230,230,230}},	{0,{0,0,0,230}},
{0,{230,230,230,230}},	{0,{0,0,0,230}},	{0,{230,230,230,230}},
{0,{230,230,230,230}},	{0,{0,0,0,230}},	{0,{0,0,0,230}},
{0,{230,230,230,230}},	{0,{230,230,230,230}},	{0,{230,230,230,230}},
{0,{0,0,0,230}},	{0,{0,0,0,230}},	{0,{230,230,230,231}},
{0,{229,229,229,229}},	{0,{230,230,230,230}},	{0,{227,227,227,230}},
{0,{230,230,230,230}},	{0,{230,0,0,231}},	{0,{231,231,231,232}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{221,221,221,230}},
{0,{230,230,230,231}},	{0,{229,229,229,229}},	{0,{230,230,230,230}},
{0,{230,230,230,230}},	{0,{230,230,230,230}},	{0,{230,230,230,230}},
{0,{229,229,229,230}},	{0,{0,0,0,230}},	{0,{230,230,230,230}},
{0,{230,230,230,230}},	{0,{225,225,225,230}},	{0,{0,0,0,230}},
{0,{230,230,230,230}},	{0,{230,230,230,230}},	{0,{230,230,230,230}},
{0,{230,230,230,230}},	{0,{209,0,0,0}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,228,228}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{228,228,228,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{229,230,230,230}},	{0,{230,229,229,229}},	{0,{230,228,228,228}},
{0,{230,227,227,227}},	{0,{230,226,226,226}},	{0,{230,225,225,225}},
{0,{224,224,224,224}},	{0,{229,223,223,223}},	{0,{229,0,0,0}},
{0,{229,0,0,0}},	{0,{229,220,220,220}},	{0,{229,229,229,229}},
{0,{228,228,229,228}},	{0,{0,0,229,0}},	{0,{216,216,229,216}},
{0,{229,229,229,225}},	{0,{229,229,229,0}},	{0,{213,213,213,229}},
{0,{212,212,212,229}},	{0,{211,211,211,229}},	{0,{210,210,210,229}},
{0,{209,209,209,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{206,206,206,229}},	{0,{205,205,205,229}},	{0,{229,204,204,204}},
{0,{203,203,203,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{199,199,199,229}},	{0,{0,0,0,229}},
{0,{229,0,0,0}},	{0,{229,229,0,0}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{229,229,0,0}},
{0,{229,229,0,0}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{225,225,225,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{229,0,0,0}},
{0,{229,229,0,0}},	{0,{229,163,163,163}},	{0,{229,0,0,0}},
{0,{229,0,0,0}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,0,0,0}},	{0,{0,0,0,229}},	{0,{229,153,153,153}},
{0,{152,152,152,229}},	{0,{0,0,0,229}},	{0,{150,150,150,229}},
{0,{149,149,149,229}},	{0,{148,148,148,229}},	{0,{147,147,147,229}},
{0,{146,146,146,229}},	{0,{145,145,145,229}},	{0,{144,144,144,229}},
{0,{143,143,143,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{140,140,140,229}},	{0,{139,139,139,229}},	{0,{138,138,138,229}},
{0,{229,0,0,0}},	{0,{136,136,136,229}},	{0,{135,135,135,229}},
{0,{134,134,134,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,0,0,0}},	{0,{229,0,0,0}},	{0,{229,0,0,0}},
{0,{229,0,0,0}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,229,0,0}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{229,0,0,0}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,0,0}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{225,225,225,229}},	{0,{224,224,224,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{221,221,221,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{214,214,214,229}},	{0,{213,213,213,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,0,0,0}},	{0,{229,0,0,0}},	{0,{229,229,229,229}},
{0,{229,0,0,0}},	{0,{229,0,0,0}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{229,229,0,0}},	{0,{229,228,0,0}},
{0,{229,229,219,219}},	{0,{229,226,0,0}},	{0,{229,229,229,229}},
{0,{229,0,0,0}},	{0,{229,0,0,0}},	{0,{229,229,229,229}},
{0,{229,228,228,228}},	{0,{229,220,0,0}},	{0,{229,229,226,226}},
{0,{229,228,225,225}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,228,228,228}},
{0,{229,0,0,0}},	{0,{229,229,229,229}},	{0,{229,229,0,0}},
{0,{224,224,224,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,0,0,0}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,0}},	{0,{229,228,228,0}},
{0,{229,229,229,229}},	{0,{229,229,226,0}},	{0,{229,229,0,0}},
{0,{0,0,0,229}},	{0,{229,223,223,0}},	{0,{229,0,0,0}},
{0,{229,229,229,229}},	{0,{228,228,228,229}},	{0,{229,219,219,0}},
{0,{229,221,218,0}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,0,0}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{229,230,230,230}},	{0,{230,230,230,230}},
{0,{228,228,228,228}},	{0,{229,230,230,230}},	{0,{230,226,226,226}},
{0,{228,228,228,228}},	{0,{229,225,225,225}},	{0,{229,224,224,224}},
{0,{229,0,0,0}},	{0,{229,0,0,0}},	{0,{229,229,229,221}},
{0,{229,229,229,229}},	{0,{228,229,228,228}},	{0,{0,229,0,0}},
{0,{229,229,229,217}},	{0,{229,225,225,225}},	{0,{229,0,0,0}},
{0,{214,214,214,229}},	{0,{213,213,213,229}},	{0,{212,212,212,229}},
{0,{211,211,211,229}},	{0,{210,210,210,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{207,207,207,229}},	{0,{206,206,206,229}},
{0,{229,205,205,205}},	{0,{204,204,204,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{200,200,200,229}},
{0,{0,0,0,229}},	{0,{229,0,0,0}},	{0,{229,229,0,0}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,229,0,0}},	{0,{229,229,0,0}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{225,225,225,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,0,0,0}},	{0,{229,229,0,0}},	{0,{229,164,164,164}},
{0,{229,229,0,0}},	{0,{229,0,0,0}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{229,0,0,0}},	{0,{0,0,0,229}},
{0,{229,154,154,154}},	{0,{153,153,153,229}},	{0,{0,0,0,229}},
{0,{151,151,151,229}},	{0,{150,150,150,229}},	{0,{149,149,149,229}},
{0,{148,148,148,229}},	{0,{147,147,147,229}},	{0,{146,146,146,229}},
{0,{145,145,145,229}},	{0,{144,144,144,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{141,141,141,229}},	{0,{140,140,140,229}},
{0,{139,139,139,229}},	{0,{0,229,0,0}},	{0,{137,137,137,229}},
{0,{136,136,136,229}},	{0,{135,135,135,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{229,0,0,0}},	{0,{229,0,0,0}},
{0,{229,0,0,0}},	{0,{229,0,0,0}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{229,229,0,0}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{229,0,0,0}},
{0,{0,0,0,229}},	{0,{229,229,229,230}},	{0,{229,229,229,229}},
{0,{229,229,229,0}},	{0,{229,229,0,0}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{225,225,225,229}},
{0,{224,224,224,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{221,221,221,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{214,214,214,229}},	{0,{213,213,213,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,0,0,0}},	{0,{229,0,0,0}},
{0,{229,229,229,229}},	{0,{229,229,0,0}},	{0,{229,229,0,0}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{229,229,0,0}},
{0,{229,228,0,0}},	{0,{229,229,219,219}},	{0,{229,226,0,0}},
{0,{229,229,229,229}},	{0,{229,0,0,0}},	{0,{229,0,0,0}},
{0,{229,229,229,229}},	{0,{229,228,228,228}},	{0,{229,220,0,0}},
{0,{229,229,226,226}},	{0,{229,228,225,225}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,228,228,228}},	{0,{229,0,0,0}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{224,224,224,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,0,0,0}},
{0,{229,229,229,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,0,0}},
{0,{229,228,0,0}},	{0,{229,229,229,229}},	{0,{229,229,0,0}},
{0,{229,229,0,0}},	{0,{0,0,0,229}},	{0,{229,223,0,0}},
{0,{229,0,0,0}},	{0,{229,229,229,229}},	{0,{228,228,228,229}},
{0,{229,219,0,0}},	{0,{229,221,0,0}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,0,0}},	{0,{0,0,0,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{229,229,229,229}},	{0,{229,229,229,229}},	{0,{229,229,229,229}},
{0,{0,0,0,229}},	{0,{0,0,0,229}},	{0,{0,0,0,229}},
{0,{0,0,0,229}},	{0,{229,229,229,229}},	{0,{229,230,231,231}},
{0,{231,232,0,0}},	{0,{232,231,0,0}},	{0,{232,230,0,0}},
{0,{232,229,0,0}},	{0,{232,233,234,234}},	{0,{234,224,225,225}},
{0,{234,231,232,232}},	{0,{223,223,223,223}},	{0,{230,230,230,230}},
{0,{232,223,0,0}},	{0,{0,232,0,0}},	{20,{0,231,0,0}},
{20,{0,0,0,0}},	{0,{230,219,0,0}},	{22,{0,228,0,0}},
{22,{0,0,0,0}},	{0,{228,216,0,0}},	{0,{228,215,0,0}},
{0,{228,214,0,0}},	{0,{228,213,0,0}},	{0,{228,212,0,0}},
{0,{228,0,0,0}},	{0,{228,0,0,0}},	{0,{228,209,0,0}},
{0,{228,208,0,0}},	{0,{228,207,0,0}},	{0,{228,206,0,0}},
{0,{228,0,0,0}},	{0,{228,0,0,0}},	{0,{228,228,228,228}},
{0,{228,202,0,0}},	{0,{228,228,228,228}},	{0,{228,228,228,228}},
{51,{228,228,228,228}},	{0,{228,228,228,228}},	{0,{228,228,228,228}},
{0,{228,228,228,228}},	{51,{0,0,0,0}},	{0,{227,227,227,227}},
{0,{227,228,229,0}},	{0,{229,227,0,0}},	{0,{229,226,0,0}},
{0,{229,225,226,0}},	{0,{229,224,225,0}},	{0,{189,223,0,0}},
{0,{223,0,223,0}},	{0,{0,227,0,0}},	{0,{227,227,0,0}},
{0,{210,219,0,0}},	{0,{226,0,0,0}},	{0,{226,226,226,226}},
{0,{226,216,0,0}},	{0,{226,0,0,0}},	{0,{226,226,226,226}},
{0,{226,226,226,226}},	{0,{0,0,0,226}},	{0,{0,0,0,226}},
{0,{0,0,0,226}},	{0,{0,0,0,226}},	{0,{0,0,0,226}},
{0,{0,0,0,226}},	{0,{0,0,0,226}},	{0,{0,0,0,226}},
{0,{226,226,226,226}},	{0,{226,226,226,226}},	{0,{226,226,226,0}},
{0,{226,166,0,0}},	{0,{0,0,0,226}},	{0,{226,226,226,226}},
{0,{0,0,0,226}},	{0,{0,0,0,226}},	{0,{226,0,0,0}},
{0,{0,0,0,226}},	{0,{0,0,0,226}},	{149,{0,0,0,0}},
{0,{0,0,0,225}},	{0,{225,156,0,0}},	{0,{225,155,0,0}},
{0,{0,0,0,225}},	{0,{225,153,0,0}},	{0,{225,152,0,0}},
{0,{225,151,0,0}},	{0,{225,150,0,0}},	{0,{225,149,0,0}},
{0,{225,148,0,0}},	{0,{225,147,0,0}},	{0,{225,146,0,0}},
{0,{0,0,0,225}},	{0,{0,0,0,225}},	{0,{225,143,0,0}},
{0,{225,142,0,0}},	{0,{225,141,0,0}},	{0,{0,0,0,225}},
{0,{225,139,0,0}},	{0,{225,138,0,0}},	{0,{225,137,0,0}},
{0,{0,0,0,225}},	{0,{0,0,0,225}},	{0,{225,225,225,225}},
{0,{225,225,225,225}},	{0,{225,224,225,224}},	{0,{225,225,225,225}},
{0,{225,225,225,0}},	{0,{225,225,0,0}},	{0,{225,0,0,0}},
{0,{225,0,0,0}},	{0,{225,225,0,0}},	{0,{0,0,225,0}},
{0,{225,0,225,0}},	{0,{0,0,0,225}},	{206,{225,225,225,225}},
{0,{224,224,224,224}},	{206,{0,0,0,0}},	{0,{223,223,0,0}},
{0,{223,0,0,0}},	{0,{223,0,0,0}},	{0,{223,0,0,0}},
{0,{223,0,0,0}},	{0,{223,223,0,0}},	{0,{223,223,223,223}},
{0,{0,223,0,0}},	{0,{223,223,223,221}},	{0,{223,222,222,220}},
{0,{223,219,219,219}},	{0,{223,218,218,218}},	{0,{223,223,0,0}},
{0,{223,223,223,223}},	{0,{215,215,215,223}},	{0,{223,223,223,224}},
{0,{224,0,0,0}},	{0,{224,0,0,0}},	{0,{0,224,0,0}},
{0,{224,0,0,0}},	{0,{224,0,0,0}},	{0,{224,208,208,208}},
{0,{224,207,207,207}},	{0,{224,224,0,0}},	{0,{0,0,224,0}},
{0,{224,224,224,224}},	{0,{224,224,0,0}},	{0,{0,0,0,224}},
{0,{224,224,0,0}},	{0,{224,224,224,224}},	{0,{224,224,0,0}},
{0,{0,224,0,0}},	{0,{224,224,0,0}},	{0,{0,0,0,224}},
{0,{224,0,225,0}},	{0,{0,0,224,0}},	{0,{224,225,0,0}},
{0,{224,224,0,0}},	{0,{224,0,0,0}},	{0,{224,0,0,0}},
{0,{224,0,0,0}},	{0,{224,0,0,0}},	{0,{224,0,0,0}},
{0,{224,0,225,0}},	{0,{225,0,224,0}},	{0,{225,0,226,0}},
{0,{226,215,222,0}},	{0,{0,226,0,0}},	{0,{226,0,0,0}},
{351,{0,0,0,0}},	{0,{225,0,209,0}},	{351,{224,0,208,0}},
{351,{215,0,216,0}},	{0,{223,0,218,0}},	{351,{222,0,217,0}},
{0,{0,0,222,0}},	{0,{0,0,222,0}},	{0,{222,222,222,222}},
{0,{0,0,222,0}},	{0,{222,0,221,0}},	{0,{221,0,0,0}},
{0,{221,0,0,0}},	{0,{0,0,0,221}},	{0,{221,0,217,0}},
{0,{220,0,0,0}},	{0,{220,220,220,220}},	{0,{220,220,220,0}},
{374,{0,0,0,0}},	{0,{219,219,0,0}},	{0,{0,0,0,219}},
{0,{219,0,0,0}},	{0,{0,0,0,219}},	{0,{0,0,0,219}},
{0,{219,219,219,219}},	{0,{219,218,218,218}},	{0,{219,0,0,0}},
{0,{219,216,220,216}},	{0,{193,0,220,0}},	{0,{220,0,0,0}},
{0,{213,213,213,220}},	{0,{0,0,0,220}},	{0,{220,220,220,220}},
{0,{220,220,220,220}},	{0,{220,209,209,209}},	{0,{220,208,212,208}},
{0,{220,220,220,220}},	{0,{220,0,0,0}},	{0,{220,220,0,0}},
{0,{220,220,220,220}},	{0,{220,220,0,0}},	{0,{220,0,0,0}},
{0,{220,0,0,0}},	{0,{220,0,0,0}},	{0,{220,0,0,0}},
{0,{220,0,0,0}},	{0,{220,0,0,0}},	{0,{220,220,220,220}},
{0,{220,0,0,0}},	{0,{220,0,0,0}},	{0,{220,0,0,0}},
{0,{0,0,0,220}},	{0,{220,0,0,0}},	{0,{220,0,0,0}},
{0,{0,0,0,220}},	{0,{220,0,0,0}},	{0,{220,220,220,220}},
{0,{220,220,220,220}},	{0,{220,0,0,0}},	{0,{220,0,0,0}},
{0,{220,0,0,0}},	{0,{220,220,0,0}},	{0,{0,220,0,0}},
{0,{0,0,0,220}},	{0,{0,0,0,220}},	{0,{220,220,220,220}},
{5,{220,220,220,220}},	{11,{220,220,220,220}},	{0,{219,219,219,219}},
{5,{219,219,219,219}},	{11,{0,0,0,0}},	{5,{0,0,0,0}},
{5,{217,217,217,217}},	{5,{217,217,217,217}},	{5,{217,217,217,217}},
{11,{217,217,217,217}},	{0,{216,216,216,216}},	{5,{210,210,210,210}},
{5,{214,214,214,214}},	{5,{214,214,214,214}},	{19,{0,0,0,0}},
{5,{213,213,213,213}},	{5,{213,213,213,213}},	{5,{213,213,213,213}},
{5,{213,213,213,213}},	{5,{213,213,213,213}},	{5,{213,213,213,213}},
{0,{213,0,0,0}},	{0,{213,0,0,0}},	{5,{213,213,213,213}},
{5,{213,0,0,0}},	{5,{213,213,213,213}},	{36,{0,0,0,0}},
{37,{0,0,0,0}},	{35,{0,0,0,0}},	{0,{210,210,0,0}},
{40,{0,0,0,0}},	{0,{209,0,0,0}},	{0,{209,0,0,0}},
{0,{209,0,0,0}},	{0,{209,210,0,0}},	{0,{210,0,0,0}},
{0,{208,208,0,0}},	{0,{209,0,0,0}},	{5,{209,209,209,209}},
{10,{0,0,0,0}},	{0,{208,208,208,208}},	{5,{208,208,208,208}},
{5,{208,208,208,208}},	{5,{208,208,208,208}},	{5,{204,204,204,204}},
{70,{0,0,0,0}},	{71,{0,0,0,0}},	{76,{0,0,0,0}},
{0,{204,0,0,0}},	{5,{204,204,204,0}},	{0,{203,203,203,0}},
{0,{203,203,0,0}},	{0,{203,203,203,203}},	{0,{0,0,0,203}},
{0,{0,0,0,203}},	{0,{0,0,0,203}},	{0,{0,0,0,203}},
{0,{0,0,0,203}},	{0,{0,0,0,203}},	{0,{0,0,0,203}},
{0,{0,0,0,203}},	{0,{203,203,0,0}},	{0,{0,203,0,0}},
{120,{0,0,0,0}},	{5,{202,0,0,0}},	{0,{202,202,202,202}},
{0,{202,0,0,0}},	{0,{0,0,0,202}},	{0,{0,0,0,202}},
{141,{0,0,0,0}},	{0,{0,0,0,201}},	{0,{0,0,0,201}},
{0,{0,0,0,201}},	{5,{201,0,0,0}},	{5,{201,201,201,201}},
{0,{0,0,0,201}},	{5,{201,201,201,201}},	{5,{201,201,201,201}},
{5,{201,201,201,201}},	{5,{201,201,201,201}},	{5,{201,201,201,201}},
{5,{201,0,0,0}},	{161,{0,0,0,0}},	{36,{200,0,0,0}},
{0,{0,0,0,200}},	{0,{0,0,0,200}},	{5,{200,0,0,0}},
{161,{200,200,200,200}},	{161,{200,200,200,200}},	{0,{200,200,200,200}},
{5,{200,200,200,200}},	{5,{200,0,0,0}},	{5,{200,200,200,200}},
{0,{0,0,0,200}},	{0,{0,0,0,200}},	{0,{200,200,200,126}},
{0,{200,200,200,0}},	{0,{200,199,199,0}},	{0,{200,200,200,128}},
{0,{200,0,0,0}},	{182,{0,0,0,0}},	{0,{199,199,199,199}},
{184,{0,0,0,0}},	{186,{0,0,0,0}},	{0,{197,0,0,0}},
{0,{197,0,0,0}},	{0,{0,0,0,197}},	{0,{197,0,0,0}},
{0,{197,197,197,197}},	{0,{197,0,0,0}},	{0,{197,0,0,0}},
{246,{0,0,0,0}},	{0,{196,0,0,0}},	{249,{0,0,0,0}},
{0,{195,195,195,195}},	{0,{195,195,195,195}},	{0,{195,195,195,195}},
{0,{195,195,195,195}},	{0,{195,195,195,195}},	{0,{195,195,195,195}},
{256,{0,0,0,0}},	{0,{194,0,0,0}},	{0,{187,187,187,194}},
{0,{194,194,194,194}},	{0,{194,194,194,194}},	{260,{0,0,0,0}},
{261,{0,0,0,0}},	{0,{192,192,192,192}},	{263,{0,0,0,0}},
{0,{191,191,191,191}},	{0,{191,191,191,191}},	{0,{191,191,191,191}},
{266,{0,0,0,0}},	{0,{190,190,0,0}},	{0,{190,190,190,190}},
{0,{190,190,190,190}},	{0,{0,0,0,190}},	{289,{0,0,0,0}},
{0,{189,189,189,189}},	{298,{0,0,0,0}},	{300,{0,0,0,0}},
{303,{0,0,0,0}},	{0,{0,0,0,186}},	{329,{0,0,0,0}},
{330,{0,0,0,0}},	{0,{184,184,184,184}},	{0,{184,184,184,184}},
{0,{184,184,184,184}},	{0,{184,184,184,184}},	{0,{184,184,184,184}},
{0,{184,184,184,184}},	{0,{184,0,0,0}},	{340,{0,0,0,0}},
{341,{0,0,0,0}},	{340,{182,182,182,182}},	{343,{0,0,0,0}},
{345,{0,0,0,0}},	{340,{173,173,173,173}},	{346,{0,0,0,0}},
{0,{178,178,178,178}},	{354,{0,0,0,0}},	{355,{0,0,0,0}},
{0,{176,176,176,176}},	{0,{176,176,176,176}},	{0,{176,176,176,176}},
{0,{176,176,176,176}},	{0,{176,176,176,176}},	{0,{176,176,176,176}},
{0,{176,176,176,176}},	{368,{0,0,0,0}},	{0,{0,0,175,0}},
{0,{175,175,0,0}},	{0,{175,175,175,0}},	{0,{0,0,0,175}},
{405,{0,0,0,0}},	{0,{174,0,0,0}},	{0,{174,0,0,0}},
{0,{174,174,0,0}},	{0,{174,174,0,0}},	{0,{174,174,174,174}},
{343,{171,171,0,0}},	{344,{170,170,0,0}},	{344,{0,0,0,0}},
{0,{171,171,171,171}},	{0,{171,171,172,172}},	{0,{171,171,171,171}},
{0,{171,171,0,0}},	{0,{171,170,0,0}},	{0,{163,171,0,0}},
{343,{162,170,0,0}},	{0,{170,0,0,0}},	{454,{0,0,0,0}},
{461,{0,0,0,0}},	{0,{168,0,0,0}},	{0,{168,168,168,168}},
{466,{0,0,0,0}},	{469,{0,0,0,0}},	{470,{0,0,0,0}},
{471,{0,0,0,0}},	{472,{0,0,0,0}},	{0,{163,163,163,163}},
{0,{0,0,163,0}},	{479,{0,0,0,0}},	{479,{162,0,0,0}},
{482,{0,0,0,0}},	{0,{0,0,0,161}},	{493,{0,0,0,0}},
{501,{0,0,0,0}},	{0,{0,0,0,159}},	{515,{0,0,0,0}},
{0,{158,158,158,158}},	{0,{158,158,158,158}},	{0,{158,0,0,0}},
{0,{158,0,0,0}},	{0,{158,0,0,0}},	{524,{0,0,0,0}},
{525,{0,0,0,0}},	{0,{0,0,0,156}},	{0,{0,0,0,156}},
{0,{156,156,156,156}},	{0,{156,157,157,157}},	{0,{156,156,156,156}},
{0,{156,0,0,0}},	{0,{156,0,0,0}},	{0,{156,0,0,0}},
{0,{156,157,157,157}},	{0,{156,156,156,156}},	{0,{0,0,0,156}},
{0,{0,0,0,156}},	{0,{156,0,0,0}},	{0,{156,0,0,0}},
{0,{156,0,0,0}},	{0,{156,0,0,0}},	{0,{156,0,0,0}},
{0,{0,156,0,0}},	{0,{0,156,0,0}},	{0,{156,0,0,0}},
{0,{156,0,0,0}},	{0,{156,0,0,0}},	{39,{0,0,0,0}},
{48,{0,0,0,0}},	{0,{154,154,154,154}},	{0,{154,154,154,154}},
{54,{154,154,154,154}},	{0,{153,153,153,153}},	{54,{0,0,0,0}},
{0,{152,152,152,152}},	{0,{152,153,154,154}},	{0,{153,153,153,153}},
{0,{153,154,0,0}},	{0,{153,153,0,0}},	{0,{149,149,150,150}},
{81,{0,0,0,0}},	{0,{0,0,0,151}},	{0,{151,151,151,151}},
{0,{151,151,151,151}},	{0,{151,0,152,0}},	{0,{152,0,0,0}},
{0,{150,0,150,0}},	{0,{151,0,0,0}},	{0,{151,0,148,0}},
{0,{151,151,151,151}},	{0,{151,151,0,0}},	{0,{151,0,0,0}},
{116,{0,0,0,0}},	{0,{150,150,150,150}},	{0,{150,150,150,150}},
{0,{0,0,0,150}},	{0,{150,150,150,150}},	{0,{150,0,0,0}},
{0,{0,0,150,0}},	{0,{150,151,0,0}},	{0,{150,150,0,0}},
{0,{150,0,0,0}},	{0,{0,0,0,150}},	{0,{0,0,0,150}},
{0,{150,0,0,0}},	{0,{150,151,151,151}},	{0,{151,0,0,0}},
{0,{151,0,0,0}},	{0,{151,151,151,151}},	{0,{147,147,147,147}},
{160,{0,0,0,0}},	{162,{0,0,0,0}},	{0,{148,0,0,0}},
{0,{148,0,0,0}},	{0,{0,0,0,148}},	{0,{148,0,0,0}},
{0,{148,0,0,0}},	{0,{0,0,0,148}},	{0,{148,148,148,148}},
{0,{148,148,148,148}},	{0,{148,148,0,0}},	{0,{148,0,0,0}},
{0,{148,0,0,0}},	{179,{82,82,82,82}},	{179,{0,0,0,0}},
{179,{146,146,146,146}},	{179,{84,84,84,84}},	{0,{145,145,145,145}},
{0,{145,145,145,145}},	{189,{0,0,0,0}},	{0,{141,141,141,141}},
{0,{143,0,0,0}},	{0,{143,143,143,143}},	{0,{143,143,143,143}},
{234,{0,0,0,0}},	{245,{0,0,0,0}},	{0,{0,0,141,0}},
{0,{0,141,0,0}},	{0,{0,0,0,141}},	{0,{141,139,0,0}},
{0,{141,138,0,0}},	{0,{141,137,0,0}},	{0,{141,136,0,0}},
{0,{141,141,141,141}},	{0,{141,134,0,0}},	{0,{141,133,0,0}},
{0,{141,132,0,0}},	{0,{0,0,0,141}},	{0,{0,0,0,141}},
{0,{108,129,0,0}},	{0,{108,128,0,0}},	{0,{0,0,0,139}},
{0,{139,139,139,139}},	{0,{139,139,0,0}},	{0,{139,0,0,0}},
{0,{139,139,0,0}},	{0,{139,139,139,139}},	{0,{139,140,140,140}},
{0,{139,139,139,139}},	{0,{0,0,0,139}},	{0,{139,139,139,139}},
{0,{138,138,138,139}},	{0,{139,0,0,0}},	{0,{0,0,0,139}},
{0,{139,139,139,139}},	{0,{139,139,139,139}},	{0,{139,140,0,0}},
{0,{139,139,0,0}},	{0,{139,139,139,0}},	{0,{139,139,0,0}},
{0,{139,0,0,0}},	{0,{0,0,0,139}},	{0,{0,0,0,139}},
{370,{0,0,0,0}},	{0,{138,138,138,138}},	{0,{138,138,138,138}},
{0,{138,138,138,0}},	{0,{0,0,0,138}},	{0,{0,0,0,138}},
{420,{0,0,0,0}},	{420,{137,137,137,137}},	{0,{0,0,0,137}},
{0,{137,137,137,137}},	{420,{0,0,0,137}},	{0,{0,0,0,136}},
{425,{0,0,0,0}},	{427,{0,0,0,0}},	{420,{134,134,134,134}},
{451,{0,0,0,0}},	{463,{0,0,0,0}},	{0,{132,132,132,132}},
{0,{132,132,132,0}},	{478,{0,0,0,0}},	{480,{0,0,0,0}},
{0,{130,130,130,130}},	{0,{130,130,130,130}},	{0,{130,130,130,130}},
{0,{130,130,130,130}},	{518,{0,0,0,0}},	{519,{0,0,0,0}},
{520,{0,0,0,0}},	{0,{127,127,127,127}},	{0,{0,0,0,127}},
{0,{0,0,0,127}},	{0,{127,127,127,127}},	{0,{127,127,127,127}},
{0,{127,127,127,127}},	{0,{127,127,127,127}},	{0,{127,127,127,127}},
{0,{127,127,127,127}},	{0,{127,127,127,127}},	{0,{127,127,127,127}},
{0,{127,127,127,127}},	{0,{127,127,127,127}},	{0,{127,127,127,127}},
{0,{127,127,127,127}},	{0,{127,127,127,127}},	{0,{127,127,127,127}},
{0,{127,0,0,0}},	{0,{127,0,0,0}},	{0,{127,127,127,127}},
{0,{0,0,0,127}},	{0,{127,127,127,127}},	{0,{0,0,0,127}},
{0,{127,127,127,127}},	{0,{127,127,0,0}},	{0,{127,127,127,127}},
{0,{127,127,127,127}},	{0,{127,127,127,127}},	{0,{127,127,127,127}},
{0,{127,127,127,127}},	{0,{127,127,127,127}},	{0,{127,127,127,127}},
{0,{127,127,127,0}},	{0,{127,127,127,127}},	{0,{127,127,127,127}},
{0,{127,127,127,127}},	{0,{127,127,127,127}},	{0,{127,127,127,127}},
{0,{127,127,127,127}},	{0,{127,0,0,0}},	{0,{127,127,127,127}},
{0,{127,127,127,127}},	{0,{127,127,127,127}},	{0,{127,127,127,127}},
{0,{127,127,127,127}},	{0,{127,127,127,127}},	{138,{0,0,0,0}},
{139,{0,0,0,0}},	{146,{125,125,125,125}},	{146,{0,0,0,0}},
{0,{124,124,124,124}},	{0,{124,124,124,124}},	{0,{124,124,124,124}},
{0,{124,124,124,124}},	{0,{124,124,124,124}},	{0,{124,124,124,124}},
{0,{124,124,124,124}},	{0,{124,124,124,124}},	{0,{124,124,124,124}},
{0,{124,124,124,124}},	{163,{0,0,0,0}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{178,{0,0,0,0}},	{0,{0,0,0,122}},
{0,{122,0,0,0}},	{0,{122,122,122,122}},	{196,{0,0,0,0}},
{0,{121,0,0,0}},	{0,{121,121,121,121}},	{0,{0,0,0,121}},
{251,{0,0,0,0}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,0,0,0}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,0,0,0}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,0,0,0}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,0,0,0}},	{0,{120,121,0,0}},
{0,{121,121,121,121}},	{0,{121,121,121,121}},	{0,{0,0,0,121}},
{0,{0,0,0,121}},	{0,{121,121,121,121}},	{0,{121,121,121,121}},
{0,{121,121,121,121}},	{0,{121,121,121,121}},	{0,{0,0,121,122}},
{0,{0,0,0,121}},	{0,{121,121,121,121}},	{0,{121,121,121,121}},
{0,{0,0,0,121}},	{0,{0,0,0,121}},	{0,{121,122,123,124}},
{0,{120,121,122,0}},	{0,{123,124,125,126}},	{0,{118,126,120,0}},
{0,{119,119,119,0}},	{0,{125,125,125,125}},	{0,{125,125,125,125}},
{0,{122,122,116,0}},	{0,{124,124,124,124}},	{0,{0,0,0,124}},
{0,{124,124,124,124}},	{0,{124,124,124,124}},	{0,{124,124,124,124}},
{0,{124,124,124,124}},	{0,{124,124,124,125}},	{0,{124,124,124,124}},
{0,{124,124,124,124}},	{0,{124,124,124,125}},	{0,{124,124,124,124}},
{0,{0,0,0,124}},	{0,{124,124,124,124}},	{0,{124,124,124,124}},
{0,{124,124,124,124}},	{0,{124,124,124,124}},	{0,{124,124,124,124}},
{0,{124,124,124,124}},	{0,{124,124,124,124}},	{109,{0,0,0,0}},
{0,{123,123,123,0}},	{0,{123,123,123,123}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{0,{0,0,0,123}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{0,0,0,123}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{123,124,124,124}},
{0,{123,123,123,123}},	{0,{123,0,0,0}},	{0,{123,86,86,86}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{0,0,0,123}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{0,0,0,123}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{0,{0,0,0,123}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{0,{123,0,0,0}},	{0,{123,65,65,65}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{0,{0,0,0,123}},	{0,{0,0,0,123}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{0,{123,123,123,123}},
{0,{123,123,123,123}},	{0,{123,123,123,123}},	{315,{0,0,0,0}},
{0,{122,122,122,123}},	{0,{121,121,121,121}},	{0,{0,0,0,122}},
{0,{122,122,122,122}},	{0,{121,121,121,122}},	{0,{0,122,0,0}},
{0,{0,0,0,122}},	{0,{122,122,122,122}},	{0,{122,122,122,122}},
{0,{122,122,123,0}},	{0,{122,122,122,0}},	{0,{122,122,122,122}},
{0,{122,122,122,122}},	{0,{0,0,0,122}},	{0,{0,0,0,122}},
{0,{0,0,0,122}},	{0,{122,122,122,122}},	{0,{122,122,122,122}},
{0,{122,122,122,122}},	{0,{0,0,0,122}},	{0,{0,0,0,122}},
{0,{122,122,122,122}},	{0,{0,0,0,122}},	{0,{122,122,122,122}},
{0,{0,0,0,122}},	{0,{122,122,122,122}},	{0,{122,122,122,122}},
{0,{122,122,122,122}},	{0,{122,122,122,122}},	{505,{121,121,121,121}},
{505,{0,0,0,0}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{0,0,0,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,0,120,0}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{0,0,0,120}},	{0,{0,0,0,120}},
{0,{120,121,0,0}},	{0,{121,120,0,0}},	{0,{119,119,0,0}},
{0,{120,0,0,0}},	{0,{120,117,0,0}},	{0,{120,116,0,0}},
{0,{120,115,0,0}},	{0,{120,0,0,0}},	{0,{120,113,0,0}},
{0,{120,0,0,0}},	{0,{120,0,0,0}},	{0,{0,0,120,0}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,121,121,121}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,121,121,121}},
{0,{120,120,120,120}},	{0,{0,0,0,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,0,121,0}},	{0,{121,0,121,0}},
{0,{121,0,121,0}},	{0,{121,0,120,0}},	{0,{117,0,117,0}},
{0,{120,120,120,0}},	{0,{120,0,0,0}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{0,0,0,120}},	{0,{120,120,120,120}},
{0,{112,120,112,0}},	{0,{0,120,0,0}},	{0,{0,0,0,120}},
{0,{120,120,120,120}},	{0,{120,0,108,0}},	{0,{120,121,121,121}},
{0,{120,120,120,120}},	{0,{120,0,0,0}},	{0,{120,0,0,0}},
{0,{120,120,120,120}},	{0,{120,0,0,0}},	{0,{0,0,0,120}},
{0,{120,120,120,0}},	{0,{120,120,120,0}},	{0,{0,0,0,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,0,0}},
{0,{120,120,0,0}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,0}},	{0,{0,0,0,120}},	{0,{120,0,0,0}},
{0,{120,0,0,0}},	{0,{120,0,0,0}},	{0,{120,0,0,0}},
{0,{120,120,120,120}},	{0,{120,0,120,0}},	{0,{120,0,0,0}},
{0,{120,0,0,0}},	{0,{0,0,0,120}},	{0,{0,0,0,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,0,0}},
{0,{120,0,0,0}},	{0,{0,0,120,0}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{0,0,0,120}},	{0,{120,120,120,120}},
{0,{119,119,119,120}},	{0,{120,0,0,0}},	{0,{0,0,0,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,121,0,0}},
{0,{120,120,0,0}},	{0,{120,120,0,0}},	{0,{120,120,0,0}},
{0,{120,120,120,120}},	{0,{0,0,0,120}},	{0,{0,0,0,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,0,0,0}},
{0,{0,0,0,120}},	{0,{0,0,0,120}},	{0,{120,120,120,120}},
{0,{0,0,0,120}},	{0,{120,120,120,120}},	{0,{0,0,0,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,0,0,0}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{0,0,120,0}},	{0,{0,0,0,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,121,121}},
{0,{121,0,0,0}},	{0,{121,116,116,116}},	{0,{121,118,118,118}},
{0,{121,115,115,115}},	{0,{121,0,0,0}},	{0,{115,115,115,115}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,0,0}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,120,120,120}},
{0,{120,120,120,120}},	{0,{120,120,120,120}},	{0,{120,121,121,121}},
{0,{121,122,122,122}},	{0,{122,0,0,0}},	{0,{118,118,118,118}},
{0,{119,119,119,119}},	{89,{0,0,0,0}},	{0,{119,119,119,119}},
{0,{119,119,0,0}},	{97,{0,0,0,0}},	{95,{0,0,0,0}},
{94,{0,0,0,0}},	{98,{0,0,0,0}},	{100,{0,0,0,0}},
{0,{114,114,114,114}},	{113,{0,0,0,0}},	{0,{113,113,113,113}},
{0,{113,113,113,113}},	{0,{0,0,0,113}},	{0,{113,113,113,113}},
{147,{0,0,0,0}},	{151,{0,0,0,0}},	{0,{111,111,111,111}},
{0,{111,0,0,0}},	{155,{0,0,0,0}},	{0,{110,111,111,111}},
{0,{111,0,0,0}},	{0,{109,109,109,109}},	{0,{110,108,108,108}},
{0,{110,0,110,0}},	{112,{0,0,0,0}},	{0,{109,0,0,0}},
{0,{109,109,109,109}},	{0,{109,109,109,109}},	{0,{0,0,0,109}},
{0,{109,0,109,0}},	{0,{109,0,0,0}},	{0,{109,0,0,0}},
{177,{0,0,0,0}},	{0,{108,108,108,108}},	{0,{108,108,108,108}},
{0,{108,108,108,108}},	{0,{108,108,108,108}},	{0,{108,108,108,108}},
{0,{108,108,108,108}},	{252,{0,0,0,0}},	{253,{0,0,0,0}},
{253,{106,0,0,0}},	{0,{106,106,106,106}},	{0,{106,105,105,105}},
{0,{106,106,106,106}},	{258,{0,0,0,0}},	{253,{105,105,105,0}},
{0,{104,104,104,0}},	{0,{0,104,0,0}},	{0,{0,104,0,0}},
{0,{104,104,0,0}},	{0,{104,104,104,104}},	{0,{104,104,104,104}},
{281,{0,0,0,0}},	{0,{0,0,0,103}},	{0,{103,103,103,103}},
{0,{103,103,103,103}},	{333,{0,0,0,0}},	{0,{102,102,102,102}},
{0,{102,102,102,102}},	{0,{102,102,102,102}},	{0,{102,0,0,0}},
{0,{102,102,102,102}},	{0,{102,102,102,102}},	{0,{102,102,103,0}},
{0,{102,102,102,0}},	{0,{102,102,0,0}},	{0,{102,102,102,102}},
{0,{102,102,102,102}},	{366,{0,0,0,0}},	{0,{0,0,0,101}},
{0,{101,101,101,0}},	{0,{101,101,101,0}},	{0,{101,0,0,0}},
{0,{0,0,0,101}},	{0,{0,0,0,101}},	{0,{101,101,101,101}},
{422,{0,0,0,0}},	{0,{100,0,0,0}},	{0,{0,0,0,100}},
{0,{100,100,100,100}},	{0,{100,100,100,100}},	{0,{100,0,0,0}},
{0,{100,100,100,100}},	{0,{100,100,100,100}},	{0,{100,100,100,100}},
{0,{0,100,0,0}},	{0,{100,100,100,0}},	{0,{100,0,0,0}},
{0,{100,100,100,100}},	{0,{100,100,100,100}},	{0,{100,100,100,100}},
{0,{100,100,100,100}},	{0,{100,100,100,100}},	{0,{95,95,95,100}},
{0,{95,95,95,100}},	{0,{100,100,100,100}},	{0,{100,100,100,100}},
{0,{100,100,100,100}},	{0,{100,100,100,100}},	{0,{100,100,100,100}},
{0,{100,100,100,100}},	{0,{100,100,100,100}},	{0,{100,100,100,100}},
{0,{100,100,100,100}},	{0,{100,100,100,100}},	{0,{100,100,100,100}},
{0,{100,100,100,100}},	{0,{100,100,100,100}},	{0,{0,100,0,0}},
{0,{100,100,100,100}},	{0,{100,100,100,100}},	{0,{100,100,100,100}},
{0,{100,100,100,100}},	{0,{100,100,100,100}},	{62,{100,100,100,100}},
{0,{99,99,99,99}},	{62,{99,99,99,99}},	{0,{98,98,98,98}},
{62,{0,0,0,0}},	{0,{97,97,97,97}},	{93,{0,0,0,0}},
{0,{96,96,96,96}},	{0,{96,96,96,96}},	{0,{96,96,96,96}},
{123,{0,0,0,0}},	{0,{95,95,95,95}},	{0,{95,95,95,95}},
{153,{0,0,0,0}},	{157,{94,94,94,94}},	{0,{93,93,93,93}},
{157,{0,0,0,0}},	{0,{92,92,92,92}},	{159,{0,0,0,0}},
{166,{0,0,0,0}},	{0,{90,90,90,90}},	{0,{90,90,90,90}},
{0,{90,90,90,90}},	{170,{0,0,0,0}},	{0,{89,89,89,89}},
{0,{89,89,89,89}},	{0,{89,89,89,89}},	{0,{89,89,89,89}},
{0,{89,89,89,89}},	{0,{89,89,89,89}},	{0,{89,89,89,89}},
{0,{89,89,89,89}},	{0,{0,0,0,89}},	{0,{89,89,89,89}},
{0,{89,89,89,89}},	{0,{89,89,89,89}},	{259,{0,0,0,0}},
{262,{0,0,0,0}},	{265,{0,0,0,0}},	{0,{86,86,86,86}},
{0,{86,86,86,0}},	{0,{86,86,86,86}},	{0,{0,0,0,86}},
{0,{86,86,86,86}},	{0,{86,86,86,86}},	{0,{86,86,86,86}},
{0,{86,86,86,86}},	{0,{86,86,86,86}},	{337,{0,0,0,0}},
{0,{85,85,85,85}},	{0,{85,85,85,85}},	{0,{85,85,85,85}},
{0,{85,85,85,85}},	{0,{85,85,85,85}},	{0,{85,85,85,85}},
{0,{85,85,85,85}},	{0,{85,85,85,85}},	{0,{85,85,85,85}},
{0,{85,85,85,85}},	{0,{85,85,85,85}},	{407,{0,0,0,0}},
{408,{0,0,0,0}},	{0,{83,83,83,83}},	{423,{0,0,0,0}},
{424,{0,0,0,0}},	{0,{81,81,81,81}},	{0,{81,81,81,81}},
{474,{0,0,0,0}},	{0,{80,80,80,80}},	{0,{80,80,80,80}},
{0,{80,80,80,80}},	{527,{0,0,0,0}},	{0,{79,79,79,0}},
{530,{0,0,0,0}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{73,73,73,78}},	{0,{73,73,73,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{0,0,0,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{0,0,0,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{73,73,73,78}},	{0,{73,73,73,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,0,0,0}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{0,0,0,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,0,0,0}},
{0,{78,78,78,78}},	{0,{0,0,0,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,0,0}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,0,0,0}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,0,0,0}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,0}},	{0,{78,0,0,0}},
{0,{78,78,78,78}},	{0,{0,0,0,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,0,0}},
{0,{78,78,78,0}},	{0,{78,78,78,0}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,0,0,0}},	{0,{0,0,78,0}},
{0,{78,78,0,0}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,0,79,0}},	{0,{78,0,78,0}},
{0,{0,0,0,78}},	{0,{78,78,78,78}},	{0,{0,0,0,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,0}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{0,{78,78,78,78}},	{0,{78,78,78,78}},
{0,{78,78,78,78}},	{171,{0,0,0,0}},	{0,{77,77,77,77}},
{0,{0,0,0,77}},	{0,{77,77,77,77}},	{0,{77,77,77,77}},
{0,{77,0,0,0}},	{0,{77,77,77,77}},	{0,{0,0,0,77}},
{0,{77,77,77,77}},	{0,{77,77,77,77}},	{0,{77,77,77,77}},
{0,{77,77,77,0}},	{268,{0,0,0,0}},	{0,{76,0,0,0}},
{0,{76,76,76,76}},	{296,{0,0,0,0}},	{0,{75,75,75,75}},
{0,{75,75,75,75}},	{0,{75,75,75,75}},	{0,{75,75,75,75}},
{0,{75,75,75,75}},	{0,{75,75,75,75}},	{0,{75,75,75,75}},
{0,{75,75,75,75}},	{0,{75,75,75,75}},	{0,{75,75,75,75}},
{0,{75,75,75,75}},	{0,{75,75,75,75}},	{367,{0,0,0,0}},
{371,{0,0,0,0}},	{375,{0,0,0,0}},	{0,{72,72,72,72}},
{0,{72,72,72,72}},	{0,{72,72,72,72}},	{0,{72,72,72,72}},
{0,{72,72,72,72}},	{516,{0,0,0,0}},	{517,{0,0,0,0}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{0,0,0,70}},	{0,{70,70,70,70}},	{0,{0,0,0,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{0,{70,70,70,70}},
{0,{70,70,70,70}},	{0,{70,70,70,70}},	{91,{0,0,0,0}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{69,69,69,0}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,0,0}},	{0,{69,69,69,69}},	{0,{69,69,69,70}},
{0,{69,69,69,69}},	{0,{69,69,69,0}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,70}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{69,70,70,0}},
{0,{70,0,0,0}},	{0,{68,68,68,0}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,65,65,0}},	{0,{69,0,0,0}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,0,0,0}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,0,69,0}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{69,0,0,0}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,0,0}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{69,70,70,70}},
{0,{69,69,69,69}},	{0,{69,0,0,0}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,65,65,65}},	{0,{69,0,0,0}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,0,0,0}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,69,0}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{0,0,0,69}},
{0,{0,0,0,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{0,{69,0,0,0}},
{0,{69,69,69,69}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{69,69,69,69}},	{0,{0,0,0,69}},	{0,{0,0,0,69}},
{0,{69,69,0,0}},	{0,{69,69,69,69}},	{0,{69,69,69,69}},
{0,{0,0,0,69}},	{0,{0,0,0,69}},	{8,{69,0,0,0}},
{0,{68,0,0,0}},	{8,{0,0,0,0}},	{0,{67,0,0,0}},
{0,{67,0,0,0}},	{8,{67,68,68,68}},	{8,{67,67,67,67}},
{0,{67,0,0,0}},	{0,{67,0,0,0}},	{0,{0,0,0,67}},
{0,{0,0,0,67}},	{0,{0,0,0,67}},	{0,{0,0,0,67}},
{0,{67,67,67,67}},	{0,{0,0,0,67}},	{0,{0,0,0,67}},
{0,{0,0,0,67}},	{0,{0,0,0,67}},	{0,{0,0,0,67}},
{0,{0,0,0,67}},	{0,{0,0,0,67}},	{0,{67,0,0,0}},
{0,{67,67,67,67}},	{0,{67,67,67,67}},	{0,{0,0,0,67}},
{0,{67,67,67,67}},	{0,{67,67,67,67}},	{0,{67,67,67,67}},
{0,{0,0,0,67}},	{0,{67,67,67,67}},	{0,{67,0,0,0}},
{0,{67,67,67,67}},	{0,{67,0,0,0}},	{0,{0,0,0,67}},
{0,{0,0,0,67}},	{0,{0,0,0,67}},	{0,{0,0,0,67}},
{169,{0,0,0,0}},	{0,{0,0,0,66}},	{0,{66,66,66,0}},
{0,{0,0,0,66}},	{0,{66,66,0,0}},	{0,{66,66,66,66}},
{0,{66,66,0,0}},	{0,{0,0,0,66}},	{0,{66,66,66,66}},
{0,{0,0,0,66}},	{0,{0,0,0,66}},	{0,{0,0,0,66}},
{0,{66,66,66,66}},	{0,{66,66,66,66}},	{0,{66,0,0,0}},
{0,{66,0,0,0}},	{0,{66,0,0,0}},	{0,{66,0,0,0}},
{0,{0,0,0,66}},	{0,{66,0,0,0}},	{0,{66,0,0,0}},
{0,{66,66,66,66}},	{0,{66,66,66,66}},	{0,{66,66,66,66}},
{0,{66,66,66,66}},	{0,{66,0,0,0}},	{0,{0,0,0,66}},
{0,{66,0,0,0}},	{0,{66,66,0,0}},	{0,{66,66,0,0}},
{0,{0,0,0,66}},	{0,{0,0,0,66}},	{0,{66,66,66,66}},
{0,{66,66,66,66}},	{0,{66,66,66,66}},	{0,{66,66,66,66}},
{0,{66,66,66,66}},	{0,{66,66,66,66}},	{0,{66,66,66,66}},
{0,{0,0,0,66}},	{0,{0,0,0,66}},	{0,{0,0,0,66}},
{0,{0,0,0,66}},	{0,{66,66,66,66}},	{0,{0,0,0,66}},
{0,{0,0,0,66}},	{0,{0,0,0,66}},	{0,{0,0,0,66}},
{0,{0,0,0,66}},	{0,{0,0,0,66}},	{0,{0,0,0,66}},
{0,{66,66,66,66}},	{0,{66,0,0,0}},	{0,{66,66,0,0}},
{0,{0,0,0,66}},	{0,{66,66,0,0}},	{0,{66,66,66,66}},
{0,{66,66,66,66}},	{0,{0,0,0,66}},	{0,{66,0,0,0}},
{0,{66,0,0,0}},	{0,{66,0,0,0}},	{0,{66,0,0,0}},
{0,{0,0,0,66}},	{0,{0,0,0,66}},	{0,{0,0,0,66}},
{0,{0,0,0,66}},	{0,{0,0,0,66}},	{0,{66,0,0,0}},
{0,{0,0,0,66}},	{183,{0,0,0,0}},	{0,{65,65,65,65}},
{231,{0,0,0,0}},	{0,{0,0,0,64}},	{0,{64,64,64,64}},
{0,{0,0,0,64}},	{0,{0,0,0,64}},	{0,{0,0,0,64}},
{0,{64,64,64,64}},	{0,{64,64,64,64}},	{331,{0,0,0,0}},
{331,{63,63,63,63}},	{334,{0,0,0,0}},	{334,{62,62,62,62}},
{0,{0,0,0,62}},	{342,{0,0,0,0}},	{0,{61,61,61,61}},
{0,{61,61,61,61}},	{0,{61,61,61,61}},	{0,{61,61,61,61}},
{0,{61,61,61,61}},	{0,{53,53,53,53}},	{0,{0,0,0,60}},
{0,{60,60,0,0}},	{0,{60,60,0,0}},	{465,{0,0,0,0}},
{0,{0,0,0,59}},	{0,{0,0,0,59}},	{0,{59,0,0,0}},
{0,{59,0,0,0}},	{0,{59,0,0,0}},	{0,{59,60,60,60}},
{0,{59,59,59,59}},	{0,{0,0,0,59}},	{0,{0,0,0,59}},
{0,{59,0,0,0}},	{0,{59,0,0,0}},	{0,{59,0,0,0}},
{0,{59,0,0,0}},	{0,{59,0,0,0}},	{0,{59,0,0,0}},
{0,{59,0,0,0}},	{0,{59,0,0,0}},	{0,{59,0,0,0}},
{0,{59,0,0,0}},	{0,{59,0,0,0}},	{0,{59,0,0,0}},
{0,{59,0,0,0}},	{0,{59,59,59,59}},	{52,{0,0,0,0}},
{0,{58,58,58,58}},	{56,{0,0,0,0}},	{0,{57,58,0,0}},
{0,{57,57,0,0}},	{0,{0,0,0,57}},	{117,{0,0,0,0}},
{122,{0,0,0,0}},	{126,{0,0,0,0}},	{0,{0,0,0,54}},
{0,{54,0,0,0}},	{0,{54,0,0,0}},	{0,{54,0,0,0}},
{0,{54,0,0,0}},	{0,{54,54,0,0}},	{180,{0,0,0,0}},
{0,{53,53,53,53}},	{0,{53,53,53,53}},	{0,{53,53,0,0}},
{0,{53,0,0,0}},	{0,{53,0,0,0}},	{0,{53,0,0,0}},
{0,{53,53,53,53}},	{0,{53,53,53,53}},	{0,{53,53,0,0}},
{0,{53,0,0,0}},	{0,{0,0,0,53}},	{0,{53,0,0,0}},
{0,{53,53,53,53}},	{0,{53,54,0,0}},	{0,{53,53,0,0}},
{0,{53,53,53,53}},	{0,{53,53,0,0}},	{0,{0,0,0,53}},
{0,{53,53,53,53}},	{439,{0,0,0,0}},	{0,{0,0,0,52}},
{0,{0,0,0,52}},	{0,{52,52,52,52}},	{0,{52,52,52,52}},
{0,{52,52,52,52}},	{0,{52,52,52,52}},	{0,{52,52,52,52}},
{0,{52,52,52,52}},	{0,{52,52,52,52}},	{23,{52,52,52,52}},
{23,{0,0,0,0}},	{23,{51,51,51,51}},	{23,{51,51,51,51}},
{0,{51,51,51,51}},	{23,{51,51,51,51}},	{23,{51,51,51,51}},
{23,{51,51,51,51}},	{0,{50,50,50,50}},	{0,{50,0,0,0}},
{0,{50,0,0,0}},	{0,{0,0,0,50}},	{0,{50,50,50,50}},
{0,{0,0,0,50}},	{0,{50,50,0,0}},	{63,{50,50,50,50}},
{63,{0,0,0,0}},	{0,{0,0,0,49}},	{0,{49,49,49,49}},
{0,{49,49,49,49}},	{0,{49,49,49,49}},	{167,{0,0,0,0}},
{168,{0,0,0,0}},	{0,{47,47,47,47}},	{0,{47,0,0,0}},
{0,{47,0,0,0}},	{248,{0,0,0,0}},	{0,{46,46,46,46}},
{0,{46,46,46,46}},	{0,{46,46,46,46}},	{0,{46,0,0,0}},
{0,{46,46,46,46}},	{273,{0,0,0,0}},	{0,{45,45,45,45}},
{0,{45,45,45,45}},	{0,{45,45,45,45}},	{0,{45,45,45,45}},
{359,{45,45,45,45}},	{359,{0,0,0,0}},	{0,{44,44,44,44}},
{365,{0,0,0,0}},	{0,{0,0,0,43}},	{0,{43,43,43,43}},
{0,{0,0,0,43}},	{0,{0,0,0,43}},	{0,{43,43,43,43}},
{0,{43,0,0,0}},	{0,{0,0,0,43}},	{0,{43,43,43,43}},
{0,{43,43,43,43}},	{0,{0,0,0,43}},	{0,{0,0,0,43}},
{0,{43,44,0,0}},	{0,{44,0,0,0}},	{0,{44,0,0,0}},
{0,{0,0,0,44}},	{0,{44,45,46,46}},	{0,{46,45,45,45}},
{0,{44,44,44,44}},	{32,{0,0,0,0}},	{31,{0,0,0,0}},
{0,{43,43,43,43}},	{0,{0,0,0,43}},	{0,{43,43,43,43}},
{55,{0,0,0,0}},	{0,{42,42,42,0}},	{0,{0,0,42,0}},
{0,{0,0,0,42}},	{0,{42,0,0,0}},	{0,{42,33,33,33}},
{0,{42,42,42,42}},	{181,{0,0,0,0}},	{0,{41,41,41,41}},
{0,{41,41,41,41}},	{0,{41,22,0,0}},	{0,{41,26,27,27}},
{257,{0,0,0,0}},	{0,{40,40,40,40}},	{0,{0,0,0,40}},
{0,{0,0,0,40}},	{0,{40,0,0,0}},	{0,{40,40,40,40}},
{0,{40,40,0,0}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{0,0,0,40}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{0,0,0,40}},	{0,{40,40,40,40}},
{0,{0,0,0,40}},	{0,{40,40,40,40}},	{110,{0,0,0,0}},
{0,{39,39,39,39}},	{0,{39,39,39,39}},	{0,{39,39,39,39}},
{0,{39,39,39,39}},	{0,{0,0,0,39}},	{0,{39,39,39,39}},
{0,{39,39,39,39}},	{0,{39,39,39,39}},	{0,{0,0,0,39}},
{0,{39,39,39,39}},	{0,{39,39,39,39}},	{0,{39,39,39,39}},
{0,{39,39,39,39}},	{0,{39,39,39,39}},	{0,{39,39,39,39}},
{0,{39,39,39,39}},	{0,{39,39,39,39}},	{0,{39,0,0,0}},
{0,{0,0,0,39}},	{0,{39,39,39,39}},	{0,{39,39,39,39}},
{0,{0,0,0,39}},	{0,{39,39,39,39}},	{0,{39,39,39,39}},
{0,{0,0,0,39}},	{0,{0,0,0,39}},	{0,{39,39,39,40}},
{0,{40,40,40,0}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{0,0,0,40}},	{0,{40,40,40,41}},	{0,{41,41,41,42}},
{0,{41,41,41,41}},	{0,{41,41,41,41}},	{0,{41,41,41,41}},
{0,{0,0,0,41}},	{0,{41,41,41,41}},	{0,{41,41,41,41}},
{0,{0,0,0,41}},	{0,{41,41,41,41}},	{0,{41,41,41,41}},
{0,{41,41,41,41}},	{0,{41,41,41,41}},	{0,{41,41,41,41}},
{0,{41,41,41,36}},	{0,{41,41,41,36}},	{0,{41,41,41,41}},
{0,{0,0,0,41}},	{0,{0,0,0,41}},	{0,{41,41,41,41}},
{0,{41,41,41,41}},	{0,{41,41,41,41}},	{0,{41,41,41,41}},
{0,{41,41,41,41}},	{0,{41,41,41,41}},	{484,{0,0,0,0}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{40,40,40,0}},
{0,{0,0,0,40}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{0,0,0,40}},	{0,{0,0,0,40}},	{0,{40,41,0,0}},
{0,{41,40,0,0}},	{0,{41,0,0,0}},	{0,{41,41,0,0}},
{0,{37,37,0,0}},	{0,{0,0,0,40}},	{0,{40,41,42,42}},
{0,{42,40,41,41}},	{0,{42,40,40,40}},	{0,{39,39,39,39}},
{0,{37,37,38,38}},	{0,{40,40,40,40}},	{0,{0,0,0,40}},
{0,{40,40,40,40}},	{0,{40,40,40,0}},	{0,{0,0,0,40}},
{0,{40,0,0,0}},	{0,{40,31,31,31}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{40,0,0,0}},
{0,{40,26,26,26}},	{0,{40,40,40,40}},	{0,{0,0,0,40}},
{0,{0,0,0,40}},	{0,{40,0,0,0}},	{0,{40,40,40,40}},
{0,{40,40,0,0}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{0,0,0,40}},	{0,{0,0,0,40}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{0,{40,40,40,40}},
{0,{40,40,40,40}},	{0,{40,40,37,37}},	{0,{40,0,0,0}},
{0,{40,34,34,34}},	{0,{40,34,34,34}},	{0,{40,0,0,0}},
{0,{40,33,33,33}},	{0,{40,33,33,33}},	{0,{40,40,0,0}},
{0,{40,40,40,40}},	{0,{40,40,40,40}},	{64,{0,0,0,0}},
{0,{0,0,0,39}},	{0,{39,39,39,39}},	{0,{39,38,38,38}},
{0,{39,0,0,0}},	{0,{39,39,39,39}},	{0,{39,0,0,0}},
{0,{39,39,39,39}},	{0,{39,38,38,38}},	{0,{39,39,39,39}},
{0,{39,39,39,39}},	{0,{0,0,0,39}},	{0,{39,39,39,39}},
{0,{39,39,39,39}},	{0,{39,39,0,0}},	{0,{39,39,0,0}},
{0,{0,39,0,0}},	{0,{39,39,39,39}},	{0,{39,39,39,0}},
{0,{39,39,39,39}},	{0,{39,39,39,39}},	{0,{39,39,39,39}},
{0,{36,36,36,39}},	{0,{0,0,0,39}},	{15,{0,0,0,0}},
{21,{0,0,0,0}},	{0,{37,37,37,37}},	{0,{37,37,37,37}},
{0,{37,37,37,37}},	{0,{37,37,37,37}},	{0,{37,37,37,37}},
{29,{0,0,0,0}},	{30,{31,31,31,31}},	{30,{31,31,31,31}},
{30,{0,0,0,0}},	{30,{30,30,30,30}},	{30,{30,30,30,30}},
{0,{31,31,0,0}},	{0,{31,31,31,31}},	{0,{31,31,31,31}},
{152,{0,0,0,0}},	{0,{30,30,30,30}},	{30,{29,29,29,29}},
{172,{0,0,0,0}},	{0,{28,28,28,28}},	{0,{0,0,0,28}},
{0,{28,28,28,28}},	{30,{27,27,27,27}},	{0,{27,27,27,27}},
{0,{27,27,27,27}},	{335,{0,0,0,0}},	{0,{26,26,26,26}},
{0,{26,26,26,26}},	{0,{26,26,26,26}},	{362,{0,0,0,0}},
{396,{0,0,0,0}},	{0,{24,24,24,24}},	{0,{24,24,24,0}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{21,21,21,24}},	{0,{0,0,0,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{0,0,0,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{21,21,21,24}},	{0,{0,0,0,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{0,0,0,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{21,21,21,24}},	{0,{0,0,0,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{0,0,0,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{21,21,21,24}},	{0,{0,0,0,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,0,0,0}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{0,0,0,24}},	{0,{24,24,24,24}},	{0,{24,0,0,0}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,0,0}},
{0,{24,24,24,24}},	{0,{24,24,24,24}},	{0,{24,24,24,24}},
{14,{21,21,21,21}},	{14,{0,0,0,0}},	{0,{22,22,22,22}},
{0,{22,22,22,22}},	{0,{22,22,22,22}},	{0,{22,22,22,22}},
{0,{22,22,22,22}},	{0,{0,0,0,22}},	{0,{22,22,22,22}},
{0,{0,0,0,22}},	{0,{22,22,22,22}},	{0,{22,22,22,22}},
{254,{0,0,0,0}},	{0,{21,21,21,21}},	{0,{21,0,0,0}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{0,{21,21,21,21}},
{0,{21,21,21,21}},	{0,{21,21,21,21}},	{528,{0,0,0,0}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{0,0,0,20}},
{0,{20,20,20,20}},	{0,{0,0,0,20}},	{0,{20,20,20,20}},
{0,{0,0,0,20}},	{0,{20,20,20,20}},	{0,{0,0,0,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{0,0,0,20}},	{0,{20,20,20,20}},
{0,{0,0,0,20}},	{0,{20,20,20,20}},	{0,{0,0,0,20}},
{0,{20,20,20,20}},	{0,{0,0,0,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{20,20,20,20}},
{0,{20,20,20,20}},	{0,{20,20,20,20}},	{0,{0,0,0,20}},
{0,{0,0,0,20}},	{0,{0,0,0,20}},	{0,{0,0,0,20}},
{0,{0,0,0,20}},	{0,{0,0,0,20}},	{0,{0,0,0,20}},
{0,{0,0,0,20}},	{0,{0,0,0,20}},	{0,{0,0,0,20}},
{0,{0,0,0,20}},	{207,{0,0,0,0}},	{0,{0,0,0,19}},
{0,{19,19,19,19}},	{0,{19,19,19,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{19,19,19,19}},	{0,{19,19,19,19}},
{0,{19,19,19,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{19,19,19,19}},	{0,{19,19,19,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{19,19,19,19}},
{0,{19,19,19,19}},	{0,{19,19,19,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{19,19,19,19}},
{0,{19,19,19,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{19,19,19,19}},	{0,{19,19,19,19}},	{0,{19,19,19,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{19,19,19,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{19,19,19,19}},	{0,{19,19,19,19}},	{0,{0,0,0,19}},
{0,{19,0,0,0}},	{0,{19,19,19,19}},	{0,{19,19,0,0}},
{0,{19,19,19,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{0,0,0,19}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{19,0,0,0}},	{0,{0,0,0,19}},
{0,{0,0,0,19}},	{0,{19,19,19,19}},	{0,{19,19,19,19}},
{0,{0,0,0,19}},	{350,{0,0,0,0}},	{0,{18,18,18,18}},
{0,{18,18,0,0}},	{0,{18,0,0,0}},	{0,{18,0,0,0}},
{0,{18,0,0,0}},	{0,{0,0,0,18}},	{0,{0,0,0,18}},
{0,{0,0,0,18}},	{0,{0,0,0,18}},	{0,{0,0,0,18}},
{0,{0,0,0,18}},	{0,{18,0,0,0}},	{50,{0,0,0,0}},
{0,{0,0,0,17}},	{0,{0,0,0,17}},	{0,{17,17,17,17}},
{0,{17,0,0,0}},	{0,{0,0,0,17}},	{0,{17,17,17,17}},
{421,{0,0,0,0}},	{9,{0,0,0,0}},	{0,{15,15,15,15}},
{13,{0,0,0,0}},	{0,{0,0,0,14}},	{0,{0,0,0,14}},
{0,{0,0,0,14}},	{0,{0,0,0,14}},	{0,{0,0,0,14}},
{0,{0,0,0,14}},	{34,{0,0,0,0}},	{0,{0,0,0,13}},
{0,{0,0,0,13}},	{0,{13,13,13,13}},	{0,{13,13,13,13}},
{0,{0,0,0,13}},	{0,{13,13,13,13}},	{0,{13,0,0,0}},
{0,{13,0,0,0}},	{0,{13,0,0,0}},	{0,{13,0,0,0}},
{0,{13,0,0,0}},	{0,{13,0,0,0}},	{0,{13,13,13,13}},
{0,{13,0,0,0}},	{0,{13,0,0,0}},	{0,{13,13,13,13}},
{0,{0,0,0,13}},	{0,{13,0,0,0}},	{0,{13,13,0,0}},
{0,{13,13,13,13}},	{25,{13,13,13,13}},	{24,{0,0,0,0}},
{25,{0,0,0,0}},	{0,{10,10,10,10}},	{28,{0,0,0,0}},
{0,{0,0,0,9}},	{158,{0,0,0,0}},	{158,{6,6,6,6}},
{0,{0,0,0,7}},	{0,{7,7,7,7}},	{336,{0,0,0,0}},
{0,{6,6,6,6}},	{0,{6,6,6,6}},	{0,{6,6,0,0}},
{0,{6,6,6,6}},	{0,{6,6,6,6}},	{0,{0,0,0,6}},
{0,{6,6,6,6}},	{0,{6,6,6,6}},	{0,{6,6,6,6}},
{0,{0,0,0,6}},	{0,{0,0,0,6}},	{0,{6,6,6,6}},
{0,{6,6,6,6}},	{0,{6,6,6,6}},	{0,{6,6,6,6}},
{0,{6,6,6,6}},	{0,{6,6,6,6}},	{0,{0,0,0,6}},
{0,{6,6,6,6}},	{0,{6,6,6,6}},	{0,{6,6,6,0}},
{0,{6,6,6,6}},	{0,{6,6,6,6}},	{0,{0,0,0,6}},
{0,{6,6,6,6}},	{0,{6,6,6,6}},	{0,{6,6,6,6}},
{0,{6,6,6,6}},	{0,{6,6,6,6}},	{0,{0,0,0,6}},
{0,{6,6,0,0}},	{0,{6,6,6,6}},	{0,{6,6,6,6}},
{0,{6,6,0,0}},	{0,{6,6,6,6}},	{332,{0,0,0,0}},
{360,{0,0,0,0}},	{0,{4,4,4,4}},	{0,{4,4,4,4}},
{33,{0,0,0,0}},	{0,{3,3,3,3}},	{0,{3,3,3,3}},
{0,{3,3,3,3}},	{0,{3,3,3,3}},	{0,{3,3,3,3}},
{0,{3,3,3,3}},	{0,{3,3,3,3}},	{0,{3,3,3,3}},
{0,{3,3,3,3}},	{0,{3,3,3,3}},	{0,{3,3,3,3}},
{0,{3,3,3,3}},	{0,{3,3,3,3}},	{0,{3,3,3,3}},
{0,{3,3,3,3}},	{0,{3,0,0,0}},	{0,{3,3,3,3}},
{0,{3,3,3,3}},	{0,{0,0,0,3}},	{0,{3,3,3,3}},
{0,{3,3,3,3}},	{0,{0,0,0,3}},	{0,{3,3,3,3}},
{0,{3,3,3,3}},	{0,{0,0,0,3}},	{0,{0,0,0,3}},
{0,{0,0,0,3}},	{269,{0,0,0,0}},	{0,{0,0,0,2}},
{0,{0,0,0,2}},	{0,{0,0,0,2}},	{0,{0,0,0,2}},
{0,{0,0,0,2}},	{0,{0,0,0,2}},	{0,{0,0,0,2}},
{0,{0,0,0,2}},	{0,{0,0,0,2}},	{0,{0,0,0,2}},
{0,{0,0,0,2}},	{0,{0,0,0,2}},	{0,{2,0,0,0}},
{0,{0,0,0,2}},	{12,{0,0,0,0}},	{0,{0,0,0,1}},
{0,{1,1,0,0}},	{26,{0,0,0,0}},	};

static const attrib_rt_t idx_owl_defendpat[531] = {
{-1,0},	{256,0},	{261,1},	{187,2},
{432,0},	{429,0},	{370,0},	{403,6},
{404,7},	{355,0},	{396,0},	{433,10},
{25,0},	{196,0},	{356,0},	{48,0},
{393,0},	{394,16},	{395,17},	{433,0},
{190,0},	{278,0},	{420,0},	{343,0},
{344,0},	{405,24},	{17,0},	{345,0},
{344,27},	{98,0},	{412,0},	{56,0},
{15,31},	{31,0},	{105,0},	{40,0},
{429,35},	{22,0},	{62,0},	{205,0},
{224,5},	{212,0},	{37,0},	{62,42},
{174,0},	{178,44},	{175,0},	{193,0},
{51,0},	{364,0},	{101,0},	{383,0},
{371,0},	{49,0},	{44,0},	{71,0},
{391,0},	{427,0},	{359,0},	{363,58},
{357,59},	{367,60},	{409,0},	{351,0},
{350,0},	{361,16},	{394,65},	{360,66},
{365,67},	{368,68},	{473,0},	{474,0},
{28,0},	{139,0},	{358,0},	{91,74},
{192,0},	{132,0},	{172,0},	{171,0},
{186,47},	{127,0},	{137,0},	{186,0},
{123,0},	{195,0},	{173,0},	{331,0},
{427,87},	{69,0},	{131,0},	{340,0},
{428,0},	{342,0},	{57,0},	{58,94},
{53,95},	{52,96},	{58,0},	{53,98},
{52,99},	{167,0},	{104,0},	{233,0},
{451,0},	{199,0},	{146,0},	{475,0},
{176,0},	{165,0},	{141,0},	{145,0},
{53,0},	{52,112},	{301,0},	{427,114},
{204,0},	{160,0},	{221,0},	{88,0},
{354,0},	{21,0},	{11,0},	{389,0},
{326,0},	{175,124},	{23,0},	{327,0},
{175,127},	{8,0},	{149,0},	{97,0},
{96,131},	{197,132},	{214,133},	{214,0},
{96,0},	{214,136},	{148,0},	{70,0},
{163,0},	{152,0},	{240,0},	{168,0},
{169,0},	{212,144},	{55,0},	{54,0},
{211,0},	{215,0},	{225,0},	{158,0},
{27,0},	{245,0},	{9,0},	{58,154},
{478,0},	{1,0},	{405,0},	{14,0},
{24,0},	{4,5},	{18,0},	{39,0},
{61,0},	{46,0},	{246,0},	{33,0},
{34,0},	{154,0},	{13,0},	{117,0},
{118,0},	{392,0},	{106,0},	{107,0},
{149,175},	{263,0},	{477,0},	{349,0},
{102,0},	{68,0},	{203,0},	{379,0},
{45,0},	{182,46},	{297,0},	{185,0},
{180,0},	{138,0},	{476,0},	{161,0},
{125,0},	{330,0},	{201,0},	{200,0},
{126,0},	{74,0},	{329,0},	{476,198},
{202,0},	{153,0},	{112,0},	{113,0},
{314,0},	{81,0},	{73,0},	{3,0},
{95,0},	{85,0},	{86,209},	{398,0},
{410,0},	{411,0},	{162,0},	{111,0},
{10,0},	{264,0},	{262,217},	{124,0},
{128,0},	{189,0},	{441,0},	{333,0},
{334,223},	{210,0},	{249,0},	{475,214},
{194,0},	{90,0},	{90,228},	{299,0},
{110,0},	{108,232},	{120,0},	{108,0},
{151,0},	{250,0},	{251,237},	{322,0},
{219,0},	{220,240},	{457,0},	{38,0},
{119,0},	{103,0},	{35,0},	{90,243},
{231,0},	{372,0},	{230,0},	{407,0},
{170,0},	{417,0},	{0,0},	{266,0},
{267,0},	{63,0},	{59,0},	{401,0},
{237,0},	{238,0},	{136,0},	{216,0},
{468,0},	{247,0},	{179,0},	{134,0},
{459,0},	{5,0},	{328,0},	{232,0},
{183,0},	{347,0},	{395,0},	{353,0},
{352,275},	{260,276},	{109,0},	{265,0},
{399,0},	{52,0},	{198,0},	{177,0},
{469,0},	{234,0},	{164,0},	{177,286},
{236,0},	{29,0},	{133,0},	{229,0},
{268,0},	{121,0},	{122,0},	{140,0},
{142,0},	{309,0},	{308,0},	{213,0},
{228,0},	{454,0},	{76,0},	{373,0},
{442,0},	{443,304},	{444,305},	{465,0},
{464,0},	{143,0},	{130,0},	{248,0},
{114,0},	{445,0},	{222,313},	{47,0},
{446,0},	{458,0},	{281,0},	{302,0},
{374,0},	{375,0},	{321,0},	{223,0},
{445,323},	{415,0},	{188,0},	{150,326},
{150,0},	{78,0},	{419,0},	{20,0},
{100,0},	{30,0},	{79,0},	{41,0},
{26,0},	{241,0},	{385,0},	{387,338},
{388,339},	{386,338},	{12,0},	{387,0},
{386,0},	{419,344},	{315,0},	{82,0},
{83,347},	{84,0},	{2,0},	{16,0},
{336,0},	{84,352},	{335,0},	{335,343},
{462,0},	{460,356},	{184,357},	{338,0},
{339,0},	{434,0},	{346,0},	{461,0},
{463,363},	{298,0},	{19,0},	{32,0},
{312,0},	{99,0},	{341,0},	{295,0},
{274,0},	{275,372},	{276,0},	{296,0},
{381,0},	{284,0},	{42,0},	{43,378},
{425,0},	{280,0},	{257,0},	{258,382},
{239,0},	{77,0},	{92,385},	{82,386},
{83,387},	{430,0},	{431,389},	{87,0},
{337,391},	{155,0},	{310,0},	{313,0},
{440,0},	{435,0},	{436,397},	{384,0},
{439,0},	{382,0},	{421,389},	{431,402},
{466,0},	{36,0},	{422,0},	{400,0},
{292,0},	{253,0},	{254,409},	{255,0},
{422,363},	{463,412},	{135,0},	{166,0},
{306,0},	{291,0},	{472,0},	{319,0},
{316,0},	{348,0},	{64,0},	{50,0},
{72,0},	{304,0},	{65,0},	{304,426},
{320,0},	{305,0},	{311,0},	{471,419},
{470,431},	{206,0},	{207,433},	{209,0},
{208,435},	{252,0},	{390,0},	{406,0},
{181,0},	{303,0},	{269,0},	{270,442},
{390,443},	{271,444},	{323,0},	{324,446},
{303,447},	{129,0},	{303,449},	{307,0},
{285,0},	{305,452},	{414,0},	{447,0},
{450,0},	{448,456},	{448,0},	{147,0},
{244,0},	{380,0},	{75,0},	{416,0},
{293,0},	{300,0},	{66,0},	{226,0},
{159,0},	{286,0},	{277,0},	{287,0},
{60,0},	{80,0},	{408,0},	{437,0},
{273,0},	{272,476},	{418,0},	{279,0},
{325,0},	{317,0},	{413,0},	{290,0},
{423,0},	{424,0},	{94,0},	{438,0},
{67,0},	{455,0},	{456,489},	{456,0},
{6,0},	{60,492},	{397,0},	{362,0},
{366,495},	{369,496},	{449,0},	{93,0},
{7,0},	{60,500},	{377,0},	{318,0},
{116,0},	{426,0},	{294,0},	{452,0},
{453,0},	{115,0},	{376,0},	{332,0},
{144,511},	{378,0},	{191,0},	{467,0},
{288,0},	{289,0},	{282,0},	{89,0},
{283,0},	{402,0},	{156,0},	{242,0},
{243,0},	{235,0},	{157,0},	{227,0},
{259,0},	{217,0},	{218,529},	};

static dfa_rt_t dfa_owl_defendpat = {
 "owl_defendpat",
state_owl_defendpat,
idx_owl_defendpat};

struct pattern_db owl_defendpat_db = {
  -1,
  0,
  owl_defendpat
 ,& dfa_owl_defendpat
};
