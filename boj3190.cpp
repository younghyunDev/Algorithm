#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int start=0,nxt=1;
int visit[101][101]={0,};
struct apple
{
	int x,y;
};

struct snake{
	int x,y,dir,t;
};
char times[10000];
queue<snake> S[2]; 
vector<apple> apples;
int N,K,L;
void init_visit()
{
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=N;j++) visit[i][j]=0;
	}
}
int main(int argc, char *argv[]) {
	scanf("%d %d",&N,&K);
	for(int i=0;i<K;i++)
	{
		apple tmp;
		scanf("%d %d",&tmp.y,&tmp.x);
		apples.push_back(tmp);
	}
	scanf("%d",&L);
	for(int i=0;i<L;i++)
	{
		int t;
		char d;
		scanf("%d %c",&t,&d);
		times[t]=d;
	}
	int cnt=0;
	snake tmp={1,1,0,0};
	S[start].push(tmp);
	while(true)
	{
		init_visit();

		bool end_flag=false;
		snake cur=S[start].front();
		cur.x+=dx[cur.dir];
		cur.y+=dy[cur.dir];
		cnt++;
		//벽에 부딪히는지 확인
		if(cur.x>N || cur.y>N || cur.x<1 || cur.y<1) break;
		
		
		bool flag=false;
		//사과 만나는지 확인
		for(int i=0;i<apples.size();i++)
		{
			apple tmp=apples[i];
			if(cur.x==tmp.x && cur.y==tmp.y) {flag=true,apples.erase(apples.begin()+i);break;}
		}
		
		snake next,last;
		while(!S[start].empty())
		{
			last=S[start].front();
			next=S[start].front();S[start].pop();
			next.x+=dx[next.dir];
			next.y+=dy[next.dir];
			next.t++;
			//자기들 끼리 만나고 있는지를 visit을 통해 확인하기
			if(visit[next.y][next.x]==1) {end_flag=true;break;}
			if(times[next.t]=='D')	next.dir=(next.dir+1)%4;	
			if(times[next.t]=='L')	next.dir=(next.dir+3)%4;
			visit[next.y][next.x]=1;
			S[nxt].push(next);
		}
		//사과 만나면 맨앞자리도 다시 추가해주기
		
		//자기들 끼리 만나고 있는지를 visit을 통해 확인하기
		if(visit[last.y][last.x]==1) {end_flag=true;break;}
		if(flag)
		{
			S[nxt].push(last);
		}
		if(end_flag) break;
		start=(start+1)%2;
		nxt=(nxt+1)%2;
		//시간이 되면 방향을 바꿔주도록 하기
		
		
	}
	
	printf("%d",cnt);
	
}