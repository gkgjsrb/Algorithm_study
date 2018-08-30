#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int result=0; 
	char before; // 이전에 들어온 입력이 무엇인지 기억한다
	char current=0; // tmp값
	string input;
	cin >> input;
	stack<char> st;
	for (auto it : input) {
		before = current; // 이전 값을 저장
		current = it;
		if (it == '(') { // 여는 괄호라면 push
			st.push(it); 
		}
		else if (it == ')') {  // 닫는 괄호이면 
			st.pop(); // 일단 pop
			if (before == '(') { // 그리고 이전 값이 여는 괄호이면 레이저기 때문에
				result = result + st.size(); // 한번 잘린것으로 가정하고 전체 size만큼 더한다
			}
			else { // 이전 값이 닫는 괄호이면 마지막 조각을 
				result++;
			}
		}
	}
	cout << result;

    return 0;
}

