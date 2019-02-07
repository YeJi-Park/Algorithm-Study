/*
@Author		YJ Park
@Date		19. 02. 07
@Descript	Programmers Graph #02
			1.	중복 제거를 위해 사용한 set 자료구조가 자동정렬이라
				선수번호가 앞인 경우 놓쳐서 test case 2에서 실패
			2.	visit(방문한 원소 수), elem_num(세트에 들어있는 원소 수) 변수를 세서
				visit<elem_num인 동안 계속 순회하도록 수정
*/

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	vector<set<int>> lose; lose.resize(n + 1);
	vector<set<int>> win; win.resize(n + 1);

	int res_num = results.size();
	for (int i = 0; i < res_num; i++) {
		win[results[i][0]].insert(results[i][1]);
		lose[results[i][1]].insert(results[i][0]);
	}

	for (int i = 1; i < n + 1; i++) {
		vector<bool> visited(n + 1, false);
		int elem_num = lose[i].size();
		int visit = 0;

		while (elem_num > visit) {
			for (auto j : lose[i]) {
				if (visited[j]) continue;
				else {
					visited[j] = true;
					visit++;

					for (auto k : lose[j]) {
						if (lose[i].insert(k).second)
							elem_num++;
					}

				}
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		vector<bool> visited(n + 1, false);
		int elem_num = win[i].size();
		int visit = 0;

		while (elem_num > visit) {
			for (auto j : win[i]) {
				if (visited[j]) continue;
				else {
					visited[j] = true;
					visit++;

					for (auto k : win[j]) {
						if (win[i].insert(k).second)
							elem_num++;
					}

				}
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
		if (win[i].size() + lose[i].size() == (n - 1)) answer++;

	return answer;
}