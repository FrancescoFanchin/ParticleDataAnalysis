#include <iostream>
#include <fstream>
#include "Event.h"
#include <vector>
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
		const Event* ev1=ev;
		return ev1;
	} 
 
	else return 0;
}

