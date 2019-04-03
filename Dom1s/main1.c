#include <stdio.h>

#define MAX 101

int a[MAX], pos = 0;

int solve(long long N)
{
    for(int i = 0; i < MAX; ++i) a[i] = 0;
    pos = 0;
    long long start = N; 
    for(int d = 9; d >= 2; --d)
    {
        while((N % d) == 0)
        {
            a[pos] = d;
            pos++;
            N /= d;
        }
    }
    if(N > 10) return -1;
    
    return 0;
}


int main(void)
{
    int T;
    long long N;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld", &N);
        if(N == 0) printf("10");
        else
        {
            if(N > 0 && N < 10) printf("%lld", N);
            else
            {
                int code = solve(N);
                if(code == -1) printf("-1");
                else
                {
                    long long res = 0;
                    while(pos--) res = res*10 + a[pos];
                    printf("%lld", res);
                }
            }
        }
        printf("\n");

    }

    return 0;
}
