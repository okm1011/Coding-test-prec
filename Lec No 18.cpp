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
	/*���� arr[n]���� 1�ʰ� �︮�� 1 �ȿ︮�� 0�ε� �����϶� cnt ++�ϴ� �ڵ带¥����
	���� �ִ밪 ī��Ʈ��..
	�� 0 �̸� cnt �ʱ�ȭ 1�̸� cnt++ 
	������ 0 �̸� cnt �� max���� ū�� Ȯ�� �ϸ� �� ��???
	������ ���� �Ű����� ��. 
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
