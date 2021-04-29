/*
@Author		YJ Park
@Date		19. 03. 25
@Descript	Programmers [완전탐색 Level 2 - 소수 찾기]
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

int size;
string n;
bool visit[7];
bool prime[9987654];
set<int> s;

void DFS(int target, int depth, string str) {
	if (depth == target) {
		s.insert(stoi(str));
		return;
	}

	for (int i = 0; i < size; i++) {
		if (!depth && str[i] == '0') continue; // 첫숫자가 0일 경우 무시
		if (visit[i]) continue;

		visit[i] = true;
		DFS(target, depth + 1, str + n[i]);
		visit[i] = false;
	}
}

void prime_set(int max) {
	prime[0] = true; prime[1] = true;

	for (int i = 2; i<max / 2 + 1; i++) {
		if (prime[i]) continue;

		for (int j = 2; j <= max; j++) {
			if (j*i > max) break;
			prime[i*j] = true;
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	n = numbers;
	size = numbers.size();

	for (int i = 1; i <= size; i++) {
		DFS(i, 0, "");
	}

	auto iter = s.end(); iter--; // 제일 큰 값 max에 저장
	int max = *iter;

	prime_set(max); // max까지의 소수 찾기
	for (auto i : s) if (!prime[i]) answer++;

	return answer;
}