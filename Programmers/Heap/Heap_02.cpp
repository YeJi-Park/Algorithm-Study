/*
@Author		YJ Park
@Date		19. 01. 17
@Descript	Programmers Heap #02
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int passed = 0, i = 0; // passed == pq에 이미 들어가있는 원소를 나타내는 idx
	int size = dates.size();

	priority_queue<int> pq;

	// (k-1)개의 이상의 밀가루가 필요하므로 
	while (stock <= k - 1) {

		// 현재 갖고 있는 밀가루의 양(stock)으로 버틸 수 있는 날짜까지
		// pq에 supplies[i] PUSH
		for (i = passed; i < size; i++) {
			if (stock < dates[i]) break;
			else pq.push(supplies[i]);
		}

		passed = i;

		// 현재 공급받을 수 있는 밀가루 중에 가장 많은 양 공급받기
		stock += pq.top(); pq.pop();
		answer++;

	}

	return answer;
}