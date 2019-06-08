#pragma once
#include <string>
using namespace std;
class cell {
private:
	string type;
	string dataS;
	double dataD;
	long long dataL;
public:
	cell(string t, string d) : type(t) {
		if (t == "string") dataS = d, dataD = 0.0, dataL = 0;
		else if (t == "double") dataS = "empty=D", dataD = stof(d), dataL = 0;
		else if (t == "long") dataS = "empty=L", dataD = 0.0, dataL = stoll(d);
	}
	~cell() {}

	void setType(string t) { type = t; }
	void setData(string d) {
		if (type == "string") dataS = d, dataD = 0.0, dataL = 0;
		else if (type == "double") dataS = "empty=D", dataD = stof(d), dataL = 0;
		else if (type == "long") dataS = "empty=L", dataD = 0.0, dataL = stoll(d);
	}
	string getType() { return type; }
	string getDataS() { return dataS; }
	double getDataD() { return dataD; }
	long long getDataL() { return dataL; }
};