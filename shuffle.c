
#include "shuffle.h"
#include "mapper.h"
void* shuffle_i(void *tn){
    int id =(intptr_t) tn;
    struct list_node* tmp =temp[id];
    while(tmp->next!=NULL){
    printf ("%i\n",tmp ->value);
    tempint->hash=tmp->value;
    printf("%i\n",atoi(tmp->key));
    tmp =tmp->next;
}




    /*while(tmp->next!=NULL)
    {
         printf ("%i\n",tmp ->value);

       
        tempint->hash = tmp->value;
        printf ("%i\n",tmp ->value);
        tempint->value = atoi(tmp ->key);

  printf ("%i\n",tmp ->value);
  printf ("%i\n",tempint ->value);
        if (rootint != NULL)
        {
            current = rootint;
            
            if ( tempint -> value < rootint -> value )
            {
                tempint -> next = current;
                rootint = tempint;
            }
            
            else if ( tempint -> value > rootint -> value )
            {
                struct list_node *InsertPointer;
                
                while ( (tempint -> value > current -> value) && ( current -> next != NULL ) )
                {
                    InsertPointer = current;
                    current = current -> next;
                    
                }
                
                if ( (tempint -> value > current -> value) && ( current -> next == NULL ) )
                    current -> next = tempint;
                else
                {
                    InsertPointer -> next = tempint;
                    tempint -> next = current;
                }
            }
        }
        else 
        {
            rootint = tempint;
        }
        
    }
    */
}

