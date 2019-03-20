/*
@Author		YJ Park
@Date		19. 03. 18
@Descript	SWEA [#1225 7일차 - 암호생성기]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	for (int tc = 1; tc <= 8; tc++) {
		int trash; cin >> trash;

		int num[8];
		for (int i = 0; i < 8; i++) 
			cin >> num[i];
		
		bool flag = true;
		int start_idx = 0;

		while (flag) {
			int idx = start_idx;
			for (int i = 0; i < 5; i++) {
				idx = (start_idx + i) % 8;

				num[idx] -= i+1;
				if (num[idx] <= 0) {
					num[idx] = 0;
					flag = false;
					break;
				}

			}
			start_idx = (idx + 1) % 8;

		}

		printf("#%d ", tc);

		for (int i = 0; i < 8; i++) {
			int ttidx = (start_idx + i) % 8;
			printf("%d ", num[ttidx]);
		}

		printf("\n");
	}
}