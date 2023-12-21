#include<iostream>
using namespace std;

void recursion_f(int);


int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	recursion_f(n);
	return 0;
}

void recursion_f(int x) {
	
	if (x == 0) {
		return;
	}
	else {
		recursion_f(x - 1);
		cout << x << " ";
		
	}
}