#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

typedef long long int lld;

lipo* readlist()
{
    lipo* head = NULL;
    lipo* current = NULL;
    lld start = 0, end;
    printf("Load list (Format: start, end, builing, room). Set -1 as start and end for termination.\n");
    while(start != -1)
    {
        lipo* node = malloc(sizeof(lipo));
        node->m.building = malloc(50*sizeof(char));
        node->m.room = malloc(50*sizeof(char));
        
        scanf("%lld, %lld, %[^,], %[^\n]", &start, &end, node->m.building, node->m.room);
        node->m.start = start;
        node->m.end = end;
        if(start == -1)
        {
            free(node);
            break;
        }
        
        if(!head)
            current = head = node;
        else
            current = current->next = node;

    }
    printf("List loaded successfilly!\n");
    return head;
}

Meeting readMeeting()
{
    printf("Load meeting in format: start, end, builing, room\n");
    Meeting out;
    out.building = malloc(100*sizeof(char));
    out.room = malloc(100*sizeof(char));
    scanf("%lld, %lld, %[^,], %[^\n]", &out.start, &out.end, out.building, out.room);
    return out;
}

void insertbeg(Meeting elem, lipo** list)
{
    lipo* tmp = malloc(sizeof(lipo));
    tmp->m = elem;
    tmp->next = *list;
    *list = tmp;
    printf("Meeting inserted!\n");
}

void insertend(Meeting elem, lipo** list)
{
    lipo* tmp = malloc(sizeof(lipo));
    tmp->m = elem;
    tmp->next = NULL;
    if(!*list)
        *list = tmp;
    else
    {
        lipo* cnt = *list;
        while(cnt->next)
            cnt = cnt->next;
        cnt->next = tmp;
    }
    printf("Meeting inserted!\n");
}

void removebeg(lipo** list)
{
    lipo* tmp = *list;
    *list = (*list)->next;
    free(tmp);
    printf("Meeting removed!\n");
}

void removeend(lipo** list)
{
    if(*list)
    {
        lipo* cnt = *list;
        if(!cnt->next)
        {
            free(cnt);
            *list = NULL;
        }
        else
        {
            while(cnt->next->next)
                cnt = cnt->next;
            free(cnt->next);
            cnt->next = NULL;
        }
    }
    printf("Meeting removed!\n");
}

int cmpmeet(Meeting elem1,  Meeting elem2)
{
    return (elem1.end == elem2.end && elem1.start == elem2.start && !strcmp(elem1.building, elem2.building) && !strcmp(elem1.room, elem2.room));
}

void removespec(Meeting elem, lipo** list)
{
    if(list)
    {
        if(cmpmeet(elem, (*list)->m))
        {
            free(*list);
            *list = NULL;
        }
        else
        {
            lipo* cnt = *list;
            while(cnt->next)
            {
                while(cnt->next && !cmpmeet(elem, cnt->next->m))
                    cnt = cnt->next;
                if(cnt->next)
                {
                    lipo* tmp = cnt->next;
                    cnt->next = cnt->next->next;
                    free(tmp);
                }
            }
        }
    }
}

