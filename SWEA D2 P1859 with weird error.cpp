#include <iostream>
using namespace std;

int main(){
	freopen("input.txt","rt",stdin);
	int n,m=0;
	int b=0;
	int sum=0;
	scanf("%d",&n);
	scanf("%d",&m);
	int arr[m]={0};
	int max=0;
	int a=0;//�̰� a����� ���̻��ϰ� ���� ��ġ�ڳ�;; 
	
	for(int i=0;i<n;i++){
		sum=0;
		if(b!=0){
			scanf("%d",&m);
		}
		for(int j=0;j<m;j++){
			scanf("%d",&arr[j]);
		}
		
		max=m-1;
		
		for(int k=m-1;k>=0;--k){
			
			
			if(arr[max]>arr[k]){
				sum+=(arr[max]-arr[k]);
				
			}else{
				max=k;
			}
			
		}
		
		
		
		b=1;
		cout<<sum<<" ";
		
	}
	
	return 0;
} 
