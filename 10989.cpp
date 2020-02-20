#include<iostream>
using namespace std;
int number[10000001];
int N;
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int tmp;
		cin>>tmp;
		number[tmp]++;
	}
	for(int i=0;i<10000001;i++)
	{
		for(int j=0;j<number[i];j++)	cout<<i<<"\n";
	}
}