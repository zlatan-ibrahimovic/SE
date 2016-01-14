#ifdef CHANGED 
#include "userthread.h"

struct schmurtz {
  int f ;
  int arg;
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
    printf("Start user threads\n");
    
    machine->WriteRegister (StackReg,threadspace->AllocateUserStack());
    
    machine->Run();

  
}

struct schmurtz* schmurtz_create(int f, int arg){
  struct schmurtz* s;
  s=(struct schmurtz*)malloc(sizeof(*s));
  s->f=f;
  s->arg=arg;
  
  return s;
}

void delete_schmurtz(struct schmurtz * schmurtz){
  free(schmurtz);
}

int do_ThreadCreate(int f, int arg){
  
  curentThread->space->Get_stack_controler()->P();//stack_controler->P();
  
  if(curentThread->space->Get_stack_controler_bitmap()->NumClear()== 0){// if(stack_controler_bitmap->NumClear()==0){
    curentThread->space->Get_stack_controler()-V();// stack_controler->V();
    return -1;
  }
    

  Thread * newThread = new Thread("new threads"); 
  struct schmurtz* schmurtz = schmurtz_create(f,arg);
  

  curentThread->space->Get_lock_nb_thread()->P();//mutex->P();
  curentThread->space->Set_nb_thread(curentThread->space->Get_nb_thread()+1);//nb_thread++;
  curentThread->space->Get_lock_nb_thread()->V();//  mutex->V();
  
  newThread->Start (StartUserThread, schmurtz);

  curentThread->space->Get_stack_controler()->V();//stack_controler->V();
  return 0;
}

int do_ThreadExit(){
  
  mutex->P();
  nb_thread--;
  if(nb_thread == 0){
  sem->V();  
  } 
  mutex->V();
  currentThread->Finish();
  return 1;
}



#endif //CHANGED
