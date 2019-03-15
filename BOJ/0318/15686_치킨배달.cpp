/*
@Author		YJ Park
@Date		19. 03. 15
@Descript	BOJ [#15686 ġŲ���]

			�� �� �� �� �� ��
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <climits>

using namespace std;

int map[50][50];
bool visit[13];
int N, M, home_num, chicken_num;
pair<int, int> home[100], chicken[13];
vector<pair<int, int> > select_c; // �� ġŲ���� pop ���ϰ� ����
int min_v, ccnt;

// ġŲ �Ÿ� ����ϴ� �Լ�: ��� ���� ��� ġŲ���Կ� ���� �ּ� �Ÿ� ���ؼ� �ջ�
void chicken_distance() {
	int cnt = 0;

	for (int i = 0; i < home_num; i++) {
		int temp_min = INT_MAX;
		for (int j = 0; j < M; j++) {
			temp_min = min(temp_min,
				abs(home[i].first - select_c[j].first) + abs(home[i].second - select_c[j].second));
		}

		cnt += temp_min;
	}

	min_v = min(min_v, cnt);
}

// M���� ġŲ�� backtracking�ϸ鼭 �߰�
void select_chicken(int depth, int from) {
	if (depth == M) {
		chicken_distance();
		return;
	}
	else {
		for (int i = from; i < chicken_num; i++) {
			if (!visit[i]) {
				visit[i] = true;
				select_c.push_back(chicken[i]);
				select_chicken(depth + 1, i);
				select_c.pop_back();
				visit[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) home[home_num++] = { i,j };
			else if (map[i][j] == 2) chicken[chicken_num++] = { i,j };
		}
	}

	min_v = INT_MAX;
	select_chicken(0, 0);

	cout << min_v << endl;
}