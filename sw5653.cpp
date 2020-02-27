#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
struct cell{
	//stat은 현재 상태, 0:죽음 1:비활성화 2:활성화
	int y,x,life,cur,stat;
};
int TC;
bool cmp(cell a,cell b)
{
	return a.life>b.life;
}
int main(int argc, char *argv[]) {
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++)
	{
		int map[350][350];
		int visit[350][350]={0,};
		
		vector<cell> v;
		int n,m,K;
		scanf("%d %d %d",&n,&m,&K);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&map[i+150][j+150]);
				if(map[i+150][j+150]>0) {
					cell tmp={i+150,j+150,map[i+150][j+150],0,1};
					v.push_back(tmp);
					visit[i+150][j+150]=1;
					}
			}
		}
		
		for(int k=0;k<K;k++)
		{
			sort(v.begin(),v.begin()+v.size()-1,cmp);
			int size=v.size();
			for(int i=0;i<size;i++)
			{
				if(v[i].stat==1)
				{
					v[i].cur++;
					if(v[i].cur==v[i].life) v[i].stat=2;
				}
				else if(v[i].stat==2)
				{
					if(v[i].cur==v[i].life)
					{
						for(int d=0;d<4;d++)
						{
							int ny=v[i].y+dy[d];
							int nx=v[i].x+dx[d];
							bool flag=true;
							if(!visit[ny][nx])				
							{
								cell tmp={ny,nx,v[i].life,0,1};
								v.push_back(tmp);
								visit[ny][nx]=1;
							}
							
						}
					}
					v[i].cur--;
					if(v[i].cur==0) 
					{
						v.erase(v.begin()+i);i--;size--;
					}
				}
				
			}
		}
		int ans=0;
		for(int i=0;i<v.size();i++)
		{
			if(v[i].stat!=0) ans++;
		}
		printf("#%d %d\n",tc,ans);
	}
}