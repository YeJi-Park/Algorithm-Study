/*
@Author		YJ Park
@Date		19. 02. 16
@Descript	SWEA [#1227 S/W 문제해결 기본 - 미로2]
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <queue>


using namespace std;

int map[100][100];
int visit[100][100];

// 상 하 좌 우 순서
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool BFS(pair<int, int> start) {
	queue<pair<int, int> > q;
	q.push(start);
	visit[start.first][start.second] = true;

	bool ret = false;
	while (!q.empty()) {
		pair<int, int> from = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = dx[i] + from.first;
			int ty = dy[i] + from.second;

			if (tx > 0 && ty > 0 && tx < 100 && ty < 100) {
				if (map[tx][ty] == 3) return true;
				else if (!visit[tx][ty]) {
					visit[tx][ty] = true;
					if (!map[tx][ty]) {
						q.push(pair<int, int>(tx, ty));
					}
				}
			}
		}
	}

	return ret;
	
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int temp; cin >> temp;
		memset(map, -1, sizeof(map));
		memset(visit, false, sizeof(visit));
		
		pair<int, int> start;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				char c;
				cin >> c;
				map[i][j] = c - '0';
				if (map[i][j] == 2) start = pair<int, int>(i, j);
			}
		}

		bool answer = BFS(start);

		cout << "#" << tc << " " << answer << endl;
	}
}