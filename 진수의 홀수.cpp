#include <iostream>
#include <math.h>

using namespace std;

long long int f[1000001];

int main()
{
	for (int i = 1; i <= 1000000; i++) { // 최대 입력 값까지 미리 소수를 계산
		int len = sqrt(i); 
		for (int j = 1; j <= len; j++) { 모든 수를 다 볼 필요가 없다
			if (i%j == 0) { // 일단 j로 나눠 떨어지는지 확인하고
				if (j % 2 == 1) { // 만약 홀수라면 더하고(ex 1)
					f[i] = f[i] + j;
					if (i / j != j && i / j % 2 == 1) { // j로 i를 나눈 수 또한 홀수라면 더해준다
						f[i] = f[i] + i / j;
					}
				}
				else { // 여기는 2X3 같은 경우를 처리한다
					if (i / j % 2 == 1) {
						f[i] = f[i] + i / j;
					}
				}
			}
		}
		f[i] = f[i] + f[i - 1];
	}
	int n;
	int l, r;
	scanf("%d",&n); // CIN을 쓰면 속도가 넘어간다
	for (int k = 1; k <= n; k++) {
		scanf("%d %d",&l,&r);
        printf("#%d %lld\n",k,f[r]-f[l-1]);
	}
    return 0;
}
