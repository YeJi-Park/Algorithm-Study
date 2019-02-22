/*
@Author		YJ Park
@Date		19. 02. 22
@Descript	BOJ [#14501 퇴사]
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int max_profit;
pair<int, int> consult[16];

void DFS(int day, int sum) {
	// 딱 맞게 끝낼 수 있는 경우
	if (day == N) {
		max_profit = max(sum, max_profit);
		return;
	}

	// 날짜 남아서 더 확인해봐야 하는 경우
	for (int i = day; i < N; i++) {

		//다음 상담 날짜가 퇴사 날짜 이전일 경우 상담 가능
		if (i + consult[i].first <= N) 
			DFS(consult[i].first + i, sum + consult[i].second);
	}

	// 딱 맞게 끝나지 않는 경우에는 지금까지 받은 금액만으로 계산
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