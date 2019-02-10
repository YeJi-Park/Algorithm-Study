/*
@Author		YJ Park
@Date		19. 02. 10
@Descript	SW Academy [#6882 ���ְ� �����ϴ� ������ ����]
*/

#include <iostream>
#include <cmath>

using namespace std;

long long cal(long long N){
	if (N == 2) 
		return 0; 
	else if (N == 1) 
		return 1;
	else {
		long long answer = 0;
		while (N != 2) {
			long long rootN = sqrt(N);

			// ��Ʈ ���Ѱ� N�̸� ���� => Ƚ�� +1
			if (rootN * rootN == N) {
				N = rootN;
				answer++;
			}
			else {
				// (rootN + 1)�� ������ �� ������ 1 ������� ��
				answer += (pow(rootN + 1, 2) - N + 1);
				N = rootN + 1;
			}
		}
		return answer;
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		long long N;
		cin >> N;
		cout << "#" << i << " " << cal(N) << endl;
	}
}