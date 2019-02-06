/*
@Author		YJ Park
@Date		19. 01. 11
@Descript	Programmers Stack/Queue #03
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int now_weight = 0;
	queue<int> on_bridge; 

	// �ٸ� ���̸�ŭ Q�� 0 �־���
	for (int i = 0; i < bridge_length; i++) on_bridge.push(0);

	int size = truck_weights.size();
	int i = 0;

	while (i < size) {
		// �ٸ��� �� �տ� �ִ� Ʈ�� Q���� POP
		now_weight -= on_bridge.front();
		on_bridge.pop();

		// �ٸ��� ���ο� Ʈ���� �ö� �� ������ Q�� PUSH
		if (now_weight + truck_weights[i] <= weight) {
			now_weight += truck_weights[i];
			on_bridge.push(truck_weights[i]);
			i++;
		} // ���ö󰡸� 0 PUSH
		else on_bridge.push(0);

		answer++;
	}

	// ������ Ʈ���� ��� �� �ǳʱ���� bridge_length �� �ʿ���
	return answer + bridge_length;
}