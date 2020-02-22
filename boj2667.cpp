#include <iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,cnt=1;
int ans[1000]={0,};
char map[26][26];
bool visit[25][25]={false,};
queue<pair<int,int> > Q;
int main(int argc, char *argv[]) {
	memset(visit, 0, sizeof(visit));

	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&map[i]);
	}
	printf("\n");
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(map[i][j]=='0') map[i][j]=0;
			if(map[i][j]=='1' && !visit[i][j])
			{
				map[i][j]=cnt;
				visit[i][j]=true;
				Q.push(make_pair(i, j));
				while(!Q.empty())
				{
					int curx=Q.front().first;
					int cury=Q.front().second; Q.pop();
					
					
					for(int d=0;d<4;d++)
					{
						int nx=curx+dx[d];
						int ny=cury+dy[d];
						if(nx>=n || ny>=n || nx<0 || ny<0 ) continue;
						if(map[nx][ny]=='1' && !visit[nx][ny])	{
							visit[nx][ny]=true;
							map[nx][ny]=cnt;
							Q.push(make_pair(nx, ny));
						}
					}
				}
				cnt++;
			}
		}
	}
	memset(ans, 0, sizeof(ans));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",map[i][j]);
			if(map[i][j]!=0)	ans[map[i][j]]++;
		}
		printf("\n");
	}
	
	sort(ans+1,ans+cnt);
	printf("%d\n",cnt-1);
	//if(cnt<1) return 00;
	for(int i=1;i<cnt;i++)	printf("%d\n",ans[i]);
}