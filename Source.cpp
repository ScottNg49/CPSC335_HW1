/*
*********** CPSC 335-04 Project 1 **********************
*********** CPSC335_Project1_SortRace ******************
************* Team Name : SLK **************************
***** Names: Scott Ng, Kavit Meghpara, Luis Rangel *****
** Files: source.cpp, MergeSortAlg.h, Bubblesort.h *****
*/

#include <iostream>
#include <string>
#include <sstream>
#include "Bubblesort.h"

using namespace std;

const int MAX_INT = 12;

class RaceMgr  
{
	BubbleSort BS;
public:
	// Member Functions()
	RaceMgr(int argv_arry[], int n);
	void run();
	void print(int argv_arry[], int n);
};

RaceMgr::RaceMgr(int argv_arry[], int n) { // n is size of the array
	
	BS.populate(argv_arry, n);
	//MS.populate(argv_arry, n);
}

void RaceMgr::print(int argv_arry[], int n) {

	for (int i = 0; i < n; i++)
	{
		cout << argv_arry[i] << " ";
	}
}

void RaceMgr::run()
{
		while (BS.get_state() != 1 /*|| !MS.Done*/) {

			if (BS.get_state() != 1) { // BS.get_state() = 0 means not done

				BS.step();

				if(BS.get_state() == 2){ // BS.get_state() = 2 means valued moved
					cout << "#" << BS.get_step_count() << ",  BS:  [";
					print(BS.get_array(), BS.get_user_size());
					cout << "]" << endl;
				}
			}/*
			if (!MS.is_done()) {
				MS.step();
				msTurnsItTook++;
				mergeSortCallCount++;
				//if(moved){
					cout << "#" << mergeSortCallCount << ",  MS:  [";
					//print();
					cout << "]" << endl;
				}
			}*/
		}
		cout << "BubbleSort took " << BS.get_step_count() << " turns to finish." << endl;
		//cout << "MergeSort took " << msTurnsItTook << " turns to finish." << endl;
}


int main() {
	int myarry[MAX_INT];
	string InputArray;

	cout << "Enter Integer array to be sorted (MAX: 12): ";
	getline(cin, InputArray); // User input

	stringstream ss(InputArray);
	string s;
	int array_size = 0;
	
	while (getline(ss, s, ' ')) { // getline gets it and tokens it after each space
		myarry[array_size] = stoi(s);
		array_size++;
	}

	if (array_size > 1) {
		RaceMgr Mgr(myarry, array_size);
		Mgr.run();
	}
	else {
		cout << "Array already sorted." << endl;
	}

	system("pause");
	return 0;
}