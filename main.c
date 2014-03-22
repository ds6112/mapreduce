
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>

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
struct list_node* mapper(char* key,FILE *fp){
    /*
     process which translates arbitrarily divided input up into key­value pairs (an
     example is reading a file chunk and generating word­count for that file chunk)
     */
    /* Create root node */
    struct list_node* root = (struct list_node*) malloc(sizeof(struct list_node));
    struct list_node* tmp = root;
    int i=0;
    char c;
    char buffer[64];
    while(1)
    {
        if((c=fgetc(fp))==EOF)
        {
            tmp->value=1;
            tmp->key=malloc(strlen(buffer));
            memcpy(tmp->key,&buffer,strlen(buffer));
            memset(buffer, 0, sizeof(buffer));
            break;
        }
        if(isalpha(c))
        {
            buffer[i]=tolower(c);
            i++;
        }
        else 
        {
            if(i>0)
            {
                tmp->value=1;
                tmp->key=malloc(strlen(buffer));
                memcpy(tmp->key,&buffer,strlen(buffer));
                tmp->next=(struct list_node*) malloc(sizeof(struct list_node));
                tmp=tmp->next;
                i=0;
                memset(buffer, 0, sizeof(buffer));
            }
        }
    }
    return root;

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
    FILE *fp;
    fp=fopen("example.txt","r");
    struct list_node* root =mapper("test",fp);
    printf("%s\n",root->key);
    return 0;
}
