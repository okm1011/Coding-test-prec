#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;

	vector<vector<int>>arr(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			arr[j][i] = temp;
		}
		
	}
	for (int i = n-1; i >= 0; i--) {
		int max;
		cin >> max;
		for (int j = n-1; j >= 0; j--) {
			if (arr[i][j] > max) {
				arr[i][j] = max;
			}
		}

	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = sum + arr[i][j];
		}
		
	}
	cout << sum;


	return 0;
}