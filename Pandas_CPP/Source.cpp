#include <iostream>
#include <conio.h>
#include "Driver.h"
using namespace std;
int main() {
	/*
	dataframe* d1 = new dataframe();
	row* r1 = new row(0);
	cell* c = new cell("value1");
	cell* c2 = new cell("8.945");
	cell* c3 = new cell("51399874603214");
	cell* c4 = new cell("==+%#*&");
	r1->push_back(c);
	r1->push_back(c2);
	r1->push_back(c3);
	r1->push_back(c4);
	d1->push_back(r1);
	cout << r1->getIndex() << "\t" << r1->at(0)->getType() << "\t" << r1->at(0)->getDataS()<<endl;
	cout << r1->getIndex() << "\t" << r1->at(1)->getType() << "\t" << r1->at(1)->getDataD() << endl;
	cout << r1->getIndex() << "\t" << r1->at(2)->getType() << "\t" << r1->at(2)->getDataS() << endl;
	cout << r1->getIndex() << "\t" << r1->at(2)->getType() << "\t" << r1->at(2)->getDataL() << endl;
	cout << r1->getIndex() << "\t" << r1->at(3)->getType() << "\t" << r1->at(3)->getDataS() << endl;
	*/
	driver* driver1 = new driver();
	driver1->addFile("exampledb.csv"); //
	driver1->print();
	_getch();
	return 0;
}