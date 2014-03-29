#ifndef REDUCE_H_INCLUDED
#define REDUCE_H_INCLUDED
#define LINESIZE 4096
#define WORDSIZE 256
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"
void* reduce_w(char* key, int value);
void* reduce_i(struct list_node *integers);
sem_t writeToFile;
FILE *outputFile;
void emitFinal(char* key, int value);
#endif
