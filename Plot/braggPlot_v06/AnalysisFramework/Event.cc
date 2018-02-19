#include "Event.h"
#include <vector>

// set the min (120) and max (128) number of points
unsigned int Event::maxpt=128;
unsigned int Event::minpt=120;

Event::Event( int i ):
  
  
evid(i)
   {
  // allocate array to contain energies: set size at max number of points
  p.reserve(maxpt);

}


Event::~Event() {
  // free dynamic memory
  p.clear();
}


void Event::add( int energyLoss ) {
  // check for max array size:
  // if max number of points not yet reached
  //   increase number of points and store new point energy
  // if max number of points already reached
  //   do nothing
  p.push_back(energyLoss);
	
}


unsigned int Event::eventNumber() const {
  return evid;
}


unsigned int Event::dataSize() const {
  return p.size();
}


int Event::energy( unsigned int i ) const {
  // check for required point being inside the array:
  // - if required point inside the array return its energy
  // - if not return -1
  if (i < p.size()){ 
	return p[i];}
 else return -1;
}


 unsigned int Event::maxSize() {
  return maxpt;
}


 unsigned int Event::minSize() {
  return minpt;
}


