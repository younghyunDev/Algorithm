#include <iostream>
#include<queue>
using namespace std;
int n,m;
int cnt=0;
struct info{
	int y,x,cnt;
};
const int dx[]={1,-1,0,0};
const int dy[]={0,0,-1,1};
int map[101][101];
int chk[101][101]={false,};
queue<info> Q;
int main(int argc, char *argv[]) {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)	scanf("%1d",&map[i][j]);
	}
	chk[1][1]=true;
	info tmp;
	tmp.y=1,tmp.x=1,tmp.cnt=0;
	Q.push(tmp);
	while(!Q.empty())
	{
		info cur=Q.front();Q.pop();
		int y=cur.y, x=cur.x ,ans=cur.cnt;
		if(y==n && x==m)
		{
			printf("%d",ans+1);
			break;
		}
		for(int i=0;i<4;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			info next={ny,nx,ans+1};
			if(ny<=0 || ny>n || nx<=0 || nx>m) continue;
			if(map[ny][nx]==1 && !chk[ny][nx])
			{
				
				chk[ny][nx]=1;
				Q.push(next);
			}
		}
	}
	
}