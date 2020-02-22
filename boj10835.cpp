#include <iostream>
#include<queue>
using namespace std;
int N;
queue<int> Q[2];
int val=0,ans=0;
bool finish=false;
int dp[2001][2001], n, a[2001], b[2001];
int solve(int y,int x)
{
			
	if (x == n || y == n)return 0;
	int &ret = dp[x][y];
	if (ret != -1)return ret;
	ret = max(solve(y + 1, x), solve(y + 1, x + 1));
	if (a[y] > b[x])
		ret = max(ret, solve(y, x + 1) + b[x]);
	return ret;
}

int main(int argc, char *argv[]) {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int j = 0; j < n; j++)
		scanf("%d", &b[j]);
	
	printf("%d\n", solve(0, 0));
	
	return 0;
}