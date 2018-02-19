#include "BraggStatistic.h"
#include "Event.h"
#include "EnergyDist.h"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "stdio.h"

using namespace std;

EnergyDist::EnergyDist() {
}


EnergyDist::~EnergyDist() {
	braggStat.clear();
}


// function to be called at execution start
void EnergyDist::beginJob()  {

  // create energy distributions for different total energy ranges
 braggStat.push_back(new BraggStatistic(3000,5000));
 braggStat.push_back(new BraggStatistic(6000,6499));
 braggStat.push_back(new BraggStatistic(6500,6799));
 braggStat.push_back(new BraggStatistic(6800,7200));
  return;

}


// function to be called at execution end
void EnergyDist::endJob() {

  // number of points
  int m=Event::minSize();
  

  // loop over distributions
  int i;
  int n=braggStat.size();
  const string names[]={"Background","Africium","Asium","Australium"};
  BraggStatistic* bStat;
 
  for(i=0;i<n;i++) {
	// get Bragg curve informations
    const string name= names[i];
    // compute results
    bStat = braggStat[i];
    bStat->compute();
     
    vector<float> Mean=bStat->eMean();
    vector<float> Rms=bStat->eRms();
    cout <<endl<<"//////////////////////////////////////"<<endl;
    cout<< name <<" total events: "<< bStat->nEvents() <<endl;
  
    char line[100];
	printf("#     mean    rms\n");
	for(int t=0;t<m;++t){
		sprintf(line,"%d   %3.2f   %2.2f\n",t+1,Mean[t],Rms[t] );  	
		cout << line;
    }
  
  }
  return;
}



// function to be called for each event
void EnergyDist::process( const Event& ev ) {
  // loop over energy distributions and pass event to each of them
  int i;
  int n=braggStat.size();
  BraggStatistic* bStat;
  for (i=0;i<n;i++ ) {
	  bStat = braggStat[i];
	  bStat->add(ev);
      
  }
  return;
}

