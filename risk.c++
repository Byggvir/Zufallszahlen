#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

double spielab (int n) ;

int main(int argc, char *argv[ ]) {

     double r;
     
     r = spielab(3);
     printf("%8.5e", r);	
 

}

double spielab (int n) {

 float erg;

 if (n==0) { erg = 1.0;}  
 else {
       if (n==6) { erg = 0.0 ;} 
       else { erg =(19.0*spielab(n-1) + 18.0*spielab(n+1))/37.0 ;};
       }

 return (erg);

}

