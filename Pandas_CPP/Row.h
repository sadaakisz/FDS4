#pragma once
#include <vector>
#include "Cell.h"
class row {
private:
	long long index;
	vector<cell*>*Rvector;
	vector<cell*>::iterator it;
public:
	row(long long i): index(i) {
		Rvector = new vector<cell*>;
		it = Rvector->begin();
	}
	~row() {
		for (cell* c : *Rvector)
			delete c;
		delete Rvector;
	}

	void setIndex(long long i) { index = i; }
	long long getIndex() { return index; }

	void push_back(cell *c) {
		Rvector->push_back(c);
	}
	void insert(string type, string data, long long pos) {
		Rvector->insert(it + pos, new cell(type, data));
	}
	void erase(long long pos) {
		Rvector->erase(it + pos);
	}
	void erase(long long first, long long last) {
		Rvector->erase(it+first,it+last);
	}
	cell* at(long long pos) { return Rvector->at(pos); }
};