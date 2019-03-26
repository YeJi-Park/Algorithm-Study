/*
@Author		YJ Park
@Date		19. 02. 18
@Descript	Programmers [����Ž��, �Ҽ� ã��]
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int num;
bool visited[7];
vector<string> lis;
bool prime[10000000];

void isPrime(int mmax) {
	prime[0] = true;
	prime[1] = true;

	for (int i = 2; i <= mmax; i++) {
		if (prime[i]) continue;

		for (int j = 2; j*i <= mmax; j++)
			prime[i*j] = true;
	}
}

void DFS(int depth, string str, string &numbers, int len) {
	if (depth == len)
		lis.push_back(str);
	else {
		for (int i = 0; i < num; i++) {
			if (depth == 0 && numbers[i] == '0') continue;

			if (!visited[i]) {
				visited[i] = true;
				DFS(depth + 1, str+numbers[i], numbers, len);
				visited[i] = false;
			}
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	num = numbers.size();

	// ���� 1���� numbers�� ũ����� ���鼭 ���� �����
	for(int i=1; i<=num; i++)
		DFS(0, "", numbers, i);

	sort(lis.begin(), lis.end());

	// �ߺ� ���� ���� ��� ����
	auto iter = unique(lis.begin(), lis.end());
	if (iter != lis.end()) lis.erase(iter, lis.end());

	isPrime(stoi(lis[lis.size() - 1]));

	// �Ҽ��� ��� answer++
	for (int i = 0; i < lis.size(); i++)
		if (!prime[stoi(lis[i])]) answer++;

	return answer;
}