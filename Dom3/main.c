#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
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
        if(!strncmp(l, "dosta Brus Li", strlen(l)))
        {
            *exit = 1;
            break; 
        }

        if(index >= size)
        {
            size += STEP;
            tmp = realloc(lines, size*sizeof(char*));
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

void translate(char *line)
{
    char *ifstart = "if";
    char *then = "then begin";
    char *end = "end;";
    char *i = strstr(line, ifstart);
    char *t = strstr(line, then);
    char *e = strstr(line, end);
    ptrdiff_t new_size = 0;
    
    if(i && t && e)
    { 
        line[2] = '(';
        *(t-1) = ')';
        *t = ' ';
        *(t+1) = '{';
        char* tmp1 = t+2;
        char* tmp2 = t+10;
        while(tmp2 != e)
        { 
            *(tmp1) = *(tmp2);
            tmp1++;
            tmp2++;
        }
        *tmp1 = '}';
        *(tmp1+1) = ';';
        *(tmp1+2) = '\0';
        new_size = tmp1 - line + 3;
         //printf("%ld new size\t", new_size);
        char *tmp = NULL;
        tmp = realloc(line, new_size*sizeof(char));
        line = tmp;
        printf("%s\n", line);
    }
    else
    {
        printf("Not valid if statement!\n");
    }
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
            printf("%s\t-->\t", lines[i]);
            translate(lines[i]);
        }
        printf("\n");
    }
    return 0;
}
