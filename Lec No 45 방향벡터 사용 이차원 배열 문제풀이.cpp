#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<vector<int>>, int, int ,int,int);

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<vector<int>>arr(n + 2, vector<int>(n + 2, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];

		}

	}
	int res = 0;
	int temp;
	// f 0 t 1
	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j <= n; j++) {
			temp = arr[i][j];
			if (compare(arr, n, temp, i, j) == true) {
				//cout << " i " << i << " j " << j << "\n";
				res++;
			}
		}

	}
	cout << res;

	return 0;
}

bool compare(vector<vector<int>>arr, int n, int temp,int i,int j){

	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 }; // 이거 방향벡터 중요

	for (int k = 0; k < 4; k++) {
		if (arr[i + dx[k]][j + dy[k]] >= temp) {
			return false;
		}
	}
	 //i , j 상 (i-1,j) 하(i+1,j) 좌(i,j-1) 우 (i,j+1)  
	
	return true;
}