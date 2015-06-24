/* Knapsack Problem */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int w,n;
	while(scanf("%d %d",&w,&n)>0 && (w!=0 || n!=0))  
	{
		int cost[105], fun[105];
		int i;
		for(i=1;i<=n;++i)
			scanf("%d %d",&cost[i], &fun[i]);

		//dp[i][j] : Max fun with budget of i and parties till j.
		int dp[505][105];
		for(i=0;i<=n;++i)dp[0][i]=0;
		for(i=0;i<=w;++i)dp[i][0]=0;

		int j;
		for(i=1;i<=w;++i)
		{
			for(j=1;j<=n;++j)
			{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				if(cost[j]<=i)dp[i][j] = max(dp[i][j], dp[i-cost[j]][j-1] + fun[j]);
			}
		}

		int maxFun = dp[w][n];
		for(i=1;i<=w;++i)
			if(dp[i][n]==maxFun)break;

		printf("%d %d\n", i, maxFun);
	}
	return 0;
}