#include "mapreducer.h"
#include "mapper.h"
#include "shuffle.h"
void mapreduce(FILE *fp, struct options arg_opt)
{
	   /* Initializations */
    sem_init(&mutex, 0, 1);
    int i;
    int n=arg_opt.map_t;
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
    
   /* for (i=0;i<n;i++){
    pthread_create(&tidint[i],NULL,&shuffle_i,(void *) (intptr_t) i);
        pthread_join(tidint[i],NULL);}*/
    for(i=0;i<n;i++)
    {
    struct list_node* tmp =root[i];
    while (tmp->next !=NULL)
    {
        if(arg_opt.type)
        {
            printf("value: %i\n",tmp->value);
        }
        else
        {
            printf("value: %s\n",tmp->key); 
        }
        tmp =tmp->next;
    }
        if(arg_opt.type)
        {
            printf("value: %i\n\n",tmp->value);
        }
        else
        {
            printf("value: %s\n\n",tmp->key); 
        }
    }
/*
while (root_int!='\0')
{
 printf("Value is: %i\n",root_int->value);
 printf("Key is: %i\n",root_int->hash);
        root_int=root_int->next;
}*/

    for(i=0;i<n;i++)
    {
    struct list_node* tmp =root[i];
    struct list_node* old;
    /* WRITE LOGIC TO FREE KEY ONLY IN WORDCOUNT CASE */
    while(tmp->next!=NULL)
    {
        old = tmp;
        tmp=tmp->next;
        if(!arg_opt.type)
        {
        free(old->key);
        }
        free(old);
    }

    if(!arg_opt.type)
    {
    free(tmp->key);
    }

    free(tmp);
    }
    
sem_destroy(&mutex);
}
