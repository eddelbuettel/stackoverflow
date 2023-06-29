#include <stdio.h>
#include <stdlib.h>

int main(void) {

    printf("Please enter a letter: \n");
    for (char c = getchar(); c !='.'; c = getchar())
        printf("The letter is: '%c'\n", c);

    return 0;
}
