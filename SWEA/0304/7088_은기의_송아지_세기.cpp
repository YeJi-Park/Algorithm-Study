/*
@Author		YJ Park
@Date		19. 03. 03
@Descript	SWEA [#7088 은기의 송아지 세기]
			
			그냥 세면 시간 초과ㅠㅠ
			입력 받을 때마다 i번째까지의 품종 갯수를 미리 저장해놓으면 해결
*/

#include <iostream>
#include <cstdio>

using namespace std;

int N, Q;
int cow_cnt[4][100001];

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &Q);
		printf("#%d\n", tc);

		int cnt[4]; // 품종번호 저장하는 변수
		cnt[1] = 0; cnt[2] = 0; cnt[3] = 0;

		int temp;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &temp);
			cnt[temp]++;

			for (int j = 1; j <= 3; j++)
				cow_cnt[j][i] = cnt[j]; // i번째 소까지 입력받았을 때 j 품종번호를 가진 소의 수
		}

		for (int i = 0; i < Q; i++) {
			int start, end;
			scanf("%d %d", &start, &end);

			int a, b, c;
			a = cow_cnt[1][end] - cow_cnt[1][start - 1];
			b = cow_cnt[2][end] - cow_cnt[2][start - 1];
			c = cow_cnt[3][end] - cow_cnt[3][start - 1];

			printf("%d %d %d\n", a, b, c);
		}
	}
}