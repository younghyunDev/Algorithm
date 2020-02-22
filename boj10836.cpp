#include <iostream>
#include <algorithm>
using namespace std;
int m, n;
int map[700][700];
int main() {
	
	scanf("%d %d",&m,&n);
	while (n--) {
		int i = m - 1, j = 0;
		int zero, one, two;
		scanf("%d %d %d",&zero,&one,&two);
		
		i -= zero;
		//zero인 부분이 세로 영역을 넘어가면 가로영역으로 옮겨주도록 한다.
		if (i < 0) j = -i,i = 0;
		
		//만약 맵 크기름 넘어가 되면 모두 0으로 해주고 다음 order를 받도록한다.
		if (j > m - 1) continue;
		//만약 1이 0이 아니라면 해당 부분 체크해주기
		if (one != 0)	map[i][j]++;
		
		//다시 초기화 하고 2인 부분 체크해주기 (위와 동일)
		i = m - 1;
		j = 0;
		
		i -= zero + one;
		if (i < 0) j = -i,i = 0;
		
		if (j > m - 1) continue;
		map[i][j]++;
		
		if (one == 0)	map[i][j]++;
	}
	//세로 부분 가장 아래부터 추가 되는 것 수정해주기
	for (int i = m - 2; i >= 0; i--)	map[i][0] += map[i + 1][0];
	//가로 부분 추가 되는 것 수정해주기
	for (int j = 1; j < m; j++)		map[0][j] += map[0][j - 1];
	//위에서 오른쪽이 최댓값이므로 맨윗줄을 출력하면된다.
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0)
				printf("%d ",map[i][j]+1);
			else
				printf("%d ",map[0][j]+1);
		}
		printf("\n");
	}
}