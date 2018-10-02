#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int palindrome(string s,int start, int end) { // 모든 조합을 다 해본다
	if (start == end) return 1; // 만약 가운데까지 아무 문제 없이 도달했다면 1을 return
	else if (start + 1 == end) { // 짝수개라 가운데가 없다면 두 개를 비교해보고 return
		if (s[start] == s[end]) return 1;
		else return 0;
	}
	if (s[start] != s[end]) return 0; //다르다면 0을 return
	else return palindrome(s,start + 1, end - 1); 현재까지 같다면 더 안쪽으로 이동
}

int main()
{
	int T;
	string s;
	char *ptr;
	cin >> T;
	for (int t = 1; t <= T; t++) {
        cin >> s;
		int size = s.size();
		int cnt = 0;
		sort(s.begin(), s.end()); // 정렬하면 왜 되는지는?
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) { //0,0 0,1 ..... n-1,n-1
				int f = palindrome(s,i, j);
				if (f == 1) {
					cnt++;
				}
			}
		}
		cout << "#" << t << " " << cnt << '\n';
	}
	return 0;
}

