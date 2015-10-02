//740
#include <stdio.h>
#include <iostream>

typedef long long int LL;

LL max(LL a, LL b)
{
	return a>b?a:b;
}

LL dp[2005][2005];
int main()
{
	int n;
	scanf("%d",&n);
	LL arr[2005];
	int i,j,days;
	arr[0]=0;
	for(i=1;i<=n;++i)
		scanf("%lld",&arr[i]);

	dp[0][n+1]=0;
	for(i=1;i<=n;++i)
		dp[i][n+1] = dp[i-1][n+1] + i*arr[i];
	for(i=n;i>=1;--i)
		dp[0][i] = dp[0][i+1] + (n+1-i)*arr[i];

	for(days=2;days<=n;++days)
	{
		for(i=1;i<days;++i)
		{
			j=n+i-days+1;
			dp[i][j] = max(dp[i-1][j] + days*arr[i], dp[i][j+1] + days*arr[j]);
		}
	}

	// for(i=0;i<=n;++i)
	// {
	// 	for(j=0;j<=n;++j)
	// 		printf("%lld\t", dp[i][j]);
	// 	printf("\n");
	// }

	LL ans=0;
	for(i=0;i<=n;++i)
		ans=max(ans, dp[i][i+1]);

	printf("%lld\n", ans);
	return 0;
}