
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include "mapreducer.h"
#include "shuffle.h"
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
    int n=1;
    struct options arg_opt;
    arg_opt.map_t=n;
    fp=fopen("example.txt","r");
    
    mapreduce(fp,arg_opt);
 

    return 0;
}
