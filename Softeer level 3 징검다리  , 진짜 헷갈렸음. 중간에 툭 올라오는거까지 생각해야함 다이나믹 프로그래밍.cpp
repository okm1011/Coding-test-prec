#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int>arr(n,0);
	vector<int>dp(n,1);
	int res;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (arr[i] > arr[j] && dp[j] >= dp[i]) {
				//cout << "enter";
				dp[i] = dp[i] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		res = max(res, dp[i]);
	}
	cout << res;

	return 0;
}