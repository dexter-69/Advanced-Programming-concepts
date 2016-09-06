#include <stdio.h>

int main ( int argc, char *argv[] ) {
    int sum = 0, i, num;

	if( argc < 2 ) {
        printf ( "No arguments provided.\n" );
		return 0;
	}

    for ( i = 1; i < argc; i++ ) {
        sscanf ( argv[i], "%d", &num );		// Convert string to number
        sum += num;
    }

    printf ( "Sum of provided numbers: %d\n", sum );
    return 0;
}
