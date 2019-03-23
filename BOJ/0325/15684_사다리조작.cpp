/*
@Author		YJ Park
@Date		19. 03. 23
@Descript	BOJ [#15684 ��ٸ� ����]
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, H, ret;
bool map[30][10]; // map[i][j]�� j�� => j+1���� ���� i���� ������

bool check_ladder() { // i��° colunm�� ����� i���� Ȯ��
	bool flag = true;

	for (int i = 0; i < N; i++) {
		int curr = i; // ���� ��ٸ��� ��ġ
		for (int j = 0; j < H; j++) {
			if (map[j][curr]) curr++;// j => j+1�� �� �� ���� ��� ��ٸ� ��ġ++
			else if (curr && map[j][curr - 1]) curr--;
		}
	
		if (curr != i) { // �� column�̶� ��� �ٸ� ��� false
			return false;
		}
	}

	return flag;
}

void DFS(int t_depth, int cur_depth, int row) {
	if (cur_depth == t_depth) {
		if (check_ladder()) // ��ٸ� ��� üũ
			ret = t_depth;
		return;
	}
	else {
		for (int i = row; i < H; i++) {
			for (int j = 0; j < N - 1; j++) { // j=> j+1�� ���� ����̶� n-1�� Ȯ�� ���ص� ��
				if (map[i][j]) continue;
				map[i][j] = true;
				DFS(t_depth, cur_depth + 1, i);
				map[i][j] = false;

				if (ret != -1) return; // �� ����� true�� �� ���̻� DFS ���� �ʾƵ� ��
			}
		}
	}
}

int main() {
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = true;
	}

	ret = -1;
	for (int i = 0; i <= 3; i++) {
		DFS(i, 0, 0);
		if (ret != -1) break; // 0���� dfs ���� ������ ������ �ּڰ�!
	}

	cout << ret;
}