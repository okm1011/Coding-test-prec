#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int&a,int&b){
    return a>b; 
    // sort의 3번째 인자에 들어가는 함수 규칙: return type은 bool
    // 인자는 동일 타입 매개변수 두개
    // return 이 true일때 왼쪽 먼저 나오고 False 면 오른쪽이 먼저 나옴
}

class Edge {

public:
    int v1;
    int v2;
    int val;
    Edge(int a , int b , int c){
        v1 = a;
        v2 = b;
        val = c;

    }
    /*
    bool operator<(Edge&b){
        return this->val < b.val;
    } // 이 뜻은 val을 기준으로 비교되는 뒤쪽 val이 더크면 앞쪽 val 먼저 나간다는거 -> 오름차순
    */
    /*
    bool operator<(Edge&b){
        return this->val > b.val;
    } // 이 뜻은 val을 기준으로 비교되는 뒤쪽 val이 더 작으면  앞쪽 val 먼저 나간다는거 -> 내림차순
    */
    
    bool operator<(Edge&b){
        return v1 > b.v1;
    } // 이 뜻은 v1을 기준으로 비교되는 뒤쪽 val이 더 작으면  앞쪽 val 먼저 나간다는거 -> 내림차순

};





int main(){
    // 구조체 정렬 && sort 함수 내림차순 올림차순 변경 정리임

    vector<int>arr;
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(2);
    for(int i = 0; i<5;i++){
        cout << arr[i] << " ";
    }cout << "\n";
    // 5 1 3 4 2
    sort(arr.begin(),arr.end());
    for(int i = 0; i<5;i++){
        cout << arr[i] << " ";
    }cout << "\n";
    // 1 2 3 4 5 이렇게 sort 처음부터 끝까지 돌리면 오름차순으로 정렬이됨 . 
    //이걸 내림차순으로 바꾸기 위한 compare 함수가 필요
    
    sort(arr.begin(),arr.end(),compare);
    for(int i = 0; i<5;i++){
        cout << arr[i] << " ";
    }cout << "\n";
    // return a>b니까 a가 b보다 크면 먼저 나온다는거니까 내림차순임.

    //여기서 class 나 structure 중 하나의 value를 정렬시키기 위해서 operator overriding을 사용한다.
    //struct[기존 c언어 , 값 타입 , 기본 public] 와 class[c++ , 참조 타입 , 기본 private] 의 차이 class만 상속가능 class -> heap struct -> stack


    vector<Edge>arr2; // class가 들어갈 vector배열
    freopen("input.txt","rt",stdin);
    int n , m;
    cin >> n >> m;
    for(int i = 1;i<=m;i++){
        int a , b , c;
        cin >> a >> b >> c;

        arr2.push_back(Edge(a,b,c));
        // 여기서 3가지 a,b,c 읽어와서 arr2에 삽입.
    }

    for(int i = 0; i<m;i++){
        cout << arr2[i].v1 <<" "<< arr2[i].v2 <<" " << arr2[i].val << "\n";
    } // 이러면 input 들어온 대로 쭉나옴
    // v1, v2 , val 중 하나를 내림차순 or 오름 차순 정리하고 싶다 위에 class operator 설정하고 sort() 하면된다.
    sort(arr2.begin(),arr2.end()); // operator 설정 이후 sort 진행 세번째 매개변수 함수 필요없음
    cout << "\n";
    for(int i = 0; i<m;i++){
        cout << arr2[i].v1 <<" "<< arr2[i].v2 <<" " << arr2[i].val << "\n";
    }    
    return 0;
}