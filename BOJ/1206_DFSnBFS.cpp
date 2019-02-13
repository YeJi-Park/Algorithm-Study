/*
@Author		YJ Park
@Date		19. 02. 11
@Descript	BOJ [#1260 DFS와 BFS]
			입력값 무작위 순서라서 정렬하기 위해 그래프에 set 사용

			+)	벡터는 clear => resize 해버리기
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M, V;
vector<set<int> > graph;
vector<int> ret_DFS;
vector<int> ret_BFS;

void DFS(vector<bool> &visited, int depth, int from) {
	if (depth == N)
		return;
	else {
		for (auto i: graph[from]) {
			if (visited[i]) continue;
			else {
				visited[i] = true;
				ret_DFS.push_back(i);
				DFS(visited, depth + 1, i);
			}
		}
	}
}

void BFS(int from, vector<bool> &visited) {
	queue<int> q;
	q.push(from);
	visited[from] = true;

	while (!q.empty()) {
		int from = q.front(); q.pop();
		ret_BFS.push_back(from);

		for (auto i : graph[from]) {
			if (visited[i]) continue;
			else {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	
	cin >> N >> M >> V;
	graph.resize(N+1);

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1].insert(n2);
		graph[n2].insert(n1);
	}

	ret_DFS.push_back(V);
	vector<bool> visited(N+1, false);
	visited[V] = true;
	DFS(visited, 0, V);

	for (int i = 0; i < ret_DFS.size(); i++)
		cout << ret_DFS[i] << " ";
	cout << "\n";

	visited.clear();
	visited.resize(N + 1, false);
	BFS(V, visited);

	for (int i = 0; i < ret_BFS.size(); i++)
		cout << ret_BFS[i] << " ";
}