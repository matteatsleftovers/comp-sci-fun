#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  char inputFileName[64] = "ch15-ex6-input.txt";
  FILE *in;
  char buffer[63], action;

  if ( (in = fopen(inputFileName, "r")) == NULL ) {
    printf("Can't open %s for reading.\n", inputFileName);
  }

  while ( !feof(in) ) {
    int i;
    for (i = 0; i < 20 && !feof(in); i++) {
      fgets(buffer, 63, in);
      fprintf(stdout, "%s", buffer);
    }
    printf("What next?\n");
    scanf("%c", &action);
    if (action == 'q') {
      break;
    }
  }

  fclose(in);

  return 0;
}
