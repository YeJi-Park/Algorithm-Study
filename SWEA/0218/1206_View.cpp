/*
@Author		YJ Park
@Date		19. 02. 14
@Descript	SWEA [#1206 S/W 문제해결 기본 View]
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int size;
		cin >> size;

		vector<int> building(size);

		for (int i = 0; i < size; i++) 
			cin >> building[i];

		int answer = 0;

		// 현재 위치에서 -2 ~ 2 중 가장 큰 빌딩 크기 max_height에 저장
		// (지금 빌딩 - max_height)이 조망권 확보된 세대 수
		for (int i = 2; i < size - 2; i++) {
			int apt = building[i];

			int max_height = INT_MIN;
			for (int j = -2; j <= 2; j++)
				if (!j) continue;
				else max_height = max(max_height, building[i + j]);

				if (max_height < apt) 
					answer += (apt- max_height);
		}

		cout << "#" << tc << " " << answer << endl;
	}
}