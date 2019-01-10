/*
@Author		YJ Park
@Date		19. 01. 08
@Descript	Programmers Hash #01 using sort
*/

#include <vector>
#include <algorithm>

using namespace::std;

string solution(vector<string> participant, vector<string> completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	int size = participant.size(), i = 0;
	for (i; i < size; i++) {
		if (participant[i] != completion[i]) break;
	}

	return participant[i];
}
