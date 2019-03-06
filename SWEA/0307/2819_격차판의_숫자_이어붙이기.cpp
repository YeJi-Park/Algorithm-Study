/*
@Author     YJ Park
@Date       19. 03. 04
@Descript   SWEA [#2819 격자판의 숫자 이어 붙이기]

			+) 메모리 관리 제대로!
*/

#include <iostream>
#include <set>
#include <string>
#include <string.h>

using namespace std;

int map[4][4];
set<string> s;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void DFS(int depth, int x, int y, string str) {
	if (depth == 7) {
		s.insert(str);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i]; int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < 4 && ty < 4) {
			DFS(depth + 1, tx, ty, str + to_string(map[tx][ty]));
		}
	}
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		s.clear();

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> map[i][j];

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				DFS(1, i, j, to_string(map[i][j]));
		
		printf("#%d %d\n", tc, s.size());
	}
}
