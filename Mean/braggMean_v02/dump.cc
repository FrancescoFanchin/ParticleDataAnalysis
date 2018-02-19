#include <iostream>
#include <stdio.h>
#include "Event.h"
using namespace std;

void dump(const Event& ev){
    unsigned int j;
    cout << ev.eventNumber() <<" "<<ev.dataSize() <<" ";
    for(j=0;j<(ev.dataSize() -1);j++){
		cout << ev.energy(j) <<" ";
		} 						
	cout <<ev.energy(ev.dataSize() -1) <<endl;
	
	return;
	}
