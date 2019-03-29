/*
@Author		YJ Park
@Date		19. 03. 28
@Descript	BOJ [#14500 ��Ʈ�ι̳�]
			
			�ٸ� ����� DFS�� 
			�Ǥä̤��� �� ��ü i,j���� �� ���⸸ ���� ���ؼ� ����
			���� �ɸ��µ� ����..
*/

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int N, M;
int max_v;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int map[500][500];
bool visit[500][500];

bool in_boundary(int r, int c) {
	return (r >= 0 && c >= 0 && c < M && r < N);
}

void DFS(int depth, int ret, int r, int c) {
	if (depth == 4) {
		max_v = max(max_v, ret);
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i]; int nc = c + dc[i];
			if (in_boundary(nr, nc) && !visit[nr][nc]) {
				visit[nr][nc] = true;
				DFS(depth + 1, ret + map[nr][nc], nr, nc);
				visit[nr][nc] = false;
			}
		}
	}
}

void woo() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) { // �� �� �� ��
				int ret = map[i][j];

				for (int l = 0; l < 4; l++) { //
					if (l == k) continue;
					int nr = i + dr[l]; int nc = j + dc[l];

					if (in_boundary(nr, nc))
						ret += map[nr][nc];
					else break;
				}

				max_v = max(max_v, ret);
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	max_v = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			visit[i][j] = true;
			DFS(1, map[i][j], i, j);
			visit[i][j] = false;
		}

	woo();

	cout << max_v << endl;
}