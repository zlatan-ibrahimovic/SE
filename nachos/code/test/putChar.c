
#include "syscall.h"


/* Pour Lancer ce test , utiliser la ligne de commande suivante :
   ./nachos -x ../test/putChar
   Le resultat attendu est:
     abcd
     <?>
   
*/



void print(char c,int n)
{
  int i;
#if 1
  for (i = 0; i < n; i++){
    PutChar(c +i);
  }
  PutChar('\n');
#endif
}

int main(){

  //permet d'afficher abcd
  print('a',4);

  PutChar(-4);
}

