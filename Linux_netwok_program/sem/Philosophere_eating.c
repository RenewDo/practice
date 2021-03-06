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



int sem_p(int semid)
{
     struct sembuf sb = {0, -1, 0};
     int ret = semop(semid, &sb, 1);
     if(ret == -1)
              ERR_EXIT("semop");
     return ret;
}

int sem_v(int semid)
{
     struct sembuf sb = {0, 1, 0};
     int ret = semop(semid, &sb, 1);
     if(ret == -1)
              ERR_EXIT("semop");
     return ret;
}

int semid;
#define DELAY (rand()%5+1)

void wait_for_2fork(int no)
{
     int left = no;
     int right = (no+1)%5;
     
     struct sembuf buf[2] = {{left, -1, 0}, {right, -1, 0}};
     semop(semid, buf, 2);
}

void free_2fork(int no)
{
     int left = no;
     int right = (no+1)%5;
     
     struct sembuf buf[2] = {{left, 1, 0}, {right, 1, 0}};
     semop(semid, buf, 2);
}

void wait_1fork(int no)
{
     struct sembuf buf[2] = {no, -1, 0};
     int ret;
     ret = semop(semid, buf, 2);
     if(ret == -1)
            ERR_EXIT("semop");
}

void Philosophere(int no)
{
     for(;;)
     {
        printf("%d is thinking\n", no);
          sleep(DELAY);
          printf("%d is hungry\n", no);
          wait_for_2fork(no);
          printf("%d is eating\n",no);
          sleep(DELAY);
          free_2fork(no);
/*       //deadlock   
          int left = no;
          int right = (no+1)%5;
          printf("%d is thinking\n", no);
          sleep(DELAY);
          printf("%d is hungry\n", no);
          wait_1fork(left);
          sleep(DELAY);
          wait_1fork(right);
          printf("%d is eating\n",no);
          sleep(DELAY);
          free_2fork(no);*/
     }
}

int main(int argc, char* argv[])
{
     semid = semget(IPC_PRIVATE, 5, IPC_CREAT | 0666);
     if(semid == -1)
              ERR_EXIT("semget");
     union semun su;
     su.val = 1;
     int i;
     for(i=0; i<5; i++)
     {
            semctl(semid, i, SETVAL, su); 
     }
     int no = 0;
     pid_t pid;
     for(i=1; i<5; ++i)
     {
              pid = fork();
              if(pid == -1)
                     ERR_EXIT("fork");
              if(pid == 0)
               {
                     no = i;
                     break;
               }
     }

     Philosophere(no);
     return 0;
}
