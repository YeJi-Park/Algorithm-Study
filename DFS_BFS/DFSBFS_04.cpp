/*
@Author		YJ Park
@Date		19. 02. 05
@Descript	Programmers DFS/BFS #04
			1.	DFS Ž������ ��, tickets�� �� �� �� ���� ��츦 ������� ���ؼ� 50��
				�ٸ� Ǯ�� �����ؼ� ����!
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

	// tickets ������ŭ �� ��� ������ ��
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
				{	// tickets �� �� �� ���� ��� �ٸ� ��� ã��
					visited[i] = false;
					answer.pop_back();
				}
			}
		}

		// tickets�� �� �� �� ���� ���
		return false;
	}
}

// ����� ���� ��� ������ ���ĺ� �� ����
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