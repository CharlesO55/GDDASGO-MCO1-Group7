/****************************************************
REFERENCE

Author:
Link:
****************************************************/


/* 
	You may declare additional functions here
*/
void merge(int A[], int n, int n_middleIndex, double *dCounter){
	int n_indexMain = 0, n_indexL = 0, n_indexR = 0;
	int a_tempL[n_middleIndex+1], a_tempR[n - (n_middleIndex+1)];
	*dCounter += 1;

	//Copy stuff into temp arrays
	for (n_indexL = 0; n_indexL <= n_middleIndex; n_indexL++){
		a_tempL[n_indexL] = A[n_indexMain];
		n_indexMain++;
		*dCounter += 1;
	}
	for (n_indexR = 0; n_indexMain < n; n_indexR++){
		a_tempR[n_indexR] = A[n_indexMain];
		n_indexMain++;
		*dCounter += 1;
	}

	//Reset pos
	int n1 = n_indexL - 1;
	int n2 = n_indexR - 1;
	n_indexL = 0;
	n_indexR = 0;
	n_indexMain = 0;
	*dCounter += 1;


	while (n_indexL <= n1 && n_indexR <= n2){
		//Add left to list when smaller
		if (a_tempL[n_indexL] <= a_tempR[n_indexR]){
			A[n_indexMain] = a_tempL[n_indexL];
			n_indexL++;
		}
		//Or add right to list when smaller
		else{
			A[n_indexMain] = a_tempR[n_indexR];
			n_indexR++;
		}
		n_indexMain++;
		*dCounter += 1;
	}


	//Dump remaining data
	while (n_indexL <= n1){
		A[n_indexMain] = a_tempL[n_indexL];
		n_indexL++;
		n_indexMain++;
		*dCounter += 1;
	}
	while (n_indexR <= n2){
		A[n_indexMain] = a_tempR[n_indexR];
		n_indexR++;
		n_indexMain++;
		*dCounter += 1;
	}
	return;
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
	if (n <= 1){
		return;
	}

	int n_middleIndex = (n-1)/2;	//Middle index (i.e. n = 6 -> m = 2 ; n = 5 -> m = 2)
	*dCounter += 1;

	//printData(A, n);
	
	mergeSort(A+0, n_middleIndex+1, dCounter);	//Split again left half
	//Only split when there's something on right
	if(n_middleIndex > 0){
		mergeSort(A+(n_middleIndex+1), n - (n_middleIndex+1), dCounter);		//Split again right half
	}
	merge(A, n, n_middleIndex, dCounter);
}