/*
@Author		YJ Park
@Date		19. 02. 13
@Descript	SWEA [#1868 파핑파핑 지뢰찾기]

			1.	DFS로 0 한번 눌렀을 때 같이 알 수 있는 영역의 갯수를 총 ans(N*N)에서 빼주기
				저기서 지뢰 갯수까지 빼주면? 눌러야 하는 최소 횟수일 거라고 생각했는데
				왜 답 다르게 나오는 지 아직도 이해 안됨ㅠㅠㅠㅠ
				=> 다음에 다시 해보기

			2.	1번 접근에서 수정해서 0인 경우에 한번에 눌리는 영역들 visit 체크
				visit 체크 안되있는 영역만 answer에 추가해줘서 계산

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

// 좌상, 상, 우상, 좌, 우, 좌하, 하, 우하 순으로 탐색! 
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// 지뢰 주변 영역들 1씩 늘려주기
void mine(int x, int y, vector<vector<int>> &map) {
	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx >= 0 && ty >= 0 && tx < N && ty < N) {
			if (map[tx][ty] == -1) continue;
			else map[tx][ty]++;
		}
	}
}

// 0인 영역과 함께 눌리는 영역들 DFS로 visit 체크
void DFS(int x, int y, vector<vector<bool>> &visit, vector<vector<int>> &map) {
	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx >= 0 && ty >= 0 && tx < N && ty < N) {
			if (map[tx][ty] == -1) continue;
			
			if (!visit[tx][ty]) {
				visit[tx][ty] = true;
				if (!map[tx][ty]) 
					DFS(tx, ty, visit, map);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		vector<vector<int>> map(N, vector<int>(N, 0));
		vector<vector<bool>> visit(N, vector<bool>(N, false));

		for(int i=0; i<N; i++)
			for (int j = 0; j < N; j++) {
				char c;
				cin >> c;
				if (c == '*') {
					map[i][j] = -1;
					mine(i, j, map);
				}
			}

		int answer = 0;
		for(int i=0; i<N; i++)
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0 && (!visit[i][j])) {
					visit[i][j] = true;
					DFS(i, j, visit, map);
					answer++;
				}
			}

		for(int i=0; i<N; i++)
			for (int j = 0; j < N; j++) {
				if (map[i][j] == -1) continue;
				if (!visit[i][j]) answer++;
			}

		cout << "#" << tc << " " << answer << endl;
	}
}