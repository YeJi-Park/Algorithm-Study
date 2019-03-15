/*
@Author		YJ Park
@Date		19. 02. 28 => 19. 03. 16
@Descript	BOJ [#15683 감시]

			copy_map을 depth 별로 관리하는 부분이 문제였음!_!
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, camera_num;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int rotates[6] = { 0, 4, 2, 4, 4, 1 };
pair<int, int> cameras[8];
int min_v;
int map[8][8];

void safe_zone() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0) cnt++;

	min_v = min(min_v, cnt);
}

void camera_set(int sort, int dir, int x, int y, int depth) {
	if (sort == 1) {
		int tx = x + dx[dir]; int ty = y + dy[dir];

		while (tx >= 0 && ty >= 0 && tx<N && ty<M) {
			if (map[tx][ty]) {
				if (map[tx][ty] == 6) break;
			}
			else map[tx][ty] = 9;

			tx += dx[dir]; ty += dy[dir];
		}
	}
	else if (sort == 2) {
		if (dir == 1) dir = 2;

		for (int i = 0; i < 2; i++) {
			int tx = x + dx[i + dir]; int ty = y + dy[i + dir];

			while (tx >= 0 && ty >= 0 && tx<N && ty<M) {
				if (map[tx][ty]) {
					if (map[tx][ty] == 6) break;
				}
				else map[tx][ty] = 9;

				tx += dx[i + dir]; ty += dy[i + dir];
			}
		}
	}
	else if (sort == 3) {
		int temp_dir[2];

		if (dir % 2) temp_dir[1] = 2;
		else temp_dir[1] = 3;
		if (dir < 2)temp_dir[0] = 0;
		else temp_dir[0] = 1;

		for (int i = 0; i < 2; i++) {
			int tx = x + dx[temp_dir[i]]; int ty = y + dy[temp_dir[i]];

			while (tx >= 0 && ty >= 0 && tx<N && ty<M) {
				if (map[tx][ty]) {
					if (map[tx][ty] == 6) break;
				}
				else map[tx][ty] = 9;

				tx += dx[temp_dir[i]]; ty += dy[temp_dir[i]];
			}
		}
	}
	else if (sort == 4) {
		for (int i = 0; i < 4; i++) {
			if (dir == i) continue;
			int tx = x + dx[i]; int ty = y + dy[i];

			while (tx >= 0 && ty >= 0 && tx<N && ty<M) {
				if (map[tx][ty]) {
					if (map[tx][ty] == 6) break;
				}
				else map[tx][ty] = 9;

				tx += dx[i]; ty += dy[i];
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i]; int ty = y + dy[i];

			while (tx >= 0 && ty >= 0 && tx<N && ty<M) {
				if (map[tx][ty]) {
					if (map[tx][ty] == 6) break;
				}
				else map[tx][ty] = 9;

				tx += dx[i]; ty += dy[i];
			}
		}
	}
}


void map_copy(int map_a[8][8], int map_b[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map_a[i][j] = map_b[i][j];
		}
	}
}

void DFS(int depth, int from) {
	if (depth == camera_num) {
		safe_zone();
		return;
	}

	for (int i = from; i < camera_num; i++) {
		int x = cameras[i].first; int y = cameras[i].second;
		int cam = map[x][y];
		for (int j = 0; j < rotates[cam]; j++) {
			int temp_map[8][8];
			map_copy(temp_map, map);
			camera_set(cam, j, x, y, depth);
			DFS(depth + 1, i + 1);
			map_copy(map, temp_map);
		}
	}
}

int main() {
	cin >> N >> M;

	camera_num = 0;
	min_v = INT_MAX;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] && map[i][j] != 6)
				cameras[camera_num++] = pair<int, int>(i, j);
		}
	}

	DFS(0, 0);
	cout << min_v << endl;
}