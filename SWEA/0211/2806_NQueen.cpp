/*
@Author		YJ Park
@Date		19. 02. 09
@Descript	SW Academy  [#2806 N-Queen]
*/

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int nq;
int answer;

void DFS(int row, vector<int> &col) {
	if (row == nq) { // row�� nq ������ �������� ��
		answer++;
		return;
	}
	else {
		for (int i = 0; i < nq; i++) {
			bool flag = true; // ���� ���� �� �ִ��� Ȯ��

			for (int j = 0; j < row; j++)
				// ���ݱ��� ����� ���� ��ġ�� ��
				if (col[j] == i || abs(row - j) == abs(i - col[j])) {
					flag = false;
					break;
				}

			if (flag) {
				col[row] = i;
				DFS(row + 1, col);
			}
		}
	}
}

int main() {
	int case_num;
	cin >> case_num;

	for (int i = 0; i < case_num; i++) {
		cin >> nq;
		vector<int> col(nq);
		answer = 0;
		DFS(0, col);

		cout << "#" << i + 1 << " " << answer << '\n';
	}
}