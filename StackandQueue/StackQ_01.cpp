/*
@Author		YJ Park
@Date		19. 01. 08
@Descript	Programmers Stack/Queue #01
*/

#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	int pipenum = 0;

	int size = arrangement.size();

	int i = 0;

	while (i < size) {
		char a = arrangement[i], b = arrangement[i + 1];
		if (a == '(') {
			if (b == ')') {
				answer += pipenum;
				i++;
			}
			else if (b == '(') {
				pipenum++;
				answer++;
			}

		}
		else pipenum--;

		i++;
	}

	return answer;
}