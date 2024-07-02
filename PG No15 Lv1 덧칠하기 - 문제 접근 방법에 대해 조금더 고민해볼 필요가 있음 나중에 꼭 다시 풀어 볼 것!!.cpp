#include <string>
#include <vector>
#include <iostream>


using namespace std;
// 포인트는 왼쪽부터 한번 시작 && 끝쪽에서 한번 이렇게 진행해야할 것 같음.
// maybe 투포인트? >> 이거 해봤는데 틀리더라... 걍 왼쪽 한방향에서 해도 상관 없을 것 같은데..

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int painted = 0; 
    // start point 설정 >> painted.
    for(int i = 0 ; i<section.size(); i++){
        if(painted < section[i]){
            painted = section[i] + m - 1;
            // 딱 그 section[i] 부터 m-1까지만 그리면서 answer 추가하는거임
            // 여기서 읽어가면서 벽 칠했어야하는데 왼쪽부터 m씩 계속 더하는거랑 헷갈려서 시간좀 걸렸음.
            answer++;
        }
    }
    return answer;
}
int main(){
   
    int n = 5;
    int m = 4;
    vector<int>section = {1,3};
    int answer = solution(n,m,section);
    cout << answer;

    return 0;
}