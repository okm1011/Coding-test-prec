#include <iostream>
using namespace std;

int main(){
	
	freopen("input.txt","rt",stdin);
	
	int n;
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		
		scanf("%d",&arr[i]);
	}
	
	for(int j=0;j<n-1;j++){
		// ���� ���� for�� �κ� ���Ǽ��� �߸��ϸ� ���� ���̳� �ٽ� �񱳰� �Ǵϱ�... 
		for(int k=j+1;k<n;k++){
			if(arr[j]<arr[k]){
				int tmp;
				tmp=arr[j];
				arr[j]=arr[k];
				arr[k]=tmp;
			}
		}
	}

	int cnt=0;
	
	for(int l=0;l<n;l++){
		if(arr[l]!=arr[l+1]){
			cnt++;
		}
		if(cnt==3){
			cout<<arr[l];
			break;
		}
	}
	for(int m=0;m<n;m++){
		
		cout<<arr[m];
	}
	return 0;
}
