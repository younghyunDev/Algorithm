#include <cstdio>
#include<string>
using namespace std;
int N;
int map[15][15];
int ans=0;
void DFS(int cnt)
{
	if(cnt==N)
	{
		ans++;
		return;
	}
	int orig[15][15];
	memcpy(orig, map, sizeof(orig));
	for(int i=0;i<N;i++)
	{
		
		int r=cnt;
		if(map[cnt][i]==0)
		{
			for(int j=0;j<N;j++)
			{
				map[r][j]=1;
				map[j][i]=1;
				if(r+j<N && i+j<N)	map[r+j][i+j]=1;
				if(r+j<N && i-j>=0)	map[r+j][i-j]=1;
				if(r-j>=0 && i+j<N)	map[r-j][i+j]=1;
				if(r-j>=0 && i-j>=0) map[r-j][i-j]=1;
			}
			DFS(cnt+1);
			memcpy(map, orig, sizeof(map));
		}
	}
}

int main(int argc, char *argv[]) {
	scanf("%d",&N);
	memset(map,0,sizeof(map));
	DFS(0);
	printf("%d",ans);
}