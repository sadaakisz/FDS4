#pragma once
#include "Columna2.h"
#include "Fila2.h"
/*NUEVO
Implementación*/

class DF {
private:
	
	long long numFilas;
	long long numColumnas;

public:
	vector<Fila*>* Filas;
	vector<Columna*>* Columnas;

	DF() {
		Filas = new vector<Fila*>;
		numFilas = 0;
		Columnas = new vector<Columna*>;
		agregarColumnaString();
		agregarColumnaLong();
		agregarColumnaDouble();
		agregarColumnaBool();
	}

	void agregarFila(Fila* f) {
		Filas->push_back(f);
		numFilas++;
	}

	void agregarColumnaString() {
		Columnas->push_back(new ColumnaString());
		numColumnas++;
	}

	void agregarColumnaLong() {
		Columnas->push_back(new ColumnaLong());
		numColumnas++;
	}

	void agregarColumnaDouble() {
		Columnas->push_back(new ColumnaDouble());
		numColumnas++;
	}

	void agregarColumnaBool() {
		Columnas->push_back(new ColumnaBool());
		numColumnas++;
	}

	void mostrar() { //Borrar más adelante etc
		cout << "String\tLong\tDouble\tBool" << endl;
		for (long long i = 0; i < numFilas; i++) {
			Filas->at(i)->mostrar();
		}
	}
};