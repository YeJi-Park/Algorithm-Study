/*
@Author		YJ Park
@Date		19. 03. 03
@Descript	SWEA [#7088 ������ �۾��� ����]
			
			�׳� ���� �ð� �ʰ��Ф�
			�Է� ���� ������ i��°������ ǰ�� ������ �̸� �����س����� �ذ�
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

		int cnt[4]; // ǰ����ȣ �����ϴ� ����
		cnt[1] = 0; cnt[2] = 0; cnt[3] = 0;

		int temp;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &temp);
			cnt[temp]++;

			for (int j = 1; j <= 3; j++)
				cow_cnt[j][i] = cnt[j]; // i��° �ұ��� �Է¹޾��� �� j ǰ����ȣ�� ���� ���� ��
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