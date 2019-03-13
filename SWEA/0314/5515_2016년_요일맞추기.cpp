/*
@Author		YJ Park
@Date		19. 03. 11
@Descript	SWEA [#5515 2016년 요일 맞추기]
*/

#include <iostream>

using namespace std;

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int m, d;
		cin >> m >> d;

		int cnt = 3;
		switch (m) {
		case 12: cnt += 30;
		case 11: cnt += 31;
		case 10: cnt += 30;
		case 9: cnt += 31;
		case 8: cnt += 31;
		case 7: cnt += 30;
		case 6: cnt += 31;
		case 5: cnt += 30;
		case 4: cnt += 31;
		case 3: cnt += 29;
		case 2: cnt += 31;
		case 1: cnt += d;
		}

		printf("#%d %d\n", tc, (cnt % 7));
	}
}