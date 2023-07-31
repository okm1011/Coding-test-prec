#include <iostream>

int main(){
	using namespace std;
	
	freopen("input.txt","rt",stdin);
	char a[30];
	scanf("%s",a);
	int count=0,i;
	
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='('){
			count ++;
		}else{
			count --;
		}
	
	}
	if(count == 0){
		cout << "good \n";
	}else{
		cout << "No good \n";
	}
	
	
	
	
	
	
	return 0;
}
