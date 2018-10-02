#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> set;

void swap(char *s, int i, int j) {
	char tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

void func(char *s, int depth, int n, int k) {
	if (depth == k) {
		set.push_back(s);
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(s, i, depth);
		func(s, depth + 1, n, k);
		swap(s, i, depth);
	}
}


int main()
{
	int T;
	string s;
	char *ptr;
	scanf_s("%d", &T);

	for (int t = 1; t <= T; t++) {
		cin >> s;
		vector<char> w(s.begin(), s.end());
		w.push_back('\0');
		ptr = &w[0];
		func(ptr, 0, s.size(), s.size());

		vector<int> sum_set;
		int sum;
		for (auto it : set) {
			vector<string> tail;
			vector<string> check;
			for (int i = 0; i < it.size(); i++) {
				string tmp(it.begin() + i, it.end());
				tail.push_back(tmp);
			}
			for (auto it2 : tail) {
				for (int i = 0; i < it2.size(); i++) {
					string tmp(it2.begin(), it2.end() - i);
					check.push_back(tmp);
				}
			}

			sum = 0;
			for (auto it2 : check) {
				if (it2.size() == 1) {
					sum++;
				}
				else {
					int size = it2.size();
					int check = 0;
					for (int i = 0; i < size / 2; i++) {
						if (it2[i] != it2[size - 1 - i]) {
							check = 1;
						}
					}
					if (check == 0) {
						sum++;
					}
				}
			}
			sum_set.push_back(sum);
		}
		sort(sum_set.begin(), sum_set.end());
		printf("#%d %d\n", t, sum_set.back());
	}

	return 0;
}

