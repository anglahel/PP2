#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void printlist(lipo* list)
{
    if(list)
    {
        lipo* node = list;
        while(node != NULL)
        {
            printf("start: %lld\t end: %lld\t building:%s room:%s\n", node->m.start, node->m.end, node->m.building, node->m.room);
            node = node->next;
        }
    }
    else
    {
        printf("No meetings today\n");
    }
    
}


