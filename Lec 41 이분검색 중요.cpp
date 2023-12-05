#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>, int,int);
void insert_sort(vector<int>&, int);


int main() {

	freopen("input.txt", "rt", stdin);
	int n , tg;
	cin >> n >> tg;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	insert_sort(arr, n);
	solve(arr, n,tg);
	return 0;
}

int solve(vector<int>arr, int n,int tg) {

	int res = 0;
	int mid = 0;
	//12 23 32 57 65 81 87 99
	int start = 0;
	int end = n-1;
	
	while (true) {
		mid = (start + end) / 2;

		if (arr[mid] > tg) {
			end = mid;
		}
		else if (arr[mid] < tg) {
			start = mid;
		}
		else {
			res = mid;
			break;
		}

	}
	cout << res; 

	return 0;
}

void insert_sort(vector<int>&arr, int n) {
	int temp;
	int i = 0, j = 0;
	for (i = 1; i < n; i++) {
		temp = arr[i];
		for ( j = i-1; j >= 0; j--) {
			if (arr[j] > temp) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = temp;
	}


}