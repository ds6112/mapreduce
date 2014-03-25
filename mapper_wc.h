#ifndef WHATEVER_H_INCLUDED
#define WHATEVER_H_INCLUDED
#define LINESIZE 4096
#define WORDSIZE 256
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
void* mapper_t(void *node);
struct list_node* mapper_p(char* key,FILE *fp);
#endif