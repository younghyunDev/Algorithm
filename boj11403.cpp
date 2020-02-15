#include <iostream>
#include <vector>
using namespace std;
int map[100][100];
int ans[100][100]={0,};
bool chk[100][100]={false,};
int N;
vector<int> graph[100];
int main(int argc, char *argv[]) {
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&map[i][j]);
			if(map[i][j]==1)	{graph[i].push_back(j);chk[i][j]=true;}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<graph[i].size();j++)
		{
			int y=graph[i][j];
			for(int k=0;k<N;k++)
			{
				if(map[y][k]==1 && !chk[i][k]) graph[i].push_back(k),chk[i][k]=true;
			}
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<graph[i].size();j++)	ans[i][graph[i][j]]=1;
	}
	
	for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)	printf("%d ",ans[i][j]);
			printf("\n");
		}

	
}