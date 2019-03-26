/*
@Author		YJ Park
@Date		19. 03. 26
@Descript	BOJ [#14888 연산자 끼워넣기]
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int number[11];
int op[4];
int N, max_v, min_v;

void DFS(int depth, int ret) {
	if (depth == N) {
		max_v = max(max_v, ret);
		min_v = min(min_v, ret);
		return;
	}
	else {
		if (op[0]) {
			op[0]--;
			DFS(depth + 1, ret + number[depth]);
			op[0]++;
		}
		if (op[1]) {
			op[1]--;
			DFS(depth + 1, ret - number[depth]);
			op[1]++;
		}
		if (op[2]) {
			op[2]--;
			DFS(depth + 1, ret * number[depth]);
			op[2]++;
		}
		if (op[3]) {
			op[3]--;
			DFS(depth + 1, ret / number[depth]);
			op[3]++;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> number[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	min_v = INT_MAX;
	max_v = INT_MIN;

	DFS(1, number[0]);

	cout << max_v << "\n" << min_v;
}