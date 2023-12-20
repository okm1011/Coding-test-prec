#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int flag = 0;

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int>arr(n,0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		
	}
	stack<int>stack;
	vector<char>out;
	//일단 stack 에 넣고 이게 1이면 바로 아웃 이게 1이아니면 또 넣어
	int cnt = 1;
	int i = 0;
	stack.push(arr[i]);
	out.push_back('P');

	while (cnt<=n) {
		if (stack.empty()) {
			;
		}
		else {
			if (stack.top() == cnt) {
				stack.pop();
				cnt++;
				out.push_back('O');
				continue;
			}
		}

		
			
		i++;
		if (i >= n) {
			flag = 1;
			break;
		}
		stack.push(arr[i]);
		out.push_back('P');
		
	}
	if (flag) {
		cout << "impossible";
	}
	else {
		for (int i = 0; i < out.size(); i++) {
			cout << out[i];
		}
	}
	return 0;
}