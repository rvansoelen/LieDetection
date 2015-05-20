#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "EEGFile.h"
using namespace std;


EEGFile::EEGFile(string filename) {
	ifstream fin;
	fin.open(filename);
	if(!fin.is_open()) {
		cout<<"Error Opening File.\n";
	}
	
	string header;
	string line;
	getline(fin, header);

	while(getline(fin, line)) {
		//cout<<"*"<<word<<"*"<<endl;
		Channel *c = new Channel();
		istringstream iss(line);
		while(iss.good()) {
			double value;
			iss>>value;
			c->values.push_back(value);
			while(iss.peek() == ' ' || iss.peek() == ',') {
				iss.get(); //skip over spaces and commas
			}
		} 
		if(iss.bad()) {
			cout<<"Error Reading Line.\n";
		}

		//c->print();
	}
	if(fin.bad()) {
		cout<<"Error Reading File.\n";
	}
	fin.close();
}

int EEGFile::numChannels() {
	return _channels.size();
}

string EEGFile::title() {
	return _title;
}

string EEGFile::recDate(){
	return _dateRec;
}

string EEGFile::recTime() {
	return _timeRec;
}

string EEGFile::subject() {
	return _subject;
}

int EEGFile::samplingRate() {
	return _samplingRate;
}

string EEGFile::units() {
	return _units;
}

map<string, Channel *> EEGFile::channels() {
	return _channels;
}

Channel * EEGFile::getChannel(string name) {
	return _channels[name];
}

string EEGFile::filename() {
	return _filename;
}