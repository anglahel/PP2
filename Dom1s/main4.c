#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

typedef struct Cow
{
    int milk;
    int time;
} Cow;

void swap(Cow *a, Cow *b)
{
    Cow tmp = *a;
    *a = *b;
    *b = tmp;
}

bool cmp(Cow a, Cow b)
{
    if(a.milk != b.milk) return a.milk <= b.milk;
    return a.time <= b.time;
}

int part(Cow in[], int low, int high)
{
    Cow pivot = in[high];
    int i = low-1;
    for(int j = low; j < high; ++j)
    {
        //if(in[j].time <= pivot.time)
        if(cmp(in[j], pivot))
        {
            i++;
            swap(&in[i], &in[j]);          
        }
    }
    i++;
    swap(&in[i], &in[high]);
    return i;
}

void sort(Cow in[], int low, int high)
{
    if(low < high)
    {
        int p = part(in, low, high);
        
        sort(in, low, p-1);
        sort(in, p+1, high);
    }

}

int main(void)
{
    int N;
    Cow a[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        a[i].milk = tmp1;
        a[i].time = tmp2;
    }
    sort(a, 0, N-1);
    /*for(int i = 0; i < N; ++i)
    {
        int tmp1 = a[i].time, tmp2 = a[i].milk;
        printf("%d\t %d \n", tmp1, tmp2);
    }*/

    long long result = 0;
    int slots[100000] = {0};
    
    for(int i = N-1; i >= 0; --i)
    {
        int d=a[i].time;
        while(d)
        {
            if(!slots[d])
            {
                slots[d]=1;
                result+=a[i].milk;
                break;
            }
            else
                d--;
        }
    } 


    printf("%lld", result);

    return 0;
}
