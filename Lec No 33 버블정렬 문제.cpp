#include <iostream>
using namespace std;
//�������� �ϳ��ϳ��� ���ؼ� �迭�� ������ ä������ �ð����⵵ �������� 

int main(){
	freopen("input.txt","rt",stdin);
	int n,tmp;
	scanf("%d",&n);
	int arr[n]={};
	for(int k=0;k<n;k++){
		scanf("%d",&arr[k]);
	} 
	
	
	//����ū�ź��� �迭�ǳ�
	
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=tmp;
			}
		}
	} 
	
	/*for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	} */
	
	for(int m=0;m<n;m++){
		printf("%d ",arr[m]);
		
	} 
	
	
	
	return 0;
}
