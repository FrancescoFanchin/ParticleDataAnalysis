#include "BraggStatistic.h"
#include "Event.h"
#include <iostream>
#include <cmath>
#include "Constants.h"
#include <fstream>
#include <vector>
#include "TotalEnergy.h"
#include "TH1F.h"
 const Event* ev;
int m = Event::minSize();
BraggStatistic::BraggStatistic( int min, int max ):
 
   minEnergy(min),maxEnergy(max),n(0),sum(m,0.0),sumsq(m,0.0),mean(m,0.0),rms(m,0.0)
  { 
 

  
}


BraggStatistic::~BraggStatistic() {
  // free dynamic memory
  sum.clear();
  sumsq.clear();
  mean.clear();
  rms.clear();
}


void BraggStatistic::add( const Event& ev ) {
	
  int m = Event::minSize();
  // loop over the min number of points and compute total energy
  float en=TotalEnergy::instance()->energy();
  // check for total energy being in the required range,
  // if not return
  if ((en < maxEnergy) && (en > minEnergy)){
	  float k;
      // loop over points and update sums for each point
      for( int j=0;j<m;++j){
		k=ev.energy(j) - Constants::bgMean;
		sum[j] += k;
		sumsq[j] += k*k;
	  }

      // update event counter
      n++;
  
  }
  else return;
}

const vector<float>& BraggStatistic::eMean() const{ 
  return mean;
}


const vector<float>& BraggStatistic::eRms()  const{
  return rms;
}


void BraggStatistic::compute() {
  int m = Event::minSize();
  // loop over points and compute mean and rms for each point
  for(int i=0;i<m;++i){
			mean[i] = (sum[i] *1.0 / n);
			rms[i] = sqrt((sumsq[i] *1.0 / n) - (mean[i]*mean[i] * 1.0));
		}
		
  return;
}


