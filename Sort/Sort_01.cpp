/*
@Author		YJ Park
@Date		19. 01. 20
@Descript	Programmers Sort #01
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	int size = commands.size();

	for (int i = 0; i < size; i++) {
		vector<int> cmd = commands[i], temp;
		for (int j = cmd[0]-1; j < cmd[1]; j++) 
			temp.push_back(array[j]);

		sort(temp.begin(), temp.end());
		answer.push_back(temp[cmd[2] - 1]);
	}

	return answer;
}