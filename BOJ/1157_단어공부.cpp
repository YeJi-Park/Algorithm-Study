/*
@Author		YJ Park
@Date		19. 03. 25
@Descript	BOJ [#1157 단어 공부]
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	string str; cin >> str;

	int gap = 'a' - 'A';

	int alphabet[26] = {0, };

	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 'Z') str[i] -= gap;
		alphabet[str[i] - 'A']++;
	}

	int max = alphabet[0]; int max_idx = 0;
	bool flag = true;

	for (int i = 1; i < 26; i++) {
		if (alphabet[i] > max) {
			max = alphabet[i];
			max_idx = i;
			flag = true;
		}
		else if (alphabet[i] == max) 
			flag = false;
	}

	if(flag) cout << (char)('A' + max_idx) << endl;
	else cout << "?" << endl;
}