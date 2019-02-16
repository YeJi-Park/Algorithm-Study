/*
@Author		YJ Park
@Date		19. 02. 16
@Descript	BOJ [#15652 N°ú M(4)]
*/

#include <iostream>
#include <string>

using namespace std;

int visit[9][9];
int N, M;

void DFS(int depth, string number, int from) {
	if (depth == M) {
		cout << number << "\n";
		return;
	}

	for (int i = from; i <= N; i++) {
		if (!visit[depth][i]) {
			visit[depth][i] = true;
			DFS(depth + 1, number + to_string(i) + " ", i);
			visit[depth][i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	DFS(0, "", 1);
}
