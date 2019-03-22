/*
@Author		YJ Park
@Date		19. 03. 23
@Descript	SWEA [#5656 ���� ����]

			width, height �߰��� �򰥷��� �����Ɏf��
			x, y��� ���� �ʱ�!!!!!
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
		// ��ź�� ���� ���� column�� ��� ���ÿ��� X
		if (!line_check[i]) continue; 

		stack<int> s; // �� �ؿ������� �ױ� ���ϰ� ���� ����
		for (int j = 0; j < H; j++) {
			if (map[j][i]) { // ��ź ���� ��� ���ÿ� �ְ� 0���� ����
				s.push(map[j][i]);
				map[j][i] = 0;
			}
		}

		if (!s.size()) continue; // ���� ����� ��� ���� column üũ

		int j = H - 1;
		while (!s.empty()) { // �� �غ��� ���� �� �� ���� �ױ�
			map[j][i] = s.top();
			s.pop();
			j--;
		}

	}
}

void bomb(int y) {
	int x = 99;
	for (int i = 0; i < H; i++) {
		if (map[i][y]) { // column �������鼭 ù��° �� ������� Ȯ��
			x = i;
			break;
		}
	}

	if (x == 99) return; // �̹� column�� ��ź ���� ���

	if (map[x][y] == 1) { // ��ź 1�̸� �ֺ��� ���� �����Ƿ� ����
		map[x][y] = 0;
		return;
	}

	queue<pair<int, int> > q;
	q.push({ x,y });
	bool visit[15][15];
	bool line_check[15]; // ��ź���� ���� ���� ���� üũ(���� ���� ���̷���Ф�)
	memset(visit, false, sizeof(visit));
	memset(line_check, false, sizeof(line_check));
	visit[x][y] = true;
	line_check[y] = true;

	while (!q.empty()) {
		int tx = q.front().first; int ty = q.front().second;
		q.pop();

		int power = map[tx][ty];
		map[tx][ty] = 0;

		for (int i = 1; i <= power - 1; i++) { // power - 1��ŭ 4���� Ȯ��
			for (int j = 0; j < 4; j++) {
				int nx = tx + (dx[j] * i); int ny = ty + (dy[j] * i);

				if (nx >= 0 && ny >= 0 && nx < H && ny < W && !visit[nx][ny] && map[nx][ny]) {
					visit[nx][ny] = true; // �Ȱ��� ��ź �ι� �ȳְ� visit Ȯ��
					line_check[ny] = true;
					if (map[nx][ny] == 1) map[nx][ny] = 0;
					else q.push({ nx, ny }); // ��ź �߰��� ���� ��쿡�� q�� �߰�
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
			int copy_map[15][15]; // map ������ ���� ����
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