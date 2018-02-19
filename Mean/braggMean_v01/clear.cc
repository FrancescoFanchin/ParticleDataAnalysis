#include <iostream>
#include "Event.h"
using namespace std;

void clear(const Event* ev){
delete[] ev->p;
delete ev;
}
