

gcc -g -c condition.c -o condition.o -lpthread 
gcc -g -c threadpool.c -o threadpool.o -lpthread -lrt
gcc -g threadpool.o condition.o main.c -o main -lpthread
