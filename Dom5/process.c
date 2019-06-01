#include "main.h"
#include <math.h>

DVDlist* mp2dvd(MPlist* inlist)
{
    double start = 0, end = 0;
    DVDlist *outlist = NULL, *curr = NULL;
    while(inlist)
    {
        DVDlist* node = malloc(sizeof(DVDlist));
        
        start += inlist->sub.wait;
        end = start + inlist->sub.duration;
        
        node->sub.start = round(start * FPS_NUM);
        node->sub.end = round(end * FPS_NUM);
        node->next = NULL;
        node->prev = NULL;
        node->sub.text = malloc(MAX_LEN*sizeof(char));
        strcpy(node->sub.text, inlist->sub.text);
 
        char* cnt = node->sub.text;
        while(*cnt != '\0')
        {
            if(*cnt == '\n')
                *cnt = '|';
            cnt++;
        }
        
        if(!outlist)
            outlist = curr = node;
        else
        {
            node->prev = curr;
            curr = curr->next = node;
        }

        start += inlist->sub.duration;

        inlist = inlist->next;
    }
    printf("Format converted successfully!\n");
    return outlist;
}

void movesub(MPlist* inlist, lld shift)
{
    double delta = (double)shift / 1000;
    while(1)
    {
        inlist->sub.wait += delta;
        if(inlist->sub.wait < 0)
        {
            inlist->sub.duration += inlist->sub.wait;
            inlist->sub.wait = 0;
            
            if(inlist->sub.duration < 0) inlist->sub.duration = 0;
            else break;
        }
        else
        {
            break;
        }
        inlist = inlist->next;
        
    }
    if(shift > 0)
        printf("Subtitle moved forward for %lld milliseconds!\n", shift);
    else
        printf("Subtitle moved backward for %lld milliseconds!\n", shift);

}

void freedvd(DVDlist* list)
{
    DVDlist* tmp = list;
    while(list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}


void freemp(MPlist* list)
{
    MPlist* tmp;
    while(list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

