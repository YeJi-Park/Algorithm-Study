/*
@Author     YJ Park
@Date       19. 02. 28
@Descript   SWEA [#3499 ����Ʈ ����]
			
			Q FIFO�̹Ƿ� 2���� Q ����ؼ� ���ݾ� �ְ�
			�����ư��鼭 POP�ϸ� ���õ�
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int N;
string cards[1000];

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		vector < queue<string>> q(2);
		int half = N / 2;
		if (N % 2 == 1) half++; // N�� Ȧ���� ��� ���� ���� �ʿ� �� �� ��

		for (int i = 0; i < half; i++) {
			cin >> cards[i];
			q[0].push(cards[i]);
		}

		for (int i = half; i < N; i++) {
			cin >> cards[i];
			q[1].push(cards[i]);
		}

		cout << "#" << tc << " ";

		for (int i = 0; i < N; i++) { // �����ư��鼭 Q pop
			if (i % 2) {
				cout << q[1].front() << " ";
				q[1].pop();
			}
			else {
				cout << q[0].front() << " ";
				q[0].pop();
			}
		}

		cout << endl;
	}
}