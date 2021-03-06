/*
@Author		YJ Park
@Date		19. 02. 19
@Descript	BOJ [#14891 ��Ϲ���]

			+) ������ �� �а� Ǯ��
*/

#include <iostream>

using namespace std;

#define LEFT 6
#define RIGHT 2

bool gear[5][8];
int start[5];
int cmd[100][2];
int K;

// 1 ���ʿ��� ��, 0 �����ʿ��� �� => ���������� ��� ������
void rotate(int gear_num, int dir, bool flag) {
	if (flag) {
		if (gear_num < 4 &&
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

// ó�� ������ ��Ϲ����� ���� �� Ȯ���ؾ���
void rotate(int gear_num, int dir) {

	// ���ʿ� ��Ϲ��� �ְ� ���� �� ������ ���������� ��Ϲ����� Ȯ��
	if (gear_num < 4 &&
		gear[gear_num][(start[gear_num] + RIGHT) % 8] != gear[gear_num + 1][(start[gear_num + 1] + LEFT) % 8])
		rotate(gear_num + 1, -dir, true);

	if (gear_num > 1 && gear[gear_num][(start[gear_num] + LEFT) % 8] != gear[gear_num - 1][(start[gear_num - 1] + RIGHT) % 8])
		rotate(gear_num - 1, -dir, false);

	// �� ������ ���� ��Ϲ����� ����(12�� ����) ����
	if (dir == 1) start[gear_num] = (start[gear_num] - 1 + 8) % 8;
	else start[gear_num] = (start[gear_num] + 1) % 8;
}

int main() {
	for (int i = 1; i < 5; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &gear[i][j]);

	scanf("%d", &K);

	for (int i = 0; i < K; i++)
		scanf("%d %d", &cmd[i][0], &cmd[i][1]);

	for (int i = 0; i < K; i++) 
		rotate(cmd[i][0], cmd[i][1]);

	int answer = 0;
	for (int i = 1; i < 5; i++) 
		answer += ((gear[i][start[i]]) << (i - 1));

	cout << answer;
}