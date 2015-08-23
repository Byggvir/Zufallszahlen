#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[ ]) {
  int zahl , m ;

  if (argc > 1 ) {
     m = atoi(argv[1]);
  }
  else {  
    m = 100;
  }

  srand(time(NULL));
  zahl = rand() % m;
  printf("%d\n", zahl);

}


