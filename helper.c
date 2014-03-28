#include "helper.h"
#include "mapper.h"
void root_delete(int type)
{
	int i;
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
            printf("value: %s\n",tmp->key); 
        }
        tmp =tmp->next;
    }
        if(type)
        {
            printf("value: %i\n\n",tmp->value);
        }
        else
        {
            printf("value: %s\n\n",tmp->key); 
        }
    }
}