// Program to explore a doubly linked list

#include <stdio.h>

struct entry
{
  int           value;
  struct entry  *previous;
  struct entry  *next;
};

void insertEntry (struct entry *startingEntryPtr, struct entry *newEntryPtr)
{
  newEntryPtr->previous = startingEntryPtr;
  newEntryPtr->next = startingEntryPtr->next;
  startingEntryPtr->next = newEntryPtr;
}

void removeEntry (struct entry *entryPtr)
{
  entryPtr->previous->next = entryPtr->next;
  entryPtr->next->previous = entryPtr->previous;
}

int main (void)
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

  struct entry n4;
  n4.value = 250;
  struct entry *insertPtr = &n2;
  printf ("\nNow let's insert a new entry of value %i after value %i\n", n4.value, insertPtr->value);
  insertEntry (insertPtr, &n4);
  list_pointer = &n1;

  while ( list_pointer != (struct entry *) 0 )
  {
    printf("%i\n", list_pointer->value);
    list_pointer = list_pointer->next;
  }

  printf ("\nNow let's remove that new entry and show the list again\n");
  removeEntry (&n4);
  list_pointer = &n1;

  while ( list_pointer != (struct entry *) 0 )
  {
    printf("%i\n", list_pointer->value);
    list_pointer = list_pointer->next;
  }
}
