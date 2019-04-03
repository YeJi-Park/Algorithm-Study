/*
@Author		YJ Park
@Date		19. 03. 26
@Descript	BOJ [#2339 ���� �ڸ���]
*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct INFO {
	int jewel; // ���� ����
	vector< pair<int, int> > dirt; // �Ҽ��� ����
}info;

int N, ans;
int map[20][20];

info search_map(int sr, int er, int sc, int ec) { // sr ~ er, sc ~ ec Ȯ���ϸ鼭 ����, �Ҽ��� ���� Ȯ��
	info cnt = { 0, vector<pair<int, int> >() };

	for (int i = sr; i <= er; i++) {
		for (int j = sc; j <= ec; j++) {
			if (map[i][j] == 1)
				cnt.dirt.push_back({ i,j }); // �Ҽ��� ��ġ ���Ϳ� �߰�
			else if (map[i][j] == 2) cnt.jewel++;
		}
	}

	return cnt;
}

// dir( 1 - ����, 0 - ���� )
int cut_stone(int sr, int er, int sc, int ec, bool dir) {
	info cnt = search_map(sr, er, sc, ec); // �� ������ ����

	if (cnt.jewel == 1 && !cnt.dirt.size()) return 1; // ���� �Ѱ��� �Ҽ��� ������ ������ ���
	else if (cnt.jewel > 1 && !cnt.dirt.size()) return 0; // ���� 1�� �̻��ε� �Ҽ��� ������ ���߶�
	else if (cnt.jewel == 0) return 0; // ���� ���� ��쵵 ����
	else { // �� �ڸ� �� �ִ� ���
		int ret = 0;

		for (int i = 0; i < cnt.dirt.size(); i++) { // �Ҽ��� Ȯ���ϸ鼭 �ڸ� �� �ִ� ��� Ȯ��
			int tempr = cnt.dirt[i].first; int tempc = cnt.dirt[i].second;
			info line_cnt;

			// ����
			if (dir) {
				if (ec - tempc < 1 || tempc - sc < 1) continue; // ���� �Ѿ�� ���

				line_cnt = search_map(sr, er, tempc, tempc); // �� ���ο� ���� �ִ��� Ȯ��

				if (line_cnt.jewel) continue; // ���� ������ ���߶�Ѥ�
				else ret += (cut_stone(sr, er, sc, tempc - 1, !dir) * cut_stone(sr, er, tempc + 1, ec, !dir));
			}
			else { // ����
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
	
	if (!ans) ans = -1; // 0 �̸� �Ұ���

	cout << ans << endl;
}