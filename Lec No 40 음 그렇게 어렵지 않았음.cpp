#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(int);


int main() {

	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	int res = 0;

	res = solve(n);
	cout << res;

	return 0;
}

int solve(int n) {
	float a = 2;

	int b = ceil(n/a);
	vector<int>arr(b+1, 0);
	int cnt = 0;
	for (int i = 1; i <= b; i++) {
		arr[i] = i;
		
	}
	int sum = 0;
	for (int i = b; i > 2; i--) {
		sum = arr[i];
		for (int j = i-1; j > 0; j--) {
			sum = sum + arr[j];
			//cout << "i " << i << " j " << j;
			if (sum == n) {
				for (int k = j; k <= i; k++) {
					if (k == i) {
						cout<<" " << arr[k] << " =";
					}
					else if (k == j) {
						cout  << arr[k] << " +";
					}
					else {
						cout << " " <<arr[k] << " +";
					}
				}
				cout << " " << n << "\n";
				cnt++;
				break;
			}
		}
	}

	return cnt;
}