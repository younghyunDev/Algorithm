#include <iostream>
#include<vector>
using namespace std;
int n,m;
int ans=0;
int chk[101]={false,};
vector<int> v[101];
int main(int argc, char *argv[]) {
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int tmp1,tmp2;
		scanf("%d %d",&tmp1,&tmp2);
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}
	chk[1]=true;
	for(int i=0;i<v[1].size();i++)
	{
		int x=v[1][i];
		chk[x]=true;
		for(int j=0;j<v[x].size();j++)
		{
			if(!chk[v[x][j]])
			{
				chk[v[x][j]]=true;
				v[1].push_back(v[x][j]);
			}
		}
	}
	
	for(int i=0;i<=n;i++)
	{
		if(chk[i]) ans++;
	}
	printf("%d",ans-1);
}