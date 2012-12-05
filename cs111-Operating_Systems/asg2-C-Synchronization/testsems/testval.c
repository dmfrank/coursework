/*******************************************************************************
 * $Id: testval.c,v 1.1 2012-05-12 18:48:09-07 dmfrank - $
 * Derek Frank
 * dmfrank@ucsc.edu
 *
 * NAME
 *   testval.c
 *
 * DESCRIPTION
 *   A test file to test the system calls of semaphore.
 ******************************************************************************/


#include <lib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
   char *exec = argv[0];
   if (argc < 2) {
      fprintf (stderr, "%s: %s: need a semaphore id\n", "ERROR", exec);
      fprintf (stderr, "%s: ./testval [semaphoreID]\n", "USAGE");
      return -1;
   }
   int semid = atoi (argv[1]);
   int testid = 0;
   
   
   // test semvalue
   printf ("%s %d: %s: %d\n", exec, testid, "starting semvalue", semid);
   int result = semvalue (semid);
   if (result <= 0) {
      fprintf (stderr, "%s %d: %s: in %s\n", exec, testid, "ERROR", "semvalue");
      return result;
   }
   printf ("%s %d: %s: %d\n", exec, testid, "finished semvalue", semid);


   // finished all
   printf ("%s %d: %s\n", exec, testid, "finished all");
   
   return result;
}
