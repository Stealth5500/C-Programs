#include <stdio.h>
#include <stdlib.h>

void addvalue5(int *a, int *b, int *c) {
    *a = *a + 5;
    *b = *b + 5;
    *c = *c + 5;
}

int main() {
    int a = 15;
    int b = 15;
    int c = 15;
    
    addvalue5(&a, &b, &c);
    printf("The value of a, b, c are %d %d %d\n", a, b, c);
}