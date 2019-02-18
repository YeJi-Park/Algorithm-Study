/*
@Author		YJ Park
@Date		19. 02. 18
@Descript	SWEA [#2805 농작물 수확하기]
*/

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int map[50][50];

int main() {
	int size; cin >> size;
	for (int tc = 1; tc <= size; tc++) {
		cin >> N;


		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) 
				scanf("%1d", &map[i][j]);
			
		int half = (N / 2);

		int answer = 0;
		for (int i = 0; i <= half; i++) {
			for (int j = half - i; j <= half + i; j++)
				answer += map[i][j];
		}

		for (int i = 1; i <= half; i++) {
			for (int j = i; j < N-i; j++)
				answer += map[half+i][j];
		}

		cout << "#" << tc << " " << answer;
	}
}