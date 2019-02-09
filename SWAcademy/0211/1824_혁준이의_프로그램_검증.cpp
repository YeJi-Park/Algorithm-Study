/*
@Author		YJ Park
@Date		19. 02. 09
@Descript	SW Academy [1824.혁진이의 프로그램 검증]

			DFS로 경로추적
			x, y, dir, mem의 4차원 visit 행렬 만들어서
			같은 메모리, 같은 방향일 때 또 접근할 경우 false
			?일 경우 4방향 모두 검사
			=> 하나라도 @에 닿을 수 있는 경우 true

			*)	memset 잊지말기
				for문 조건 정확하게 주기
*/

#include <vector>
#include <string>
#include <iostream>
#include <memory.h>

using namespace std;


bool visit[20][20][4][15]; 

// 방향 아래 위 오른 왼
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int R, C;
vector<string> cmd;

bool DFS(int x, int y, int dir, int mem) {
	if (cmd[x][y]  == '@') return true;
	else if (cmd[x][y]  == '<') {
		if (y == 0) y = C - 1;
		else y--;

		if (visit[x][y][3][mem]) return false;
		else {
			visit[x][y][3][mem] = true;
			return DFS(x, y, 3, mem);
		}
	}
	else if (cmd[x][y]  == '>') {
		if (y == C - 1) y = 0;
		else y++;

		if (visit[x][y][2][mem]) return false;
		else {
			visit[x][y][3][mem] = true;
			return DFS(x, y, 2, mem);
		}
	}
	else if (cmd[x][y]  == '^') {
		if (x == 0) x = R - 1;
		else x--;

		if (visit[x][y][1][mem]) return false;
		else {
			visit[x][y][1][mem] = true;
			return DFS(x, y, 1, mem);
		}
	}
	else if (cmd[x][y]  == 'v') {
		if (x == R - 1) x = 0;
		else x++;

		if (visit[x][y][0][mem]) return false;
		else {
			visit[x][y][0][mem] = true;
			return DFS(x, y, 0, mem);
		}
	}
	else if (cmd[x][y]  == '_') {
		if (mem == 0) dir = 2;
		else dir = 3;

		y = (y + dy[dir] + C) % C;

		if (visit[x][y][dir][mem]) return false;
		else {
			visit[x][y][dir][mem] = true;
			return DFS(x, y, dir, mem);
		}
	}
	else if (cmd[x][y]  == '|') {
		if (mem == 0) dir = 0;
		else dir = 1;

		x = (x + dx[dir] + R) % R;

		if (visit[x][y][dir][mem]) return false;
		else {
			visit[x][y][dir][mem] = true;
			return DFS(x, y, dir, mem);
		}
	}
	else if (cmd[x][y] == '?') {
		bool check = false;

		for (int i = 0; i < 4; i++) {
			int temp_x = (x + dx[i] + R) % R;
			int temp_y = (y + dy[i] + C) % C;

			if (visit[temp_x][temp_y][i][mem]) continue;
			else {
				visit[temp_x][temp_y][i][mem] = true;
				if (DFS(temp_x, temp_y, i, mem))
					check = true;
			}
		}
		return check;
	
	}
	else {
		if (cmd[x][y] >= '0' && cmd[x][y] <= '9') {
			mem = cmd[x][y] - '0';
		}
		else if (cmd[x][y] == '+') {
			mem++;
			if (mem == 16) mem = 0;
		}
		else if (cmd[x][y] == '-') {
			mem--;
			if (mem < 0) mem = 15;
		}

		x = (x + dx[dir] + R) % R;
		y = (y + dy[dir] + C) % C;

		if (visit[x][y][dir][mem]) return false;
		else {
			visit[x][y][dir][mem] = true;
			return DFS(x, y, dir, mem);
		}
	}
}

int main() {
	int case_num;
	cin >> case_num;

	for (int i = 0; i < case_num; i++) {
		memset(&visit, false, sizeof(visit));

		cin >> R >> C;

		cmd.resize(R);

		string temp;
		for (int j = 0; j < R; j++)
			cin >> cmd[j];

		bool flag = DFS(0, 0, 2, 0);
		cout << "#" << i + 1 << " ";

		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}