/*
@Author		YJ Park
@Date		19. 01. 08
@Descript	Programmers Hash #03 
*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace::std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> cloth;
	unordered_map<string, int>::iterator iter;

	int size = clothes.size();

	for (int i = 0; i < size; i++) {
		if ( (iter = cloth.find(clothes[i][1])) == cloth.end()) {
			cloth.insert(pair<string, int>(clothes[i][1], 1));
		}
		else {
			iter->second++;
		}
	}

	for (iter = cloth.begin(); iter != cloth.end(); iter++) {
		answer *= (iter->second + 1);
	}

	return --answer;
}