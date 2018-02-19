#ifndef EnergyDist_h
#define EnergyDist_h

#include "AnalysisSteering.h"
#include <vector>
#include <string>

class TH1F;
class Event;
class BraggStatistic;

class EnergyDist: public AnalysisSteering {

 public:

  EnergyDist();
  virtual ~EnergyDist();

  // function to be called at execution start
   virtual void beginJob();
  // function to be called at execution end
  virtual void   endJob();
  // function to be called for each event
  virtual void process( const Event& ev );

 private:

  // Bragg curve information
  struct BraggCurve {
    BraggStatistic* braggStat; // mean and rms energies
    TH1F* hist; // energy loss graph
  };

  // set of Bragg curves for different total energies
  vector<BraggCurve*> bCurve;

  // create objects for a Bragg curve
  void bCreate( int id, float min, float max );
  
  char name[100];

  EnergyDist           ( const EnergyDist& x );
  EnergyDist& operator=( const EnergyDist& x );

};

#endif

