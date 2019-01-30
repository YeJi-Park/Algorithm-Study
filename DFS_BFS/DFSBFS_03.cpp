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

// 그래프 만들기
void make_graph(string str, int idx, int word_size) {
	for (int i = idx+1; i < ::size; i++) {
		int diff = 0;

		for (int j = 0; j < word_size; j++) {
			if (str[j] != dict[i][j]) 
				diff++;
		}

		// 다른 글자가 1개일 경우에만 추가
		if (diff == 1) {
			graph[idx][i] = 1;
			graph[i][idx] = 1;
		}
	}
}

// BFS 기반 최단경로 찾기
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

		// target이 있는 idx 찾고 그래프 만듦
		if (words[i] == target) 
			target_idx = i;
		make_graph(words[i], i, word_size);

		// 시작점이 될 수 있는 단어들 추가
		int diff = 0;
		for (int j = 0; j < word_size; j++) {
			if (words[i][j] != begin[j]) diff++;
		}

		if (diff == 1) start.push_back(i);
	}

	// target이 단어 목록에 없을 경우
	if (target_idx == -1) return 0;

	// start 배열 중 가장 짧은 변환 과정을 갖는 경우 찾기
	answer = 2147483647;
	for (int i = 0; i < start.size(); i++) {
		BFS(start[i], target_idx);

		if (dist[target_idx] < answer) 
			answer = dist[target_idx];
	}

	//begin에서 start 배열에 있는 단어로 가기 위해 1번 추가
	return answer + 1;
}