#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int LL;

int beenums[30000];
int e;
void pre()
{
	beenums[0] = 1;
	int runningSum = 1;
	int curr = 6;
	int i=1;
	while(runningSum <= 1000000000)
	{
		runningSum+=curr;
		beenums[i] = runningSum;
		curr+=6;
		i++;
	}
	e=i-1;
	// printf("%d\n", e);
}

int bsearch(int * arr, int beg, int end, int key)
{
	if(beg > end)return 0;

	int mid = (beg+end)/2;
	if(arr[mid] == key)
		return 1;
	else if(arr[mid] < key)
		return bsearch(arr, mid+1, end, key);
	else
		return bsearch(arr, beg, mid-1, key);
}

int main()
{
	int n;
	pre();
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)break;

		if(bsearch(beenums, 0, e, n))
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}