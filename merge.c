#include "merge.h"
#include "mapper.h"
void* merge(void *node)
{
	int i=(intptr_t) node;	
	struct list_node* node_l;
	struct list_node* node_r;
	struct list_node* current;
	if(i==(j-1-i))
	{
		node_l=temp[i-1];
		node_r=temp[(j-1-i)];
	}
	else
	{
		node_l=temp[i];
		node_r=temp[(j-1-i)];
	}

	while(1)
	{
		current = (struct list_node*) malloc(sizeof(struct list_node));
		current->key="1\0";
		current->value=node_r->value;

		if(current->value < temp[i]->value)
		{
			current->next=temp[i];
			temp[i]=current;
			node_l=temp[i];
		}

		else if(current->value >= node_l->value)
		{

			while(node_l->next != NULL && (current->value > node_l->next->value))
			{
				node_l=node_l->next;

			}
			current->next=node_l->next;
			node_l->next=current;
			

		}
		
		if(node_r->next==NULL)
			break;
		node_r=node_r->next;

	}
	
	
}