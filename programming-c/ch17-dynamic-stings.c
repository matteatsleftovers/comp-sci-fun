#include <stdio.h>

int getStringSize(const char *s1)
{
  int size = 0;
  while ( s1[size] != '\0' ) size++;
  return size;
}

int findString(const char s1[], const char s2[])
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

char *removeString(char *text, int startingIndex, int stringSize)
{
  int i = 0;
  while ( text[i] != '\0' )
  {
    if ( i >= startingIndex ) text[i] = text[i + stringSize];
    i++;
  }
  printf("Righteous, your string now looks like this: %s\n", text);
}

char *insertString(char *text, char *textToInsert, int startingIndex)
{
  int i = 0;
  int insertedTextLength = getStringSize(textToInsert);

  while ( i < insertedTextLength )
  {
    text[i + startingIndex + insertedTextLength] = text[i + startingIndex];
    i++;
  }
  text[i + startingIndex + insertedTextLength] = '\0';
  printf("Before inserting the new string, the string in memory looks like this: %s\n", text);
  i = 0;

  while ( textToInsert[i] != '\0' )
  {
    text[startingIndex + i] = textToInsert[i];
    i++;
  }
}

char *replaceString(char *sourceText, char *s1, char *s2) {
  int index = findString(sourceText, s1);
  if (index >= 0)
  {
    removeString(sourceText, index, getStringSize(s1));
    insertString(sourceText, s2, index);
  }

}

int main(void)
{
  char charString[30], s1[20], s2[20];

  printf("Enter a character string: ");
  scanf("%[^\n]", charString);
  printf("Great! I have that the string is \"%s\".\n", charString);
  printf("Enter a contained character string you would like replaced: ");
  scanf("%s", s1);
  printf("What would you like to replace it with?: ");
  scanf("%s", s2);
  printf("Cool, let's replace \"%s\" with \"%s\".\n", s1, s2);

  replaceString(charString, s1, s2);

  printf("\nThe resulting string is now \"%s\".\n", charString);

  return 0;
}
