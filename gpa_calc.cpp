#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct duo{
	double grdpnts, unts;
};
//setting prototypes
duo open_store(string filename, duo &CPSC);

//int main
int main(){
	duo display, CPSC;
	display = open_store("classes.txt", CPSC);
	cout << "**Total GPA**" << endl;
	cout << display.grdpnts <<  " / " << display.unts << endl;
	cout << display.grdpnts / display.unts << endl << endl;

	cout << "**Computer Science GPA**" << endl;
	cout << CPSC.grdpnts << " / " << CPSC.unts << endl;
	cout << CPSC.grdpnts / CPSC.unts << endl << endl; //CS_GPA = 3.33389

	return 0;
}

duo open_store(string filename, duo &CPSC){
	string theclass;
	string grade;
	string units;
	string toss;
	double gradepoints = 0;
	bool trig = true;
	duo temp;

	ifstream fin;
	fin.open(filename);
	while(getline(fin,theclass, ',')){
		trig = true;
		getline(fin,grade, ',');
		getline(fin,units, ',');
		getline(fin,toss);
		cout << "CLASS: " << theclass << endl;
		cout << "GRADE:" << grade << endl;
		cout << "UNITS:" << units << endl;

		if(grade == " A"){
			gradepoints = 4 * stoi(units);
		}
		else if(grade == " A-"){
			gradepoints = 3.67 * stoi(units);
		}
		else if(grade == " B+"){
			gradepoints = 3.34 * stoi(units);
		}
		else if(grade == " B"){
			gradepoints = 3 * stoi(units);
		}
		else if(grade == " B-"){
			gradepoints = 2.67 * stoi(units);
		}
		else if(grade == " C+"){
			gradepoints = 2.34 * stoi(units);
		}
		else if(grade == " C"){
			gradepoints = 2 * stoi(units);
		}
		else if(grade == " D"){
			gradepoints = 1 * stoi(units);
		}
		else{
			gradepoints = 0;  trig = false;
			cout << endl;
		}

		//add units and grade points to total
		temp.unts = temp.unts + stoi(units);
		temp.grdpnts = temp.grdpnts + gradepoints;
		if(trig){
			cout << "\tTotal Grade Points : " << temp.grdpnts << endl;
			cout << "\tTotal Units Count  : " << temp.unts << endl << endl;
		}

		//if the class is CPSC or COMS or CS-
		string classy = string() + theclass[0] + theclass[1] + theclass[2] + theclass[3];
		if(classy == "CPSC" || classy == "COMS" || classy == "CS-3" || classy == "CS-4"){
			CPSC.grdpnts = CPSC.grdpnts + gradepoints;
			CPSC.unts = CPSC.unts + stoi(units);
		}
	}
	fin.close();
	return temp;
}
