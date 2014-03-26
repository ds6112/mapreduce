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
    /* Allocate initial */
    
    for(i=0;i<n;i++)
    {
        root[i] = (struct list_node*) malloc(sizeof(struct list_node));
        bzero(root[i],sizeof(struct list_node));
    }
    /* Allocate temp int*/

    i=0;
    
    temp=root;

    while(!feof(fp))
    {
        pthread_create(&tid[i],NULL,&mapper_p,(void *) (intptr_t) i);
        pthread_join(tid[i],NULL);
	    
        i++;
        if(i==(n))
        {
            i=0;
        }
    }
   /* for (i=0;i<n;i++){
    pthread_create(&tidint[i],NULL,&shuffle_i,(void *) (intptr_t) i);
        pthread_join(tidint[i],NULL);}*/
    printf("test\n");
    for(i=0;i<n;i++)
    {
    struct list_node* tmp =root[i];
    while (tmp->next !='\0')
    {
        tmp =tmp->next;
        printf("value: %i\n",tmp->value);
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
    while(tmp->next!=NULL)
    {
        old = tmp;
        tmp=tmp->next;
        free(old);
    }
    free(tmp);
    }
    for(i=0;i<n;i++)
    {
    struct sort_node* tmp =root_int;
    /*while(tmp->next!=NULL)
    {
        free(tmp->key);
        old = tmp;
        tmp=tmp->next;
        free(old);
        printf("seg2\n");
    }*/
    free(tmp);
    }
sem_destroy(&mutex);
}
