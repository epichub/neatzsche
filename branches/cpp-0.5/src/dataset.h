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
#ifndef DATASET_H_
#define DATASET_H_
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "neuralmath.h"

using namespace std;

class DataSet
{
protected:
  vector< vector<double>* > * data;
  vector<string> * classes;
  string name;
  int tests;
  int trainings;
  int uniqueClasses;
  int * testCoords;
  int * trainCoords;
  bool checkTextual(string inp);
public:
  DataSet(bool classAtStart,string file, double ratio);
  virtual ~DataSet();
  void resetCounters();
  int getTests(){return tests;}
  int getTrainings(){return trainings;}
  int getClasses(){return uniqueClasses;}
  int getParams(){return data->at(0)->size();}
  vector<double>* getTest(int i){
    cout << "i:" << i << endl;
    if(testCoords[i]>=0&&(unsigned int)testCoords[i]<data->size())
      return data->at(testCoords[i]);
    cout << "testcoord "<<testCoords[i]<<"was out of range..("<<data->size()<<")\n";
    return 0;
  }
  vector<double>* getTrain(int i){return data->at(trainCoords[i]);}
  double getClass(bool train, int i);
  void print();
  string getName(){return name;}
};

#endif /*DATASET_H_*/
