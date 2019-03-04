/*
@Author     YJ Park
@Date       19. 03. 04
@Descript   BOJ [#16235 나무재테크]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, K;
int fert[11][11];
int map[11][11];
int need_grow[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

typedef struct Tree {
	int x;
	int y;
	int age;
}tree;

vector<tree> v;

bool cmp(tree &a, tree &b) {
	if (a.y == b.y && a.x == b.x)  return a.age < b.age;
	else if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

void year() {
	sort(v.begin(), v.end(), cmp);

	vector<int> dead_list;
	vector < pair<int, int> > grow;

	int size = v.size();
	for (int i = 0; i < size; i++) {
		int x = v[i].x; int y = v[i].y;
		if (map[x][y] >= v[i].age) {
			map[x][y] -= v[i].age;
			v[i].age++;
			if (!(v[i].age % 5))
				grow.push_back(pair<int, int>(x, y));
		}
		else dead_list.push_back(i);
	}

	for (int i = dead_list.size() - 1; i >= 0; i--) {
		tree temp_tree = v[dead_list[i]];
		int x = temp_tree.x; int y = temp_tree.y;
		map[x][y] += (temp_tree.age / 2);
		v.erase(v.begin() + dead_list[i]);
	}

	for (int i = 0; i < grow.size(); i++) {
		for (int j = 0; j < 8; j++) {
			int tx = grow[i].first + dx[j]; int ty = grow[i].second + dy[j];
			if (tx > 0 && ty > 0 && tx <= N && ty <= N) {
				tree new_tree;
				new_tree.x = tx; new_tree.y = ty;
				new_tree.age = 1;
				v.push_back(new_tree);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] += fert[i][j];
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &fert[i][j]);
			map[i][j] = 5;
		}

	for (int i = 0; i < M; i++) {
		tree new_tree;
		scanf("%d %d %d", &new_tree.x, &new_tree.y, &new_tree.age);
		v.push_back(new_tree);
	}

	for (int i = 0; i < K; i++) {
		year();
	}

	cout << v.size() << "\n";
}
