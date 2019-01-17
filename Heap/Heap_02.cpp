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
	int passed = 0, i = 0; // passed == pq�� �̹� ���ִ� ���Ҹ� ��Ÿ���� idx
	int size = dates.size();

	priority_queue<int> pq;

	// (k-1)���� �̻��� �а��簡 �ʿ��ϹǷ� 
	while (stock <= k - 1) {

		// ���� ���� �ִ� �а����� ��(stock)���� ��ƿ �� �ִ� ��¥����
		// pq�� supplies[i] PUSH
		for (i = passed; i < size; i++) {
			if (stock < dates[i]) break;
			else pq.push(supplies[i]);
		}

		passed = i;

		// ���� ���޹��� �� �ִ� �а��� �߿� ���� ���� �� ���޹ޱ�
		stock += pq.top(); pq.pop();
		answer++;

	}

	return answer;
}