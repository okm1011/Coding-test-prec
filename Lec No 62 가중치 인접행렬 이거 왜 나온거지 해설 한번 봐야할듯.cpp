#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,m;
	freopen("input.txt","rt",stdin);
	cin >> n >> m ;
	vector < vector <int> > arr(n+1,vector <int>(n+1,0));
	
	int f = 0 , s = 0 ,t = 0;
	for(int i = 0; i<m;i++){
			cin >> f >> s>>t;
			arr[f][s] = t;
	}
	
	
	for(int i = 1;i<=n;i++){
		for(int j =1 ; j<=n;j++){
			cout<<arr[i][j];
		}
		cout<<"\n";
	}
	
	
	return 0;
}

