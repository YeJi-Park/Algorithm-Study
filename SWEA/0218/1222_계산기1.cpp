/*
@Author		YJ Park
@Date		19. 02. 14
@Descript	SWEA [#1222 S/W 문제해결 기본 - 계산기1]
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int size;
		cin >> size;
		
		string str;
		cin >> str;

		stack<int> num;
		stack<char> op;

		int answer = 0;
		for (int i = 0; i < size; i++) {
			if (str[i] >= '0' && str[i] <= '9')
				answer += (str[i] - '0');
		}
	
		cout << "#" << tc << " " << answer << endl;
	}
}