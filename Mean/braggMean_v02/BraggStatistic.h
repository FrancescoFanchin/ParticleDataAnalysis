#ifndef BraggStatistic_h
#define BraggStatistic_h

class Event;
class BraggStatistic {



 public:

  // create a set of counters for events with 
  // total energy between minEnergy and maxEnergy
  BraggStatistic( int min, int max );
  ~BraggStatistic();

  // add an event, after checking for total energy
  void add( const Event* ev);
  // compute mean and rms
  void compute();

  // return results:
  // number of events with total energy in the range
  // array of mean energies for each point
  // array of rms  energies for each point
  int nEvents() const { return n; }
  const float* eMean() const;
  const float* eRms()  const;

 private:

  // dummy copy constructor and assignment to prevent unadvertent copy
  BraggStatistic           ( const BraggStatistic& x );
  BraggStatistic& operator=( const BraggStatistic& x );

  // min and max energy, number of selected events
  int minEnergy;
  int maxEnergy;
  int n;

  // arrays with sum of energies and sum of square energies
  int* sum;
  int* sumsq;

  // arrays with mean and rms energies
  float* mean;
  float* rms;

 
};

#endif

