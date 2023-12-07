#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int>, int, int);

int main() {
	freopen("input.txt", "rt", stdin);
	int n, k;
	cin >> n >> k;

	vector<int>arr(n + 1, 0);
	
	solve(arr, n, k);

	return 0;
}

void solve(vector<int>arr, int n, int k) {
	int pos = 1;
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		cnt = 0;
		while (1) {
			//cout << " pos " << pos << " cnt " << cnt << "\n";
			if (arr[pos] == 0) {
				cnt++;
				if (cnt == k) {
					break;
				}
			}
			
			pos++;

			if (pos > n) {
				pos = pos - n;
			}

		}arr[pos] = 1;

		
	}
	for (int j = 1; j <= n; j++) {
		if (arr[j] == 0) {
			cout << j;
		}
	}


}