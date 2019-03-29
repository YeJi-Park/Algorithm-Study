/*
@Author		YJ Park
@Date		19. 03. 29
@Descript	Programmers [#2018 KAKAO ����ä�ù�]

			2) ���� ��� => ����ģ ��� => �����ֱ�
			for�� 3�� ���Ƽ� �׳� Ǯ������..

			(9.19ms / 5.63MB)

*/

#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

// ������ ������ => �ε��� ���� �� ����
bool cmp(pair<double, int> &a, pair<double, int> &b) {
	if (a.first != b.first) return (a.first > b.first);
	else return (a.second < b.second);
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int size = stages.size();
	vector<pair<double, int>> cnt(N + 1, { 0, 0 }); // ���������� ���� ���, �ε���
	vector<int> pass(N + 1, 0); // ������ ��� ��

	for (int i = 1; i <= N; i++) cnt[i].second = i; // answer�� �ֱ� ���ϰ� �ڱ� �ε��� ����

	int all_clear = 0;
	for (int i = 0; i < size; i++) {
		if (stages[i] == N + 1) all_clear++; // ��Ŭ�� ���
		else cnt[stages[i]].first++;
	}

	pass[N] = all_clear + cnt[N].first;

	for (int i = N - 1; i > 0; i--) // �� �������� ����ģ ����� �� �������� ������ ���+���� ���� ���
		pass[i] = pass[i + 1] + cnt[i].first;

	for (int i = N; i > 0; i--) {
		if (!cnt[i].first) cnt[i].first = 0; // �� ���������� ���� ��� X
		else cnt[i].first = cnt[i].first / pass[i]; 
	}

	cnt.erase(cnt.begin()); //0�� ����

	sort(cnt.begin(), cnt.end(), cmp);

	for (int i = 0; i < N; i++)
		answer.push_back(cnt[i].second);

	return answer;
}