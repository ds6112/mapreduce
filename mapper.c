#include "mapper.h"
void* mapper_t(void *tn)
{ 
    int i=0,j=0;
    char c;
    char line_buffer[LINESIZE];
    char word_buffer[WORDSIZE];
    if(!fgets(line_buffer,sizeof(line_buffer),fp))
    {
            return;
    }
    int id =(intptr_t) tn;
    struct list_node* tmp =temp[id];
    /* Goto end of list */
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
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
            tmp->value=1;
            tmp->key=malloc(strlen(word_buffer));
            memcpy(tmp->key,&word_buffer,strlen(word_buffer));
            tmp->next=(struct list_node*) malloc(sizeof(struct list_node));
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
                tmp->value=1;
                tmp->key=malloc(strlen(word_buffer));
                memcpy(tmp->key,&word_buffer,strlen(word_buffer));
                memset(word_buffer, 0, sizeof(word_buffer));
                tmp->next=(struct list_node*) malloc(sizeof(struct list_node));
                tmp=tmp->next;
                j=0;
            }
        }
    }
}
void* mapper_p(void *tn)
{ 
    int i=0,j=0;
    char c;
    char line_buffer[LINESIZE];
    char word_buffer[WORDSIZE];
    int id =(intptr_t) tn;
    char* key = "1\0";
    while(fgets(line_buffer,sizeof(line_buffer),fp))
    {   i=0;
        j=0;
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
    if(fgets(line_buffer,sizeof(line_buffer),fp))
        return;
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

    if ( strncmp(ins -> key,temp[id]-> key,WORDSIZE) < 0 )
            {

    printf("%i\n",temp[id]->value);
                ins -> next = temp[id];
                temp[id] = ins;
            }
            
            else if ( strncmp(ins -> key,temp[id]-> key,WORDSIZE) >= 0 )
            {
                 
                
                while ( strncmp(ins -> key,temp[id]-> key,WORDSIZE) >= 0 && ( cur -> next != '\0' ) )
                {
                    insNode = cur;
                    cur = cur -> next;
                    
                }
                
                if ( strncmp(ins -> key,temp[id]-> key,WORDSIZE) >= 0 && ( cur -> next == '\0' ) )
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