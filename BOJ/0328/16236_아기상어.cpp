/*
@Author		YJ Park
@Date		19. 03. 26
@Descript	BOJ [#16236 �Ʊ� ���]
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

// r => c ���� ������ ����
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first == b.first) return a.second < b.second;
	else return (a.first < b.first);
}

bool BFS() {
	int cnt = 0; // �̹� Ž������ �ɸ� �� �� 
	vector < pair<int, int> > candidate; // ���� �� �ִ� ���� �ĺ���

	queue<pair<int, int> > q;
	q.push(shark);
	vector<vector<bool> > visit(N, vector<bool>(N, false));
	visit[shark.first][shark.second] = true;
	bool find = false; // �̹� Ž������ ���� �� �ִ� ���� �־����� Ȯ��

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int r = q.front().first; int c = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) { // 4���� Ȯ��
				int nr = r + dr[j]; int nc = c + dc[j];
				if (!boundary(nr, nc) || visit[nr][nc]) continue;
				visit[nr][nc] = true;

				if (map[nr][nc] > shark_size.first) continue;

				//�������� ������ �� �ִ� ����
				if (!map[nr][nc] || map[nr][nc] == shark_size.first)
					q.push({ nr,nc });
				else if (map[nr][nc] < shark_size.first) { // ���� ����
					find = true;
					candidate.push_back({ nr, nc });
				}
			}
		}

		cnt++;

		if (find) {
			sort(candidate.begin(), candidate.end(), cmp); // ��ǥ �� ����

			if (!--shark_size.second) { // ��� ������
				shark_size.first++; 
				shark_size.second = shark_size.first;
			}

			map[candidate[0].first][candidate[0].second] = 0;
			shark = candidate[0];

			break;
		}
	}

	if (find) { // ��ȿ�� Ž���̾��� ��� �� �� ������
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