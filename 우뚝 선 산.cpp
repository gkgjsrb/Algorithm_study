#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	int N;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		vector<int> map;
		cin >> N;
		int sum = 0;
		for (int n = 0; n < N; n++) {
			int tmp;
			cin >> tmp;
			map.push_back(tmp);
		}
		for (int i = 1; i < N - 1; i++) { // 끝 부분은 우뚝 선 산이 될 수 없기 때문에 배제한다
			int left = 0; 
			int right = 0;
			if (map[i - 1] < map[i] && map[i + 1] < map[i]) { //일단 변곡점을 찾는다
				for (int l = i-1; l >= 0; l--) { // 그리고 왼쪽에 몇개가 있는지 계산한다
					if (l == 0) {
						if (map[l] < map[i]) { 가장 끝까지 왔으면 더해준다
							left++;
						}
					}
					else {
						if (map[l] < map[i] && map[l-1]<map[l] && map[l+1]>map[l]) { 아직 내려가는 모양이 진행 중인 경우
							left++;
						}
						else if (map[l] < map[i] && map[l - 1]>map[l] && map[l + 1]>map[l]) { // 꺽인 경우
							left++;
							break;
						}
					}
				}
				for (int r = i + 1; r< N; r++) { // 오른쪽에 몇개가 있는지 계산하여 조합한다
					if (r == N-1) {
						if (map[r] < map[i]) { // 가장 우측까지 오면 더해 준다
							right++;
						}
					}
					else {
						if (map[r] < map[i] && map[r - 1]>map[r] && map[r + 1]<map[r]){ // 아직 내려가는 모양이 진행중인 경우
							right++;
						}
						else if (map[r] < map[i] && map[r - 1] > map[r] && map[r + 1] > map[r]) { // 꺽인 경우
							right++;
							break;
						}
					}
				}
			}
			sum = sum + (left * right);
		}
		cout << "#" << t << " " << sum << '\n';
	}
    return 0;
}
