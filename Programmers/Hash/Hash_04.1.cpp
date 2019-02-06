/*
@Author		YJ Park
@Date		19. 02. 06
@Descript	Programmers Hash #02			
*/


#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
	return (a.second > b.second);
}

bool cmp2(pair<int, int> &a, pair<int, int> &b) {
	return (a.first > b.first);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	int size = genres.size();
	map<string, int> g_list;
	map < string, vector<pair<int, int>>> s_list;

	for (int i = 0; i < size; i++) {
		g_list[genres[i]] += plays[i];
		s_list[genres[i]].push_back(pair<int, int>(plays[i], i));
	}

	vector<pair<string, int>> gg;
	for (auto x : g_list) gg.push_back(x);

	sort(gg.begin(), gg.end(), cmp);

	for (auto iter : gg) {
		vector<pair<int, int>> &temp = s_list[iter.first];
		sort(temp.begin(), temp.end(), cmp2);
		size = temp.size();
		answer.push_back(temp[0].second);

		if (size >= 2)
			answer.push_back(temp[1].second);

	}

	return answer;

}
