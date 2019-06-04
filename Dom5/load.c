#include "main.h"

MPlist* load_mplist(FILE* input)
{
    MPlist *list = NULL, *current = NULL;
    char* tmp = malloc(MAX_LEN*sizeof(char));
    while(fgets(tmp, MAX_LEN+1, input))
    {
        double wait, duration;
        sscanf(tmp, "%lf %lf", &wait, &duration);
        char* text = calloc(MAX_LEN, sizeof(char));
        while(fgets(tmp, MAX_LEN+1, input) && strcmp(tmp, "\n"))
        {
            strcat(text, tmp);
        }
        text[strlen(text)-1] = '\0';//take \n char from the end of subtitle string

        MPlist* node = malloc(sizeof(MPlist));
        node->sub.wait = wait;
        node->sub.duration = duration;
        node->sub.text = text;
        node->next = node->prev = NULL;
        
        if(!list)
        {
            node->prev = node->next = NULL;
            list = current = node;
        }
        else
        {
            node->prev = current;
            current = current->next = node;
        }
    }
    printf("Subtitle loaded successfully!\n");
    return list;
}
