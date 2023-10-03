#include <iostream>
using namespace std;

bool isPrime(int x){
	if(x<=1){
		return false;
	}else if(x%2==0){
		return x==2;
	}else{
		for(int i=3;i*i<=x;i+=2){
			if(x%i==0){
				return false;
			}	
		}
	}
	return true;
}





int main(){
	freopen("input.txt","rt",stdin);
	int n;
	int fac=1;
	int arrcnt = 1;
	scanf("%d",&n);
	int arr[n] = {};
	for(int i=n;i>1;i--){
		fac=fac*i;
	}
	for(int j=2;j<=fac;j++){
		if(isPrime(j)==true){
			if(fac%j==0){
				fac = fac/j;
				arr[arrcnt]++;
				j--;
			}else{
				arrcnt++;
			}
		}else{
			;
		}
	}

	
	
	for(int k=1;k<=arrcnt;k++){
		cout<<arr[k];
	}
	
	
	return 0;
}
