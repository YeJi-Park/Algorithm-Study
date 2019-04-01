/*
@Author		YJ Park
@Date		19. 04. 02
@Descript	SWEA [#5644 무선 충전]
			
			**예외처리 놓치지 않기**
			공통충전소만 여러개 공유할 경우를 놓침

			좀 더 간단히 풀 수 있을 것 같은데 => 더 생각해보기
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int M, A;
int moves[2][100];
int dr[5] = { 0, -1, 0, 1, 0 }; // X 상 우 하 좌
int dc[5] = { 0, 0, 1, 0, -1 };
pair< pair<int, int>, pair<short, int> > chargers[8]; // { {좌표}, {범위, 성능} }
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

		// i번째 충전소의 범위 내에 있을 경우 i번째 비트에 표시
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
			// p1, p2가 있는 좌표의 충전소 번호를 나타내는 비트
			int co1, co2; co1 = map[p1.first][p1.second]; 
			co2 = map[p2.first][p2.second];

			int comm = co1 & co2; // 공통 충전소 비트로 표시

			if (comm) { // 충전소 공유할 경우
				int max1, max2; max1 = max2 = 0; // 사람 별 max 충전량

				for (int i = 0; i < 8; i++) { // 공통 충전소 말고 다른 충전소 있을 경우의 MAX 값
					if ((comm >> i) & 1 ) // 공통 충전소 무시
						continue;

					if (co1 & (1 << i)) max1 = max(max1, chargers[i].second.second);
					if (co2 & (1 << i)) max2 = max(max2, chargers[i].second.second);
				}

				for (int i = 0; i < 8; i++) {
					if ((comm >> i) & 1) { // i번째 충전소가 공통 충전소
						if (!max1 && !max2) // max 다 0일 경우 공통 충전소만 있는 경우 => 그냥 p1 줘버림
							max1 = chargers[i].second.second;
						else { // 사람 별 max 중에 더 작은 값을 공통 충전소 혼자 쓰도록 대체
							if (max1 < max2)
								max1 = max(max1, chargers[i].second.second);
							else 
								max2 = max(max2, chargers[i].second.second);
						}
					}
				}
					
				ret += (max1 + max2);
				
			}
			else { // 공통 충전소 없는 경우
				int max1, max2; max1 = max2 = 0;

				for (int i = 0; i < 8; i++) { // 0-7번 충전소 다 돌면서 이 충전소 범위 내에 있는지 확인해서 max값 갱신
					if (co1 & (1 << i)) 
						max1 = max(max1, chargers[i].second.second);
					if (co2 & (1 << i)) 
						max2 = max(max2, chargers[i].second.second);
				}

				ret += (max1 + max2);
			}

			
			//좌표 바꿔줌
			p1.first += dr[moves[0][mv_idx]]; p1.second += dc[moves[0][mv_idx]];
			p2.first += dr[moves[1][mv_idx]]; p2.second += dc[moves[1][mv_idx]];
				
			mv_idx++;			
		} 

		printf("#%d %d\n", tc, ret);
	}

}