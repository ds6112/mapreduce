#include "mapreducer.h"
#include "mapper.h"
#include "merge.h"
#include "helper.h"
int n;
int j;
void mapreduce(FILE *fp, struct options arg_opt)
{
	   /* Initializations */
    sem_init(&mutex, 0, 1);
    int i;
    n=arg_opt.map_t;
    node_count=malloc(sizeof(int)*n);
    pthread_t tid[n];
	pthread_t tidint[n];
    struct list_node* root[n];
    temp=root;
    /* function pointer array*/
    void* (mapper[2])={mapper_w,mapper_i};
    /* Allocate initial */
    
    for(i=0;i<n;i++)
    {
        root[i] = (struct list_node*) malloc(sizeof(struct list_node));
        bzero(root[i],sizeof(struct list_node));
    }
    i=0;

    /* Allocate temp int*/
    /*
    while(!feof(fp))
    {
        pthread_create(&tid[i],NULL,mapper[arg_opt.type],(void *) (intptr_t) i);
        pthread_join(tid[i],NULL);  
        i++;
        if(i==(n))
        {
            i=0;
        }
    }
    */
    // BETTER IMPLEMENTATION -> CHECK IF THIS WORKS IN ALL CASES? ANY BUGS?
    while(!feof(fp))
    {
        for(i=0;i<n;i++)
        {
        pthread_create(&tid[i],NULL,mapper[arg_opt.type],(void *) (intptr_t) i);
        }
        for(i=0;i<n;i++)
        {
        pthread_join(tid[i],NULL);
        if(feof(fp))
        {
            break;
        }

        }
    }
    
/*
while (root_int!='\0')
{
 printf("Value is: %i\n",root_int->value);
 printf("Key is: %i\n",root_int->hash);
        root_int=root_int->next;
}*/
    j=n;
    pthread_t td;
    while(j>1)
    {
    for(i=0;i<(j+1)/2;i++)
    {

    pthread_create(&tid[i],NULL,&merge_i,(void *) (intptr_t) i);

    }
    for(i=0;i<(j+1)/2;i++)
    {

    pthread_join(tid[i],NULL);  

    }
 
    j=(j)/2;
    }
    root_print(arg_opt.type);
    //struct list_node* tmp =root[0];
    /*while (tmp->next !=NULL)
    {
        printf("%i\n",tmp->value);
        tmp=tmp->next;
    }*/
    root_delete(arg_opt.type);

    

    // end merge
    

    
}
