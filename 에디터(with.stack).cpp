#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string st; 
	stack<char> left; // 커서의 좌측
	stack<char> right; // 커서의 우측
	int cnt;
	cin >> st; 
	cin >> cnt; 

	for (auto it : st) { // 처음에는 커서가 가장 우측에 있다
		left.push(it);
	}
	for (int i = 0; i < cnt; i++) {
		char command;
		char input;
		cin >> command;
		if (command == 'L') { // 커서를 좌측으로 움직이는 명령어이면 
			if (left.empty() == false) { // 가장 왼쪽이 아니라면 왼쪽의 것을 오른쪽으로 하나 옮긴다
				right.push(left.top());
				left.pop();
			}
		}
		else if (command == 'D') { // 위와 같은 원리
			if (right.empty() == false) {
				left.push(right.top());
				right.pop();
			}
			
		}
		else if (command == 'B') { // 커서가 가장 좌측이 아니라면 왼쪽의 것을 하나 지운다
			if (left.empty() == false) {
				left.pop();
			}
		}
		else if (command == 'P') { // 커서의 좌측에 문자를 하나 삽입한다
			cin >> input;
			left.push(input);
		}
	}
	while (left.empty() == false) { // 왼쪽의 것을 우측에 다 넣는다
		right.push(left.top());
		left.pop();
	}
	while (right.empty() == false) { // 우측을 
		cout << right.top();
		right.pop();
	}

	return 0;
}

