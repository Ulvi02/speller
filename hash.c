#include <stdio.h>
#include <stdlib.h>

#define LENGTH 45

int main(void)
{
    char * input = malloc(LENGTH + 1);
    printf("Word to hash: ");
    scanf("%s", input);
    printf("%s\n", input);
}