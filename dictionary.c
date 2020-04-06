// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Create new node function
node *create_new_node(char word[LENGTH + 1]) {
  node *result = malloc(sizeof(node));
  strcpy(result->word, word);
  result->next = NULL;
  return result;
}

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r"); // Open file

    if (dict == NULL)
    {
      return false;
    }

    char word[LENGTH + 1];
    node *tmp;
    node *head;

    while (fscanf(dict, "%s", word) != EOF) //Condition to read whole of dict
    {
      tmp = create_new_node(word);
      tmp->next = head;
      head = tmp;
    }
    // TODO - make the head go to the hash value of the word
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
