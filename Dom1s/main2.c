#include <stdio.h>

#define MAX 1000

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int N, K;
        scanf("%d %d", &N, &K);
        int ones[MAX], zeros[MAX], z = 0, o = 0;
        char c;
        scanf("%c", &c);
        char num[MAX];
        for(int i = 0; i < N; ++i)
        {
            scanf("%c", &c);
            num[i] = c;
            if(c == '0') zeros[z++] = i;
            else ones[o++] = i;
        }
        for(int i = 0, d = 0, s = 0; i < N-K; i++)
        {
            if(i % 2 == 0)
            {
                if(s < o) num[ones[s++]] = '2'; 
                else num[zeros[d++]] = '2';
            }
            else
            {
                if(d < z) num[zeros[d++]] = '2';
                else  num[ones[s++]] = '2';
            }
        }
        for(int i = 0; i < N; ++i)
        {
            if(num[i] != '2')
            {
                printf("%c", num[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
