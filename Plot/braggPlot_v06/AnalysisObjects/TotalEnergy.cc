
#include "TotalEnergy.h"
#include "AnalysisUtilities/Constants.h"
#include "AnalysisFramework/Event.h"
#include <iostream>
#include <math.h>

using namespace std;


TotalEnergy::TotalEnergy() {
}


TotalEnergy::~TotalEnergy() {
}


// function to be called when a new event arrives
void TotalEnergy::update( const Event& ev ) {
  // set sum at 0
   sumen=0;
   float en;
   // loop over points
   int m = Event::minSize();
   for ( int k=0;k<m;++k) {
		// get energy measurement
		en=ev.energy(k);
        // increment sum
        sumen+=en;
   }
  const float bg=Constants::bgMean;
  sumensub =sumen-(bg*m);
  return;
}




float TotalEnergy::energy() {
  // check for new event and return result
  check();
  return sumensub;
}


float TotalEnergy::rawSum() {
  // check for new event and return result
  check();
  return sumen;
}
