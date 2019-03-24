/*
@Author		YJ Park
@Date		19. 03. 25
@Descript	BOJ [#16988 Baaaaaaaaaduk2(Easy)]

			- DFS로 바둑돌 놓을 위치 정함
			- 2개 놓으면 BFS로 적 바둑돌 찾고 0 있는지 확인
			=> 이 과정에서 바둑돌 2개 놓을 때 마다 적 바둑돌 위치 찾아야했음
			
			1. 바둑돌 위치 입력받고 BFS 먼저 돌아서 적 바둑돌 그룹별로 v에 저장
			2. 적 바둑돌 근처에 빈 칸 3개 이상일 경우 죽일 수 없으므로 v에서 제거
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

			for (int k = 0; k < 4; k++) { // 적 바둑돌 4방향 확인하면서 빈칸 한 개라도 있을 경우 break
				int nr = r + dy[k]; int nc = c + dx[k];

				if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
					if (!map[nr][nc]) {
						is_dead = false;
						break;
					}
				}
			}
		}

		if (is_dead) cnt += enemies[i].size(); // 그룹 내 바둑돌 다 돌았는데 빈칸 없었을 경우
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
				if (map[nr][nc] == 2) { // 같은 그룹의 바둑돌 벡터 저장
					q.push({ nr, nc });
					enemies[gnum].push_back({ nr, nc });
				}
				if (!map[nr][nc]) cnt++; // 빈칸 갯수

				if (cnt >= 3) { // 3개 이상일 경우 바둑돌 2개 놓아서 죽일 수 없음
					enemies.pop_back(); // 불필요한 연산 줄이기 위해 벡터 제거
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
			if (!visit[i][j] && map[i][j] == 2) { // 적 바둑돌일 경우 그룹짓기
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