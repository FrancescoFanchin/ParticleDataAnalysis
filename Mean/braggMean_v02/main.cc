#include <iostream>
#include <fstream>
#include <sstream>
#include "BraggStatistic.h"
#include "Event.h"
using namespace std;

const Event* read( ifstream& file );
void dump( const Event& ev );

int main( int argc, char* argv[] ) {

  const char* name = argv[1];
  ifstream file( name);
  
  //create BraggStatistic classes
  BraggStatistic ba(3000,5000);
  BraggStatistic af(6000,6499);
  BraggStatistic as(6500,6799); 
  BraggStatistic au(6800,7200);
 
 
 const Event* ev;
  while ( ( ev = read(file) ) != 0 ) {
   dump( *ev );
   //call add function  
   ba.add(ev);
   af.add(ev);
   as.add(ev);
   au.add(ev);
   
  
   }
   
  
  //compute mean, rms and print results
    
    cout <<endl<<"////////////////////////////"<<endl;
    unsigned int t;
   
   ba.compute();
   const float* baM=ba.eMean();
   const float* baR=ba.eRms();
	  printf( "Background total events: %d\n",ba.nEvents());
	  	   char line[100];
	  	   printf("#     mean    rms\n");
	  	   for(t=0;t<ev->minSize();++t){
			   sprintf(line,"%d   %3.2f   %2.2f\n",t+1,baM[t],baR[t] );  	
			   cout << line;
	  }
  
  
  
  af.compute();
   const float* afM=af.eMean();
   const float* afR=af.eRms();
	  printf( "Africium total events: %d\n",af.nEvents());
	  	   char line1[100];
	  	   printf("#     mean    rms\n");
	  	   for(t=0;t<ev->minSize();++t){
			   sprintf(line1,"%d   %3.2f   %2.2f\n",t+1,afM[t],afR[t]  ); 
			   cout << line1;
	  }
  
  
 
  
  as.compute();
   const float* asM=as.eMean();
   const float* asR=as.eRms();
	  printf( "Asium total events: %d\n",as.nEvents());
	  	   char line2[100];
	  	   printf("#     mean    rms\n");
	  	   for(t=0;t<ev->minSize();++t){
			  sprintf(line2,"%d   %3.2f   %2.2f\n",t+1,asM[t],asR[t]  );
			  	cout << line2;
	  }
  
  
  
  au.compute();
  const float* auM=au.eMean();
   const float* auR=au.eRms();
   
	  printf( "Australium total events: %d\n",au.nEvents());
	  	  char line3[100];
	  	   printf("#     mean    rms\n");
	  	   for(t=0;t<ev->minSize();++t){
			  sprintf(line3,"%d   %3.2f   %2.2f\n",t+1,auM[t],auR[t]  );
			   cout << line3;
	  }

 return 0;

}

