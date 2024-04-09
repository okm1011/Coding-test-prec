#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int n = 0;
int max_value = -1000;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};



void dfs(vector<vector<int>> map, int cnt) {
	if (cnt == 5) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (max_value < map[i][j]) {
					max_value = map[i][j];
				}
			}
		}
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> temp = map;
		switch (i) {
			case 0:
				// ��
				// �ϴ� �� ����°� �����ΰ�?
				// �̰� ���ܳ��� ���ľߴ� ���ĳ��� ������ ����� �ߺ����� ����������.
				// ���� ���� �κ�.
				for (int j = 1; j <= n; j++) {
					stack<int> t_s;
					for (int k = 1 ; k <= n; k++) {
						if (temp[j][k] != 0) {
							t_s.push(temp[j][k]);
						}
						temp[j][k] = 0;
					}
					int n_cnt = 0;
					while (!t_s.empty()) {
						temp[j][n - n_cnt] = t_s.top();
						t_s.pop();
						n_cnt++;
					}
				}
				//��ġ��
				for (int j = 1; j <= n; j++) {
					for (int k = n-1; k > 0; k--) {
						if (temp[j][k] != 0) {
							if (temp[j][k + 1] == temp[j][k]) {

									temp[j][k + 1] = 2 * temp[j][k];
									temp[j][k] = 0;
								

							}

						}

					}
				}
				//�ٽ� ����
				for (int j = 1; j <= n; j++) {
					stack<int> t_s;
					for (int k = 1; k <= n; k++) {
						if (temp[j][k] != 0) {
							t_s.push(temp[j][k]);
						}
						temp[j][k] = 0;
					}
					int n_cnt = 0;
					while (!t_s.empty()) {
						temp[j][n - n_cnt] = t_s.top();
						t_s.pop();
						n_cnt++;
					}
				}
				//��º�
				
				cout << " turn : " << cnt + 1 << " Right " << "\n";
				for (int j = 0; j <= n + 1; j++) {
					for (int k = 0; k <= n + 1; k++) {
						cout << temp[j][k] << " ";
					}cout << "\n";
				}
				dfs(temp, cnt + 1);

				break;
			case 1:
				// ��
				// ����� ���⼭�� �·� ����ϱ� ť����.
				for (int j = 1; j <= n; j++) {
					queue<int> t_q;
					for (int k = 1; k <= n; k++) {
						if (temp[j][k] != 0) {
							t_q.push(temp[j][k]);
						}
						temp[j][k] = 0;
					}
					int n_cnt = 0;
					while (!t_q.empty()) {
						temp[j][1 + n_cnt] = t_q.front();
						t_q.pop();
						n_cnt++;
					}
				}
				//��ġ��
				for (int j = 1; j <= n; j++) {
					for (int k = 2; k <= n; k++) {
						if (temp[j][k] != 0) {
							if (temp[j][k - 1] == temp[j][k]) {

									temp[j][k - 1] = 2 * temp[j][k];
									temp[j][k] = 0;
								

							}

						}

					}
				}
				//�ٽ� ����
				for (int j = 1; j <= n; j++) {
					queue<int> t_q;
					for (int k = 1; k <= n; k++) {
						if (temp[j][k] != 0) {
							t_q.push(temp[j][k]);
						}
						temp[j][k] = 0;
					}
					int n_cnt = 0;
					while (!t_q.empty()) {
						temp[j][1 + n_cnt] = t_q.front();
						t_q.pop();
						n_cnt++;
					}
				}
				cout << " turn : " << cnt + 1 << " Left " << "\n";
				for (int j = 0; j <= n + 1; j++) {
					for (int k = 0; k <= n + 1; k++) {
						cout << temp[j][k] << " ";
					}cout << "\n";
				}
				dfs(temp, cnt + 1);
				break;
			case 2:
				// ��
				for (int j = 1; j <= n; j++) {
					stack<int> t_s;
					for (int k = 1; k <= n; k++) {
						if (temp[k][j] != 0) {
							t_s.push(temp[k][j]);
						}
						temp[k][j] = 0;
					}
					int n_cnt = 0;
					while (!t_s.empty()) {
						temp[n - n_cnt][j] = t_s.top();
						t_s.pop();
						n_cnt++;
					}
				}
				//��ġ��
				for (int j = n-1; j > 0; j--) {
					for (int k = 1; k <= n; k++) {
						if (temp[j][k] != 0) {
							if (temp[j+1][k] == temp[j][k]) {

									temp[j + 1][k] = 2 * temp[j][k];
									temp[j][k] = 0;
								

							}

						}

					}
				}
				//�ٽ� ����
				for (int j = 1; j <= n; j++) {
					stack<int> t_s;
					for (int k = 1; k <= n; k++) {
						if (temp[k][j] != 0) {
							t_s.push(temp[k][j]);
						}
						temp[k][j] = 0;
					}
					int n_cnt = 0;
					while (!t_s.empty()) {
						temp[n - n_cnt][j] = t_s.top();
						t_s.pop();
						n_cnt++;
					}
				}

				//��º�
				cout << " turn : " << cnt + 1 << "Down" << "\n";
				for (int j = 0; j <= n + 1; j++) {
					for (int k = 0; k <= n + 1; k++) {
						cout << temp[j][k] << " ";
					}cout << "\n";
				}
				dfs(temp, cnt + 1);
				break;
			case 3:
				// ��
				for (int j = 1; j <= n; j++) {
					queue<int> t_q;
					for (int k = 1; k <= n; k++) {
						if (temp[k][j] != 0) {
							t_q.push(temp[k][j]);
						}
						temp[k][j] = 0;
					}
					int n_cnt = 0;
					while (!t_q.empty()) {
						temp[1 + n_cnt][j] = t_q.front();
						t_q.pop();
						n_cnt++;
					}
				}
				//��ġ��
				for (int j = 2; j <= n; j++) {
					for (int k = 1; k <= n; k++) {
						if (temp[j][k] != 0) {
							if (temp[j - 1][k] == temp[j][k]) {

									temp[j - 1][k] = 2 * temp[j][k];
									temp[j][k] = 0;
								

							}

						}

					}
				}
				//�ٽ� ����
				for (int j = 1; j <= n; j++) {
					queue<int> t_q;
					for (int k = 1; k <= n; k++) {
						if (temp[k][j] != 0) {
							t_q.push(temp[k][j]);
						}
						temp[k][j] = 0;
					}
					int n_cnt = 0;
					while (!t_q.empty()) {
						temp[1 + n_cnt][j] = t_q.front();
						t_q.pop();
						n_cnt++;
					}
				}
				//��º�
				cout << " turn : " << cnt + 1 << "Up" << "\n";
				for (int j = 0; j <= n + 1; j++) {
					for (int k = 0; k <= n + 1; k++) {
						cout << temp[j][k] << " ";
					}cout << "\n";
				}
				dfs(temp, cnt + 1);
				break;
			defalut:
				break;
		}
	}
}


int main() {

	bool f = freopen("input.txt", "rt", stdin);
	cin >> n; 
	vector<vector<int>> map(n + 2, vector<int>(n + 2, -1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	dfs(map, 0);
	cout << max_value;
	// map ������ -1�� �ѷ����� n������ ���簢����.
	/*  ��ü�� 1 ���� n������ ��ǥ
 -1-1-1-1-1
-1222-1
-1444-1
-1888-1
-1-1-1-1-1
	*/
	return 0;
}

// �⺻������ Max 5���̶�� ������ �������ְ� Max ���� ã�°Ŵϱ� DFS�� �´°� ���� 
// Ƚ���� ũ�������ϱ� �׶� �׶� �� ��ü �����ؼ� �����ִ°� ���� �� ����
