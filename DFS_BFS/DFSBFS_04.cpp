/*
@Author		YJ Park
@Date		19. 02. 05
@Descript	Programmers DFS/BFS #04
			1.	DFS 탐색했을 때, tickets을 다 쓸 수 없는 경우를 고려하지 못해서 50점
				다른 풀이 참고해서 수정!
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int size;
vector<string> answer;

bool dfs(vector<bool> &visited, vector<vector<string> > &tickets, int depth, string from) {
	answer.push_back(from);

	// tickets 갯수만큼 다 경로 돌았을 때
	if (depth == ::size) {
		return true;
	}
	else {
		for (int i = 0; i < ::size; i++) {
			if (tickets[i][0] == from && !(visited[i])) {
				visited[i] = true;
				bool flag = dfs(visited, tickets, depth + 1, tickets[i][1]);
				if (flag)
					return true;
				else
				{	// tickets 다 쓸 수 없는 경우 다른 경로 찾기
					visited[i] = false;
					answer.pop_back();
				}
			}
		}

		// tickets을 다 쓸 수 없는 경우
		return false;
	}
}

// 출발지 같은 경우 도착지 알파벳 순 정렬
bool cmp(vector<string> &a, vector<string> &b) {
	if( a[0] == b[0]) return (a[1] < b[1]);
}

vector<string> solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end(), cmp);
	::size = tickets.size();

	vector<bool> visited;
	visited.resize(::size, false);
	dfs(visited, tickets, 0, "ICN");

	return answer;
}