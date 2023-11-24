#include <iostream>
#include <memory.h>
using namespace std;

void insertion_sort(int*,int);
int arr[101];


int main() {

	freopen("input.txt", "rt", stdin);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {

		int n;
		cin >> n;
		memset(arr,0,sizeof(arr));

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		insertion_sort(arr,n);

		cout << "#" << t << " ";
		for (int i = 0; i < n; i++) {
			cout << arr[i]<<" ";
		}
		cout << "\n";
	}


	return 0;
}

// 삽입 정렬 포인트는 I의 하위는 모두 정렬이 되어있으니까 그걸 Break로 캔슬하는거임

void insertion_sort(int*ptr,int n) {

	int temp = 0;
	int i = 0, j = 0;
	for (i = 1; i < n; i++) {
		temp = ptr[i]; // 이게 i인거지
		for ( j = i - 1; j >= 0; j--) {
			
			if (ptr[j] > temp) {
				ptr[j + 1] = ptr[j];
			}
			else {
				break;
			}			
		}
		ptr[j + 1] = temp;// j 문이 끝나고 들어가는거지 그치
	}



	

}