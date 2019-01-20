/*
@Author		YJ Park
@Date		19. 01. 20
@Descript	Programmers Heap #04
*/

#include <string>
#include <vector>
#include <functional>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	//priority_queue<int> min_heap;
	//priority_queue<int> max_heap;
	deque<int> dq;

	answer.push_back(0); answer.push_back(0);

	for (int i = 0; i < operations.size(); i++) {
		string op = operations[i];
		int size = op.size();

		if (op[0] == 'I') {
			int data = stoi(op.substr(2, size - 1));
			//min_heap.push(data);
			dq.push_back(data);
			cout << data << "³ÖÀ½" << endl;
			sort(dq.begin(), dq.end(), greater<int>());
		}
		else {
			if (dq.empty()) continue;

			if (op[2] == '-') {
				cout << dq.back() << "³ª¿È" << endl;
				dq.pop_back();
			}
			else {
				cout << dq.front() << "³ª¿È" << endl;
				dq.pop_front();
			}
		}
	}
	
	if (!dq.empty()) {
		answer[1] = dq.front();
		answer[0] = dq.back();
	}

	return answer;
}

int main() {

}