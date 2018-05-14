/* A function to determine the position of a character substring in a string,
    returning the position of the substring if contained, and -1 if not */

#include <stdio.h>

// Function to find the length of a given string
int getStringSize (const char *s1)
{
  int size = 0;
  while ( s1[size] != '\0' ) size++;
  return size;
}

// Function to compare two character strings

int findString (const char s1[], const char s2[])
{
  int s2Size = getStringSize (s2);
  int i = 0, j = 0;

  while ( s1[i] != '\0' )
  {
    if (s1[i] == s2[j]) {
      while ( s1[i+j] == s2[j] && s2[j] != '\0' ) j++;
      if (j == s2Size) return i;
      else j = 0;
    }
    i++;
  }

  return -1;
}

void removeString (char text[], int startingIndex, int stringSize)
{
  int i = 0;
  while ( text[i] != '\0' )
  {
    if ( i >= startingIndex )
    {
      text[i] = text[i + stringSize];
    }
    i++;
  }
}

int main (void)
{
  int startingIndex, stringSize;
  char charString[20];
  // , substring[20];

  printf ("Enter a character string: ");
  scanf ("%[^\n]", charString);
  printf ("Great! I have that the string is \"%s\".\n", charString);
  printf ("Enter the starting index for removing characters: ");
  scanf("%i", &startingIndex);
  printf ("Enter the length of the character string you want to remove: ");
  scanf("%i", &stringSize);
  // printf ("Enter a word you want to find within: ");
  // scanf ("%19s", substring);
  //
  // index = findString (word, substring);
  //
  // printf ("\nLooks like your substring is at index %i.\n", index);

  removeString (charString, startingIndex, stringSize);

  printf ("\nThe altered string is now \"%s\".\n", charString);

  return 0;
}
