/*
@Author     YJ Park
@Date       19. 03. 06
@Descript   BOJ [#3190 뱀]
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, K, L;
int map[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<pair<int, int> > snake_pos;
int tail;
int curr_sec;

bool snake(int end, int dir) {

	int size = snake_pos.size();
	while (curr_sec < end) {
		curr_sec++; // 초 늘리기

		// 머리 움직일 위치
		int tx = snake_pos[size - 1].first + dx[dir];
		int ty = snake_pos[size - 1].second + dy[dir];

		//벽 부딪히거나 꼬리가 이미 있을 경우 게임 종료
		if (tx <= 0 || ty <= 0 || tx > N || ty > N) return false;
		if (map[tx][ty] == 1) return false;

		snake_pos.push_back(pair<int, int>(tx, ty)); // 머리 위치 추가

		if (map[tx][ty] != 9) { // 사과 없었을 경우 꼬리 있던 자리 0 
			map[snake_pos[tail].first][snake_pos[tail].second] = 0;
			tail++; // 꼬리 인덱스++
		}

		map[tx][ty] = 1; // 맵에 뱀 표시
		size++; // 뱀 벡터 총 사이즈
	}

	// 잘려나간 꼬리들 벡터에서 없애주기
	snake_pos.erase(snake_pos.begin(), snake_pos.begin() + tail);

	return true;
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 9;
	}

	cin >> L;

	int sec, dir = 0;
	char d;
	bool flag;
	snake_pos.push_back(pair<int, int>(1, 1)); // 초기 머리 위치 입력
	
	for (int i = 0; i < L; i++) {
		cin >> sec >> d;
		tail = 0; // 현재시점부터 입력받은 시점까지 뱀 앞으로 감
		flag = snake(sec, dir); 
		if (!flag) break; // 중간에 게임 종료일 경우

		if (d == 'D') dir = (dir + 1) % 4; // X초 이후 방향 전환
		else dir = (dir + 3) % 4;
	}

	while (flag) flag = snake(INT_MAX, dir); // 방향전환 끝났을 경우 계속 한 방향으로

	cout << curr_sec << endl;
}