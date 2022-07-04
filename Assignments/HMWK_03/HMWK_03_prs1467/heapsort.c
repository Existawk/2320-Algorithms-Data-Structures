// Skinner, Parker
// prs1467
// 2020-07-07

//----------------------------------------------------------
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "heapsort.h"

//----------------------------------------------------------
static int PARENT( int i ) { return (i-1)/2; }
static int LEFT( int i ) { return 2*i + 1; }
static int RIGHT( int i ) { return 2*i + 2; }

//----------------------------------------------------------
static inline void exchangeInt( int *a, int *b ) { int c = *a; *a = *b; *b = c; }

static long int buildMaxHeap( int *A, int heapSize );
static long int maxHeapify( int *A, int heapSize, int i );

//----------------------------------------------------------

long int heapsort(int *A, int length){
  int i;
  long int iters=0;

  int heapSize=length-1;

  iters+=buildMaxHeap(A,heapSize);

  for(i=length-1; i>0; i--){
    exchangeInt(&A[0],&A[i]);
    iters++;

    heapSize=heapSize-1;

    iters+=maxHeapify(A,heapSize,0);
  }

  return iters;
}

// TODO: Put your heapsort() routine here.  (buildMaxHeap() and
//       maxHeapify() go below.)  Get the definition signature
//       from heapsort.h.  (You don't need "extern" on a
//       definition!)
//
//       The code follows what we discussed in class.
//
//       The return value from this routine should be how many
//         exchanges were done.  Start the count at 0, add 1 every
//         time you do an exchange here.  Add in the number of
//         exchanges buildMaxHeap() and all the calls to
//         maxHeapify() do.  Use long int!
//
//       When you code this in C, don't forget arrays are 1 .. n
//         in pseudo-code but 0 .. n-1 in C!  This has a definite
//         effect on the limits of the loop, how A is indexed, and
//         how maxHeapify() is called.
//
// The body of the reference solution heapsort() is nine (9)
//   lines of code (LOC).  You don't need to get EXACTLY that
//   number of LOC, but if you find yourself writing a LOT more
//   than that, you might be going off-track somehow.  Stop and
//   think about it.
//
// That LOC count might even be a bit high as my coding style puts
//   close braces on their own lines, etc., so my code is
//   sometimes a bit longer than what others get.

/***

HEAP_SORT( A )

  -- A - array to sort.

  BUILD_MAX_HEAP( A )

  for i ←  A.length downto 2
    exchange A[ 1 ] and A[ i ]

    A.heapsize ← A.heapsize - 1

    MAX_HEAPIFY( A, 1 )

***/
static long int buildMaxHeap( int *A, int heapSize ){
  long int iters=0;
  int i;

  for(i=PARENT(heapSize);i>=0;i--){
    iters+=maxHeapify(A,heapSize,i);
  }
  return iters;
}
//----------------------------------------------------------
// TODO: Put your buildMaxHeap() routine here.  Get the definition
//       signature from the declaration above.
//
//       The code follows what we discussed in class.
//
//       The return value from this routine should be how many
//         exchanges were done.  Start the count at 0.  Add in the
//         number of exchanges each call to maxHeapify() does.
//         Use long int!
//
//       When you code this in C, don't forget arrays are 1 .. n
//         in pseudo-code but 0 .. n-1 in C!  This has a definite
//         effect on the limits of the loop and how maxHeapify()
//         is called.
//
// The body of the reference solution buildMaxHeap() is six (6)
//   lines of code (LOC).  You don't need to get EXACTLY that
//   number of LOC, but if you find yourself writing a LOT more
//   than that, you might be going off-track somehow.  Stop and
//   think about it.
//
// That LOC count might even be a bit high as my coding style puts
//   close braces on their own lines, etc., so my code is
//   sometimes a bit longer than what others get.

/***

BUILD_MAX_HEAP( A )

  -- A - array to convert to  heap arrangement.

  A.heapsize ← A.length

  for i ←  PARENT( A.length ) downto 1
    MAX_HEAPIFY( A, i )

***/
static long int maxHeapify( int *A, int heapSize, int i ){
  long int iters=0;
  int ell;
  int arr;
  int largest;

  ell=LEFT(i);
  arr=RIGHT(i);

  if(ell<=heapSize&&A[ell]>A[i]){
    largest=ell;
  }
  else{
    largest=i;
  }

  if(arr<=heapSize&&A[arr]>A[largest]){
    largest=arr;
  }
  if(largest!=i){
    exchangeInt(&A[i],&A[largest]);
    iters+=maxHeapify(A,heapSize,largest);
    iters++;
  }
  return iters;
}
//----------------------------------------------------------
// TODO: Put your maxHeapify() routine here.  Get the definition
//       signature from the declaration above.
//
//       The code follows what we discussed in class.
//
//       The return value from this routine should be how many
//         exchanges were done.  Start the count at 0.  Add 1 each
//         time you do an exchange here.  Also add in the number
//         of exchanges done by the recursive call to maxHeapify().
//         Use long int!
//
//       When you code this in C, don't forget arrays are 1 .. n
//         in pseudo-code but 0 .. n-1 in C!  This has a definite
//         effect on the comparisons to heapsize.
//
// The body of the reference solution maxHeapify() is sixteen (16)
//   lines of code (LOC).  You don't need to get EXACTLY that
//   number of LOC, but if you find yourself writing a LOT more
//   than that, you might be going off-track somehow.  Stop and
//   think about it.
//
// That LOC count might even be a bit high as my coding style puts
//   close braces on their own lines, etc., so my code is
//   sometimes a bit longer than what others get.

/***

MAX_HEAPIFY( A, i )

  -- A - array to heapify.
  -- i - start position to enforce heap property

  ell ← LEFT( i )
  arr ← RIGHT( i )

  if ell <= A.heapsize and A[ ell ] > A[ i ]
    largest ← ell

  else
    largest ← i

  if arr <= A.heapsize and A[ arr ] > A[ largest ]
    largest ← arr

  if largest <> i
    exchange A[ i ] and A[ largest ]
    MAX_HEAPIFY( A, largest )

***/

//----------------------------------------------------------
