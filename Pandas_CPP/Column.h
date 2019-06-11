#pragma once
#include <vector>
#include "Cell.h"
class column {
protected:
	string name;
	vector<cell**>*Cvector;
	vector<cell**>::iterator it;
public:
	column(string s) : name(s) {
		Cvector = new vector<cell**>;
		it = Cvector->begin();
	}
	~column() {
		for (cell** c : *Cvector)
			delete c;
		delete Cvector;
	}
	void setName(string s) { name = s; }
	string getName() { return name; }

	void upIterator() { it = Cvector->begin(); }

	void push_back(cell *c) {
		Cvector->push_back(&c);
	}
	void insert(cell* c, long long pos) {
		upIterator();
		Cvector->insert(it + pos, &c);
	}
	void erase(long long pos) {
		upIterator();
		Cvector->erase(it + pos);
	}
	void erase(long long first, long long last) {
		upIterator();
		Cvector->erase(it + first, it + last);
	}
	cell* at(long long pos) { return (*Cvector->at(pos)); }

	void printC() {
		cout << " " << name << "\t";
		for (long long i = 0; i < Cvector->size(); i++) {
			(*Cvector->at(i))->printC();
		}
		cout << endl;
	}
};