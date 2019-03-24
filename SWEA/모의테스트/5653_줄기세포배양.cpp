/*
@Author		YJ Park
@Date		19. 03. 24
@Descript	SWEA [#5653 �ٱ⼼�����]

			�� ���÷��� �ٸ� Ǯ�� ����!_!
			q �迭�� power ���� ���� ����

*/

#include <iostream>
#include <queue>
#include <climits>

#define CENTER 250

using namespace std;

typedef struct Cell {
	int hp;
	int power;
}cell;

int N, M, K;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
cell map[500][500];

void init() {
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			map[i][j].hp = 0;
			map[i][j].power = 0;
		}
	}
}

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> K;
		init();
		queue<pair<int, int> > q[11];

		for (int i = 0; i < N; i++) {	
			for (int j = 0; j < M; j++) {
				int temp; cin >> temp;
				if (temp) { // ���� �ִ� ��쿡�� q�� �߰�
					map[CENTER + i][CENTER + j].hp = temp << 1;
					map[CENTER + i][CENTER + j].power = temp;

					q[temp].push({ CENTER + i, CENTER + j });
				}
			}
		}

		while (K--) {
			for (int i = 10; i >= 1; i--) {
				int qsize = q[i].size();

				for (int j = 0; j < qsize; j++) {
					int r = q[i].front().first;
					int c = q[i].front().second;
					q[i].pop();

					// ��Ȱ��->Ȱ���� ���� ������
					if (map[r][c].hp == map[r][c].power) {
						for (int k = 0; k < 4; k++) {
							int nr = r + dy[k]; int nc = c + dx[k];

							// power 0 �ƴ� ���� �̹� ���� �ִ� ��
							if (map[nr][nc].power) continue;
							map[nr][nc].power = map[r][c].power;
							map[nr][nc].hp = map[r][c].power << 1;

							q[i].push({ nr,nc });
						}
					}

					map[r][c].hp--;

					// hp ���������� q�� �ٽ� �߰�
					if (map[r][c].hp) q[i].push({ r,c });
				}
			}
		}

		int cnt = 0;
		for (int i = 1; i <= 10; i++) cnt += q[i].size();

		printf("#%d %d", tc, cnt);
	}
}