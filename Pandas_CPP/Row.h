#pragma once
#include <vector>
#include "Cell.h"
class row {
protected:
	long long index;
	vector<cell*>*Cvector;
	vector<cell*>::iterator it;
public:
	row(long long i) : index(i) {
		Cvector = new vector<cell*>;
		it = Cvector->begin();
	}
	~row() {
		for (cell* c : *Cvector)
			delete c;
		delete Cvector;
	}

	void setIndex(long long i) { index = i; }
	long long getIndex() { return index; }

	void upIterator() { it = Cvector->begin(); }

	void push_back(cell *c) {
		Cvector->push_back(c);
	}
	void insert(cell* c, long long pos) {
		upIterator();
		Cvector->insert(it + pos, c);
	}
	void erase(long long pos) {
		upIterator();
		Cvector->erase(it + pos);
	}
	void erase(long long first, long long last) {
		upIterator();
		Cvector->erase(it + first, it + last);
	}
	cell* at(long long pos) { return Cvector->at(pos); }

	void printR() {
		cout << " " << index << "\t";
		for (long long i = 0; i < Cvector->size(); i++) {
			Cvector->at(i)->printC();
		}
		cout << endl;
	}
};