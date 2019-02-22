/*
@Author		YJ Park
@Date		19. 02. 22
@Descript	SWEA [#3752 가능한 시험 점수]

*/

#include <iostream>
#include <string.h>

using namespace std;

int N;
int arr[100];
bool grade[10001];

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		memset(grade, false, sizeof(grade));

		int sum = 0;
		grade[0] = true;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		for (int i = 0; i < N; i++) {
			for (int j = sum; j >= 0; j--) {
				if (grade[j])
					grade[j + arr[i]] = true;
			}
		}

		int ret = 0;
		for (int i = 0; i <= sum; i++) 
			if (grade[i]) 
				ret++

		cout << "#" << tc << " " << ret << endl;
	}
}