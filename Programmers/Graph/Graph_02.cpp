/*
@Author		YJ Park
@Date		19. 02. 07
@Descript	Programmers Graph #02
			1.	�ߺ� ���Ÿ� ���� ����� set �ڷᱸ���� �ڵ������̶�
				������ȣ�� ���� ��� ���ļ� test case 2���� ����
			2.	visit(�湮�� ���� ��), elem_num(��Ʈ�� ����ִ� ���� ��) ������ ����
				visit<elem_num�� ���� ��� ��ȸ�ϵ��� ����
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