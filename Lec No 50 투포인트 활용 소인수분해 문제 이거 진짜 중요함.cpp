#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solve(int);
int main() {

	freopen("input.txt", "rt",stdin);
	int n;
	cin >> n;
	int res = 0;

	res = solve(n);
	cout << res;
	return 0;
}
int solve(int n) {
	vector<int>arr(n,0);
	arr[0] = 1;
	int p2 = 0, p3 = 0, p5 = 0;
	int val = 0;

	for (int i = 1; i < n; i++) {
		
		
		val = min({ arr[p2] * 2, arr[p3] * 3, arr[p5] * 5 });
		arr[i] = val;
		if (val == arr[p2] * 2) {
			p2++;
		}
		if (val == arr[p3] * 3) {
			p3++;
		}
		if (val == arr[p5]*5 ) {
			p5++;
		}
	
	}

	return arr[n-1];
	
}