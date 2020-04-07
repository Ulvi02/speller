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
} node;

// Create new node function
node *create_new_node(char word[LENGTH + 1])
{
  node *result = malloc(sizeof(node));
  strcpy(result->word, word);
  result->next = NULL;
  return result;
}

// Number of buckets in hash table
const unsigned int N = 89696662;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
  int hash_lookup = hash(word);      // Hash the word to compare
  node *current_node;                // Set node to search list
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
  int hash, i; // Jenkins "One at a Time" hash
  for (hash = i = 0; i < strlen(word); ++i)
  {
    hash += word[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);
  return (hash % N);
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
  }
  return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
  return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
  node *temp; // Temp and crawler to seek and delete
  node *crawler;

  for (int i = 0; i < N; i++)
  {
    if (table[i] != NULL)
    {
      crawler = table[i];
      while (crawler != NULL)
      {
        temp = crawler->next;
        free(crawler);
        crawler = temp;
      }
      temp = crawler;
      free(temp);
    }
    return true;
  }
  return false;
}
