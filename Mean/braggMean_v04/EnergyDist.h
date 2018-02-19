#ifndef EnergyDist_h
#define EnergyDist_h


#include "AnalysisSteering.h"
#include <vector>

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

  // set of Bragg curves for different total energies
  
  std::vector<BraggStatistic*> braggStat;
  
  
 
  EnergyDist           ( const EnergyDist& x );
  EnergyDist& operator=( const EnergyDist& x );

};

#endif

