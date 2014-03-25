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
struct list_node** temp;
struct sort_node *tmp_int;
struct sort_node *cur;
struct sort_node *root_int;
struct list_node{
  char* key;
  int value;
  struct list_node *next;
};
struct sort_node {
	int hash;
	int value;
	struct sort_node *next;
};
void* mapper_t(void *node);
struct list_node* mapper_p(char* key,FILE *fp);
#endif
