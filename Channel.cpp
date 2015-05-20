#include "Channel.h"
#include <vector>
#include <iostream>
using namespace std;

vector<double> Channel::data() {
	return values;
}

void Channel::print() {
	for(vector<double>::iterator it = values.begin(); it != values.end(); it++) {
		cout<<*it<<", ";
	}
	cout<<endl;
}