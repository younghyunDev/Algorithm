#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
int map[9][9];
vector<pair<int,int> > prob;
bool finish=false;

void solve(int cnt)
{
	if(cnt==prob.size()) 
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++) printf("%d ",map[i][j]);
			printf("\n");
		}
		finish=true;
		return;
	}
	int tx=prob[cnt].first, ty=prob[cnt].second;
	//printf("first:%d %d\n",tx,ty);
	for(int i=1;i<=9;++i)
	{
		map[tx][ty]=i;
		
		bool flag=true;
		//행 확인하기
		bool chk[10]={false,};
		for(int j=0;j<9;++j)
		{
			if(!chk[map[tx][j]])
			{
				chk[map[tx][j]]=true;
			}
			else if(map[tx][j]!=0){flag=false;break;}
		}
		if(!flag)
		{
			map[tx][ty]=0;
			continue;
		}
		
		//열 확인하기
		memset(chk, 0, 10);
		for(int j=0;j<9;++j)
		{
			if(!chk[map[j][ty]])
			{
				chk[map[j][ty]]=true;
			}
			else if(map[j][ty]!=0) {flag=false;break;}
		}
		if(!flag)
		{
			map[tx][ty]=0;
			continue;
		}
		/*printf("\n");
		for(int m=0;m<9;m++)
		{
			for(int n=0;n<9;n++) printf("%d ",map[m][n]);
			printf("\n");
		}*/
		//사각형 확인하기
		memset(chk, 0, 10);
		for(int j=0;j<9;++j)
		{
			int x=tx/3*3+j/3;
			int y=ty/3*3+j%3;
			//printf("%d %d\n",x,y);
			if(!chk[map[x][y]])
			{
				chk[map[x][y]]=true;
			}
			else if(map[x][y]!=0) {flag=false;break;}
		}
		if(!flag)
		{
			map[tx][ty]=0;
			continue;
		}
		solve(cnt+1);
		map[tx][ty]=0;
		
	}
}

int main(int argc, char *argv[]) {
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;++j)
		{
			scanf("%d",&map[i][j]);
			if(map[i][j]==0) prob.push_back(make_pair(i,j));
		}
	}
	solve(0);
}