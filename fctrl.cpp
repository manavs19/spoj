#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

typedef long long LL;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL n;
		scanf("%lld",&n);
		LL ans = 0;
		for(int i=1;i<=20;++i)
		{
			LL power5 = (LL)pow(5, i);
			ans += n/power5;
		}

		printf("%lld\n", ans);
	}	

	return 0;
}