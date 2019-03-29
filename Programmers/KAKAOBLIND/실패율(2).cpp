/*
@Author		YJ Park
@Date		19. 03. 29
@Descript	Programmers [#2018 KAKAO 오픈채팅방]

			2) 멈춘 사람 => 지나친 사람 => 나눠주기
			for문 3번 돌아서 그냥 풀었ㄸㅏ..

			(9.19ms / 5.63MB)

*/

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
	vector<pair<double, int>> cnt(N + 1, { 0, 0 }); // 스테이지에 멈춘 사람, 인덱스
	vector<int> pass(N + 1, 0); // 지나간 사람 수

	for (int i = 1; i <= N; i++) cnt[i].second = i; // answer에 넣기 편하게 자기 인덱스 저장

	int all_clear = 0;
	for (int i = 0; i < size; i++) {
		if (stages[i] == N + 1) all_clear++; // 올클한 사람
		else cnt[stages[i]].first++;
	}

	pass[N] = all_clear + cnt[N].first;

	for (int i = N - 1; i > 0; i--) // 이 스테이지 지나친 사람은 전 스테이지 지나간 사람+여기 멈춘 사람
		pass[i] = pass[i + 1] + cnt[i].first;

	for (int i = N; i > 0; i--) {
		if (!cnt[i].first) cnt[i].first = 0; // 이 스테이지에 멈춘 사람 X
		else cnt[i].first = cnt[i].first / pass[i]; 
	}

	cnt.erase(cnt.begin()); //0번 삭제

	sort(cnt.begin(), cnt.end(), cmp);

	for (int i = 0; i < N; i++)
		answer.push_back(cnt[i].second);

	return answer;
}