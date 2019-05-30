#include <stdio.h>
#include "main.h"
#include <string.h>

void printhelp()
{
    printf("0 : exit\n");
    printf("1 : load list (deletes all previous lists)\n");
    printf("2 : insert element at the beggining\n");
    printf("3 : insert element at the end\n");
    printf("4 : remove first element\n");
    printf("5 : remove last element\n");
    printf("6 : remove specific element\n");
    printf("7 : sort all meeting\n");
    printf("8 : sort list and create schedule\n");
    printf("9 : print all meetings\n");
    printf("10 : print scheduled meetings\n");
    printf("100 : print help\n");
    printf("\nEnter yout choice: ");
}

int main(void)
{

    lipo* list = NULL;
    lipo* schedule = NULL;

    int sw;
    Meeting tmp;
    
    printhelp();

    scanf("%d", &sw);
    while(sw)
    {
        switch(sw)
        {
            case (1):
                list = readlist();
                break;
            case (2):
                tmp = readMeeting();
                insertbeg(tmp, &list);
                break;
            case (3):
                tmp = readMeeting();
                insertend(tmp, &list);
                break;
            case (4):
                removebeg(&list);
                break;
            case (5):
                removeend(&list);
                break;
            case (6):
                printf("Insert meeting:\n");
                tmp = readMeeting();
                removespec(tmp, &list);
                break;
            case (7):
                sortlist(list);
                break;
            case (8):
                sortlist(list);
                schedule = createschedule(list);
                break;
            case (9):
                printlist(list);
                break;
            case (10):
                printlist(schedule);
                break;
            case (11):
                freelist(list);
                printf("List deleted!");
                break;
            default:
                printhelp();
                break;
        }
        printf("\nEnter yout choice: ");
        scanf("%d", &sw);
    }

/*    list = readlist();
    
    printlist(list);
    printf("\n");

    tmp.start = 10;
    tmp.end = 20;
    tmp.building = "ETF";
    tmp.room = "65";
    
    Meeting b;
    b.start = 2;
    b.end = 2;
    b.building = "b";
    b.room = "b";


    insertend(tmp, &list);
    insertend(b, &list);

    printlist(list);
    printf("\n");

    removespec(b, &list);

    printlist(list);
*/
    freelist(list);
    freelist(schedule);

    return 0;
}
