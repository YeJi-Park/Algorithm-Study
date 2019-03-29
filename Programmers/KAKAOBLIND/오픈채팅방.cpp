/*
@Author		YJ Park
@Date		19. 03. 29
@Descript	Programmers [#2018 KAKAO ����ä�ù�]

			record �Ľ��� ��� ����� �ұ� ����ߴµ� ���� ��� ���� �� ���Ƽ�
			�׳� ���ڿ� ���̸�ŭ ���Ƽ� ���� ã�Ƽ� �߶���

			map�� �̹� �ִ� key�� ���� ������ �������ֱ� ������ map�� {id, nn} ���� ����
			change�� ��� map���� ó���Ǳ� ������ enter/leave�� q{cmd, id}�� ����
			id�� q���� pop�ϰ� map���� �г��� ã�Ƽ� cmd�� ���� ���� �������߰�����
			
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
		for (int j = 0; j < record[i].size(); j++) // ���� �������� ���ڿ� �����̽�
			if (record[i][j] == ' ') {
				temp.push_back(record[i].substr(strcnt, j - strcnt));
				strcnt = j + 1;
			}

		temp.push_back(record[i].substr(strcnt, record[i].size() - strcnt));

		if(temp[0] != "Change") q.push({ temp[0], temp[1] }); // change�� �� q���� �˾Ƽ� ó��
		if (temp[0] != "Leave") m[temp[1]] = temp[2]; // leave�� ��� �г��� ���� �ʿ� X
	}


	while (!q.empty()) {
		string cmd = q.front().first; string id = m[q.front().second]; // id �ʿ��� ã�Ƽ� �ҷ���
		q.pop();

		// change�� q�� ���� ���߱� ������ enter / leave �� ��츸 ����
		if (cmd == "Enter") id += "���� ���Խ��ϴ�.";
		else id += "���� �������ϴ�.";

		answer.push_back(id);
	}

	return answer;
}