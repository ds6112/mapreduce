
#include "shuffle.h"
#include "mapper.h"
void* shuffle_i(void *tn){
    int id =(intptr_t) tn;
    struct list_node* tmp =temp[id];
    struct sort_node *tmp_int;
    struct sort_node *current;
    struct sort_node *InsertPointer;
    while(tmp->next!=NULL)
    {
        printf ("%i\n",tmp ->value);
        tmp_int=(struct sort_node*) malloc(sizeof(struct sort_node));
        tmp_int->value = atoi(tmp->key);
        tmp_int->hash = tmp->value;
        tmp_int->next = NULL;
        if (root_int != NULL)
        {   
            current=(struct sort_node*) malloc(sizeof(struct sort_node));
            current = root_int;
            
            if ( tmp_int -> value < root_int -> value )
            {
                tmp_int -> next = current;
                root_int = tmp_int;
            }
            
            else if ( tmp_int -> value > root_int -> value )
            {
                
                
                while ( (tmp_int -> value > current -> value) && ( current -> next != NULL ) )
                {
                    InsertPointer=(struct sort_node*) malloc(sizeof(struct sort_node));
                    InsertPointer = current;
                    current = current -> next;
                    
                }
                
                if ( (tmp_int -> value > current -> value) && ( current -> next == NULL ) )
                    current -> next = tmp_int;
                else
                {
                    InsertPointer -> next = tmp_int;
                    tmp_int -> next = current;
                }
            }
        }
        else
        {
            root_int = tmp_int;
        }
        tmp=tmp->next;
    }
    
}



