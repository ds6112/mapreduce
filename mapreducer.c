#include "mapreducer.h"
#include "mapper.h"
#include "merge.h"
#include "helper.h"
#include "reduce.h"
#include <semaphore.h>
int j,n,m;
void mapreduce(FILE *fp, struct options arg_opt)
{
    /* Initializations */
sem_t reduceworkers;
	outputFile =fopen(arg_opt.printFile, "w");
    int i;
    n=arg_opt.map_t;
m= arg_opt.reduce_t;
sem_init(&reduceworkers, 0, m);
sem_init(&writeToFile, 0, 1);
    node_count=malloc(sizeof(int)*n);
    pthread_t tid[n];
	
    struct list_node* root[n];
    temp=root;
    /* Mapper function pointer array*/
    void* (mapper[2])={mapper_w,mapper_i};
    /* Allocate initial root*/
    for(i=0;i<n;i++)
    {
        root[i] = (struct list_node*) malloc(sizeof(struct list_node));
        bzero(root[i],sizeof(struct list_node));
    }
    i=0;
    /* Perform mapping with threads on file */
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
                break;

        }
    }
    
    /* Run a filter to remove all threads that have not been used */
    filter_list();
    /* Merge operation on structure */
    merge(arg_opt.type);
    /* Merge words together to perform count */
    if(!arg_opt.type)
    {
        combine_w();
    }

    /* Print function to view structure
     *
     * root_print(arg_opt.type);
     *
     */

	if (arg_opt.type)
	{reduce_i(root[0]);
	}
else
{
struct list_node* current=temp[0];
while (current->next !='\0'){
reduce_w(current->key,current->value);
current = current->next;
}
reduce_w(current->key,current->value);
}

    /* Free Memory */
    root_delete(arg_opt.type);

    
}
