#include <iostream>
#include <memory.h>
using namespace std;

void solve(int*);
int arr[1000000];

int main() {
	freopen("input.txt", "rt", stdin);
	int test_case;
	cin >> test_case; // 
	for (int t = 1; t <= test_case; t++) {
		int n;
		int k;
		
		cin >> n;
		cin >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < k; i++) {
			int start;
			cin >> start;
			int end;
			cin >> end;
			int sum = 0;
			float res = 0;
			float cnt = 0;

			for (int j = start - 1; j < end; j++) {
				sum = sum + arr[j];
				cnt+=1;
			}
			res = sum / cnt;
			cout << fixed; // �̰� ���ķ� precision���� ���� �Ҽ����ڸ� ���ڴٴ°���
			cout.precision(); // ���� n����� �Ҽ����ڸ�.
			cout << res << "\n";

		}

	}
	return 0;
}

void solve(int* ptr) {


}