/*
@Author		YJ Park
@Date		19. 02. 16
@Descript	BOJ [#15651 N°ú M(3)]
*/

#include <iostream>
#include <string>

using namespace std;

int visit[9][9];
int N, M;

void DFS(int depth, string number) {
	if (depth == M) {
		cout << number << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[depth][i]) {
			visit[depth][i] = true;
			DFS(depth + 1, number + to_string(i) + " ");
			visit[depth][i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	DFS(0, "");
}
