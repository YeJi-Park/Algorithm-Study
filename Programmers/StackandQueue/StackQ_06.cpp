/*
@Author		YJ Park
@Date		19. 01. 16
@Descript	Programmers Stack/Queue #06
*/

#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> prices) {
	vector<int> answer;

	int size = prices.size();

	for (int i = 0; i < size; i++) answer.push_back(0);

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size - 1; j++) // i���� (�������� - 1)�ʱ��� ���鼭 �������� �ݺ��� Ż��
			if (prices[i] <= prices[j]) answer[i]++; 
			else break;
	}

	return answer;
}
