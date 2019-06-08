#pragma once
#include <fstream>
#include <sstream>
#include "Dataframe.h"
class driver {
private:
	dataframe mdataframe;
public:
	driver() {}
	~driver() {}
	int addFile(string filename) {
		ifstream f(filename);
		string line, num;
		long long counter=0;
		if (!f.is_open()) {
			cout << endl << "El archivo no se logro abrir" << endl;
			return 0;
		}
		while (f >> line) {
			stringstream ss(line);
			row* auxR = new row(counter);
			counter++;
			while (getline(ss, num, ',')) {
				cell* auxC = new cell(num.c_str());
				auxR->push_back(auxC);
			}
			mdataframe.push_back(auxR);
		}
		f.close();
		/*
		cell* auxC = new cell("value1");
		row* auxR = new row(0);
		auxR->push_back(auxC);
		mdataframe.insert(auxR, 0);*/
		return 0;
	}
	void print() {
		mdataframe.printD();
	}
};