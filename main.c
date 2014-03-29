
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include "mapreducer.h"
FILE *fp;
int main(int argc, const char * argv[]){
   
    int i,n=211;
    /* flag array for ints */
    flag_array=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        flag_array[i]=0;
    }

    struct options arg_opt;
    arg_opt.map_t=n;
    arg_opt.type=0;
    /* type 0 is wc, 1 is integer*/
    fp=fopen("example_wc.txt","r");
    
    mapreduce(fp,arg_opt);
    free(flag_array);

    return 0;
}
