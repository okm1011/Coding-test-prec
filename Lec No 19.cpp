#include <iostream>
using namespace std;


int main(){
	freopen("input.txt","rt",stdin);
	
	int n;
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		arr[i]=x;
	}
	int cnt=0;
	//���� for�� �������� �� ������?
	for(int j=0;j<n;j++){
		for(int k=j+1;k<n;k++){
			if(arr[j]<=arr[k]){
				break;
			}
			
			if(k==n-1){
				cnt++;
			}
		}
	} 
	/*
	�̷� ����� ����. �ڿ��� ���� �ϴ°��� 
	int max = arr[n-1];
	for(i=n-2;i>=0;i--){
		if(arr[i]>max){
			max=arr[i];
			cnt++; 


		}	
	
	}
	
	
	*/
	cout << cnt;
	return 0;
}
