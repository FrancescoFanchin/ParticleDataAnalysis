#include <iostream>
#include "Event.h"
using namespace std;

void dump(const Event* ev){
    int j;
    cout << ev->evNum <<" "<<ev->n <<" ";
    for(j=0;j<(ev->n -1);j++){
		cout << ev->p[j] <<" ";
		} 						
	cout <<ev->p[ev->n -1] <<endl;
	}
