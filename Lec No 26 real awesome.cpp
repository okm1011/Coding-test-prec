#include <iostream>

using namespace std;

int main(){
	
	freopen("input.txt","rt",stdin);
	int cnt = 0;
	int n;
	
	
	scanf("%d",&n);
	int a[n];
	int res[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		res[i]=1;
	}
	for(int j=1;j<n;j++){
		res[j]=j+1;
		for(int k=j-1;k>=0;k--){
			if(a[k]<a[j]){
				res[j]--;
			}
		}
		
	} // 여기 ㄹㅇ 개쩔었다. 
	for(int l=0;l<n;l++){
		cout << res[l];
	}

}
