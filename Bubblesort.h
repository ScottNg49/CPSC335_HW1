#pragma once
#include <iostream>
using namespace std;

// assumed max size 12 based on instruction
const int MAXSIZE = 12;


class BubbleSort
{
	int  user_array[MAXSIZE],
	     user_size,
		 step_count,
		 prefix,
		 suffix;
	bool done;

public:

	BubbleSort();
	bool is_done();
	int step();
	void swap(int i, int j);
	void print();
	void populate(int argv_array[], int n);
};

BubbleSort::BubbleSort()
{
	prefix = 0;
	suffix = 1;
	done = 0;
};

bool BubbleSort::is_done()
{
	return done;
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
	step_count++;
};


int BubbleSort::step()
{
	// sorted prefix and unsorted suffix
	// if swap increment both prefix and suffix and continue
	// if prefix = suffix, suffix[0] is less than all prefix
	// move suffix[0] to end of prefix

	if(suffix == prefix && suffix == (user_size - 1))
		done = true;
	
	cout << "Compared suffix value " << user_array[suffix] << " with prefix value " << user_array[prefix] << '\n';
	step_count++;

	if(user_array[suffix] > user_array[prefix] && suffix <= user_size - 1)
	{
		cout << "Swapped values " << user_array[suffix] << " and " << user_array[prefix] << '\n';
		swap(suffix, prefix);
		//suffix++;
		//prefix++;
	}

	else if(user_array[suffix] < user_array[prefix] && (suffix - 1) == prefix && suffix <= user_size - 2)
	{
		// if suffix is not greater than any prefix
		// move suffix to end of prefix
		// increment suffix and move prefix to 0
		cout << "Moved " << user_array[suffix] << " to the back of prefix\n";
		step_count++;
		suffix++;
		prefix = 0;
	}

	else if(user_array[suffix] <= user_array[prefix] && prefix < suffix)
	{
		// if suffix is not greater than current prefix
		// move prefix up, this assumes prefix < suffix pointer
		prefix++;
	};
	
	// if done is true then return true
	// default is false
	// done represents one pass
	return done;
};
