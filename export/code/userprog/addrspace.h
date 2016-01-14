// addrspace.h 
//      Data structures to keep track of executing user programs 
//      (address spaces).
//
//      For now, we don't keep any information about address spaces.
//      The user level CPU state is saved and restored in the thread
//      executing the user program (see thread.h).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef ADDRSPACE_H
#define ADDRSPACE_H

#include "copyright.h"
#include "filesys.h"
#include "translate.h"
#include "bitmap.h"


#define UserStacksAreaSize		1024	// increase this as necessary!


#ifdef CHANGED
class Semaphore;
class Bitmap;
#endif //CHANGED


class AddrSpace:dontcopythis
{
  public:
    AddrSpace (OpenFile * executable);	// Create an address space,
    // initializing it with the program
    // stored in the file "executable"
    ~AddrSpace ();		// De-allocate an address space

    void InitRegisters ();	// Initialize user-level CPU registers,
    // before jumping to user code

    void SaveState ();		// Save/restore address space-specific
    void RestoreState ();	// info on a context switch 
      
    unsigned int AllocateUserStack();

    //get for thread's variables
    int Get_nb_thread();
    Semaphore *Get_stack_controler();
    Semaphore *Get_lock_nb_thread();
    Semaphore *Get_lock_function();
    BitMap *Get_stack_controler_bitmap();
    
    //set for thread's variables
    void Set_nb_thread(int new_nb_thread);
    
    
 private:
      TranslationEntry * pageTable;	// Assume linear page table translation
    // for now!
    unsigned int numPages;	// Number of pages in the virtual 
    // address space

    // variable for threads
    Semaphore *lock_nb_thread;
    Semaphore *lock_function;
    int nb_thread;
    Semaphore *sem;
    Semaphore *stack_controler;
    Bitmap *stack_controler_bitmap;
};

#endif // ADDRSPACE_H
