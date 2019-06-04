#include "main.h"
#include <time.h>


void printhelp()
{
    printf("0 : exit\n");
    printf("1 : (re)load subtitle from MPlayer\n");
    printf("2 : move forward subtitle\n");
    printf("3 : move backward subtitle\n");
    printf("4 : convert subtitle to MicroDVD format\n");
    printf("5 : save subtitle\n");
    printf("6 : delete all memory\n");
    printf("100 : print help\n");
    printf("\nEnter yout choice: ");
}



int main(int argc, char** argv)
{
    clock_t start, end;
    start = clock();
    time_t t = time(NULL);
    struct tm* currentLocal = localtime(&t);
    char* timestring = calloc(101, sizeof(char));
    if(currentLocal && timestring)
    {
        strftime(timestring, 100, "%H:%M:%S", currentLocal);
        printf("Start time:%s\n", timestring);
    }

    if(argc != 3)
    {
        printf("Invalid commandline args!\n");
    }
    printf("FPS:%lf\n", FPS_NUM);

    MPlist* inlist = NULL;
    DVDlist* outlist = NULL;

    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    if(!input || !output)
    {
        printf("No such file!\n");
        return 0;
    }

    int sw;
    printhelp();
    
    lld shift;

    scanf("%d", &sw);
    while(sw)
    {
        switch(sw)
        {
            case (1):
                freemp(inlist);
                inlist = load_mplist(input);
                break;
            case (2):
                printf("Insert delay: ");
                scanf("%lld", &shift); 
                movesub(inlist, shift);
                break;
            case (3):
                printf("Insert delay: ");
                scanf("%lld", &shift);
                shift = -shift;
                movesub(inlist, shift);
                break;
            case (4):
                outlist = mp2dvd(inlist);
                break;
            case (5):
                save_dvdlist(outlist, output);
                break;
            case (6):
                freemp(inlist);
                freedvd(outlist);
                break;
            default:
                printhelp();
                break;
        }
        printf("\nEnter yout choice: ");
        scanf("%d", &sw);
    }
    
    freedvd(outlist);
    freemp(inlist);

    t = time(NULL);
    currentLocal = localtime(&t);
    if(currentLocal && timestring)
    {
        strftime(timestring, 100, "%H:%M:%S", currentLocal);
        printf("Start time:%s\n", timestring);
    }


    end = clock();
    double elapsed = ((double)(end-start)) / CLOCKS_PER_SEC;
    printf("Exe time:%lf\n", elapsed);

    return 0;
}
