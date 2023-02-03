/****************************************************
REFERENCE

Author:
Link:
****************************************************/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


#include <stdlib.h> 
#include <time.h> 



void generateData (int A[], int n) {   
    int i;
    for (i=0; i<n; i++){
        A[i] = MIN_DATA_RANGE_VALUE + rand() % (MAX_DATA_RANGE_VALUE - MIN_DATA_RANGE_VALUE + 1);
    }
}