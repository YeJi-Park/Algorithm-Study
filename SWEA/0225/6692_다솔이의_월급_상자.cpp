/*
@Author		YJ Park
@Date		19. 02. 21
@Descript	SWEA [#6692 다솔이의 월급 상자]
			
			+) 출력형식 신경쓰기!_!
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
		
		cout << "얍";

		cout << "#" << tc <<" " << fixed << money << endl;
	}
}