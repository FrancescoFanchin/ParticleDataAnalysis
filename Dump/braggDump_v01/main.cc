#include <iostream>
#include <fstream>
using namespace std;

struct Event;
const Event* read(ifstream& ifile);
void dump(const Event* ev);


int main(int argc, char* argv[]){
	const char* name = argv[1];
	const Event* ev;
	ifstream ifile(name);
	while ((ev=read(ifile)) != 0) {
		dump(ev);

	}
	return 0;
}

