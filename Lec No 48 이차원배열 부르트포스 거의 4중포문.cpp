#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {

	freopen("input.txt", "rt",stdin);
	int row, column;
	cin >> row >> column;
	vector<vector<int>>arr(row, vector<int>(column, 0));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> arr[i][j];
			
		}
		
	}
	int res_row, res_column;
	cin >> res_row >> res_column;
	//여기서 brute force인데 흠....
	int max = -2147000;
	int sum = 0;
	int pos_row = 0;
	int pos_column = 0;
	while (pos_row<row-res_row) {
		sum = 0;
		for (int i = pos_row; i < pos_row + res_row; i++) {

			for (int j = pos_column; j < pos_column + res_column; j++) {
				sum = sum + arr[i][j];
				//cout << " i " << i << " j " << j << "\n";
			}
		}
		if (sum > max) {
			max = sum;
		}
		pos_column++;
		if (pos_column > column - res_column) {
			pos_column = 0;
			pos_row++;
		}
		
	}
	cout << max; 
	return 0;
}