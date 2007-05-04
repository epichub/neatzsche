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
