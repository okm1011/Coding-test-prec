#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int>, vector<int>, int , int);


int main() {

	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int>a(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		
	}
	int m;
	cin >> m;
	vector<int>b(m+1, 0);
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		
	}



	solve(a, b, n,m);

	

	return 0;
}

void solve(vector<int>a, vector<int>b, int n, int m) {
	vector<int>res;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ptr1 = 1;
	int ptr2 = 1;
	


	for (int i = 1; i <= n; i++) {
		if (ptr1 > n || ptr2 > m) {
			break;
		}
		else if (a[ptr1] > b[ptr2]) {
			ptr2++;
		}
		else if (a[ptr1] < b[ptr2]) {
			ptr1++;
		}
		else {
			res.push_back(a[ptr1]);
			ptr1++;
			ptr2++;
			
		}
		
	}
	int end = res.size();

	for (int i = 0; i < end; i++) {
		cout << res[i] << " ";
	}
	

}