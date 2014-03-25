#ifndef MAPREDUCER_H_INCLUDED
#define MAPREDUCER_H_INCLUDED
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
struct options{
    int type;
    int map_t;
    int reduce_t;
};
void mapreduce(FILE *fp, struct options arg_opt);
#endif