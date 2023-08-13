#include <iostream>

using namespace std;

int main(){
	freopen("input.txt","rt",stdin);
	
	//1초 실행 -> O(C) = 10억.
	int max = -21470000; 
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	int arr[n];
	int sum =0;
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}//여기서 10만씀 
	
	//그냥 2중 for문 돌리면 10억넘어감.. 10만*10만
	// 다른방법??
	/*for(int j=0;j<n;j++){
		for(int m=0;m<k;m++){
			sum = sum+arr[j+m];
		}
		if(max<sum){
			max = sum;
			}
		sum = 0;
	} */
	for(i=0; i<k ;i++){
		sum+=arr[i];
	}
	max = sum;
	for(i=k;i<n;i++){
		sum=sum+(arr[i]-arr[i-k]); // 와 한칸씩 옮기면되니까 이거 종이책에 써보면서 해야함. 어차피 한칸씩 옮겨지는거니까 
		if(max<sum){
			max = sum;
			}
	}
	
	cout << max;
	
	return 0;
}
