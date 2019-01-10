/*
@Author		YJ Park
@Date		19. 01. 08
@Descript	Programmers Hash #02 using multi map
*/

#include <vector>
#include <string>
#include <map>

using namespace::std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	multimap<char, string> phone_map;

	int size = phone_book.size();

	for (int i = 0; i < size; i++) {
		phone_map.insert(pair<char, string>(phone_book[i][0], phone_book[i]));
	}

	multimap<char, string>::iterator iter;

	for (int i = 0; i < size; i++) {
		string phone = phone_book[i];
		int pfx_size = phone.size();
		char prefix = phone[0];

		for (iter = phone_map.lower_bound(prefix);
			iter != phone_map.end() & iter != phone_map.upper_bound(prefix); iter++) {

			if (phone_book[i] == iter->second) continue;

			if (phone_book[i] == iter->second.substr(0, pfx_size)) {
				return !answer;
			}
		}
	}

	return answer;
}