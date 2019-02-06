/*
@Author		YJ Park
@Date		19. 02. 06
@Descript	Programmers Graph #02
			1.	중복 제거를 위해 사용한 set 자료구조가 자동정렬이라
				선수번호가 앞인 경우 놓쳐서 test case 2에서 실패
*/

#include <string>
#include <vector>
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

	for (int i = 1; i < n+1; i++) {
		for (auto j : lose[i])
			for (auto k : lose[j])
				lose[i].insert(k);
	}

	for (int i = 1; i < n + 1; i++) {
		for (auto j : win[i])
			for (auto k : win[j])
				win[i].insert(k);
	}

	for (int i = 1; i < n + 1; i++)
		if (win[i].size() + lose[i].size() == (n-1)) answer++;

	return answer;
}

int main() {
	cout << solution(5,{ {4, 3}, { 4, 2 }, { 3, 2 }, { 1, 2 }, { 2, 5 }});
}

