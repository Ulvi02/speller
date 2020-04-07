#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int hash(const char *word)
{
    int hash, i; // Jenkins "One at a Time" hash
    for(hash = i = 0; i < strlen(word); ++i)
    {
        hash += word[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

int main(void)
{
    printf("%i", hash("Pneumonoultramicroscopicsilicovolcanoconiosis"));
}
