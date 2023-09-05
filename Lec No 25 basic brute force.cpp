#include <iostream>

using namespace std;

int main(){
	
	freopen("input.txt","rt",stdin);
	int cnt =1;
	int n;
	int a[5];
	int res[5];
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	  /* 여기서 아싸리 res[5]를 다 1로 초기화 해놓고 ++ 해도 괜찮음.
	 */
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++){
			if(a[j]<a[k]){
			cnt++;	
			}else if(a[j]==a[k]){
				
			}else{
					
			}
		}
		
		res[j] = cnt;
		cnt = 1;
	}
	for(int l=0;l<n;l++){
		cout << res[l] << " ";
	}
	return 0;

}
