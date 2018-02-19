#ifndef AnalysisSteering_h
#define AnalysisSteering_h

#include "AnalysisInfo.h"
#include "util/include/ActiveObserver.h"

class AnalysisInfo;
class Event;

class AnalysisSteering: public ActiveObserver<AnalysisInfo::AnalysisStatus>  {

 public:

  AnalysisSteering( const AnalysisInfo* info );
  virtual ~AnalysisSteering();

  // function to be called at execution start / end
  virtual void update( const AnalysisInfo::AnalysisStatus& status );

 protected:

  const AnalysisInfo* aInfo;

 private:

  // function to be called at execution start
  virtual void beginJob() = 0;
  // function to be called at execution end
  virtual void   endJob() = 0;

  AnalysisSteering           ( const AnalysisSteering& x );
  AnalysisSteering& operator=( const AnalysisSteering& x );

};

#endif

