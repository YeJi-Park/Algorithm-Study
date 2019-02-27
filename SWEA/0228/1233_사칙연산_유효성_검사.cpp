/*
@Author		YJ Park
@Date		19. 02. 27
@Descript	SWEA [#1233 ��Ģ���� ��ȿ�� �˻�]

			DFS�� �������鼭 �Ұ����� ��� flag ���!
*/

#include <iostream>
#include <string.h>

using namespace std;

char node[201];
int child[201][2];
bool flag;
int N;

void DFS(int node_num) { // �ڽ� ���� ��� ��� ���� ���ڿ��� ��
	if (child[node_num][0] == -1) {
		if (node[node_num] <= '9' && node[node_num] >= '0')
			return;
		else {
			flag = false;
			return;
		}
	}
	else {
		DFS(child[node_num][0]); // ���� �ڽ�
		if (flag) DFS(child[node_num][1]); // ������ �ڽ�
		else return;

		if (flag) { // �ڽĵ� �� ��ȿ�� ��� ���� ���� �����ڿ�����
			if (node[node_num] == '+' || node[node_num] == '-' ||
				node[node_num] == '*' || node[node_num] == '/')
				return;
			else {
				flag = false;
				return;
			}
		}
	}
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		flag = true;

		int node_num;
		int half = N / 2;

		// 0 ~ half������ ������� �ƴϹǷ� �ڽ� �־����
		for (int i = 0; i < half; i++) {
			cin >> node_num;
			cin >> node[node_num] >> child[node_num][0] >> child[node_num][1];
		}

		// �������� �ڽ� X
		for (int i = half; i < N; i++) {
			cin >> node_num;
			cin >> node[node_num];

			// ��������ε� ���� �ƴ� ��� DFS �� �ʿ� X
			if (node[node_num] < '0' || node[node_num] > '9') {
				flag = false;
			}

			child[node_num][0] = child[node_num][1] = -1;
		}

		if (flag) DFS(1);

		cout << "#" << tc << " " << flag << endl;
	}
}