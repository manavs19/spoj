/*
  3923 - bytesm2
  	Solution - DP.
  		Start DP from every tile in last row. Only some paths are possible for each DP.  		 
  	Similar
*/
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

typedef long long int LL;

int dp[105][105];
int cost[105][105];
int h, w;
int solve(int i, int j)
{
	if(i<0 || i>=h || j<0 || j>=w)return 0;

	if(dp[i][j]!=0)return dp[i][j];

	dp[i][j] = max(max(solve(i-1, j-1), solve(i-1, j)), solve(i-1, j+1));
	dp[i][j]+=cost[i][j];
	return dp[i][j];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&h,&w);

		memset(dp, 0, sizeof(dp));

		int i,j;
		// for(i=0;i<10;++i)
		// {	for(j=0;j<10;++j)
		// 		printf("%d ", dp[i][j]);
		// 	printf("\n");
		// }

		for(i=0;i<h;++i)
		{
			for(j=0;j<w;++j)
				scanf("%d",&cost[i][j]);
		}

		int mx = 0;
		for(j=0;j<w;++j)
		{
			mx = max(mx, solve(h-1, j));
		}

		printf("%d\n", mx);		
	}
	return 0;
}