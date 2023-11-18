#include<iostream>
#include<memory.h>
using namespace std;

int solve(int*);
int box[100];
int flag1 = 0; // 평탄화 완료 flag.
int flag2 = 0;


int main() {
	
	freopen("input.txt", "rt", stdin);
	int test_case = 10;
	int res = 0;
	for (int t = 1; t <= test_case; t++) {

		memset(box, 0, sizeof(box));
		int dump;
		cin >> dump;
		flag1 = 0;
		flag2 = 0;

		for (int i = 0; i < 100; i++) {
			cin >> box[i];
		}
		//최고점에서 -1 최저점 +1
		for (int j = 0; j <= dump; j++) {
			
			if (j >= dump) {
				flag2 = 1;
				
			}
			res = solve(box);

			if (flag1 == 1) {
				break;
			}
			
		}
		cout <<"#"<<t<<" "<<res<<"\n";
	}
	return 0;
}

int solve(int*ptr) {
	
	int temp = 0;

	for (int i = 0; i < 99; i++) {
		if (ptr[i] > ptr[i + 1]) {
			temp = ptr[i];
			ptr[i] = ptr[i + 1];
			ptr[i + 1] = temp;

		}
		
	}
	if (ptr[99] - ptr[0] < 2) {
		flag1 = 1;
		return ptr[99] - ptr[0];

	}
	if (flag2 == 1) {
		return ptr[99] - ptr[0];
	}
	ptr[0]++;
	ptr[99]--;

	


	return 0;

}