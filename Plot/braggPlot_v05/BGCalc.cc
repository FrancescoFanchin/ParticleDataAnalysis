#include "BGCalc.h"
#include "AnalysisSteering.h"
#include "TotalEnergy.h"
#include <iostream>
#include "AnalysisFactory.h"
#include <vector>
#include "Event.h"
#include "util/include/Singleton.h"
#include "util/include/LazyObserver.h"
#include <map>
#include <math.h>
using namespace std;

// define a builder for this analyzer and register it
class BGCalcBuilder: public AnalysisFactory::Builder {
 public:

BGCalcBuilder(): AnalysisFactory::Builder( "bgc" ) {}

virtual AnalysisSteering* build( const AnalysisInfo* info ){
 return new BGCalc( info ) ;
}
};

static BGCalcBuilder bb;

BGCalc::BGCalc( const AnalysisInfo* info ):AnalysisSteering(info){}

BGCalc::~BGCalc() {
}


void BGCalc::beginJob() {

  // min and max energy, min and max point, number of selected events
  minen=3000;
  maxen=5000;
  minpt=100;
  maxpt=120;
  
  // sum of energies and sum of square energies
  int m=maxpt-minpt;
  
  // sum of energies and sum of square energies
  sum.reserve(m);
  sumsq.reserve(m);
  
  for(int i=0;i<m;i++){
	sum[i]=0.0;
	sumsq[i]=(0.0);
  }
 
  return;

}


void BGCalc::update( const Event& ev ) {

  // total energy
  float toten = TotalEnergy::instance()->rawSum();
  if ((toten > minen) && (toten < maxen)){
    
	// loop over points and update sums
	int i;
	for ( i=minpt;i<maxpt;++i) {
		sum[i-minpt] += ev.energy(i);
		sumsq[i-minpt] += ev.energy(i)*ev.energy(i);
	}

	// update event counter
	nevt++;
	}
  else return;

}


void BGCalc::endJob() {

  // compute background
  float mean= 0.0;
  float rms= 0.0;
  for (int i = 0; i < maxpt-minpt; ++i){
    mean +=sum[i];
    rms +=sumsq[i];
  } 
  // number of points
  float m = maxpt-minpt;
  
  // compute mean and rms
  mean /= m*nevt*1.0;
  rms = sqrt( (1.0*rms/(nevt*m)) - (mean*mean) );
  // printout result
  cout << "background, mean: " << mean << " rms: " << rms << endl;

  return;

}

