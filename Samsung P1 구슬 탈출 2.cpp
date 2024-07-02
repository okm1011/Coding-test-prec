#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
class Ball {
public:
	int r_x;
	int r_y;
	int b_x;
	int b_y;
	int turn;
	Ball(int a, int b, int c , int d , int e) {
		r_x = a;
		r_y = b;
		b_x = c;
		b_y = d;
		turn = e;
	}
};
// ���� ���� �� �� �� �Ʒ�
int main() {

	
	int n = 0, m = 0;
	bool op = freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	int r_s_x = 0 , r_s_y = 0, b_s_x = 0, b_s_y = 0, g_x = 0, g_y = 0;
	// i = y = n , j = x = m
	vector<vector<int>> map(n, vector<int>(m, 0));
	// �ߺ� checking �迭 �ߺ��� red�� �ϸ� �� �� ������. >> �Ƴ�... �ƴϿ���
	int ch[10][10][10][10] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			if (temp == '#') {
				map[i][j] = -1;
			}else if(temp == '.'){
				map[i][j] = 0;
			}
			else if (temp == 'O') {
				//����
				map[i][j] = 1;
				g_x = j;
				g_y = i;
			}
			else if (temp == 'R') {
				map[i][j] = 0;
				r_s_x = j;
				r_s_y = i;
			}
			else if (temp == 'B') {
				map[i][j] = 0;
				b_s_x = j;
				b_s_y = i;
			}

		}
	}
	// �ּ� ������� �������� to ���� �Ұ��� �̸� -1 ����ε� �̰� ������ BFS��
	// 
	queue<Ball> q;

	// ���� x,y��ǥ for ���� �ı�
	q.push(Ball(r_s_x,r_s_y, b_s_x, b_s_y,0));
	ch[r_s_y][r_s_x][b_s_y][b_s_x] = 1;
	// ���� x,y ������ ���� for start pos

	while (!q.empty()) {
		Ball temp = q.front();
		q.pop();


		for (int i = 0; i < 4; i++) {
			int move_x = dx[i];
			int move_y = dy[i];
			int r_x = temp.r_x;
			int r_y = temp.r_y;
			int b_x = temp.b_x;
			int b_y = temp.b_y;
			int turn = temp.turn;
			bool r_f = false, b_f = false;

			// blue�� ���� �Űܾ���, �̰� ���� red�� ������� fail�̴ϱ�. �� �ٵ� ���� ��ĥ �� ��� �ؾ����� ...........? �� while�� �������� ����.
			while (1) {
				
				
				if (r_f && b_f && ch[r_y][r_x][b_y][b_x] == 0) {
					ch[r_y][r_x][b_y][b_x] = 1;
					cout << " r_x: " << r_x << " r_y: " << r_y << " b_x: " << b_x << " b_y: " << b_y << "turn" << turn << "\n";
					q.push(Ball(r_x, r_y, b_x, b_y, turn + 1));
					break;
				}
				else if (r_f && !b_f) {
					if ((0 <= b_x + move_x <= m) && (0<= b_y + move_y <= n)) {
						b_x += move_x;
						b_y += move_y;
					}

				}
				else if (!r_f && b_f) {
					if ((0 <= r_x + move_x <= m) && (0 <= r_y + move_y <= n)) {
						r_x += move_x;
						r_y += move_y;
					}

				}
				else if (!r_f && !b_f) {
					if (((0 <= r_x + move_x <= m) && (0 <= r_y + move_y <= n)) && ((0 <= b_x + move_x <= m) && (0 <= b_y + move_y <= n))) {
						b_x += move_x;
						b_y += move_y;
						r_x += move_x;
						r_y += move_y;
					}

				}
				else {
					break;
				}


				// blue �Ǻ� 4���� ��� 1) ������ . 2) ���� 3) ��� 4)red ����
				if (b_f) {
					;
				}
				else if (map[b_y][b_x] == -1) {
					b_x -= move_x;
					b_y -= move_y;
					b_f = true;
					// reset pos for blue and flag set
				}
				else if (map[b_y][b_x] == 0) {
					if (b_x == r_x && b_y == r_y) {
						//crushed
						b_x -= move_x;
						b_y -= move_y;
						b_f = true;
						
					}
					else {
						// �� ����
					}
				}
				else if (map[b_y][b_x] == 1) {
					// blue�� ���� �̷��� �̹� ��ǥ�� ������ fail��.
					break;
				}

				// �����ϰ� red �ǰ� 4���� ���
				if (r_f) {
					;
				}
				else if (map[r_y][r_x] == -1) {
					r_x -= move_x;
					r_y -= move_y;
					r_f = true;
					// reset pos for blue and flag set
				}
				else if (map[r_y][r_x] == 0) {
					if (r_x == b_x && r_y == b_y) {
						//crushed
						r_x -= move_x;
						r_y -= move_y;
						r_f = true;

					}
					else {
						// �� ����
					}
				}
				else if (map[r_y][r_x] == 1) {
					// ���⼭ red �� blue �տ����� ��� ���� �� �־����
					while (1) {
						b_x += move_x;
						b_y += move_y;
						if (map[b_y][b_x] == 1) {
							break;
						}
						else if (map[b_y][b_x] == -1) {
							cout << turn + 1;
							return 0;
						}
					}

					break;
				}
			}

		}
	}

	cout << -1;
	return 0;
}

/*
-1-1-1-1-1
-1003-1
-10-10-1
-1210-1
-1-1-1-1-1
*/