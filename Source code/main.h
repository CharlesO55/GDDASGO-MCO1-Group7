#ifndef MAIN_HEADER
#define MAIN_HEADER

#define COLOR_RED   "\033[0;31m"
#define COLOR_RESET "\033[0m"

#define WIPE_CSV_DATA 0


#define ALGORITHM_TYPES 6
#define ALGORITHM_RUNS 10   //MIN IS 10


//SETTINGS
enum settings_runToggle{DEBUG_MODE, MCO1_OUTPUT_MODE};
enum settings_dataSet{DATA_SET_SIZE = 1024*10, MIN_DATA_RANGE_VALUE = 1, MAX_DATA_RANGE_VALUE = 99};
enum sortingAlgorithms{BUBBLE_SORT = 0, SELECTION_SORT, INSERTION_SORT, MERGE_SORT, QUICK_SORT, STUPID_SORT};


/*
	Swaps the value stored in 2 integer pointers.
	@param int* p1 			Integer pointer 1
	@param int* p2 			Integer pointer 2
*/
void swap(int* p1, int* p2){
    int nTemp = *p1;
    *p1 = *p2;
    *p2 = nTemp;
}


/*
	Prints the entire array.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
*/
const void printData(int A[], int n){
    int i;
    printf("ARRAY OF SIZE %d:\n", n);
    for (i=0; i < n; i++){
        printf("%d  ", A[i]);
    }
    printf("[END]\n");
}


/*
	Returns the average.

	@param double input[] 	Array to be averaged
	@param int n			size of the array to be used in average
*/
double calcAverage(double input[], int n){
    double total = 0;
	int i;
	for (i = 0; i < n; i++){
		total += input[i];
    }
    return total / n;
} 


/*
	Get user input for sorting type selection.

	@param int* pChoice 			Choice to update
*/
void chooseSortingType(int* pChoice){
    while(*pChoice < 0 || *pChoice > 5){
        printf("CHOOSE SORTING TYPES: \n");
        printf("0. BUBBLE SORT\n");
        printf("1. SELECTION SORT\n");
        printf("2. INSERTION SORT\n");
        printf("3. MERGE SORT\n");
        printf("4. 5 SORT\n");
        printf("5. 6 SORT\n");
        scanf(" %d", pChoice);
    }
}


/*
    Copies contents of an array of size n

    @param a_Source     Array to copy from
    @param a_Output     Array to alter
    @param n            size of array
*/
void copyArray(int a_Source[], int a_Output[], int n){
    int i;
    for (i = 0; i < n; i++){
        a_Output[i] = a_Source[i];
    }
}


#endif