#include "mapper_wc.h"
FILE *fp;
struct list_node** temp;
void* mapper_t(void *tn)
{ 
    int i=0,j=0;
    char c;
    char line_buffer[LINESIZE];
    char word_buffer[WORDSIZE];
    fgets(line_buffer,sizeof(line_buffer),fp);
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
        if(c=='\n')
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
struct list_node* mapper_p(char* key,FILE *fp){
    /*
     process which translates arbitrarily divided input up into key­value pairs (an
     example is reading a file chunk and generating word­count for that file chunk)
     */
    /* Create root node */
    struct list_node* root = (struct list_node*) malloc(sizeof(struct list_node));
    struct list_node* tmp = root;
    int i=0;
    char c;
    char buffer[64];
    while(1)
    {
        if((c=fgetc(fp))==EOF)
        {
            tmp->value=1;
            tmp->key=malloc(strlen(buffer));
            memcpy(tmp->key,&buffer,strlen(buffer));
            memset(buffer, 0, sizeof(buffer));
            break;
        }
        if(isalpha(c))
        {
            buffer[i]=tolower(c);
            i++;
        }
        else 
        {
            if(i>0)
            {
                tmp->value=1;
                tmp->key=malloc(strlen(buffer));
                memcpy(tmp->key,&buffer,strlen(buffer));
                tmp->next=(struct list_node*) malloc(sizeof(struct list_node));
                tmp=tmp->next;
                i=0;
                memset(buffer, 0, sizeof(buffer));
            }
        }
    }
    return root;

}