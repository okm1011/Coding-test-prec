#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int>, int,int);

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int>arr(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		
	}
	int k;
	cin >> k;

	solve(arr,n,k);

	return 0;
}

void solve(vector<int>arr,int n, int k) {
	int pos = 1;
	int flag = 0;
	while (1) {
		//cout <<" pos " <<pos<<" k "<<k;
		if (arr[pos] != 0) {
			
			arr[pos]--;
			k--;
			if (k < 1) {
				break;
			}
		}
		
		pos++;
		if (pos > n) {
			pos = pos - (n);
		}

	}
	for (int i = 1; i <= n; i++) {
		//cout << arr[i] << " ";
		if (arr[i] != 0) {
			flag = 1;
		}

	}
	if (flag == 0) {
		cout << -1;
	}
	else {
		cout << pos;
	}

}