// Skinner, Parker R.
// prs1467
// 2020-06-26

//----------------------------------------------------------
#include "quicksort.h"

static inline void exchangeInt( int *a, int *b ) { int c = *a; *a = *b; *b = c; }

static int partition( int *A, int low, int high );

//----------------------------------------------------------

long int quicksort( int *A, int low, int high ){
  int p;
  long int iters=0;
  long int a;
  long int b;
  iters++;

  if(low<high){
    p=partition(A,low,high);

    a=quicksort(A,low,p-1);
    b=quicksort(A,p+1,high);

    iters=a+b+iters;
  }
  return iters;
}

// TODO: Put your quicksort routine here.  (partition() goes below.)
//       Get the definition signature from quicksort.h.
//
//       The code follows that we discussed in class.
//
//       The return value from this routine should be how many
//         times quicksort() was entered.  Count 1 on entry and
//         add into that the values returned by each recursive
//         call to quicksort().  Use long int!
//
//       When you code this in C, don't forget arrays are 1 .. n
//         in pseudo-code but 0 .. n-1 in C!  (Does that matter
//         here given how quicksort() takes its arguments?  Why
//         or why not?  Think about it.)

// The body of the reference solution quicksort() is seven (7)
//   lines of code (LOC).  You don't need to get EXACTLY that
//   number of LOC, but if you find yourself writing a LOT more
//   than that, you might be going off-track somehow.  Stop and
//   think about it.
//
// That LOC count might even be a bit high as my coding style puts
//   close braces on their own lines, etc., so my code is sometimes
//   a bit longer.

/***

QUICKSORT( A, low, high )

-- A    - Array to sort
-- low  - lowest index in A to consider
-- high - highest index in A to consider

  if low < high
    p ← PARTITION( A, low, high )

    QUICKSORT( A, low, p-1 )
    QUICKSORT( A, p+1, high )

***/

static int partition( int *A, int low, int high ){
  int pivot;
  int i;
  int j;
  int mid;

  mid=(high+low)/2;

  if((A[mid]>=A[low]&&A[low]>=A[high])||(A[mid]<=A[low]&&A[low]<=A[high])){
    exchangeInt(&A[low],&A[high]);
  }
  else if((A[low]>=A[mid]&&A[mid]>=A[high])||(A[low]<=A[mid]&&A[mid]<=A[high])){
    exchangeInt(&A[mid],&A[high]);
  }

  pivot=A[high];

  i=low-1;

  for(j=low;j<high;j++){
    if (A[j]<pivot){
      i++;
      exchangeInt(&A[i],&A[j]);
    }
  }

  exchangeInt(&A[i+1],&A[high]);

  return i+1;
}

//----------------------------------------------------------
// TODO: Put your partition routine here.
//       Get the definition signature from quicksort.h.
//
//       The code follows that we discussed in class, using the
//         median-of-three approach to pick the pivot value.  The
//         pseudo-code shown is Hoare's ORIGINAL definition of
//         partition, which DOESN'T use median-of-three.  Your
//         implementation SHOULD USE median-of-three.
//
//       This routine return the index of the pivot point.
//
//       When you code this in C, don't forget arrays are 1 .. n
//         in pseudo-code but 0 .. n-1 in C!  (Does that matter
//         here given how partition() takes its arguments?  Why or
//         why not?  Think about it.)

// The body of the reference solution partition() is sixteen (16)
//   lines of code (LOC).  You don't need to get EXACTLY that
//   number of LOC, but if you find yourself writing a LOT more
//   than that, you might be going off-track somehow.  Stop and
//   think about it.
//
// That LOC count might even be a bit high as my coding style puts
//   close braces on their own lines, etc., so my code is sometimes
//   a bit longer.

/***

PARTITION( A, low, high )

  -- A    - array in which to partition
  -- low  - lowest index in A to consider
  -- high - highest index in A to consider

  pivot ← A[ high ]

  i ← low-1

  for j ← low to high-1
    if A[ j ] < pivot
      i ← i+1
      exchange A[ i ], A[ j ]

  exchange A[ i+1 ], A[ high ]

  return i+1

***/

//----------------------------------------------------------
