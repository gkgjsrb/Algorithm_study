#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int d[11][11];

int palindrome(string s,int start, int end) {
	if (start == end) return 1;
	else if (start + 1 == end) {
		if (s[start] == s[end]) return 1;
		else return 0;
	}
	if (d[start][end] > 0) return d[start][end];
	if (s[start] != s[end]) return d[start][end] = 0;
	else return d[start][end] = palindrome(s,start + 1, end - 1);
}

int main()
{
	int T;
	string s;
	char *ptr;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(d,0,sizeof(d));
        cin >> s;
		int size = s.size();
		int cnt = 0;
		sort(s.begin(), s.end());
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
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

