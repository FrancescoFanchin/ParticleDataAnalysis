#ifndef Event_h
#define Event_h
#include <vector>
using namespace std;
class Event {

 public:

  // create event with number "n"
  Event( int i );
  ~Event();
	  
	  
     
  // function to add a point
  void add(int energyLoss );

  // get event-specific information:
  //   event number
  //   number of points in the event
  //   energy for point "i"
  unsigned int eventNumber() const;
  unsigned int dataSize() const;
  int energy( unsigned int i ) const;
 
  // get general informations
  static unsigned int maxSize();
  static unsigned int minSize();

 private:

  // dummy copy constructor and assignment to prevent unadvertent copy
  Event           ( const Event& x );
  Event& operator=( const Event& x );

  // shared variables to contain min and max number of points
 static  unsigned int maxpt;
 static  unsigned int minpt;

  // event-specific informations:
  //   event number
  //   number of points in the event
  //   array with energies
 int evid;
 vector<int>  p;
 
};

#endif

