#pragma once
//NUEVO
#include "Columna2.h"
#include <iostream>
using namespace std;
class Fila {
private:
	long long indice;
	string datoString;
	long long datoLong;
	double datoDouble;
	bool datoBool;

	ColumnaString	*ColString; //Punteros a columnas de cada tipo para obtener los datos a partir de ellas.
	ColumnaLong		*ColLong;
	ColumnaDouble	*ColDouble;
	ColumnaBool		*ColBool;

public:
	Fila(int ind) : indice(ind) {
		datoString	= "";
		datoLong	= NULL;
		datoDouble	= NULL;
		datoBool	= NULL;
		ColString	=nullptr;
		ColLong		=nullptr;
		ColDouble	=nullptr;
		ColBool		=nullptr;
	}

	Fila(int ind, string str, double doub, long long lon, bool boo, ColumnaString *colS, ColumnaLong *colL,
		ColumnaDouble *colD, ColumnaBool *colB) : indice(ind), datoString(str), datoLong(lon), datoDouble(doub), datoBool(boo),
		ColString(colS), ColLong(colL), ColDouble(colD), ColBool(colB) {}

	~Fila(){
		delete ColString;
		delete ColLong	;
		delete ColDouble;
		delete ColBool	;
	}

	void AsignarDatos() {
		datoString = ColString->getDato(this->indice);
		datoLong = ColLong->getDato(this->indice);
		datoDouble = ColDouble->getDato(this->indice);
		datoBool = ColBool->getDato(this->indice);
	}

	void mostrar() { //Eliminar más adelante, hacer lambda en Source.cpp
		cout << "| " << datoString << " |\t" << "| " << datoLong << " |\t" << "| " << datoDouble << " |\t" << "| " << datoBool << " |" << endl;
	}


};