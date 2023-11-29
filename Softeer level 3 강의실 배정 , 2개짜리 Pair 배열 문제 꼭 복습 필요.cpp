#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000000000 

vector<pair <int,int>>arr; // pair 라는 배열이 있음 2개 쓸수있는거 한칸에.
//pair.first// pair.second로 호출 가능 걍 배열(배열) 느낌인거임.

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	int s = 0, f = 0;

	for (int i = 0; i < n; i++) {
		cin >> s >> f;

		arr.push_back(make_pair(f,s)); // pair[배열]을 넣는거니까 make pair해준거임 그리고 끝나는시간 먼저 넣어줌

		
	}
	sort(arr.begin(), arr.end()); // 배열중 앞에꺼를 가지고 Sort함
	int point = arr[0].first; // 제일 처음 끝나는 종료시간 포인트
	int cnt = 1;  // 수업 1개 start

	for (int i = 1; i < n; i++) {
		
		if (point <= arr[i].second) {
			point = arr[i].first;
			cnt++;
		}


	}
	cout << cnt;
	return 0;
}