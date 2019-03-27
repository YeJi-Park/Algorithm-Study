/*
@Author		YJ Park
@Date		19. 03. 26
@Descript	BOJ [#16236 아기 상어]
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int map[20][20];
int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };
int N, sec;
pair<int, int> shark;
pair<int, int> shark_size(2,2);
//int fish[7];

bool boundary(int r, int c) {
	return (r >= 0 && c >= 0 && r < N && c < N);
}

// r => c 적은 순으로 정렬
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first == b.first) return a.second < b.second;
	else return (a.first < b.first);
}

bool BFS() {
	int cnt = 0; // 이번 탐색에서 걸린 초 수 
	vector < pair<int, int> > candidate; // 먹을 수 있는 생선 후보들

	queue<pair<int, int> > q;
	q.push(shark);
	vector<vector<bool> > visit(N, vector<bool>(N, false));
	visit[shark.first][shark.second] = true;
	bool find = false; // 이번 탐색에서 먹을 수 있는 생선 있었는지 확인

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int r = q.front().first; int c = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) { // 4방향 확인
				int nr = r + dr[j]; int nc = c + dc[j];
				if (!boundary(nr, nc) || visit[nr][nc]) continue;
				visit[nr][nc] = true;

				if (map[nr][nc] > shark_size.first) continue;

				//못먹지만 지나갈 수 있는 생선
				if (!map[nr][nc] || map[nr][nc] == shark_size.first)
					q.push({ nr,nc });
				else if (map[nr][nc] < shark_size.first) { // 먹을 생선
					find = true;
					candidate.push_back({ nr, nc });
				}
			}
		}

		cnt++;

		if (find) {
			sort(candidate.begin(), candidate.end(), cmp); // 좌표 별 정렬

			if (!--shark_size.second) { // 상어 레벨업
				shark_size.first++; 
				shark_size.second = shark_size.first;
			}

			map[candidate[0].first][candidate[0].second] = 0;
			shark = candidate[0];

			break;
		}
	}

	if (find) { // 유효한 탐색이었을 경우 초 수 더해줌
		sec += cnt;
		return true;
	}
	else return false;

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j])
				if (map[i][j] == 9) {
					shark = { i,j };
					map[i][j] = 0;
				}
		}
	}

	while (BFS());

	cout << sec << '\n';
}