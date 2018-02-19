#include "StdRandom.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

static StdRandom sr;

StdRandom::StdRandom() {
  if ( verbosity >= 1 ) cout << "create StdRandom " << this << endl; 
}


StdRandom::~StdRandom() {
}


// implementation of random number generation functions

void StdRandom::set( unsigned int seed ) {
  if ( verbosity >= 2 ) cout << "StdRandom::set called" << endl;
  srandom( seed );
  return;
}


float StdRandom::generate( Random::probability p, float a, float b ) {
  if ( verbosity >= 2 ) cout << "StdRandom::generate called" << endl;
  float x = random() * 1.0 / RAND_MAX;
  switch ( p ) {
  case Random::Flat:
    return a + ( x * ( b - a ) );
  case Random::Gauss:
    float y = random() * 1.0 / RAND_MAX;
    return a - ( b * sqrt( -log( 1.0 - x ) ) * cos( 2.0 * M_PI * y ) );
  }
  return 0.0;
}


