#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int ch[11][11][11][11] = { 0 };
vector<vector<int>> map(11, vector<int>(11, 0));
bool done_flag = false;
bool fail_flag = false;
int n = 0, m = 0;

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

Ball move_ball(Ball temp, int i) {
	Ball result = temp;
	result.turn += 1;
	int r_f = 0, b_f = 0;
	// flag 0 = �⺻ 1�� ���� 2�� ����.
	int move_x = dx[i];
	int move_y = dy[i];
	while (1) {
		 if (r_f != 0 && b_f != 0)break;
		 // �̵� �κ�
		 if ((0 <= result.r_x + move_x) && (result.r_x + move_x <= m) && (0 <= result.r_y + move_y) && (result.r_y + move_y <= n)) {
			 if (map[result.r_y + move_y][result.r_x + move_x] == 0 && r_f == 0) {
				 result.r_x += move_x;
				 result.r_y += move_y;
			 }
			 else if (map[result.r_y + move_y][result.r_x + move_x] == 1) {
				 r_f = 2;
			 }
			 else if (map[result.r_y + move_y][result.r_x + move_x] == -1) {
				 r_f = 1;
			 }
		 }
		 else {
			 r_f = 1;
		 }
		 
		 if ((0 <= result.b_x + move_x) && (result.b_x + move_x <= m) && (0 <= result.b_y + move_y) && (result.b_y + move_y <= n)) {
			 if (map[result.b_y + move_y][result.b_x + move_x] == 0 && b_f == 0) {
				 result.b_x += move_x;
				 result.b_y += move_y;
			 }
			 else if (map[result.b_y + move_y][result.b_x + move_x] == 1) {
				 b_f = 2;
			 }
			 else if (map[result.b_y + move_y][result.b_x + move_x] == -1) {
				 b_f = 1;
			 }
		 }
		 else {
			 b_f = 1;
		 }

		// ������� �̵�
	}
	if (b_f == 2) {
		fail_flag = true;
	}
	else if (r_f == 2 && b_f != 2) {
		done_flag = true;
	}

	return result;
}
int main() {

	

	bool op = freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	int r_s_x = 0 , r_s_y = 0, b_s_x = 0, b_s_y = 0, g_x = 0, g_y = 0;
	// i = y = n , j = x = m
	// �ߺ� checking �迭 �ߺ��� red�� �ϸ� �� �� ������. >> �Ƴ�... �ƴϿ���
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
			// �̺κп��� ���� , �İ� �ε����°� �����ؼ� �����̴� �κ��� �Լ��� ����������.
			//  move(b_x , b_y , res ) >> ���� ��ǥ & ���� ������ // ���� �Ѵ� move������ ��ǥ ������  move ������ �� ��ǥ ���ؼ� �ڿ��ִ³� ��ǥ �ϳ� - (�̰� i�� ������ �ٸ�.)
			// Ball�� ��¥�� �ѱ�� �ǰڴµ�
			Ball result = move_ball(temp, i);
			if (done_flag) {
				if (result.turn > 10) {
					cout << -1 ;
				}
				else {
					cout << result.turn;
				}
				
				return 0;
			}
			else if (fail_flag) {
				fail_flag = false;
				continue;
			}
			// first_ball 0�� �Ȱ�ħ 1�� red�� 2�� blue�� ��
			if (result.b_x == result.r_x && result.b_y == result.r_y) {
				switch (i) {
				case 0:
					// �� > x�� ū���� first
					if (temp.b_x > temp.r_x) {
						result.r_x -= 1;
					}
					else if (temp.b_x < temp.r_x) {
						result.b_x -= 1;
					}
					break;
				case 1:
					//�� >> x�� �������� first
					if (temp.b_x > temp.r_x) {
						result.b_x += 1;
					}
					else if (temp.b_x < temp.r_x) {
						result.r_x += 1;
					}
					break;
				case 2:
					//�Ʒ�
					if (temp.b_y > temp.r_y) {
						result.r_y -= 1;
					}
					else if (temp.b_y < temp.r_y) {
						result.b_y -= 1;
					}
					break;
				case 3:
					//��
					if (temp.b_y > temp.r_y) {
						result.b_y += 1;
					}
					else if (temp.b_y < temp.r_y) {
						result.r_y += 1;
					}
					break;
				default:
					break;

				}

			}
			cout << " r_x: " << result.r_x << " r_y: " << result.r_y << " b_x: " << result.b_x << " b_y: " << result.b_y << " turn: " << result.turn << "\n";
			if (ch[result.r_y][result.r_x][result.b_y][result.b_x] == 0) {
				ch[result.r_y][result.r_x][result.b_y][result.b_x] = 1;
				q.push(result);
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