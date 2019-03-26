/*
@Author		YJ Park
@Date		19. 03. 26
@Descript	BOJ [#6603 ·Î¶Ç]
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> lotto;
vector<int> ret;
bool visit[12];
int K;

using namespace std;

void DFS(int depth, int from) {
	if (depth == 6) {
		for (int i = 0; i<6; i++)
			cout << ret[i] << " ";
		cout << "\n";
		return;
	}
	else {
		for (int i = from; i<K; i++) {
			if (visit[i]) continue;
			visit[i] = true;
			ret.push_back(lotto[i]);
			DFS(depth + 1, i + 1);
			visit[i] = false;
			ret.pop_back();
		}
	}
}

int main() {
	while (true) {
		cin >> K;
		if (!K) break;
		lotto.resize(K);

		for (int i = 0; i<K; i++) cin >> lotto[i];

		DFS(0, 0);
		cout << "\n";
	}
}