/*
@Author		YJ Park
@Date		19. 02. 03
@Descript	BOJ 스타트와 링크
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int depth, N;
int minV = 99999;
bool visited[20];
int ability[20][20];

int cal_stat(vector<int> team) {
	int sum = 0;
	for (int i = 0; i < team.size(); i++) {
		for (int j = i+1; j < team.size(); j++) {
			sum += ability[team[i]][team[j]];
			sum += ability[team[j]][team[i]];
		}
	}
	return sum;
}

void dfs(int v) {
	// A팀 멤버가 (n/2) - 1명 됐을 때 minV 구하기
	if (depth == (N / 2) - 1) {
		vector<int> teamA, teamB;
		for (int i = 0; i < N; i++){
			if (visited[i]) teamA.push_back(i); // DFS로 방문한 경우 team A
			else teamB.push_back(i); // 방문 안했을 경우 team B
		}
		
		minV = min(minV, abs(cal_stat(teamA) - cal_stat(teamB)));
	}

	else {
		for (int i = v + 1; i < N; i++) {
			depth++;
			visited[i] = true;
			dfs(i);
			visited[i] = false;
		}
	}

	depth--;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> ability[i][j];
		}

	// 0번 사람 A팀에 넣고 A팀의 조합( ((N/2) - 1)명 ) 구하기
	visited[0] = true;

	for (int i = 0; i < N-1; i++) {
		depth = 1;
		visited[i + 1] = true;
		dfs(i+1);
		visited[i + 1] = false;
	}

	cout << minV;
}