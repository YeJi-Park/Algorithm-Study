/*
@Author		YJ Park
@Date		19. 01. 20
@Descript	Programmers Sort #03
*/

#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<int>());

	//h번 이상 인용된 논문이 h편 이상일 때 break
	int size = citations.size();
	if (citations[size - 1] > size) return size-1;

	for (int i = 0; i < size; i++) {
		if (citations[i] < (i + 1)) return i;
	}

	return answer;
}