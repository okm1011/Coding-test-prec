 /*
 #include <iostream>

using namespace std;

int main(){
	
	freopen("input.txt","rt",stdin);
	char n[10];
	int res=0;
	int pos1 = 0;
	int pos2 = 0;
	scanf("%s",&n);
	for(int i=0; i<10;i++){
		if(n[i]==72){
		break;
		}else{
		pos1++;
		}
	}
		for(int j=0; j<10;j++){
		if(n[j]=='\0'){
		break;
		}else{
		pos2++;
		}
	}
	pos2 = pos2 - pos1;
	  // A 65 C 67 H 72, a 97  -48=num

	// could be CxxxHxxx ~ CH
	//pos1 = loca of H , pos2 = loca of NULL
	
	switch(pos1){
		case 4: // CxxxH
			res = 1200;
			break;
		
		case 3: // CxxH
			res = res+ 120* (n[1]-'0');
			res = res+ 12* (n[2]-'0');  
			break;
		case 2: // CxH
			res = res+ 12* (n[1]-'0');  
			break;
		case 1: //CH
			res = 12;
			break;
		
	}
		switch(pos2){
		case 4: // Hxxx
			res = 100;
			break;
		
		case 3: // Hxx
			res = res+ 10*(n[pos1+1]-'0');
			res = res+ (n[pos1+2]-'0');  
			break;
		case 2: // Hx
			res = res+  (n[pos1+1]-'0');  
			break;
		case 1: //
			res = 12;
			break;
		
	}
	cout << res;


	return 0;
}



*/
// 맨날 이거 몰라서 코드 엄청 길어짐.. 문자열 -> 숫자에서  앞부터 곱해가는모양의 코드  

#include<iostream>

using namespace std;

int main(){
	
	freopen("input.txt","rt",stdin);
	char n[10];
	scanf("%s",n);
	int pos ;
	int c=0;
	int h=0;
	int res = 0;
	
	if(n[1]=='H'){
		c=1;
		pos = 1;
	}else{
		for(int i=1;n[i]!='H';i++){
			c=c*10 + (n[i]-'0'); // 이게 제일 포인트임. 
			pos = i+1;
		}
		
	}
	if(n[pos+1]=='\0'){
		h=1;
	}else{
		for(int j=pos+1;n[j]!='\0';j++){
			h=h*10 + (n[j]-'0'); // 이게 제일 포인트임. 
		}
		
		
	}
	res = 12*c + h;
	
	cout << res;
	
	
	return 0;
} 
