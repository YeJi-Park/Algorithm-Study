/*
@Author		YJ Park
@Date		19. 02. 16
@Descript	BOJ [#15654 N°ú M(5)]
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int visit[9];
vector<int> num;
int N, M;

void DFS(int depth, string number) {
	if (depth == M) {
		cout << number << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			DFS(depth + 1, number + to_string(num[i]) + " ");
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	num.resize(N);

	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num.begin(), num.end());

	DFS(0, "");
}
