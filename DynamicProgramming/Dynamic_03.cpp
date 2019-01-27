/*
@Author		YJ Park
@Date		19. 01. 27
@Descript	Programmers Dinamic Programming #03
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int height = triangle.size();

	//�ؿ��� 2��° �ٺ��� �밢�� �� or �������� �� �� ū �� ���ϸ鼭 �ö�
	for (int i = height - 2; i >= 0; i--)
		for (int j = 0; j<i + 1; j++)
			triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);

	answer = triangle[0][0];

	return answer;
}