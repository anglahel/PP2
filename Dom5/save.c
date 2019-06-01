#include "main.h"

void printmp(MPlist* list)
{
    while(list)
    {
        printf("%lf\t%lf\n", list->sub.wait, list->sub.duration);
        printf("%s", list->sub.text);
        printf("\n\n");
        list = list->next;
    }
}

void printdvd(DVDlist* list)
{
    while(list)
    {
        printf("%lld\t%lld\n", list->sub.start, list->sub.end);
        printf("%s", list->sub.text);
        printf("\n\n");
        list = list->next;
    }
}

void save_dvdlist(DVDlist* outlist, FILE* output)
{
    while(outlist)
    {
        fprintf(output, "{%lld}{%lld}%s\n", outlist->sub.start, outlist->sub.end, outlist->sub.text);
        outlist = outlist->next;
    }
    printf("Subtitle saved successfully!\n");
    
}
