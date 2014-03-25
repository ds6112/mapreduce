#include "mapreducer.h"
#include "mapper.h"
#include "shuffle.h"
void mapreduce(FILE *fp, struct options arg_opt)
{
	   /* Initializations */
    int i;
    int n=arg_opt.map_t;
    pthread_t tid[n];
	pthread_t tidint[n];
    struct list_node* root[n];
    /* Allocate initial */
    
    for(i=0;i<n;i++)
    {
        root[i] = (struct list_node*) malloc(sizeof(struct list_node));
    }
    /* Allocate temp int*/
    root_int=(struct sort_node*) malloc(sizeof(struct sort_node));
    i=0;
    
    temp=root;

    while(!feof(fp))
    {
        pthread_create(&tid[i],NULL,&mapper_t,(void *) (intptr_t) i);
        pthread_join(tid[i],NULL);
	    pthread_create(&tidint[i],NULL,&shuffle_i,(void *) (intptr_t) i);
        pthread_join(tidint[i],NULL);
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
while (root_int->next!=NULL)
{
 printf("%s\n",root_int->value);
        root_int=root_int->next;
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

}
