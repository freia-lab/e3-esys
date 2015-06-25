#include <stdio.h>
#include <string.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <subRecord.h>
#include <aSubRecord.h>
#include <epicsExport.h>

int mySubDebug;


static long mysubInit(struct subRecord *psub)
{
    printf("subInit was called\n");
    return(0);
}
 
static long mysubProcess(struct subRecord *psub)
{
    psub->val++;
    return(0);
}
static long myAsubInit(aSubRecord *precord)
{
    if (mySubDebug)
        printf("Record %s called myAsubInit(%p)\n",
               precord->name, (void*) precord);
    return 0;
}

static long myAsubProcess(aSubRecord *precord)
{
  epicsOldString outs;
  int m, d, y, hh, mm, ss;
  unsigned long l;
  if (mySubDebug) {
        printf("Record %s called myAsubProcess(%p)\n",
               precord->name, (void*) precord);
	printf ("Input: %lu\n", *((unsigned long *) precord->a));
  }
  l = *(unsigned long *) precord->a;
  ss = l & 0x0000003F;
  mm = (l & 0x00000FC0) >> 6;
  hh = (l & 0x0001F000) >> 12;
  y = 2000 + ((l & 0x007E0000) >> 17);
  m = (l & 0x07800000) >> 23;
  d = (l & 0xF8000000) >> 27;
  sprintf ((char *) outs, "%d-%02d-%02d %02d:%02d:%02d", y, m, d, hh, mm, ss);
  strncpy ((char *) precord->vala, outs, 40);

  if (mySubDebug) {  
    printf ("Output: %s p->vala: %p: %s\n", outs, (void*) (precord->vala), (char *)  precord->vala);
    printf ("Old output: %s\n",  (char *)  precord->ovla);
  } 
    return 0;
}

/* Register these symbols for use by IOC code: */

epicsRegisterFunction(mysubInit);
epicsRegisterFunction(mysubProcess);
epicsExportAddress(int, mySubDebug);
epicsRegisterFunction(myAsubInit);
epicsRegisterFunction(myAsubProcess);

