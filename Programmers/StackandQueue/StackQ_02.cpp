/*
@Author		YJ Park
@Date		19. 01. 11
@Descript	Programmers Stack/Queue #02
*/

#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	queue<pair<int, int>> q; // priority와 idx 저장할 Q

	int size = priorities.size();
	for (int i = 0; i < size; i++) {
		q.push(pair<int, int>(priorities[i], i)); 
	}

	// priorities 내림차 순 정렬
	sort(priorities.begin(), priorities.end(), greater<int>());

	int i = 0;
	while (i < size) {
		// 정렬된 prio v와 q의 prio 비교
		// 다를 경우 q의 맨뒤로 보내기
		if (priorities[i] != q.front().first) {
			q.push(q.front());
			q.pop();
		}
		else { // 같을 경우
			i++;
			// 원하는 location인 경우 return, 아닐 경우 pop
			if (q.front().second == location) return i;
			else q.pop();
		}
	}
}