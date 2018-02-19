#ifndef EventSim_h
#define EventSim_h

#include "EventSource.h"

#include <iostream>
#include <fstream>
#include <string>
class Event;

class EventSim: public EventSource {

 public:

  // simulate n events with random seed s
  EventSim( unsigned int n, unsigned int s );
  virtual ~EventSim();

  // get an event
  virtual const Event* get();

 private:

  int evId;
  int nMax;

  // generate and event
  const Event* generate();

  EventSim           ( const EventSim& x );
  EventSim& operator=( const EventSim& x );

};

#endif

