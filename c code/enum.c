#include <stdio.h>

enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main() {
    enum Day today = WEDNESDAY;

    if (today == WEDNESDAY) {
        printf("It's Wednesday!\n");
    } else {
        printf("It's not Wednesday.\n");
    }

    return 0;
}