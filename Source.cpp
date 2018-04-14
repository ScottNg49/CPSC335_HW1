#include <iostream>
#include <string>
#include <sstream>
#include "Bubblesort.h"

using namespace std;

const int MAX_INT = 12;
const int MAX_STR = 24;

class RaceMgr  
{
	BubbleSort BS;

public:
	// Member Functions()
	RaceMgr(int argv_arry[], int n);
	void run();
	
};


RaceMgr::RaceMgr(int argv_arry[], int n) { // n is size of the array
	
	BS.populate(argv_arry, n);
	//MS.populate(argv_arry, n);
	/*MergeSort  MS(argv_arry[], n); 
	
	*/
}


void RaceMgr::run()
{
	//loop
	//do {
		//if (BS.DONE) {
		BS.step();
		BS.print();
		//}
		//}
		/*
		if (MS.DONE) {
			MS.step();
			MS.print();
		*/

	//} while (BS.DONE && MS.DONE);
		

	//loop
		//MS.step();
		//MS.print();
	//cout << "Geekname is: " << geekname << endl;
}


int main() {
	int input[12];
	string InputArray;

	int myarry[12];
	cout << "Enter Integer array to be sorted (MAX: 12): ";
	getline(cin, InputArray);

	stringstream ss(InputArray);
	string s;
	int i = 0;
	
	while (getline(ss, s, ' ')) {
		myarry[i] = stoi(s);
		i++;
	}
	int array_size = i;

	RaceMgr Mgr(myarry, array_size);
	Mgr.run();

	system("pause");
	return 0;
}