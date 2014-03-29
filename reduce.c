#include "reduce.h"
#include "helper.h"

void* reduce_w(char* key, int value){
emitFinal(key,value);
}

void* reduce_i(struct list_node *integers){
while (integers->next!=NULL)
	emitFinal(" \0",integers->value);
emitFinal(" \0",integers->value);
}

void emitFinal(char* key, int value){
	sem_wait(&writeToFile);
	fprintf(outputFile, "%s %i\n", key, value);
    fflush(outputFile);
	sem_post(&writeToFile);
}
