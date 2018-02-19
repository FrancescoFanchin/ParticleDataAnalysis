#ifndef StdRandom_H
#define StdRandom_H

#include "Random.h"

class StdRandom: public Random {

 public:

  StdRandom();
  ~StdRandom();

 protected:

  // redeclaration of random number generation functions
  virtual void set( unsigned int seed );
  virtual float generate( Random::probability p, float a, float b );

 private:

  StdRandom           ( const StdRandom& x );
  StdRandom& operator=( const StdRandom& x );

};

#endif

