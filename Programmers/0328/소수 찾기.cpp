/*
@Author		YJ Park
@Date		19. 03. 25
@Descript	Programmers [����Ž�� Level 2 - �Ҽ� ã��]
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
		if (!depth && str[i] == '0') continue; // ù���ڰ� 0�� ��� ����
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

	auto iter = s.end(); iter--; // ���� ū �� max�� ����
	int max = *iter;

	prime_set(max); // max������ �Ҽ� ã��
	for (auto i : s) if (!prime[i]) answer++;

	return answer;
}