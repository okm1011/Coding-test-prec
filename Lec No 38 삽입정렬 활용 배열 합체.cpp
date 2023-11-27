#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	freopen("input.txt", "rt", stdin);

	int n;
	cin >> n;
	vector<int> arr(200,0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = n;
	int m;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		int pos = n+m-1;
		int temp;
		cin >> temp;
		
		while (pos>-1) {

			//cout << arr[pos];
			if (temp > arr[pos]&&arr[pos]!=0) {
				break;
				
			}
			
			pos--;
			
		}
		
		for (int j = cnt-1; j > pos; j--) {
			arr[j+1] = arr[j];
		}
		arr[pos + 1] = temp;
		cnt++;
	}

	for (int i = 0; i < n + m; i++) {
		cout << arr[i];
	}

	


	return 0;
}