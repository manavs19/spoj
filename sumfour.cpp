#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <limits.h>
 
#define MOD 1000000007 

typedef long long LL;
 
using namespace std;

LL gcd(LL u, LL v)
{
	return (v != 0)?gcd(v, u%v):u;
}

const int N = 4001;
int ab[N*N], cd[N*N];

int main()
{
	int n;
	scanf("%d",&n);
	int a[N], b[N], c[N], d[N];
	int i,j;
	for(i=0;i<n;++i)
		scanf("%d %d %d %d",&a[i], &b[i], &c[i], &d[i]);

	int index=0;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			ab[index] = a[i]+b[j];
			cd[index++] = c[i]+d[j];
		}
	}

	sort(ab, ab+index);
	sort(cd, cd+index);

	LL ans=0;
	i=0;j=index-1;
	while(i<index && j>=0)
	{	
		int v1=ab[i];
		int v2=cd[j];

		if(v1+v2==0)
		{			
			int freq1=1;i++;
			while(i<index && ab[i]==v1)
			{
				freq1++;
				i++;
			}

			int freq2=1;j--;
			while(j>=0 && cd[j]==v2)
			{
				freq2++;
				j--;
			}

			ans+=(LL)freq1 * (LL)freq2;
		}
		else if(v1+v2<0)
			i++;
		else
			j--;
	}
	printf("%lld\n", ans);
	return 0;
}