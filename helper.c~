#include "helper.h"
#include "mapper.h"
#include "merge.h"
void root_delete(int type)
{
	int i;
    /* Iterate through list and free depending on type */
    for(i=0;i<n;i++)
    {
	    struct list_node* tmp =temp[i];
	    struct list_node* old;

    while(tmp->next!=NULL)
    {
        old = tmp;
        tmp=tmp->next;
        if(!type)
        {
        free(old->key);
        }
        free(old);
    }

    if(!type)
    {
    	free(tmp->key);
    }

   		free(tmp);
    }
}
void root_print(int type)
{
	int i;
    /* Iterate through list and print depending on type */
    for(i=0;i<n;i++)
    {
    struct list_node* tmp =temp[i];
    while (tmp->next !=NULL)
    {
        if(type)
        {
            printf("value: %i\n",tmp->value);
        }
        else
        {
            printf("value: %s,%i \n",tmp->key,tmp->value); 
        }
        tmp =tmp->next;
    }
        if(type)
        {
            printf("value: %i\n\n",tmp->value);
        }
        else
        {
            printf("value: %s,%i \n\n",tmp->key,tmp->value); 
        }
    }
}
void filter_list()
{
    /* Remove NULL thread returns */
    int i,c=0;
    for(i=0;i<n;i++)
    {
    struct list_node* tmp =temp[i];
    if(tmp->key==NULL)
    {
        c++;
        free(tmp);
    }

    }
    n=n-c;
}
void merge(int type)
{
    void* (merge[2])={merge_w,merge_i};
    j=n;
    int i;
    pthread_t tid[n];
    /* Multi-threaded simulatenous merge of sorted lists*/
    while(j>1)
    {
        for(i=0;i<(j+1)/2;i++)
        {

            pthread_create(&tid[i],NULL,merge[type],(void *) (intptr_t) i);

        }

        for(i=0;i<(j+1)/2;i++)
        {

            pthread_join(tid[i],NULL);  

        }
 
        j=(j)/2;
    }
}
void combine_w()
{
    struct list_node* tmp;
    struct list_node* cur;
    cur=temp[0];
    /* Combine same words  and increment count */
    while(cur->next!=NULL)
    {
        while(strcmp(cur->key,cur->next->key)==0)
        {
            tmp=cur->next;
            cur->next=tmp->next;
            cur->value++;
            free(tmp->key);
            free(tmp);
        }
        cur=cur->next;
    }
}