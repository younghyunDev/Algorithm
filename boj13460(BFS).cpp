#include <iostream>
#include<queue>
using namespace std;

int N,M;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
char map[10][10];
struct info{
	int rx,ry,bx,by,cnt;
};
int gx,gy;
queue<info> Q;
bool visited[10][10][10][10]={false,};
int ans=-1;
int main(int argc, char *argv[]) {
	info start;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%s",map[i]);
		for(int j=0;j<M;j++)
		{
			if(map[i][j]=='O') gx=j,gy=i;
			if(map[i][j]=='B') start.bx=j,start.by=i;
			if(map[i][j]=='R') start.rx=j,start.ry=i;
		}
	}
	start.cnt=0;
	visited[start.rx][start.ry][start.bx][start.by]=true;
	Q.push(start);
	while(!Q.empty())
	{
		
		info tmp=Q.front(); Q.pop();
		if(tmp.cnt>10) break;
		if(map[tmp.ry][tmp.rx]=='O' && map[tmp.by][tmp.bx]!='O'){
			ans=tmp.cnt;
			break;
		}
		for(int i=0;i<4;i++)
		{
			int nrx=tmp.rx;
			int nry=tmp.ry;
			int nbx=tmp.bx;
			int nby=tmp.by;
			
			while(true)
			{
				if(map[nry][nrx]=='O') break;
				nrx+=dx[i];
				nry+=dy[i];
				if(map[nry][nrx]=='#' ||map[nry][nrx]=='O')
				{
					if(map[nry][nrx]=='#')nry-=dy[i],nrx-=dx[i];
					break;
				}
			}
			
			while(true)
			{
				if(map[nby][nbx]=='O') break;
				nbx+=dx[i];
				nby+=dy[i];
				if(map[nby][nbx]=='#' ||map[nby][nbx]=='O')
				{
					if(map[nby][nbx]=='#') nby-=dy[i],nbx-=dx[i];
					break;
				}
			}
			
			if(nrx==nbx && nry==nby && map[nry][nrx]!='O')
			{
				int rdis=abs(nrx-tmp.rx)+abs(nry-tmp.ry);
				int bdis=abs(nbx-tmp.bx)+abs(nby-tmp.by);
				if(rdis>bdis)	nrx-=dx[i],nry-=dy[i];
				else	nbx-=dx[i],nby-=dy[i];
			}
			info next={nrx,nry,nbx,nby,tmp.cnt+1};
			
			if(!visited[nrx][nry][nbx][nby])
			{	
				visited[nrx][nry][nbx][nby]=true;
				Q.push(next);
			}
			
		}
	}
		
	printf("%d",ans);
}