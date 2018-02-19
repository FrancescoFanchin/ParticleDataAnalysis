#include <iostream>
#include <fstream>
#include "Event.h"
#include <cmath>
using namespace std;
const int minum=120;

//compute mean and rms
void stat(int* sum, int* sumsq,float* mean,float* rms,int count){
	for(int i=0;i<minum;++i){
			mean[i] = (sum[i] *1.0 / count);
			rms[i] = sqrt((sumsq[i] *1.0 / count) - (mean[i] * mean[i]*1.0));
		}
	return;
}
