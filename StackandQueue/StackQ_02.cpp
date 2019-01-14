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
	queue<pair<int, int>> q; // priority�� idx ������ Q

	int size = priorities.size();
	for (int i = 0; i < size; i++) {
		q.push(pair<int, int>(priorities[i], i)); 
	}

	// priorities ������ �� ����
	sort(priorities.begin(), priorities.end(), greater<int>());

	int i = 0;
	while (i < size) {
		// ���ĵ� prio v�� q�� prio ��
		// �ٸ� ��� q�� �ǵڷ� ������
		if (priorities[i] != q.front().first) {
			q.push(q.front());
			q.pop();
		}
		else { // ���� ���
			i++;
			// ���ϴ� location�� ��� return, �ƴ� ��� pop
			if (q.front().second == location) return i;
			else q.pop();
		}
	}
}