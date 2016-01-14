#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "synchconsole.h"


static Semaphore *readAvail;
static Semaphore *writeDone;
static Semaphore *synchroThread;
 

static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }
 


SynchConsole::SynchConsole(const char *in, const char *out)
{
  readAvail = new Semaphore("read avail", 0);
  writeDone = new Semaphore("write done", 0);
  synchroThread =  new  Semaphore("thread executed", 1);
  console = new Console (in, out, ReadAvailHandler, WriteDoneHandler, 0);
  
}
SynchConsole::~SynchConsole()
{
  delete console;
  delete writeDone;
  delete readAvail;
  delete synchroThread;
}

void SynchConsole::SynchPutChar(int ch)
{
  synchroThread->P ();
  console->PutChar (ch);
  writeDone->P ();
  synchroThread->V ();
  return ;
}

int SynchConsole::SynchGetChar()
{
  synchroThread->P ();
  readAvail->P ();
  int c=console->GetChar ();
  synchroThread->V ();
  return c;
  
}

void SynchConsole::SynchPutString(const char s[])
{
  int i=0;
  while ( s[i] !='\0'){
    console->PutChar(s[i]);
    writeDone->P();
    i++;
  }
}
void SynchConsole::SynchGetString(char *s, int n)
{
  int i=0;
  do{
    readAvail->P ();
    s[i]=console->GetChar ();
    i++;
  }while ( i < n && s[i-1]!='\0'&& s[i-1]!='\n');
  s[i]='\0';
}

#endif // CHANGED
