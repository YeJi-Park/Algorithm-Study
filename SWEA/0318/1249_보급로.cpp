/*
@Author     YJ Park
@Date       19. 03. 13
@Descript   SWEA [#1249 4일차 - 보급로]
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <climits>
#include <queue>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int map[100][100], visit[100][100];
int N;

void BFS() {
	queue<pair<int, int> > q;
	q.push({ 0, 0 });

	// 왜 memset으로 초기화가 안되는지?_?
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = INT_MAX;

	visit[0][0] = 0;

	while (!q.empty()) {
		pair<int, int> from = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = from.first + dx[i]; int ty = from.second + dy[i];

			// 최단거리 갱신해가면서 map 전부 순회
			if (tx >= 0 && ty >= 0 && tx < N && ty < N) {
				if (visit[tx][ty] > visit[from.first][from.second] + map[tx][ty]) {
					visit[tx][ty] = visit[from.first][from.second] + map[tx][ty];
					q.push({ tx, ty });
				}
			}
		}
	}

}


int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%1d", &map[i][j]);

		BFS();

		printf("#%d %d\n", tc, visit[N - 1][N - 1]);
	}
}