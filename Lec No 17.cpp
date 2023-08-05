#include <iostream>
using namespace std;


int sum_num(int x){
	int sum=0;
	
	for(int i=1;i<=x;i++){
		sum=sum+i;
	}
	return sum;
	
}



int main(){
	freopen("input.txt","rt",stdin);
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		int q,a;
		scanf("%d",&q);
		scanf("%d",&a);
		if(a==sum_num(q)){
			cout << "YES\n";
			
		}else {
			cout << "NO\n";
		}
	}
	
	return 0;
}
