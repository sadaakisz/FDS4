#pragma once
#include "Row.h"
class dataframe {
private:
	vector<row*>*Rvector;
	vector<row*>::iterator it;
public:
	dataframe() { 
		Rvector = new vector<row*>; 
		it = Rvector->begin(); 
	}
	~dataframe(){
		for (row* r : *Rvector)
			delete r;
		delete Rvector;
	}



	void upIterator() { it = Rvector->begin(); }

	void push_back(row *r) {
		Rvector->push_back(r); // CRASH POINT //
	}
	void insert(row *r, long long pos) {
		upIterator();
		Rvector->insert(it + pos, r);
	}
	void erase(long long pos) {
		upIterator();
		Rvector->erase(it + pos);
	}
	void erase(long long first, long long last) {
		upIterator();
		Rvector->erase(it + first, it + last);
	}
	row* at(long long pos) { return Rvector->at(pos); }

	void printD() {
		for (long long i; i < Rvector->size(); i++) {
			Rvector->at(i)->printR();
		}
	}
};