// Program to sort an array of integers into ascending/descending order

#include <stdio.h>
#include <string.h>

void reassign (int *ai, int *aj)
{
  int temp;

  temp = *ai;
  *ai = *aj;
  *aj = temp;
}

void sort (int a[], int n, int order)
{
  int i, j;

  for ( i = 0; i < n - 1; ++i )
    for ( j = i + 1; j < n; ++j )
      if ( order == 1) {
        if ( a[i] > a[j] ) {
          reassign (&a[i], &a[j]);
        }
      }
      else if ( order == -1) {
        if ( a[i] < a[j] ) {
          reassign (&a[i], &a[j]);
        }
      }
}

int main (void)
{
  int i, order = -1;
  int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
                    44, -3, -9, 12, 17, 22, 6, 11 };
  char sortOrder[5];

  printf ("The array before the sort:\n");

  for ( i = 0; i < 16; ++i )
    printf ("%i ", array[i]);

  sort (array, 16, order);

  if ( order == 1 ) {
    strcpy (sortOrder, "asc ");
  }
  else if ( order == -1 ) {
    strcpy (sortOrder, "desc");
  }

  printf ("\n\nThe array after the %s sort:\n", sortOrder);

  for ( i = 0; i < 16; ++i)
    printf ("%i ", array[i]);

  printf ("\n");

  return 0;
}
