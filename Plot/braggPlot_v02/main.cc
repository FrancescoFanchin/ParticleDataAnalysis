#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "BraggStatistic.h"
#include "EventDump.h"
#include "Event.h"
#include "EnergyDist.h"
#include "AnalysisInfo.h"
#include "SourceFactory.h"
#include "EventSource.h"

using namespace std;

int main( int argc, char* argv[] ) {
	// store command line parameters
	 AnalysisInfo* info = new AnalysisInfo( argc, argv );
	 
	  // create data source
  EventSource* es = SourceFactory::create( info );

  
 

// create a list of analyzers
  vector<AnalysisSteering*> aList;


  // create object to dump event and store into list of analyzers
  aList.push_back( new EventDump );

  // create object to compute pt mean and rms and store into list of analyzers
  aList.push_back( new EnergyDist );

  // variables to loop over analyzers
  int l = aList.size();
  int i;
  
 // initialize all analyzers
  for ( i = 0; i < l; ++ i ) aList[i]->beginJob();

  // loop over events
  const Event* ev;
 
  while ( ( ev = es->get() ) != 0 ) {
    for ( i = 0; i < l; ++ i ) aList[i]->process( *ev );
    
    delete ev;
  }

  // finalize all analyzers
  for ( i = 0; i < l; ++ i ) aList[i]->endJob();

  return 0;

}
 
