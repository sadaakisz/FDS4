#pragma once
#include "Row.h"
#include "Column.h"
class dataframe {
private:
	vector<row*>*Rvector;
	vector<row*>::iterator it;
	vector<column*>*Covector;
	vector<column*>::iterator it2;
public:
	dataframe() { 
		Rvector = new vector<row*>; 
		it = Rvector->begin(); 
		Covector = new vector<column*>;
		it2 = Covector->begin();
	}
	~dataframe(){
		for (row* r : *Rvector)
			delete r;
		for (column* c : *Covector)
			delete c;
		delete Rvector, Covector;
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



	void upIteratorCo() { it2 = Covector->begin(); }

	void push_backCo(column *c) {
		Covector->push_back(c); // CRASH POINT //
	}
	void insertCo(column *r, long long pos) {
		upIteratorCo();
		Covector->insert(it2 + pos, r);
	}
	void eraseCo(long long pos) {
		upIteratorCo();
		Covector->erase(it2 + pos);
	}
	void eraseCo(long long first, long long last) {
		upIteratorCo();
		Covector->erase(it2 + first, it2 + last);
	}
	column* atCo(long long pos) { return Covector->at(pos); }



	void printD() {

		for (long long i=0; i < Rvector->size(); i++) {
			Rvector->at(i)->printR();
		}
	}
};