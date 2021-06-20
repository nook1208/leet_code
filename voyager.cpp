#include<cstdio>
#include<algorithm>
using namespace std;
const int inf = 1e9;
int R, C, PR, PC, ansD = 0,k, maxT, fr[4] = {-1,0,1,0}, fc[4] = {0,1,0,-1};
bool chk[505][505][4];
char B[505][505], dir[4] = {'U','R','D','L'};
void dfs(int r, int c, int nowD, int cnt) {	
	if (r == 0 || c == 0 || r > R || c > C || B[r][c] == 'C') {
		if (cnt > maxT) {
			maxT = cnt;
			ansD = k;
		}
		return;
	}
	if (chk[r][c][nowD]) {
		if (maxT == inf) return;
		maxT = inf;
		ansD = k;
		return;
	}
	chk[r][c][nowD] = 1;
	int nextD;
	if (B[r][c] == 92) {
		nextD = 3 - nowD;
		dfs(r + fr[nextD], c + fc[nextD], nextD, cnt + 1);
	}
	else if (B[r][c] == '/') {
		nextD = (nowD % 2) ? nowD - 1 : nowD + 1;
		dfs(r + fr[nextD], c + fc[nextD], nextD, cnt + 1);
	}
	else
		dfs(r + fr[nowD], c + fc[nowD], nowD, cnt + 1);
	chk[r][c][nowD] = 0;	
}

int main() {
	scanf("%d%d", &R, &C);
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			scanf(" %c", &B[i][j]);
	scanf("%d%d",&PR, &PC);
	for (k = 0; k < 4; k++) 
		dfs(PR, PC, k, 0);	
	
	if (maxT == inf) {
		printf("%c\n", dir[ansD]);
		puts("Voyager");
	}
	else {
		printf("%c\n", dir[ansD]);
		printf("%d\n", maxT);
	}
	return 0;
}
