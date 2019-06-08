#include <iostream>
#include <conio.h>
#include "Row.h"
using namespace std;

int main() {
	row* r1 = new row(0);
	cell* c = new cell("string", "value1");
	cell* c2 = new cell("double", "8.945");
	r1->push_back(c);
	r1->push_back(c2);
	cout << r1->getIndex() << "\t" << r1->at(0)->getType() << "\t" << r1->at(0)->getDataS()<<endl;
	cout << r1->getIndex() << "\t" << r1->at(1)->getType() << "\t" << r1->at(1)->getDataD() << endl;
	cout << r1->getIndex() << "\t" << r1->at(1)->getType() << "\t" << r1->at(1)->getDataS() << endl;
	_getch();
	return 0;
}