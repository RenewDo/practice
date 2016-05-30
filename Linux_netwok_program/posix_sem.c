#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<pthread.h>
#include<semaphore.h>

#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

#define ERR_EXIT(m)\
        do\
        {\
            perror(m);\
            exit(EXIT_FAILURE);\
         }while(0)

#define CONSUMERS_COUNT 1
#define PROCESS_COUNT 5
#define BUFFSIZE 10

int g_buffer[BUFFSIZE];

unsigned short in = 0;
unsigned short out = 0;
unsigned short produce_id = 0;
unsigned short consume_id = 0;

sem_t g_sem_full;
sem_t g_sem_empty;
pthread_mutex_t g_mutex;

pthread_t g_thread[CONSUMERS_COUNT+PROCESS_COUNT];

void *consume(void *arg)
{
       int i;
       while(1)
       {
            printf("%d wait buffer not empty\n", (int)arg);
            sem_wait(&g_sem_empty);
            pthread_mutex_lock(&g_mutex);
            for(i=0; i<BUFFSIZE; i++)
            {
                   printf("%02d", i);
                   if(g_buffer[i] == -1)
                           printf("%s", "null");
                   else    printf("%d", g_buffer[i]);
                   if(i == out)
                           printf("\t<--consume");
                           printf("\n");

            }
            consume_id = g_buffer[out];
            printf("%d begin consume product %d\n",(int)arg, consume_id);
            g_buffer[out] = -1;
            out = (out+1)%BUFFSIZE;
            printf("%d end consume product %d\n", (int)arg,consume_id);
            pthread_mutex_unlock(&g_mutex);
            sem_post(&g_sem_full);
            sleep(5);
       }
       return NULL;
}

void *produce(void *arg)
{
       int i;
       while(1)
       {
            printf("%d wait buffer not full\n", (int)arg);
            sem_wait(&g_sem_full);
            pthread_mutex_lock(&g_mutex);
            for(i=0; i<BUFFSIZE; i++)
            {
                   printf("%02d", i);
                   if(g_buffer[i] == -1)
                           printf("%s", "null");
                   else    printf("%d", g_buffer[i]);
                   if(i == in)
                           printf("\t<--produce");
                           printf("\n");

            }
            printf("%d begin produce product %d\n", (int)arg, produce_id);
            g_buffer[in] = produce_id;
            in = (in+1)%BUFFSIZE;
            printf("%d end produce product %d\n", (int)arg, produce_id++);
            pthread_mutex_unlock(&g_mutex);
            sem_post(&g_sem_full);
            pthread_mutex_unlock(&g_mutex);
            sem_post(&g_sem_empty);
            sleep(1);
       }
      return NULL;
}

int main()
{   
     int i;
     for(i=0; i<BUFFSIZE; i++)
             g_buffer[i]= -1;
     sem_init(&g_sem_full, 0, BUFFSIZE);
     sem_init(&g_sem_empty, 0, 0);

     pthread_mutex_init(&g_mutex, NULL);

     for(i=0; i<CONSUMERS_COUNT; ++i)
             pthread_create(&g_thread[i], NULL, consume, (void*)i);

     for(i=0; i<PROCESS_COUNT; ++i)
             pthread_create(&g_thread[i+CONSUMERS_COUNT], NULL, produce, (void*)i);

    for(i=0; i<PROCESS_COUNT+CONSUMERS_COUNT; ++i)
          pthread_join(g_thread[i], NULL);
     
     sem_destroy(&g_sem_full);
     sem_destroy(&g_sem_empty);
     pthread_mutex_destroy(&g_mutex);

     return 0;
}
