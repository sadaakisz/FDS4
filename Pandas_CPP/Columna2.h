#pragma once
#include <string>
#include <vector>
using namespace std;

class Columna {
protected:
	string tipoDeDato;
public:
	Columna(string tipo) : tipoDeDato(tipo) {}

	string getTipo() { return tipoDeDato; }
	void setTipo(string t) { this->tipoDeDato = t; }
	~Columna(){}
};

class ColumnaString : public Columna {
private:
	vector<string*>* datosString;
public:
	ColumnaString(): Columna("String") {
		datosString = new vector<string*>;
	}

	~ColumnaString() {
		for (string* s: *datosString) {
			delete s;
		}
		delete datosString;
	}
};

class ColumnaLong : public Columna {
private:
	vector<long long*>* datosLong;
public:
	ColumnaLong():Columna("Long") {
		datosLong = new vector<long long*>;
	}

	~ColumnaLong() {
		for (long long* s : *datosLong) {
			delete s;
		}
		delete datosLong;
	}
	
};

class ColumnaDouble : public Columna {
private:
	vector<double*>* datosDouble;
public:
	ColumnaDouble(): Columna("Double") {
		datosDouble = new vector<double*>;
	}

	~ColumnaDouble() {
		for (double* d : *datosDouble) {
			delete d;
		}
		delete datosDouble;
	}
};

class ColumnaBool : public Columna {
private:
	vector<bool*>* datosBool;
public:
	ColumnaBool() : Columna("Bool") {
		datosBool = new vector<bool*>;
	}

	~ColumnaBool() {
		for (bool *b : *datosBool) {
			delete b;
		}
		delete datosBool;
	}
};