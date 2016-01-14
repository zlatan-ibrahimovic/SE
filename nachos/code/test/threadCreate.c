#include "syscall.h"




void f( char c){
  
  PutChar(c);
  ThreadExit();
}





int main(){
  char c = 'c';
  ThreadCreate(f, c);
   PutChar('d');
 

}
