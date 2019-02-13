/*
@Author		YJ Park
@Date		19. 02. 12
@Descript	SWEA [S/W�����ذ� �⺻ - ��ȣ ¦����]
			�������� ���� �� ���� ��ȣ ���� ���� ������ �´ٸ� �ݴ� ��ȣ�� �־�� �ϴ� ��ġ Ȯ��
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cal(char c, char rv, int start, vector<char> &paren) {
	int cnt = 0;

	for (int j = start; j < paren.size(); j++) {
		if (paren[j] == c) cnt++;
		else {
			cnt = (cnt << 1) - 1 + start;
			if (paren[cnt] != rv) return -1;
			else return cnt;
		}
	}
}

int main() {
	for (int i = 1; i <= 10; i++) {
		int num; cin >> num;
		vector<char> paren(num);
		for (int j = 0; j < num; j++)
			cin >> paren[j];

		sort(paren.begin(), paren.end());

		char c[4] = { '(', '<', '[' , '{' };
		char rev[4] = { ')', '>', ']', '}' };

		int ret = 0; bool flag = true;

		for (int i = 0; i < 4; i++) {
			ret = cal(c[i], rev[i], ret, paren);
			if (ret == -1) {
				flag = false; break;
			}
			ret++;
		}

		cout << "#" << i<< " " << flag << endl;
	}
}