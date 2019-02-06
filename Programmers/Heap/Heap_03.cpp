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
	int end = 0; // ���� �۾��� ���� �ð�
	int j = 0;

	//������ �ð��� ���� ��, �����ð��� ������ �ҿ�ð��� ���� ������ ����
	priority_queue<A::pair_type, vector<A::pair_type>, A::compare> pq;
	stack<A::pair_type> st;

	for (int i = 0; i < job_num; i++) {
		pq.push(A::pair_type(jobs[i][0], jobs[i][1]));
	}

	while (!pq.empty()) {
		A::pair_type temp = pq.top(); pq.pop();
		int turnaround;

		// pq top�� �ִ� �۾� �����ð��� ���� �۾�����ð����� ������ ��
		// == �۾��� �����ϰ� ���� �ʾҴ� ���
		if(temp.first >= end){
			turnaround = temp.second; // ta time == �ҿ�ð�
			int interval = temp.first - end; // (�����ð� - �����۾� ����ð�)�� ���� ���
			end += (interval + temp.second); // ���� �۾� ����ð� = ���� + �ҿ�ð�
			answer += turnaround; // �ش� �۾��� ta time ���ϱ�

			continue;
		}

		// ���� �۾��� ������ ���� ���� �۾� ������ ���
		// end ������ ������ �۾��� �� �ҿ�ð� ���� ª�� �۾��� �����ؾ� ��
		A::pair_type min = temp;
		st.push(min);

		while (true) {
			//end���� �����̹Ƿ� ���� ����(end)���� ���� �������� ���� �۾�
			if (temp.first > end) break; 

			//�ּҼҿ�ð� ���� �۾� ã��
			if (min.second > temp.second)
				min = temp; 

			//���̻� �۾� ���� ���
			if (pq.empty()) break;

			//���� �۾� Ȯ�� �� ������ ���� ���ÿ� �־���
			temp = pq.top(); pq.pop();
			st.push(temp);
		}

		//���ÿ��� q�� �ٽ� �־��ֱ�
		while (!st.empty()) {
			if (st.top() != min) 
				pq.push(st.top());
			
			st.pop();
		}

		//ta time == (�����۾� ����ð� - �̹� �۾� �����ð�) + �̹��۾� �ҿ�ð�
		turnaround = end - min.first + min.second;
		
		answer += turnaround;
		end += min.second; // �̹� �۾� ����ð�

	}

    return answer/job_num;
}