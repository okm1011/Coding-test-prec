#include <iostream>
using namespace std;

int res(int x,int y){
	
	
	if(x==y){
		return 1;
	}
	if(x==1){
		if(y==3){
			return 2;
		}else{
			return 3;
		}
	}else if(x==2){
		if(y==1){
			return 2;
		}else{
			return 3;
		}
	}else{
		if(y==2){
			return 2;
		}else{
			return 3;
		}		
	}	
}
/* ��� ���⼭ return 3���� ��¥ else�� �׳� ���� �� ����.
if(x==y){
	return 1;
}else if(x==1&&y==3){
	return 2;
}else if (x==2&&y==1){
	return 2;
}else is (x==3&&y==2){
	return 2;
}	
else {
	return 3;
}  �䷸��  
*/


int main(){

freopen("input.txt","rt",stdin);	
int n;
scanf("%d",&n);

int arrA[n]={};
int arrB[n]={};
int final[5]={};

for(int i=0;i<=n-1;i++){
	scanf("%d",&arrA[i]);
}
for(int i=0;i<=n-1;i++){
	scanf("%d",&arrB[i]);
	final[i] = res(arrA[i],arrB[i]);
}

	
for(int i=0;i<=n-1;i++){
	if(final[i]==1){
		cout << "D";
	}else if(final[i]==2){
		cout << "A";
	}else {
		cout << "B";
	}
}	
	

	
	return 0;
} 
