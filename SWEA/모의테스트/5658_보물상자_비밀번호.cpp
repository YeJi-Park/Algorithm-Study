/*
@Author		YJ Park
@Date		19. 03. 24
@Descript	SWEA [#5658 보물상자 비밀번호]
*/

#include <iostream>
#include <set>
#include <cmath>
#include <climits>

using namespace std;

int N, K;
set<int> s;
int number[28];

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		s.clear();

		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			scanf("%1x", &number[i]);
		}

		for (int i = 0; i < N / 4; i++) {
			int idx = i; // i번 회전시켰을 때의 시작 인덱스

			for (int j = 0; j < 4; j++) {
				int cnt = 0;
				for (int k = N/4; k > 0; k--) {
					cnt += (number[idx] * pow(16, k-1)); // 16진수 자릿수 계산
					idx = (idx + 1) % N;
				}
				s.insert(cnt); // 중복처리 위해 세트 사용~_~
			}
		}

		set<int>::iterator iter = s.begin();
		for (int i = 0; i < s.size() - K; i++) iter++; // 세트 오름차 순이라 뒤에서 k 번째
		printf("#%d %d\n", tc, *iter);
	}
}