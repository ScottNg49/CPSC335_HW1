#include "RaceMgr.h"
#include <stdio.h>


RaceMgr::RaceMgr(int Sarray[]){
	//BubbleSortAlg::BubbleSortAlg(Sarray);
	//MergeSortAlg::MergeSortAlg(Sarray);
	for (int i = 0; i < 4; i++){
		cout << Sarray[i];
	}

	//start calling each step method;count how many turns each algorithm took to complete
}


RaceMgr::~RaceMgr()
{
}
