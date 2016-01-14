   // exception.cc 
//      Entry point into the Nachos kernel from user programs.
//      There are two kinds of things that can cause control to
//      transfer back to here from user code:
//
//      syscall -- The user code explicitly requests to call a procedure
//      in the Nachos kernel.  Right now, the only function we support is
//      "Halt".
//
//      exceptions -- The user code does something that the CPU can't handle.
//      For instance, accessing memory that doesn't exist, arithmetic errors,
//      etc.  
//
//      Interrupts (which can also cause control to transfer from user
//      code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"

#ifdef CHANGED 
#include "userthread.h"


#endif 

//----------------------------------------------------------------------
// UpdatePC : Increments the Program Counter register in order to resume
// the user program immediately after the "syscall" instruction.
//----------------------------------------------------------------------
static void
UpdatePC ()
{
  int pc = machine->ReadRegister (PCReg);
  machine->WriteRegister (PrevPCReg, pc);
  pc = machine->ReadRegister (NextPCReg);
  machine->WriteRegister (PCReg, pc);
  pc += 4;
  machine->WriteRegister (NextPCReg, pc);
}

#ifdef CHANGED 
int copyStringFromMachine( int from, char *to, unsigned size)

{
  int i=0,data ;
  char c ;

  do{
    machine->ReadMem(from+i, 1,&data);
    c = (char) data ;
    to[i]=c;
    i++;
  }while(i<(int) size && (c!='\0') && (c!=EOF));
  to[i]='\0';
  return i;


}

int copyStringToMachine( int from, char *to, unsigned size)

{
  int i=0,data ;
 
  while(to[i]!='\0' && to[i]!= EOF && to[i]!='\n' && i<(int) size){
    data = (int) to[i];
    machine->WriteMem(from+i, 1,data);
    i++;
  }
  machine->WriteMem(from+i, 1,'\0');
  return i;

}
#endif //CHANGED

//----------------------------------------------------------------------
// ExceptionHandler
//      Entry point into the Nachos kernel.  Called when a user program
//      is executing, and either does a syscall, or generates an addressing
//      or arithmetic exception.
//
//      For system calls, the following is the calling convention:
//
//      system call code -- r2
//              arg1 -- r4
//              arg2 -- r5
//              arg3 -- r6
//              arg4 -- r7
//
//      The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//      "which" is the kind of exception.  The list of possible exceptions 
//      are in machine.h.
//----------------------------------------------------------------------

void
ExceptionHandler (ExceptionType which)
{
  int type = machine->ReadRegister (2);

  switch (which)
    {
    case SyscallException:
      {
	switch (type)
	  {
	  case SC_Halt:
	    {
	      DEBUG ('a', "Shutdown, initiated by user program.\n");
	      interrupt->Halt();
	     
	      break;
	    }
#ifdef CHANGED 
	  case SC_PutChar:
	    {
	      DEBUG ('a', "Shutdown, initiated by user program.\n");
	      
	      synchconsole->SynchPutChar (machine->ReadRegister (4) );
	      break;
	    }
		
	  case SC_PutString:
	    { 

	      int n =MAX_STRING_SIZE;
	      int i=0;
	      char str[MAX_STRING_SIZE]; 
	      while(n==MAX_STRING_SIZE){
		DEBUG ('a', "Shutdown, initiated by user program.\n");
		n=copyStringFromMachine(machine->ReadRegister (4)+i, str, MAX_STRING_SIZE);
		synchconsole->SynchPutString (str);
		i=i+n;
	      }
		   
		  
		
	      break;
	    }
	  case SC_Exit:
	    {
	      DEBUG ('a', "Exit, initiated by user program.\n");
	      
	      while(nb_thread !=0)
		sem->P();
	      interrupt->Halt ();	
      
	      break;
	    }


	  case SC_GetChar:
	    {
	      DEBUG ('a', "Shutdown, initiated by user program.\n");
	      machine->registers[2]=synchconsole->SynchGetChar ();
	      break;
	    }


	  case SC_GetString:
	    {
	      int n =MAX_STRING_SIZE;
	      int i=0;
	      char str[MAX_STRING_SIZE];
	
	      int tmp=MAX_STRING_SIZE;
	      while(n==MAX_STRING_SIZE && i < machine->registers[5]){


		if(MAX_STRING_SIZE > machine->registers[5]-i){
		  tmp= machine->registers[5]-i;
	
		}


		DEBUG ('a', "Shutdown, initiated by user program.\n");
		synchconsole->SynchGetString (str,tmp);
		n= copyStringToMachine(machine->ReadRegister(4)+i, str, tmp);

		printf("\ni=%d - value before cpySt.... %d\n",i,n);
		i=i+n;
		
	      }
	     
	      break;
	    
	    }

	    case SC_PutInt:
	    {
	      DEBUG ('a', "Shutdown, initiated by user program.\n");
	      char int_val[12];
              snprintf(int_val, 12 ,"%d", machine->ReadRegister (4) );
	      synchconsole->SynchPutString(int_val);
	      break;
	    }

	     case SC_GetInt:
	    {
	      DEBUG ('a', "Shutdown, initiated by user program.\n");
	      char int_val[12];
	      int val;
	      synchconsole->SynchGetString (int_val,12);
	      sscanf(int_val,"%d",&val);
	      machine->WriteMem(machine->ReadRegister (4), 4,val);
	      break;
	    }

	     case SC_ThreadCreate:
	    {
	      DEBUG ('a', "Thread create, initiated by user program.\n");
	      do_ThreadCreate( machine->ReadRegister (4) ,  machine->ReadRegister (5));	     
	      break;
	    }
	  case SC_ThreadExit:
	    {
	      do_ThreadExit();
	      break;
	    }


	    


	
		
#endif //CHANGED
      default:
	{
	  printf("Unimplemented system call %d\n", type);
	  ASSERT(FALSE);
	}
      }

      // Do not forget to increment the pc before returning!
      UpdatePC ();
      break;
    }

 case PageFaultException:
   if (!type) {
     printf("NULL dereference at PC %x!\n", machine->registers[PCReg]);
     ASSERT (FALSE);
   } else {
     printf ("Page Fault at address %x at PC %x\n", type, machine->registers[PCReg]);
     ASSERT (FALSE);	// For now
   }

 default:
   printf ("Unexpected  mode exception %d %d at PC %x\n", which, type, machine->registers[PCReg]);
   ASSERT (FALSE);
}
}
