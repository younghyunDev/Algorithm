#include <iostream>
#include<stdio.h>
using namespace std;
int dx[4]={1,-1,0,0}; int dy[4]={0,0,1,-1};
int N,M;
char map[11][11];
int visited[11][11][11][11]={0,};
struct bid{
	int y,x;
};
int ans=-1;
bid R,B,G;
void DFS(int cnt)
{
	if(cnt>ans && ans!=-1) return;
	if(B.y==G.y && B.x==G.x) return;
	if(R.y==G.y && R.x==G.x){
		if(cnt<ans || ans==-1)	ans=cnt;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int R_nx=R.x;
		int R_ny=R.y;
		int B_nx=B.x;
		int B_ny=B.y;
		//빨간공 움직이기
		while(true)
		{
			if(map[R_ny][R_nx]!='#' && map[R_ny][R_nx]!='O')	{R_ny+=dy[i];R_nx+=dx[i];}
			else{
				if(map[R_ny][R_nx]=='#') {R_ny-=dy[i];R_nx-=dx[i];}
				break;
			}
		}
		//파란공 움지깅기
		while(true)
		{
			if(map[B_ny][B_nx]!='#' && map[B_ny][B_nx]!='O')	{B_ny+=dy[i];B_nx+=dx[i];}
			else{
				if(map[B_ny][B_nx]=='#') {B_ny-=dy[i];B_nx-=dx[i];}
				break;
			}
		}
		
		// 두 공이 움직이고 난 위치가 같을 때
		if(R_ny==B_ny && R_nx==B_nx)
		{
			//goal이면 상관 없음
			if(map[R_ny][R_nx]!='O')
			{
				int red_dist=abs(R_ny-R.y) + abs(R_nx-R.x);
				int blue_dist=abs(B_ny-B.y) + abs(B_nx-B.x);
				if(red_dist>blue_dist)	{R_ny-=dy[i],R_nx-=dx[i];}
				else	{B_ny-=dy[i],B_nx-=dx[i];}
			}
		}
		bid orig_R=R;
		bid orig_B=B;
		R.x=R_nx; R.y=R_ny; B.x=B_nx; B.y=B_ny;
		if(visited[R.y][R.x][B.y][B.x]==0)
		{
			visited[R.y][R.x][B.y][B.x]=1;
			DFS(cnt+1);
			visited[R.y][R.x][B.y][B.x]=0;
		}
		R=orig_R;B=orig_B;					
	}
}

int main(int argc, char *argv[]) {
	string tmp;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++) scanf("%s",map[i]);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) 
		{
			if(map[i][j]=='R')	{R.y=i;R.x=j;}
			else if(map[i][j]=='B') {B.y=i;B.x=j;}
			else if(map[i][j]=='O') {G.y=i;G.x=j;}
		}
	}
	visited[R.y][R.x][B.y][B.x]=1;
	DFS(0);
	printf("%d",ans);
}