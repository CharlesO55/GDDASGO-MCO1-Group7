/****************************************************
REFERENCE

Author:
Link:
****************************************************/


/* 
	You may declare additional functions here
*/
void merge(int A[], int n, int middle, int n2){
	
	int n1 = middle+1;				//size of left array
	int aLeft[n1], aRight[n2];		//temporary arrays to copy to

	int indexL, indexR;
	for (indexL = 0; indexL < middle; indexL++){
		aLeft[indexL] = A[indexL];		//Copy the left half into a temp arr
	}
/*
	for (indexR = 0; indexR < rightSize; indexR++){
		aRight[indexR] = A[indexR + middle+1];		//Copy the right half into a temp arr
	}*/
	
	int index = 0;
	indexL = 0;
	indexR = 0;
	while(indexL < n1 || indexR < n2){
		if(aLeft[indexL] <= aRight[indexR]){
			A[index] = aLeft[indexL];
			indexL++;
		}
		else{
			A[index] = aRight[indexR];
			indexR++;
		}
		index++;
	}
	
	/*
	int k = 0;
	int i = 0;
	while(i < indexL){	//Take everything from left until everything was copied (reached indexL)
		A[k] = aLeft[i];
		k++;
		i++;
	}
	while(i < indexR){	//Take everythin from right until everything was copied (reached indexR)
		A[k] = aRight[i];
		k++;
		i++;
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
