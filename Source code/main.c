/****************************************************
Group: 		GROUP 7
Section:	S11
Members:	JACINTO, ONG
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
#include "csvGenerator.h"		//CUSTOM HEADER

//gcc -Wall -o main main.c && main
int main() {
	//VARIABLES
	char a_AlgoNames[ALGORITHM_TYPES][20] = {"BUBBLE SORT", "SELECTION SORT", "INSERTION SORT", "MERGE SORT", "QUICK SORT", "STUPID GNOME SORT"};
	struct timespec s_StartTime;
	//Could just increment time/counter then average it, but store in case needed
	double a_Counters[ALGORITHM_RUNS], a_SortingTime[ALGORITHM_RUNS], d_AverageCount, d_AverageTime;
	int a_MainData[DATA_SET_SIZE], a_CopyData[DATA_SET_SIZE];
	

	enum settings_runToggle run_Mode = MCO1_OUTPUT_MODE;//DEBUG_MODE;
	//STARTUP
	srand(time(NULL));
	if (WIPE_CSV_DATA)
		resetCSV();
	
	//ALGO DEBUGGER. DOESN'T STORE NOR CALC AVERAGE TIME DATA
	if(run_Mode == DEBUG_MODE)
	{
		int nSortingType;
		
		chooseSortingType(&nSortingType);
		int aData[ALGORITHM_RUNS][DATA_SET_SIZE];

		int M;
		for (M = 0; M < ALGORITHM_RUNS; M++){	//REPEAT FOR NUMBER OF ALGORITHM RUNS
			printf("\nRUN #%d STARTING DATA:\n", M);
			generateData(aData[M], DATA_SET_SIZE);
			printData(aData[M], DATA_SET_SIZE);

			
			//ALGORITHM SORTING.
			s_StartTime = getTime();	//LOG START TIME
			a_Counters[M] = 0;

			//CALL THE ALGORITHM
			switch (nSortingType){
				case BUBBLE_SORT:
					bubbleSort(aData[M], DATA_SET_SIZE, &a_Counters[M]);
					break;
				case SELECTION_SORT:
					selectionSort(aData[M], DATA_SET_SIZE, &a_Counters[M]);
						break;
				case INSERTION_SORT:
					insertionSort(aData[M], DATA_SET_SIZE, &a_Counters[M]);
						break;
				case MERGE_SORT:
					mergeSort(aData[M], DATA_SET_SIZE, &a_Counters[M]);
						break;
				case QUICK_SORT:
					sort5(aData[M], DATA_SET_SIZE, &a_Counters[M]);
						break;
				case STUPID_SORT:
					sort6(aData[M], DATA_SET_SIZE, &a_Counters[M]);
						break;
				default:
					printf("INVALID OPTION. TERMINATING...");
					return 999999999;
			}
			
			//SHOW RESULTS
			printData(aData[M], DATA_SET_SIZE);
			printf("[TIME]: %f   [COUNTER]: %f\n", getElapsed(s_StartTime, getTime()), a_Counters[M]);
			printf("-------------------------------------------");
		}
	}
	

	//ACTUAL MCO1 OUTPUT CSV PRINTER
	if(run_Mode == MCO1_OUTPUT_MODE)
	{
		int n_AlgoType, n_RunCounter;

		//CREATE DATA ALL WILL USE
		generateData(a_MainData, DATA_SET_SIZE);
		printf("-- N : %d --\n\n", DATA_SET_SIZE);

		//RUN THROUGH ALL 6 ALGOS USING THE SAME STARTING DATA
		for (n_AlgoType = 0; n_AlgoType < ALGORITHM_TYPES; n_AlgoType++){
			//REPEAT FOR ALGORITHM_RUNS TO GET AVERAGE OF SPECIFIC ALGO TYPE 
			for (n_RunCounter = 0; n_RunCounter < ALGORITHM_RUNS; n_RunCounter++){
				//COPY DATA
				copyArray(a_MainData, a_CopyData, DATA_SET_SIZE);

				//START TIME & REFRESH COUNTER FROM PREVIOUS ALGO TYPE
				s_StartTime = getTime();
				a_Counters[n_RunCounter] = 0;

				//CALL THE SORT ALGORITHMS
				switch(n_AlgoType){
					case BUBBLE_SORT:
						bubbleSort(a_CopyData, DATA_SET_SIZE, &a_Counters[n_RunCounter]);
						break;
					case SELECTION_SORT:
						selectionSort(a_CopyData, DATA_SET_SIZE, &a_Counters[n_RunCounter]);
						break;
					case INSERTION_SORT:
						insertionSort(a_CopyData, DATA_SET_SIZE, &a_Counters[n_RunCounter]);
						break;
					case MERGE_SORT:
						mergeSort(a_CopyData, DATA_SET_SIZE, &a_Counters[n_RunCounter]);
						break;
					case QUICK_SORT:
						sort5(a_CopyData, DATA_SET_SIZE, &a_Counters[n_RunCounter]);
						break;
					case STUPID_SORT:
						sort6(a_CopyData, DATA_SET_SIZE, &a_Counters[n_RunCounter]);
						break;
					default:
						printf("[ERROR]: ALGORITHM OUT OF SCOPE\n");
				}
				//CALC RUN TIME
				a_SortingTime[n_RunCounter] = getElapsed(s_StartTime, getTime()) * 1000; //Seconds to milliseconds
			}
			//CALC AVERAGE FOR AMOUNT OF RUNS
			d_AverageTime = calcAverage(a_SortingTime, ALGORITHM_RUNS);
			d_AverageCount = calcAverage(a_Counters, ALGORITHM_RUNS);

			//RECORD RESULTS
			printf("\n%s\n", a_AlgoNames[n_AlgoType]);
			printf("AVERAGE MET: "); printf(COLOR_RED); printf("%f ", d_AverageTime); printf(COLOR_RESET);
			printf("milliseconds\nAVERAGE COUNTER VALUE: "); printf(COLOR_RED); printf("%f\n", d_AverageCount); printf(COLOR_RESET);
			recordCSV(DATA_SET_SIZE, a_AlgoNames[n_AlgoType], d_AverageTime, d_AverageCount);
		}
	}
}
