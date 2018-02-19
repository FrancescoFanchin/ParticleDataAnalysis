#include "EventDump.h"
#include "AnalysisFramework/Event.h"
#include "AnalysisFramework/AnalysisFactory.h"
#include "AnalysisFramework/AnalysisInfo.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include "util/include/ActiveObserver.h"
#include "util/include/Singleton.h"
using namespace std;

// builder to create an EventDump analyzer
class EventDumpBuilder: public AnalysisFactory::Builder {
 public:
  // assign "dump" as name for this analyzer and builder
  EventDumpBuilder(): AnalysisFactory::Builder( "dump" ) {}
  // create an EventDump when builder is run
  virtual AnalysisSteering* build( const AnalysisInfo* info ) {
    return new EventDump( info );
  }
};
// create a global EventDumpBuilder, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// an EventDumpBuilder will be available with name "dump".
static EventDumpBuilder ed;

EventDump::EventDump( const AnalysisInfo* info ):
 AnalysisSteering( info ) {
}


EventDump::~EventDump() {
}



// function to be called at execution start
void EventDump::beginJob() {
  return;
}


// function to be called at execution end
void EventDump::endJob() {
  return;
}


// function to be called for each event
void EventDump::update( const Event& ev ) {

  unsigned int j;
  cout << ev.eventNumber() <<" "<<ev.dataSize() <<" ";
  for(j=0;j<(ev.dataSize() -1);j++){
	cout << ev.energy(j) <<" ";
  } 						
  cout <<ev.energy(ev.dataSize() -1) <<endl;
  return;
}

