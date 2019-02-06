/*
@Author		YJ Park
@Date		19. 02. 05
@Descript	Programmers Graph #01
*/

#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int> > vertex;

void BFS(vector<int> &dist) {
	queue<int> q;
	dist[0] = 0;
	q.push(0);

	while (!q.empty()) {
		int from = q.front(); q.pop();

		for (int i = 0; i < vertex[from].size(); i++) {
			int to = vertex[from][i];
			if (dist[to] == -1) {
				q.push(to);
				dist[to] = dist[from] + 1;
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 1;
	vertex.resize(n);
	vector<int> dist; dist.resize(n, -1);
	
	for (int i = 0; i < edge.size(); i++) {
		vertex[edge[i][0] - 1].push_back(edge[i][1] - 1);
		vertex[edge[i][1] - 1].push_back(edge[i][0] - 1);
	}

	BFS(dist);

	sort(dist.begin(), dist.end());

	int max = dist[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (max == dist[i]) answer++;
		else break;
	}

	return answer;
}