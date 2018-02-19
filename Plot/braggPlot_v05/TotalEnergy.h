#ifndef TotalEnergy_h
#define TotalEnergy_h

#include "Event.h"
#include "util/include/Singleton.h"
#include "util/include/LazyObserver.h"

#include <vector>
class Event;
class TotalEnergy:public Singleton<TotalEnergy>,public LazyObserver<Event>{

  friend class Singleton<TotalEnergy>;

 public:

  // function to be called when a new event arrives
  virtual void update( const Event& ev );

  // sum of measurements, no background subtraction
  float energy();
  float rawSum();

 private:

  // sum of data, no background subtraction
  float sumen;
  float sumensub;
 
  TotalEnergy();
  ~TotalEnergy();
  TotalEnergy           ( const TotalEnergy& x );
  TotalEnergy& operator=( const TotalEnergy& x );

};

#endif

