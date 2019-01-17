/*
@Author		YJ Park
@Date		19. 01. 16
@Descript	Programmers Stack/Queue #05
*/

#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> heights) {
	vector<int> answer;

	int size = heights.size();
	
	for (int i = 0; i < size; i++) 
		answer.push_back(0);
	
	for (int i = size - 1; i > 0; i--) {
		int sig = heights[i];

		for (int j = i - 1; j >= 0; j--) {
			if (sig < heights[j]) {
				answer[i] = j+1;
				break;
			}
		}
	}
}
