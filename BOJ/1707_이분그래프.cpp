/*
@Author		YJ Park
@Date		19. 03. 29
@Descript	BOJ [#1707 이분그래프]

			[color] 0: 방문 X,  1/2: 부모노드와 구분해주기 위한 값
			초기 값 1로 주고 세대별로 2, 1 ~ 로 저장
			이미 방문한 노드인데 부모와 같은 값일 경우 이분 그래프 X
			
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<short> color;
bool is_bipartite;
vector<vector<int> > v;

void BFS(int from) {
	queue<int> q;
	q.push(from);
	color[from] = 1;

	while (!q.empty()) {
		int node = q.front(); q.pop();

		for (int i = 0; i<v[node].size(); i++) {
			int next = v[node][i];
			if (color[next]) {
				if (color[next] == color[node]) {
					is_bipartite = false;
					break;
				}
				else continue;
			}
			else {
				if (color[node] == 1) color[next] = 2;
				else color[next] = 1;

				q.push(next);
			}
		}

		if (!is_bipartite) break;
	}
}

int main() {
	int K; cin >> K;
	for (int tc = 0; tc < K; tc++) {
		int N, M, answer = 0;
		cin >> N >> M;
		color.clear(); v.clear();
		color.resize(N + 1, 0);
		v.resize(N + 1, vector<int>());
		is_bipartite = true;

		for (int i = 0; i < M; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			v[n1].push_back(n2);
			v[n2].push_back(n1);
		}

		for (int i = 1; i <= N; i++) {
			if (!color[i]) {
				BFS(i);
				if (!is_bipartite) break;
			}
		}

		(is_bipartite) ? (cout << "YES\n") : (cout << "NO\n");
	}
}