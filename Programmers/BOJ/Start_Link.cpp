/*
@Author		YJ Park
@Date		19. 02. 03
@Descript	BOJ ��ŸƮ�� ��ũ
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
	// A�� ����� (n/2) - 1�� ���� �� minV ���ϱ�
	if (depth == (N / 2) - 1) {
		vector<int> teamA, teamB;
		for (int i = 0; i < N; i++){
			if (visited[i]) teamA.push_back(i); // DFS�� �湮�� ��� team A
			else teamB.push_back(i); // �湮 ������ ��� team B
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

	// 0�� ��� A���� �ְ� A���� ����( ((N/2) - 1)�� ) ���ϱ�
	visited[0] = true;

	for (int i = 0; i < N-1; i++) {
		depth = 1;
		visited[i + 1] = true;
		dfs(i+1);
		visited[i + 1] = false;
	}

	cout << minV;
}