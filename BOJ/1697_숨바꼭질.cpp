/*
@Author		YJ Park
@Date		19. 02. 13
@Descript	BOJ [#1697 숨바꼭질]
*/

#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, K;
bool visit[MAX];

int BFS(int from) {
	queue<int> q;
	q.push(from);
	visit[from] = true;

	int depth = 0;
	// 각 깊이를 전부 검사했을 때 depth++
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			from = q.front(); q.pop();
			if (from == K) return depth;
			
			if (from < MAX && !visit[from + 1]) {
				visit[from + 1] = true;
				q.push(from + 1);
			}
			if (from > 0 && !visit[from - 1]) {
				visit[from - 1] = true;
				q.push(from - 1);
			}
			if (from * 2 < MAX && !visit[from * 2] ) {
				visit[from * 2] = true;
				q.push(from * 2);
			}
		}

		depth++;
	}
}

int main() {
	cin >> N >> K;
	cout << BFS(N);
}