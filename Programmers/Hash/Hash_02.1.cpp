/*
@Author		YJ Park
@Date		19. 01. 08
@Descript	Programmers Hash #02 not using multi map
*/

#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace::std;

bool compare(string &a, string &b) {
	return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
	bool answer = true;

	int size = phone_book.size();

	sort(phone_book.begin(), phone_book.end(), compare);

	for (int i = 0; i < size; i++) {
		string prefix = phone_book[i];
		int pfx_size = prefix.size();

		for (int j = i + 1; j < size; j++) {
			if (phone_book[j].substr(0, pfx_size) == prefix) {
				return !answer;
			}
		}
	}
	return answer;
}