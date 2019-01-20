/*
@Author		YJ Park
@Date		19. 01. 17
@Descript	Programmers Heap #03 (Non-preemptive SJF)
*/

#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class A {
public:
	typedef pair<int, int> pair_type;

	struct compare {
		bool operator()(const pair_type& a, const pair_type& b) {
			if (a.first > b.first) return true;
			else if ((a.first == b.first) && (a.second > b.second)) return true;
			else return false;
		}
	};
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, min = 0;
	int job_num = jobs.size();
	int end = 0; // 직전 작업이 끝난 시간
	int j = 0;

	//도착한 시간이 빠른 순, 도착시간이 같으면 소요시간이 적은 순으로 정렬
	priority_queue<A::pair_type, vector<A::pair_type>, A::compare> pq;
	stack<A::pair_type> st;

	for (int i = 0; i < job_num; i++) {
		pq.push(A::pair_type(jobs[i][0], jobs[i][1]));
	}

	while (!pq.empty()) {
		A::pair_type temp = pq.top(); pq.pop();
		int turnaround;

		// pq top에 있는 작업 도착시간이 직전 작업종료시간보다 이후일 때
		// == 작업을 수행하고 있지 않았던 경우
		if(temp.first >= end){
			turnaround = temp.second; // ta time == 소요시간
			int interval = temp.first - end; // (도착시간 - 이전작업 종료시간)의 간격 계산
			end += (interval + temp.second); // 최종 작업 종료시간 = 간격 + 소요시간
			answer += turnaround; // 해당 작업의 ta time 더하기

			continue;
		}

		// 이전 작업이 끝나기 전에 다음 작업 도착한 경우
		// end 이전에 도착한 작업들 중 소요시간 가장 짧은 작업을 수행해야 함
		A::pair_type min = temp;
		st.push(min);

		while (true) {
			//end보다 이후이므로 현재 시점(end)에서 아직 도착하지 않은 작업
			if (temp.first > end) break; 

			//최소소요시간 갖는 작업 찾기
			if (min.second > temp.second)
				min = temp; 

			//더이상 작업 없을 경우
			if (pq.empty()) break;

			//다음 작업 확인 후 복원을 위해 스택에 넣어줌
			temp = pq.top(); pq.pop();
			st.push(temp);
		}

		//스택에서 q로 다시 넣어주기
		while (!st.empty()) {
			if (st.top() != min) 
				pq.push(st.top());
			
			st.pop();
		}

		//ta time == (직전작업 종료시간 - 이번 작업 도착시간) + 이번작업 소요시간
		turnaround = end - min.first + min.second;
		
		answer += turnaround;
		end += min.second; // 이번 작업 종료시간

	}

    return answer/job_num;
}