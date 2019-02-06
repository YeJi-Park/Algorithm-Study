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

	// weight[0]이 1이 아니었을 경우 answer는 1
	answer = weight[0];

	for (int i = 1; i<weight.size(); i++) {
		// (answer+ 1)이 weight보다 작을 경우 
		// => 만들 수 없는 가장 작은 수
		if (answer + 1 < weight[i])
			break;

		answer += weight[i];
	}
	return answer + 1;
}