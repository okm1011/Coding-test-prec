#include <iostream>
#include <memory.h>
using namespace std;


int solve(int*);
int arr[101];



int main() {
	int en_test_case;
	int test_case;
	int temp = 0;
	int res = 0;
	freopen("input.txt", "rt", stdin);
	cin >> en_test_case;
	

	

	for (int t = 0; t < en_test_case; t++) {
		cin >> test_case;
		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < 1000; i++) {
			cin >> temp;
			arr[temp]++;
			
			
		}

		res=solve(arr);


		cout <<"#"<<test_case<<" "<<res<<"\n";


	}


	return 0;
}

int solve(int* ptr) {

	int max = 0;


	for (int i = 1; i < 100; i++) {
		
		if (arr[i] > arr[max]) {
			max = i;

		}
		else if (arr[i] == arr[max]) {
			max = i;
			
		}
		else {
			;
		}


	}
	return max;

}