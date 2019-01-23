/*
@Author		YJ Park
@Date		19. 01. 23
@Descript	Programmers Greedy #04 (����)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());

	int size = people.size();

	// i ==  ���� ��� �� ���� ������ ���, j == ���� ���ſ� ���
	int i = 0, j = size - 1;
	for(i; i < j; j--){
		//���� ������ ����̶� ���� ���ſ� ����� ���� Ż �� ���� ���
		// �θ� �¿��� ����
		if (people[j] <= (limit - people[i])) 
			i++; // i == �θ� Ÿ�ִ� ��Ʈ�� ��
	} 
	
	return size - i; // (��ü ��� �� - �θ� Ÿ�ִ� ��Ʈ�� ��)
}