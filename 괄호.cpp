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
		stack<char> st;
		bool fail = false;
		cin >> input;
		for (auto it : input) {
			if (it == '(') {
				st.push(it);
			}
			else if (it == ')') {
				if (st.empty() == true) {
					fail = true;
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (st.empty() == true && fail==false) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
    return 0;
}
