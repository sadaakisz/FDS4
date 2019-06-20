#pragma once
#include <string>
#include <vector>
using namespace std;

class Columna {
protected:
	string tipoDeDato;
public:
	Columna(string tipo) : tipoDeDato(tipo) {}

	string getTipo() { return tipoDeDato; }			//Retorna el "nombre" de la columna. El nombre de una columna 
							
													//indica qué tipo de datos contiene

	void setTipo(string t) { this->tipoDeDato = t; } //Permite cambiar el nombre de la columna
	~Columna(){}
};

class ColumnaString : public Columna {
private:
	vector<string>* datosString;
public:
	ColumnaString(): Columna("String") {
		datosString = new vector<string>;
					  //Agregando 2 "palabras" con propósitos de prueba
		agregar("Hola");
		agregar("mundo");
	}

	~ColumnaString() {
		delete datosString;
	}

	void agregar(string s) {
		datosString->push_back(s);
	}

	string getDato(int indice) {
		return datosString->at(indice);
	}
};

class ColumnaLong : public Columna {
private:
	vector<long long>* datosLong;
public:
	ColumnaLong():Columna("Long") {
		datosLong = new vector<long long>;
		agregar(rand()% 1000000000); //Se agregan 2 long longs con propósitos de prueba
		agregar(2000000000); //
	}

	~ColumnaLong() {
		
		delete datosLong;
	}

	void agregar(long long l) {
		datosLong->push_back(l);
	}

	long getDato(int indice) {
		return datosLong->at(indice);
	}
};

class ColumnaDouble : public Columna {
private:
	vector<double>* datosDouble;
public:
	ColumnaDouble(): Columna("Double") {
		datosDouble = new vector<double>;
		agregar((rand() % 100000)+ rand()%11/10.0 );  //Se agregan 2 doubles aleatorios con propósitos de prueba
		agregar((rand() % 100000) + rand() % 11 / 10.0);
	}

	~ColumnaDouble() {
		
		delete datosDouble;
	}

	void agregar(double d) {
		datosDouble->push_back(d);
	}

	double getDato(int indice) {
		return datosDouble->at(indice);
	}
};

class ColumnaBool : public Columna {
private:
	vector<bool>* datosBool;
public:
	ColumnaBool() : Columna("Bool") {
		datosBool = new vector<bool>;
		agregar(rand() % 2);			//Se agregan valores de tipo bool
		agregar(rand() % 2);			//aleatorios (posible 0 o 1) con propósitos de prueba
	}

	~ColumnaBool() {
		delete datosBool;
	}

	void agregar(bool b) {
		datosBool->push_back(b);
	}

	bool getDato(int indice) {
		return datosBool->at(indice);
	}
};