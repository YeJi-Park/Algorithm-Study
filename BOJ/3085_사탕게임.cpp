/*
@Author		YJ Park
@Date		19. 03. 30
@Descript	BOJ [#3085 ªÁ≈¡ ∞‘¿”]

*/
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

int N;
char map[50][50];
int max_candy;

void eat_candy() {
	for (int i = 0; i<N; i++) {
		char curr = map[i][0];
		int cnt = 1;
		for (int j = 1; j<N; j++) {
			if (curr != map[i][j]) {
				max_candy = max(cnt, max_candy);
				curr = map[i][j];
				cnt = 1;
			}
			else cnt++;
		}

		max_candy = max(cnt, max_candy);
	}

	for (int i = 0; i<N; i++) {
		char curr = map[0][i];
		int cnt = 1;
		for (int j = 1; j<N; j++) {
			if (curr != map[j][i]) {
				max_candy = max(cnt, max_candy);
				curr = map[j][i];
				cnt = 1;
			}
			else cnt++;
		}

		max_candy = max(cnt, max_candy);
	}
}

void change_candy(int r, int c, int nr, int nc) {
	int temp = map[r][c];
	map[r][c] = map[nr][nc];
	map[nr][nc] = temp;
}

int main() {
	char ff;
	scanf("%d", &N); scanf("%c", &ff);
	max_candy = INT_MIN;

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++)
			scanf("%c", &map[i][j]);
		scanf("%c", &ff);
	}

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			if (i<N - 1 && map[i][j] != map[i + 1][j]) {
				change_candy(i, j, i + 1, j);
				eat_candy();
				change_candy(i + 1, j, i, j);
				
			}
			if (j<N - 1  && map[i][j] != map[i][j + 1]) {
				change_candy(i, j, i, j+1);
				eat_candy();
				change_candy(i, j+1, i, j);
			}
		}
	}

	cout << max_candy << "\n";
}