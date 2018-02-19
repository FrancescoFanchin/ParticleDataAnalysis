#ifndef BGCalc_h
#define BGCalc_h

#include "AnalysisSteering.h"
#include <vector>
#include "util/include/Singleton.h"
#include "util/include/LazyObserver.h"
#include "util/include/ActiveObserver.h"

class TH1F;
class Event;
class BraggStatistic;

class BGCalc: public ActiveObserver<Event>, public AnalysisSteering  {

 public:

  BGCalc( const AnalysisInfo* info );
  virtual ~BGCalc();

  // function to be called at execution start
  virtual void beginJob();
  // function to be called at execution end
  virtual void   endJob();
  // function to be called for each event
  virtual void update( const Event& ev );

 private:

  // min and max energy, min and max point, number of selected events
  int minen;
  int maxen;
  int minpt;
  int maxpt;
  int nevt;

  // sum of energies and sum of square energies
   vector<float> sum;
  vector<float> sumsq;

  BGCalc           ( const BGCalc& x );
  BGCalc& operator=( const BGCalc& x );

};

#endif

