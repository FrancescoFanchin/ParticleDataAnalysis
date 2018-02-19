#include "Random.h"
#include <iostream>

using namespace std;

int Random::verbosity = 0;

Random::Random() {
  if ( verbosity >= 1 ) cout << "create Random " << this << endl; 
  Random*& i = instance();
  if ( i == 0 ) i = this;
}


Random::~Random() {
}


// random number generation functions

void Random::setSeed( unsigned int seed ) {
  if ( verbosity >= 3 ) cout << "Random::setSeed " << endl; 
  // get concrete random generator pointer
  // save a static reference to avoid repeating function call
  static Random*& i = instance();
  if ( verbosity >= 3 ) cout << "Random::setSeed " << i << endl; 
  if ( i == 0 ) {
    cout << "concrete random generator not set" << endl;
  }
  i->set( seed );
  return;
}


float Random::flat( double min , double max ) {
  if ( verbosity >= 3 ) cout << "Random::flat " << endl; 
  // get concrete random generator pointer
  // save a static reference to avoid repeating function call
  static Random*& i = instance();
  if ( verbosity >= 3 ) cout << "Random::flat " << i << endl; 
  if ( i == 0 ) {
    cout << "concrete random generator not set" << endl;
    return ( min + max ) / 2.0;
  }
  return i->generate( Flat, min, max );
}


float Random::gauss( double mean, double rms ) {
  if ( verbosity >= 3 ) cout << "Random::gauss " << endl; 
  // get concrete random generator pointer
  // save a static reference to avoid repeating function call
  static Random*& i = instance();
  if ( verbosity >= 3 ) cout << "Random::gauss " << i << endl; 
  if ( i == 0 ) {
    cout << "concrete random generator not set" << endl;
    return mean;
  }
  return i->generate( Gauss, mean, rms );
}


// get a pointer to a random generator,
// eventually to be assigned a concrete random generator
Random*& Random::instance() {
  if ( verbosity >= 1 ) cout << "Random::instance " << endl; 
  // the pointer is created only once, the first time "instance()" is called
  static Random* p = 0;
  return p;
}

