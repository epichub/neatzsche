#include "neuralmath.h"
using namespace std;
TransferFunctions::TransferFunctions(NEATsettings * s)
{
  f = new vector<TransferFunction *>();
  bool unipolar = s->getValue("unipolar")==1.0;
  ta = new TransferFunction();
  double ss = s->getValue("sigmoid_sharpness");
  if(ss==0)
    ss = -4.9;
  sigmoid = new SigmoidTransfer(unipolar,ss);
  f->push_back(sigmoid);

  if(s->getValue("enable_identity_tfunc")==1.0)
    f->push_back(ta);
  if(s->getValue("enable_abs_tfunc")==1.0)
    f->push_back(new AbsoluteValue());
  if(s->getValue("enable_sinus_tfunc")==1.0){
    sine = new SinusTransfer(unipolar,s->getValue("sinus_sharpness"),s->getValue("sinus_add"),s->getValue("sinus_div"));
    f->push_back(sine);
  }
  if(s->getValue("enable_cosine_tfunc")==1.0)
    f->push_back(new CosineTransfer(unipolar,s->getValue("cosine_sharpness"),s->getValue("consine_add"),s->getValue("cosine_div")));
  if(s->getValue("enable_gauss_tfunc")==1.0)
    f->push_back(new GaussTransfer(unipolar,s->getValue("gauss_median"),s->getValue("gauss_std_deviation")));
  if(s->getValue("enable_stochastic_tfunc")==1.0)
    f->push_back(new StochasticTransfer(unipolar,s->getValue("stoch_std_deviation"),(int)s->getValue("stoch_table_size")));
  if(s->getValue("enable_parabel_tfunc")==1.0)
    f->push_back(new ParabelTransfer(unipolar,s->getValue("parabel_sharpness"),s->getValue("parabel_add")));


}
TransferFunctions::~TransferFunctions()
{
  for(unsigned int i=0;i<f->size();i++){
    if(f->at(i)!=ta)
      delete f->at(i);
  }
  delete ta;
  delete f;
}
TransferFunction::TransferFunction()
{
  ftype = "ta";
}
TransferFunction::~TransferFunction()
{

}

SignumTransfer::SignumTransfer(){
  ftype = "sig";
}
SignumTransfer::~SignumTransfer(){
}
inline int SignumTransfer::sgn(double inp)
{
  if(inp>=0)
    return 1;
  else
    return -1;
}
SigmoidTransfer::SigmoidTransfer(bool unipolar, double ik){
  ftype = "so";
  k = ik;

  con = (unipolar) ? 0 : -0.5;
  //cout << "unipolar: " << unipolar << " con: " << con << endl;
}
SigmoidTransfer::~SigmoidTransfer(){
}
inline double SigmoidTransfer::sgm(double inp)
{
  return ((double)1.0/
	  ((double)1.0+exp(k*inp)))+con;
}
StochasticTransfer::StochasticTransfer(bool unipolar, double id, int its)
{
  d = id; ts = its;
  
  rc = 0; ftype = "sto";
  t = new double [ts];
  for(unsigned int i=0;i<ts;i++){
    t[i] = randsign()*randdouble()*d;
  }
}
double StochasticTransfer::y(double x)
{
  return x+t[(++rc)%ts];
}
bool Dummy::isIn(int ** arr,int length, int x, int y){
  for(int i=0;i<length;i++)
    if(arr[i][0] == x && arr[i][1] == y)
      return true;
  return false;
}

int ** Dummy::randomCoords(int maxX, int maxY)
{

  int gotC=0;
  int coordC = maxX*maxY;
  if(maxY==0)
    coordC = maxX;
  int ** randArr = new int * [coordC];
  for(int i=0;i<(coordC);i++){
    randArr[i] = new int [2];
    randArr[i][0] = -1;
    randArr[i][1] = -1;
  }
  int tmpX,tmpY;
  while(gotC<(coordC)){
    tmpX = rand()%maxX;
    if(maxY!=0)
      tmpY = rand()%maxY;
    else
      tmpY = 0;
    if(!isIn(randArr,(coordC),tmpX,tmpY)){
      randArr[gotC][0] = tmpX;
      randArr[gotC++][1] = tmpY;
    }
  }
  return randArr;
}
void Dummy::printBitmap(int ** arr, int x, int y, bool printneg)
{
  for(int i=0;i<x;i++){
    for(int i2=0;i2<y;i2++){
      if(arr[i][i2]==-1&&!printneg)
	cout << "  ";
      else if(arr[i][i2]==1)
	cout << " " << arr[i][i2];
      else if(arr[i][i2]!=-2)
	cout << arr[i][i2];
      else if(arr[i][i2]==-2)
	cout << "  ";
    }
    cout << endl;
  }		
}
void Dummy::deleteArray(int x, int ** arr){
  for(int i=0;i<x;i++)
    delete[] arr[i];
  delete[] arr;
}

