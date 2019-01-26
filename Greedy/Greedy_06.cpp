/*
@Author		YJ Park
@Date		19. 01. 26
@Descript	Programmers Greedy #06
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int answer = 0;
	sort(weight.begin(), weight.end());

	// weight[0]�� 1�� �ƴϾ��� ��� answer�� 1
	answer = weight[0];

	for (int i = 1; i<weight.size(); i++) {
		// (answer+ 1)�� weight���� ���� ��� 
		// => ���� �� ���� ���� ���� ��
		if (answer + 1 < weight[i])
			break;

		answer += weight[i];
	}
	return answer + 1;
}