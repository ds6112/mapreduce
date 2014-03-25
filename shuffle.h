#ifndef SHUFFLE_H_INCLUDED
#define SHUFFLE_H_INCLUDED
#define LINESIZE 4096
#define WORDSIZE 256
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
void* shuffle_i(void *node);

#endif
