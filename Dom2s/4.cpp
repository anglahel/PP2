#include<bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
 
const int maxN = 2e6+10;
vector<int> dp[maxN];
int a[maxN], cnt[maxN];
int sum;
void solve()
{
	int n;
	cin>>n;
	sum+=n;
	assert(n>=1 && n<=1000000);
 
	for (int i=1;i<=2*n;i++){
	 dp[i].clear();
	 cnt[i]=0;
	}
 
	int ans = 0;
	for (int i=1;i<=n;i++){
	    scanf("%d",&a[i]);
	    assert(a[i]>=1 && a[i]<=1e9);
	    if (a[i]>2*n) ans++; else
	        cnt[a[i]]++;
	}
 
	for (int i=0;i<=2*n;i++)
	    dp[0].pb(0);
 
	for (int i=1;i<=2*n;i++){
	 for (int j=0;j<=(2*n)/i;j++)
	    dp[i].pb(dp[i-1][j]+abs(cnt[i]-j));
 
	 for (int j=(2*n)/i -1;j>=0;j--)
	    dp[i][j]=min(dp[i][j],dp[i][j+1]);
	}
 
	ans+=min(dp[2*n][0],dp[2*n][1]);
 
	printf("%d\n",ans);
  return;
}
int main()
{
	int t;
	cin>>t;
 
	assert(t>0 && t<=1000);
 
	while(t--)
	    solve();
 
	assert(sum<=1e6 && sum>0);
	return 0;
}
