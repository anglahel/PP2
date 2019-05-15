#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100000

typedef struct Mine
{
    long long int val;
    long long int idx;
    bool start;
} Mine;


long long int max(long long int a, long long int b)
{
    if(a >= b) return a;
    else return b;
}

bool cmp(Mine a, Mine b)
{
    if(a.val > b.val || (a.val == b.val && a.start == false)) return true;
    else return false;
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
        if(cmp(pivot, in[j]))
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


int compare (const void * Oa, const void * Ob)
{

    Mine *a = (Mine *)Oa;
    Mine *b = (Mine *)Ob;
    if(a->val > b->val) return true;
    else
    {
        if(a->val == b->val)
        {
            if(a->start == false) return true;
            else return false;
        }
        return false;
    }
/*
    if(a->val > b->val || (a->val == b->val && a->start == false)) return true;
    else return false;
*/
  
}


int main(void)
{
    long long int N;
    scanf("%lld", &N);
    long long int x[MAX];
    long long int g[MAX];
    long long int d[MAX];
    Mine all[2*MAX];
    x[0] = 0; g[0] = 0; d[0] = 0;
    long long int ans = 0;
    for(long long int i = 1; i <= N; ++i)
    {
        scanf("%lld %lld %lld", &x[i], &g[i], &d[i]);
        ans  = max(ans, g[i]);
            g[i] += g[i-1];
            d[i] += d[i-1];
            Mine tmp1, tmp2;
            tmp1.val = d[i] - x[i];tmp1.start = false;tmp1.idx = i;
            tmp2.val = d[i-1] - x[i];tmp2.start = true;tmp2.idx = i;
            all[2*(i-1)] = tmp1;
            all[2*(i-1)+1] = tmp2;
    }
    //sort(all, 0, 2*N-1);
    qsort(all, 2*N, sizeof(Mine), compare);
    /*for(int i = 0; i < 2*N; i++)
    {
        printf("%lld, %lld, %d\n", all[i].val, all[i].idx, all[i].start);
    }
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        printf("%lld\t", g[i]);
    }*/

    long long int j = MAX + 10;
    for(long long int k = 0; k < 2*N; ++k)
    {
        if(all[k].start)
        {
            if(all[k].idx < j) j = all[k].idx;
        }
        else
        {
            if(j != MAX + 10)
            {    
                long long int i = all[k].idx;
                long long int currgold;
                currgold = g[i] - g[j-1];
                ans = max(ans, currgold);
            }
        }
    }  
    printf("%lld", ans);  
   
    return 0;
}
