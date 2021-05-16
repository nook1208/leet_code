#include<cstdio>
#define MAX_R 65
#define MAX_C 15

int r1, r2, c1, c2;
int ans[MAX_R][MAX_C], maxV,maxLev;
int fr[4] = { -1, 0, 1, 0 }, fc[4] = { 0, 1, 0, -1 };

void init(){
	for (int i = 0; i < MAX_R; i++)
		for (int j = 0; j < MAX_C; j++)
			ans[i][j] = 0;
	maxV = 0;
	maxLev = 0;
}

int abs(int a){
	return (a < 0) ? -a : a;
}
int max(int a, int b){
	return (a > b) ? a : b;
}

void makeLine(int sr, int sc, int dir, int startV, int cnt){
	int nr = sr + fr[dir], nc = sc + fc[dir];
	int nowV = startV + 1;
	while (cnt--){
		if (r1 <= nr && nr <= r2 && c1 <= nc && nc <= c2){
			ans[nr - r1][nc - c1] = nowV;
			maxV = max(maxV, nowV);			
		}
		nr += fr[dir];
		nc += fc[dir];
		nowV++;
	}
}

void makeSquare(int r){
	int N = abs(r) * 2 + 1, diff = N - 1;
	int startV = N*N - 4 * diff;
	makeLine(r, r, 0, startV, diff);
	makeLine(r - diff, r, 3, startV + diff, diff);
	makeLine(r - diff, r - diff, 2, startV + diff * 2, diff);
	makeLine(r, r - diff, 1, startV + diff * 3, diff);
}

int levCnt(int val){
	int cnt = 0;
	while (val){
		val /= 10;
		cnt++;
	}
	return cnt;
}

int main(){
	init();
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	for (int i = r1; i <= r2; i++)
		for (int j = c1; j <= c2; j++)
			if (!ans[i - r1][j - c1]){
				if (i == 0 && j == 0)
					ans[i - r1][j - c1] = 1;
				else
					makeSquare(max(abs(i), abs(j)));
			}
	
	maxLev = levCnt(maxV);

	for (int i = r1; i <= r2; i++){
		for (int j = c1; j <= c2; j++){
			int r = i - r1, c = j - c1;
			int val = abs(ans[r][c]), cnt = 0;
			cnt = levCnt(val);

			for (int k = 0; k < maxLev - cnt; k++)
				printf(" ");
			printf("%d ", ans[r][c]);
		}
		puts("");
	}	

	return 0;
}
