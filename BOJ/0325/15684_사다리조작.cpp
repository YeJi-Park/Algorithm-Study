/*
@Author		YJ Park
@Date		19. 03. 23
@Descript	BOJ [#15684 사다리 조작]
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, H, ret;
bool map[30][10]; // map[i][j]는 j열 => j+1열로 가는 i행의 가로줄

bool check_ladder() { // i번째 colunm의 결과가 i인지 확인
	bool flag = true;

	for (int i = 0; i < N; i++) {
		int curr = i; // 현재 사다리의 위치
		for (int j = 0; j < H; j++) {
			if (map[j][curr]) curr++;// j => j+1로 갈 수 있을 경우 사다리 위치++
			else if (curr && map[j][curr - 1]) curr--;
		}
	
		if (curr != i) { // 한 column이라도 결과 다를 경우 false
			return false;
		}
	}

	return flag;
}

void DFS(int t_depth, int cur_depth, int row) {
	if (cur_depth == t_depth) {
		if (check_ladder()) // 사다리 결과 체크
			ret = t_depth;
		return;
	}
	else {
		for (int i = row; i < H; i++) {
			for (int j = 0; j < N - 1; j++) { // j=> j+1로 가는 방식이라 n-1은 확인 안해도 됨
				if (map[i][j]) continue;
				map[i][j] = true;
				DFS(t_depth, cur_depth + 1, i);
				map[i][j] = false;

				if (ret != -1) return; // 한 결과라도 true일 때 더이상 DFS 돌지 않아도 됨
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
		if (ret != -1) break; // 0부터 dfs 돌기 때문에 언제나 최솟값!
	}

	cout << ret;
}