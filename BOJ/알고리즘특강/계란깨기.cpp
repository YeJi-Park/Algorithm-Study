/*
@Author		YJ Park
@Date		19. 03. 02
@Descript	[A. 계란깨기]
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int max_egg;
pair<int, int> eggs[8];

void egg_cnt(pair<int, int> temp_egg[8]) {
	int cnt = 0;

	for (int i = 0; i < N; i++) 
		if (temp_egg[i].first <= 0)
			cnt++;

	max_egg = max(max_egg, cnt);
	return;
}
//
// 왜 다른 지 분석해보기
//void crash_egg(pair<int, int> temp_egg[8], int from) {
//	for (int i = from; i < N; i++) {
//		bool flag = false;
//		if (temp_egg[i].first <= 0) crash_egg(temp_egg, from + 1);
//
//		for (int j = 0; j < N; j++) {
//			if (i == j) continue;
//			if (temp_egg[j].first <= 0) continue;
//
// 			temp_egg[i].first -= temp_egg[j].second;
//			temp_egg[j].first -= temp_egg[i].second;
//
//			crash_egg(temp_egg, i+1);
//
//			temp_egg[i].first += temp_egg[j].second;
//			temp_egg[j].first += temp_egg[i].second;
//		}
//	}
//
//	egg_cnt(temp_egg);
//}
//

void crash(pair<int, int> temp_egg[8], int from) {
	if (from == N) {
		egg_cnt(temp_egg);
		return;
	}

	if (temp_egg[from].first <= 0) {
		crash(temp_egg, from + 1);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (temp_egg[i].first <= 0) continue;
		if (i == from) continue;

		temp_egg[i].first -= temp_egg[from].second;
		temp_egg[from].first -= temp_egg[i].second;

		crash(temp_egg, from+1);

		temp_egg[i].first += temp_egg[from].second;
		temp_egg[from].first += temp_egg[i].second;

	}
	
	crash(temp_egg, N);
}


int main() {
	cin >> N;
	max_egg = 0;

	for (int i = 0; i < N; i++) {
		cin >> eggs[i].first >> eggs[i].second;
	}

	crash(eggs, 0);

	cout << max_egg << endl;
}