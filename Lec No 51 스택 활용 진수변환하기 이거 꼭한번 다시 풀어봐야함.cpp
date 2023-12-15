#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>stack;
int top = -1;
void push(int);
int pop(void);


int main() {
	freopen("input.txt", "rt", stdin);
	int n, k;
	cin >> n >> k;
	char str[20] = { "0123456789ABCDEF" };
	while (n > 0) {
		push(n%k);
		n = n / k;
	}
	while (top != -1) {
		cout << str[pop()];
	}



	return 0;
}

int pop(void) {
	return stack[top--];
}
void push(int x) {
	top++;
	stack.push_back(x);
}