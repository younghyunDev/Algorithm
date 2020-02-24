#include <iostream>
#include<queue>
using namespace std;
int n,k;
int ans=-1;
queue<pair<int,int> > Q;
bool chk[100001]={false,};


int main(int argc, char *argv[]) {
	scanf("%d %d",&n,&k);
	Q.push(make_pair(n, 0));
	if(n==k)
	{
		printf("0");
		return 0;
	}
	while(!Q.empty())
	{
		int n=Q.front().first;
		int cnt=Q.front().second;Q.pop();
		if(n==k) {
			while(!Q.empty()) Q.pop();
			ans=cnt;
			break;}
		if(0<n && 2*n<=100000 && !chk[2*n])
		{
			chk[n*2]=true;
			Q.push(make_pair(n*2, cnt+1));
		}
				
		if(0<=n-1 && !chk[n-1])
		{
			chk[n-1]=true;
			Q.push(make_pair(n-1, cnt+1));
		}
		if(n+1<=100000 && !chk[n+1])
		{
			chk[n+1]=true;
			Q.push(make_pair(n+1, cnt+1));
		}
	}
	
	printf("%d",ans);
	}