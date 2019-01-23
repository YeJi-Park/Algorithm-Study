/*
@Author		YJ Park
@Date		19. 01. 23
@Descript	Programmers Greedy #04 (수정)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());

	int size = people.size();

	// i ==  남은 사람 중 제일 가벼운 사람, j == 제일 무거운 사람
	int i = 0, j = size - 1;
	for(i; i < j; j--){
		//제일 가벼운 사람이랑 제일 무거운 사람이 같이 탈 수 있을 경우
		// 두명 태워서 보냄
		if (people[j] <= (limit - people[i])) 
			i++; // i == 두명 타있는 보트의 수
	} 
	
	return size - i; // (전체 사람 수 - 두명 타있는 보트의 수)
}