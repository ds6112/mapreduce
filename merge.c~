#include "merge.h"
#include "helper.h"
void* merge_i(void *node)
{
	int i=(intptr_t) node;	
	struct list_node* node_l;
	struct list_node* node_r;
	struct list_node* current;
	if(i==(j-(i+1)))
	{
		node_l=temp[i-1];
		node_r=temp[(i)];
		i=i-1;
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

		if(temp[i]->value > current->value)
		{
			current->next=temp[i];
			temp[i]=current;
			node_l=temp[i];
		}
		else if (current->value >= node_l->value && current->value < node_l->next->value)
		{
			current->next=node_l->next;
			node_l->next=current;
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
void* merge_w(void *node)
{
	int i=(intptr_t) node;	
	struct list_node* node_l;
	struct list_node* node_r;
	struct list_node* current;
	if(i==(j-(i+1)))
	{
		node_l=temp[i-1];
		node_r=temp[(i)];
		i=i-1;
	}
	else
	{
		node_l=temp[i];
		node_r=temp[(j-1-i)];
	}

	
	while(1)
	{
		current = (struct list_node*) malloc(sizeof(struct list_node));
		current->key = malloc(strlen(node_r->key));
		strcpy(current->key,node_r->key);
		current->value=node_r->value;

		if(strcmp(current->key,temp[i]->key)<0)
		{
			current->next=temp[i];
			temp[i]=current;
			node_l=temp[i];
		}
		else if (strcmp(current->key,node_l->key)>= 0  && strcmp(current->key,node_l->next->key)<0)
		{
			current->next=node_l->next;
			node_l->next=current;
		}
		else if(strcmp(current->key,node_l->key)>= 0)
		{

			while(node_l->next != NULL && (strcmp(current->key,node_l->next->key)>0))
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