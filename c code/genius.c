#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 1000000

int nth_prime(int n) {
    char *is_prime = calloc(MAX, sizeof(char));
    int count = 0, result = -1;

    if (!is_prime) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 2; i < MAX; ++i) is_prime[i] = 1;

    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) {
            count++;
            if (count == n) {
                result = i;
                break;
            }
            for (int j = i * 2; j < MAX; j += i)
                is_prime[j] = 0;
        }
    }

    free(is_prime);
    return result;
}

int main() {
    int n;
    printf("Enter n to find the nth prime: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid input.\n");
        return 1;
    }

    clock_t start = clock();
    int prime = nth_prime(n);
    clock_t end = clock();

    if (prime != -1)
        printf("The %dth prime is %d\n", n, prime);
    else
        printf("Could not find the %dth prime within range.\n", n);

    printf("Time taken: %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
