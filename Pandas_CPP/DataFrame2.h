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
	//map<string, Col*> cols

	DF() {
		Filas = new vector<Fila*>;
		Columnas = new vector<Columna*>;
		agregarColumnaString();			//En este caso se está agregando una columna de
		agregarColumnaLong();			//cada tipo para realizar pruebas
		agregarColumnaDouble();
		agregarColumnaBool();
	}

	//DF* select(vector<string> colNames) { //Retorna un DataFrame. Para escoger de las columnas totales que se tienen cuáles se quieren seleccionar. Puede ser en cualquier orden
	//	colmap* nCols = new colmap();
	//	for (auto cn : colNames) {
	//		nCols[cn] = cols[cn];
	//	}
	//	DF* nuevoDF(nCols);
	//	nuevoDF->rows = this->rows;
	//}

	/*DF* filter(string numcol1, string op1, string val1, string numcol2="", string op2="", string val2=""){
		colmap* nCols = new colmap();
		*nCols = this->Columnas;
		vector<Fila*> nFilas;
		for (auto r : this->Filas) {
			if (compare(numCol1, op1, val1, r) && compare(numcol2, opc2, val2, r))
				nFilas.push_back(r); 
		}
	}*/

	/*void index(string colname) {
		AVLTree<Fila*, string>* t = new AVLTree<Row* r, string>([=](Row* r){ return r->getdata(colname) });
		for (auto row : this->rows) {
			t->Add(row);
		}
		trees[colname] = t; //mapa de árboles
	}*/

	/*DF* sort(string colname) {
		colmap* nCols = new colmap();
		*nCols = this->Columnas;
		DF* nDF=nDF(nCols);
		nDF->rows = this->rows;
		quicksort<Fila*, string>(nDF->rows, [=](Fila* r) {return r->getdata(colname); })
	}*/


	void agregarFila() {
		
		Fila* aux = new Fila(numFilas);
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

	void mostrar() { //Se eliminará más adelante, se hará un lambda en Source.cpp
		cout << "String \t\t Long \t\t Double \t\t Bool" << endl; //Falta hacer que se alineen bien los nombres de las columnas
		for (long long i = 0; i < numFilas; i++) {				  //con los datos
			Filas->at(i)->mostrar();
		}
	}
};