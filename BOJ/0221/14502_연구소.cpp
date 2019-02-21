/*
@Author		YJ Park
@Date		19. 02. 21
@Descript	BOJ [#14502 ������]

			1.	���̷��� ��ġ �Է� ���� �� ����
			2.	DFS�� �� 3�� ��ġ�ϴ� ��� ��� Ž��
			3.	�� 3�� ��ġ�Ϸ��� ��� �ٽ� DFS�� ���̷��� Ȯ��
			4.	Ȯ���Ų �� 0�� ���� ����

			+)	��ü���� - ��Ű�� �ݷ� ������ �� �����Ƿ� 
				0 ������ �����!!
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <string.h>

using namespace std;

int N, M;
int map[9][9];
int temp_map[9][9];
bool visit[9][9];
bool visit_2[9][9];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int v_num, cnt;
pair<int, int> virus[10];

// ���̷��� Ȯ��
void DFS_diffusion(int x, int y) {
	visit_2[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx >= 0 && ty >= 0 && tx < N && ty < M) {
			if (map[tx][ty]) continue;

			if (!visit_2[tx][ty]) {
				if (!map[tx][ty]) {
					temp_map[tx][ty] = 2;
					DFS_diffusion(tx, ty);
				}
			}
		}
	}
}

int zero_count() {
	int ret = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			if (!temp_map[i][j]) ret++;
		
	return ret;
}

void DFS_wall(int depth, int b_x) {
	// �� 3�� ��ġ�� ���
	if (depth == 3) {
		memset(visit_2, false, sizeof(visit_2));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) temp_map[i][j] = map[i][j];

		// ���̷��� Ȯ���Ŵ
		for (int i = 0; i < v_num; i++)
			DFS_diffusion(virus[i].first, virus[i].second);

		// ���������� ���� Ȯ��
		cnt = max(cnt, zero_count());

		return;
	}

	for (int i = b_x; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) continue;

			if (!visit[i][j]) {
				visit[i][j] = true;
				if (!map[i][j]) {
					map[i][j] = 1;
					DFS_wall(depth + 1, i);
					map[i][j] = 0;
				}
				visit[i][j] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	cnt = INT_MIN;

	// ������ �Է� �ް� �ʱ� virus ��ġ �̸� ����
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus[v_num] = pair<int, int>(i, j);
				v_num++;
			}
		}

	DFS_wall(0, 0);

	cout << cnt << endl;
}