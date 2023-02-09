/****************************************************
REFERENCE

Author: Cormen, T.H., Leiserson, C.E., Rivest, R.L., & Stein, C. (2009). 
		Introduction to Algorithms, 3rd ed. 
		Cambridge, Massachusetts: The MIT Press.
Link: Page 18, 26
****************************************************/


/* 
	You may declare additional functions here
*/

/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using insertion sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void insertionSort(int A[], int n, double *dCounter) {
	/*{
	//	INSERTION-SORT.A/
	//1 for j = 2 to A.length
	//2 	key = A[j]
	//3 // Insert A[j] into the sorted sequence A[1...j - 1].
	//4 	i = j - 1
	//5 	while i > 0 and A[i] > key
	//6 		A[i + 1] = A[i]
	//7 		i = i - 1
	//8 	A[i + 1] = key
		
		int i, j, stop = 0;

		for(i = 1; i < n; i++) {
			for(j = i; j > 0 && !stop; j--){
				if(A[j] < A[j-1])
					swap(&A[j], &A[j-1]);
				else
					stop = 1;
			}
		}
	}*/

	//CO VER.
	{
		int slot, pointer, key;
		for (slot = 1; slot <= n - 1; slot++){		//Slot goes from left to righmost
			key = slot;				//Record the key to move
			
			for (pointer = slot - 1; pointer >= 0; pointer--){
				*dCounter += 1;
				if (A[pointer] > A[key]){		//Pointer scans to the left of key for a higher value
					swap(&A[key], &A[pointer]);	//Swap to create ascending order
					key--;						//Move the key as well to note it's new index
					*dCounter += 1;
				}
				else{			//When pointer can't find higher value,
					break;		//Stop. Assume that everything to the left is already sorted.
				}
			}
			
			//WHILE LOOP VER.
			//pointer = slot - 1;		//Record the pointer
			/*while (pointer >= 0){
				if (A[pointer] > A[key]){		//Pointer scans to the left of key for a lower value
					swap(&A[key], &A[pointer]);	//Swap when lower
					key--;						//Move the key as well to note it's new index
				}
				else{			//When pointer can't find lower value,
					break;	//Stop. Assume that everything to the left is already sorted.
				}
				pointer--;		//Pointer searches next item
			}*/
		}
	}
}
