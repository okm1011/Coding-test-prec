#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>, int, int);

int main() {
	freopen("input.txt", "rt", stdin);
	int n, m;
	cin >> n >> m;
	
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve(arr, n, m);



	return 0;
}

int solve(vector<int>arr, int n, int m) {
	int sum = 0;
	int part_sum = 0;
	int cnt = 0;

	for (int i = n-1; i >= 0; i--) {
		sum = sum + arr[i];
		cnt = 1;
		part_sum = 0;
		for (int j = i - 1; j >= 0; j--) {
			//cout << "i " << i << " j " << j << " cnt " << cnt << " part_sum " << part_sum << " sum " << sum << "\n";
			if (sum < part_sum+arr[j] ) {
				cnt++;
				part_sum = 0;
				//cout <<"i "<<i<<" j "<<j<<" cnt "<<cnt<<" part_sum "<<part_sum<<" sum "<<sum<<"\n" ;
				
			}
			part_sum = part_sum + arr[j];
			
		}
		if (cnt < m) {
			cout << sum;
			break;
		}
		else {
			continue;
		}
	}





	return 0;
}