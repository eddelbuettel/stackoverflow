#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int c;

    printf("Please enter a letter: ");

    while ((c = getchar()) !='.')
        printf("The letter is: %c", c);

    return 0;
}
