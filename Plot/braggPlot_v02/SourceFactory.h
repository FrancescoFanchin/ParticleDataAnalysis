#ifndef SourceFactory_h
#define SourceFactory_h

#include <string>
#include <map>

class EventSource;
class AnalysisInfo;

class SourceFactory {

 public:

  SourceFactory();
  virtual ~SourceFactory();

  // create event source
  static EventSource* create( const AnalysisInfo* info );

 private:

  SourceFactory           ( const SourceFactory& x );
  SourceFactory& operator=( const SourceFactory& x );

};

#endif

