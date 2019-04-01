/*
@Author		YJ Park
@Date		19. 03. 26
@Descript	BOJ [#14890 경사로]
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N, L;
int map[100][100];
int dr[2] = { 1, 0 };
int dc[2] = { 0, 1 };

int main() {
	cin >> N >> L;
	int answer = 0;

	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++) { //가로
		bool flag = true;
		vector<bool> ladder(N, false); // 이미 경사로 놓아졌는지 확인

		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] != map[i][j + 1]) {
				if (abs(map[i][j] - map[i][j + 1]) != 1) { // 높이차이 1 이상이면 ㄴㄴ
					flag = false;
					break;
				}
				if (map[i][j] > map[i][j + 1]) { // j가 더 높을 때
					for (int k = j + 1; k <= j + L; k++) {
						if (k >= N || ladder[k] || map[i][j + 1] != map[i][k]) { // 경사로 놓여져있거나 높이 다를 경우
							flag = false;
							break;
						}
						else ladder[k] = true;
					}
				}
				else {
					for (int k = j; k > j - L; k--) {
						if (k < 0 || ladder[k] || map[i][j] != map[i][k]) {
							flag = false; break;
						}
						else ladder[k] = true;
					}
				}

				if (!flag) break;
			}
		}

		if (flag) answer++;
	}

	for (int i = 0; i<N; i++) { // 세로
		bool flag = true;
		vector<bool> ladder(N, false);

		for (int j = 0; j<N - 1; j++) {
			if (map[j][i] != map[j + 1][i]) {
				if (abs(map[j][i] - map[j + 1][i]) != 1) {
					flag = false;
					break;
				}
				if (map[j][i] > map[j + 1][i]) {
					for (int k = j + 1; k <= j + L; k++) {
						if (k >= N || ladder[k] || map[j + 1][i] != map[k][i]) {
							flag = false;
							break;
						}
						else ladder[k] = true;
					}
				}
				else {
					for (int k = j; k > j - L; k--) {
						if (k<0 || ladder[k] || map[j][i] != map[k][i]) {
							flag = false; break;
						}
						else ladder[k] = true;
					}
				}
			}
			if (!flag) break;
		}

		if (flag) answer++;
	}

	cout << answer << endl;
}