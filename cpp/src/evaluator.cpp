/*
  Copyright 2007 Bjørn Magnus Mathisen
  This file is part of NEATzsche.

  NEATzsche is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  NEATzsche is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with NEATzsche; if not, write to the Free Software Foundation,
  Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

*/

#include "evaluator.h"
#include <iomanip>


double DatasetEvaluator::f(Phenotype * f)
{
  double esum = 0;
  vector<double> v;
  for(int i=0;i<ds->getTrainings();i++){
    f->cleanNet();
    v = f->react(*ds->getTrain(i));
    //     cerr << "vsize: " << v.size() << endl;
    //     cerr << "ds->getClass(true,i): " << ds->getClass(true,i) << " vat0: " << (v.at(0)) << endl;
    esum += fabs(ds->getClass(true,i)-(v.at(0)));
  }
//   double r = pow(ds->getTrainings()-esum,2.0);
  f->setFitness(ds->getTrainings()-esum);
  //   cout << " esum: "<< esum <<" new fitness: " << pow(ds->getTrainings()-esum,2.0) <<endl;
  //       << " getfitness: " << f->getFitness() << endl;
  //   if(pow(ds->getTrainings()-esum,2.0)==0)
  //     cerr << "pow(ds->getTrainings()-esum,2.0) was zero!!"<<endl;  
  //   if(pow(ds->getTrainings()-esum,2.0)>20){
  //     cerr << "esum: " << esum << endl;
  //     cerr << "v0: " << v.at(0) << endl;
  //     // cerr << "phenotype outputftype: " << f->outputFType() << endl;
  //     cerr << "pow(ds->getTrainings()-esum,2.0) was over 20!!"<<endl;  
  //     cerr << "genome: " << f->getGenome() << endl;
  //     cerr << "state: " << printvector(f->getState()) << endl;
  //     f->cleanNet();
  //     cerr << "state: " << printvector(f->getState()) << endl;
  //   }
  return ds->getTrainings()-esum;
}
void DatasetEvaluator::runTest(Phenotype * f)
{
  //f->genesis();
  vector<double> v;
  for(int i=0;i<ds->getTrainings();i++){
    v = f->react(*ds->getTrain(i));
    f->cleanNet();
    cerr << "input: " << printvector(*ds->getTrain(i))
	 << " output: " << v.at(0) 
	 << " should have been: " << ds->getClass(true,i) 
	 << " diff: " << fabs(ds->getClass(true,i) - v.at(0)) << endl;
  }
  //  f->cleanup();
}
bool DatasetEvaluator::xorDone(Phenotype * f)
{
  //  f->genesis();
  vector<double> v;
  int c=0;
  for(int i=0;i<ds->getTrainings();i++){
    f->cleanNet();
    v = f->react(*ds->getTrain(i));
//     fabs(ds->getClass(true,i) - v.at(0))
    if(fabs(ds->getClass(true,i) - v.at(0))<0.4) c++; 
//     if(fabs(ds->getClass(true,i) - v.at(0))<0.4) c++;
  }
  //  f->cleanup();
//   cout << "c:" << c << endl;
  return c==4;
}

bool comp(vector<double> v)
{
  if(v.size()!=sensecomp.size())
    return false;
  for(unsigned int i=0;i<v.size();i++)
    if(v.at(i)!=sensecomp.at(i))
      return false;
  return true;
}
