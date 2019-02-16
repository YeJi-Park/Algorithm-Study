/*
@Author		YJ Park
@Date		19. 02. 16
@Descript	BOJ [#15649 N°ú M(1)]
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int visit[9];
int N, M;

void DFS(int depth, string number) {
	if (depth == M) cout << number << "\n";

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			DFS(depth + 1, number + to_string(i) + " ");
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	DFS(0, "");

}
