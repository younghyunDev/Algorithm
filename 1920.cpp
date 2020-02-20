#include <iostream>
#include<algorithm>
using namespace std;
int N,M;
int number[100000];
bool flag;
void search(int val)
{
	int low=0,high=N-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(val==number[mid]) {flag=true;return;}
		if(val>number[mid])	low=mid+1;
		else high=mid-1;
	}	
}

int main(int argc, char *argv[]) {
	cin>>N;
	for(int i=0;i<N;i++)	cin>>number[i];
	sort(number,number+N);
	cin>>M;
	int ans[M];
	for(int i=0;i<M;i++)	cin>>ans[i];
	for(int i=0;i<M;i++)
	{
		flag=false;
		search(ans[i]);
		printf("%d\n",flag);
	}
}