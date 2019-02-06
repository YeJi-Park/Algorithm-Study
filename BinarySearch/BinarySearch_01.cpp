/*
@Author		YJ Park
@Date		19. 02. 05
@Descript	Programmers Binary Search #01

			1.	처음에 예산평균보다 작은 예산을 요구하는 부서들에게 다 나눠준 후
				남은 예산치의 평균이 답일 거라고 생각했는데 80점ㅠㅠ
			2.	

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//int binary_search(int high, int low, int money) {
//
//	while (low<=high) {
//		int mid = (high + low) / 2;
//		if (bd[mid] > money) {
//			high = mid;
//			if (bd[mid - 1] <= money) 
//				return mid - 1;
//		}
//		else if (bd[mid] < money) {
//			low = mid;
//			if (bd[mid + 1] > money) return mid;
//			else if (bd[mid + 1] == money) return mid + 1;
//		}
//		else return mid;
//	}
//
//	return -1;
//}
//
//int solution(vector<int> budgets, int M) {
//	int answer = 0;
//	int sum = 0, size = budgets.size();
//	bd = budgets;
//
//	sort(bd.begin(), bd.end());
//
//	for (int i = 0; i < size; i++) {
//		sum += bd[i];
//	}
//
//	if (sum <= M) 
//		return bd[size-1];
//
//	int money = M / size;
//	int mid_idx = binary_search(size - 1, 0, money);
//
//	for (int i = 0; i <= mid_idx; i++)
//		M -= bd[i];
//
//	size -= mid_idx + 1;
//
//	return M / size;
//}

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int sum = 0, size = budgets.size();
	
	sort(budgets.begin(), budgets.end());
	
	for (int i = 0; i < size; i++) {
		sum += budgets[i];
	}
	
	if (sum <= M) 
		return budgets[size-1];

	int high = budgets[size - 1];
	int low = 0;

	while (low + 1 < high) {
		int mid = (high + low) / 2;
		sum = 0;

		int i;
		for (i = 0; i < size; i++) {
			if (budgets[i] <= mid)
				sum += budgets[i];
			else break;
		}

		sum += ((size - i) * mid);

		if (sum <= M) low = mid;
		else high = mid;
	}

	return low;
}