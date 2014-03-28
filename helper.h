#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED
#include <stdlib.h>
int n;
struct list_node** temp;
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
void root_delete(int type);
#endif