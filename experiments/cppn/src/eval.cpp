#include "eval.h"
#include "iface.h"
#include "image.h"
extern "C" {
  FitnessEvaluator *maker(char * str)
  {
    FitnessEvaluator * ret;
    vector<string> * sv = split(str," ");
    if(sv->at(0).find("cppnpicture")!=string::npos) {
      if(sv->size()!=3){
	cerr << "wrong arguments to eye eval should be: \"cppnpicture <picturefile> <pic(1) or data(0)>\"" << endl;
	exit(1);
      }
      bool img = atoi(sv->at(2).c_str()) == 1;

      ret = new PictureEvaluator(sv->at(1),img);
      delete sv;
      return ret;
    }else{
      cerr << "wrong arguments to eye eval should be: \"cppnpicture <picturefile> <pic(1) or data(0)>\"" << endl;
      delete sv;
      return NULL;
    }
  }
}
void PictureEvaluator::readdata(std::string filename)
{
  double * img;
  sizes = new int [2];
  cout << "this: " << this << " in mf read" << endl;
  char buf[4096];
  int minlength;
  ifstream ifs(filename.c_str());
  ifs.getline(buf,sizeof buf);//ascii
  ifs.getline(buf,sizeof buf);//uc
  vector<string> * inpv = split(buf," ");
  int uc,xs,ys,zs;
  uc = atoi(inpv->at(0).c_str());
  ifs.getline(buf,sizeof buf);//dims
  delete inpv; inpv = split(buf," ");
  xs = atoi(inpv->at(0).c_str());
  ys = atoi(inpv->at(1).c_str());
  zs = atoi(inpv->at(2).c_str());

  ifs.getline(buf,sizeof buf);//resolution
  delete inpv; inpv = split(buf," ");

  minlength = (xs<ys) ? xs : ys;
  minlength = (minlength<zs) ? minlength : zs;
  cout << "xs: " << xs << " ys: " << ys << " zs: " << xs << endl;
  delete inpv;
  double * model;
  model = (double*)calloc(xs*ys,sizeof(double));
  sizes[0] = xs;
  sizes[1] = ys;
  int v = 0;
  for(unsigned x=0;x<xs;x++){
    ifs.getline(buf,sizeof buf);
//     cout << "buf("<<x<<"): " << buf << endl;
    inpv = split(buf," ");
    for(unsigned y=0;y<ys;y++){
      v = atoi(inpv->at(y).c_str());
      
      if(v == 3)
	model[(x*xs)+y] = 1;
      else
	model[(x*xs)+y] = 0;
      
    }
  }
  cout << "done ! " << endl;
  delete inpv;


  picoffset = xs*ys;
  for(int i=0;i<picoffset;i++){
    picdata.push_back(model[i]);
  }
}
void PictureEvaluator::readimg(std::string filename)
{
  double * img;
  sizes = new int [2];
  cout << "readimg: " << read_image(img,filename.c_str(),sizes) <<endl;
  cout<<"sizes[0]: " << sizes[0] << " sizes[1]:" << sizes[1] << endl;
  picoffset = (sizes[0]*sizes[1]);
  for(int i=0;i<picoffset;i++){
    picdata.push_back(img[i]);
  }
//   write_image_coords ( "data/test.tiff" , img , sizes[0] , sizes[1] );
}
PictureEvaluator::PictureEvaluator(std::string filename, bool img)
{
  if(img)
    readimg(filename);
  else
    readdata(filename);
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
      inp.at(0) = ((double)x/(double)xmax)-0.5;
      inp.at(1) = ((double)y/(double)ymax)-0.5;
      inp.at(2) = (sqrt(pow(((double)x)-((double)xmax),2)))-0.5;
      reaction = f->react(inp);
      wrong += sqrt(pow(picdata.at((ymax*x)+y)-(reaction.at(0)),2));
      if(reaction.at(0) > 0.0) reaction.at(0) = .9999;
      else if(reaction.at(0) < 0) reaction.at(0) = 0;

    }
  }
//   wrong *= 2;
  double fi = (double)(picoffset-wrong+1)/((double)picoffset);
  f->setFitness(fi);

  return fi;
}
void PictureEvaluator::runTest(Phenotype * f)
{
  double * oimg = (double*)calloc(sizes[0]*sizes[1],sizeof(double));
  vector<double> reaction;
  vector<double> inp;inp.push_back(0);inp.push_back(0); inp.push_back(0);
  int xmax = sizes[0];
  int ymax = sizes[1];
  double wrong=0;

  for(int x=0;x<sizes[0];x++){
    for(int y=0;y<sizes[1];y++){
      inp.at(0) = ((double)x/(double)xmax)-0.5;
      inp.at(1) = ((double)y/(double)ymax)-0.5;
      inp.at(2) = (sqrt(pow(((double)x)-((double)xmax),2)))-0.5;
      //       inp.at(2) = sqrt((x-(xmax/2))^2 + (y-(ymax/2))^2);
      reaction = f->react(inp);
      wrong += sqrt(pow(picdata.at((ymax*x)+y)-(reaction.at(0)),2));
      if(reaction.at(0) > 0.0) reaction.at(0) = 1;
      else if(reaction.at(0) < 0) reaction.at(0) = 0;
      oimg[(x*sizes[1])+y] = reaction[0];

    }
  }
    cout << "printing to out.tiff .. xmax: "<<xmax << " ymax: "<<xmax
	 << " wrong: " << wrong << endl;
  write_image_coords ( "out.tiff" , oimg , sizes[0] , sizes[1] );
  delete[] oimg;
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
