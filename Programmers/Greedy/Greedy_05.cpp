/*
@Author		YJ Park
@Date		19. 01. 23
@Descript	Programmers Greedy #05
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//������ ���� ����
bool cmp(vector<int> &a, vector<int> &b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	sort(routes.begin(), routes.end(), cmp);

	//���� ī�޶� 0�� ��� �������� ��ġ
	int cam_location = routes[0][1];
	answer++;

	int size = routes.size();

	//��� ��� ���鼭 �� ���� ��ġ�� ī�޶�� Ŀ�� �������� Ȯ��
	// �ȵǸ� ī�޶� �߰�
	for (int i = 0; i < size; i++) {
		if (cam_location < routes[i][0] | cam_location > routes[i][1]) {
			answer++;
			cam_location = routes[i][1];
		}
	}

	return answer;
}