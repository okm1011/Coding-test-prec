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
	//�ϴ� stack �� �ְ� �̰� 1�̸� �ٷ� �ƿ� �̰� 1�̾ƴϸ� �� �־�
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