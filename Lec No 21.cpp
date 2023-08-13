#include <iostream>

using namespace std;

int main(){
	freopen("input.txt","rt",stdin);
	
	int arrA[10],arrB[10];
	int i;
	int Acnt=0,Bcnt=0;
	char last='N';
	
	for(i=0;i<20;i++){
		if(i<10){
			scanf("%d",&arrA[i]);
		}else{
		
		scanf("%d",&arrB[i-10]);
		}
	}

	for(int j=0;j<10;j++){
		if(arrA[j]>arrB[j]){
			Acnt+=3;
			last = 'A';
		}else if(arrA[j]<arrB[j]){
			Bcnt+=3;
			last = 'B';
		}else{
			Acnt++;
			Bcnt++;
		}
	}
	
	if(Acnt>Bcnt){
		cout << "A win";
	}else if(Acnt<Bcnt){
		cout << "B win";
	}else if(Acnt==Bcnt&&last=='A'){
		cout << "A win";
	}else if(Acnt==Bcnt&&last=='B'){
		cout << "B win";
	}else{
		cout << "Equal";
	}
	
	
	
	return 0;
	
}
