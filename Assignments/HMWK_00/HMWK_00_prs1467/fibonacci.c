// Skinner, Parker R.
// prs1467
// 2020-06-12

//----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

long int numFibonacciCalls;

extern long int fibonacci( int n ){
  numFibonacciCalls=numFibonacciCalls+1;

  if(n<=0){
    return 0;
  }

  else if(n==1){
    return 1;
  }

  else{
    return fibonacci( n-1 ) + fibonacci( n-2);
  }

}
//----------------------------------------------------------
// TODO : Definition of numFibonacciCalls.

// TODO : Definion of fibonacci().
//        - Increment numFibonacciCalls on entry.
//        - n <= 0, return 0.
//        - n == 1, return 1.
//        - Otherwise return fibonacci( n-1 ) + fibonacci( n-2)

//----------------------------------------------------------
