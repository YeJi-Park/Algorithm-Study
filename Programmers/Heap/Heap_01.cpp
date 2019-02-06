/*
@Author		YJ Park
@Date		19. 01. 17
@Descript	Programmers Heap #01
*/

#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	// 내림차 순으로 정렬된 pq
	priority_queue<int, vector<int>, greater<int>> pq; 

	int size = scoville.size();
	for (int i = 0; i < size; i++) pq.push(scoville[i]);

	while (pq.top() < K) { 
		// pq의 원소가 1개여서 K 이상으로 만들 수 없는 경우
		if (pq.size() == 1) return -1;

		int mixed = pq.top(); pq.pop();
		mixed += pq.top() * 2; pq.pop();
		pq.push(mixed);
		answer++;
	}

	return answer;
}