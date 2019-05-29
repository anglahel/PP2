#ifndef MAIN_H_   
#define MAIN_H_

#include <stdio.h>

typedef long long int lld;

typedef struct meeting
{
    lld start, end;
    char* building;
    char* room;
} Meeting;

typedef struct lipo{
    Meeting m;
    struct lipo* next;
} lipo;

extern lipo* readlist();

extern void insertbeg(Meeting elem, lipo** list);
extern void insertend(Meeting elem, lipo** list);
//extern void insert(Meeting elem, lipo* list);
extern void removebeg(lipo** list);
extern void removeend(lipo** list);
extern void removespec(Meeting elem, lipo** list);
extern Meeting readMeeting();

extern void printlist(lipo* list);

extern void sortlist(lipo* elem);
extern lipo* createschedule(lipo* list);
extern void freelist(lipo* list);
#endif
