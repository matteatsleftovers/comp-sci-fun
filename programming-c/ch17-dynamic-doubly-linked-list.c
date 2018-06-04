// Program to explore a doubly linked list, DYNAMICALLY

#include <stdio.h>
#include <stdlib.h>

struct entry
{
  int           value;
  struct entry  *previous;
  struct entry  *next;
};

struct entry *insertEntry(struct entry *startingEntryPtr, int value)
{
  struct entry *newEntryPtr = (struct entry *) malloc (sizeof(struct entry));
  newEntryPtr->value = value;
  newEntryPtr->previous = startingEntryPtr;
  newEntryPtr->next = startingEntryPtr->next;
  startingEntryPtr->next = newEntryPtr;
  return newEntryPtr;
}

void removeEntry(struct entry *entryPtr)
{
  entryPtr->previous->next = entryPtr->next;
  entryPtr->next->previous = entryPtr->previous;
  free(entryPtr);
}

int main(void)
{
  struct entry n1, n2, n3;
  struct entry *list_pointer = &n3;

  n1.value = 100;
  n1.previous = (struct entry *) 0;
  n1.next = &n2;

  n2.value = 200;
  n2.next = &n3;
  n2.previous = &n1;

  n3.value = 300;
  n3.previous = &n2;
  n3.next = (struct entry *) 0;

  printf ("The original doubly linked list!\n");
  while ( list_pointer != (struct entry *) 0 )
  {
    printf("%i\n", list_pointer->value);
    list_pointer = list_pointer->previous;
  }

  struct entry *insertPtr = &n2;
  struct entry *newEntryPtr = insertEntry(insertPtr, 250);
  list_pointer = &n1;
  printf ("\nNow let's insert a new entry of value %i after value %i\n", newEntryPtr->value, insertPtr->value);

  while ( list_pointer != (struct entry *) 0 )
  {
    printf("%i\n", list_pointer->value);
    list_pointer = list_pointer->next;
  }

  printf("\nNow let's remove that new entry and show the list again\n");
  removeEntry(newEntryPtr);
  list_pointer = &n1;

  while ( list_pointer != (struct entry *) 0 )
  {
    printf("%i\n", list_pointer->value);
    list_pointer = list_pointer->next;
  }
}
