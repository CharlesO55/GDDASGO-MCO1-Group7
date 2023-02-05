/****************************************************
Group: 		
Section:	
Members:	
****************************************************/

#include <stdio.h>
#include <time.h>
#include "main.h"
#include "Sorting_Algorithms/bubbleSort.h"
#include "Sorting_Algorithms/insertionSort.h"
#include "Sorting_Algorithms/selectionSort.h"
#include "Sorting_Algorithms/mergeSort.h"
#include "Sorting_Algorithms/sort5.h"
#include "Sorting_Algorithms/sort6.h"
#include "generateData.h"
#include "timer.h"
#include "csvGenerator.h"

//gcc -Wall -o main main.c && main
int main() {
	//STARTUP
	srand(time(NULL));

	int aData[ALGORITHM_RUNS][DATA_SET_SIZE];
	double aCounters[ALGORITHM_RUNS] = {0};
	struct timespec aTimeLogs[ALGORITHM_RUNS][2];
	double aSortingTime[ALGORITHM_RUNS];
	int nSortingType;

	//Will be removed. For testing only
	chooseSortingType(&nSortingType);

	int M;
	for (M = 0; M < ALGORITHM_RUNS; M++){	//REPEAT FOR NUMBER OF ALGORITHM RUNS
		printf("\nRUN #%d STARTING DATA:\n", M);
		generateData(aData[M], DATA_SET_SIZE);
		printData(aData[M], DATA_SET_SIZE);

		
		//ALGORITHM SORTING.
		aTimeLogs[M][0] = getTime();	//LOG START TIME


		//CALL THE ALGORITHM
		switch (nSortingType){
			case BUBBLE_SORT:
				bubbleSort(aData[M], DATA_SET_SIZE, &aCounters[M]);
				break;
			case SELECTION_SORT:
				selectionSort(aData[M], DATA_SET_SIZE, &aCounters[M]);
					break;
			case INSERTION_SORT:
				insertionSort(aData[M], DATA_SET_SIZE, &aCounters[M]);
					break;
			case MERGE_SORT:
				mergeSort(aData[M], DATA_SET_SIZE, &aCounters[M]);
					break;
			case SORTING_5:
				sort5(aData[M], DATA_SET_SIZE, &aCounters[M]);
					break;
			case SORTING_6:
				sort6(aData[M], DATA_SET_SIZE, &aCounters[M]);
					break;
			default:
				printf("INVALID OPTION. TERMINATING...");
				return 999999999;
		}
		


		aTimeLogs[M][1] = getTime();	//LOG END TIME
		aSortingTime[M] = getElapsed(aTimeLogs[M][0], aTimeLogs[M][1]);

		//SHOW RESULTS
		printData(aData[M], DATA_SET_SIZE);
		printf("[TIME]: %f   [COUNTER]: %f\n", aSortingTime[M], aCounters[M]);
		printf("-------------------------------------------");
	}

	//CALCULATE AVERAGE TIME
	printf("\n\n===========================================\n");
	double avgTime = calcAverage(aSortingTime, ALGORITHM_RUNS);
	double avgCount = calcAverage(aCounters, ALGORITHM_RUNS);

	printf("AVERAGE TIME FOR %d RUNS:          %f\n", M, avgTime);
	printf("AVERAGE COUNTER VALUE FOR %d RUNS: %f\n", M, avgCount);

	recordCSV(avgTime, avgCount);
}