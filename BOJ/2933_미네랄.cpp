/*
@Author		YJ Park
@Date		19. 03. 26
@Descript	BOJ [#2933 미네랄]

			내리는 게 너무.....
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool map[100][100];
bool line_check[100];
int throoow[100];
int R, C;
int dr[2] = { 1, -1 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void cluster_check(int r, int c) {
	vector<vector<bool> > visit(R, vector<bool>(C, false));
	int floor = R - 1;

	for (int i = 0; i < C; i++) { // 바닥에 붙은 클러스터들 방문 체크~!~!
		if (map[floor][i] && !visit[floor][i]) {
			queue<pair <int, int> > q;
			q.push({ floor, i });
			visit[floor][i] = true;

			while (!q.empty()) {
				int x = q.front().first; int y = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nr = x + dx[i]; int nc = y + dy[i];
					if (nr < 0 || nc < 0 || nc >= C || nr >= R || visit[nr][nc])
						continue;

					if (map[nr][nc]) {
						visit[nr][nc] = true;
						q.push({ nr,nc });
					}
				}
			}
		}
	}

	// 내려야하는 칸 수 찾기
	int down = 101; //최대
	for (int i = 0; i < C; i++) {
		for (int j = R-1; j >= 0; j--) {
			if (map[j][i] && !visit[j][i]) { // 떠다니는 클러스터
				//이번 column에 내려야 할 칸 수 , 초기값은 바닥까지 내리는 경우
				int temp_down = R - 1 - j; 
				for (int k = j + 1; k < R; k++) {
					if (visit[k][i]) // 바닥에 붙은 클러스터 찾았으면 여기지만 내리기
						temp_down = k - j - 1; // 

					down = min(down, temp_down); // 제일 작은 값으로 내려줘야
				}
			}
		}
	}

	for (int i = 0; i < C; i++) {
		for (int j = R-1; j >= 0; j--) {
			if (j + down < R && map[j][i] && !visit[j][i]) {
				map[j + down][i] = map[j][i];
				map[j][i] = false;
			}
		}
	}

}

void print_map() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j]) cout << "x";
			else cout << ".";
		}
		cout << "\n";
	}
}

void crash(int height, bool dir) {
	height = R - height;
	int nc;
	(dir) ? (nc = C - 1) : (nc = 0); // 0: 왼=>오, 1: 오=>왼
	
	for (int i = 0; i < C; i++) { 
		if (map[height][nc]) { // 깨기
			map[height][nc] = false;
			cluster_check(height, nc);
			break;
		}

		nc += dr[dir];
	}
}

int main() {
	cin >> R >> C;
	char c; scanf("%c", &c);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &c);
			if (c == '.') map[i][j] = false;
			else map[i][j] = true;
		}

		scanf("%c", &c);
	}

	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> throoow[i];

	for (int i = 0; i < N; i++) 
		crash(throoow[i], (i % 2));

	print_map();
}