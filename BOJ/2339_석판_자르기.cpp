/*
@Author		YJ Park
@Date		19. 03. 26
@Descript	BOJ [#2339 석판 자르기]
*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct INFO {
	int jewel; // 보석 갯수
	vector< pair<int, int> > dirt; // 불순물 갯수
}info;

int N, ans;
int map[20][20];

info search_map(int sr, int er, int sc, int ec) { // sr ~ er, sc ~ ec 확인하면서 보석, 불순물 갯수 확인
	info cnt = { 0, vector<pair<int, int> >() };

	for (int i = sr; i <= er; i++) {
		for (int j = sc; j <= ec; j++) {
			if (map[i][j] == 1)
				cnt.dirt.push_back({ i,j }); // 불순물 위치 벡터에 추가
			else if (map[i][j] == 2) cnt.jewel++;
		}
	}

	return cnt;
}

// dir( 1 - 수직, 0 - 수평 )
int cut_stone(int sr, int er, int sc, int ec, bool dir) {
	info cnt = search_map(sr, er, sc, ec); // 이 석판의 상태

	if (cnt.jewel == 1 && !cnt.dirt.size()) return 1; // 보석 한개고 불순물 없으면 가능한 경우
	else if (cnt.jewel > 1 && !cnt.dirt.size()) return 0; // 보석 1개 이상인데 불순물 없으면 못잘라
	else if (cnt.jewel == 0) return 0; // 보석 없는 경우도 실패
	else { // 더 자를 수 있는 경우
		int ret = 0;

		for (int i = 0; i < cnt.dirt.size(); i++) { // 불순물 확인하면서 자를 수 있는 경우 확인
			int tempr = cnt.dirt[i].first; int tempc = cnt.dirt[i].second;
			info line_cnt;

			// 수직
			if (dir) {
				if (ec - tempc < 1 || tempc - sc < 1) continue; // 범위 넘어가는 경우

				line_cnt = search_map(sr, er, tempc, tempc); // 이 라인에 보석 있는지 확인

				if (line_cnt.jewel) continue; // 보석 있으면 못잘라ㅡㅡ
				else ret += (cut_stone(sr, er, sc, tempc - 1, !dir) * cut_stone(sr, er, tempc + 1, ec, !dir));
			}
			else { // 수평
				if (er - tempr < 1 || tempr - sr < 1) continue;

				line_cnt = search_map(tempr, tempr, sc, ec);

				if (line_cnt.jewel) continue;
				else ret += (cut_stone(sr, tempr - 1, sc, ec, !dir) * cut_stone(tempr + 1, er, sc, ec, !dir));
			}
		}

		return ret;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];
		
	info cnt = search_map(0, N - 1, 0, N - 1);

	ans = cut_stone(0, N - 1, 0, N - 1, 1) + cut_stone(0, N - 1, 0, N - 1, 0);
	
	if (!ans) ans = -1; // 0 이면 불가능

	cout << ans << endl;
}