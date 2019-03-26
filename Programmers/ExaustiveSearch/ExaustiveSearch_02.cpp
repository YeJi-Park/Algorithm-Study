/*
@Author		YJ Park
@Date		19. 02. 09
@Descript	Programmers Exaustive Search #02			
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num;
bool visited[7];
vector<string> lis;
bool prime[10000000];

void isPrime(int mmax) {
	for (int i = 2; i < mmax; i++) {
		if (prime[i]) continue;

		for (int j = 2; j*i < mmax; j++)
			prime[i*j] = true;
	}
}

void DFS(int depth, string str, string &numbers) {
	if (depth == num)
		lis.push_back(str);
	else {
		for (int i = 0; i < num; i++) {
			if (depth == 0 && numbers[i] == 0) continue;

			if (!visited[i]) {
				visited[i] = true;
				str += numbers[i];
				DFS(depth + 1, str, numbers);
				visited[i] = false;
			}
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	num = numbers.size();
	
	DFS(0, "", numbers);

	sort(lis.begin(), lis.end());

	isPrime(stoi(lis[lis.size() - 1]));

	for (int i = 0; i < lis.size(); i++)
		if (prime[stoi(lis[i])]) answer++;

	return answer;
}

