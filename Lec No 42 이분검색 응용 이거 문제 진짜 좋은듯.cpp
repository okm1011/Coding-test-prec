#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>, int , int, int);


int main() {
	freopen("input.txt", "rt", stdin);
	int n, c;
	cin >> n >> c;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		
	}
	sort(arr.begin(), arr.end());
	int res = 0, start = arr[0], end = arr[n-1] , value = 0 , mid = 0;
	

	while (start < end) {
		value = (start + end) / 2;
		//cout << value << " ";
		res = solve(arr, value,n,c);
		
		if (res == -1) {

			end = value - 1;
			
		}
		else {
			
			start = value + 1;
		}
		
	}
	cout << res ;
	return 0;
}

int solve(vector<int>arr, int value,int n,int c) {
	int res = 0;
	int cnt = 1;
	int point = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - point >= value) {
			point = arr[i];
			cnt++;
			//cout << cnt << " "; 
		}
	}
	if (cnt >= c) {
		return value;
	}
	else {
		return -1;
	}
}