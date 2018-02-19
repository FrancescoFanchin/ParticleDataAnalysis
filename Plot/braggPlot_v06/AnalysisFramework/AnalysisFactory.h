#ifndef AnalysisFactory_h
#define AnalysisFactory_h

#include <string>
#include <vector>
#include <map>

class AnalysisSteering;
class AnalysisInfo;

class AnalysisFactory {

 public:

  AnalysisFactory();
  virtual ~AnalysisFactory();

  // create all requested analysis objects
  static std::vector<AnalysisSteering*> create( const AnalysisInfo* info );

  // analysis object builder ( it's not a "builder" in the common sense,
  // it's actually an abstract factory )
  class Builder {
   public:
    // Analyzers are registered with a name so that they are actually 
    // created only if, at runtime, their name is listed in the command line
    Builder( const std::string& name ) { registerBuilder( name, this ); }
    virtual ~Builder() {}
    virtual AnalysisSteering* build( const AnalysisInfo* info ) = 0;
  };

 private:

  AnalysisFactory           ( const AnalysisFactory& x );
  AnalysisFactory& operator=( const AnalysisFactory& x );

  // function to add analyzer builders to the factory
  static void registerBuilder( const std::string& name, Builder* b );
  // map to associate analyzer names with corresponding builders
  static std::map<std::string,Builder*>* builderMap();

};

#endif

