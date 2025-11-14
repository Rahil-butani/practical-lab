#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // Display sizes of data types
    printf("RAHIL-25CE011");

    printf("Size of char: %lu byte(s)\n", sizeof(char));
    printf("Size of int: %lu byte(s)\n", sizeof(int));
    printf("Size of float: %lu byte(s)\n", sizeof(float));
    printf("Size of double: %lu byte(s)\n", sizeof(double));
    printf("Size of short: %lu byte(s)\n", sizeof(short));
    printf("Size of long: %lu byte(s)\n", sizeof(long));
    printf("Size of long long: %lu byte(s)\n\n", sizeof(long long));

    // Display ranges of integer types
    printf("Range of char: %d to %d\n", CHAR_MIN, CHAR_MAX);


    printf("Range of short: %d to %d\n", SHRT_MIN, SHRT_MAX);

    printf("Range of int: %d to %d\n", INT_MIN, INT_MAX);

    printf("Range of long: %ld to %ld\n", LONG_MIN, LONG_MAX);


    printf("Range of long long: %lld to %lld\n", LLONG_MIN, LLONG_MAX);

    // Display ranges of floating point types
    printf("Range of float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Range of double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Range of long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);

    return 0;
}
