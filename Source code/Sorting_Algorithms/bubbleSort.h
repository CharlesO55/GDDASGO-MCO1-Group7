/****************************************************
REFERENCE

Author: Cormen, T.H., Leiserson, C.E., Rivest, R.L., & Stein, C. (2009). 
		Introduction to Algorithms, 3rd ed. 
		Cambridge, Massachusetts: The MIT Press.
Link: Page 40
****************************************************/

/* 
	You may declare additional functions here
*/

/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using bubble sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void bubbleSort(int A[], int n, double *dCounter) {
	//BOOK VER.
	/*{
		int i, j;
		//for i = 1 to A.length - 1
		//	for j = A.length down to i + 1
		//		if A[j] < A[j-1]
		//			exchange A[j] with A[j - 1]
		
		for (i = 0; i < n; i++){
			for (j = n - 1; j >= i + 1; j--){
				if (A[j] < A[j-1])
					swap(&A[j], &A[j-1]);
			}
		}
	}*/

	//CO VER.
	{
		int slot, pointer;
		for (slot = 0; slot < n - 1; slot++){							//SLOT goes from left to rightmost - 1
			for (pointer = n - 1; pointer > slot; pointer--){			//POINTER goes from rightmost towards SLOT+1
				if(A[pointer] < A[slot])	//When the pointer value is lower than the slot value, swap
					swap(&A[slot], &A[pointer]);

				//printData(A, n);	//To see per calc results
			}
		}
	}
}