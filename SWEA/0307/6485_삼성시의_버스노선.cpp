/*
@Author     YJ Park
@Date       19. 03. 04
@Descript   SWEA [#6485 삼성시의 버스노선]
*/

#include <iostream>
#include <string.h>

using namespace std;

int N, P;
int bus_stop[5001];

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(bus_stop, 0, sizeof(bus_stop));
		cin >> N;

		for (int i = 0; i < N; i++) {
			int start, end;
			cin >> start >> end;

			for (int j = start; j <= end; j++)
				bus_stop[j]++;
		}

		cin >> P;

		printf("#%d ", tc);
		for (int i = 0; i < P; i++) {
			int temp; cin >> temp;
			printf("%d ", bus_stop[temp]);
		}

		printf("\n");
	}
}
