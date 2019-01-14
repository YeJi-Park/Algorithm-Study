/*
@Author		YJ Park
@Date		19. 01. 11
@Descript	Programmers Stack/Queue #04
*/

#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int days = 0;
	int idx = -1;

	int size = progresses.size();
	for (int i = 0; i < size; i++) {

		// days 기준의 개발 진도
		int p = progresses[i] + (days * speeds[i]);

		// 배포 시점에서 개발 완료일 경우
		if (p >= 100) {
			answer[idx]++;
			continue;
		}

		// 배포까지 걸리는 날짜 계산
		while (p < 100) {
			p += speeds[i];
			days++;
		}

		answer.push_back(1);
		idx++;
	}

	return answer;
}