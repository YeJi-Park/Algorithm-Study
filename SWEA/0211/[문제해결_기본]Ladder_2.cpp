/*
@Author		YJ Park
@Date		19. 02. 10
@Descript	SW Academy [Ladder 2]
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int ladder[100][100];

int min_route(vector<int> &start) {
	int min_v = INT_MAX;
	int min_idx = -1;

	for (int i = 0; i < start.size(); i++) {
		// 움직인 거리,	현재 수직선 위치
		int curr_move = 0, point = i;
		bool flag = true;

		// 밑으로 내려가면서 사다리 확인
		for (int j = 1; j < 100; j++) {
			curr_move++;

			// 현재 위치가 0이 아닐 경우 왼쪽에 다리 있는지 확인
			// 다리 있으면 현재 수직선에서 왼쪽 수직선 위치만큼 이동거리에 추가
			if (start[point]) {
				if (ladder[j][start[point] - 1]) {
					curr_move += (start[point] - start[point - 1]);
					point--;

					// 이동거리가 이전 최솟값보다 커질 경우 더 탐색할 필요 X
					if (curr_move > min_v) {
						flag = false;
						break;
					}

					continue;
				}
			}

			// 오른쪽에 다리 있는지 확인
			if (start[point] != 99) {
				if (ladder[j][start[point] + 1]) {
					curr_move += (start[point + 1] - start[point]);
					point++;

					if (curr_move > min_v) {
						flag = false;
						break;
					}

					continue;
				}
			}

			if (curr_move > min_v) {
				flag = false;
				break;
			}
		}

		// 최솟값일 경우
		if (flag) {
			min_v = curr_move;
			min_idx = start[i];
		}

	}

	return min_idx;
}

int main() {


	for (int i = 1; i <= 10; i++) {
		int temp;
		vector<int> vertical;
		vector<vector<int>> horizontal(99, vector<int>());
		scanf("%d", &temp);

		// 첫 줄 따로 입력받아 시작점이 될 수 있는 인덱스 벡터에 추가
		for (int j = 0; j < 100; j++) {
			scanf("%d", &ladder[0][j]);
			if (ladder[0][j]) 
				vertical.push_back(j);
		}

		
		for (int j = 1; j < 100; j++)
			for (int k = 0; k < 100; k++) 
				scanf("%d", &ladder[j][k]);

		int ret = min_route(vertical);
		printf("#%d %d\n", i, ret);
	}
}