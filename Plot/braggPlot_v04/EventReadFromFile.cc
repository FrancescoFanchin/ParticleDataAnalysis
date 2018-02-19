#include "EventReadFromFile.h"

#include "Event.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// read data from file "name"
EventReadFromFile::EventReadFromFile( const string& name ) {
  file = new ifstream( name.c_str() );
}


EventReadFromFile::~EventReadFromFile() {
  delete file;
}


// get an event
const Event* EventReadFromFile::get() {
  return readFile();
}


// read an event
const Event* EventReadFromFile::readFile() {
    Event* ev;
	int i,j,n;
	unsigned int u;
   
    if ( *file  >> i ){
		ev = new Event( i );
		*file >> n;
		
		for (j=0;j<n;j++){
			*file >> u;
			ev->add(u);
		}
		const Event* ev1=ev;
		return ev1;
	} 
 
	else return 0;
  
}

