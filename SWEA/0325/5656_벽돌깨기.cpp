/*
@Author		YJ Park
@Date		19. 03. 23
@Descript	SWEA [#5656 벽돌 깨기]

			width, height 중간에 헷갈려서 오래걸럈다
			x, y라고 하지 않기!!!!!
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

int N, W, H;
int map[15][15];
int min_v;
bool bomb_map[15][15];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void count_brick() {
	int cnt = 0;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			if (map[i][j]) cnt++;

	min_v = min(cnt, min_v);
}

void map_copy(int to[15][15], int from[15][15]){
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			to[i][j] = from[i][j];
}

void map_set(bool line_check[15]) {
	for (int i = 0; i < W; i++) {
		// 폭탄이 닿지 않은 column의 경우 스택연산 X
		if (!line_check[i]) continue; 

		stack<int> s; // 맨 밑에서부터 쌓기 편하게 스택 선언
		for (int j = 0; j < H; j++) {
			if (map[j][i]) { // 폭탄 있을 경우 스택에 넣고 0으로 셋팅
				s.push(map[j][i]);
				map[j][i] = 0;
			}
		}

		if (!s.size()) continue; // 스택 비었을 경우 다음 column 체크

		int j = H - 1;
		while (!s.empty()) { // 맨 밑부터 스택 빌 때 까지 쌓기
			map[j][i] = s.top();
			s.pop();
			j--;
		}

	}
}

void bomb(int y) {
	int x = 99;
	for (int i = 0; i < H; i++) {
		if (map[i][y]) { // column 내려가면서 첫번째 블럭 어딨는지 확인
			x = i;
			break;
		}
	}

	if (x == 99) return; // 이번 column에 폭탄 없는 경우

	if (map[x][y] == 1) { // 폭탄 1이면 주변에 영향 없으므로 리턴
		map[x][y] = 0;
		return;
	}

	queue<pair<int, int> > q;
	q.push({ x,y });
	bool visit[15][15];
	bool line_check[15]; // 폭탄으로 영향 받은 라인 체크(스택 연산 줄이려고ㅠㅠ)
	memset(visit, false, sizeof(visit));
	memset(line_check, false, sizeof(line_check));
	visit[x][y] = true;
	line_check[y] = true;

	while (!q.empty()) {
		int tx = q.front().first; int ty = q.front().second;
		q.pop();

		int power = map[tx][ty];
		map[tx][ty] = 0;

		for (int i = 1; i <= power - 1; i++) { // power - 1만큼 4방향 확인
			for (int j = 0; j < 4; j++) {
				int nx = tx + (dx[j] * i); int ny = ty + (dy[j] * i);

				if (nx >= 0 && ny >= 0 && nx < H && ny < W && !visit[nx][ny] && map[nx][ny]) {
					visit[nx][ny] = true; // 똑같은 폭탄 두번 안넣게 visit 확인
					line_check[ny] = true;
					if (map[nx][ny] == 1) map[nx][ny] = 0;
					else q.push({ nx, ny }); // 폭탄 추가로 터질 경우에만 q에 추가
				}
			}
		}
	}

	map_set(line_check);
}

void DFS(int depth) {
	if (depth == N) {
		count_brick();
		return;
	}
	else {
		for (int i = 0; i < W; i++) {
			int copy_map[15][15]; // map 복원을 위해 복사
			map_copy(copy_map, map);
			bomb(i);
			DFS(depth + 1);
			map_copy(map, copy_map);
		}
	}
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> W >> H;
		min_v = INT_MAX;
		
		for (int i = 0; i < H; i++) 
			for (int j = 0; j < W; j++)
				cin >> map[i][j];
		
		DFS(0);
		printf("#%d %d\n", tc, min_v);

	}
}