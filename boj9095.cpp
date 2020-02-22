#include <iostream>
#include<vector>
using namespace std;
int TC;
int n;
int dp[1000] = { 0 };
int solve(int cnt)
{
	if (cnt < 0)return 0;
	if (cnt <= 1)return 1;
	if (dp[cnt])return dp[cnt];
	return dp[n] = solve(cnt - 3) + solve(cnt - 2) + solve(cnt - 1);
}

int main(int argc, char *argv[]) {
	scanf("%d",&TC);
	for(int t=0;t<TC;t++)
	{
		scanf("%d",&n);
		printf("%d\n",solve(n));
	}
}