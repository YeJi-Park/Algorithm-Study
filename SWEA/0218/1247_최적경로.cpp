/*
@Author		YJ Park
@Date		19. 02. 16
@Descript	SWEA [#1247 S/W 문제해결 응용 - 최적경로]

			+)	도착지의 갯수가 적으니까 애초에 10x10으로 memoization 해놓고
				백트래킹만 하면 더 빠를 거 같기도 함
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <vector>

int min_v;
int N;

using namespace std;

// a부터 b까지의 거리 반환
int distance(pair<int, int> &a, pair<int, int> &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void DFS(int dist, vector<bool> &visit, int depth, vector<pair<int, int>> &location, int here) {

	// N개의 고객 방문했을 경우 마지막으로 집까지의 거리 추가
	if (depth == N) {
		dist += distance(location[here], location[N + 1]);
		min_v = min(dist, min_v);
		return;
	}
	
	for (int i = 1; i < N + 1; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dist += distance(location[i], location[here]);

			// 지금까지 계산한 최솟값보다 클 경우 더 이상 계산 X
			if(dist < min_v) 
				DFS(dist, visit, depth+1, location, i);
			visit[i] = false;
			dist -= distance(location[i], location[here]);
		}
	}
}

int main() {
	int size;
	cin >> size;

	for (int tc = 1; tc <= size; tc++) {
		cin >> N;

		vector<pair<int, int>> location(N+2);
		vector<bool> visit(N+2, false);
		pair<int, int> home;

		min_v = INT_MAX;

		int x, y;
		cin >> x >> y;
		location[0] = pair<int, int>(x, y);

		cin >> x >> y;
		home = pair<int, int>(x, y);

		for (int i = 1; i < N+1; i ++) {
			cin >> x >> y;
			location[i] = pair<int, int>(x, y);
		}

		location[N + 1] = home;

		visit[0] = true;
		for (int i = 1; i < N + 1; i++) {
			int t_dist = distance(location[0], location[i]);
			visit[i] = true;
			DFS(t_dist, visit, 1, location, i);
			visit[i] = false;
		}

		cout << "#" << tc << " " << min_v << endl;
	}
}