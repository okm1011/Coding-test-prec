#include <iostream>
using namespace std;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

int main() {
	int test_case;
	cin >> test_case;
	int i = 0, j = 0;

	int map[10][10];

	for (int t = 1; t <= test_case; t++) {
		int n;
		cin >> n;
		int size = n * n;
		int cnt = 2;
		int drc = 0;
		memset(map, 0, sizeof(map));
		map[0][0] = 1;
		i = 0;
		j = 0;


		while (size >= cnt) {
			//여기서 i,j쓰는건 넘어갔을때 저장해놓고 DY,DX[] 이거로 롤백할 수 있음.. 와
			int ty = i + dy[drc];
			int tx = j + dx[drc];



			if (ty<0 || tx<0 || ty>=n || tx>=n || map[ty][tx] > 0){
				drc += 1;

				if (drc == 4) {
					drc = 0;
				}
				continue;
				
				
			}
			i = ty;
			j = tx;
			map[ty][tx] = cnt;

			cnt++;

		}

		cout << "#" << test_case << "\n";
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}


		
	}


	return 0;
}