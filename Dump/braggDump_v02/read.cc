#include <iostream>
#include <fstream>
#include "Event.h"
using namespace std;

const Event* read(ifstream& ifile){
Event* ev;
	int k,n,j;
	
	if ( ifile >> k){
		ev = new Event;
		ev->evNum = k;
		ifile >> n;
		ev->n = n;
		ev->p = new int[n];
		for (j=0;j<n;j++){
			ifile >> ev->p[j];
			}
		 const Event* ev1=ev;
		 
		return ev1;
		}
	else return 0;
}
