#pragma once
#include <string>
#include <iostream>
using namespace std;
class cell {
protected:
	string type;
	string dataS;
	double dataD;
	long long dataL;
public:
	cell(string d) {
		string t = checkType(d);
		type = t;
		if (t == "string") dataS = d, dataD = 0.0, dataL = 0;
		else if (t == "double") dataS = "empty=D", dataD = stof(d), dataL = NULL;
		else if (t == "long") dataS = "empty=L", dataD = NULL, dataL = stoll(d);
		else if (t == "unknown") dataS = d, dataD = NULL, dataL = NULL;
		else dataS = "error", dataD = NULL, dataL = NULL;
	}
	~cell() {}

	string checkType(string d) {
		if (d[0] >= 65 && d[0] <= 122) return "string";
		else if (d[0] >= 48 && d[0] <= 57) {
			if ((double)stoll(d) != stod(d)) return "double";
			else if ((double)stoll(d) == stod(d)) return "long"; 
		}
		else return "unknown";
	}

	void setType(string t) { type = t; }
	void setData(string d) {
		string t = checkType(d);
		type = t;
		if (t == "string") dataS = d, dataD = 0.0, dataL = 0;
		else if (t == "double") dataS = "empty=D", dataD = stof(d), dataL = NULL;
		else if (t == "long") dataS = "empty=L", dataD = NULL, dataL = stoll(d);
		else if (t == "unknown") dataS = d, dataD = NULL, dataL = NULL;
		else dataS = "error", dataD = NULL, dataL = NULL;
	}
	string getType() { return type; }
	string getDataS() { return dataS; }
	double getDataD() { return dataD; }
	long long getDataL() { return dataL; }

	void printC() {
		cout <<"|\t"<< type << "\t";
		if (type == "string"||type=="unknown"||type=="error") cout << dataS;
		else if (type == "double") cout << dataD;
		else if (type == "long")cout << dataL;
		cout << "\t|";
	}
};