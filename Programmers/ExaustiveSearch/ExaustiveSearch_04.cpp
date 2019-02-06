/*
@Author		YJ Park
@Date		19. 01. 20
@Descript	Programmers Exaustive Search #04
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int mok;

	for (int i = 1; i <= red; i++) {
		// i = 빨간 격자의 세로 갯수, mok = 빨간 격자의 가로 갯수
		// i를 1부터 한개씩 늘려가면서 가능한 경우의 수 체크
		mok = red / i;

		if (mok*i == red) {
			//갈색 격자를 테두리에 둘렀을 때의 갯수 
			// = (빨간 격자 가로/세로 + 2)개
			int garo = mok + 2; 
			int sero = i + 2;

			if ((garo*sero - red) == brown) {
				answer.push_back(garo);
				answer.push_back(sero);
				break;
			}
		}
	}

	return answer;
}