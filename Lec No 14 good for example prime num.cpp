#include <iostream>
using namespace std;


bool isPrime(int x){
	if(x<=1){
		return false;
	}
	if(x%2==0){
		return x==2;
	}
	for(int i=3 ; i*i<=x;i+=2){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
/* ��� Reverse �κ� �� ��¾�� ��¥
����Ʈ�� ���ڸ��� �ٲٴ� �ſ���....
ex) 3455 �� ���� result�� ���� 10���ϰ� ���������ϰ�

int reverse(int x){
int res = 0,tmp=0;

while(x>0){
temp=x%10;
res=res*10+tmp;
x=x/10;

}
��¾�� ���� 



}



 */
int reverse(int x){
	
	int cnt=0,d=100000;
	int arr[6];
	while(d>1){
		if(x/d==0){
			arr[cnt]=0;
		}else{
			arr[cnt]=x/d;
			x=x-(arr[cnt]*d);
		}
		d=d/10;
		cnt++;  //100 3 10 4 1 5 
	}
	arr[cnt]=x;
	
    int result = 0;
    for (int i = 0; i <= cnt; i++) {
    	
        if(arr[cnt - i]!=0){
		result = result * 10 + arr[cnt - i];}
		
    }
    return result;
}


int main(){

	freopen("input.txt","rt",stdin);
	int n,x,y;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		y=reverse(x);
		if(isPrime(y)==true){
			cout << y;
			cout << " ";
		}
	}
	
	return 0;
	
	
	
	
}
