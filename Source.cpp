#include <iostream>
#include <string>
#include <sstream>
#include "Bubblesort.h"

using namespace std;

const int MAX_INT = 12;

class RaceMgr  
{
	BubbleSort BS;
	int bubbleSortCallCount = 0;
	int mergeSortCallCount = 0;
	int bsTurnsItTook = 0;
	int msTurnsItTook = 0;
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
		cout << argv_arry[i] << ", ";
	}
}

void RaceMgr::run()
{
	//0 is not done
	//1 is done
	//2 valued moved

		while (BS.get_state != 1 /*|| !MS.Done*/) {

			if (BS.get_state != 1) {

				BS.step();

				if(BS.get_state == 2){
					cout << "#" << BS.get_step_count << ",  BS:  [";
					//print();
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
		cout << "BubbleSort took " << BS.get_step_count << " turns to finish." << endl;
		cout << "MergeSort took " << msTurnsItTook << " turns to finish." << endl;
}


int main() {
	int myarry[MAX_INT];
	string InputArray;

	cout << "Enter Integer array to be sorted (MAX: 12): ";
	getline(cin, InputArray);

	stringstream ss(InputArray);
	string s;
	int array_size = 0;
	
	while (getline(ss, s, ' ')) {
		myarry[array_size] = stoi(s);
		array_size++;
	}

	RaceMgr Mgr(myarry, array_size);
	Mgr.run();

	system("pause");
	return 0;
}

/*void RaceMgr::run()
{
	while(BS.get_state() != 1)
		if(BS.get_state() != 1)
		{
			BS.step();
			if(BS.get_state() == 2)
				print(BS.get_array(), BS.get_step_count(), BS.get_user_size());
		};
};*/

/*
void RaceMgr::print(int *argv_array, int step_count, int array_size)
{
	cout << "# " << step_count << " BubbleSort: [";
	for(int i = 0; i < array_size; i++)
		cout << argv_array[i] << ' ';
	cout << "]\n\n";
};*/
