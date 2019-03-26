/*
@Author		YJ Park
@Date		19. 03. 26
@Descript	BOJ [#15662 톱니바퀴(2)]

			그냥 톱니 갯수랑 출력만 조정ㅇㅅㅇ
*/

#include <iostream>

using namespace std;

#define LEFT 6
#define RIGHT 2

bool gear[1001][8];
int start[1001];
int cmd[1000][2];
int K, T;

// 1 왼쪽에서 옴, 0 오른쪽에서 옴 => 연쇄적으로 톱니 돌리기
void rotate(int gear_num, int dir, bool flag) {
	if (flag) {
		if (gear_num < T &&
			gear[gear_num][(start[gear_num] + RIGHT) % 8] != gear[gear_num + 1][(start[gear_num + 1] + LEFT) % 8])
			rotate(gear_num + 1, -dir, true);
	}
	else {
		if (gear_num > 1 &&
			gear[gear_num][(start[gear_num] + LEFT) % 8] != gear[gear_num - 1][(start[gear_num - 1] + RIGHT) % 8])
			rotate(gear_num - 1, -dir, false);
	}

	if (dir == 1) start[gear_num] = (start[gear_num] - 1 + 8) % 8;
	else start[gear_num] = (start[gear_num] + 1) % 8;
}

// 처음 돌리는 톱니바퀴는 양쪽 다 확인해야함
void rotate(int gear_num, int dir) {

	// 양쪽에 톱니바퀴 있고 돌릴 수 있으면 연쇄적으로 톱니바퀴들 확인
	if (gear_num < T &&
		gear[gear_num][(start[gear_num] + RIGHT) % 8] != gear[gear_num + 1][(start[gear_num + 1] + LEFT) % 8])
		rotate(gear_num + 1, -dir, true);

	if (gear_num > 1 && gear[gear_num][(start[gear_num] + LEFT) % 8] != gear[gear_num - 1][(start[gear_num - 1] + RIGHT) % 8])
		rotate(gear_num - 1, -dir, false);

	// 다 돌리고 나면 톱니바퀴의 시작(12시 방향) 조정
	if (dir == 1) start[gear_num] = (start[gear_num] - 1 + 8) % 8;
	else start[gear_num] = (start[gear_num] + 1) % 8;
}

int main() {
	scanf("%d", &T);

	for (int i = 1; i <= T; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &gear[i][j]);

	scanf("%d", &K);

	for (int i = 0; i < K; i++)
		scanf("%d %d", &cmd[i][0], &cmd[i][1]);

	for (int i = 0; i < K; i++)
		rotate(cmd[i][0], cmd[i][1]);

	int answer = 0;
	for (int i = 1; i <= T; i++)
		if (gear[i][start[i]]) answer++;

	cout << answer;
}
