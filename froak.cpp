#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int TC;
	cin >> TC;
	string s;
	
	for (int k = 0; k < TC; k++) {
		int ans = 0;
		int exist = 0;
		cin >> s;
		vector<stack<char>> v;
		int size = s.size();
		if (size % 5 != 0) { // 가장 먼저 크기가 5의 배수가 아니면 무조건 실패이기 때문에 -1을 출력한다
			printf("#%d -1\n", k+1);
		}
		else {
			for (int i = 0; i < size; i++) {
				exist = 0;
				if (s[i] == 'c') { // 입력이 c인 경우 현재까지 구성된 문자열을 돌아보며 k로 끝나는 문자열이 있으면 추가한다.
					for (int j = 0; j < v.size(); j++) {
						if (v[j].top() == 'k') {
							v[j].push('c');
							exist = 1;
							break;
						}
					}
					if (exist == 0) { // 만약 없다면 새로운 stack을 만들어 추가한다.
						stack<char> tmp;
						tmp.push('c');
						v.push_back(tmp);
					}
				}
				else if (s[i] == 'r') { // r의 경우에는 처음이 아니기 때문에 c로 시작하는 문자열이 있다면 추가하고 아니면 실패로 간주하고 break한다.
					for (int j = 0; j < v.size(); j++) {
						if (v[j].top() == 'c') {
							v[j].push('r');
							exist = 1;
							break;
						}
					}
					if (exist == 0) {
						ans = -1;
						break;
					}
				}
				else if (s[i] == 'o') {
					for (int j = 0; j < v.size(); j++) {
						if (v[j].top() == 'r') {
							v[j].push('o');
							exist = 1;
							break;
						}
					}
					if (exist == 0) {
						ans = -1;
						break;
					}
				}
				else if (s[i] == 'a') {
					for (int j = 0; j < v.size(); j++) {
						if (v[j].top() == 'o') {
							v[j].push('a');
							exist = 1;
							break;
						}
					}
					if (exist == 0) {
						ans = -1;
						break;
					}
				}
				else if (s[i] == 'k') {
					for (int j = 0; j < v.size(); j++) {
						if (v[j].top() == 'a') {
							v[j].push('k');
							exist = 1;
							break;
						}
					}
					if (exist == 0) {
						ans = -1;
						break;
					}
				}
			} // 여기까지만하면 ccccr 같은 경우도 성공으로 취급하기 때문에
            for(auto it : v){ // 여기서 모든 stack이 5의 배수인지를 확인한다.
            	if(it.size()%5!=0){
                	ans=-1;
                }
            }
			if (ans == -1) {
				printf("#%d -1\n", k+1);
			}
			else {
				printf("#%d %d\n", k+1, v.size());
			}
		}
	}
    return 0;
}
