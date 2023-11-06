#include <iostream>
using namespace std;


int main(){
	
	freopen("input.txt","rt",stdin);
	
	int n;
	scanf("%d",&n);
	int cnt=1;
	int sum=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++){
			int tmp;
			scanf("%d",&tmp);
			if(tmp%2!=0){
				sum+=tmp;
			}
		}
		
		cout <<'#'<<cnt<<' '<<sum<<"\n";
		sum=0;
		cnt++;
	}
	
	return 0;
}
