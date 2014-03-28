#include "mapper.h"
pthread_mutex_t f_mutex = PTHREAD_MUTEX_INITIALIZER;
void* mapper_w(void *tn)
{ 
    int i=0,j=0;
    char c;
    char line_buffer[LINESIZE];
    char word_buffer[WORDSIZE];
    
    int id =(intptr_t) tn;
    pthread_mutex_lock(&f_mutex);
    if(!fgets(line_buffer,sizeof(line_buffer),fp))
        return;
    while(line_buffer[0]=='\n')
    {
        bzero(line_buffer,sizeof(line_buffer));
        if(!fgets(line_buffer,sizeof(line_buffer),fp))
        return;
    }
    pthread_mutex_unlock(&f_mutex);
    while(i<LINESIZE)
    {
        c=line_buffer[i];
        i++;
        /* End of line, store final word*/
        if(c=='\n' || c=='\0')
        {
            if(strlen(word_buffer)==0)
            {
                break;
            }
            char *key;
            key=calloc(1,strlen(word_buffer)+1);
            memcpy(key, word_buffer, j);

            emit(key, 1, id);
            bzero(word_buffer,sizeof(word_buffer));
            break;
        }
        /* Store alphabetical characters & convert to lower case */
        if(isalpha(c) || isdigit(c))
        {
            
            if(isalpha(c))
            {
                c=tolower(c);
            }
            
            word_buffer[j]=c;
            j++;
        }
        else
        {
            /* When non alphabetical character occurs, dump buffer if we have a word */
            if(j>0)
            {
                if(strlen(word_buffer)==0)
                {
                     break;
                }
                char *key;
            key=calloc(1,strlen(word_buffer)+1);
            memcpy(key, word_buffer, j);
            emit(key, 1, id);
            bzero(word_buffer,sizeof(word_buffer));
            j=0;
            }
        }
    }

}
void* mapper_i(void *tn)
{ 
    int i=0,j=0;
    char c;
    char line_buffer[LINESIZE];
    char word_buffer[WORDSIZE];
    int id =(intptr_t) tn;
    char* key = "1\0";
    pthread_mutex_lock(&f_mutex);
    if(!fgets(line_buffer,sizeof(line_buffer),fp))
        return;
    pthread_mutex_unlock(&f_mutex);
    while(i<LINESIZE)
    {   
        c=line_buffer[i];
        i++;
        /* End of line, store final word*/
        if(c=='\n' || c=='\0')
        {
            if(strlen(word_buffer)==0)
            {
                break;
            }
            emit(key,atoi(word_buffer), id);
            bzero(word_buffer,sizeof(word_buffer));
            break;
        }
        /* Store alphabetical characters & convert to lower case */
        if(isdigit(c))
        {
            word_buffer[j]=c;
            j++;
        }
        else
        {
            /* When non alphabetical character occurs, dump buffer if we have a word */
            if(j>0)
            {
                if(strlen(word_buffer)==0)
                {
                     break;
                }
                emit(key, atoi(word_buffer), id);
                bzero(word_buffer,sizeof(word_buffer));
                j=0;
            }
        }
    }
    
}

void emit(char* key, int value, int id){
struct list_node *insNode; 
struct list_node *cur =temp[id];
struct list_node *ins =(struct list_node*) malloc(sizeof(struct list_node)); 
node_count[id]++;
ins->value = value;
ins->key = key;
ins->next =NULL;
if(key=="1\0")
{
if(temp[id]->next == NULL && flag_array[id]==0)
{
    temp[id]->key=key;
    temp[id]->value=value;
    flag_array[id]=1;
    free(ins);

}
else
{
if ( value < temp[id]->value )
{
    ins -> next = temp[id];
    temp[id] = ins;

}
else if ( value >= temp[id]->value )
{

    while ( value >= cur->value && ( cur -> next != NULL ) )
    {
        insNode = cur;
        cur = cur -> next;

    }

    if ( value >= cur->value && ( cur -> next == NULL ) )
    {
        cur -> next = ins;
    }
    else
    {
        insNode -> next = ins;
        ins -> next = cur;
    }

}
}
}
else{
if (temp[id]->key==NULL  )
{
    temp[id]->key=key;
    temp[id]->value=value;
    free(ins);
}
else
{

    if ( strcmp(key,temp[id]-> key) < 0 )
            {
                ins -> next = temp[id];
                temp[id] = ins;
            
            }
            
    else if ( strcmp(key,temp[id]-> key) >= 0 )
            {
                 
                
                while ( strcmp(key,cur-> key) >= 0 && ( cur -> next != '\0' ) )
                {
                    insNode = cur;
                    cur = cur -> next;
                    
                }
                
                if ( strcmp(key,cur-> key) >= 0 && ( cur -> next == '\0' ) )
                    {
                        cur -> next = ins;
                    }
                else
                    {
                        insNode -> next = ins;
                        ins -> next = cur;
                    }
            }

}
}
}