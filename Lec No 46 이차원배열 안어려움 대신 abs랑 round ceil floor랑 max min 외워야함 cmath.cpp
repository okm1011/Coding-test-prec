#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {

	freopen("input.txt", "rt", stdin);
	vector<vector<int>>arr(9, vector<int>(9, 0));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			
		}
	}
	
	for (int i = 0; i < 9; i++) {
		int sum = 0;
		float div = 9;
		for (int j = 0; j < 9; j++) {
			sum = sum + arr[i][j];

		}
		// float로 값이 나오려면 int/float여야함.
		int aus = round(sum / div);
		cout << aus << " ";
		int min = 2147000;
		int min_i = 0, min_j = 0;

		for (int j = 0; j < 9; j++) {
			if (min > abs(aus - arr[i][j])) {
				min = abs(aus - arr[i][j]);
				min_i = i;
				min_j = j;
			}
			else if (min == abs(aus - arr[i][j])) {
				if (arr[min_i][min_j] < arr[i][j]) {
					min = abs(aus - arr[i][j]);
					min_i = i;
					min_j = j;
				}
			}
			
		}
		cout << arr[min_i][min_j] << "\n";
	}

	return 0;
}