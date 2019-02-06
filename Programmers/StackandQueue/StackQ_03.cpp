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

	// 다리 길이만큼 Q에 0 넣어줌
	for (int i = 0; i < bridge_length; i++) on_bridge.push(0);

	int size = truck_weights.size();
	int i = 0;

	while (i < size) {
		// 다리의 맨 앞에 있는 트럭 Q에서 POP
		now_weight -= on_bridge.front();
		on_bridge.pop();

		// 다리에 새로운 트럭이 올라갈 수 있으면 Q에 PUSH
		if (now_weight + truck_weights[i] <= weight) {
			now_weight += truck_weights[i];
			on_bridge.push(truck_weights[i]);
			i++;
		} // 못올라가면 0 PUSH
		else on_bridge.push(0);

		answer++;
	}

	// 마지막 트럭의 경우 다 건너기까지 bridge_length 초 필요함
	return answer + bridge_length;
}