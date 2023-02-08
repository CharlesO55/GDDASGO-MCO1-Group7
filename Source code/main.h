#ifndef MAIN_HEADER
#define MAIN_HEADER

#define BUBBLE_SORT     0
#define SELECTION_SORT  1
#define INSERTION_SORT  2
#define MERGE_SORT      3
#define SORTING_5       4
#define SORTING_6       5

#define COLOR_RED   "\033[0;31m"
#define COLOR_RESET "\033[0m"

#define WIPE_CSV_DATA 0

//EDITABLE
#define DATA_SET_SIZE 1024*100
#define MIN_DATA_RANGE_VALUE 1
#define MAX_DATA_RANGE_VALUE 20

#define ALGORITHM_TYPES 6
#define ALGORITHM_RUNS 10   //MIN IS 10


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
    while(*pChoice < 1 || *pChoice > 6){
        printf("CHOOSE SORTING TYPES: \n");
        printf("1. BUBBLE SORT\n");
        printf("2. SELECTION SORT\n");
        printf("3. INSERTION SORT\n");
        printf("4. MERGE SORT\n");
        printf("5. 5 SORT\n");
        printf("6. 6 SORT\n");
        scanf(" %d", pChoice);
    }
}


/*
    Copies contents of an array of size n
*/
void copyArray(int a_Source[], int a_Output[], int n){
    int i;
    for (i = 0; i < n; i++){
        a_Output[i] = a_Source[i];
    }
}


#endif