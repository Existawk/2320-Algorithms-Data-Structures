// Dalio, Brian A.
// dalioba
// 2020-07-03

//----------------------------------------------------------
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "heapsort.h"

#define ASCENDING   (0)
#define DESCENDING  (1)
#define SHUFFLE     (2)

static inline void exchangeInt( int *a, int *b ) { int c = *a; *a = *b; *b = c; }

//----------------------------------------------------------
int  checkArray( int *A, int n );
void fillArray( int *A, int n, int order );

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
    fprintf( stderr, "Usage: %s <size>\n", argv[0] );
    exit( 1 );
  }

  int size;

  sscanf( argv[1], "%d", &size );

  //--------------------------------------
  // Allocate space for the numbers.
  int *A = (int *) malloc( sizeof( int ) * size );
  if ( A == NULL ) {
    fprintf( stderr, "%s: unable to allocate %d int%s.\n",
      argv[0], size, size == 1 ? "" : "s" );

    return 1;
  }

  //--------------------------------------
  // Fill the array with 0 .. size-1 in ascending order.
  fillArray( A, size, ASCENDING );

  // Time a run ...
  clock_t  begin = clock();
  long int exchanges = heapsort( A, size );
  clock_t  end   = clock();

  double elapsed = (double) ( end - begin ) / CLOCKS_PER_SEC;
  int numErrs = checkArray( A, size );

  printf( "heapsort( ascending,  %'13d ) => %'5d err%s, %'26ld exchange%s, %'11.3fs\n",
    size,
    numErrs, numErrs == 1 ? "" : "s",
    exchanges, exchanges == 1 ? "" : "s",
    elapsed );

  //--------------------------------------
  // Fill the array with 0 .. size-1 and then
  // shuffle the elements around.
  fillArray( A, size, SHUFFLE );

  // Time a run ...
  begin = clock();
  exchanges = heapsort( A, size );
  end   = clock();

  elapsed = (double) ( end - begin ) / CLOCKS_PER_SEC;
  numErrs = checkArray( A, size );

  printf( "heapsort( shuffle,    %'13d ) => %'5d err%s, %'26ld exchange%s, %'11.3fs\n",
    size,
    numErrs, numErrs == 1 ? "" : "s",
    exchanges, exchanges == 1 ? "" : "s",
    elapsed );

  //--------------------------------------
  // Fill the array with 0 .. size-1 in descending order.
  fillArray( A, size, DESCENDING );

  // Time a run ...
  begin = clock();
  exchanges = heapsort( A, size );
  end   = clock();

  elapsed = (double) ( end - begin ) / CLOCKS_PER_SEC;
  numErrs = checkArray( A, size );

  printf( "heapsort( descending, %'13d ) => %'5d err%s, %'26ld exchange%s, %'11.3fs\n",
    size,
    numErrs, numErrs == 1 ? "" : "s",
    exchanges, exchanges == 1 ? "" : "s",
    elapsed );

  //--------------------------------------
  // Free our allocated array ...
  free( A );

  // ... and exit with no error.  Hurray!
  return 0;
}

//----------------------------------------------------------
int checkArray( int *A, int n )
{
  int errs = 0;
  int tooManyErrs = 0;

  for ( int i = 0; i < n-1; i++ ) {
    if ( A[i] >= A[i+1] ) {
      if ( ++errs > 5 ) {
        if ( !tooManyErrs ) {
          tooManyErrs = 1;
          printf( "  ...\n" );
        }
      } else {
        printf( "Oops: A[%'d] >= A[%'d] : %'d >= %'d\n", i, i+1, A[i], A[i+1] );
      }
    }
  }

  return errs;
}

//----------------------------------------------------------
void fillArray( int *A, int n, int order )
{
  if ( DESCENDING == order ) {
    for ( int i=0; i < n; i++ ) {
      A[ i ] = n-i;
    }
  } else {
    for ( int i=0; i < n; i++ ) {
      A[ i ] = i;
    }

    if ( order == SHUFFLE ) {
      for ( int i=n-1; i > 0; i-- ) {
        int j = drand48()*(i+1);
        exchangeInt( &A[i], &A[j] );
      }
    }
  }
}
//----------------------------------------------------------
