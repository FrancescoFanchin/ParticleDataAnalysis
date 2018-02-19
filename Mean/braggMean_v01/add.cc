#include <iostream>
#include <fstream>
#include "Event.h"
using namespace std;
const int minum=120;

//boolean function to verify energy condition

bool add(int en,const int minen,const int maxen){
 
	if ((en > maxen)||(en < minen))  {
		return false;
	}
	else{
	return true;
	}
}

//int function to count "good" events

int add(const Event& ev, int* sum,int* sumsq,const int minen, const int maxen) {

	int en=0;
	for(int i=0;i<minum;++i){
		en += ev.p[i];
 
	}

	if (add(en,minen,maxen)){
		for(int j=0;j<minum;++j){
			sum[j] += (ev.p[j]);
			sumsq[j] += ((ev.p[j]) * (ev.p[j]));
	        }
        
		return 1;
		}
	else {
		return 0;
	}

}



