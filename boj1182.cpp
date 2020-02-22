#include <cstdio>
#include <vector>
using namespace std;
int N,S;
int arr[20];
vector<int> ans;
int ret=0;
void solve(int cnt)
{
		if(cnt==N)
	{
		int sum=0;
		for(int i=0;i<ans.size();i++)
		{
			sum+=ans[i];
			
		}
		if(sum==S && ans.size()>0) {ret++;return;}
		return;
	}

	ans.push_back(arr[cnt]);
	solve(cnt+1);
	ans.erase(ans.begin()+ans.size()-1);
	solve(cnt+1);
}
int main(int argc, char *argv[]) {
	scanf("%d %d",&N,&S);
	for(int i=0;i<N;i++) scanf("%d",&arr[i]);
	solve(0);
	printf("%d",ret);
}