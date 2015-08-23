#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[ ]) {
  int zahl , anzahl, i , j;
  int max[256];

  if (argc > 1 ) {
     anzahl = atoi(argv[1]);
     for (j=2;j<argc;j++) {
	max[j-2]=atoi(argv[j]);
     }
  }
  else {
    anzahl = 1;
  }

  srand(time(NULL));
  for (i=0;i<anzahl; i++ ) {
     for (j=0;j<argc-2;j++) {
	zahl = rand() % max[j];
	printf("%d ", zahl);
     }
     printf("\n");	
  }

}


