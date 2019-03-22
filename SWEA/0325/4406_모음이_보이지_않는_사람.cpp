/*
@Author		YJ Park
@Date		19. 03. 21
@Descript	SWEA [#4406 모음이 보이지 않는 사람]
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		string str;
		cin >> str;

		int size = str.size();
		printf("#%d ", tc);
		for (int i = 0; i < size; i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				continue;
			else printf("%c", str[i]);
		}

		printf("\n");
	}
}