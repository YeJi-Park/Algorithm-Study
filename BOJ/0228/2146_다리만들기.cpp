/*
@Author		YJ Park
@Date		19. 02. 28
@Descript	BOJ [#2146 �ٸ� �����]
			1) �Է¹��� �� BFS�� �� ��������
			2) MAP ���鼭 �ֺ��� �ٴ��� ��� BFS �����ؼ� �ֺ� �� ã��

			+) BFS �޸� ���� ���̱� ���ؼ��� Q�� ���� �� �湮 üũ ����� ��
*/

#include <iostream>
#include <climits>
#include <string.h>
#include <queue>

using namespace std;

int map[100][100];
bool visit[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, min_val;

void BFS_island() { // �� ������ �����ϴ� BFS
	int num_island = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == -1) { // ���� �湮���� ���� ���� ���
				num_island++;
				queue<pair<int, int> > q;
				q.push(pair<int, int>(i, j));
				visit[i][j] = true;

				while (!q.empty()) {
					pair<int, int> here = q.front(); q.pop();
					map[here.first][here.second] = num_island; // ������ ��ȣ ����

					for (int k = 0; k < 4; k++) {
						int tx = here.first + dx[k];
						int ty = here.second + dy[k];

						if (tx >= 0 && ty >= 0 && tx < N && ty < N)
							if (!visit[tx][ty]) {
								visit[tx][ty] = true;
								if(map[tx][ty] == -1) {
									q.push(pair<int, int>(tx, ty));
							}
						}
					}
				}
			}
		}
	}
}

void BFS_bridge() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) {
				bool oc_flag = false;

				for (int k = 0; k < 4; k++) { // �ֺ��� �ٴ� �ִ��� Ȯ��
					int tx = i + dx[k];
					int ty = j + dy[k];

					if (tx >= 0 && ty >= 0 && tx < N && ty < N && !map[tx][ty]) {
						oc_flag = true; // �ֺ� �ٴ��� ��� Ž�� ����
						break;
					}
				}

				if (!oc_flag) continue;
				int this_island = map[i][j]; // ���� ���� ��ȣ

				memset(visit, false, sizeof(visit));
				queue<pair<int, int> > q;
				q.push(pair<int, int>(i, j));
				visit[i][j] = true;
				
				int depth = 0;
				while (!q.empty()) {
					if (depth >= min_val) break;
					int size = q.size(); 

					// depth ���� BFS ���鼭 �ֺ��� �ִ� ���� Ž��
					// => ���� ��� ���ο� ���̸� min_v�� �����ϰ� ����
					// => �ٴ��� ��� Q�� �־ �ٽ� Ž��
					for (int k = 0; k < size; k++) {
						pair<int, int> here = q.front(); q.pop();
						int x = here.first; int y = here.second;
						
						for (int l = 0; l < 4; l++) {
							int tx = x + dx[l]; int ty = y + dy[l];

							if (tx >= 0 && ty >= 0 && tx < N && ty < N && !visit[tx][ty]) {
								visit[tx][ty] = true;

								if (map[tx][ty] && map[tx][ty] != this_island) {
									min_val = min(depth, min_val);
									break;
								}
								else if(!map[tx][ty])
									q.push(pair<int, int>(tx, ty));
							}
						}
					}

					depth++;
				}
			}
		}
	}
}

int main() {
	cin >> N;
	min_val = INT_MAX;

	int temp;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp) temp = -1; //���� ��� -1�� �ʱ�ȭ
			map[i][j] = temp;
		}
	
	BFS_island();
	BFS_bridge();

	cout << min_val << endl;
}