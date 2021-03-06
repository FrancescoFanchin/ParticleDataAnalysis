#include "BraggStatistic.h"
#include "AnalysisFactory.h"
#include "Event.h"
#include "EnergyDist.h"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "stdio.h"
#include "TH1F.h"
#include "TFile.h"


using namespace std;

// builder to create a ParticleStatistic analyzer
class EnergyDistBuilder: public AnalysisFactory::Builder {
 public:
  // assign "stat" as name for this analyzer and builder
  EnergyDistBuilder(): AnalysisFactory::Builder( "stat" ) {}
  // create a EnergyDist when builder is run
  virtual AnalysisSteering* build( const AnalysisInfo* info ) {
    return new EnergyDist( info );
  }
};
// create a global EnergyDistBuilder,
// so that it is created and registered before main execution start:
// when the AnalysisFactory::create function is run,
// a EnergyDistBuilder will be available with name "stat".
static EnergyDistBuilder ps;

using namespace std;

EnergyDist::EnergyDist( const AnalysisInfo* info ):
 AnalysisSteering( info ) {
}


EnergyDist::~EnergyDist() {
}





// function to be called at execution start
 void EnergyDist::beginJob()  {

  // create energy distributions for different total energy ranges
  bCreate(0,3000,5000);
  bCreate(1,6000,6499);
  bCreate(2,6500,6799);
  bCreate(3,6800,7200);
  
  return;

}


// function to be called at execution end
void EnergyDist::endJob() {
   TDirectory* currentDir=gDirectory;
   TFile* file = new TFile( "h.root", "UPDATE" );
   

  // number of points
   int m=Event::minSize();
 
 
  // loop over distributions
  int i,j;
  int n=bCurve.size();
 
    const string names[]={"Background","Africium","Asium","Australium"};
  BraggStatistic* bStat;
  TH1F* h;
  
  for ( j=0;j<n;j++ ) {
    // get Bragg curve informations:
    // mean and rms energies and energy loss graph
    const string name= names[j];
     bStat= bCurve[j]->braggStat;
     h = bCurve[j]->hist;
      

    // compute results
    bStat->compute();
     

    // get mean and rms energies
    vector<float> Mean=bStat->eMean();
    vector<float> Rms=bStat->eRms();
    cout<<"\n" << name <<" total events: "<<bStat->nEvents()<<endl;
    char line[100];
    printf("#     mean    rms\n");
    

    // loop over points
		for (i=0;i<m;i++) {
			sprintf(line,"%d   %3.2f   %2.2f\n",i+1,Mean[i],Rms[i] );  	
			cout << line;
        
            // set center and error values in the graph
            // by using SetBinContent and SetBinError, bin count starts from 1
            h->SetBinContent(i,Mean[i]);
            h->SetBinError(i, Rms[i]); 
        
            // save distribution
            TDirectory* currentDir = gDirectory;
     
        }

        h->Write();


  }
  file->Write();
  file->Close();
  delete file;
  currentDir->cd();


  return;
}


// function to be called for each event
void EnergyDist::process( const Event& ev )  {
  // loop over energy distributions and pass event to each of them
  int i;
  int n=bCurve.size();
  BraggStatistic* bStat;
  for (i=0;i<n;i++ ) {
	  bStat = bCurve[i]->braggStat;
	 
	  bStat->add(ev);
  }

return;
}
  
  // create objects for a Bragg curve
void EnergyDist::bCreate( int id, float min, float max ) {

  // create energy distribution for events with total energy in given range
   BraggStatistic* bStat = new BraggStatistic(min, max);
  
  // create name for TH1F object as "hMeaX" with X given by id
  char* name = new char[100];   
  sprintf( name, "hMea%d",id);
 
  // bin number equal to point number
  unsigned int bin=20;

  // create TH1F and statistic objects and store their pointers
  TH1F * h = new TH1F(name, name, bin, min,max);
   
  BraggCurve* bCur = new BraggCurve;
  bCur->braggStat = bStat;
  bCur->hist = h;
  bCurve.push_back(bCur);

  
 return;

}

