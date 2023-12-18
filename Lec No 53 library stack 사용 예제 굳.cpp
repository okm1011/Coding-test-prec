#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;


int main() {
	freopen("input.txt", "rt", stdin);
	char a[50];
	stack<char> s;
	scanf("%s", &a);
	int flag = 1;
	for (int i = 0; a[i] != '\0';i++) {
		if (a[i] == '(') {
			s.push(a[i]);
		}
		else {
			if (s.empty()) {
				cout << "NO";
				flag = 0;
				break;
			}
			else {
				s.pop();
			}
		}
	}
	if (s.empty() && flag ==1) {
		
		cout << "YES";
	}
	else if(!s.empty() && flag == 1){
		cout << "NO";
	}
	return 0;
}
