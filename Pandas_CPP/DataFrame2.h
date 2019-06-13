#pragma once
#include "Columna2.h"
#include "Fila2.h"
class DF {
private:
	
	long long numFilas = 0;
	long long numColumnas=0;

public:
	vector<Fila*>* Filas;
	vector<Columna*>* Columnas;

	DF() {
		Filas = new vector<Fila*>;
		Columnas = new vector<Columna*>;
		agregarColumnaString();
		agregarColumnaLong();
		agregarColumnaDouble();
		agregarColumnaBool();
	}

	void agregarFila() {
		long long ind = 0;
		Fila* aux = new Fila(ind);
		Filas->push_back(aux);
		for (long long i = 0; i < numColumnas; i++) {
			if (Columnas->at(i)->getTipo() == "String")
				aux->setPunteroString((ColumnaString*)Columnas->at(i));
			if (Columnas->at(i)->getTipo() == "Long")
				aux->setPunteroLong((ColumnaLong*)Columnas->at(i));
			if (Columnas->at(i)->getTipo() == "Double")
				aux->setPunteroDouble((ColumnaDouble*)Columnas->at(i));
			if (Columnas->at(i)->getTipo() == "Bool")
				aux->setPunteroBool((ColumnaBool*)Columnas->at(i));
		}
		aux->AsignarDatos();
		numFilas++;
		ind++;
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
		cout << "String \t Long \t Double \t Bool" << endl; //Falta hacer que se alineen bien los nombres de las columnas
		for (long long i = 0; i < numFilas; i++) {
			Filas->at(i)->mostrar();
		}
	}
};