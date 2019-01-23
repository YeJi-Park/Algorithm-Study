/*
@Author		YJ Park
@Date		19. 01. 22
@Descript	Programmers Greedy #03
효율성 테스트 #1, #3 통과 못해서
수정해야 될 것 같음
=> 굳이 스택, 디큐로 구현해야 할 필요 없으면
벡터에 min, max idx를 저장해도 될 것 같은??
*/

#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	deque<int> dq;
	stack<int> st;

	sort(people.begin(), people.end(), greater<int>());

	int size = people.size();
	for (int i = 0; i < people.size(); i++)
		dq.push_back(people[i]);

	while (!dq.empty()) {
		int heaviest = dq.front(); dq.pop_front();

		if (dq.empty()) {
			answer++;
			break;
		}

		int left = limit - heaviest;
		int lightest = dq.back();

		if (lightest > left) {
			answer++;
			continue;
		}
		else if (lightest == left) {
			answer++;
			dq.pop_back();
			continue;
		}
		else {
			dq.pop_back();
			st.push(lightest);

			while (true) {
				if (dq.empty()) break;

				int temp = dq.back();

				if (temp > left) break;
				else {
					dq.pop_back();
					st.push(temp);

					if (lightest < temp)
						lightest = temp;
				}
			}

			//스택에서 다시 디큐로 넣기
			bool isChecked = false;
			while (!st.empty()) {
				int temp = st.top();
				if (temp == lightest) {
					if (isChecked)
						dq.push_back(st.top());
					else
						isChecked = true;
				}
				else
					dq.push_back(st.top());

				st.pop();
			}

			answer++;
		}
	}

	return answer;
}