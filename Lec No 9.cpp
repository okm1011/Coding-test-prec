#include <iostream>

/* int main(){
using namespace std;
int n,i,j,cnt=0;

cin >> n;

for(i=1;i<=n;i++){
	for(j=1;j<=i;j++){
		if(i%j==0){
		cnt ++;
			
		}

}
	cout << cnt;
	cout << ' ';
	cnt = 0;	
}
	return 0;
}
*/ //this main function can not meet 1sec time limit almost n^2 time complexity.
int cnt[50001];

int main(){
using namespace std;

int n,i,j;
cin >> n;

for(i=1;i<=n;i++){
	for(j=i;j<=n;j=j+i){
		cnt[j]++;
		
	}
	
}
for(i=1;i<=n;i++){
	cout << cnt[i];
	cout << ' ';
}
}
