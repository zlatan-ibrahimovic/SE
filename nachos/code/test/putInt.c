
#include "syscall.h"



/* Pour Lancer ce test , utiliser la ligne de commande suivante :
   ./nachos -x ../test/putInt
   Le resultat attendu est:
    250
    -8948
    3000000000
*/






int main(){
   
  PutInt(250);
  PutChar('\n');
  PutInt(-8948);
  PutChar('\n');
  PutInt(300000000);
  PutChar('\n');
}

