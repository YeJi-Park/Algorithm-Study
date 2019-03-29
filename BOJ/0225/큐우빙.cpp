/*
@Author		YJ Park
@Date		19. 02. 22
@Descript	BOJ [#5373 ť��]

			��¥ �巯���� ��Ǯ�ڴ٤ФФФФ�
			3x3 �迭 ���� 0-8 ���� �ε��� �༭ Ǫ�� �� ������
			�ٵ� �ٽ� �� �ڽ��� ����
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

#define TP 0
#define BT 1
#define FR 2
#define BK 3
#define LL 4
#define RR 5

using namespace std;

int N;
int cube[6][3][3];

// 0: ����, 1: �Ʒ���, 2: �ո�,   3: �޸�    , 4: ���ʸ�, 5: �����ʸ�
// 0: ���, 1: �����, 2: ������, 3: ��������, 4: �ʷϻ�, 5: �Ķ���
void cube_init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++)
			for (int k = 0; k<3; k++)
				cube[i][j][k] = i;
	}
}

void rotate(int dim) {
	int temp[3];

	if (dim == 0) { // ����(��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[BK][0][i];
		for (int i = 0; i < 3; i++) cube[BK][0][i] = cube[LL][0][i];
		for (int i = 0; i < 3; i++) cube[LL][0][i] = cube[FR][0][i];
		for (int i = 0; i < 3; i++) cube[FR][0][i] = cube[RR][0][i];
		for (int i = 0; i < 3; i++) cube[RR][0][i] = temp[i];
	}
	else if (dim == 1) { // �Ʒ� (��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[BK][2][i];
		for (int i = 0; i < 3; i++) cube[BK][2][i] = cube[RR][2][i];
		for (int i = 0; i < 3; i++) cube[RR][2][i] = cube[FR][2][i];
		for (int i = 0; i < 3; i++) cube[FR][2][i] = cube[LL][2][i];
		for (int i = 0; i < 3; i++) cube[LL][2][i] = temp[i];
	}
	else if (dim == 2) { // ��(��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][2][i];
		for (int i = 0; i < 3; i++) cube[TP][2][i] = cube[LL][2 - i][2];
		for (int i = 0; i < 3; i++) cube[LL][i][2] = cube[BT][2][2 - i];
		for (int i = 0; i < 3; i++) cube[BT][2][i] = cube[RR][i][0];
		for (int i = 0; i < 3; i++) cube[RR][i][0] = temp[i];
	}
	else if (dim == 3) { // �� (��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][0][i];
		for (int i = 0; i < 3; i++) cube[TP][0][i] = cube[RR][i][2];
		for (int i = 0; i < 3; i++) cube[RR][i][2] = cube[BT][0][i];
		for (int i = 0; i < 3; i++) cube[BT][0][i] = cube[LL][2 - i][0];
		for (int i = 0; i < 3; i++) cube[LL][i][0] = temp[2 - i];
	}
	else if (dim == 4) { // �� ( ��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][i][0];
		for (int i = 0; i < 3; i++) cube[TP][i][0] = cube[BK][2 - i][2];
		for (int i = 0; i < 3; i++) cube[BK][i][2] = cube[BT][i][2];
		for (int i = 0; i < 3; i++) cube[BT][i][2] = cube[FR][2 - i][0];
		for (int i = 0; i < 3; i++) cube[FR][i][0] = temp[i];
	}
	else if (dim == 5) { // �� ( ��-> ��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][i][2];
		for (int i = 0; i < 3; i++) cube[TP][i][2] = cube[FR][i][2];
		for (int i = 0; i < 3; i++) cube[FR][i][2] = cube[BT][2 - i][0];
		for (int i = 0; i < 3; i++) cube[BT][i][2] = cube[BK][i][0];
		for (int i = 0; i < 3; i++) cube[BK][i][0] = temp[2 - i];
	}
}

void rotate_rvs(int dim) {
	int temp[3];

	if (dim == 0) { // �� (��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[BK][0][i];
		for (int i = 0; i < 3; i++) cube[BK][0][i] = cube[RR][0][i];
		for (int i = 0; i < 3; i++) cube[RR][0][i] = cube[FR][0][i];
		for (int i = 0; i < 3; i++) cube[FR][0][i] = cube[LL][0][i];
		for (int i = 0; i < 3; i++) cube[LL][0][i] = temp[i];
	}
	else if (dim == 1) { //�Ʒ�(��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[BK][2][i];
		for (int i = 0; i < 3; i++) cube[BK][2][i] = cube[LL][2][i];
		for (int i = 0; i < 3; i++) cube[LL][2][i] = cube[FR][2][i];
		for (int i = 0; i < 3; i++) cube[FR][2][i] = cube[RR][2][i];
		for (int i = 0; i < 3; i++) cube[RR][2][i] = temp[i];
	}
	else if (dim == 2) { //��(��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][2][i];
		for (int i = 0; i < 3; i++) cube[TP][2][i] = cube[RR][i][0];
		for (int i = 0; i < 3; i++) cube[RR][i][0] = cube[BT][i][2];
		for (int i = 0; i < 3; i++) cube[BT][i][2] = cube[LL][2 - i][2];
		for (int i = 0; i < 3; i++) cube[LL][i][2] = temp[2 - i];
	}
	else if (dim == 3) { //��(��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][0][i];
		for (int i = 0; i < 3; i++) cube[TP][0][i] = cube[LL][2 - i][0];
		for (int i = 0; i < 3; i++) cube[LL][i][0] = cube[BT][0][2 - i];
		for (int i = 0; i < 3; i++) cube[BT][0][i] = cube[RR][i][2];
		for (int i = 0; i < 3; i++) cube[RR][i][2] = temp[i - 2];
	}
	else if (dim == 4) { //��(��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][i][0];
		for (int i = 0; i < 3; i++) cube[TP][i][0] = cube[FR][i][0];
		for (int i = 0; i < 3; i++) cube[FR][i][0] = cube[BT][i][2];
		for (int i = 0; i < 3; i++) cube[BT][i][0] = cube[BK][i][2];
		for (int i = 0; i < 3; i++) cube[BK][i][2] = temp[2 - i];
	}
	else if (dim == 5) { //��(��->��->��->��->��)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][i][2];
		for (int i = 0; i < 3; i++) cube[TP][i][2] = cube[BK][2 - i][0];
		for (int i = 0; i < 3; i++) cube[BK][i][0] = cube[BT][i][0];
		for (int i = 0; i < 3; i++) cube[BT][i][0] = cube[FR][2 - i][2];
		for (int i = 0; i < 3; i++) cube[FR][i][2] = temp[i];
	}
}

void print_upper() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (cube[0][i][j] == 0) cout << 'w';
			else if (cube[0][i][j] == 1) cout << 'y';
			else if (cube[0][i][j] == 2) cout << 'r';
			else if (cube[0][i][j] == 3) cout << 'o';
			else if (cube[0][i][j] == 4) cout << 'g';
			else if (cube[0][i][j] == 5) cout << 'b';
		}
		cout << "\n";
	}
}

void print_all() {
	for (int k = 0; k < 6; k++) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (cube[k][i][j] == 0) cout << 'w';
				else if (cube[k][i][j] == 1) cout << 'y';
				else if (cube[k][i][j] == 2) cout << 'r';
				else if (cube[k][i][j] == 3) cout << 'o';
				else if (cube[k][i][j] == 4) cout << 'g';
				else if (cube[k][i][j] == 5) cout << 'b';
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

int dim_to_num(char c) {
	if (c == 'U') return 0;
	else if (c == 'D') return 1;
	else if (c == 'F') return 2;
	else if (c == 'B') return 3;
	else if (c == 'L') return 4;
	else if (c == 'R') return 5;
}

void self_rt(int dim) {
	queue<int> q;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			q.push(cube[dim][i][j]);

	for (int i = 2; i >= 0; i--)
		for (int j = 0; j < 3; j++) {
			cube[dim][j][i] = q.front(); q.pop();
		}
}

void self_rv(int dim) {
	queue<int> q;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			q.push(cube[dim][i][j]);

	for (int i = 0; i <3; i++)
		for (int j = 2; j >= 0; j--) {
			cube[dim][j][i] = q.front(); q.pop();
		}
}

int main() {
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;

		cube_init();

		for (int i = 0; i < N; i++) {
			char temp[3];
			cin >> temp;
			if (temp[1] == '+') {
				rotate(dim_to_num(temp[0]));
				self_rt(dim_to_num(temp[0]));
			}
			else {
				rotate_rvs(dim_to_num(temp[0]));
				self_rv(dim_to_num(temp[0]));
			}

			/*printf("**%d**\n", i);
			print_all();*/
		}

		print_upper();
	}
}