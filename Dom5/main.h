#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef NTSC
#define FPS_NUM 23.976
#else
#define FPS_NUM 25.0
#endif

#define MAX_LEN 100
typedef long long int lld;


//MPlayer structures
typedef struct Mplayer
{
    double wait, duration;
    char* text;
} Mplayer;

typedef struct elemmp
{
    Mplayer sub;
    struct elemmp* prev;
    struct elemmp* next;
} MPlist;


//MicroDVD structures
typedef struct Mdvd
{
    lld start, end;
    char* text;
}  Mdvd;

typedef struct elemdvd
{
    Mdvd sub;
    struct elemdvd* prev;
    struct elemdvd* next;
} DVDlist;

//Load

extern MPlist* load_mplist(FILE* input);

//Save
extern void save_dvdlist(DVDlist* outlist, FILE* output);

extern void printdvd(DVDlist* list);
extern void printmp(MPlist* list);

//Process
extern DVDlist* mp2dvd(MPlist* inlist);
extern void movesub(MPlist* inlist, lld shift);

extern void freedvd(DVDlist* list);
extern void freemp(MPlist* list);

#endif
