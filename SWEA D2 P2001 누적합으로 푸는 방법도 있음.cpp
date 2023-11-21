#include <iostream>
#include <memory.h>
using namespace std;

int solve(int arr[][15],int n,int m);
int main_map[15][15];




int main() {

	freopen("input.txt", "rt", stdin);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int n = 0, m = 0;
		int res = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> main_map[i][j];
				//cout << main_map[i][j];
			}
		}
		res = solve(main_map,n,m);

		cout << "#" << t << " " << res<<"\n";
	}

	return 0;
}

int solve(int arr[][15],int n,int m) {
	int max = 0;
	int temp = 0;
	int point = 0;


		// 0,0 0,1 1,0 1 1 // 0 0 01 02 10 11 12 20 21 22
	for (int i = 0; i <= n-m; i++) {
		for (int j = 0; j <= n-m; j++) {
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					temp += arr[i + k][j + l];
					//cout << temp<<" ";

				}
		
			}
			if (temp > max) {
				max = temp;
				
				temp = 0;
			}
			else {
				temp = 0;
			}
		}
	}

	return max;






}