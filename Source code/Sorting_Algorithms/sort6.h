/****************************************************
REFERENCE

Author: geeksforgeeks
Link:	https://www.geeksforgeeks.org/gnome-sort-a-stupid-one/
****************************************************/


/* 
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using stupid sort sorting algorithm.
	Move a pointer from first to the last index
	Check if the pointer element is less than that before it, and swap if so. 
	Then check the same lower element to see if the element before is lower once more.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void sort6(int A[], int n, double *dCounter) {
	//Stupid sort/Gnome sort

	int i = 0;
	while (i < n){	//Move the pointer from left to rightmost
		*dCounter += 1;
		if(i == 0)	//Nothing to compare. Just move pointer forward
			i++;

		*dCounter += 1;
		if(A[i] < A[i-1]){	//If element before is greater, swap the two. Move pointer back to check as well
			swap(&A[i], &A[i-1]);
			i--;
		}
		else{		//Move pointer forward if already sorted
			i++;
		}
	}
}
