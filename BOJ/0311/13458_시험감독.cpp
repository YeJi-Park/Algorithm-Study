/*
@Author     YJ Park
@Date       19. 03. 07
@Descript   BOJ [#13458 시험감독]
			
			데이터 범위 체크
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, dir, vice;
vector<int> room;

int main() {
	cin >> N;
	room.resize(N);

	for (int i = 0; i < N; i++) 
		cin >> room[i];
	
	cin >> dir >> vice;
	
	long long cnt = N;
	for (int i = 0; i < N; i++) {
		room[i] -= dir;

		if (room[i] > 0) {
			if (room[i] <= vice) 
				cnt++;
			else 
				cnt += ceil((double)(room[i]) / vice);
		}
	}

	cout << cnt << endl;
}