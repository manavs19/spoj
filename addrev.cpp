#include <stdio.h>
#include <iostream>

typedef long long int LL;

LL reverse(LL x)
{
	LL ans = 0ll;
	while(x!=0ll)
	{
		ans*=10;
		ans+=x%10;
		x/=10;
	}
	return ans;
}

int main()
{
	int i, n;
	scanf("%d",&n);

	for(i=0;i<n;++i)
	{
		LL a, b;
		scanf("%lld %lld",&a,&b);

		LL sum = reverse(reverse(a) + reverse(b));
		printf("%lld\n", sum);
	}
	return 0;
}