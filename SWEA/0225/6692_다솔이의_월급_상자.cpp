/*
@Author		YJ Park
@Date		19. 02. 21
@Descript	SWEA [#6692 �ټ����� ���� ����]
			
			+) ������� �Ű澲��!_!
*/

#include <iostream>

using namespace std;

int N;
double p[20];
int x[20];

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		double money = 0;

		for (int i = 0; i < N; i++) {
			cin >> p[i] >> x[i];
			money += (p[i] * x[i]);
		}

		cout << cout.precision(6);
		
		cout << "��";

		cout << "#" << tc <<" " << fixed << money << endl;
	}
}