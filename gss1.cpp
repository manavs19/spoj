/*
	1043 - Can you answer these queries I
	Solution: Divide and Conquer, Segment Tree, Cumulative Sum	
*/
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

const int N = 50004;
const int INF = -1e9;
struct node
{	
	int leftSum,rightSum,maxSum,sum;
	node(){}
	node(int l,int r,int m,int s)
	{
		leftSum=l;
		rightSum=r;
		maxSum=m;
		sum=s;
	}
};

node st[1000000];
int arr[N];

node build(int arr[], int ss, int se, int index)
{
	if(ss==se)
	{
		st[index].leftSum = arr[ss];
		st[index].rightSum = arr[ss];
		st[index].maxSum = arr[ss];
		st[index].sum = arr[ss];
		return st[index];
	}

	int mid = (ss+se)/2;
	node l = build(arr, ss, mid, 2*index+1);
	node r = build(arr, mid+1, se, 2*index+2);

	st[index].leftSum = max(l.leftSum, l.sum+r.leftSum);
	st[index].rightSum = max(r.rightSum, r.sum+l.rightSum);
	st[index].maxSum = max(st[index].rightSum, max(st[index].leftSum, max(max(l.maxSum, r.maxSum), l.rightSum+r.leftSum)));
	st[index].sum = l.sum + r.sum;
	return st[index];
}

node query(int ss, int se, int qs, int qe, int index)
{
	if(ss > qe || se < qs)
	{
		node a(INF, INF, INF, INF);
		return a;
	}

	if(ss>=qs && se<=qe)
		return st[index];

	int mid = (ss+se)/2;
	node l = query(ss, mid, qs, qe, 2*index+1);
	node r = query(mid+1, se, qs, qe, 2*index+2);

	node a;
	a.leftSum = max(l.leftSum, l.sum+r.leftSum);
	a.rightSum = max(r.rightSum, r.sum+l.rightSum);
	a.maxSum = max(a.rightSum, max(a.leftSum, max(max(l.maxSum, r.maxSum), l.rightSum+r.leftSum)));
	a.sum = l.sum+r.sum;

	if(l.leftSum==INF)
	{
		a.leftSum = r.leftSum;
		a.rightSum = r.rightSum;
		a.maxSum=r.maxSum;
		a.sum=r.sum;
	}
	else if(r.rightSum==INF)
	{
		a.leftSum = l.leftSum;
		a.rightSum = l.rightSum;
		a.maxSum=l.maxSum;
		a.sum=l.sum;
	}
	
	return a;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);

	build(arr, 0, n-1, 0);
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int qs,qe;
		scanf("%d %d",&qs,&qe);
		qs--;qe--;
		node ans = query(0,n-1,qs,qe,0);
		printf("%d\n",ans.maxSum);
	}

	return 0;
}