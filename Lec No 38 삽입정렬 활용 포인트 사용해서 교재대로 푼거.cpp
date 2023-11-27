#include <iostream>
#include <memory.h>
#include<vector>
#include <algorithm>

using namespace std;

void solve(vector<int>, vector<int>,vector<int>,int,int);

int main() {
	
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int>arr1(n+1,0);

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
		//cout << arr1[i];
	}

	int m;
	cin >> m;
	vector<int>arr2(m+3,0);

	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
		//cout << arr2[i];
	}

	vector<int>arr3(n + m+1,0);
	
	solve(arr1,arr2,arr3, n, m);



	return 0;
}

void solve(vector<int> arr1,vector<int> arr2,vector<int> arr3, int n, int m) {
	int point1 = 0, point2 = 0;



	for (int i = 0; i < n + m; i++) {
		if (arr1[point1] == 0 ) {
			
				
				arr3[i] = arr2[point2];
				//cout << arr3[i];
				//cout << "point1 " << point1;
				point2++;
			
		}
		else if (arr2[point2] == 0) {
			
				arr3[i] = arr1[point1];
				point1++;
			
		}
		else if (arr1[point1] > arr2[point2]) {
			arr3[i] = arr2[point2];
			point2++;
			//cout << "point2 "<<point2<<"\n";
		}
		else {
			arr3[i] = arr1[point1];
			point1++;
			//cout << "point1 " << point1<< "\n";
		}

		
	}
	for (int i = 0; i < n + m; i++) {
		cout << arr3[i];
		//cout << arr2[i];
	}
	
}