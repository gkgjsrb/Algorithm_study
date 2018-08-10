#include <iostream>
#include <list>
#include <queue>

using namespace std;

list<int> k[101];
int v[101];

int main()
{
	int com_n;
	int con_n;
	cin >> com_n >> con_n; // 컴퓨터의 개수와 연결의 개수를 입력 받는다

	for (int i = 0; i < con_n; i++) {
		int x;
		int y;
		cin >> x >> y;
		k[x].push_back(y); 
		k[y].push_back(x); // 양쪽 방향을 다 넣어줘야 한다.
	}

	int ret = 0;
	queue<int> q;
	q.push(1);
	while (q.empty() == false) {
		int x = q.front();
		q.pop();
		if (v[x] == 0) { // 방문하지 않은 노드라면 카운트를 증가시켜 준다
			ret++;
			v[x] = 1;
		}

		for (int i : k[x]) { // 현재 front인 node와 연결된 node들 중 방문하지 않은 노드를 모두 queue에 삽입한다
			if (v[i] == 0) { 
				q.push(i);
			}
		}
	}
	cout << (ret-1); // 처음 1을 포함하기 때문에 답에서 1을 빼준다
	return 0;
}
