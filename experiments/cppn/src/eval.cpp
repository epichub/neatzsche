#include "eval.h"
#include "iface.h"
#include "image.h"
extern "C" {
  FitnessEvaluator *maker(char * str)
  {
    FitnessEvaluator * ret;
    vector<string> * sv = split(str," ");
    if(sv->at(0).find("cppnpicture")!=string::npos) {
      if(sv->size()!=2){
      cerr << "wrong arguments to eye eval should be: \"cppnpicture <picturefile>\"" << endl;
	exit(1);
      }
      ret = new PictureEvaluator(sv->at(1));
      return ret;
    }else
      cerr << "wrong arguments to eye eval should be: \"cppnpicture <picturefile>\"" << endl;
  }
}

PictureEvaluator::PictureEvaluator(std::string filename)
{
  double * img;
  sizes = new int [2];
  cout << "readimg: " << read_image(img,filename.c_str(),sizes) <<endl;
  cout<<"sizes[0]: " << sizes[0] << " sizes[1]:" << sizes[1] << endl;
  picoffset = (sizes[0]*sizes[1]);
  for(int i=0;i<picoffset;i++){
    picdata.push_back(img[i]);
  }
  write_image_coords ( "data/test.tiff" , img , sizes[0] , sizes[1] );

}
double PictureEvaluator::f(Phenotype *f)
{
  double wrong=0;
  vector<double> reaction;
  vector<double> inp;inp.push_back(0);inp.push_back(0);inp.push_back(0);
  //   cout<<"inp size: " << inp.size() << endl;
  int xmax = sizes[0];
  int ymax = sizes[1];
  for(int x=0;x<xmax;x++){
    for(int y=0;y<ymax;y++){
      inp.at(0) = (double)x/(double)xmax;
      inp.at(1) = (double)y/(double)ymax;
      inp.at(2) = sqrt(pow(((double)x)-((double)xmax),2));
      reaction = f->react(inp);
      if(reaction.at(0) > 1.0) reaction.at(0) = .9999;
      else if(reaction.at(0) < 0) reaction.at(0) = 0;
      wrong += sqrt(pow(picdata.at((ymax*x)+y)-reaction.at(0),2));
    }
  }
  double fi = (double)(picoffset-wrong+1)/((double)picoffset);
  f->setFitness(fi);

  return fi;
}
void PictureEvaluator::runTest(Phenotype * f)
{
  double * oimg = (double*)calloc(sizes[0]*sizes[1],sizeof(double));
  vector<double> inp;inp.push_back(0);inp.push_back(0);// inp.push_back(0);
  int xmax = sizes[0];
  int ymax = sizes[1];
  for(int x=0;x<sizes[0];x++){
    for(int y=0;y<sizes[1];y++){
      inp.at(0) = (double)x/(double)xmax;
      inp.at(1) = (double)y/(double)ymax;
      //       inp.at(2) = sqrt((x-(xmax/2))^2 + (y-(ymax/2))^2);
      oimg[(x*sizes[1])+y] = f->react(inp).at(0);
    }
  }
  write_image_coords ( "out.tiff" , oimg , sizes[0] , sizes[1] );
}
double PictureEvaluator::f2(Phenotype *f)
{
  int wrong=0;
  vector<double> reaction;
  for(int x=0;x<ROWS;x++){
    for(int y=0;y<COLS;y++){
      picdata.at(picoffset) = x;
      picdata.at(picoffset) = y;
      reaction = f->react(picdata);
      wrong += (reaction.at(0)==picdata.at((COLS*x)+y)) ? 0 : 1;
    }
  }
  double fi = (double)wrong/((double)COLS*ROWS);
  f->setFitness(fi);
  return fi;
}
