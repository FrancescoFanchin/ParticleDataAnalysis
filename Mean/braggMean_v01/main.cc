#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;



struct Event;
const Event* read(ifstream& ifile);
void dump(const Event& ev);
void clear(const Event* ev);
int  add( const Event& ev, int* sum, int* sumsq,const int minem,const int maxen);
void stat(int* sum,int* sumsq,float* mean, float* rms,int count );

extern const int minum=120;  


int main(int argc, char* argv[]){
	const char* name = argv[1];

//inizializations

	const int minen=6500;
	const int maxen=7500;
	int sum[minum];
	int sumsq[minum];
	float mean[minum];
	float rms[minum];
	for(int q=0;q<minum;q++){
		sum[q]=0;
		sumsq[q]=0;
		mean[q]=0.0;
		rms[q]=0.0;
	  
	  }
	int count = 0;
  
  //main program
  
	const Event* ev;
	ifstream ifile(name);
	while ((ev=read(ifile)) != 0) {
		dump(*ev);
		count += add( *ev, sum, sumsq,minen,maxen );
		clear(ev);
	}
	stat( sum,sumsq, mean, rms,count );
  
	//print results
	
	 printf("\n////////////////////\n");
	 printf( "number of good events: %d\n",count);
	 char line[100];
	 printf("#     mean    rms\n");
	 for(int t=0;t<minum;++t){
		sprintf(line,"%d   %3.2f   %2.2f\n",t+1,mean[t],rms[t]);  	
		cout << line;
	 }
 
	return 0;
}

