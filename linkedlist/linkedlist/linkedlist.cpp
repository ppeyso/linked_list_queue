#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

//#define NULL 0
uint32_t size;

typedef struct buffer_t
{
    
    void* ptr;
    struct buffer_t* next;

}buffer_t;

buffer_t* buff_last(buffer_t* head)
{
    buffer_t* itr = head;

    while (itr->next != NULL)
    {
        itr = itr->next;
    }

    return itr;
}

buffer_t* buff_create(void)
{
    buffer_t* root = (buffer_t*)malloc(sizeof(buffer_t));
    root->next = NULL;
    root->ptr = NULL;
    size = 1;
    return root;
}

void buff_append(buffer_t** head, void* ptr)
{   
    if( *head == NULL)
    {
     *head = buff_create();
    }
    if ((*head)->ptr == NULL)
    {
        (*head)->ptr = ptr;
        return;
    }
    else
    {
        buffer_t* itr = buff_last(*head);
        buffer_t* Nelem = (buffer_t*)malloc(sizeof(buffer_t));
        
        /// insert new element 
        Nelem->next = NULL;
        Nelem->ptr = ptr;
        itr->next = Nelem;
        size++;

    }



}

void* buf_top(buffer_t* head)
{
    if (head != NULL)
        return (head->ptr);
    else
        return NULL;

}


void buff_pop(buffer_t** head)
{
    buffer_t* itr = *head;
    *head = itr->next;
    free(itr);
    size--;

}


void buff_print(buffer_t** root)
{
    uint32_t temp;
    while (*root != NULL)
    {
        temp = *(uint32_t*)(buf_top(*root));
        printf("val:%d\r\n", temp);
        buff_pop(root);
    }
}



buffer_t* root = NULL;
uint32_t x = 1, y = 2, z = 3,h=4;

int main()
{

    
    buff_append(&root, &x);
    buff_append(&root, &y);
    buff_append(&root, &z);
    buff_print(&root);
    buff_append(&root, &h);
    buff_print(&root);
}
