class PictureEvaluator : public FitnessEvaluator {
private:
  vector<double> picdata;
  int picoffset;
  int * sizes;
public:
  PictureEvaluator(std::string filename);
  virtual ~PictureEvaluator(){};
  virtual double f(Phenotype * f);
  double f2(Phenotype * f);
  void runTest(Phenotype * f);
  virtual void nextGen(){return;} // no need for this here..
};
