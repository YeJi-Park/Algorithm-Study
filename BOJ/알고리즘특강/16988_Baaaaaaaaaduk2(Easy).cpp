/*
@Author		YJ Park
@Date		19. 03. 25
@Descript	BOJ [#16988 Baaaaaaaaaduk2(Easy)]

			- DFS�� �ٵϵ� ���� ��ġ ����
			- 2�� ������ BFS�� �� �ٵϵ� ã�� 0 �ִ��� Ȯ��
			=> �� �������� �ٵϵ� 2�� ���� �� ���� �� �ٵϵ� ��ġ ã�ƾ�����
			
			1. �ٵϵ� ��ġ �Է¹ް� BFS ���� ���Ƽ� �� �ٵϵ� �׷캰�� v�� ����
			2. �� �ٵϵ� ��ó�� �� ĭ 3�� �̻��� ��� ���� �� �����Ƿ� v���� ����
*/

#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

int map[20][20];
vector<vector <pair<int, int> > > enemies;
int N, M, max_v, group;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void count_death(){
	bool visit[20][20];
	memset(visit, false, sizeof(visit));
	int cnt = 0;

	for (int i = 0; i < enemies.size(); i++) {
		bool is_dead = true;

		for (int j = 0; j < enemies[i].size(); j++) {
			int r = enemies[i][j].first; int c = enemies[i][j].second;
			visit[r][c] = true;

			for (int k = 0; k < 4; k++) { // �� �ٵϵ� 4���� Ȯ���ϸ鼭 ��ĭ �� ���� ���� ��� break
				int nr = r + dy[k]; int nc = c + dx[k];

				if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
					if (!map[nr][nc]) {
						is_dead = false;
						break;
					}
				}
			}
		}

		if (is_dead) cnt += enemies[i].size(); // �׷� �� �ٵϵ� �� ���Ҵµ� ��ĭ ������ ���
	}

	max_v = max(max_v, cnt);
}

void DFS(int depth, int from) {
	if (depth == 2) {
		count_death();
		return;
	}
	else {
		for (int i = from; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!map[i][j]) {
					map[i][j] = 1;
					DFS(depth + 1, i);
					map[i][j] = 0;
				}
			}
		}
	}
}

void enemy_grouping(int r, int c, int gnum, bool visit[][20]) {
	queue<pair<int, int> > q;
	q.push({ r,c });
	visit[r][c] = true;

	int cnt = 0;

	while (!q.empty()) {
		int tr = q.front().first; int tc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = tr + dy[i]; int nc = tc + dx[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M && !visit[nr][nc]) {
				visit[nr][nc] = true;
				if (map[nr][nc] == 2) { // ���� �׷��� �ٵϵ� ���� ����
					q.push({ nr, nc });
					enemies[gnum].push_back({ nr, nc });
				}
				if (!map[nr][nc]) cnt++; // ��ĭ ����

				if (cnt >= 3) { // 3�� �̻��� ��� �ٵϵ� 2�� ���Ƽ� ���� �� ����
					enemies.pop_back(); // ���ʿ��� ���� ���̱� ���� ���� ����
					group--;
					while (!q.empty()) q.pop();
					break;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	bool visit[20][20];
	memset(visit, false, sizeof(visit));
	group = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && map[i][j] == 2) { // �� �ٵϵ��� ��� �׷�����
				enemies.push_back(vector < pair<int, int>>());
				enemies[group++].push_back({ i,j });
				enemy_grouping(i, j, group-1, visit);
			}
		}
	}

	max_v = 0;

	DFS(0, 0);
	cout << max_v << endl;
}