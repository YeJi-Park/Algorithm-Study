/*
@Author		YJ Park
@Date		19. 01. 22
@Descript	Programmers Greedy #03
*/
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	deque<int> dq;
	stack<int> st;

	sort(people.begin(), people.end(), greater<int>());

	int size = people.size();
	for (int i = 0; i < size; i++) 
		dq.push_back(people[i]);
	
	//while (!dq.empty()) {
	//	int heaviest = dq.front(); dq.pop_front();

	//	if (dq.empty()) {
	//		answer++;
	//		break;
	//	}
	while (true){
		if (dq.empty()) {
			answer++;
			break;
		}

		int heaviest = dq.front(); dq.pop_front();

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
					if(isChecked)
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

int main() {
	cout << solution({ 70,50,80,50 },100);
}