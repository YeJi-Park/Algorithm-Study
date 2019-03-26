/*
@Author		YJ Park
@Date		19. 02. 16
@Descript	SWEA [#1247 S/W 문제해결 응용 - 최적경로]

+)	memoization 백트래킹

19. 02. 18
++) vector 대신에 pair 전역변수로 선언해서 속도 개선!

*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <vector>

using namespace std;

int min_v;
int N;
int memo[12][12];
bool visit[12];
pair<int, int> location[12];

void DFS(int dist, int depth, int here) {
	// N개의 고객 방문했을 경우 마지막으로 집까지의 거리 추가
	if (depth == N) {
		dist += memo[here][N + 1];
		min_v = min(dist, min_v);
		return;
	}

	for (int i = 1; i < N + 1; i++) {
		if (!visit[i]) {
			visit[i] = true;

			// 지금까지 계산한 최솟값보다 클 경우 더 이상 계산 X
			if (dist + memo[here][i] < min_v)
				DFS(dist + memo[here][i], depth + 1, i);

			visit[i] = false;
		}
	}
}

int main() {
	int size;
	cin >> size;

	for (int tc = 1; tc <= size; tc++) {
		cin >> N;

		pair<int, int> home;

		min_v = INT_MAX;

		int x, y;
		cin >> x >> y;
		location[0] = pair<int, int>(x, y);

		cin >> x >> y;
		home = pair<int, int>(x, y);

		for (int i = 1; i < N + 1; i++) {
			cin >> x >> y;
			location[i] = pair<int, int>(x, y);
		}

		location[N + 1] = home;

		for (int i = 0; i < N + 2; i++) {
			for (int j = i; j < N + 2; j++) {
				int dist = abs(location[i].first - location[j].first) +
					abs(location[i].second - location[j].second);
				memo[i][j] = dist;
				memo[j][i] = dist;
			}
		}

		visit[0] = true;
		for (int i = 1; i < N + 1; i++) {
			visit[i] = true;
			DFS(memo[0][i], 1, i);
			visit[i] = false;
		}

		cout << "#" << tc << " " << min_v << endl;
	}
}