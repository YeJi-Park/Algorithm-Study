/*
@Author		YJ Park
@Date		19. 02. 22
@Descript	BOJ [#14501 ���]
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int max_profit;
pair<int, int> consult[16];

void DFS(int day, int sum) {
	// �� �°� ���� �� �ִ� ���
	if (day == N) {
		max_profit = max(sum, max_profit);
		return;
	}

	// ��¥ ���Ƽ� �� Ȯ���غ��� �ϴ� ���
	for (int i = day; i < N; i++) {

		//���� ��� ��¥�� ��� ��¥ ������ ��� ��� ����
		if (i + consult[i].first <= N) 
			DFS(consult[i].first + i, sum + consult[i].second);
	}

	// �� �°� ������ �ʴ� ��쿡�� ���ݱ��� ���� �ݾ׸����� ���
	max_profit = max(sum, max_profit);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> consult[i].first >> consult[i].second;
	}

	max_profit = INT_MIN;
	DFS(0, 0);

	cout << max_profit << endl;
}