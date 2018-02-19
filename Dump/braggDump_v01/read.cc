#include <iostream>
#include <fstream>
#include "Event.h"
using namespace std;

const Event* read(ifstream& ifile){
	Event ev[3];
	int k,n,j;
	int q[128];
	if ( ifile >> k){
		ev->evNum =k;
		ifile >> n;
		ev->n = n;
		for (j=0;j<n;j++){
			ifile >> q[j];
			ev->p[j] = q[j];}
		 	const Event* ev1=ev;
			return ev1;
		}
	else return 0;
}
