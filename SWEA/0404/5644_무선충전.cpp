/*
@Author		YJ Park
@Date		19. 04. 02
@Descript	SWEA [#5644 ���� ����]
			
			**����ó�� ��ġ�� �ʱ�**
			���������Ҹ� ������ ������ ��츦 ��ħ

			�� �� ������ Ǯ �� ���� �� ������ => �� �����غ���
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int M, A;
int moves[2][100];
int dr[5] = { 0, -1, 0, 1, 0 }; // X �� �� �� ��
int dc[5] = { 0, 0, 1, 0, -1 };
pair< pair<int, int>, pair<short, int> > chargers[8]; // { {��ǥ}, {����, ����} }
int map[11][11];

bool in_boundary(int r, int c) {
	return (r > 0 && c > 0 && r <= 10 && c <= 10);
}

void init() {
	for (int i = 1; i <= 10; i++) 
		for (int j = 1; j <= 10; j++) 
			map[i][j] = 0;
}

void spread_signal() {
	for (int i = 0; i < A; i++) {
		int r = chargers[i].first.first; int c = chargers[i].first.second;
		int coverage = chargers[i].second.first;

		// i��° �������� ���� ���� ���� ��� i��° ��Ʈ�� ǥ��
		for (int j = -coverage; j <= coverage; j++) {
			for (int k = -coverage; k <= coverage; k++) {
				if (abs(j) + abs(k) > coverage || !in_boundary(r+j, c+k)) 
					continue;
				else map[r+j][c+k] = map[r+j][c+k] | (1 << i);
			}
		}
	}
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> A;
		init();

		for (int i = 0; i < M; i++)
			cin >> moves[0][i];

		for (int i = 0; i < M; i++)
			cin >> moves[1][i];
		
		for (int i = 0; i < A; i++)
			cin >> chargers[i].first.second >> chargers[i].first.first
			>> chargers[i].second.first >> chargers[i].second.second;

		spread_signal();
		
		int ret = 0;
		pair<short, short> p1 = { 1, 1 };
		pair<short, short> p2 = { 10, 10 };

		int mv_idx = 0;
		M++;
		while (M--) {
			// p1, p2�� �ִ� ��ǥ�� ������ ��ȣ�� ��Ÿ���� ��Ʈ
			int co1, co2; co1 = map[p1.first][p1.second]; 
			co2 = map[p2.first][p2.second];

			int comm = co1 & co2; // ���� ������ ��Ʈ�� ǥ��

			if (comm) { // ������ ������ ���
				int max1, max2; max1 = max2 = 0; // ��� �� max ������

				for (int i = 0; i < 8; i++) { // ���� ������ ���� �ٸ� ������ ���� ����� MAX ��
					if ((comm >> i) & 1 ) // ���� ������ ����
						continue;

					if (co1 & (1 << i)) max1 = max(max1, chargers[i].second.second);
					if (co2 & (1 << i)) max2 = max(max2, chargers[i].second.second);
				}

				for (int i = 0; i < 8; i++) {
					if ((comm >> i) & 1) { // i��° �����Ұ� ���� ������
						if (!max1 && !max2) // max �� 0�� ��� ���� �����Ҹ� �ִ� ��� => �׳� p1 �����
							max1 = chargers[i].second.second;
						else { // ��� �� max �߿� �� ���� ���� ���� ������ ȥ�� ������ ��ü
							if (max1 < max2)
								max1 = max(max1, chargers[i].second.second);
							else 
								max2 = max(max2, chargers[i].second.second);
						}
					}
				}
					
				ret += (max1 + max2);
				
			}
			else { // ���� ������ ���� ���
				int max1, max2; max1 = max2 = 0;

				for (int i = 0; i < 8; i++) { // 0-7�� ������ �� ���鼭 �� ������ ���� ���� �ִ��� Ȯ���ؼ� max�� ����
					if (co1 & (1 << i)) 
						max1 = max(max1, chargers[i].second.second);
					if (co2 & (1 << i)) 
						max2 = max(max2, chargers[i].second.second);
				}

				ret += (max1 + max2);
			}

			
			//��ǥ �ٲ���
			p1.first += dr[moves[0][mv_idx]]; p1.second += dc[moves[0][mv_idx]];
			p2.first += dr[moves[1][mv_idx]]; p2.second += dc[moves[1][mv_idx]];
				
			mv_idx++;			
		} 

		printf("#%d %d\n", tc, ret);
	}

}