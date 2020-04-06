// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

int word_count = 0;

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
const unsigned int N = 583570837;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hash_lookup = hash(word); // Hash the word to compare
    node *current_node; // Set node to search list
    current_node = table[hash_lookup]; // Set list to hash
    int index = 0;

    while (current_node != NULL && strcasecmp(current_node->word, word) != 0)
    {
      if (strcasecmp(current_node->word, word) == 0)
      {
        return true;
      }
      index++;
      current_node = current_node->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Implementation of djb2
    unsigned int hashAddress = 5381;
    for (int counter = 0; word[counter]!='\0'; counter++)
    {
      hashAddress = ((hashAddress << 5) + hashAddress) + word[counter];
    }
    return hashAddress;
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

    while (fscanf(dict, "%s", word) != EOF) //Condition to read whole of dict
    {
      tmp = create_new_node(word);
      int result = hash(word);
      tmp->next = table[result];
      table[result] = tmp;
      word_count++;
      return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
