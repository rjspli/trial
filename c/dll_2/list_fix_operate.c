#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _elem{
    char name[21];
    int age;
    int num;
} Elem;

typedef struct _list
{
    struct _list *prev;
    struct _list *next;
    Elem *data;
} List;

List *head, *tail;

int insert_one_list(char* input_name, int input_age, int input_num)
{
    List *dummy;
    Elem *content;

    List *curr_target;

    dummy = (List*)malloc(sizeof(List));
    memset(dummy, 0, sizeof(List));

    content = (Elem*)malloc(sizeof(Elem));
    memset(content, 0, sizeof(content));
    strncpy(content->name, input_name, sizeof(char) * 21);
    content->age = input_age;
    content->num = input_num;
    dummy->data = content;

    if(head)
    {
        curr_target = head;  //not head->next
    }else
    {
        return 0;
    }

    do{
        if(tail != curr_target->next)
        {
            curr_target = curr_target->next;
            continue;
        }
        else
        {
            dummy->prev = curr_target;  //need treat dummy
            dummy->next = tail;         //need treat dummy
            curr_target->next = dummy;
            tail->prev = dummy;
            break;
        }
    }while(1);

    return 0;
}

int print_all_list()
{
    List *curr_target;

    if(head)
    {
        curr_target = head;  //not head->next
    }else
    {
        return 0;
    }

    do{
        if(tail != curr_target->next)
        {
            curr_target = curr_target->next;
            if(curr_target->data)
            {
                printf("display: (%s) (%d) (%d)\n"
                    , curr_target->data->name, curr_target->data->age, curr_target->data->num);
            }
            continue;
        }
        else
        {
            break;
        }
    }while(1);

    return 0;
}

List* create_head_tail()
{
    List *dummy;
    dummy = (List*)malloc(sizeof(List));
    memset(dummy, 0, sizeof(List));

    return dummy;
}

int release_all_list()
{
    List *curr_target, *prev_target;

    int i = 0;

    if(head)
    {
        curr_target = head;
    }

    do{
        if(tail != curr_target->next)
        {
            printf("exist %d\n", ++i);
            prev_target = curr_target;
            curr_target = curr_target->next; // prior execute cause effect of (1)
            if(prev_target->data)
            {
                free(prev_target->data);
            }   
            free(prev_target);  //(1)changed ->next after free

            continue;
        }
        else{
            if(curr_target->data)
            {
                free(curr_target->data);
            } 
            free(curr_target);

            free(tail);
            printf("reach end !!!\n");
            break;
        }
    }while(1);

    return 0;
}

#if 0
int release_all_list()
{
    List *curr_target, *prev_target;

    int i = 0;

    if(head)
    {
        curr_target = head->next;
        free(head);
    }

    do{
        if(!curr_target)
        {
            break;
        }
        else
        {
            if(tail != curr_target)
            {
                printf("exist %d\n", ++i);
            }
            else{
                printf("tail !!!\n");
            }
            prev_target = curr_target;
            curr_target = curr_target->next;
            if(prev_target->data)
            {
                free(prev_target->data);
            }
            free(prev_target);
        }
    }while(1);

    return 0;
}
#endif

int main(int argc, char* argv[])
{

    head = create_head_tail();
    tail = create_head_tail();

    head->next = tail;
    tail->prev = head;

    insert_one_list("dog", 10, 1);
    insert_one_list("cat", 13, 2);

    print_all_list();

    release_all_list();

    return 0;
}
