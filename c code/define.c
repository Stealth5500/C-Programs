#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))

int main() {
    printf("Value of PI: %f\n", PI);
    printf("Square of 5: %d\n", SQUARE(5));
    return 0;
}

#endif // MY_HEADER_H