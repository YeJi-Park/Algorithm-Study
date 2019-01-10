/*
@Author		YJ Park
@Date		19. 01. 10
@Descript	Programmers Hash #04
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <functional>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	unordered_map<string, int> genre_list;
	map<int, string, greater<int>> rvs_list;
	unordered_map<string, vector<int>> song_list;

	int size = genres.size();
	for (int i = 0; i < size; i++) {
		genre_list[genres[i]] += plays[i];
		song_list[genres[i]].push_back(i);
	}

	for (auto iter = genre_list.begin(); iter != genre_list.end(); ++iter) {
		rvs_list[iter->second] = iter->first;
	}

	for (auto iter = rvs_list.begin(); iter != rvs_list.end(); ++iter) {
		string genre = iter->second;
		vector<int> songs = song_list[genre];
		size = songs.size();
		int first = -1, second = -1;

		for (int i = size - 1; i >= 0; i--) {
			int temp = plays[songs[i]];
			if (first == -1) first = songs[i];
			else if (second == -1) second = songs[i];
			else if (temp >= plays[first]) {
				second = first;
				first = songs[i];
			}
			else if (temp >= plays[second])
				second = songs[i];
		}

		answer.push_back(first);

		if (size != 1)
			answer.push_back(second);

	}

	return answer;
}