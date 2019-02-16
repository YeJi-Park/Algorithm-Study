/*
@Author		YJ Park
@Date		19. 02. 16
@Descript	BOJ [#15650 N°ú M(2)]
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int visit[9];
int N, M;

void DFS(int depth, string number, int from) {
	if (depth == M) cout << number << "\n";

	for (int i = from; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			DFS(depth + 1, number + to_string(i) + " ", i);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	DFS(0, "", 1);
}
