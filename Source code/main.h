#ifndef MAIN_HEADER
#define MAIN_HEADER

#define BUBBLE_SORT 1
#define SELECTION_SORT 2
#define INSERTION_SORT 3
#define MERGE_SORT 4
#define SORTING_5 5
#define SORTING_6 6


//EDITABLE
#define DATA_SET_SIZE 6
#define MIN_DATA_RANGE_VALUE 1
#define MAX_DATA_RANGE_VALUE 20
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
#endif