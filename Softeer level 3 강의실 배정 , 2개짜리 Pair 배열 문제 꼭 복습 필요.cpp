#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000000000 

vector<pair <int,int>>arr; // pair ��� �迭�� ���� 2�� �����ִ°� ��ĭ��.
//pair.first// pair.second�� ȣ�� ���� �� �迭(�迭) �����ΰ���.

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	int s = 0, f = 0;

	for (int i = 0; i < n; i++) {
		cin >> s >> f;

		arr.push_back(make_pair(f,s)); // pair[�迭]�� �ִ°Ŵϱ� make pair���ذ��� �׸��� �����½ð� ���� �־���

		
	}
	sort(arr.begin(), arr.end()); // �迭�� �տ����� ������ Sort��
	int point = arr[0].first; // ���� ó�� ������ ����ð� ����Ʈ
	int cnt = 1;  // ���� 1�� start

	for (int i = 1; i < n; i++) {
		
		if (point <= arr[i].second) {
			point = arr[i].first;
			cnt++;
		}


	}
	cout << cnt;
	return 0;
}