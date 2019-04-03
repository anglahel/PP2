#include <stdio.h>

#define MAX 100000

int main(void)
{
    long int N;
    scanf("%ld", &N);
    while(N >= 2 && N <= MAX)
    {
        long long int out = 0, curr = 0, a;
        while(N--)
        {
            scanf("%lld", &a);
            curr += a;
            if(curr < 0) out -= curr;
            else out += curr;
        }
        printf("%lld\n", out);


        scanf("%ld", &N);
    }
    return 0;
}

// TODO main0
