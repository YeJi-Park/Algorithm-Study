/*
@Author     YJ Park
@Date       19. 02. 28
@Descript   SWEA [#3499 퍼펙트 셔플]
			
			Q FIFO이므로 2개의 Q 사용해서 절반씩 넣고
			번갈아가면서 POP하면 셔플됨
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
		if (N % 2 == 1) half++; // N이 홀수인 경우 먼저 놓는 쪽에 한 장 더

		for (int i = 0; i < half; i++) {
			cin >> cards[i];
			q[0].push(cards[i]);
		}

		for (int i = half; i < N; i++) {
			cin >> cards[i];
			q[1].push(cards[i]);
		}

		cout << "#" << tc << " ";

		for (int i = 0; i < N; i++) { // 번갈아가면서 Q pop
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