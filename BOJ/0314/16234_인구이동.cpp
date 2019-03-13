/*
@Author		YJ Park
@Date		19. 03. 13
@Descript	BOJ [#16234 인구 이동]
*/

#include <iostream>
#include <queue>
#include <cmath>
#include <string.h>

using namespace std;

int N, L, R, cnt;
bool flag;
int map[50][50];
bool visit[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// 국경 열 수 있는지 확인
bool can_open(pair<int, int> &a, int x, int y) {
	int abs_v = abs(map[a.first][a.second] - map[x][y]);

	if (abs_v >= L && abs_v <= R) return true;
	else return false;
}

void BFS(int x, int y) {
	queue<pair<int, int> > q;
	vector<pair<int, int> > v; // 국경 열려있는 땅들의 리스트
	q.push(pair<int, int>(x, y));
	v.push_back(pair<int, int>(x, y));
	visit[x][y] = true;

	int sum = map[x][y];
	while (!q.empty()) {
		pair<int, int> from = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = from.first + dx[i]; int ty = from.second + dy[i];

			if (tx >= 0 && ty >= 0 && tx < N && ty < N && !visit[tx][ty]) {
				if (can_open(from, tx, ty)) {
					visit[tx][ty] = true;
					q.push(pair<int, int>(tx, ty));
					v.push_back(pair<int, int>(tx, ty));
					sum += map[tx][ty];
					flag = true; // 하나라도 국경 열렸을 경우 인구이동 진행
								 // => 다음 인구이동 가능한지 확인해야 함
				}
			}
		}
	}

	int size = v.size();
	int avg = sum / size;

	// 인구 이동
	if (size > 1) {
		for (int i = 0; i < size; i++) 
			map[v[i].first][v[i].second] = avg;
	}

}

int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	do {
		memset(visit, false, sizeof(visit));
		flag = false; // 인구 이동 일어났는지 확인하는 flag

		for (int i = 0; i < N; i++) {
			for (int j = 0; j< N; j++) {
				if (!visit[i][j]) BFS(i, j);
			}
		}

		if (flag) cnt++; // 인구이동 일어난 횟수

	} while (flag); // 인구 이동 일어났을 경우 다음 인구이동 가능한지 체크해야 함

	cout << cnt << endl;

}