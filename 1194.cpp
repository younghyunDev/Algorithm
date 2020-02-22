#include <iostream>
#include<queue>
#include<string.h>
using namespace std;
int dirx[]={1,-1,0,0},diry[]={0,0,-1,1};
int n,m;
int ans=-1;
int sx,sy;
struct info{
	int y,x,k,cnt;
	
};
char map[50][50];
bool visited[50][50][64];
queue<info> Q;
int main(int argc, char *argv[]) {
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;++j){
			cin>>map[i][j];
			if(map[i][j]=='0')	sx=j,sy=i,map[i][j]='.';
		}
	}
	memset(visited,0,sizeof(visited));
	info s={sy,sx,0,0};
	visited[sy][sx][0]=1;
	Q.push(s);
	while(!Q.empty())
	{
		
		info cur=Q.front();Q.pop();
		if(map[cur.y][cur.x]=='1') {ans=cur.cnt;break;} 
		for(int i=0;i<4;i++)
		{
			info nxt=cur;
			nxt.cnt++;
			nxt.y+=diry[i],nxt.x+=dirx[i];
			if(nxt.y>=n || nxt.y<0 || nxt.x>=m || nxt.x<0) continue;
			if(map[nxt.y][nxt.x]=='#')	continue;
			if('A'<=map[nxt.y][nxt.x] && map[nxt.y][nxt.x]<='F')
			{
				if((nxt.k&(1<<(map[nxt.y][nxt.x]-'A'))) && !visited[nxt.y][nxt.x][nxt.k]) visited[nxt.y][nxt.x][nxt.k]=1,Q.push(nxt);
			}
			else if('a'<=map[nxt.y][nxt.x] && map[nxt.y][nxt.x]<='f')
			{
				nxt.k|=(1<<(map[nxt.y][nxt.x]-'a'));
				if(visited[nxt.y][nxt.x][nxt.k]) continue;
				visited[nxt.y][nxt.x][nxt.k]=1;
				Q.push(nxt);
			}
			else if(!visited[nxt.y][nxt.x][nxt.k])	visited[nxt.y][nxt.x][nxt.k]=1,Q.push(nxt);
		}
		
	}
	
	printf("%d",ans);
	
	
	
}