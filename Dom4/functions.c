#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void freelist(lipo* list)
{
    lipo* prev = NULL;
    while(!list)
    {
        prev = list;
        list = list->next;
        free(prev);
    }
}

void sortlist(lipo* list)
{
    if(list)
    {
        for(lipo* cnt1 = list; cnt1->next; cnt1 = cnt1->next)
            for(lipo* cnt2 = cnt1->next; cnt2; cnt2=cnt2->next)
                if(cnt1->m.start > cnt2->m.start)
                {
                    Meeting tmp = cnt1->m;
                    cnt1->m = cnt2->m;
                    cnt2->m = tmp; 
                }
    }
    else
       printf("Nothing to sort!\n");
}

lipo* createschedule(lipo* list)
{
    int currend = -1;
    lipo* schedule = NULL;
    lipo* curr = NULL;
     
    if(list)
    {
       while(list)
        {
            if(list->m.start >= currend)
            {
                lipo* new = malloc(sizeof(lipo));
                new->m = list->m;
                new->next = NULL;
                if(!schedule)
                {
                    curr = schedule = new;
                }
                else
                {
                    curr = curr->next = new;
                }
                currend = list->m.end;
            }
            list = list->next;
        }
    }
    else
    {
        printf("No meeting today -> can't create schedule!\n");
    }
    return schedule;
}


