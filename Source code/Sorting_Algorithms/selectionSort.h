/****************************************************
REFERENCE

Author: Cormen, T.H., Leiserson, C.E., Rivest, R.L., & Stein, C. (2009). 
		Introduction to Algorithms, 3rd ed. 
		Cambridge, Massachusetts: The MIT Press.
Link: Solution to Exercise 2.2-2
****************************************************/


/* 
	You may declare additional functions here
*/

/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using selection sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void selectionSort(int A[], int n, double *dCounter) {
	//BOOK VER.
	/*{
		int i, j, nSmallest;
		
			//loop to access each element in the array until it gets to the 2nd to the last value
			//does not have to loop for the last value since those 2 values are arranged together
		for (i = 0; i < n; i++){
			//assigns the first value of the unsorted group as the potential smallest number
			nSmallest = i;

			//loop to access each element in the unsorted group until it gets to the end of the array 
			for (j = i + 1; j < n; j++){
				//if condition where nSmallest is replaced by the current number if it's less than nSmallest
				if (A[j] < A[nSmallest])
					nSmallest = j;
			}
			swap(&A[i], &A[nSmallest]);
		}
	}*/
	
	//CO VER.
	{
		int slot, pointer, smallest;
		//SCAN THROUGH ALL PROCEEDING THE SLOT AND FIND THE SMALLEST, THEN SWAP 
		for (slot = 0; slot < n - 1; slot++){		//Move slot from left to rightmost-1
			smallest = slot;						//Reset the smallest pointer to match slot position
			for (pointer = slot + 1; pointer <= n-1; pointer++){	//Move pointer from next to slot towards rightmost
				*dCounter += 1;
				if (A[pointer] < A[smallest])
					smallest = pointer;	//Note the smallest's index
			}
			if (smallest != slot){
				swap(&A[slot], &A[smallest]);
				*dCounter += 1;
			}
			//Ignore if already smallest
		}
	}
}
