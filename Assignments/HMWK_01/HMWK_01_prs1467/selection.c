// Skinner, Parker R.
// prs1467
// 2020-06-19

//----------------------------------------------------------
#include "selection.h"

static inline void exchangeInt( int *a, int *b ) { int c = *a; *a = *b; *b = c; }

long int selection(int *A, int size){
    int i;
    int j;
    int min;
    long int iters=0;

    for(j=0;j<size-1;j++){
      min=j;

      for(i=j+1;i<size;i++){

        if(A[i]<A[min]){
          min=i;
        }
        iters++;
      }
      exchangeInt(&A[min],&A[j]);
    }
    return iters;
}
//----------------------------------------------------------
// TODO: Put your selection sort here.
//       Get the definition signature from selection.h.
//
//       The code follows that we discussed in class.
//       The return value from this routine should be
//         how many times the inner for loop was entered.
//
//       OK, OK, for those of you who didn't take notes
//         in class, here's the pseudo-code for the sort.
//
//       When you code this in C, don't forget to count
//         the inner-for-loop iterations and to return that
//         count as the value of this function.
//
//       A definition for "exchangeInt()" is given above.
//         Is it clear how that operates?

/***

SELECTION_SORT( A )

  -- A - array to sort

  for j ← 1 to A.length-1
    min ← j

    for i ← j+1 to A.length
      if A[ i ] < A[ min ]
        min ← i

    exchange A[ min ], A[ j ]

***/

//----------------------------------------------------------
