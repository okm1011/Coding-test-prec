#include <iostream>
#include <memory.h>
using namespace std;

int put_cache(int*,int);
int arr[10];


int main() {
	freopen("input.txt", "rt", stdin);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {

		int size;
		cin >> size;
		int task;
		cin >> task;
		memset(arr, 0, sizeof(arr));
		

		for (int i = 0; i < task; i++) {
			put_cache(arr,size);
			for (int j = 0; j < size; j++) {
				cout << arr[j] << " ";
			}
			cout << "\n";
		}

		/*cout << "#" << t << " ";

		for (int i = 0; i < size; i++) {
			cout << arr[i];
		}
		cout << "\n";
		*/
	}



	

	return 0;
}

int put_cache(int* ptr,int size) {

	int task_num;
	cin >> task_num;
	// 1 비어있는거 2 꽉차있는데 안맞는거 3 꽉차있는데 맞는게 있는거.
	int i = 0, j = 0 , k = 0;
	int temp = 0;
	int hit_flag = 0;
	// 이게 Hit 부분
	for (i = 0; i < size; i++) {
		if (arr[i] == task_num) {
			hit_flag = 1;
			arr[i] = 0;
			temp = 0;
			for (j = i - 1; j >= 0; j--) {
				if (temp < arr[j]) {
					arr[j + 1] = arr[j];
				}
			}
			arr[j + 1] = task_num;

		}
	}
	if (hit_flag == 1) {
		return 0;
	}
	//이게 비어있을때 && No hit
	if (ptr[size - 1] == 0) {
		temp = 0;
		for (j = size - 2; j >= 0; j--) {
			if (temp < arr[j]) {
				arr[j + 1] = arr[j];
			}
		}
		arr[j + 1] = task_num;

	}
	// 꽉 찻는데 && No Hit
	else {
		ptr[size - 1] = 0;
		temp = 0;
		for (j = size - 2; j >= 0; j--) {
			if (temp < arr[j]) {
				arr[j + 1] = arr[j];
			}
		}
		arr[j + 1] = task_num;

	}
	return 0;
}