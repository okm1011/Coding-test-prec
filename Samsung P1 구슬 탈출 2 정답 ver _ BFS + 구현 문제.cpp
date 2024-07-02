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
// 방향 벡터 우 좌 위 아래

Ball move_ball(Ball temp, int i) {
	Ball result = temp;
	result.turn += 1;
	int r_f = 0, b_f = 0;
	// flag 0 = 기본 1은 막힘 2는 골인.
	int move_x = dx[i];
	int move_y = dy[i];
	while (1) {
		 if (r_f != 0 && b_f != 0)break;
		 // 이동 부분
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

		// 여기까지 이동
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
	// 중복 checking 배열 중복은 red만 하면 될 것 같은데. >> 아냐... 아니였어
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
				//구멍
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
	// 최소 몇번만에 빨간구슬 to 구멍 불가능 이면 -1 출력인데 이건 무조껀 BFS지
	// 
	queue<Ball> q;

	// 각각 x,y좌표 for 빨구 파구
	q.push(Ball(r_s_x,r_s_y, b_s_x, b_s_y,0));
	ch[r_s_y][r_s_x][b_s_y][b_s_x] = 1;
	// 각각 x,y 순서로 삽입 for start pos

	while (!q.empty()) {
		Ball temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			// 이부분에서 빨공 , 파공 부딛히는거 생각해서 움직이는 부분을 함수로 나눠버리자.
			//  move(b_x , b_y , res ) >> 최종 좌표 & 구멍 들어갔는지 // 빨파 둘다 move때리고 좌표 같으면  move 때리기 전 좌표 비교해서 뒤에있는놈 좌표 하나 - (이건 i의 값마다 다름.)
			// Ball을 통짜로 넘기면 되겠는데
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
			// first_ball 0은 안겹침 1은 red가 2는 blue가 앞
			if (result.b_x == result.r_x && result.b_y == result.r_y) {
				switch (i) {
				case 0:
					// 우 > x값 큰놈이 first
					if (temp.b_x > temp.r_x) {
						result.r_x -= 1;
					}
					else if (temp.b_x < temp.r_x) {
						result.b_x -= 1;
					}
					break;
				case 1:
					//좌 >> x값 작은놈이 first
					if (temp.b_x > temp.r_x) {
						result.b_x += 1;
					}
					else if (temp.b_x < temp.r_x) {
						result.r_x += 1;
					}
					break;
				case 2:
					//아래
					if (temp.b_y > temp.r_y) {
						result.r_y -= 1;
					}
					else if (temp.b_y < temp.r_y) {
						result.b_y -= 1;
					}
					break;
				case 3:
					//위
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