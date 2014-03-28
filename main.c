
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include "mapreducer.h"
FILE *fp;

/*
void mapreducer();
void mapper();
void shuffle();
void reducer();
 */
/*
void mapreducer(FILE *filepointer, struct options *mapredopt){
    /*
     parent controller which creates threads and coordinates stages of the pipeline
     
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
*/


int main(int argc, const char * argv[]){
   
    int i,n=14;
    /* flag array for ints */
    flag_array=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        flag_array[i]=0;
    }

    struct options arg_opt;
    arg_opt.map_t=n;
    arg_opt.type=1;
    /* type 0 is wc, 1 is integer*/
    fp=fopen("example_i.txt","r");
    
    mapreduce(fp,arg_opt);
    free(flag_array);

    return 0;
}
