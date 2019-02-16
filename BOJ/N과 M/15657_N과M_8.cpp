/*
@Author		YJ Park
@Date		19. 02. 16
@Descript	BOJ [#15657 N°ú M(8)]
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int visit[9][9];
vector<int> num;
int N, M;

void DFS(int depth, string number, int from) {
	if (depth == M) {
		cout << number << "\n";
		return;
	}

	for (int i = from; i < N; i++) {
		if (!visit[depth][i]) {
			visit[depth][i] = true;
			DFS(depth + 1, number + to_string(num[i]) + " ", i);
			visit[depth][i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	num.resize(N);

	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num.begin(), num.end());

	DFS(0, "", 0);
}
