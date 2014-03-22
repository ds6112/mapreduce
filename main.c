
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

struct options{
    int inputtype;
    int mapthreads;
    int reducethreads;
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

void mapper(string key,string value){
    /*
     process which translates arbitrarily divided input up into key­value pairs (an
     example is reading a file chunk and generating word­count for that file chunk)
     */
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
    /*
     extern char *optarg;
     extern int optind;
     int c, err = 0;
     int aflag=0, iflag=0, mflag=0, rflag=0;
     char *aname, *iname, *mname, *rname;
     static char usage[] = "usage: %s -a [wordcount, sort] -i [procs, threads] -m num_maps -r num_reduces infile outfile\n";
     
     while ((c = getopt(argc, argv, "a:i:m:r:")) != -1)
     switch (c) {
     case 'a':
     aflag = 1;
     aname = optarg;
     break;
     case 'i':
     iflag = 1;
     iname = optarg;
     break;
     case 'm':
     mflag = 1;
     mname = atoi(optarg);
     break;
     case 'r':
     rflag = 1;
     rname = atoi(optarg);
     break;
     case '?':
     err = 1;
     break;
     }
     
     if (aflag == 0||iflag == 0||mflag == 0||rflag == 0) {
     fprintf(stderr, "%s: missing option\n", argv[0]);
     fprintf(stderr, usage, argv[0]);
     exit(1);
     } else if ((optind+2) > argc) {
     printf("optind = %d, argc=%d\n", optind, argc);
     fprintf(stderr, "%s: missing input/output files\n", argv[0]);
     fprintf(stderr, usage, argv[0]);
     exit(1);
     } else if (err) {
     fprintf(stderr, usage, argv[0]);
     exit(1);
     } else if ((strncmp(aname, "sort", strlen(aname)) != 0 )&& (strncmp(aname, "wordcount", strlen(aname)) != 0)){
     fprintf(stderr, usage, argv[0]);
     exit(1);
     } else if ((strncmp(iname, "procs", strlen(iname)) != 0 )&& (strncmp(iname, "threads", strlen(iname)) != 0)){
     fprintf(stderr, usage, argv[0]);
     exit(1);
     }   else if (mname == 0 || rname == 0 ){
     fprintf(stderr, usage, argv[0]);
     exit(1);
     }
     if (optind < argc)
     for (; optind < argc; optind++)
     printf("argument: \"%s\"\n", argv[optind]);
     else {
     printf("no arguments left to process\n");
     }
     */
    FILE *filepointer;
    filepointer = fopen("example.txt","r");
    struct options mapredopt;
    mapredopt.inputtype = 0;
    mapredopt.mapthreads = 1;
    mapredopt.reducethreads = 1;
    mapreducer(filepointer, &mapredopt);
    fclose(filepointer);
   	exit(0);
}
