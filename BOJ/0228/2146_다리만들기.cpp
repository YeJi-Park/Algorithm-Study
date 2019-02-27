/*
@Author		YJ Park
@Date		19. 02. 28
@Descript	BOJ [#2146 다리 만들기]
			1) 입력받은 후 BFS로 섬 구분짓기
			2) MAP 돌면서 주변이 바다인 경우 BFS 시작해서 주변 섬 찾기

			+) BFS 메모리 낭비 줄이기 위해서는 Q에 넣을 때 방문 체크 해줘야 함
*/

#include <iostream>
#include <climits>
#include <string.h>
#include <queue>

using namespace std;

int map[100][100];
bool visit[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, min_val;

void BFS_island() { // 섬 구역을 지정하는 BFS
	int num_island = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == -1) { // 아직 방문하지 않은 섬의 경우
				num_island++;
				queue<pair<int, int> > q;
				q.push(pair<int, int>(i, j));
				visit[i][j] = true;

				while (!q.empty()) {
					pair<int, int> here = q.front(); q.pop();
					map[here.first][here.second] = num_island; // 섬마다 번호 지정

					for (int k = 0; k < 4; k++) {
						int tx = here.first + dx[k];
						int ty = here.second + dy[k];

						if (tx >= 0 && ty >= 0 && tx < N && ty < N)
							if (!visit[tx][ty]) {
								visit[tx][ty] = true;
								if(map[tx][ty] == -1) {
									q.push(pair<int, int>(tx, ty));
							}
						}
					}
				}
			}
		}
	}
}

void BFS_bridge() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) {
				bool oc_flag = false;

				for (int k = 0; k < 4; k++) { // 주변에 바다 있는지 확인
					int tx = i + dx[k];
					int ty = j + dy[k];

					if (tx >= 0 && ty >= 0 && tx < N && ty < N && !map[tx][ty]) {
						oc_flag = true; // 주변 바다인 경우 탐색 시작
						break;
					}
				}

				if (!oc_flag) continue;
				int this_island = map[i][j]; // 현재 섬의 번호

				memset(visit, false, sizeof(visit));
				queue<pair<int, int> > q;
				q.push(pair<int, int>(i, j));
				visit[i][j] = true;
				
				int depth = 0;
				while (!q.empty()) {
					if (depth >= min_val) break;
					int size = q.size(); 

					// depth 별로 BFS 돌면서 주변에 있는 지역 탐색
					// => 섬일 경우 새로운 섬이면 min_v에 저장하고 끝냄
					// => 바다일 경우 Q에 넣어서 다시 탐색
					for (int k = 0; k < size; k++) {
						pair<int, int> here = q.front(); q.pop();
						int x = here.first; int y = here.second;
						
						for (int l = 0; l < 4; l++) {
							int tx = x + dx[l]; int ty = y + dy[l];

							if (tx >= 0 && ty >= 0 && tx < N && ty < N && !visit[tx][ty]) {
								visit[tx][ty] = true;

								if (map[tx][ty] && map[tx][ty] != this_island) {
									min_val = min(depth, min_val);
									break;
								}
								else if(!map[tx][ty])
									q.push(pair<int, int>(tx, ty));
							}
						}
					}

					depth++;
				}
			}
		}
	}
}

int main() {
	cin >> N;
	min_val = INT_MAX;

	int temp;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp) temp = -1; //섬일 경우 -1로 초기화
			map[i][j] = temp;
		}
	
	BFS_island();
	BFS_bridge();

	cout << min_val << endl;
}