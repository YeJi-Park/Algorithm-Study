/*
@Author		YJ Park
@Date		19. 04. 04
@Descript	SWEA [#2112 보호 필름]

			외 느리지
*/

#include <iostream>
#include <vector>

using namespace std;

int D, W, K, ans;
int min_v;
bool film[13][20];

bool can_pass() { // 이 필름 성능 통과인지
	for (int i = 0; i < W; i++) {

		bool flag = film[0][i]; int cnt = 0;
		for (int j = 0; j < D; j++){
			if (flag == film[j][i]) {
				if (++cnt == K) break;
			}
			else {
				flag = film[j][i];
				cnt = 1;
			}
		}

		if (cnt < K) return false;
	}

	return true;
}

void copy_film(bool src[][20], bool dst[][20], int sr, int dr) {
	for (int i = 0; i < W; i++)
		dst[dr][i] = src[sr][i];
}

void pouuur(bool mdc, int r) {
	for (int i = 0; i < W; i++)
		film[r][i] = mdc;
}

void DFS(int depth, int from) {
	if (depth > D || depth > min_v) return;
	else {
		if (can_pass()) {
			min_v = depth;
			return;
		}
		else {
			for (int i = from; i < D; i++) {
				bool copy[1][20];
				copy_film(film, copy, i, 0);
				// a 약품 넣고 dfs 돌아
				pouuur(1, i);
				DFS(depth + 1, i + 1);

				//b 약품 넣고 dfs 돌아
				pouuur(0, i);
				DFS(depth + 1, i + 1);
				
				// 맵 복원
				copy_film(copy, film, 0, i);
			}
		}
	}
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> D >> W >> K;
		min_v = 14;

		for (int i = 0; i < D; i++) 
			for (int j = 0; j < W; j++) 
				cin >> film[i][j];
		
		DFS(0, 0);

		printf("#%d %d\n", tc, min_v);
		
	}
}