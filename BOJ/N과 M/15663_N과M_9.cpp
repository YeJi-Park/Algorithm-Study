/*
@Author		YJ Park
@Date		19. 02. 17
@Descript	BOJ [#15663 N°ú M(9)]
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

int visit[9];
vector<int> num;
vector<vector<int>> answers;
int N, M;


void DFS(int depth, vector<int> temp) {
	if (depth == M) {
		answers.push_back(temp);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			temp[depth] = num[i];
			DFS(depth + 1, temp);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	num.resize(N);

	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num.begin(), num.end());

	vector<int> temp(M);

	DFS(0, temp);

	sort(answers.begin(), answers.end());

	auto pos = unique(answers.begin(), answers.end());
	if (pos != answers.end()) {
		answers.erase(pos, answers.end());
	}
	
	for (auto iter : answers) {
		for (int i = 0; i < iter.size(); i++) {
			cout << iter[i] << " ";
		}
		cout << "\n";
	}
}