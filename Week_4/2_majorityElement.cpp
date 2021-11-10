#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right);

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

int get_majority_element(vector<int> &a, int left, int right) {
	if (left == right)
		return -1;
	if (left + 1 == right)
		return a[left];

	int lCnt = 0, rCnt = 0;
	int l_Elmnt = get_majority_element(a, left, ((left + right - 1) >> 1) + 1);
	int r_Elmnt = get_majority_element(a, ((left + right - 1) >> 1) + 1, right);

	for (int i = left; i < right; i++)
		if (a[i] == l_Elmnt)
			lCnt++;
	if (lCnt > ((right - left) >> 1))
		return l_Elmnt;
	for (int i = left; i < right; i++)
		if (a[i] == r_Elmnt)
			rCnt++;
	if (rCnt > ((right - left) >> 1))
		return r_Elmnt;
	return -1;
}