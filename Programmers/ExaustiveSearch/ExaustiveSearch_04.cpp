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
		// i = ���� ������ ���� ����, mok = ���� ������ ���� ����
		// i�� 1���� �Ѱ��� �÷����鼭 ������ ����� �� üũ
		mok = red / i;

		if (mok*i == red) {
			//���� ���ڸ� �׵θ��� �ѷ��� ���� ���� 
			// = (���� ���� ����/���� + 2)��
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