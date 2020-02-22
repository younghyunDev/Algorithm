#include <cstdio>
#include<vector>
using namespace std;
int K,arr[13];
vector<int> ans;
void solve(int cnt)
{
	if(ans.size()==6){
		for(int i=0;i<6;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
		return;
	}
	if(cnt==K) return;

	ans.push_back(arr[cnt]);
	solve(cnt+1);
	ans.erase(ans.begin()+ans.size()-1);
	solve(cnt+1);
	
	
}
int main(int argc, char *argv[]) {
	while(true)
	{
		scanf("%d",&K);
		if(K==0) return 0;
		for(int i=0;i<K;++i) scanf("%d",&arr[i]);
		solve(0);
		printf("\n");

	}
	}