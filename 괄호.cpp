#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{	
	int tc;
	string input;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		stack<char> st; // 매 반복마다 스택이 초기화되어야 하기 때문에 내부에 선언
		bool fail = false; // 위와 같은 이유
		cin >> input;
		for (auto it : input) {
			if (it == '(') {
				st.push(it); // 괄호가 여는 괄호이면 스택에 푸쉬
			}
			else if (it == ')') { // 괄호가 닫는 괄호인데
				if (st.empty() == true) { // 스택이 비어 있다면 안된다
					fail = true; // 실패로 표시
					break;
				}
				else { // 스택이 비어있지 않다면 여는 괄호를 꺼낸다
					st.pop();
				}
			}
		}
		if (st.empty() == true && fail==false) { // 모든 조합이 완성되어 스택이 비어 있다면 yes 출력
			cout << "YES" << '\n';
		}
		else { // 아니면 no 
			cout << "NO" << '\n';
		}
	}
    return 0;
}
