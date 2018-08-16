#include <iostream>
#include <queue>

using namespace std;


int main()
{
	int x = 0; // 가로 크기
	int y = 0; // 세로 크기
	int input = 0; // 토마토 입력
	int z = 0; // 토마토가 모두 익은 상태 확인
	queue<pair<pair<int, int>, int>> q; // 큐 좌표와 차수
	
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };

	cin >> x >> y;

	int **t = new int*[y]; 
	for (int i = 0; i < y; i++) {
		t[i] = new int[x];
	}

	int **v = new int*[y];
	for (int i = 0; i < y; i++) {
		v[i] = new int[x];
	}

	for (int i = 0; i < y; i++) { // 토마토를 한개 씩 입력 받으면 익은토마토(1)이라면 q에 초기값으로 삽입 그리고 0이 없는 경우가 있는지 확인
		for (int j = 0; j < x; j++) {
			cin >> input;
			t[i][j] = input;
			if (input == 1) {
				q.push({{ i,j }, 0});
			}
			if (input == 0) {
				z = 1;
			}
		}
	}
	if (z == 0) { // 모두 익은 상태라면 0을 출력하고 리턴
		cout << 0;
		return 0;
	}
	for (int i = 0; i < y; i++) { // 무한 루프를 방지하기 위해 방문 여부 확인용
		for (int j = 0; j < x; j++) {
			v[i][j] = 0;
		}
	}

	int h; // 차수
	while (q.empty() == false) { 
			int a = 0;
			int b = 0;
			a = q.front().first.first;
			b = q.front().first.second;
			h = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int a2 = dy[k] + a;
				int b2 = dx[k] + b;

				if (a2 >= 0 && a2 < y && b2 >= 0 && b2 < x) {
					if ((t[a2][b2] == 0) && (v[a2][b2] == 0)) {
						t[a2][b2] = 1;
						v[a2][b2] = 1;
						q.push({ { a2, b2 }, h+1 });
					};
				}
			}
			
	}
	for (int i = 0; i < y; i++) { //익지 않는 경우를 확인
		for (int j = 0; j < x; j++) {
			if(t[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << h << '\n'; // 익지 않은 경우나 모두 익어 있던 상태가 아니라면 차수를 출력
	
    return 0;
}
