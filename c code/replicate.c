#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source = fopen(__FILE__, "r");
    if (!source) return 1;

    char buffer[1024];
    int i = 1;
    while (1) {
        char filename[32];
        snprintf(filename, sizeof(filename), "replica%d.c", i);
        FILE *dest = fopen(filename, "r");
        if (!dest) {
            dest = fopen(filename, "w");
            if (!dest) {
                fclose(source);
                return 1;
            }
            rewind(source);
            while (fgets(buffer, sizeof(buffer), source)) {
                fputs(buffer, dest);
            }
            fclose(dest);
            break;
        } else {
            fclose(dest);
            i++;
        }
    }
    fclose(source);
    return 0;
}
