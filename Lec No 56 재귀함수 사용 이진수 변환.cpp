#include <iostream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// input 11 output should be 1011
int rec(int);

int main(int argc, char** argv) {
	freopen("input.txt","rt",stdin);
	int n;
	cin >> n;
	
	rec(n);
	return 0;
}

int rec(int n){
	int tmp;
	tmp = n%2;
	n = n/2;
	if(n != 0){
		rec(n);
	}
	cout << tmp;
}
