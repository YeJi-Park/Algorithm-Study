/*
@Author     YJ Park
@Date       19. 03. 06
@Descript   BOJ [#3190 ��]
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
		curr_sec++; // �� �ø���

		// �Ӹ� ������ ��ġ
		int tx = snake_pos[size - 1].first + dx[dir];
		int ty = snake_pos[size - 1].second + dy[dir];

		//�� �ε����ų� ������ �̹� ���� ��� ���� ����
		if (tx <= 0 || ty <= 0 || tx > N || ty > N) return false;
		if (map[tx][ty] == 1) return false;

		snake_pos.push_back(pair<int, int>(tx, ty)); // �Ӹ� ��ġ �߰�

		if (map[tx][ty] != 9) { // ��� ������ ��� ���� �ִ� �ڸ� 0 
			map[snake_pos[tail].first][snake_pos[tail].second] = 0;
			tail++; // ���� �ε���++
		}

		map[tx][ty] = 1; // �ʿ� �� ǥ��
		size++; // �� ���� �� ������
	}

	// �߷����� ������ ���Ϳ��� �����ֱ�
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
	snake_pos.push_back(pair<int, int>(1, 1)); // �ʱ� �Ӹ� ��ġ �Է�
	
	for (int i = 0; i < L; i++) {
		cin >> sec >> d;
		tail = 0; // ����������� �Է¹��� �������� �� ������ ��
		flag = snake(sec, dir); 
		if (!flag) break; // �߰��� ���� ������ ���

		if (d == 'D') dir = (dir + 1) % 4; // X�� ���� ���� ��ȯ
		else dir = (dir + 3) % 4;
	}

	while (flag) flag = snake(INT_MAX, dir); // ������ȯ ������ ��� ��� �� ��������

	cout << curr_sec << endl;
}