#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int N,B[25][25],ans = 1e9,list[25];
void cul(){
	int score[2] = {};
	for (int i = 1; i <= N; i++){
		for (int j = i + 1; j <= N; j++)
			if (list[i] && list[j]) score[0] += B[i][j] + B[j][i];
			else if (!list[i] && !list[j]) score[1] += B[i][j] + B[j][i];			
	}
	ans = min(ans, abs(score[0] - score[1]));
}

void go(int startIdx, int cnt){
	if (cnt == N / 2){
		cul();
		return;
	}
	for (int i = startIdx; i <= N; i++)
		if (!list[i]){
			list[i] = 1;
			go(i + 1, cnt + 1);
			list[i] = 0;
		}
}

int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &B[i][j]);
	go(1, 0);
	printf("%d\n", ans);
	return 0;
}
