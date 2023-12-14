#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {

	freopen("input.txt", "rt",stdin);
	int row, column;
	cin >> row >> column;
	vector<vector<int>>arr(row+1, vector<int>(column+1, 0));

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			cin >> arr[i][j];
			
		}
		
	}
	int res_row, res_column;
	cin >> res_row >> res_column;
	
	//���⼭ DP ���������� 4��for�� -> 2��for������ ����' �Ʊٵ� �̰� �׵θ��� 0�̿����ϴϱ� +2�ؼ� �������� �迭
	vector<vector<int>>dp(row+1, vector<int>(column+1, 0));
	
	//DP ����� �κ�
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];
			
		}
	}
	//DP ������ �迭Ȱ��
	int sum = 0;
	int max = -2147000;
	for (int i = res_row; i <= row; i++) {
		for (int j = res_column; j <= column; j++) {
			sum = dp[i][j] - dp[i - res_row][j] - dp[i][j - res_column] + dp[i - res_row][j - res_column];
			if (sum > max)max = sum;
		}
	}
	cout << max;





	/* ���Ⱑ 4�� for���̰�
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
	*/
	return 0;
}