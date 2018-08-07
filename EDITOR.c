#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	string st; // 처음 문자열을 받아오기 위한 용도
	list<char> s; // 문자열을 list로 저장하여 지우는 것과 접근을 편하게 한다
	list<pair<char, char>> c; // 명령어와 입력 값을 짝지어 P 명령어를 해결한다
	int cnt, size; // SIZE는 ST를 S에 넣을 때 반복문에 사용 CNT는 명령어의 개수
	cin >> st; // 문자열 입력 받음
	cin >> cnt; // 명령어 개수 입력 받음

	for (int i = 0; i < cnt; i++) {
		char x;
		char y;
		cin >> x;
		if (x == 'P') { // 삽입 명령어일때 SECOND에 입력 값 넣기
			cin >> y;
		}
		else {
			y = 'a'; // 아닐 시 무의미한 값
		}
		c.push_back({ x,y }); // 명령어 저장
	}
	

	size = st.size();
	
	for (int i = 0; i < size; i++) {
		s.push_back(st[i]);
	} // 문자열에 있는 것을 LIST로 이동

	auto it = c.begin(); // 명령어의 처음을 가르킨다
	auto it2 = s.end(); // 커서를 끝에 위치시킨다
	
	for (int i = 0; i < cnt; i++) {
		if (it->first == 'L') {
			if (it2 == s.begin()) { // 커서가 가장 앞에 있을때는 아무것도 하지 않는다
				//do nothing
			}
			else {
				it2--;
			}
			it++;
		}
		else if (it->first == 'D') {
			if (it2 == s.end()) {
				//do nothing // 커서가 가장 끝에 있을때는 아무것도 하지 않는다
			}
			else {
			it2++;
			}
			it++;
		}
		else if (it->first == 'B') {
			if (it2 == s.begin()) { // 커서가 가장 앞에 있을때는 아무것도 지우지 않는다.
				//do nothing
			}

			else {  
				auto temp = it2; // TEMP에 현재 커서를 저장해 놓고
			it2--; // 커서 좌측으로 이동하여
			s.erase(it2); // 그 값을 지운다
			it2 = temp;
			}
			it++;
		}
		else if (it->first == 'P') {
			s.insert(it2, it->second); // 커서 좌측에 삽입한다
			it++;
		}

	}
	auto itor = s.begin();
	while (itor != s.end()) {
		printf("%c", *itor);
		itor++; 
	} // 출력한다
}

