#include <iostream>
#include <stdio.h>
using namespace std;

class MergeSortAlg
{
	int LtoSort;
	int Lstart;
	int Lend;

	int RtoSort;
	int Rstart;
	int Rend;

	int step_count;
	int length;
	int intArray[];

public:
	MergeSortAlg();
	int step();
	void populate(int Targetarray[], int n);
	void swap(int i, int j);

};

void MergeSortAlg::populate(int Targetarray[], int n)
{
	// n is size of array
	// passing argv into obj array

	length = n;
	step_count = 0;

	for (int i = 0; i < length; i++)
		intArray[i] = Targetarray[i];
};

MergeSortAlg::MergeSortAlg()
{
	Lstart = 0, LtoSort = 0, Lend = 0;
	Rstart = 1, RtoSort = 1, Rend = 1;

};
void MergeSortAlg::swap(int i, int j)
{
	// swaps the two locations of variables
	// temp holds the user_array[i]

	int temp = intArray[i];
	intArray[i] = intArray[j];
	intArray[j] = temp;
};


//attempts tp merge the "next" two sublists where the second sublist always immediately follows the first
int MergeSortAlg::step(){
	//print
	for (int i = 0; i < 12; i++){
		cout << intArray[i] << " ";
	}
	cout << endl;
	// STATE UPDATES:

	//if left sublist value to be sorted is already in place; INCREMENT UNSORTED VALUE INDEX
	if (intArray[LtoSort] < intArray[RtoSort]){
		if (LtoSort == Lend){
			Lend++;
		}
		LtoSort++;
		if (LtoSort == RtoSort) {
			RtoSort++;
		}

		//check if done (STATE UPDATE: MERGE)-----------
		if (Lend == Rend){
			LtoSort = Lstart;
			Rstart++;
			Rend = (2 * Lend) + 1;
		}

	}	//if left sublist value needs to be swapped; SWAP AND INCREMENT UNSORTED VALUE INDEX
	else if (intArray[LtoSort] > intArray[RtoSort]){
		cout << endl << "These values have been swapped: " << intArray[LtoSort] << " and " << intArray[RtoSort] << endl;
		swap(LtoSort, RtoSort);
		if (LtoSort == Lend){
			Lend++;
		}
		LtoSort++;
		if (LtoSort == RtoSort) {
			RtoSort++;
		}

		//check if done (STATE UPDATE: MERGE)-----------
		cout << endl << "merge complete" << endl;
		if (Lend == Rend){
			LtoSort = Lstart;
			Rstart++;
			Rend = (2 * Lend) + 1;
		}

		//print
		for (int i = 0; i < 12; i++){
			cout << intArray[i] << " ";
		}
	}
	return 0;
};

/*
While(Lend != Rend) {
step();
Ltosort = Lstart;
Rstart++;
Rend = (2*Lend) +1;
}
*/