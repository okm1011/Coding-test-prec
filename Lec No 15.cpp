#include <iostream>


bool isPrime(int x){
	if(x<=1){
		return false;
	}
	if(x%2==0){
		return x==2;
	}
	for(int i=3;i*i<=x;i+=2){
		if(x%i==0){
			return false;
		}
	}
	return true;
}




int main(){
	using namespace std;
	freopen("input.txt","rt",stdin);
	
	// 1초 -> 시간복잡도 10억 , N >200,000 
	// 기존 isPrimenumber 쓰면 복잡도 [루트N]*N  = 8천9백만 쌉가능
	 
	int n;
	scanf("%d",&n);
	
	int cnt=0;
	
	for(int i=1;i<=n;i++){
		if(isPrime(i)==true){
				cnt ++;
			}
	} 
	
	cout << cnt;
	
	return 0;
}
