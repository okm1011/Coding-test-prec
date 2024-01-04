#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> >arr(9,vector<int>(9,1));
vector<vector<int> >ch(9,vector<int>(9,0));
int cnt = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void dfs(int,int);

int main(){
	freopen("input.txt","rt",stdin);
	
	for(int i =1;i<=7;i++){
		for(int j = 1; j<=7 ; j++){
			cin >> arr[i][j];	
		}	
	}
	
	ch[1][1] = 1;
	dfs(1,1);
	cout<<cnt;
	return 0;
}

void dfs(int x, int y){
	int xx,yy;
	
	if(x==7&&y==7){
		
		cnt++;
		
	}else{
		for(int i =0;i<4;i++){
			xx = x + dx[i];
			yy = y + dy[i];
			if(xx<1 || xx>7 || yy <1 || yy>7) continue;
			
			if(arr[yy][xx] == 0 && ch[yy][xx] == 0){
				ch[yy][xx] = 1;
				cout << " x : " << xx << " y : " << y <<"\n";
				dfs(xx,yy);
				ch[yy][xx] = 0;
			}
		}
		
	}
	

	
	
}
