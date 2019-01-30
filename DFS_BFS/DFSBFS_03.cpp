/*
@Author		YJ Park
@Date		19. 01. 30
@Descript	Programmers DFS/BFS #03
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int graph[50][50];
int size;
vector<string> dict;
vector<int> dist;

// �׷��� �����
void make_graph(string str, int idx, int word_size) {
	for (int i = idx+1; i < ::size; i++) {
		int diff = 0;

		for (int j = 0; j < word_size; j++) {
			if (str[j] != dict[i][j]) 
				diff++;
		}

		// �ٸ� ���ڰ� 1���� ��쿡�� �߰�
		if (diff == 1) {
			graph[idx][i] = 1;
			graph[i][idx] = 1;
		}
	}
}

// BFS ��� �ִܰ�� ã��
void BFS(int start, int end) {
	queue<int> q;

	dist.resize(::size, -1);
	dist[start] = 0;
	
	q.push(start);

	while (!q.empty()) {
		int temp = q.front(); q.pop();

		for (int i = 0; i < ::size; i++) {

			if (graph[temp][i] && dist[i] == -1) {
				q.push(i);
				dist[i] = dist[temp] + 1;
			}
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	::size = words.size();
	int word_size = begin.size();
	vector<int> start;
	dict = words;

	int target_idx = -1;
	for (int i = 0; i < ::size; i++) {

		// target�� �ִ� idx ã�� �׷��� ����
		if (words[i] == target) 
			target_idx = i;
		make_graph(words[i], i, word_size);

		// �������� �� �� �ִ� �ܾ�� �߰�
		int diff = 0;
		for (int j = 0; j < word_size; j++) {
			if (words[i][j] != begin[j]) diff++;
		}

		if (diff == 1) start.push_back(i);
	}

	// target�� �ܾ� ��Ͽ� ���� ���
	if (target_idx == -1) return 0;

	// start �迭 �� ���� ª�� ��ȯ ������ ���� ��� ã��
	answer = 2147483647;
	for (int i = 0; i < start.size(); i++) {
		BFS(start[i], target_idx);

		if (dist[target_idx] < answer) 
			answer = dist[target_idx];
	}

	//begin���� start �迭�� �ִ� �ܾ�� ���� ���� 1�� �߰�
	return answer + 1;
}