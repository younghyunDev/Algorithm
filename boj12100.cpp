#include <iostream>

using namespace std;

int n,ret;
struct BOARD{
	int map[20][20];
	void rotate(){
		int temp[20][20];
		for(int y=0;y<n;y++)
		{
			for(int x=0;x<n;x++)	temp[y][x]=map[n-x-1][y];
		}
		memcpy(map, temp, sizeof(temp));
	}
	int get_max()
	{
		int ret=0;
		for(int y=0;y<n;y++)
		{
			for(int x=0;x<n;x++)
			{
				if(ret<map[y][x])	ret=map[y][x];
			}
		}
		return ret;
	}
	
	void up(){
		int temp[20][20];
		for(int x=0;x<n;x++)
		{
			int flag=0,target=-1;
			for(int y=0;y<n;y++)
			{
				if(map[y][x]==0) continue;
				if(map[y][x]==temp[target][x] && flag==1)	temp[target][x]*=2,flag=0;
				else	temp[++target][x]=map[y][x],flag=1;
			}
			for(++target;target<n;target++)
			{
				temp[target][x]=0;
			}
		}
		memcpy(map, temp, sizeof(temp));
	}
};
void dfs(BOARD cur,int count)
{
	if(count==5)
	{
		int candi=cur.get_max();
		if(ret<candi)	ret =candi;
		return;
	}
	for(int dir=0;dir<4;dir++)
	{
		BOARD next=cur;
		next.up();
		dfs(next,count+1);
		cur.rotate();
	}
}
int main(int argc, char *argv[]) {
	BOARD board;
	scanf("%d",&n);
	for(int y=0;y<n;y++)
	{
		for (int x=0;x<n;x++)	scanf("%d",&board.map[y][x]);	
	}
	ret=0;
	dfs(board,0);
	printf("%d",ret);
}