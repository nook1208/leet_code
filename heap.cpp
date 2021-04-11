#include <iostream>
using namespace std;

#define MAX 200005

int N;
int heap[MAX];
int last_idx = 1;

bool update(int bigger, int smaller) {
	int temp;

	if (heap[bigger] < heap[smaller]) {
		temp = heap[bigger];
		heap[bigger] = heap[smaller];
		heap[smaller] = temp;

		return true;
	}
	return false;
}

void push(int val) {
	int parent = last_idx / 2;
	int cur = last_idx;
	int u_ret = true;

	heap[last_idx++] = val;

	while (parent && u_ret) {
		u_ret = update(parent, cur);
		cur = parent;
		parent = cur / 2;
	}
}

int pop() {
	int ret = heap[1], u_ret = true;
	int cur = 1, bigger_child;
	int lc = cur * 2, rc = cur * 2 + 1;

	if (last_idx == 1)
		return 0;

	heap[1] = heap[--last_idx];
	heap[last_idx] = 0;
	while (heap[lc] && u_ret) {
		bigger_child = (heap[lc] < heap[rc]) ? rc : lc;
		u_ret = update(cur, bigger_child);
		cur = bigger_child;
		lc = cur * 2, rc = cur * 2 + 1;
	}

	return ret;
}

int main() {
	scanf("%d", &N);
	int val;

	for (int i = 0; i < N; i++) {
		scanf("%d", &val);
		if (val)
			push(val);
		else
			printf("%d\n", pop());
	}

	return 0;
}
