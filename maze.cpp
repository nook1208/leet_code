#include<cstdio>
#include<algorithm>
using namespace std;
int N, fr[4] = { -1,0,1,0 }, fc[4] = { 0,1,0,-1 }, dir = 2;
int R[2] = { 50,50 }, C[2] = { 50,50 },ans[105][105];
char inp[55];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf(" %c", &inp[i]);
	int r = 50, c = 50;
	ans[r][c] = 1;
	int idx = 0;
	while (idx < N) {
		if (inp[idx] == 'F')
			r += fr[dir], c += fc[dir];
		else if (inp[idx] == 'R')
			dir = (dir + 1) % 4;
		else
			dir = (dir - 1 + 4) % 4;
		ans[r][c] = 1;
		idx++;		
		R[0] = min(R[0], r);
		C[0] = min(C[0], c);
		R[1] = max(R[1], r);
		C[1] = max(C[1], c);
	}
	for (int i = R[0]; i <= R[1]; i++) {
		for (int j = C[0]; j <= C[1]; j++) {
			if (ans[i][j]) printf(".");
			else printf("#");
		}
		printf("\n");
	}
	return 0;
}
