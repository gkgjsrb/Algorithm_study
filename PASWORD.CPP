#include <iostream>
#include <vector>
#include <deque> // 양쪽에서 삽입 삭제하기 위해
#include <algorithm> // SORT하기 위해
#include <functional> // UNIQUE 사용하기 위해

using namespace std;

int main(){
	int TC; // Test Case의 개수
	int N; // 숫자의 개수 4의 배수로 주어짐
	int K; // k번째로 큰 수를 구하기 위한 k
	cin >> TC; 
	for (int k = 1; k <= TC; k++) {
		cin >> N >> K;
		vector<vector<char>> res;
		deque<char> a;
		
		for (int i = 0; i < N; i++) {
			char tmp;
			cin >> tmp;
			a.push_back(tmp);
		}  // 일단 deque에 초기 값을 입력 받음
		
		for (int m = 0; m < (N / 4); m++) { // 총 몇번 회전하면 초기 값과 같아 지는지 n/4번 회전하면 같아짐 ex) 12면 3번 회전하면 초기값과 같아짐
			a.push_front(a.back()); // 가장 뒤에 있는걸 가장 앞에 추가함
			a.pop_back(); // 뒤에 있는걸 삭제
			for (int i = 0; i < N; i = i + (N / 4)) { // 각 변에 있는 16진수를 넣기위해 사용
				vector<char> tmp;
				for (int j = 0; j < (N / 4); j++) { // 각 변에 몇개가 있는지를 파악하여 넣음
					tmp.push_back(a[i + j]); 
				}
				res.push_back(tmp);
			}
		}
		// 여기 까지하면 모든 가능한 조합이 표시됨
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
		} // 각 조합의 계산 값을 받아오는 코드
		sort(sum.begin(), sum.end(), greater<int>()); // 내림 차순으로 정렬
		sum.erase(unique(sum.begin(), sum.end()),sum.end()); // 내림 차순으로 정렬한 것 중 겹치는 것을 제거
		cout << "#" << k << " " << sum.at(K-1) << '\n'; // k번째 수를 
	}

    return 0;
}
