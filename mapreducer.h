#ifndef MAPREDUCER_H_INCLUDED
#define MAPREDUCER_H_INCLUDED
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
int *flag_array;
struct options{
    int type;
    int map_t;
    int reduce_t;
int apptype;
    char *printFile;
};
sem_t mutex;
void mapreduce(FILE *fp, struct options arg_opt);
#endif
