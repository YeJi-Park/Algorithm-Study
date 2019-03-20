/*
@Author		YJ Park
@Date		19. 03. 20
@Descript	BOJ [#14499 주사위 굴리기]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, K, x, y;
int map[20][20];
int cmd[1000];
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };
int cube[6]; // 위, 아래, 앞, 뒤, 왼, 오 순

void set_cube(int dir) {
	int temp = cube[0];

	if (dir == 1) { // 동
		cube[0] = cube[4];
		cube[4] = cube[1];
		cube[1] = cube[5];
		cube[5] = temp;
	}
	else if (dir == 2) { // 서
		cube[0] = cube[5];
		cube[5] = cube[1];
		cube[1] = cube[4];
		cube[4] = temp;
	}
	else if (dir == 3) { // 남
		cube[0] = cube[3];
		cube[3] = cube[1];
		cube[1] = cube[2];
		cube[2] = temp;
	}
	else { // 북
		cube[0] = cube[2];
		cube[2] = cube[1];
		cube[1] = cube[3];
		cube[3] = temp;
	}
}

void roll() {
	for (int i = 0; i < K; i++) {
		int dir = cmd[i];
		int tx = x + dx[dir]; int ty = y + dy[dir];

		if (tx >= 0 && ty >= 0 && tx < N && ty < M) {
			x = tx; y = ty;
			set_cube(dir);

			if (map[x][y] != 0) {
				cube[1] = map[tx][ty];
				map[tx][ty] = 0;
			}
			else map[tx][ty] = cube[1];

			printf("%d\n", cube[0]);
		}
	}
}

int main() {
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
		cin >> cmd[i];

	roll();

}