#include "syscall.h"


/* Pour Lancer ce test , utiliser la ligne de commande suivante :
   ./nachos -x ../test/putString
   Le resultat attendu est MAX_SIZE = 10 :
        0123456789
	012345
	01234567890123456789012345678901234567890
        
*/



void printString(char* ch)
{
  PutString(ch);
}

int main(){

  char ch1[]="0123456789";
  char ch2[]="012345";
  char ch3[]="01234567890123456789012345678901234567890";
  char separator[]="\n";

  printString(separator);
  printString(ch1);
 printString(separator);
  printString(ch2);
  printString(separator);
  printString(ch3);
  printString(separator);
   Halt();



}
