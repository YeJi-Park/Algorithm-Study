/*
@Author		YJ Park
@Date		19. 01. 23
@Descript	Programmers Greedy #05
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//진출점 기준 정렬
bool cmp(vector<int> &a, vector<int> &b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	sort(routes.begin(), routes.end(), cmp);

	//최초 카메라 0번 경로 진출점에 설치
	int cam_location = routes[0][1];
	answer++;

	int size = routes.size();

	//모든 경로 돌면서 이 전에 설치한 카메라로 커버 가능한지 확인
	// 안되면 카메라 추가
	for (int i = 0; i < size; i++) {
		if (cam_location < routes[i][0] | cam_location > routes[i][1]) {
			answer++;
			cam_location = routes[i][1];
		}
	}

	return answer;
}