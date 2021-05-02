#include<cstdio>
using namespace std;
int C, K, val = 1,ans;
int main() {
	scanf("%d%d", &C, &K);

	for (int i = 0; i < K; i++)
		val *= 10;
	
	if (C % val) {
		ans = C / val;
		if (C % val >= val / 2)
			ans++;
		ans = ans * val;
	}
	else 
		ans = C;
	
	printf("%d\n", ans);

	return 0;
}
