#include "AnalysisObjects/BraggStatistic.h"
#include "AnalysisFramework/AnalysisInfo.h"
#include "AnalysisFramework/AnalysisFactory.h"
#include "AnalysisObjects/TotalEnergy.h"
#include "AnalysisFramework/Event.h"
#include <sstream>
#include "EnergyDist.h"
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include "stdio.h"
#include "TH1F.h"
#include "TFile.h"
#include "util/include/ActiveObserver.h"

using namespace std;



// builder to create a ParticleStatistic analyzer
class EnergyDistBuilder: public AnalysisFactory::Builder {
 public:
  // assign "stat" as name for this analyzer and builder
  EnergyDistBuilder(): AnalysisFactory::Builder( "stat" ) {
	  }
  // create a ParticleStatistic when builder is run
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
	 info1=info;

}


EnergyDist::~EnergyDist() {
	bCurve.clear();
	
}





// function to be called at execution start
 void EnergyDist::beginJob()  { 
	 
	 //check if key "hist" is present 
	 if (info1->contains("hist")==false){
		  
		cout<<"error syntax"<<endl;
		return;
	 }
	
	 //check if key "ranges" is present 

	 if (info1->contains("ranges")==false){
		  
	 cout<<"error syntax "<<endl;
	 return;

	}
	
	//create histogram
	histogram = new TH1F("histogram","All energies", 100, 0,10000);
	 
	//loop over bCreate arguments acquisition 
	ifstream ifile((info1->value("ranges")));
    int i,j,k,l;
    l=0;
    while(ifile.good()){	
		ifile >> i >>j >>k;
        if(i==l){
			bCreate(i,j,k);
	    }
        l++;
    }
    ifile.close();
    return;
}

 
 void EnergyDist::endJob() { 
	
    // fill distributions with mean and rms energies
 
    int m=Event::minSize();
    TDirectory* currentDir=gDirectory;

    file = new TFile((info1->value("hist")).c_str(), "UPDATE" );
    // loop over distributions
    int i,j;
    int n=bCurve.size();
    const string names[]={"Background","Africium","Asium","Australium"};
    BraggStatistic* bStat;
    TH1F* h;
    for ( j=0;j<n;j++ ) {
		// get Bragg curve informations:
		// mean and rms energies and energy loss graph
		bStat= bCurve[j]->braggStat;
		h = bCurve[j]->hist;
		const string name= names[j];
		
		// compute results
		bStat->compute();
		
		// get mean and rms energies
		vector<float> Mean=bStat->eMean();
		vector<float> Rms=bStat->eRms();
		cout<<"\n" << name <<" total events: "<<bStat->nEvents()<<endl;
		char line[100];
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
        histogram->Write();
     }
     file->Write();
     file->Close();
     delete file;
     currentDir->cd();
     return;
}


// function to be called for each event
void EnergyDist::update( const Event& ev )  {
     // loop over energy distributions and pass event to each of them
	 int i;
	 int n=bCurve.size();
	 BraggStatistic* bStat;
	 for (i=0;i<n;i++ ) {
		bStat = bCurve[i]->braggStat;
		bStat->add(ev);
		
		//fill histogram with energy event
		if ((i%4)==0){
			float energy =TotalEnergy::instance()->energy();
			histogram->Fill(energy);}
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

 
