// Dalio, Brian A.
// dalioba
// 2020-06-10

//----------------------------------------------------------
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fibonacci.h"

//----------------------------------------------------------
int main( int argc, char *argv[] )
{
  // No buffering of output.
  setbuf( stdout, NULL );
  setbuf( stderr, NULL );

  // Enable thousand separators in printf().
  setlocale( LC_NUMERIC, "" );

  //--------------------------------------
  // Get argument ...
  if ( argc != 2 ) {
    fprintf( stderr, "Usage: %s <n>\n", argv[0] );
    exit( 1 );
  }

  int n;

  sscanf( argv[1], "%d", &n );

  //--------------------------------------
  // Time a run ...
  clock_t  begin;
  clock_t  end;
  double   elapsed;

  long int result;

  numFibonacciCalls = 0L;

  begin  = clock();
  result = fibonacci( n );
  end    = clock();

  elapsed = (double) ( end - begin ) / CLOCKS_PER_SEC;

  printf( "fibonacci( %'2d ) => %'14ld, %'14ld call%s, %'9.3fs\n",
    n, result,
    numFibonacciCalls, numFibonacciCalls == 1 ? "" : "s",
    elapsed );

    return 0;
}

//----------------------------------------------------------
