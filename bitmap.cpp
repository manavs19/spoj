/*
  206 - bitmap
  	Solution - BFS.
  		Imagine wavefronts starting from white pixels. As they move forward,
  		they cover entire graph. But do BFS only once to prevent TLE. So enqueue all white pixels initially.
  		The first time a pixel is visited, that is it's minimum distance from
  		a white pixel(White pixel from which the wavefront originated).
  	Similar
  		Minesweeper
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <utility>
#include <queue>

using namespace std;

string graph[200];
int dist[200][200];
int n,m;

bool isValid(int i, int j)
{
	return i>=0 && i<n && j>=0 && j<m;
}

void bfs()
{
	int visited[200][200] = {0};
	queue<pair<int,int> > q;
	int i,j;
 	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(graph[i][j] == '1')
			{
				// printf("%d %d\n", i,j);
				q.push(make_pair(i,j));
				dist[i][j] = 0;
				visited[i][j] = 1;
			}
		}
	}

	while(!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();
		i=curr.first;j=curr.second;
		int currDist = dist[i][j];
		
		int dx[] = {+1,0,-1,0};
		int dy[] = {0,+1,0,-1};
		for(int d=0;d<4;++d)
		{
			if(isValid(i+dx[d], j+dy[d]) && visited[i+dx[d]][j+dy[d]]==0)
			{
				q.push(make_pair(i+dx[d], j+dy[d]));
				dist[i+dx[d]][j+dy[d]] = currDist+1;
				visited[i+dx[d]][j+dy[d]] = 1;
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dist, 0, sizeof(dist));
		scanf("%d %d",&n,&m);

		int i,j;
		for(i=0;i<n;++i)
			cin>>graph[i];

		bfs();

		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
				printf("%d ", dist[i][j]);
			printf("\n");
		}
	}	

	return 0;
}