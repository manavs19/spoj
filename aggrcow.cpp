/*
  297 - aggrcow
  	Solution - Binary Search.
  		Binary search on possible values of minimum distance(0 to 10^9) 
		Check whether a minimum distance can be attained. Assign leftmost cow to first stall.
		For every cow check if it can be given a stall which is atleast at a minimum distance
		from the previous cow. 
  	Similar
  		Mice and holes problem
  		Here #cows<=#stalls. So binary search needed.
  		If #cows==#stalls, simply assign cows from left and check min distance possible.
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int pos[100005];
int n, c;
int isPossible(int k)
{
	int i=1, j=1;
	int prev = pos[0];
	while(i<n && j<c)
	{
		if(pos[i] - prev >= k)
		{
			j++;
			prev = pos[i];
		}
		i++;
	}

	if(j==c)return 1;
	else return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&c);

		int i;
		for(i=0;i<n;++i)
			scanf("%d",&pos[i]);

		sort(pos, pos+n);

		int beg=0, end=1000000000;
		int ans;
		while(beg<=end)
		{
			int mid=(beg+end)/2;
			if(isPossible(mid))
			{
				ans=mid;
				beg=mid+1;
			}
			else
			{
				end= mid-1;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}