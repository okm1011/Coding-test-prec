#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<pair<int, int>>dp(n+1,make_pair(0,0));
	cin >> dp[0].first >> dp[0].second;
	int ab = 0, ba = 0;
	cin >> ab >> ba;
	int res = 0;
	//cout << "first " << dp[0].first << "\n";
	//cout << "second " << dp[0].second << "\n";

	for (int i = 1; i < n; i++) {
		int a = 0, b = 0;

		cin >> a >> b;
	
		dp[i].first = min(dp[i - 1].first + a, dp[i - 1].second + ba + a);
		//cout << "first " << dp[i].first << "\n";
		
		dp[i].second = min(dp[i - 1].second + b, dp[i - 1].first + ab + b);
		//cout << "second " << dp[i].second << "\n";

		res = min(dp[i].first, dp[i].second);

		if (i != n - 1) { cin >> ab >> ba; }

		

	}
	cout << res;

	return 0;
}