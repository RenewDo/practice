#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include <signal.h>
#include <sys/wait.h>

#define ERR_EXIT(m)\
        do\
        {\
            perror(m);\
            exit(EXIT_FAILURE);\
         }while(0)

struct msgbuf
{
       long mtype;
       char mtext[1];
};

int main(int argc, char *argv[])
{
      if(argc != 3)
      {
            fprintf(stderr, "Usage: %s <bytes> <type>\n", argv[0]);
            exit(EXIT_FAILURE);
      }
    
      int len = atoi(argv[1]);
      int type = atoi(argv[2]);
      int msgid;
      msgid = msgget(1234, 0666 | IPC_CREAT);
      if(msgid == -1)
              ERR_EXIT("msgget");
      
       struct msgbuf *ptr;
       ptr = (struct msgbuf*)malloc(sizeof(long)+len);
       ptr->mtype = type;
       if (msgsnd(msgid, ptr, len, 0) < 0)
                   ERR_EXIT("msgsnd");
       return 0;
}
