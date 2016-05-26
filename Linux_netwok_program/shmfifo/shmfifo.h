#ifndef _SHM_FIFO_H_
#define _SHM_FIFO_H_

#include "ipc.h"


struct shmhead
{
       unsigned int blksize;  //块大小
       unsigned int blocks;   //总块数
       unsigned int rd_index;  //读索引
       unsigned int wr_index;  // 写索引 
};

typedef struct shmhead shmhead_t;

struct shmfifo
{
           shmhead_t *p_shm;  // 共享内存头部指针
	   char *p_payload;   //有效负载的起始地址
	   
	   int shmid;         //共享内存头部指针id
	   int sem_mutex;     //互斥的信号量
	   int sem_full;      //用来控制共享内存是否满的信号量
	   int sem_empty;      //用来控制共享内存是否空的信号量
};

typedef struct shmfifo shmfifo_t;


shmfifo_t *shmfifo_init(int key, int blksize, int blocks);
void shmfifo_put(shmfifo_t *fifo, const void *buf);
void shmfifo_get(shmfifo_t *fifo, void *buf);
void shmfifo_destroy(shmfifo_t *fifo);

#endif
