#include "shmfifo.h"
#include <stdio.h>

typedef struct stu
{
   char name[32];
   int age;
}STU; 


int main()
{
   shmfifo_t *fifo = shmfifo_init(1234, sizeof(STU), 3);
   shmfifo_destroy(fifo);
   return 0;
}
