#include "syscall.h"





/* Pour Lancer ce test , utiliser la ligne de commande suivante :
   ./nachos -x ../test/getChar
   Le resultat attendu est:
   Le premier caractere de la chaine que vous avez tapé.
        
*/



int main(){
 

  int c = GetChar();
  PutChar(c);
  PutChar('\n');

}

