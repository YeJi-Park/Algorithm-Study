/*
@Author		YJ Park
@Date		19. 03. 29
@Descript	Programmers [#2018 KAKAO ����ä�ù�](1)

			1) stages �������� ����
			�ش� ���������� ������ idx�� �� �������� ����ģ ��� ���� �Ŷ�� �����ؼ�
			�� �ڸ����� �������ȴµ� ���� ������ �߸��� ��;��;

			=> ���� Ʋ���� �ƴ϶� �ι�° for�� �� �� i�� v ���������� ������ �� idxó���� ������!

			(8.20ms, 5.71MB)

*/

#include <iostream>
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
	vector<pair<double, int> > v(N + 1, { 0,0 });
	sort(stages.begin(), stages.end(), greater<int>()); // �������� ����
	for (int i = 1; i <= N; i++) v[i].second = i;

	int idx = 0;
	while (idx < size) {
		if (stages[idx] == N + 1) {
			idx++;
			continue;
		}

		int cnt = 0; // ���� ������������ ���� ��� ����
		int curr_stg = stages[idx];
		for (int i = idx; i < size; i++) {
			if (curr_stg == stages[i]) {
				cnt++;
				if (i == size - 1) idx = size - 1;
				/* i�� ���������� ������ ��� �� Ȯ�� �ʿ� XXX */
			}
			else {
				idx = i - 1;
				break;
			};
		}

		idx++; // idx == �� �� �������� ������ ��� ��+ ���� ���������� ���� ��� �� 
		v[curr_stg].first = (cnt) / (double)(idx); 
	}

	v.erase(v.begin());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++)
		answer.push_back(v[i].second);

	return answer;
}