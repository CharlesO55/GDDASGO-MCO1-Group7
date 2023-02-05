/****************************************************
REFERENCE

Author:
Link:
****************************************************/


/* 
	You may declare additional functions here
*/
void merge(int A[], int n, int middle, int rightSize){
	int aLeft[middle+1], aRight[rightSize];

	int i;
	for (i = 0; i <= middle; i++){
		aLeft[i] = A[i];		//Copy the left half into a temp arr
	}

	int j;
	for (j = 0; j < rightSize; j++){
		aRight[j] = A[j + middle+1];		//Copy the right half into a temp arr
	}
	
	int k = 0;
	while(i >= 0){
		A[k] = aLeft[i-1];
		k++;
		i--;
	}/*
	while(j >= 0){
		A[k] = aRight[j];
		k++;
		j--;
	}*/

	printf("\nMERGED OUTPUT: "); printData(A, n);
}

/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using merge sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void mergeSort(int A[], int n, double *dCounter) {
	//Arr can still be splitted
	if (n > 1){
		int middle = (n-1)/2;	//Middle index (i.e. n = 5 -> m = 2 ; n = 4 - > m = 2)


		printf("\nPROCESSING THIS:\n");
		printData(A, n);
		
		printf("SPLITTING LEFT\n");
		mergeSort(A+0, middle+1, dCounter);			//Split and sort left half
		

		int size = n - middle - 1;
		if(n % 2){
			size--;
		}
		printf("SPLITTING RIGHT\n");
		mergeSort(A+middle+1, size, dCounter);		//Split and sort right half
		merge(A, n, middle, size);
	}


}
