#include <iostream>
using namespace std;

int main(){
	
	freopen("input.txt","rt",stdin);
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int arr[n];
	
	for(int i=0;i<=n-1;i++){
		int x;
		scanf("%d",&x);
		if(x-m>0){
			arr[i]=1;
		}else{
			arr[i]=0;
		}
		
	}
	/*이제 arr[n]에는 1초간 울리면 1 안울리면 0인데 연속일때 cnt ++하는 코드를짜야함
	연속 최대값 카운트업..
	걍 0 이면 cnt 초기화 1이면 cnt++ 
	다음께 0 이면 cnt 가 max보다 큰지 확인 하면 될 듯???
	마지막 수는 신경써야할 듯. 
	*/
	int max=-200000;
	int cnt = 0;
	for(int j =0;j<= n-1;j++){
		
		if(j==n&&arr[j]==1){
			cnt++;
			if(cnt>=max){
				max = cnt;
			}
		} 
		
		if(arr[j]==1){
			cnt++;
		}else{
			cnt = 0;
		}
		if(arr[j+1]==0){
			if(cnt>=max){
				max = cnt;
			}	
		}
	}
	if(max==0){ cout << "-1\n";
	}else{
	cout << max;
}
	return 0;
}
