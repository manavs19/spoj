/*
	1043 - Can you answer these queries I
	Solution: Divide and Conquer, Segment Tree, Cumulative Sum	
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>

using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

int arr[50004], leftSum[50004], rightSum[50004];
// int rangeSum(int start, int end)
// {
// 	if(start==0)return leftSum[end];
// 	else return leftSum[end] - leftSum[start-1];
// }
class SegmentTree
{
public:
	int * nodes;
	int n;
	SegmentTree(int arr[], int n)
	{
		this->n=n;
		int ht = (int)(ceil(log2(n))); //Height of segment tree
	    int max_size = 2*(int)pow(2, ht); //Maximum size of segment tree
	    nodes = new int[max_size];

	    build(arr, 0, n-1, 0);
	}

	int build(int arr[], int ss, int se, int si)
	{
		if(ss==se)
		{
			nodes[si] = arr[ss];
			return nodes[si];
		}
		int mid = (ss+se)/2;
		nodes[si] = max(build(arr, ss, mid, 2*si+1), build(arr, mid+1, se, 2*si+2));
		return nodes[si];
	}

	int query(int qs, int qe)
	{
		return query(0, n-1, 0, qs, qe);
	}
	int query(int ss, int se, int si, int qs, int qe)
	{
		if(qe < ss || se < qs)return INT_MIN;
		if(qs<=ss && se<=qe)return nodes[si];

		int mid = (ss+se)/2;
		return max(query(ss, mid, 2*si+1, qs, qe), query(mid+1, se, 2*si+2, qs, qe));
	}
};

class RangeSegmentTree
{
public:
	SegmentTree *stleft, *stright;
	int * nodes;
	int n;
	RangeSegmentTree(int arr[], int n, SegmentTree * stleft, SegmentTree * stright)
	{
		this->n=n;
		this->stleft = stleft;
		this->stright = stright;

		int ht = (int)(ceil(log2(n))); //Height of segment tree
	    int max_size = 2*(int)pow(2, ht); //Maximum size of segment tree
	    nodes = new int[max_size];

	    build(arr, 0, n-1, 0);
	}

	int build(int arr[], int ss, int se, int si)
	{
		if(ss==se)
		{
			nodes[si] = arr[ss];
			return nodes[si];
		}
		int mid = (ss+se)/2;
		int v1 = build(arr, ss, mid, 2*si+1);
		int v2 = build(arr, mid+1, se, 2*si+2);
		int v3 = stright->query(ss, mid) + stleft->query(mid+1, se) - rightSum[0];
		nodes[si] = max(max(v1, v2), v3);
		return nodes[si];
	}

	int query(int qs, int qe)
	{
		return query(0, n-1, 0, qs, qe);
	}
	int query(int ss, int se, int si, int qs, int qe)
	{
		if(qe < ss || se < qs)return INT_MIN;
		if(qs<=ss && se<=qe)return nodes[si];

		int mid = (ss+se)/2;
		int v1 = query(ss, mid, 2*si+1, qs, qe);
		int v2 = query(mid+1, se, 2*si+2, qs, qe);
		int v3 = INT_MIN;
		if(qs <= ss && qe>mid)
			v3 = stright->query(ss, mid) + stleft->query(mid+1, qe) - rightSum[0];
		else if(qs>=ss && qs<=mid && qe<=se)
			v3 = stright->query(qs, mid) + stleft->query(mid+1, qe) - rightSum[0];
		else if(qs>=ss && qs<=mid && qe>se)
			v3 = stright->query(qs, mid) + stleft->query(mid+1, se) - rightSum[0];

		return max(max(v1, v2), v3);
	}
};
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);

	leftSum[0] = arr[0];
	for(i=1;i<n;++i)
		leftSum[i] = leftSum[i-1] + arr[i];
	rightSum[n-1] = arr[n-1];
	for(i=n-2;i>=0;--i)
		rightSum[i] = rightSum[i+1] + arr[i];

	SegmentTree stleft(leftSum, n);
	SegmentTree stright(rightSum, n);

	RangeSegmentTree st(arr, n, &stleft, &stright);
	
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int qs,qe;
		printf("%d\n", st.query(qs-1, qe-1));
	}

	return 0;
}
