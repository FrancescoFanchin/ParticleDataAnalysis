#include "EventSim.h"

#include "Event.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

// simulate data with random seed
EventSim::EventSim( unsigned int n, unsigned int s ):
 evId( 0 ),
 nMax( n ) {
  srandom( s );
}


EventSim::~EventSim() {
}


// get an event
const Event* EventSim::get() {
  if ( evId < nMax ) return generate();
  return 0;
}


// generate an event
const Event* EventSim::generate() {

  // create a new event
  Event* ev = new Event( ++evId );

  // simulate a number of points
  int nMin = Event::minSize();
  int nMax = Event::maxSize();
  int n = nMin + round( ( nMax - nMin ) * ( random() * 1.0 / RAND_MAX ) );

  // simulate energy loss
  int i;
  for ( i = 0; i < n; ++i ) ev->add( round( random() * 60.0 / RAND_MAX ) );

  return ev;

}

