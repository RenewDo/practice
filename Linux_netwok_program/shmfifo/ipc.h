#ifndef _IPC_H_
#define _IPC_H_

#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

#define ERR_EXIT(m)\
        do\
        {\
            perror(m);\
            exit(EXIT_FAILURE);\
         }while(0)

union semun
{
       int val;
       struct semid_ds *buf;
       unsigned short *array;
       struct semifo *_buf;
};

int sem_create(key_t key);
int sem_open(key_t key);
int sem_p(int semid);
int sem_v(int semid);
int sem_d(int semid);
int sem_setval(int semid, int val);
int sem_getval(int semid);
int sem_getmode(int semid);
int sem_setmode(int semid, char* mode);

#endif
