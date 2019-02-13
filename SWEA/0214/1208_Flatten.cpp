/*
@Author		YJ Park
@Date		19. 02. 11
@Descript	SW Academy [S/W 문제해결 기본 1일차 - Flatten]
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	for (int i = 1; i <= 10; i++) {
		vector<int> boxes;

		int dump; cin >> dump;

		for (int j = 0; j < 100; j++) {
			int bx;

			cin >> bx;
			boxes.push_back(bx);
		}

		sort(boxes.begin(), boxes.end());

		while (dump > 0 ) {
			if ((boxes[99] - boxes[0]) <= 1) break;
			else {
				dump--;
				boxes[99]--;
				boxes[0]++;
				sort(boxes.begin(), boxes.end());
			}
		}

		cout << "#" << i <<" " << boxes[99] - boxes[0] << endl;

	}
}