/*
  1437 - pt07z
  	Solution - 2 BFS.
  		Can be proved by considering some cases.
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

vector<int> nbrs[10004];

int bfs(int node, int * end)
{
	bool visited[10004] = {false};
	queue<int> q;
	queue<int> d;
	q.push(node);
	d.push(0);

	int curr;
	int dist=0;
	while(!q.empty())
	{
		curr = q.front();
		dist = d.front();
		q.pop();
		d.pop();
		// printf("Visiting %d\n", curr);
		visited[curr] = true;
		for(int j=0;j<nbrs[curr].size();++j)
		{
			if(!visited[nbrs[curr][j]])
			{
				q.push(nbrs[curr][j]);
				d.push(dist+1);
			}
		}
	}	
	*end = curr;
	return dist;
}

int main()
{
	int n;
	scanf("%d",&n);

	int i;
	for(i=0;i<n-1;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		nbrs[u].push_back(v);
		nbrs[v].push_back(u);
	}

	int end;
	int len1 = bfs(1, &end);
	int len2 = bfs(end, &end);
	printf("%d\n", len2);

	return 0;
}