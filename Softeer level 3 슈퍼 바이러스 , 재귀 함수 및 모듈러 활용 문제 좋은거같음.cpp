/*#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int k;
	cin >> k;
	int p;
	cin >> p;
	long long int n;
	cin >> n;

	long long  res;
	long long int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 && j == 0) {
				res = k * p;
				continue;
			}
			res = res * p; 

		}
	}

	cout << res%1000000007;

	return 0;
}
*/

#include <iostream>
#include <algorithm>

#define MOD 1000000007;

using namespace std;

long long sol(long long p, long long cnt); // 분할 정복함수 >> 시간복잡도 N에서 logN으로 줄여줌 , 재귀함수

int main() {
	freopen("input.txt", "rt", stdin);
	long long k, p, n;
	cin >> k >> p >> n;
	long long answer = (sol(p, n * 10)*k) % MOD;
	cout << answer;



	return 0;
}

long long sol(long long p, long long cnt) {
	

	if (cnt == 1) {
		return p;
	}
	long long res = sol(p, cnt / 2);
	res = res * res % MOD;
	if (cnt % 2 == 1) {
		res = (res*p) % MOD;
	}
	return res;



}