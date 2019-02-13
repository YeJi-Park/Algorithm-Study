/*
@Author		YJ Park
@Date		19. 02. 13
@Descript	SWEA [#1868 �������� ����ã��]

			1.	DFS�� 0 �ѹ� ������ �� ���� �� �� �ִ� ������ ������ �� ans(N*N)���� ���ֱ�
				���⼭ ���� �������� ���ָ�? ������ �ϴ� �ּ� Ƚ���� �Ŷ�� �����ߴµ�
				�� �� �ٸ��� ������ �� ������ ���� �ȵʤФФФ�
				=> ������ �ٽ� �غ���

			2.	1�� ���ٿ��� �����ؼ� 0�� ��쿡 �ѹ��� ������ ������ visit üũ
				visit üũ �ȵ��ִ� ������ answer�� �߰����༭ ���

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

// �»�, ��, ���, ��, ��, ����, ��, ���� ������ Ž��! 
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// ���� �ֺ� ������ 1�� �÷��ֱ�
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

// 0�� ������ �Բ� ������ ������ DFS�� visit üũ
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