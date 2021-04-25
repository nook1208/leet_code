#include<cstdio>
using namespace std;

char A[55], B[55],same, ansB[55][55];
int R, C,cnt[126];

void init() {
	for (int i = 0; i < 55; i++)
		for (int j = 0; j < 55; j++)
			ansB[i][j] = '.';
}

int main() {
	scanf("%s %s", A, B);
	init();
	
	for (int i = 0; B[i]; i++)
		cnt[B[i]]++;

	for (int i = 0; A[i]; i++)
		if (cnt[A[i]]) {
			same = A[i];
			break;
		}

	for (int i = 0; A[i]; i++)
		if (same == A[i]) {
			C = i;
			break;
		}

	for (int i = 0; B[i]; i++)
		if (same == B[i]) {
			R = i;
			break;
		}

	for (int i = 0; A[i]; i++)
		ansB[R][i] = A[i];
	for (int i = 0; B[i]; i++)
		ansB[i][C] = B[i];

	for (int i = 0; B[i]; i++) {
		for (int j = 0; A[j]; j++)
			printf("%c", ansB[i][j]);
		puts("");
	}


	return 0;
}
