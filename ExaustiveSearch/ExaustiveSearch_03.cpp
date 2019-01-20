/*
@Author		YJ Park
@Date		19. 01. 20
@Descript	Programmers Exaustive Search #03
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int num, int input, int strike, int ball) {

	int n1 = num / 100, n2 = (num % 100) / 10, n3 = (num % 100) % 10;
	int i1 = input / 100, i2 = (input % 100) / 10, i3 = (input % 100) % 10;
	int s_cnt = 0, b_cnt = 0;

	if (n1 == i1) s_cnt++;
	if (n2 == i2) s_cnt++;
	if (n3 == i3) s_cnt++;

	if (s_cnt != strike) return false;

	if (i1 == n2 || i1 == n3) b_cnt++;
	if (i2 == n1 || i2 == n3) b_cnt++;
	if (i3 == n1 || i3 == n2) b_cnt++;

	if (b_cnt == ball ) return true;
	else return false;
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	vector<int> v;
	
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (i == j) continue;
			for (int k = 1; k < 10; k++) {
				if (j == k || i == k) continue;
				else {
					v.push_back(i * 100 + j* 10 + k);
				}
			}
		}
	}

	int size = v.size();
	for (int i = 0; i < size; i++) {
		bool flag;
		for (int j = 0; j < baseball.size(); j++) {
			vector<int> cond = baseball[j];
			flag = check(v[i], cond[0], cond[1], cond[2]);

			if (!flag) break;
		}

		if (flag) answer++;
	}
	return answer;
}