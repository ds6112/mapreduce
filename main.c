
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include "mapper_wc.h"
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
FILE *fp;
struct list_node** temp;
struct options{
    int inputtype;
    int mapthreads;
    int reducethreads;
};
struct list_node{
  char* key;
  int value;
  struct list_node *next;
};
/*
void mapreducer();
void mapper();
void shuffle();
void reducer();
 */
void mapreducer(FILE *filepointer, struct options *mapredopt){
    /*
     parent controller which creates threads and coordinates stages of the pipeline
     */
    int token;
    int numberofmaps =mapredopt->mapthreads;
    int numberoflines = 0;
    
    while ( (token=fgetc(filepointer)) != EOF ) {
        if ( token == '\n' )
            numberoflines++;
    }
    int sizeofmap = numberoflines/numberofmaps;
    int lastmapsize = numberoflines-sizeofmap*(numberofmaps-1);
    
    printf("%i lines\n", lastmapsize);
    printf("%i lines\n", mapredopt->mapthreads);
}


void shuffle(){
    /*
     process which restructures the unordered key­value outputs of the mapper
     into a map of key­>set of values required by the reducer (in the word counting example,
     taking all separate word­counts from the input files and re­organizing by word­count)
     */
}
void reducer(){
    /*
     process which takes the key­set of values and creates a single key­value
     output (sum up the counts for each word and output a single word­count for all files)
     */
}
int main(int argc, const char * argv[]){
    fp=fopen("example.txt","r");
    /* Initializations */
    int i;
    int n=10;
    pthread_t tid[n];
    struct list_node* root[n];
    /* Allocate initial */
    
    for(i=0;i<n;i++)
    {
        root[i] = (struct list_node*) malloc(sizeof(struct list_node));
    }
    
    i=0;
    temp=root;
    while(!feof(fp))
    {
        pthread_create(&tid[i],NULL,&mapper_t,(void *) (intptr_t) i);
        pthread_join(tid[i],NULL);
        i++;
        if(i==(n))
        {
            i=0;
        }
    }
    for(i=0;i<n;i++)
    {
    struct list_node* tmp =root[i];
    while(tmp->next!=NULL)
    {
        printf("%s\n",tmp->key);
        tmp=tmp->next;
    }
    }

    for(i=0;i<n;i++)
    {
    struct list_node* tmp =root[i];
    struct list_node* old;
    while(tmp->next!=NULL)
    {
        free(tmp->key);
        old = tmp;
        tmp=tmp->next;
        free(old);
    }
    free(tmp);
    }

    return 0;
}
