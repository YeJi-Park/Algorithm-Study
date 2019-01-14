/*
@Author		YJ Park
@Date		19. 01. 11
@Descript	Programmers Stack/Queue #04
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;
	int days = 0;
	int idx = -1;

	int size = progresses.size();

	for (int i = 0; i < size; i++) q.push(progresses[i]);

	for (int i = 0; i < size; i++) {
		int p = progresses[i] + (days * speeds[i]);
		if (p >= 100) {
			answer[idx]++;
			q.pop();
			continue;
		}
		
		while (p < 100) {
			p += speeds[i];
			days++;
		}

		answer.push_back(1);
		idx++;
	}

	return answer;
}