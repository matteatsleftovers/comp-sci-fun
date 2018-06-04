#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  char inputFileName[64] = "ch15-ex5-input.txt";
  FILE *in;
  int m, n;
  char buffer[63];

  if ( (in = fopen(inputFileName, "r")) == NULL ) {
    printf("Can't open %s for reading.\n", inputFileName);
  }

  printf("Please enter the starting column m.\n");
  scanf("%i", &m);
  printf("Please enter the ending column n.\n");
  scanf("%i", &n);

  while ( !feof(in) ) {
    fgets(buffer, 63, in);
    int i;
    for (i = m; i <= n; i++) {
      fprintf(stdout, "%c", buffer[i]);
    }
    fprintf(stdout, "\n");
  }

  fclose(in);

  return 0;
}
