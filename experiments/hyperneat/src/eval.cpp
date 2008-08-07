#include "eval.h"
#include "iface.h"
extern "C" {
  FitnessEvaluator *maker(char * str)
  {
    FitnessEvaluator * ret;
    vector<string> * sv = split(str," ");
    if(sv->at(0).find("hyperdataset")!=string::npos) {
      if(sv->size()!=4){
      cerr << "wrong arguments to eye eval should be: \"hyperdataset <settingsfile> <datasetfile> [classification at start[0/1]] [testration]\"" << endl;
	exit(1);
      }
      bool classAtStart = (atoi(sv->at(3).c_str()) == 1) ? true : false;
      double testratio = atof(sv->at(4).c_str());
      NEATsettings * set = new NEATsettings(); 
      ifstream ifs(sv->at(1).c_str());
      ifs>>set;
      ifs.close();
      TransferFunctions * tfs = new TransferFunctions(set);
      DataSet * ds = new DataSet(classAtStart,sv->at(2),testratio);
      ret = new DatasetHyperNEAT(set,tfs,ds);
      return ret;
    }else
      cerr << "wrong arguments to eye eval should be: \"dataset <datasetfile> [classification at start[0/1]] [testration]\"" << endl;
  }
}

double HyperNEAT::f(Phenotype * f)
{
  f->cleanNet();
  unsigned int mx,my,mx2,my2;

  vector<nodeVector*> * layers = new vector<nodeVector*>();
  vector<double> inp; 
  inp.push_back(0); inp.push_back(0); inp.push_back(0); inp.push_back(0);
  
  layers->push_back(new nodeVector());
  mx = dims->at(0)[0];
  my = dims->at(0)[1];
  int id = 0;
  //   cerr << "creating " << (mx*my) << " input nodes" << endl;
  for(unsigned int i=0;i<(mx*my);i++)
    layers->at(0)->push_back(new NeuralNode(tfs->getTA(),id++,NeuralNode::INPUT,0));
  NeuralNode * bias = new NeuralNode(tfs->getTA(),id++,NeuralNode::BIAS,0);
  int bx = mx; int by = my+1;
  layers->at(0)->push_back(bias);
  //   cerr << "dims size: " << dims->size() << endl;
  int d = 1; 
  char t;
  double w=0;
  for(unsigned int i=1;i<dims->size();i++){
    layers->push_back(new nodeVector());

    mx = dims->at(i-1)[0];
    my = dims->at(i-1)[1];
    mx2 = dims->at(i)[0];
    my2 = dims->at(i)[1];
    //     cerr << "mx: " << mx << " my: " << my << endl;
    //     cerr << "mx2: " << mx2 << " my2: " << my2 << endl;
    if(i==dims->size()-1)
      t = NeuralNode::OUTPUT;
    else
      t = NeuralNode::HIDDEN;
    for(unsigned int x=0;x<mx2;x++){//create the next layer
      for(unsigned int y=0;y<my2;y++){
	layers->at(i)->push_back(new NeuralNode(tfs->getSigmoid(),id++,t,d));
	//make bias link??
	inp.at(0) = bx; inp.at(1) = by; inp.at(2) = x; inp.at(3) = y;
	w = f->react(inp).at(0);
	if(fabs(w)>0.2){
	  if(w>0.0)
	    w = ((w-0.2)/0.8)*3.0;
	  else
	    w = ((w+0.2)/0.8)*3.0;
// 	  cout << "w: " << w << endl;

	  new Link(false,bias,layers->at(i)->at((x*my2)+y),w);
	}
      }
    }

    d++;
  }
  double x1n,y1n,x2n,y2n;

  for(unsigned int i=0;i<dims->size()-1;i++){
    for(unsigned int i2=i+1;i2<dims->size();i2++){
      mx = dims->at(i)[0];
      my = dims->at(i)[1];
      mx2 = dims->at(i2)[0];
      my2 = dims->at(i2)[1];
      x1n = -(double)(mx-1.0)/2.0;
      y1n = -(double)(my-1.0)/2.0;
      x2n = -(double)(mx2-1.0)/2.0;
      y2n = -(double)(my2-1.0)/2.0;
      for(unsigned int x=0;x<mx;x++){
	for(unsigned int y=0;y<my;y++){
	  // 	cout << "from layer i-1" << endl;
	  //	cout << "x:" << x << " y: " << y << " (x*my)+y: " <<  (x*my)+y << " making link from id: " << layers->at(i-1)->at((x*my)+y)->getID() << endl;
	  for(unsigned int x2=0;x2<mx2;x2++){
	    for(unsigned int y2=0;y2<my2;y2++){
// 	      cout << "x: " << x << " y: " << y << " x2: " << x2 << " y2: " << y2 << endl;
// 	      cout << "x1n: " << x1n << " mx: " << mx << endl;
// 	      cout << "y1n: " << y1n << " my: " << my << endl;
// 	      cout << "x2n: " << x2n << " mx2: " << mx2 << endl;
// 	      cout << "y2n: " << y2n << " my2: " << my2 << endl;
// 	      cout << "((double)x+x1n)/(double)mx: " << ((double)x+x1n)/(double)mx << endl;
// 	      cout << "((double)y+y1n)/(double)my: " << ((double)y+y1n)/(double)my << endl;
// 	      cout << "((double)x2+x2n)/(double)mx2: " << ((double)x2+x2n)/(double)mx2 << endl;
// 	      cout << "((double)y2+y2n)/(double)my2: " << ((double)y2+y2n)/(double)my2 << endl;
	      inp.at(0) = ((double)x+x1n)/(double)mx;
	      inp.at(1) = ((double)y+y1n)/(double)my;
	      inp.at(2) = ((double)x2+x2n)/(double)mx2;
	      inp.at(3) = ((double)y2+y2n)/(double)my2;


	      f->cleanNet();
	    // 	    cout << "f->react(inp).at(i-1): " << f->react(inp).at(i-1)<<endl;
	    //	    cout << "x2:"<<x2<<" y2:"<<y2<<" (x2*my2)+y2: "<<(x2*my2)+y2<<" making link to id: " << layers->at(i)->at((x2*my2)+y2)->getID() << endl;
	      w = f->react(inp).at(0);
	      if(fabs(w)>0.2){
		if(w>0.0)
		  w = ((w-0.2)/0.8)*3.0;
		else
		  w = ((w+0.2)/0.8)*3.0;
		// 	      cout << "w: " << w << endl;
		new Link(false,layers->at(i)->at((x*(my))+y),layers->at(i2)->at((x2*(my2))+y2),w);
	      }
	    }      	  
	  }      
	}
      }
    }
  }
  nodeVector * nv = new nodeVector();
  int in = 0;
  for(unsigned int i=0;i<layers->size();i++){
    for(unsigned int i2=0;i2<layers->at(i)->size();i2++){
      cout <<  "type: "<<layers->at(i)->at(i2)->getType() << " id: "<<layers->at(i)->at(i2)->getID()<<" layers->at(i)->at(i2)->getInputLinks()->size(): " << layers->at(i)->at(i2)->getInputLinks()->size() << endl;
      in += layers->at(i)->at(i2)->getInputLinks()->size();
      nv->push_back(layers->at(i)->at(i2));
    }
  }
  
  cerr << "input links: " << in << endl;
  n = new Network(dims->at(0)[0]*dims->at(0)[1],dims->at(dims->size()-1)[0]*dims->at(dims->size()-1)[1]);

  n->addNodes(nv,false);
#ifdef NEATZSCHEDEBUG
  cout << (new Genome(tfs,n));
#endif
//     exit(0);
  return 0;
  //run the damn thing on a task at hand, woopdedo (i'll let that be a task for my polymorphic children)
}
string HyperNEAT::output(Phenotype * ph)
{
  f(ph);
  stringstream ss;
  ss << (new Genome(tfs,n));
  return ss.str();
}
double DatasetHyperNEAT::f(Phenotype * f)
{
  //   double r = (double)rand()/(double)RAND_MAX;
  //   r = (r==0) ? 10^-5 : r;
  //   f->setFitness(r);
  //   return r;
  HyperNEAT::f(f);
  Phenotype * p = new Phenotype(n);
  double fitness = d->f(p);

  if(fitness <= 0.0)
    fitness = 10^-4;
  f->setFitness(fitness);

//   exit(0);
  delete p;
#ifdef NEATZSCHEDEBUG
  runTest(f);
  cout << "fitness: " << fitness << endl;
  exit(0);
#endif

  return fitness;
}
bool DatasetHyperNEAT::done(Phenotype *f)
{
  //   double r = (double)rand()/(double)RAND_MAX;
  //   r = (r==0) ? 10^-5 : r;
  //   f->setFitness(r);
  //   return r;

  HyperNEAT::f(f);
  Phenotype * p = new Phenotype(n);
  bool done = d->xorDone(p);
  delete p;
  return done;
}
void  DatasetHyperNEAT::runTest(Phenotype *f)
{
  //   double r = (double)rand()/(double)RAND_MAX;
  //   r = (r==0) ? 10^-5 : r;
  //   f->setFitness(r);
  //   return r;
  HyperNEAT::f(f);
  Phenotype * p = new Phenotype(n);
  d->runTest(p);
  delete p;
}
