#ifndef MAPPER_H_INCLUDED
#define MAPPER_H_INCLUDED
#define LINESIZE 4096
#define WORDSIZE 256
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
FILE *fp;
int n;
int *flag_array;
int *node_count;
struct list_node** temp;
struct sort_node *root_int;
void* mapper_w(void *node);
void* mapper_i(void *node);
void emit(char* key, int value, int id);
#endif
