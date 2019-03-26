/*
@Author		YJ Park
@Date		19. 03. 25
@Descript	Programmers [����Ž�� Level 1 - ���ǰ�� ]
*/

#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int size = answers.size();

	int studA[5] = { 1,2,3,4,5 };
	int studB[4] = { 1,3,4,5 };
	int studC[5] = { 3,1,2,4,5 };

	int result[3] = { 0,0,0 };
	int idx[3] = { 0,0,0 };

	for (int i = 0; i<size; i++) {
		int ans = answers[i];
		if (ans == studA[idx[0]]) result[0]++;

		if (i % 2 && ans == studB[idx[1]]) result[1]++; //Ȧ����ȣ ������ ��
		else if (i % 2 == 0 && ans == 2) result[1]++; // ¦���̸� �� 2�� ����

		if (ans == studC[idx[2]]) result[2]++;

		// ���� �� �� ���� �ε��� ����
		idx[0] = (idx[0] + 1) % 5;
		if (i % 2) {
			idx[2] = (idx[2] + 1) % 5;
			idx[1] = (idx[1] + 1) % 4;
		}

	}

	int MAX = INT_MIN;
	for (int i = 0; i<3; i++) {
		if (result[i] > MAX) {
			answers.clear();
			MAX = result[i];
			answers.push_back(i + 1);
		}
		else if (result[i] == MAX)
			answers.push_back(i + 1);
	}

	return answers;
}