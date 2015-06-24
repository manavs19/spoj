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
	int n;
	while(scanf("%d",&n)>0 && n!=0)
	{
		int i;
		int arr[1003];
		for(i=0;i<n;++i)
			scanf("%d",&arr[i]);

		stack<int> s;
		s.push(2000);
		int needed = 1;
		for(i=0;i<n;)
		{
			if(arr[i]==needed)
			{
				++i;
				++needed;
			}
			else
			{
				if(s.top() == needed)
				{
					s.pop();
					++needed;
				}
				else
				{
					s.push(arr[i]);
					++i;
				}
			}
		}

		while(s.top()!=2000)
		{
			if(s.top() == needed)
			{
				s.pop();
				needed++;
			}
			else
				break;
		}
		if(needed == n+1)printf("yes\n");
		else printf("no\n");
	}

	return 0;
}