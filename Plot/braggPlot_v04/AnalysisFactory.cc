#include "AnalysisFactory.h"
#include "AnalysisInfo.h"
#include <iostream>

using namespace std;

AnalysisFactory::AnalysisFactory() {
}


AnalysisFactory::~AnalysisFactory() {
}


vector<AnalysisSteering*> AnalysisFactory::create( const AnalysisInfo* info ) {
  vector<AnalysisSteering*> aList;
  // loop over analysis object builders
  static map<string,Builder*>* bm = builderMap();
  map<string,Builder*>::iterator iter = bm->begin();
  map<string,Builder*>::iterator iend = bm->end();
  while ( iter != iend ) {
    const pair<string,Builder*>& element = *iter++;
    // create analysis object if its name is listed in the command line
    if ( info->contains( element.first ) )
        aList.push_back( element.second->build( info ) );
  }
  return aList;
}


// function to add analyzer builders to the factory
void AnalysisFactory::registerBuilder( const string& name, Builder* b ) {
  static map<string,Builder*>& bm = *builderMap();
  bm[name] = b;
  return;
}


// map to associate analyzer names with corresponding builders
std::map<std::string,AnalysisFactory::Builder*>*
                     AnalysisFactory::builderMap() {
  static map<string,Builder*>* bm = new map<string,Builder*>;
  return bm;
}

