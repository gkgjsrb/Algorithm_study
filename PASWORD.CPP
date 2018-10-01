#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int TC;
	int N;
	int K;
	cin >> TC;
	for (int k = 1; k <= TC; k++) {
		cin >> N >> K;
		vector<vector<char>> res;
		deque<char> a;
		
		for (int i = 0; i < N; i++) {
			char tmp;
			cin >> tmp;
			a.push_back(tmp);
		}
		
		for (int m = 0; m < (N / 4); m++) {
			a.push_front(a.back());
			a.pop_back();
			for (int i = 0; i < N; i = i + (N / 4)) {
				vector<char> tmp;
				for (int j = 0; j < (N / 4); j++) {
					tmp.push_back(a[i + j]);
				}
				res.push_back(tmp);
			}
		}
		vector<int> sum;
		for (auto it : res) {
			int tmp=0;
			for (int i = 0; i < it.size(); i++) {
				if (it[i] == '0') {
					
				}
				else if (it[i] == '1') {
					tmp = tmp + 1 * pow(16,it.size()-1-i);
				}
				else if (it[i] == '2') {
					tmp = tmp + 2 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == '3') {
					tmp = tmp + 3 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == '4') {
					tmp = tmp + 4 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == '5') {
					tmp = tmp + 5 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == '6') {
					tmp = tmp + 6 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == '7') {
					tmp = tmp + 7 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == '8') {
					tmp = tmp + 8 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == '9') {
					tmp = tmp + 9 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == 'A') {
					tmp = tmp + 10 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == 'B') {
					tmp = tmp + 11 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == 'C') {
					tmp = tmp + 12 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == 'D') {
					tmp = tmp + 13 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == 'E') {
					tmp = tmp + 14 * pow(16, it.size() - 1 - i);
				}
				else if (it[i] == 'F') {
					tmp = tmp + 15 * pow(16, it.size() - 1 - i);
				}
			}
			sum.push_back(tmp);	
		}
		sort(sum.begin(), sum.end(), greater<int>());
		sum.erase(unique(sum.begin(), sum.end()),sum.end());
		cout << "#" << k << " " << sum.at(K-1) << '\n';
	}

    return 0;
}
