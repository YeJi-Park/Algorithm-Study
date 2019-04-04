/*
@Author		YJ Park
@Date		19. 02. 19
@Descript	BOJ [#14503 로봇청소기]
*/

#include <iostream>

using namespace std;

int N, M, r, c, d, answer;
int map[50][50];
bool visit[50][50];
bool flag;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void DFS(int x, int y, int dir) {
	// 후진해서 온 경우 answer 안늘려줘도 됨
	if (flag) flag = false;
	else answer++;

	int td, tx, ty;
	int cnt = 0;

	// 보고 있던 방향의 왼쪽부터 탐색 시작
	while (cnt < 4) {
		td = (dir + 3 - cnt) % 4;
		tx = x + dx[td];
		ty = y + dy[td];

		// 탐색 중 청소 안한 영역 발견했을 경우
		if (tx >= 0 && ty >= 0 && tx < N && ty < M) {
			if (!visit[tx][ty] && !map[tx][ty]) {
				visit[tx][ty] = true;
				break;
			}
		}

		cnt++;
	}

	// cnt가 4인 경우 탐색을 다 했는데 청소할 영역이 없는 것이기 때문에 방향은 그대로 두고 후진!
	if (cnt == 4) {
		int temp = (td + 2) % 4;
		int tx = x + dx[temp];
		int ty = y + dy[temp];
		flag = true;

		if (tx >= 0 && ty >= 0 && tx < N && ty < M && !map[tx][ty]) {
			DFS(tx, ty, td);
		} // 탐색 중 청소 안한 영역 있는 거면 그냥 청소하러 가기
	}else DFS(tx, ty, td);
	
}

int main() {
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	answer = 0;

	visit[r][c] = true;
	DFS(r, c, d);

	cout << answer << endl;
}