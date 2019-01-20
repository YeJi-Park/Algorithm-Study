/*
@Author		YJ Park
@Date		19. 01. 20
@Descript	Programmers Sort #02
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//bool cmp(string &a, string &b) {
//
//	if (a[0] == b[0]) {
//		for (int i = 1; i < a.size(); i++) {
//			if (i >= b.size()) // �� ���� a���� b�� ª�� ��
//				break;
//
//			if (a[i] == b[i]) continue;
//			else return a[i] > b[i]; // i��° �ڸ����� ū ������ ����
//		}
//
//		return a.size() < b.size(); // �ٸ��� ª�� �� ����
//	}
//	else return a[0] > b[0];
//}

bool cmp(string &a, string &b) {
	return (a + b) > (b + a) ? true : false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> v;

	int size = numbers.size();
	for (int i = 0; i < size; i++) v.push_back(to_string(numbers[i]));

	sort(v.begin(), v.end(), cmp);

	for (auto a = v.begin(); a != v.end(); ++a) {
		answer += *a;
	}

	if (answer[0] == '0') answer = "0";

	return answer;
}