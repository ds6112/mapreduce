
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include "mapreducer.h"
FILE *fp;


int main(int argc, const char * argv[]){
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
    fp=fopen(argv[optind],"r");
    
    
    int i,n=14;
    /* flag array for ints */
    flag_array=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        flag_array[i]=0;
    }
    
    struct options arg_opt;
    arg_opt.map_t=mname;
    arg_opt.reduce_t=rname;
    optind++;
    arg_opt.printFile=argv[optind];
    if (strcmp(aname, "sort")==0)
        arg_opt.type=1;
    else
        arg_opt.type=0;
    if (strcmp(iname,"threads")==0)
        arg_opt.apptype = 0;
    else
    {
        perror("Process not implemented.");
        exit(0);
    }
    /* type 0 is wc, 1 is integer*/
    
    
    mapreduce(fp,arg_opt);
    free(flag_array);
    
    return 0;
}
