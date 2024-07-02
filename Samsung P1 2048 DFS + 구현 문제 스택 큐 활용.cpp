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
				// 우
				// 일단 쭉 땡기는게 먼저인가?
				// 이거 떙겨놓고 합쳐야대 합쳐놓고 나머지 떙기면 중복으로 합쳐져버림.
				// 땡겨 놓는 부분.
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
				//합치기
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
				//다시 떙겨
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
				//출력부
				
				cout << " turn : " << cnt + 1 << " Right " << "\n";
				for (int j = 0; j <= n + 1; j++) {
					for (int k = 0; k <= n + 1; k++) {
						cout << temp[j][k] << " ";
					}cout << "\n";
				}
				dfs(temp, cnt + 1);

				break;
			case 1:
				// 좌
				// 땡기기 여기서는 좌로 떙기니까 큐썻음.
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
				//합치기
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
				//다시 떙겨
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
				// 하
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
				//합치기
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
				//다시 떙겨
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

				//출력부
				cout << " turn : " << cnt + 1 << "Down" << "\n";
				for (int j = 0; j <= n + 1; j++) {
					for (int k = 0; k <= n + 1; k++) {
						cout << temp[j][k] << " ";
					}cout << "\n";
				}
				dfs(temp, cnt + 1);
				break;
			case 3:
				// 상
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
				//합치기
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
				//다시 떙겨
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
				//출력부
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
	// map 구조는 -1로 둘러싸인 n사이즈 정사각형임.
	/*  전체가 1 부터 n까지인 좌표
 -1-1-1-1-1
-1222-1
-1444-1
-1888-1
-1-1-1-1-1
	*/
	return 0;
}

// 기본적으로 Max 5번이라는 조건이 정해져있고 Max 값을 찾는거니까 DFS가 맞는거 같고 
// 횟수가 크지않으니까 그때 그때 맵 전체 복사해서 전해주는게 좋을 것 같고
