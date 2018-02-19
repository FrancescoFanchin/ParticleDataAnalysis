#include "EventDump.h"
#include "Event.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

EventDump::EventDump() {
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
void EventDump::process( const Event& ev ) {

	unsigned int j;
    cout << ev.eventNumber() <<" "<<ev.dataSize() <<" ";
    for(j=0;j<(ev.dataSize() -1);j++){
		cout << ev.energy(j) <<" ";
	} 						
	cout <<ev.energy(ev.dataSize() -1) <<endl;
	return;

}

