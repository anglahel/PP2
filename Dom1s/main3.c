#include <stdio.h>
#include <stdbool.h>

#define MAX 100000

typedef struct Mine
{
    long long int x;
    long long int d;
    long long int g;
} Mine;

bool cmp(Mine a, Mine b)
{
    return ((a.d - a.x) >= (b.d - b.x));
}


void swap(Mine *a, Mine *b)
{
    Mine tmp = *a;
    *a = *b;
    *b = tmp;
}

int part(Mine in[], int low, int high)
{
    Mine pivot = in[high];
    int i = low-1;
    for(int j = low; j < high; ++j)
    {
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

void sort(Mine in[], int low, int high)
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
    long long int N;
    scanf("%lld", &N);
    Mine a[MAX];
    for(long long int i = 0; i < N; ++i)
    {
        scanf("%lld %lld %lld", &a[i].x, &a[i].g, &a[i].d);
    }
    printf("\n");
    sort(a, 0, N-1);
    for(long long int i = 0; i < N; ++i)
    {
        printf("%lld, %lld, %lld \n", a[i].x, a[i].g, a[i].d);
    }


    
    return 0;
}
