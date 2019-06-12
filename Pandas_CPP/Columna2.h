#pragma once
#include <string>
#include <vector>
using namespace std;
/*NUEVO: 
Funciones agregar en cada columna
Funciones get en cada columna*/
class Columna {
protected:
	string tipoDeDato;
public:
	Columna(string tipo) : tipoDeDato(tipo) {}

	string getTipo() { return tipoDeDato; }			//Devuelve el "nombre" de la columna  El nombre de una columna indica que tipo de datos contiene
	void setTipo(string t) { this->tipoDeDato = t; } //Cambia el "nombre" de la columna
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

	void agregar(string* s) {
		datosString->push_back(s);
	}

	string getDato(int indice) {
		return *datosString->at(indice);
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

	void agregar(long long* l) {
		datosLong->push_back(l);
	}

	long getDato(int indice) {
		return *datosLong->at(indice);
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

	void agregar(double* d) {
		datosDouble->push_back(d);
	}

	double getDato(int indice) {
		return *datosDouble->at(indice);
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

	void agregar(bool* b) {
		datosBool->push_back(b);
	}

	bool getDato(int indice) {
		return *datosBool->at(indice);
	}
};