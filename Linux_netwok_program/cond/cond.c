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

#define CONSUMERS_COUNT 2
#define PROCESS_COUNT 1

pthread_mutex_t g_mutex;
pthread_cond_t g_cond;

pthread_t g_thread[CONSUMERS_COUNT+PROCESS_COUNT];

int nready = 0;

void *consume(void *arg)
{
       int num = (int)arg;
       while(1)
       {
            pthread_mutex_lock(&g_mutex);
            while(nready == 0)
            {
                 printf("%d begin wait a condition...\n",num);
                 pthread_cond_wait(&g_cond, &g_mutex);
            }
            printf("%d end wait a condition...\n",num);
             printf("%d begin consume product...\n",num);
             --nready;
             pthread_mutex_unlock(&g_mutex);
             sleep(1);
       }
       return NULL;
}

void *produce(void *arg)
{
      
       int num = (int)arg;
       while(1)
       {
            pthread_mutex_lock(&g_mutex);
             printf("%d begin produce product...\n",num);
            ++nready; 
              printf("%d end produce  product...\n",num);
             pthread_cond_signal(&g_cond);
             printf("%d signal...\n",num);
             pthread_mutex_unlock(&g_mutex);
             sleep(5);
       }
      return NULL;
}

int main()
{   
      int i;

      pthread_mutex_init(&g_mutex, NULL);
      pthread_cond_init(&g_cond, NULL);
   
      for(i=0; i<CONSUMERS_COUNT; ++i)
              pthread_create(&g_thread[i], NULL, consume, (void*)i);
      sleep(1);

      for(i=0; i<PROCESS_COUNT; ++i)
              pthread_create(&g_thread[i+CONSUMERS_COUNT], NULL, produce, (void*)i);

      for(i=0; i<PROCESS_COUNT+CONSUMERS_COUNT; ++i)
               pthread_join(g_thread[i], NULL);
     
      pthread_mutex_destroy(&g_mutex);
      pthread_cond_destroy(&g_cond);
     return 0;
}
