#include "Event.h"

// set the min (120) and max (128) number of points
unsigned int Event::maxpt=128;
unsigned int Event::minpt=120;

Event::Event( int i ):
  
  evid(i),n(0)

   {
  // allocate array to contain energies: set size at max number of points
  p= new int[maxpt];
  for(unsigned int r=0;r<maxpt;r++){
	  p[r]=0;}
	  
}


Event::~Event() {
  // free dynamic memory
 
	delete[] p;
}


void Event::add( int energyLoss ) {
  // check for max array size:
  // if max number of points not yet reached
  //   increase number of points and store new point energy
  // if max number of points already reached
  //   do nothing
	unsigned int i;
	
	if (n==maxpt){
		maxpt *=2;
		int* pnew = new int[maxpt];
		for (i=0;i<maxpt;i++){
			p[i] = energyLoss;
			pnew[i]=p[i];
		}
		delete[] p;
		p = pnew;/////// Rename pnew >> p
	}
	
	p[n]=energyLoss;
	n++;
	
	return;
}


unsigned int Event::eventNumber() const {
  return evid;
}


unsigned int Event::dataSize() const {
  return n;
}


int Event::energy( unsigned int i ) const {
  // check for required point being inside the array:
  // - if required point inside the array return its energy
  // - if not return -1
	if (i <= maxpt){ 
		return p[i];
	}
	else return -1;
}


 unsigned int Event::maxSize() {
	return maxpt;
}


 unsigned int Event::minSize() {
	return minpt;
}


