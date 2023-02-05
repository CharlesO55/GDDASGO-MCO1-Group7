/****************************************************
REFERENCE

Author:	geeksforgeeks
Link:	https://www.geeksforgeeks.org/quick-sort/
****************************************************/


/* 
	Moves pointers i and j across to swap values depending on their value compared to the pivot, before lastly swapping the pivot.
	A[i], A[i-1], A[i-x] will contain values lower than the pivot
	A[i+1] will contain the pivot
	A[i+2], A[i+x] contains values greater than the pivot

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code

	@return i+1				index of the pivot value
*/
int partition(int A[], int n, double* dCounter){
	int pivot = A[n-1];	//Last element as pivot
	int i = -1;
	int j;

	//MOVE 2 POINTERS ACROSS. i will always be behind j
	for (j = 0; j < n-1; j++){	//j scans all the values from left to right excluding the pivot
		if(A[j] < pivot){		//i marks the index of the last lower value inserted
			i++;					//move the i pointer up
			swap(&A[i], &A[j]);		//Swap values of i and j
		}
	}

	//PUT THE PIVOT TO ITS PLACE. AFTER THE LAST SMALLER VALUE
	swap(&A[i+1], &A[n-1]);
	return i+1;
}

/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using <fill this> sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void sort5(int A[], int n, double *dCounter) {
	//Quicksort
	if (n > 1){
		int partitioningIndex = partition(A, n, dCounter);	//The index of the pivot

		//printf("RECEIVED...   "); printData(A, n);
		sort5(A + 0, partitioningIndex, dCounter);								//Sort everything to the left of the pivot index
		sort5(A + partitioningIndex + 1, n - partitioningIndex - 1, dCounter);	//Sort everything to the right of the pivot index
	}
}
