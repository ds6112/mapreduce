#include "mapper.h"
void* mapper_w(void *tn)
{ 
    int i=0,j=0;
    char c;
    char line_buffer[LINESIZE];
    char word_buffer[WORDSIZE];
    
    int id =(intptr_t) tn;
    if(!fgets(line_buffer,sizeof(line_buffer),fp))
    {
            return;
    }
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
            key=malloc(strlen(word_buffer)+1);
            bzero(key, strlen(key));
            memcpy(key, word_buffer, j);

            emit(key, 1, id);
            memset(word_buffer, 0, sizeof(word_buffer));
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
            key=malloc(strlen(word_buffer)+1);

            bzero(key, strlen(key));
            memcpy(key, word_buffer, j);
            emit(key, 1, id);

            memset(word_buffer, 0, sizeof(word_buffer));
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
    if(!fgets(line_buffer,sizeof(line_buffer),fp))
    {
            return;
    }
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
            memset(word_buffer, 0, sizeof(word_buffer));
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
                memset(word_buffer, 0, sizeof(word_buffer));
                j=0;
            }
        }
    }
   

}

void emit(char* key, int value, int id){
struct list_node *insNode; 
struct list_node *cur =temp[id];
struct list_node *ins =(struct list_node*) malloc(sizeof(struct list_node)); 
ins->value = value;
ins->key = key;
ins->next =NULL;
if (temp[id]->key=='\0')
    temp[id]=ins;
else
{

    if ( strcmp(key,temp[id]-> key) < 0 )
            {
                ins -> next = temp[id];
                temp[id] = ins;
                printf("%s\n",ins->key);
            
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
                        printf("%s\n",ins->key);
                    }
                else
                    {
                        insNode -> next = ins;
                        printf("%s\n",ins->key);
                        ins -> next = cur;
                    }
            }

}
}