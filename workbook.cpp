#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int N, M,inDegreeCnt[32005];
priority_queue<int> pq;
vector<vector<int>> adj;

int main(){
	scanf("%d%d", &N, &M);
	adj.resize(N + 1);
	for (int i = 0,a,b; i < M; i++){
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		inDegreeCnt[b]++;
	}
	for (int i = 1; i <= N; i++)
		if (inDegreeCnt[i] == 0)
			pq.push(-i);

	while (!pq.empty()){
		int now = -pq.top();
		pq.pop();
		printf("%d ", now);
		for (int i = 0; i < adj[now].size(); i++){
			int nextV = adj[now][i];
			if (--inDegreeCnt[nextV] == 0) pq.push(-nextV);
		}
	}
	return 0;

}
