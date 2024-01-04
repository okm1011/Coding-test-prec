#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(int);
int n = 0 , m = 0,cnt = 0;

vector< vector < int > > arr(20,vector<int>(20,0));
vector<int>ch(20,0);

int main(){
	freopen("input.txt","rt",stdin);
	cin >> n >> m;
	
	
	for(int i = 0;i<m;i++){
		int from = 0,to =0;
		cin >> from >> to;
		arr[from][to] = 1;
	}

	
	ch[1] = 1;
	dfs(1);
	cout << cnt;
	return 0;
}

void dfs(int level){
	
	if(level == n){
		cnt++;	
	}else{
		for(int i = 1;i<=n;i++){
			if(arr[level][i]==1 && ch[i] == 0){
				ch[i] = 1;
				dfs(i);
				ch[i] = 0;
			}
		}
	}
		
	
}
