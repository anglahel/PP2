#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>

#define MAX 210
typedef long int ld;

int N;
ld a[MAX];
int dp[MAX][MAX][MAX]; //store data

int min(int a, int b)
{
	if (a <= b) return a;
	return b;
}
 
int solve(int idx, int blackidx, int whiteidx)
{
	if (idx > N) return 0;
	if (dp[idx][blackidx][whiteidx] != -1) return dp[idx][blackidx][whiteidx];
	dp[idx][blackidx][whiteidx] = MAX + 1;
	if ((blackidx == 0 || a[idx] > a[blackidx]) && (whiteidx == 0 || a[idx] < a[whiteidx]))
		return dp[idx][blackidx][whiteidx] = min(min(solve(idx + 1, blackidx, idx), solve(idx + 1, idx, whiteidx)), 1 + solve(idx + 1, blackidx, whiteidx));
	else if (blackidx == 0 || a[idx] > a[blackidx])
		return dp[idx][blackidx][whiteidx] = min(solve(idx + 1, idx, whiteidx), 1 + solve(idx + 1, blackidx, whiteidx));
	else if (whiteidx == 0 || a[idx] < a[whiteidx])
		return dp[idx][blackidx][whiteidx] = min(solve(idx + 1, blackidx, idx), 1 + solve(idx + 1, blackidx, whiteidx));
	else
		return dp[idx][blackidx][whiteidx] = 1 + solve(idx + 1, blackidx, whiteidx);

}

void setdp()
{
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			for (int k = 0; k < MAX; ++k)
				dp[i][j][k] = -1;
}

int main(void)
{
    scanf("%d", &N);
	while(N != -1)
    {
        for(int i = 1; i <= N; scanf("%ld", &a[i++]));
		//memset(dp, -1, sizeof(dp));
		setdp();
		printf("%d\n", solve(1, 0, 0));
        scanf("%d", &N);
    }
    return 0;
}
