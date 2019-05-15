#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000005
typedef long int ld;

/*ld abs(ld a)
{
    return a > 0 ?a : -a;
}*/

int min(int a, int b)
{
    return a <= b ? a : b;
}

int occ[2*MAXN] = {0};//broj pojavljivanja broja i u nizu

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int N;
        int a;
        scanf("%d", &N);
        for (int i = 0; i <= 2 * N; i++)
		{
			occ[i] = 0;
		}
        int out = 0;
        for(int i = 0; i < N; ++i)
        {
            scanf("%d", &a);
            if(a > 2*N) out++;
            else occ[a]++;
        }
        //too big for static
        int **dp;
        dp = malloc((2*N + 1) * sizeof(int*));
        dp[0] = calloc(2*N+1, sizeof(int));
        for(int i = 1; i <= 2*N; i++)
        {
        }
        for(int i = 1; i <= 2*N; ++i)
        {

            for(int j = 0; j <= 2*N/i; ++j)
            {
                dp[i][j] = abs(occ[i] - j) + dp[i-1][j];
            }
            for(int j = 2*N/i - 1; j >= 0; --j)
            {
                dp[i][j] = min(dp[i][j], dp[i][j+1]);
            }
        }
        out += min(dp[2*N][0], dp[2*N][1]);
        printf("%d\n", out);
        for(int i = 0; i <= 2*N; ++i)
        {
            free(dp[i]);
        }
        free(dp);

    }
    return 0;
}
