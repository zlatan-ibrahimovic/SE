#ifdef CHANGED 
#include "userthread.h"
#include "addrspace.h"

struct schmurtz {
  int f ;
  int arg;
  int i_bitclear;
};


static void StartUserThread(void * schmurtz)
{
 
  AddrSpace *threadspace;

  threadspace = currentThread->space;
  struct schmurtz* sc = (struct schmurtz*) schmurtz;
  
    // Initial program counter -- must be location of the begining of the function
    machine->WriteRegister (PCReg, sc->f);
   
    // Write the argument of the function
    machine->WriteRegister (4,sc->arg );

   
    machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);

    // Set the stack register to the end of the address space, where we
    // allocated the stack; but subtract off a bit, to make sure we don't
    // accidentally reference off the end!
    machine->WriteRegister (StackReg, threadspace->AllocateUserStack() -(sc->i_bitclear * 256));
    // machine->WriteRegister (StackReg,threadspace->AllocateUserStack());

    machine->Run();

  
}

struct schmurtz* schmurtz_create(int f, int arg, int indice){
  struct schmurtz* s;
  s=(struct schmurtz*)malloc(sizeof(*s));
  s->f=f;
  s->arg=arg;
  s->i_bitclear = indice;

  return s;
}

void delete_schmurtz(struct schmurtz * schmurtz){
  free(schmurtz);
}

int do_ThreadCreate(int f, int arg){
  sembitmap->P();
  int bitclear = bitmap->Find();
  sembitmap->V();
  if(bitclear == -1){
    return -1;
  }
  Thread * newThread = new Thread("new threads"); 
  struct schmurtz* schmurtz = schmurtz_create(f,arg,bitclear);
  mutex->P();
  nb_thread++;
  mutex->V(); 

  newThread->Start (StartUserThread, schmurtz);
  
  return 0;
}

int do_ThreadExit(){

  mutex->P();
  nb_thread--;
  sembitmap->P();
  bitmap->Clear(( machine->registers[StackReg]-(PageSize * currentThread->space->GetNumPages()))/256);
  mutex->P();
  nb_thread++;
  mutex->V(); 
 
  sembitmap->V();
  if(nb_thread == 0){
  sem->V();  
  } 
  mutex->V();
  currentThread->Finish();
  return 1;
}



#endif //CHANGED
