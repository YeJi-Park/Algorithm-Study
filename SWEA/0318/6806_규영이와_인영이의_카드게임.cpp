/*
@Author     YJ Park
@Date       19. 03. 16
@Descript   SWEA [#6808 규영이와 인영이의 카드게임]

			단순 DFS 계산인데 확률이라고 생각해서 오래걸림ㅠㅠㅠㅠ
*/

#include <iostream>
#include <string.h>

using namespace std;

int k_cards[9], i_cards[9];
int visit[9];
int win, lose;

void DFS(int depth, int k_score, int i_score) {
	if (depth == 9) {
		if (k_score > i_score) win++;
		else if (k_score < i_score) lose++;
		return;
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (!visit[i]) {
				visit[i] = true;
				int sum = k_cards[depth] + i_cards[i];
				if (k_cards[depth] > i_cards[i])
					DFS(depth + 1, k_score + sum, i_score);
				else DFS(depth + 1, k_score, i_score + sum);
				visit[i] = false;
			}
		}
	}
}

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		memset(visit, false, sizeof(visit));
		win = lose = 0;

		bool check[19] = {false, };
		for (int i = 0; i < 9; i++) {
			scanf("%d", &k_cards[i]);
			check[k_cards[i]] = true;
		}

		int cnt = 0;
		for (int i = 1; i < 19; i++) {
			if (!check[i]) i_cards[cnt++] = i;
		}

		DFS(0, 0, 0);

		printf("#%d %d %d\n", tc, win, lose);
	}
}