/* FAXPY
 *
 *  a * x + y
 *
 *  a is a scalar, and x and y are vectors of the same size n. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>

void faxpy( int n, float a, float *x, float *y, float *result ) {

    for( int i = 0; i < n; i+=4 ) {
        result[i] = a * x[i] + y[i];
        result[i+1] = a * x[i+1] + y[i+1];

         _mm_storeu_ps(&result[i],
            _mm_add_ps(
                _mm_mul_ps(
                    _mm_set_ps1(a),
                    _mm_loadu_ps(x + i)
                ),
                _mm_loadu_ps(y + i)
            )
        );
    }
}

int main( void ) {
    
    const int N = 2000000;
    printf( "Running FAXPY operation of size %d \n", N );
	float *X = (float *) malloc( N *  sizeof(float) ); // First
	float *Y = (float *) malloc( N *  sizeof(float) ); // Second
	float *result = (float *) malloc( N * sizeof(float) ); // Third

	// Carry out operation
	faxpy( N, 1.0, X, Y, result );

	// Free up the memory
	free( X );
	free( Y );
	free( result );

	return 0;
}
















