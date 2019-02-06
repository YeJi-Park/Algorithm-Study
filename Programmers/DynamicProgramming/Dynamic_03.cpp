/*
@Author		YJ Park
@Date		19. 01. 27
@Descript	Programmers Dinamic Programming #04
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int map[101][101];
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;

	for (int i = 0; i < puddles.size(); i++)
		map[puddles[i][1]][puddles[i][0]] = -1;

	dp[1][0] = 1; /*dp[0][1] = 1;*/
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == -1) d[i][j] = 0;
			else d[i][j] = d[i - 1][j] + d[i][j - 1] % 1000000007;

			cout << d[i][j] << " ";
		}
		cout << "\n";
	}


	answer = d[n][m];

	return answer;
}

int main() {
	solution(4, 3, { {2,2} });
}