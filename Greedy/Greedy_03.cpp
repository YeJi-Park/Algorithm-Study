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

	// k���� ���ڸ� Ȯ���ؼ� ���� ū ��(prefix)�� �տ� �ִ� ���ڵ� ����
	for (int i = 0; i < k+1; i++) {
		if (prefix < number[i]) {
			pfx_idx = i;
			prefix = number[i];
		}
	}

	answer = number.substr(pfx_idx, size - pfx_idx);
	k -= pfx_idx; // ������ ���� �� ��ŭ k ���̱�

	pfx_idx = 0;

	while (k>0) {
		char max = -1; int max_idx = -1;

		//prefix�� ���� ���ں��� k���� ���� Ȯ���ؼ� ���� ū �� max�� ����
		for (int i = pfx_idx+1; i < (pfx_idx+1)+(k+1); i++) {
			if (max < answer[i]) {
				max_idx = i;
				max = answer[i];
			}
		}

		// max�� 0�� ��� ���ӵ� k���� 0�� �ִٴ� ���̹Ƿ� ���� �տ� �ִ� 0 �Ѱ� ����
		if (max == '0') {
			answer.erase(answer.begin() + max_idx, answer.begin() + max_idx + 1);
			k--;
			continue;
		}

		// prefix ���ĺ��� max_idx ���� ���� �߶󳻱�
		int to_delete = max_idx - pfx_idx - 1;
		if (!to_delete) { 
 			pfx_idx++; 

			//prefix+k�� ���� ���ں��� ũ�ų� ���� ��� �ڿ������� k�� �ڸ���
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
