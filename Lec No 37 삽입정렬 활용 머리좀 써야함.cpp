#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

void solve(int* , int);
int is[100];
int os[100];

int main() {

	freopen("input.txt", "rt", stdin);
	memset(is, 0, sizeof(is));
	memset(os, 0, sizeof(os));
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> is[i];
		
	}

	solve(is, n);

	/*for (int i = 0; i < n; i++) {
		cout << os[i];

	}*/
	return 0;
}

void solve(int*ptr,int n) {
	
	int value = n;
	os[n-1] = value;
	value--;
	int cnt1 = 0;
	int cnt2 = 0;
	
	for (int i = n-2; i >= 0; i--) {
		cnt1 = 0;
		cnt2 = 1;
		for (int j = ptr[i]; j > 0; j--) {
			//cout << "i" << " " << i << "\n";
			//cout << "j" << " " << j << "\n";
			//cout <<"os[i + cnt]" <<os[i + cnt]<<"\n";
			//cout <<"os[i + j]" <<os[i + j] << "\n";

			os[i + cnt1] = os[i + cnt2];
			cnt1++;
			cnt2++;
		}
		os[i+ptr[i]] = value;
		value--;
		for (int i = 0; i < n; i++) {
			cout << os[i];
			

		}
		cout << " ";
	}



}