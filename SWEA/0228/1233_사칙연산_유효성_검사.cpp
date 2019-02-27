/*
@Author		YJ Park
@Date		19. 02. 27
@Descript	SWEA [#1233 사칙연산 유효성 검사]

			DFS로 내려가면서 불가능할 경우 flag 찍기!
*/

#include <iostream>
#include <string.h>

using namespace std;

char node[201];
int child[201][2];
bool flag;
int N;

void DFS(int node_num) { // 자식 없을 경우 노드 값이 숫자여야 함
	if (child[node_num][0] == -1) {
		if (node[node_num] <= '9' && node[node_num] >= '0')
			return;
		else {
			flag = false;
			return;
		}
	}
	else {
		DFS(child[node_num][0]); // 왼쪽 자식
		if (flag) DFS(child[node_num][1]); // 오른쪽 자식
		else return;

		if (flag) { // 자식들 다 유효할 경우 현재 노드는 연산자여야함
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

		// 0 ~ half까지는 리프노드 아니므로 자식 있어야함
		for (int i = 0; i < half; i++) {
			cin >> node_num;
			cin >> node[node_num] >> child[node_num][0] >> child[node_num][1];
		}

		// 리프노드는 자식 X
		for (int i = half; i < N; i++) {
			cin >> node_num;
			cin >> node[node_num];

			// 리프노드인데 숫자 아닌 경우 DFS 돌 필요 X
			if (node[node_num] < '0' || node[node_num] > '9') {
				flag = false;
			}

			child[node_num][0] = child[node_num][1] = -1;
		}

		if (flag) DFS(1);

		cout << "#" << tc << " " << flag << endl;
	}
}