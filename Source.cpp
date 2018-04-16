#include <iostream>
#include <stdio.h>
#include <string>
#include "Header.h"
using namespace std;
const int MAX_INT = 12;
const int MAX_STR = 24;

int main(int argc, const char* argv[]) {
	string InputArray;
	int SortArray[MAX_INT] = { 14, 7, 88, 1, 6, 2, 9, 13, 24, 3, 11, 56};
	//int cnt = 0;
	//cout << "Enter Integer array to be sorted (MAX: 12): \n";
	//getline(cin, InputArray);

	MergeSortAlg MS;
	MS.populate(SortArray, MAX_INT);

	cout << endl << MS.step() << endl;
	cout << endl << MS.step() << endl;
	cout << endl << MS.step() << endl;
	cout << endl << MS.step() << endl;
	cout << endl << MS.step() << endl;
	cout << endl << MS.step() << endl;

	//MergeSortAlg::MergeSortAlg::populate(*SortArray, MAX_INT);
	system("pause");
	return 0;
}