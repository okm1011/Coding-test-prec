#include <iostream>
using namespace std;
int seeting_array(int*, int);

int main() {
	
	freopen("input.txt", "rt", stdin);
	int t;
	scanf("%d", &t);
	int cnt = 0;
	int tmp = 0;
	int arr[10];
	int c = 0;
	int max = 0;
	int max_index = 0;
	int t_case = 1;
	

	
	for (int i = 0; i < t; i++) {
		
		scanf("%d", &tmp);
		scanf("%d", &cnt);
		c= seeting_array(arr, tmp); // c�� ��� ���� �� ����
		
		for (int m = 0; m < c-1; m++) {
			int temp = 0;
			max = arr[m];
			max_index = m;


			for (int n = m + 1; n < c; n++) {
				


				if (max < arr[n] || max == arr[n]) {
					max = arr[n];
					max_index = n;

				}

				
			}

			temp = arr[m];
			arr[m] = max;
			arr[max_index] = temp;
			cnt--;
			if (cnt == 0) break;


		}

		//���⼭ 3���� ��� cnt ������ ���¾� , cnt ¦���ξ�= �״�� �ִ밪 , cnt Ȧ���ξ� = c-1 ��°�� c-2��°�� �ٲ������.
		
		if(cnt == 0 || cnt%2==0) {
			cout << "#" << t_case << " ";
			for (int k = 0; k < c; k++) {
				cout << arr[k];
				
			}
			cout << "\n";
		}
		else {
			int temp2 = 0;
			temp2 = arr[c - 1];
			arr[c - 1] = arr[c - 2];
			arr[c - 2] = temp2;

			cout << "#" << t_case << " ";
			for (int k = 0; k < c; k++) {
				cout << arr[k];

			}
			cout << "\n";

		}
	


	}
	

	return 0;
}

int seeting_array(int* arr,int tmp) {

	int c=0;
	int div = 100000;

	while (div != 0) {

		if (tmp / div == 0) {
			div /= 10;
		}
		else {
			arr[c] = tmp / div;
			
			tmp = tmp % div;
			//cout << arr[c] << "\n";
			c++;
			div /= 10;
		}

		

	}
	return c;
}