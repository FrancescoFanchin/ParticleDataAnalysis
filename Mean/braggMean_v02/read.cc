#include <iostream>
#include <fstream>
#include "Event.h"
using namespace std;

const Event* read(ifstream& file ) {
  
  Event* ev;
  int i,j,n;
   unsigned int u;
   if ( file  >> i ){
    ev = new Event( i );
   
    	file >> n;
		
		
		for (j=0;j<n;j++){
           file >> u;
            ev->add(u);
			}
		 
		 
			return ev;
			} 
 
 else return 0;
  }

