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

	//밑에서 2번째 줄부터 대각선 왼 or 오른쪽의 수 중 큰 값 더하면서 올라감
	for (int i = height - 2; i >= 0; i--)
		for (int j = 0; j<i + 1; j++)
			triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);

	answer = triangle[0][0];

	return answer;
}