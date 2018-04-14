#pragma once
#include <iostream>
using namespace std;

// assumed max size 12 based on instruction
const int MAXSIZE = 12;


class BubbleSort
{
	int user_array[MAXSIZE],
	    user_size,
		step_count;

public:

	BubbleSort();
	int step();
	void swap(int i, int j);
	void print();
	void populate(int argv_array[], int n);
};

BubbleSort::BubbleSort()
{
};

void BubbleSort::populate(int argv_array[], int n)
{
	// n is size of array
	// passing argv into obj array

	user_size = n;
	step_count = 0;

	for(int i = 0; i < user_size; i++)
		user_array[i] = argv_array[i];
};

void BubbleSort::print()
{
	// prints the array
	cout << endl << "# " << step_count << " BubbleSort: [";
	for(int i = 0; i < user_size; i++)
		cout << user_array[i] << ' ';
	cout << "]";
};

void BubbleSort::swap(int i, int j)
{
	// swaps the two locations of variables
	// temp holds the user_array[i]

	int temp = user_array[i];
	user_array[i] = user_array[j];
	user_array[j] = temp;
	print();
};


int BubbleSort::step()
{
	// sort function processed with 2 for loops

	for(int i = 0; i < user_size - 1; i++)
		for(int j = 0; j < user_size - i - 1; j++)
		{
			step_count++;
			if (user_array[j] > user_array[j + 1])
				swap(j, j + 1);
		}
	return 0;
};

// bubblesort.step()