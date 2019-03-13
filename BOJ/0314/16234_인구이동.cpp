/*
@Author		YJ Park
@Date		19. 03. 13
@Descript	BOJ [#16234 �α� �̵�]
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

// ���� �� �� �ִ��� Ȯ��
bool can_open(pair<int, int> &a, int x, int y) {
	int abs_v = abs(map[a.first][a.second] - map[x][y]);

	if (abs_v >= L && abs_v <= R) return true;
	else return false;
}

void BFS(int x, int y) {
	queue<pair<int, int> > q;
	vector<pair<int, int> > v; // ���� �����ִ� ������ ����Ʈ
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
					flag = true; // �ϳ��� ���� ������ ��� �α��̵� ����
								 // => ���� �α��̵� �������� Ȯ���ؾ� ��
				}
			}
		}
	}

	int size = v.size();
	int avg = sum / size;

	// �α� �̵�
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
		flag = false; // �α� �̵� �Ͼ���� Ȯ���ϴ� flag

		for (int i = 0; i < N; i++) {
			for (int j = 0; j< N; j++) {
				if (!visit[i][j]) BFS(i, j);
			}
		}

		if (flag) cnt++; // �α��̵� �Ͼ Ƚ��

	} while (flag); // �α� �̵� �Ͼ�� ��� ���� �α��̵� �������� üũ�ؾ� ��

	cout << cnt << endl;

}