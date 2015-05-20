#ifndef CHANNEL
#define CHANNEL

#include <vector>
using namespace std;

class Channel {
friend class EEGFile;
protected:
	vector<double> values;

public:
	vector<double> data();
	void print();

};


#endif