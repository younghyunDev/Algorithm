#include<cstdio>
#include<vector>
#include<cmath>
#include <algorithm>
using namespace std;
int TC,N,K;

bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++)
	{
		vector<int> nums;
		vector<int> final;
		scanf("%d %d",&N,&K);
		
		char tmp[N+1];
		scanf("%s",&tmp);
		
		//입력 받기, 알파벳과 숫자를 구별해서 받는다.
		for(int i=0;i<N;i++)
		{
			if(tmp[i]>='A')	tmp[i]=tmp[i]-'A'+10;
			else tmp[i]=tmp[i]-'1'+1;	
			nums.push_back(tmp[i]);
		}
		int cnt=N/4;
		
		//cnt횟수만큼 회전을 한다. 그 이상 회전하는건 어차피 결과가 같다.
		for(int i=0;i<cnt;i++)
		{
			for(int j=0;j<4;j++)
			{
				int val=0;
				for(int k=0;k<cnt;k++)	val=val+nums[j*cnt+k]*pow(16,cnt-k-1); //16진수로 변환 시켜준다.
				bool flag=false;
				for(int k=0;k<final.size();k++)
				{
					if(final[k]==val)	 {flag=true;break;} //이미 final에 추가된 값이면 추가안함.
				}
				if(!flag) final.push_back(val);
			}
			//회전시켜주기
			nums.insert(nums.begin(), nums[nums.size()-1]);
			nums.erase(nums.begin()+nums.size()-1);
		}
		
		//정렬하기
		sort(final.begin(),final.begin()+final.size(),cmp);
		
		
		printf("#%d %d\n",tc,final[K-1]);
		
	}
	
}