#include <cstdio>
#include <vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int> number;
int chk[500000];
bool search(int val)
{
	int low=0,high=number.size()-1;
	while(high>=low)
	{
		int mid=(high+low)/2;
		if(number[mid]==val)
		{
			return true;
		}
		if(number[mid]<val) low=mid+1;
		else high=mid-1;
	}
	return false;
}

int main(int argc, char *argv[]) {
	scanf("%d",&N);
	int tmp;
	for(int i=0;i<N;i++){
		scanf("%d",&tmp);
		number.push_back(tmp);
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++) scanf("%d",&chk[i]);
	sort(number.begin(),number.end());
	for(int i=0;i<M;i++)
	{
		if(search(chk[i]))
		{
			printf("1 ");
		}
		else printf("0 ");
	}
}