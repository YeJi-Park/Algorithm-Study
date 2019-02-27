/*
@Author		YJ Park
@Date		19. 02. 25
@Descript	SWEA [#6781 ªÔªÔ ∆Æ∏Æ«√ ∞‘¿”]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int success_set;
int map[3][10];

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		success_set = 0;
		vector<pair<int, char> > v(9);
		memset(map, 0, sizeof(map));

		for (int i = 0; i < 9; i++)
			scanf("%1d", &v[i].first);

		int temp;
		scanf("%d", &temp);

		for (int i = 0; i < 9; i++)
			scanf("%1c", &v[i].second);

		for (int i = 0; i < 9; i++) {
			if (v[i].second == 'R') map[0][v[i].first]++;
			else if (v[i].second == 'G') map[1][v[i].first]++;
			else map[2][v[i].first]++;
		}


		for (int i = 0; i < 3; i++) {
			for (int j = 1; j <= 9; j++) {
				while (map[i][j] >= 3) {
					success_set++;
					map[i][j] -= 3;
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 2; j <= 9; j++) {
				while (map[i][j - 2] && map[i][j - 1] && map[i][j]) {
					success_set++;
					map[i][j - 2]--;
					map[i][j - 1]--;
					map[i][j]--;
				}
			}
		}

		cout << "#" << tc << " ";
		if (success_set >= 3) cout << "Win" << endl;
		else cout << "Continue" << endl;
	}
}