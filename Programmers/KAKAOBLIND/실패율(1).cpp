/*
@Author		YJ Park
@Date		19. 03. 29
@Descript	Programmers [#2018 KAKAO 오픈채팅방](1)

			1) stages 내림차로 정렬
			해당 스테이지의 마지막 idx가 이 스테이지 지나친 사람 수일 거라고 생각해서
			그 자리에서 나눠버렸는데 뭔가 로직이 잘못된 듯;ㅅ;

			=> 로직 틀린게 아니라 두번째 for문 돌 때 i가 v 마지막까지 돌았을 때 idx처리를 빼놓음!

			(8.20ms, 5.71MB)

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

// 실패율 내림차 => 인덱스 작은 순 정렬
bool cmp(pair<double, int> &a, pair<double, int> &b) {
	if (a.first != b.first) return (a.first > b.first);
	else return (a.second < b.second);
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int size = stages.size();
	vector<pair<double, int> > v(N + 1, { 0,0 });
	sort(stages.begin(), stages.end(), greater<int>()); // 내림차순 정렬
	for (int i = 1; i <= N; i++) v[i].second = i;

	int idx = 0;
	while (idx < size) {
		if (stages[idx] == N + 1) {
			idx++;
			continue;
		}

		int cnt = 0; // 같은 스테이지에서 멈춘 사람 숫자
		int curr_stg = stages[idx];
		for (int i = idx; i < size; i++) {
			if (curr_stg == stages[i]) {
				cnt++;
				if (i == size - 1) idx = size - 1;
				/* i가 마지막까지 돌았을 경우 더 확인 필요 XXX */
			}
			else {
				idx = i - 1;
				break;
			};
		}

		idx++; // idx == 내 앞 스테이지 지나간 사람 수+ 같은 스테이지에 멈춘 사람 수 
		v[curr_stg].first = (cnt) / (double)(idx); 
	}

	v.erase(v.begin());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++)
		answer.push_back(v[i].second);

	return answer;
}