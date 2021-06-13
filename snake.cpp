#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long int LLi;
typedef struct _Line{
	LLi rs, cs, re, ce;
}Line;

LLi ans, L, N, nowR, nowC, Time, fr[4] = { -1, 0, 1, 0 }, fc[4] = { 0, 1, 0, -1 }, nowD;
char Dir;//now Direction
vector<Line> Lset;

Line make_Line(){
	Line newL = { nowR, nowC, nowR + fr[nowD] * Time, nowC + fc[nowD] * Time };
	return newL;
}
bool cross(LLi aL, LLi aR, LLi bL, LLi bR){//a가 기준 선.
	if (aL > aR) swap(aL, aR);
	if (bL > bR) swap(bL, bR);
	return (bR < aL || aR < bL) ? 0 : 1;	
}
LLi find_length(Line now){
	LLi ret = 1e12;
	if (nowD % 2 == 0) ret = min(ret, min(abs(nowR - now.rs), abs(nowR - now.re)));
	else ret = min(ret, min(abs(nowC - now.cs), abs(nowC - now.ce)));
	return ret;
}
int main(){
	scanf("%lld %lld", &L,&N);
	nowR = nowC = L + 1;
	nowD = 1;
	Lset.push_back({ 0, 1, 0, 2 * L + 1 });
	Lset.push_back({ 2 * L + 2, 1, 2 * L + 2, 2 * L + 1 });
	Lset.push_back({ 1, 0, 2 * L + 1, 0 });
	Lset.push_back({ 1, 2 * L + 2, 2 * L + 1, 2 * L + 2 });

	bool end = 0;
	LLi minSize = 1e12;
	Line newLine;

	for (int i = 1; i <= N + 1; i++){
		if(i <= N) scanf("%lld %c", &Time, &Dir);
		else Time = 1e12;

		if (end) continue;

		newLine = make_Line();
		if (i == 1) Lset.push_back({ 3 * L, 3 * L, 3 * L, 3 * L });
		for (int j = 0; j < Lset.size() - 1; j++){
			if (cross(Lset[j].rs, Lset[j].re, newLine.rs, newLine.re)
				&& cross(Lset[j].cs, Lset[j].ce, newLine.cs, newLine.ce)){
				end = 1;
				minSize = min(minSize, find_length(Lset[j]));
			}
		}		
		if (i == 1) Lset.pop_back();
		if (end) continue;
		Lset.push_back(newLine);
		nowR = newLine.re, nowC = newLine.ce;
		ans += Time;
		nowD = (Dir == 'L') ? (nowD + 3) % 4 : (nowD + 1) % 4;
	}
	if (end) ans += minSize;
	
	printf("%lld\n", ans);
	return 0;
}
