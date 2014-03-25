void* shuffle_i(void *tn){
    int id =(intptr_t) tn;
    struct list_node* tmp =temp[id];
    while(tmp->next!=NULL)
    {
        
        tempint -> next = NULL;
        tempint -> key =tmp->value;
        tempint ->value = tmp ->key;
        
        if (rootint != NULL)
        {
            current = rootint;
            
            if ( tempint -> value < rootint -> value )
            {
                tempint -> next = current;
                rootint = tempint;
            }
            
            else if ( tempint -> value > root -> value )
            {
                list_node *InsertPointer = new node;
                
                while ( (tempint -> value > current -> value) && ( current -> next != NULL ) )
                {
                    InsertPointer = current;
                    current = current -> next;
                    
                }
                
                if ( (tempint -> value > current -> value) && ( current -> next == NULL ) )
                    current -> next = tempint;
                else
                {
                    InsertPointer -> next = temp;
                    temp -> next = current;
                }
            }
        }
        else 
        {
            rootint = tempint;
        }
        
    }
}
}
