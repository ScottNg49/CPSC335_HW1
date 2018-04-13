#include <iostream>
#include <stdio.h>
#include <string>
#include "RaceMgr.h"
using namespace std;
const int MAX_INT = 12;
const int MAX_STR = 24;

int main(int argc, const char* argv[]) {
	string InputArray;
	int SortArray[MAX_INT] = { 1, 2, 3, 4 };
	cout << "Enter Integer array to be sorted (MAX: 12): \n";
	getline(cin, InputArray);

	/*for (int i = 0; i < MAX_INT; i++){
			while (!isdigit(InputArray[])){
				i++;
		}
	}*/
	
	RaceMgr::RaceMgr(SortArray);
	system("pause");
	return 0;
}