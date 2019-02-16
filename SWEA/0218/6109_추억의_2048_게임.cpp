/*
@Author		YJ Park
@Date		19. 02. 16
@Descript	SWEA [#6109 �߾��� 2048 ����]
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N;
string cmd;

void game(vector<vector<int> > &map) {
	vector<queue<int> > q(N);

	if (cmd == "up") {

		// q�� �� ���� 0 ������ �� ����
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				if(map[j][i]) q[i].push(map[j][i]);
			
		// �� ���鼭 q pop��
		// q front Ȯ���ؼ� ���� ���Ұ� ���� ����� �� ��ġ��
		for (int i = 0; i < N; i++) {
			int idx = 0; // ������ ��ġ
			while (!q[i].empty()) {
				int top = q[i].front(); q[i].pop();
				if (!top) continue;

				if (!q[i].empty() && q[i].front() == top) {
					q[i].pop();
					top *= 2;
				}

				map[idx][i] = top;
				idx++;
			}

			// q�� �� ���µ� map ���� ������ ��� 0���� ä��
			if (idx != N) {
				for (int j = idx; j < N; j++) map[j][i] = 0;
			}
		}
	} // ���� ���� �ε��� ���� �ٸ��� ����!
	else if (cmd == "down") {
		for (int i = 0; i < N; i++)
			for (int j = N-1; j >= 0; j--)
				if (map[j][i]) q[i].push(map[j][i]);


		for (int i = 0; i < N; i++) {
			int idx = N-1;
			while (!q[i].empty()) {
				int top = q[i].front(); q[i].pop();
				if (!top) continue;

				if (!q[i].empty() && q[i].front() == top) {
					q[i].pop();
					top *= 2;
				}

				map[idx][i] = top;
				idx--;
			}

			if (idx != -1) {
				for (int j = idx; j >= 0; j--) map[j][i] = 0;
			}
		}
	}
	else if (cmd == "left") {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (map[i][j]) q[i].push(map[i][j]);

		for (int i = 0; i < N; i++) {
			int idx = 0;
			while (!q[i].empty()) {
				int top = q[i].front(); q[i].pop();
				if (!top) continue;

				if (!q[i].empty() && q[i].front() == top) {
					q[i].pop();
					top *= 2;
				}

				map[i][idx] = top;
				idx++;
			}

			if (idx != N) {
				for (int j = idx; j < N; j++) map[i][j] = 0;
			}
		}
	}
	else { 
		for (int i = 0; i < N; i++)
			for (int j = N-1; j >= 0; j--)
				if (map[i][j]) q[i].push(map[i][j]);

		for (int i = 0; i < N; i++) {
			int idx = N-1;
			while (!q[i].empty()) {
				int top = q[i].front(); q[i].pop();
				if (!top) continue;

				if (!q[i].empty() && q[i].front() == top) {
					q[i].pop();
					top *= 2;
				}

				map[i][idx] = top;
				idx--;
			}

			if (idx != -1) {
				for (int j = idx; j >= 0; j--) map[i][j] = 0;
			}
		}
	}
}

int main() {
	int size;
	cin >> size;

	for (int tc = 1; tc <= size; tc++) {
		cin >> N >> cmd;
		vector<vector<int> > map(N, vector<int>(N));

		for(int i=0; i<N; i++)
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}

		game(map);

		cout << "#" << tc << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
	}
}