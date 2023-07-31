#include <iostream>
using namespace std;

// this was awsome !!


int digit_sum(int x){
	int i,res=0,div=10000000;
	int sum=0;
	for(i=7;i>=0;i--){
		res = x/div;
		if(res != 0){
			sum = sum + res;
			x=x-(res*div);
			div = div/10;
		}
		else{div = div/10;}
		
		
	}
	
return sum;	
}	
	
	
	
int main(){
int n,i,j;
cin >> n;
int a[n];
int in[n];
int max=-2147000000; // this is important . we have to set Max as -2147000000 
int equal_max =-2147000000;


for(i=1;i<=n;i++){
	cin >> in[i];
	a[i]=digit_sum(in[i]);
}

//from now a[i] has all of sum values.
 
for(j=1;j<=n;j++){
	if(a[j]>max){
	max = a[j];	
	}
	else if (a[j]==max){
		if(in[j]>equal_max){
			equal_max = in[j];
		}
	} 
	else{
		
	}
	
}

if(max>equal_max){
	cout << max;
}else{
	cout << equal_max;
}
	
return 0;
}
	
