/*
@Author     YJ Park
@Date       19. 03. 07
@Descript   SWEA [#1244 최대 상금]
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

int change, max_v, str_size;

void change_str(string &str, int i, int j) {
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void DFS(int depth, string str, int from) {
	if (depth == change) {
		max_v = max(max_v, stoi(str));
		return;
	}
	else {
		for (int i = from; i < str_size; i++) {
			for (int j = i+1; j < str_size; j++) {
				string temp = str;

				change_str(str, i, j);
				if(stoi(temp) <= stoi(str))
					DFS(depth + 1, str, i);

				change_str(str, j, i);
			}
		}
	}
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string str;
		cin >> str >> change;
		str_size = str.size();
		max_v = INT_MIN;
		DFS(0, str, 0);

		printf("#%d %d\n", tc, max_v);
	}
}