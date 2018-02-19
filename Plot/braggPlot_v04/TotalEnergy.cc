#include "TotalEnergy.h"
#include "Event.h"


using namespace std;


TotalEnergy::TotalEnergy() {
}


TotalEnergy::~TotalEnergy() {
}


// function to be called when a new event arrives
void TotalEnergy::update( const Event& ev ) {
	// set sum at 0
    sumen=0.0;
    float en;
    // loop over points
    int m = Event::minSize();
    for (int k=0;k<m;++k) {
		// get energy measurement
		en=ev.energy(k);
		// increment sum
		sumen+=en;
    }
    return;
}


// sum of measurements, no background subtraction
float TotalEnergy::rawSum() {
	// check for new event and return result
	check();
	return sumen;
}

