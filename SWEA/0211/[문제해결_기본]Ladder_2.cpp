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
		// ������ �Ÿ�,	���� ������ ��ġ
		int curr_move = 0, point = i;
		bool flag = true;

		// ������ �������鼭 ��ٸ� Ȯ��
		for (int j = 1; j < 100; j++) {
			curr_move++;

			// ���� ��ġ�� 0�� �ƴ� ��� ���ʿ� �ٸ� �ִ��� Ȯ��
			// �ٸ� ������ ���� ���������� ���� ������ ��ġ��ŭ �̵��Ÿ��� �߰�
			if (start[point]) {
				if (ladder[j][start[point] - 1]) {
					curr_move += (start[point] - start[point - 1]);
					point--;

					// �̵��Ÿ��� ���� �ּڰ����� Ŀ�� ��� �� Ž���� �ʿ� X
					if (curr_move > min_v) {
						flag = false;
						break;
					}

					continue;
				}
			}

			// �����ʿ� �ٸ� �ִ��� Ȯ��
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

		// �ּڰ��� ���
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

		// ù �� ���� �Է¹޾� �������� �� �� �ִ� �ε��� ���Ϳ� �߰�
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