#include "syscall.h"





/* Pour Lancer ce test , utiliser la ligne de commande suivante :
   ./nachos -x ../test/getInt
   Le resultat attendu est:
   retourne la chaine d'entiers donné par l'utilisateur.
si l'utilisateur donne des caracteres alphabethique au lieu des entiers, le programme retourn un nombre quand même.
        
*/



int main(){
 

  int c;
  GetInt(&c);
  PutInt(c);
  PutChar('\n');

}
