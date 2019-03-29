/*
@Author		YJ Park
@Date		19. 03. 29
@Descript	Programmers [#2018 KAKAO 오픈채팅방]

			record 파싱을 어떻게 해줘야 할까 고민했는데 딱히 방법 없는 것 같아서
			그냥 문자열 길이만큼 돌아서 공백 찾아서 잘라줌

			map은 이미 있는 key가 새로 들어오면 갱신해주기 때문에 map에 {id, nn} 으로 저장
			change의 경우 map에서 처리되기 때문에 enter/leave만 q{cmd, id}에 저장
			id는 q에서 pop하고 map에서 닉네임 찾아서 cmd에 따라 입출 문구만추가해줌
			
			(181.36ms / 46.9MB)
*/

#include <queue>
#include <iostream>
#include <map>
#include <string>
#include <string.h>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;
	queue<pair<string, string>> q;

	for (int i = 0; i<record.size(); i++) {
		vector<string> temp;

		int strcnt = 0;
		for (int j = 0; j < record[i].size(); j++) // 공백 기준으로 문자열 슬라이싱
			if (record[i][j] == ' ') {
				temp.push_back(record[i].substr(strcnt, j - strcnt));
				strcnt = j + 1;
			}

		temp.push_back(record[i].substr(strcnt, record[i].size() - strcnt));

		if(temp[0] != "Change") q.push({ temp[0], temp[1] }); // change일 땐 q에서 알아서 처리
		if (temp[0] != "Leave") m[temp[1]] = temp[2]; // leave의 경우 닉네임 갱신 필요 X
	}


	while (!q.empty()) {
		string cmd = q.front().first; string id = m[q.front().second]; // id 맵에서 찾아서 불러옴
		q.pop();

		// change는 q에 저장 안했기 때문에 enter / leave 두 경우만 있음
		if (cmd == "Enter") id += "님이 들어왔습니다.";
		else id += "님이 나갔습니다.";

		answer.push_back(id);
	}

	return answer;
}