#include <iostream>

using namespace std;
int N;
int number[1000000];
int tmp[1000000];
int k=0;
void merge(int low, int mid, int high)

{
	//각각 분리된 애들끼리 정렬한 후에 다시 합쳐주기!
	int i = low, j = mid + 1, k = low;
	//합치면서 정리를 하도록한다.
	while (i <= mid && j <= high)
	{
		if (number[i] < number[j])
			tmp[k] = number[i++];
		else
			tmp[k] = number[j++];
		k++;
	}
	//남는 부분은 뒤에 붙여준다.
	if (i > mid)
		for (int idx = j; idx <= high; idx++)
			tmp[k++] = number[idx];
	else
		for (int idx = i; idx <= mid; idx++)
			tmp[k++] = number[idx];
			
	//합친걸 다시 arr에 넣어서 정렬시켜준다.
	for (int idx = low; idx <= high; idx++)
		number[idx] = tmp[idx];
}

 

void mergeSort(int low, int high)

{
	if (high>low)
	{
		int mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		merge(low, mid, high);
	}
}
int main(int argc, char *argv[]) {
	cin>>N;
	for(int i=0;i<N;i++) cin>>number[i];
	mergeSort(0,N-1);
	for(int i=0;i<N;i++) printf("%d\n",number[i]);
}