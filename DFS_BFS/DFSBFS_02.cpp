/*
@Author		YJ Park
@Date		19. 01. 30
@Descript	Programmers DFS/BFS #02
*/

#include <vector>

using namespace std;

vector<vector<int>> com;
bool check[200];

void DFS(int node, int size) {
	check[node] = true;

	for (int i = 0; i < size; i++) 
		if (com[node][i] && !check[i]) 
			DFS(i, size);
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	com = computers;

	for(int i=0; i < n; i++)
		if (!check[i]) {
			DFS(i, n);
			answer++;
		}

	return answer;
}