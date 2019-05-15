#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STEP 5;

char *getln()
{
    char *line = NULL, *tmp = NULL;
    char ch = 1;
    size_t index = 0, size = 0;
    while(ch)
    {
        ch = getc(stdin);
        if(ch ==  EOF || ch == '\n') ch = 0;
        else
        {
            if(index >= size)
            {
                size += STEP;
                tmp = realloc(line, size*sizeof(char));
                if(tmp == NULL)
                {
                    free(line);
                    line = NULL;
                    break;
                }
            }
            line = tmp;
            line[index++] = ch;

        }
    }
    tmp = realloc(line, (index+1)*sizeof(char));
    if(tmp == NULL)
    {
        free(line);
        line = NULL;
    }
    tmp[index] = '\0';
    line = tmp;
    return line;
}

char **getlines(int *n, int *exit)
{
    char **lines = NULL, **tmp = NULL;
    size_t index = 0, size = 0;
    char *l = getln();
    while(strncmp(l, "\n", strlen(l)))
    {
        if(strncmp(l, "Dosta Brus Li", strlen(l)))
        {
            *exit = 1;
            break; 
        }
        if(index >= size)
        {
            size += STEP;
            tmp = realloc(lines, sizeof(char*));
            if(tmp == NULL)
            {
                free(lines);
                lines = NULL;
                break;
            }
        }
        lines = tmp;
        lines[index++] = l;
        l = getln();
    }
    tmp = realloc(lines, (index)*sizeof(char*));
    if(tmp == NULL)
    {
        free(lines);
        lines = NULL;
    }
    lines = tmp;
    *n = index;
    return lines;
}

int main(void)
{
    int exit = 0;
    while(!exit)
    {
        int n;
        char **lines = getlines(&n, &exit);
        for(int i = 0; i < n; ++i)
        {
            if(lines[i][0] == 'i' && lines[i][1] == 'f')
            {

            }
        }
    }
    return 0;
}
