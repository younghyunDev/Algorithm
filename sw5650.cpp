#include <iostream>
#include<vector>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
vector<pair<int,int> > worm[5];
int TC,N;
int map[100][100];

int solve(int y,int x)
{
	int max_Val=0;
	if(map[y][x]!=0) return -1;
	int orig_y=y;
	int orig_x=x;
	for(int d=0;d<4;d++)
	{
		
		int ret=0;
		int cdy=dy[d];
		int cdx=dx[d];
		y=orig_y+cdy;
		x=orig_x+cdx;
		//printf("\n\n\n");
		while(true)
		{
			//printf("%d %d\n",y,x);
			
			//벽에 부딪히는지 확인
			if(y>=N || x>=N || y<0 || x<0)
			{
				ret++;
				cdx=-cdx;
				cdy=-cdy;
				x+=cdx;
				y+=cdy;
				continue;
			}
			int loc=map[y][x];
			//새로 가는 곳이 블랙홀이면 현재 점수 반환해주기
			if(loc==-1 || (y==orig_y && x==orig_x)){
				if(max_Val<ret) max_Val=ret;
				break;
			}
			//웜홀 이면
			else if(loc>5)
			{
				for(int i=0;i<worm[loc-6].size();i++)
				{

					if(worm[loc-6][i].first!=y || worm[loc-6][i].second!=x)	
					{
						//printf("worm: %d %d  y %d x %d\n",worm[loc-6][i].first,worm[loc-6][i].second,y,x);
						y=worm[loc-6][i].first+cdy;
						x=worm[loc-6][i].second+cdx;
						break;
					}
				}
				continue;
			}
			
			//방향별 처리 해주기
			else if(loc!=0)
			{
				ret++;
				if(loc==1)
				{
					if(cdy==1) cdy=0,cdx=1;
					else if(cdx==-1) cdy=-1,cdx=0;
					else cdy=-cdy,cdx=-cdx;
				}
				
				else if(loc==2)
				{
					if(cdy==-1) cdy=0,cdx=1;
					else if(cdx==-1) cdy=1,cdx=0;
					else cdy=-cdy,cdx=-cdx;
				}
				
				else if(loc==3)
				{
					if(cdy==-1) cdy=0,cdx=-1;
					else if(cdx==1) cdy=1,cdx=0;
					else cdy=-cdy,cdx=-cdx;
				}
				
				else if(loc==4)
				{
					if(cdy==1) cdy=0,cdx=-1;
					else if(cdx==1) cdy=-1,cdx=0;
					else cdy=-cdy,cdx=-cdx;
				}
				else if(loc==5)
				{
					cdy=-cdy,cdx=-cdx;
				}
				
			}
			y+=cdy,x+=cdx;
		}	
	}
	return max_Val;
}

int main(int argc, char *argv[]) {
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++)
	{
		for(int i=0;i<5;i++) worm[i].clear();
		int ans=0;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]>5) worm[map[i][j]-6].push_back(make_pair(i, j));
			}
		}	
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				int val=solve(i,j);
				//printf("ans: %d\n",val);
				if(ans<val)	ans=val;
			}
		}
		printf("#%d %d\n",tc,ans);
	}
	
}
