/*
@Author		YJ Park
@Date		19. 01. 26
@Descript	Programmers Dynamic Programming #02
*/

#include <string>
#include <vector>

using namespace std;

//memoizationÀ» À§ÇÑ ¹è¿­
long long memo[81];

long long fibonacci(int n) {
	if (n <= 1) return n;
	else if (memo[n] != 0) return memo[n];
	else return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

long long solution(int N) {
	long long answer = 0;

	fibonacci(N);
	answer = (memo[N - 1] << 1) + (memo[N] << 2);

	return answer;
}
