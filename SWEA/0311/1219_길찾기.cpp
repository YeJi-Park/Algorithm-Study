/*
@Author     YJ Park
@Date       19. 03. 07
@Descript   SWEA [#1219 ±Ê√£±‚]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

bool BFS(vector<vector<int>> &route) {
	queue<int> q;
	q.push(0);

	int visit[100];
	memset(visit, false, sizeof(visit));
	visit[0] = true;
	
	while (!q.empty()) {
		int from = q.front(); q.pop();
		
		if (route[from].empty()) return false;
		else {
			for (int i = 0; i < route[from].size(); i++) {
				int to = route[from][i];
				if (to == 99) return true;

				if (!visit[to]) {
					visit[to] = true;
					q.push(route[from][i]);
				}
			}
		}
	}
	return false;
}


int main() {
	int T = 10;
	for (int tc = 1; tc <= T; tc++) {
		int route_num; cin >> route_num;
		cin >> route_num;

		vector<vector<int>> route(100, vector<int>(2));

		for (int i = 0; i < route_num; i++) {
			int from, to;
			cin >> from >> to;
			route[from].push_back(to);
		}

		printf("#%d %d\n", tc, BFS(route));

	}
}