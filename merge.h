#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
int n;
int j;
struct list_node** temp;
void* merge_i(void *node);
void* merge_w(void *node);
#endif
