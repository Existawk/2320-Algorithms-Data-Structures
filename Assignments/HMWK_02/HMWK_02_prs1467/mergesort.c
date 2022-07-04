// Skinner, Parker R.
// prs1467
// 2020-06-26

//----------------------------------------------------------
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "mergesort.h"

static void merge( int *A, int low, int mid, int high );

//----------------------------------------------------------

long int mergesort(int *A, int low, int high){
  int mid;
  long int iters=0;
  long int a;
  long int b;
  iters++;

  if (low<high){
    mid=(high+low)/2;

    a=mergesort(A, low, mid);
    b=mergesort(A, mid+1, high);

    iters=iters+a+b;

    merge(A, low, mid, high);
  }
  return iters;
}

// TODO: Put your mergesort routine here.  (merge() goes below.)
//       Get the definition signature from mergesort.h.
//
//       The code follows that we discussed in class.
//
//       The return value from this routine should be how many
//         times mergesort() was entered.  Count 1 on entry and
//         add into that the values returned by each recursive
//         call to mergesort().  Use long int!
//
//       When you code this in C, don't forget arrays are 1 .. n
//         in pseudo-code but 0 .. n-1 in C!  (Does that matter
//         here given how mergesort() takes its arguments?  Why
//         or why not?  Think about it.)

// The body of the reference solution mergesort() is eight (8)
//   lines of code (LOC).  You don't need to get EXACTLY that
//   number of LOC, but if you find yourself writing a LOT more
//   than that, you might be going off-track somehow.  Stop and
//   think about it.
//
// That LOC count might even be a bit high as my coding style puts
//   close braces on their own lines, etc., so my code is sometimes
//   a bit longer.

/***

MERGE_SORT( A, low, high )

  -- A    - array to sort
  -- low  - lowest index in A to consider
  -- high - highest index in A to consider

  if low < high
    mid ← ⌊ ( high + low ) / 2 ⌋

    MERGE_SORT( A, low, mid )
    MERGE_SORT( A, mid+1, high )

    MERGE( A, low, mid, high )

***/

static void merge( int *A, int low, int mid, int high ){
  int szL;
  int szR;
  int i;
  int j;
  int k;

  szL=mid-low+1;
  szR=high-mid;

  int *L = (int *) malloc( sizeof( int ) * (szL+1) );
  if ( L == NULL ) {
    fprintf( stderr,"%s: unable to allocate %d int%s.\n",
      "merge L", szL+1, szL+1 == 1 ? "" : "s" );

    exit(0);
  }
  int *R = (int *) malloc( sizeof( int ) * (szR+1) );
  if ( R == NULL ) {
    fprintf( stderr, "%s: unable to allocate %d int%s.\n",
      "merge R", szR+1, szR+1 == 1 ? "" : "s" );

    exit(0);
  }

  for(i=0;i<szL;i++){
    L[i]=A[low+i];
  }
  for(i=0;i<szR;i++){
    R[i]=A[mid+i+1];
  }

  L[szL]=INT_MAX;
  R[szR]=INT_MAX;

  i=0;
  j=0;

  for(k=low;k<high+1;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }

  free(L);
  free(R);
}

//----------------------------------------------------------
// TODO: Put your merge routine here.
//       Get the definition signature from mergesort.h.
//
//       The code follows that we discussed in class.
//
//       This routine has no return value.
//
//       Do NOT try to allocate the L and R arrays on the stack!
//         (I.e., using C's ill-considered VLA "capability".
//         VLAs might have been introduced in C99, but they were
//         retracted in C11 as a "bad idea".)
//
//         The arrays can be incredibly large (hundreds of millions
//         of entries) and that can cause stack overflow.
//
//         Use malloc() / free() to allocate / free L and R.
//
//       When you code this in C, don't forget arrays are 1 .. n
//         in pseudo-code but 0 .. n-1 in C!  (Does that matter
//         here given how merge() takes its arguments?  Why or why
//         not?  Think about it.)

// The body of the reference solution merge() is thirty (30)
//   lines of code (LOC).  You don't need to get EXACTLY that
//   number of LOC, but if you find yourself writing a LOT more
//   than that, you might be going off-track somehow.  Stop and
//   think about it.
//
// That LOC count might even be a bit high as my coding style puts
//   close braces on their own lines, etc., so my code is sometimes
//   a bit longer.

/***

MERGE( A, low, mid, high )

  -- A    - array in which to merge
  -- low  - lowest index in A to consider
  -- mid  - division between halves to merge
  -- high - highest index in A to consider

  szL ← mid - low + 1
  szR ← high - mid

  L ← new [ 1 .. szL+1 ] array
  R ← new [ 1 .. szR+1 ] array

  for i ← 1 to szL
    L[ i ] ← A[ low+i-1 ]

  for i ← 1 to szR
    R[ i ] ← A[ mid+i ]

  L[ szL+1 ] ← ∞
  R[ szR+1 ] ← ∞

  i ← 1
  j ← 1

  for k ← low to high
    if L[ i ] ≤ R[ j ]
      A[ k ] ← L[ i ]
      i ← i+1

    else
      A[ k ] ← R[ j ]
      j ← j+1

***/

//----------------------------------------------------------
