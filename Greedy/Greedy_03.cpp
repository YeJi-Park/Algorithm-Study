/*
@Author		YJ Park
@Date		19. 01. 22
@Descript	Programmers Greedy #03
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	char prefix = -1; int pfx_idx = -1;

	int size = number.size();

	// k개의 숫자를 확인해서 가장 큰 수(prefix)의 앞에 있는 숫자들 삭제
	for (int i = 0; i < k+1; i++) {
		if (prefix < number[i]) {
			pfx_idx = i;
			prefix = number[i];
		}
	}

	answer = number.substr(pfx_idx, size - pfx_idx);
	k -= pfx_idx; // 삭제한 숫자 수 만큼 k 줄이기

	pfx_idx = 0;

	while (k>0) {
		char max = -1; int max_idx = -1;

		//prefix의 다음 숫자부터 k개의 숫자 확인해서 제일 큰 수 max에 저장
		for (int i = pfx_idx+1; i < (pfx_idx+1)+(k+1); i++) {
			if (max < answer[i]) {
				max_idx = i;
				max = answer[i];
			}
		}

		// max가 0일 경우 연속된 k개의 0이 있다는 뜻이므로 가장 앞에 있는 0 한개 삭제
		if (max == '0') {
			answer.erase(answer.begin() + max_idx, answer.begin() + max_idx + 1);
			k--;
			continue;
		}

		// prefix 이후부터 max_idx 사이 숫자 잘라내기
		int to_delete = max_idx - pfx_idx - 1;
		if (!to_delete) { 
 			pfx_idx++; 

			//prefix+k가 남은 숫자보다 크거나 같을 경우 뒤에서부터 k개 자르기
			if (pfx_idx + k >= answer.size() - 1) {
				answer.erase(answer.end() - k, answer.end());
				break;
			}

			continue; 

		}

		answer.erase(answer.begin() + (pfx_idx + 1), answer.begin() + max_idx);

		pfx_idx = max_idx - to_delete - 1;
		k -= to_delete;
	}

	return answer;
}
