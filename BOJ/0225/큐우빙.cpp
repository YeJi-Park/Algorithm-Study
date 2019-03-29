/*
@Author		YJ Park
@Date		19. 02. 22
@Descript	BOJ [#5373 큐빙]

			진짜 드러워서 못풀겠다ㅠㅠㅠㅠㅠ
			3x3 배열 말고 0-8 개별 인덱스 줘서 푸는 게 나을듯
			근데 다시 할 자신이 없엉
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

// 0: 윗면, 1: 아랫면, 2: 앞면,   3: 뒷면    , 4: 왼쪽면, 5: 오른쪽면
// 0: 흰색, 1: 노란색, 2: 빨간색, 3: 오렌지색, 4: 초록색, 5: 파란색
void cube_init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++)
			for (int k = 0; k<3; k++)
				cube[i][j][k] = i;
	}
}

void rotate(int dim) {
	int temp[3];

	if (dim == 0) { // 윗면(뒤->오->앞->왼->뒤)
		for (int i = 0; i < 3; i++) temp[i] = cube[BK][0][i];
		for (int i = 0; i < 3; i++) cube[BK][0][i] = cube[LL][0][i];
		for (int i = 0; i < 3; i++) cube[LL][0][i] = cube[FR][0][i];
		for (int i = 0; i < 3; i++) cube[FR][0][i] = cube[RR][0][i];
		for (int i = 0; i < 3; i++) cube[RR][0][i] = temp[i];
	}
	else if (dim == 1) { // 아래 (뒤->왼->앞->오->뒤)
		for (int i = 0; i < 3; i++) temp[i] = cube[BK][2][i];
		for (int i = 0; i < 3; i++) cube[BK][2][i] = cube[RR][2][i];
		for (int i = 0; i < 3; i++) cube[RR][2][i] = cube[FR][2][i];
		for (int i = 0; i < 3; i++) cube[FR][2][i] = cube[LL][2][i];
		for (int i = 0; i < 3; i++) cube[LL][2][i] = temp[i];
	}
	else if (dim == 2) { // 앞(위->오->밑->왼->위)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][2][i];
		for (int i = 0; i < 3; i++) cube[TP][2][i] = cube[LL][2 - i][2];
		for (int i = 0; i < 3; i++) cube[LL][i][2] = cube[BT][2][2 - i];
		for (int i = 0; i < 3; i++) cube[BT][2][i] = cube[RR][i][0];
		for (int i = 0; i < 3; i++) cube[RR][i][0] = temp[i];
	}
	else if (dim == 3) { // 뒤 (위->왼->밑->오->위)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][0][i];
		for (int i = 0; i < 3; i++) cube[TP][0][i] = cube[RR][i][2];
		for (int i = 0; i < 3; i++) cube[RR][i][2] = cube[BT][0][i];
		for (int i = 0; i < 3; i++) cube[BT][0][i] = cube[LL][2 - i][0];
		for (int i = 0; i < 3; i++) cube[LL][i][0] = temp[2 - i];
	}
	else if (dim == 4) { // 왼 ( 위->앞->밑->뒤->위)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][i][0];
		for (int i = 0; i < 3; i++) cube[TP][i][0] = cube[BK][2 - i][2];
		for (int i = 0; i < 3; i++) cube[BK][i][2] = cube[BT][i][2];
		for (int i = 0; i < 3; i++) cube[BT][i][2] = cube[FR][2 - i][0];
		for (int i = 0; i < 3; i++) cube[FR][i][0] = temp[i];
	}
	else if (dim == 5) { // 오 ( 위-> 뒤->밑->앞->위)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][i][2];
		for (int i = 0; i < 3; i++) cube[TP][i][2] = cube[FR][i][2];
		for (int i = 0; i < 3; i++) cube[FR][i][2] = cube[BT][2 - i][0];
		for (int i = 0; i < 3; i++) cube[BT][i][2] = cube[BK][i][0];
		for (int i = 0; i < 3; i++) cube[BK][i][0] = temp[2 - i];
	}
}

void rotate_rvs(int dim) {
	int temp[3];

	if (dim == 0) { // 위 (뒤->왼->앞->오->뒤)
		for (int i = 0; i < 3; i++) temp[i] = cube[BK][0][i];
		for (int i = 0; i < 3; i++) cube[BK][0][i] = cube[RR][0][i];
		for (int i = 0; i < 3; i++) cube[RR][0][i] = cube[FR][0][i];
		for (int i = 0; i < 3; i++) cube[FR][0][i] = cube[LL][0][i];
		for (int i = 0; i < 3; i++) cube[LL][0][i] = temp[i];
	}
	else if (dim == 1) { //아래(뒤->오->앞->왼->뒤)
		for (int i = 0; i < 3; i++) temp[i] = cube[BK][2][i];
		for (int i = 0; i < 3; i++) cube[BK][2][i] = cube[LL][2][i];
		for (int i = 0; i < 3; i++) cube[LL][2][i] = cube[FR][2][i];
		for (int i = 0; i < 3; i++) cube[FR][2][i] = cube[RR][2][i];
		for (int i = 0; i < 3; i++) cube[RR][2][i] = temp[i];
	}
	else if (dim == 2) { //앞(위->왼->밑->오->위)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][2][i];
		for (int i = 0; i < 3; i++) cube[TP][2][i] = cube[RR][i][0];
		for (int i = 0; i < 3; i++) cube[RR][i][0] = cube[BT][i][2];
		for (int i = 0; i < 3; i++) cube[BT][i][2] = cube[LL][2 - i][2];
		for (int i = 0; i < 3; i++) cube[LL][i][2] = temp[2 - i];
	}
	else if (dim == 3) { //뒤(위->오->밑->왼->위)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][0][i];
		for (int i = 0; i < 3; i++) cube[TP][0][i] = cube[LL][2 - i][0];
		for (int i = 0; i < 3; i++) cube[LL][i][0] = cube[BT][0][2 - i];
		for (int i = 0; i < 3; i++) cube[BT][0][i] = cube[RR][i][2];
		for (int i = 0; i < 3; i++) cube[RR][i][2] = temp[i - 2];
	}
	else if (dim == 4) { //왼(위->뒤->밑->앞->위)
		for (int i = 0; i < 3; i++) temp[i] = cube[TP][i][0];
		for (int i = 0; i < 3; i++) cube[TP][i][0] = cube[FR][i][0];
		for (int i = 0; i < 3; i++) cube[FR][i][0] = cube[BT][i][2];
		for (int i = 0; i < 3; i++) cube[BT][i][0] = cube[BK][i][2];
		for (int i = 0; i < 3; i++) cube[BK][i][2] = temp[2 - i];
	}
	else if (dim == 5) { //오(위->앞->밑->뒤->위)
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