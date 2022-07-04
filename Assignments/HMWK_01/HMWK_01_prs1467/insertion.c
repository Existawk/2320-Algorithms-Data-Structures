// Skinner, Parker R.
// prs1467
// 2020-06-19

//----------------------------------------------------------
#include "insertion.h"

//---------------------------------------------------------

extern long int insertion(int *A, int size){
  int j;
  int i;
  int key;
  long int iters=0;

  for(j=1; j< size; j++){
    key = A[j];
    i = j-1;

    while(i>-1 && A[i]>key){
      A[i+1]=A[i];
      i = i-1;
      iters++;
    }
    A[i+1]=key;
  }
  return iters;
}

// TODO: Put your insertion sort here.
//       Get the definition signature from insertion.h.
//
//       The code follows that we discussed in class.
//       The return value from this routine should be
//         how many times the while loop was entered.
//
//       OK, OK, for those of you who didn't take notes
//         in class, here's the pseudo-code for the sort.
//
//       When you code this in C, don't forget to count
//         the while-loop iterations and to return that
//         count as the value of this function.

/***

INSERTION_SORT( A )

  -- A - array to sort

  for j ← 2 to A.length
    key ← A[ j ]

    i ← j-1

    while i > 0 and A[ i ] > key
      A[ i+1 ] ← A[ i ]

      i ← i-1

    A[ i+1 ] ← key

***/

//----------------------------------------------------------
