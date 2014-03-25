void* shuffle_i(void *tn){
    int id =(intptr_t) tn;
    struct list_node* tmp =temp[id];
    while(tmp->next!=NULL)
    {
        node *tempint = new node;
        tempint -> next = NULL;
        tempint -> key =tmp->value;
        tempint ->value = tmp ->key;
        
        // Check If There Is An Initial Record In the List
        if (rootint != NULL)
        {
            current = rootint;
            
            // temporary pointers location
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
                    // Set the insert location to the current location then change the current location to the next position
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
        // If there is no initial record assign the new record to the Root position
        else 
        {
            rootint = tempint;
        }
        
    }
}
}
