/*
@Author		YJ Park
@Date		19. 02. 19
@Descript	BOJ [#14503 �κ�û�ұ�]
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
	// �����ؼ� �� ��� answer �ȴ÷��൵ ��
	if (flag) flag = false;
	else answer++;

	int td, tx, ty;
	int cnt = 0;

	// ���� �ִ� ������ ���ʺ��� Ž�� ����
	while (cnt < 4) {
		td = (dir + 3 - cnt) % 4;
		tx = x + dx[td];
		ty = y + dy[td];

		// Ž�� �� û�� ���� ���� �߰����� ���
		if (tx >= 0 && ty >= 0 && tx < N && ty < M) {
			if (!visit[tx][ty] && !map[tx][ty]) {
				visit[tx][ty] = true;
				break;
			}
		}

		cnt++;
	}

	// cnt�� 4�� ��� Ž���� �� �ߴµ� û���� ������ ���� ���̱� ������ ������ �״�� �ΰ� ����!
	if (cnt == 4) {
		int temp = (td + 2) % 4;
		int tx = x + dx[temp];
		int ty = y + dy[temp];
		flag = true;

		if (tx >= 0 && ty >= 0 && tx < N && ty < M && !map[tx][ty]) {
			DFS(tx, ty, td);
		} // Ž�� �� û�� ���� ���� �ִ� �Ÿ� �׳� û���Ϸ� ����
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