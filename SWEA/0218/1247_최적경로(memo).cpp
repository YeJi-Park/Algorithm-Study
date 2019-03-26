/*
@Author		YJ Park
@Date		19. 02. 18
@Descript	BOJ [#14503 ·Îº¿Ã»¼Ò±â]

*/

#include <iostream>
#include <queue>

using namespace std;

int N, M, r, c, d, answer;
int map[50][50];
bool visit[50][50];
bool flag;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool DFS(int x, int y, int dir) {
	answer++;

	int td;
	for (int i = 0; i < 4; i++) {
		td = (dir + 3 - i) % 4;
		int tx = x + dx[td];
		int ty = y + dy[td];

		if (tx >= 0 && ty >= 0; tx < N && ty < M) {
			if(!visit[tx][ty] || !map[tx][ty])
				td = DFS()
		}
	}
}

int main() {
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	
	answer = 0;

	DFS(r, c, d);
}