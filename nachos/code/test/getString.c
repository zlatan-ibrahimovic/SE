#include "syscall.h"

/*
.\nachos -x ../test/getString n i

Si i<n le systeme risquera d'ecrire sur zone memoire non allouée, ce qui peut produire une erreur (ce comportement est le même fgets de unix)
Si non le syteme copira dans str les n premiers characteres de la chaine ecrite par l'utilisateur.

Remarque: la taille du buffer interne est de 10.
 */

int main(){
 
  int i= 5;
  int n= 10 ;
  char str[i];
  
  PutString("Ecrivez la chaine de charactere\n");
  GetString(str,n);
  PutString(str);

  return 0;

}

