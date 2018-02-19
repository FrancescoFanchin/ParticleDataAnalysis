#include "BraggStatistic.h"
#include "Event.h"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

BraggStatistic::BraggStatistic( int min, int max ):
 
minEnergy(min),maxEnergy(max),n(0)
{ 
 // allocate arrays for sums, mean and rms: set size at min number of points
 // set at 0 all sums, means and rms
	int m = Event::minSize();
	sum = new int[m];
	sumsq = new int[m];
	mean = new float[m];
	rms = new float[m];
    for(int y=0;y<m;++y){
		sum[y]=0; 
		sumsq[y]=0;
		mean[y]=0.0;
		rms[y]=0.0;
	}
}


BraggStatistic::~BraggStatistic() {
  // free dynamic memory
  delete[] sum;
  delete[] sumsq;
  delete[] mean;
  delete[] rms;
  
}


void BraggStatistic::add( const Event* ev ) {

  // loop over the min number of points and compute total energy
  int en=0;
  
  for(unsigned int k=0;k<ev->minSize();++k){
	  en+=ev->energy(k);}

  // check for total energy being in the required range,
  // if not return
  if ((en < maxEnergy) && (en > minEnergy)){
	  

  // loop over points and update sums for each point
  for(unsigned int j=0;j<ev->minSize();++j){
	sum[j] += (ev->energy(j));
	sumsq[j] += ((ev->energy(j)) * (ev->energy(j)));
  }

  // update event counter
  n++;
   }
else return;
}


const float* BraggStatistic::eMean() const {
  return mean;
}


const float* BraggStatistic::eRms()  const {
  return rms;
}


void BraggStatistic::compute() {
  // loop over points and compute mean and rms for each point
  for(unsigned int i=0;i<Event::minSize();++i){
	  mean[i] = (sum[i] *1.0 / n);
	  rms[i] = sqrt((sumsq[i] *1.0 / n) - (mean[i]*mean[i] * 1.0));
		}
  return;
}


