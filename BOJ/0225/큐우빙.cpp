/*
@Author		YJ Park
@Date		19. 02. 22
@Descript	BOJ [#5373 Å¥ºù]
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int cube[6][3][3];
int direction[6][4] = {
	{2,4,3,5}, {2,5,3,4}, {4,0,5,1}, {4,1,5,0}, {0,2,1,3}, {0,3,1,2}
};

// 0: À­¸é, 1: ¾Æ·§¸é, 2: ¾Õ¸é,   3: µÞ¸é    , 4: ¿ÞÂÊ¸é, 5: ¿À¸¥ÂÊ¸é
// 0: Èò»ö, 1: ³ë¶õ»ö, 2: »¡°£»ö, 3: ¿À·»Áö»ö, 4: ÃÊ·Ï»ö, 5: ÆÄ¶õ»ö
void cube_init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++)
			for(int k=0; k<3; k++)
				cube[i][j][k] = i;
	}
}

void rotate(int dim) {
	int tempA[3], tempB[3];

	if (dim == 0) {
		for (int i = 0; i < 3; i++) tempA[i] = cube[2][0][i];
		for (int i = 0; i < 3; i++) tempB[i] = cube[4][0][i];

		for (int i = 0; i < 3; i++) cube[2][0][i] = cube[5][0][i];
		for (int i = 0; i < 3; i++) cube[4][0][i] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[3][0][i];

		for (int i = 0; i < 3; i++) cube[3][0][i] = tempB[i];
		for (int i = 0; i < 3; i++) cube[5][0][i] = tempA[i];
	}
	else if (dim == 1) {
		for (int i = 0; i < 3; i++) tempA[i] = cube[2][2][i];
		for (int i = 0; i < 3; i++) tempB[i] = cube[5][2][i];

		for (int i = 0; i < 3; i++) cube[2][2][i] = cube[4][2][i];
		for (int i = 0; i < 3; i++) cube[5][2][i] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[3][2][i];

		for (int i = 0; i < 3; i++) cube[3][2][i] = tempB[i];
		for (int i = 0; i < 3; i++) cube[4][2][i] = tempA[i];
	}
	else if (dim == 2) { 
		for (int i = 0; i < 3; i++) tempA[i] = cube[4][i][2];
		for (int i = 0; i < 3; i++) tempB[i] = cube[0][2][i];

		for (int i = 0; i < 3; i++) cube[4][i][2] = cube[1][0][i];
		for (int i = 0; i < 3; i++) cube[0][2][i] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[5][i][0];

		for (int i = 0; i < 3; i++) cube[5][i][0] = tempB[i];
		for (int i = 0; i < 3; i++) cube[1][0][i] = tempA[i];
	}
	else if (dim == 3) {
		for (int i = 0; i < 3; i++) tempA[i] = cube[4][i][0];
		for (int i = 0; i < 3; i++) tempB[i] = cube[1][2][i];

		for (int i = 0; i < 3; i++) cube[4][i][0] = cube[0][0][i];
		for (int i = 0; i < 3; i++) cube[1][2][i] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[5][i][2];

		for (int i = 0; i < 3; i++) cube[5][i][2] = tempB[i];
		for (int i = 0; i < 3; i++) cube[0][0][i] = tempA[i];
	}
	else if (dim == 4) { // ¿ÞÂÊ ½Ã°è¤Ð¤Ð À§¾Õ ¾Õ¹Ø ¹ØµÚ µÚÀ§
		for (int i = 0; i < 3; i++) tempA[i] = cube[0][i][0];
		for (int i = 0; i < 3; i++) tempB[i] = cube[2][i][0];

		for (int i = 0; i < 3; i++) cube[0][i][0] = cube[3][i][0];
		for (int i = 0; i < 3; i++) cube[2][i][0] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[1][i][0];

		for (int i = 0; i < 3; i++) cube[1][i][0] = tempB[i];
		for (int i = 0; i < 3; i++) cube[3][i][0] = tempA[i];
	}
	else if (dim == 5) {
		for (int i = 0; i < 3; i++) tempA[i] = cube[0][i][2];
		for (int i = 0; i < 3; i++) tempB[i] = cube[3][i][2];

		for (int i = 0; i < 3; i++) cube[0][i][2] = cube[2][i][2];
		for (int i = 0; i < 3; i++) cube[3][i][2] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[1][i][2];

		for (int i = 0; i < 3; i++) cube[1][i][2] = tempB[i];
		for (int i = 0; i < 3; i++) cube[2][i][2] = tempA[i];
	}
}

void rotate_rvs(int dim) {
	int tempA[3], tempB[3];

	if (dim == 0) { // À§ ¹Ý½Ã°è µÚ->¿Þ ¿Þ->¾Õ ¾Õ->¿À ¿À->µÚ
		for (int i = 0; i < 3; i++) tempA[i] = cube[3][0][i];
		for (int i = 0; i < 3; i++) tempB[i] = cube[4][0][i];

		for (int i = 0; i < 3; i++) cube[3][0][i] = cube[5][0][i];
		for (int i = 0; i < 3; i++) cube[4][0][i] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[2][0][i];

		for (int i = 0; i < 3; i++) cube[2][0][i] = tempB[i];
		for (int i = 0; i < 3; i++) cube[5][0][i] = tempA[i];
	}
	else if (dim == 1) { // ¹Ø ¹Ý½Ã°è ¾Õ->¿Þ ¿Þ->µÚ µÚ->¿À ¿À->¾Õ
		for (int i = 0; i < 3; i++) tempA[i] = cube[3][2][i];
		for (int i = 0; i < 3; i++) tempB[i] = cube[5][2][i];

		for (int i = 0; i < 3; i++) cube[3][2][i] = cube[4][2][i];
		for (int i = 0; i < 3; i++) cube[5][2][i] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[2][2][i];

		for (int i = 0; i < 3; i++) cube[2][2][i] = tempB[i];
		for (int i = 0; i < 3; i++) cube[4][2][i] = tempA[i];
	}
	else if (dim == 2) {
		for (int i = 0; i < 3; i++) tempA[i] = cube[4][i][2];
		for (int i = 0; i < 3; i++) tempB[i] = cube[1][0][i];

		for (int i = 0; i < 3; i++) cube[4][i][2] = cube[0][2][i];
		for (int i = 0; i < 3; i++) cube[1][0][i] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[5][i][0];

		for (int i = 0; i < 3; i++) cube[5][i][0] = tempB[i];
		for (int i = 0; i < 3; i++) cube[0][2][i] = tempA[i];
	}
	else if (dim == 3) {
		for (int i = 0; i < 3; i++) tempA[i] = cube[4][i][0];
		for (int i = 0; i < 3; i++) tempB[i] = cube[0][0][i];

		for (int i = 0; i < 3; i++) cube[4][i][0] = cube[1][2][i];
		for (int i = 0; i < 3; i++) cube[0][0][i] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[5][i][2];

		for (int i = 0; i < 3; i++) cube[5][i][2] = tempB[i];
		for (int i = 0; i < 3; i++) cube[1][2][i] = tempA[i];
	}
	else if (dim == 4) {
		for (int i = 0; i < 3; i++) tempA[i] = cube[0][i][0];
		for (int i = 0; i < 3; i++) tempB[i] = cube[3][i][0];

		for (int i = 0; i < 3; i++) cube[0][i][0] = cube[2][i][0];
		for (int i = 0; i < 3; i++) cube[3][i][0] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[1][i][0];

		for (int i = 0; i < 3; i++) cube[1][i][0] = tempB[i];
		for (int i = 0; i < 3; i++) cube[2][i][0] = tempA[i];
	}
	else if (dim == 5) {
		for (int i = 0; i < 3; i++) tempA[i] = cube[0][i][2];
		for (int i = 0; i < 3; i++) tempB[i] = cube[2][i][2];

		for (int i = 0; i < 3; i++) cube[0][i][2] = cube[3][i][2];
		for (int i = 0; i < 3; i++) cube[2][i][2] = tempA[i];

		for (int i = 0; i < 3; i++) tempA[i] = cube[1][i][2];

		for (int i = 0; i < 3; i++) cube[1][i][2] = tempB[i];
		for (int i = 0; i < 3; i++) cube[3][i][2] = tempA[i];
	}
}

void print_upper() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (cube[0][i][j] == 0) cout << 'w';
			else if(cube[0][i][j] == 1) cout << 'y';
			else if (cube[0][i][j] == 2) cout << 'r';
			else if (cube[0][i][j] == 3) cout << 'o';
			else if (cube[0][i][j] == 4) cout << 'g';
			else if (cube[0][i][j] == 5) cout << 'b';
		}
		cout << "\n";
	}
}

int dim_to_num(char c)
{
	if (c == 'U') return 0;
	else if (c == 'D') return 1;
	else if (c == 'F') return 2;
	else if (c == 'B') return 3;
	else if (c == 'L') return 4;
	else if (c == 'R') return 5;
}

int main() {
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;

		cube_init();
		
		for (int i = 0; i < N; i++) {
			char temp[3];
			cin >> temp;
			if (temp[1] == '+') rotate(dim_to_num(temp[0]));
			else rotate_rvs(dim_to_num(temp[0]));
		}

		print_upper();
	}
}