/*
@Author		YJ Park
@Date		19. 02. 14
@Descript	SWEA [#1206 S/W �����ذ� �⺻ View]
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

		// ���� ��ġ���� -2 ~ 2 �� ���� ū ���� ũ�� max_height�� ����
		// (���� ���� - max_height)�� ������ Ȯ���� ���� ��
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