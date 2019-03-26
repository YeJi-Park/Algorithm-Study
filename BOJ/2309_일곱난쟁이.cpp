/*
@Author		YJ Park
@Date		19. 03. 26
@Descript	BOJ [#2309 ¿œ∞ˆ ≥≠¿Ô¿Ã]
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int nanjaeng[9];
bool flag;
bool visit[9];
vector<int> v;

void DFS(int depth, int ret) {
	if (ret > 100) return;

	if (depth == 7) {
		if (ret == 100) {
			flag = true;
			sort(v.begin(), v.end());
			for (int i = 0; i < 7; i++) cout << v[i] << "\n";
			return;
		}
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (visit[i]) continue;
			visit[i] = true;
			v.push_back(nanjaeng[i]);
			DFS(depth + 1, ret + nanjaeng[i]);
			v.pop_back();
			visit[i] = false;
			if (flag) return;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) cin >> nanjaeng[i];

	DFS(0, 0);
}