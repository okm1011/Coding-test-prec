/*// n = 회원수 m=친분관계
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int>w(100001);
	vector<pair<int,int>>r(100001);
	
	
	
	int res = 0;
	

	

	for (int i = 1; i <= n; i++) {
		cin >> w[i]; // 1~n번까지의 wait 값입력.
		
	}
	for (int i = 1; i <= m; i++) {
		int temp1;
		cin >> temp1;
		int temp2;
		cin >> temp2;
		r[i] = make_pair(temp1, temp2);
	}
	for (int i = 1; i <= n; i++) {
		
		
		int arr[2] = { 0 };

		
		for (int j = 1; j <= m; j++) {
			
			if (i == r[j].first) {
				
				if (w[i] > w[r[j].second]) {
					if (arr[0] == 2) {
						;
					}
					else {
						arr[0] = 1;
					}
				}
				else {
					arr[0] = 2;
				}
			}
			else if (i == r[j].second) {
				
				if ((w[i] > w[r[j].first])) {
					if (arr[1] == 2) {
						;
					}
					else {
						arr[1] = 1;
					}
				}
				else {
					arr[1] = 2;
				}
			}
		}
		
		cout <<"i"<<i<<" "<<arr[0]<<arr[1] << "\n";
	
		if ((arr[0]==1&&arr[1]==0)|| (arr[0] == 0 && arr[1] == 1)|| (arr[0] == 1 && arr[1] == 1)|| (arr[0] == 0 && arr[1] == 0)) {
			
			res++; // 2번 -> 1번
		}

	}

	//cout << res;

	return 0;
}*/

//new solution

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<bool>best(n + 1, 1);
	vector<int>w(n + 1, 0);
	int a = 0, b = 0;
	int res = 0;

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (w[a] > w[b]) {
			best[b] = 0;
		}
		else if (w[a] < w[b]) {
			best[a] = 0;
		}
		else {
			best[a] = 0;
			best[b] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (best[i] == 1) {
			res++;
		}
	}
	cout << res;
	return 0;

}