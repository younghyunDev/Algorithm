#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dx[]={1,-1,0,0},dy[]={0,0,-1,1};
int n,m,ans=0;
int map[100][100];
vector<pair<int,int> > v;
vector<pair<int,int> > cheese;
queue<pair<int,int> > Q;
bool chk(int y,int x)
{
	queue<pair<int,int> > tmp;
	bool visit[100][100];
	memset(visit, 0, sizeof(visit));
	tmp.push(make_pair(y,x));
	while(!tmp.empty())
	{
		y=tmp.front().first,x=tmp.front().second;tmp.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(ny>=n || ny<0 || nx<0 || nx>=m) return false;
			if(map[ny][nx]!=1 &&!visit[ny][nx])	
			{
				visit[ny][nx]=true;
				tmp.push(make_pair(ny,nx));
			}
		}

	}
	return true;
		
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==1)	cheese.push_back(make_pair(i,j));
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==0 && chk(i,j))
			{
				v.push_back(make_pair(i,j));
				map[i][j]=2;
			}
		}
	}
	
	while(cheese.size()!=0)
	{
		ans++;
	
		for(int i=0;i<cheese.size();i++)
		{
			int dirt=0;
			int cy=cheese[i].first,cx=cheese[i].second;
			if(map[cy+1][cx]==0) dirt++;
			if(map[cy-1][cx]==0) dirt++;
			if(map[cy][cx+1]==0) dirt++;
			if(map[cy][cx-1]==0) dirt++;
			if(dirt>=2) {
				Q.push(cheese[i]);
				cheese.erase(cheese.begin()+i);
				i--;
				}
		}
		while(!Q.empty())
		{
			pair<int,int> cur=Q.front();Q.pop();
			map[cur.first][cur.second]=0;
		}
		for(int i=0;i<v.size();i++)
		{
			int cy=v[i].first,cx=v[i].second;
			if(!chk(cy,cx)) {
				Q.push(v[i]);
				v.erase(v.begin()+i);
				i--;
				}
		}
		while(!Q.empty())
		{
			pair<int,int> cur=Q.front();Q.pop();
			map[cur.first][cur.second]=0;
		}
	}
	printf("%d",ans);
	
	
}