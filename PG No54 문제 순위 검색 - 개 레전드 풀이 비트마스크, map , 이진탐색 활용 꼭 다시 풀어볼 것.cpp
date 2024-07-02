#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<unordered_map>

/*
unorderd_map
map보다 더 빠른 탐색을 하기 위한 자료구조입니다.

unordered_map은 해쉬테이블로 구현한 자료구조로 탐색 시간복잡도는 O(1)입니다.

map은 Binary Search Tree로 탐색 시간 복잡도는 O(log n)입니다.

unordered_map을 사용하기 위해서는 #include< unordered_map > 을 선언해야 합니다.

unordered_map은 중복된 데이터를 허용하지 않고 map에 비해 데이터가 많을 시 월등히 좋은 성능을 보입니다.

하지만, key가 유사한 데이터가 많을 시 해시 충돌로 인해 성능이 떨어질 수도 있습니다.

*/

using namespace std;



vector<int> solution(vector<string> info, vector<string> query) {
    vector<int>answer;
   // 시간복잡도 N제곱 해결하려면 Map을 써야함.. 조건의 경우 몇개 없으니 조건 : 키값 느낌으로 Map을 생성.
    unordered_map<string , int>map;
    map.insert( {"-", 0} );
    map.insert( {"cpp", 1} );
    map.insert( {"java", 2} );
    map.insert( {"python", 3} );
    map.insert( {"backend", 1} );
    map.insert( {"frontend", 2} );
    map.insert( {"junior", 1} );
    map.insert( {"senior", 2} );
    map.insert( {"chicken", 1} );
    map.insert( {"pizza", 2} );
 // 이 맵을 기반으로 각 Info를 아래 vec배열에 index화 시켜버림.
    vector<int>vec[4][3][3][3] ;

    for(auto st: info){
        stringstream ss(st);
        string a,b,c,d;
        int e;
        ss>>a>>b>>c>>d>>e;
        
        // 이부분이 진짜 레전드 부분 이게 이렇게만 하면 "-" 인경우를 처리할 수가 없으니까 그냥 숫자조합 외에 각각 0추가한 것까지.
        // 비트마스크 조합 구하는거로 다 추가해준다는거같은데. 한번에 이해하는게 쉽지않음
        // 예를들어 vec[3][1][2][1] 스코어 4를 추가할때 경우의 수가 총 16개임. 
        // vec[0][1][2][1] , vec[3][0][2][1] , vec[3][1][0][1] , vec[3][1][2][0] , vec[0][0][2][1] , vec[0][0][0][1] ... etc
        // 이거를 아래와 같이 비트마스크 조합으로 구현할 수가 있는거임.

        int arr[4] = {map[a],map[b],map[c],map[d]};
        for(int i = 0; i<(1 << 4); i++){
            // 총 2의 n승만큼의 조합 n이 4니까 i<(1<<4) 0~15까지
            int idx[4] = {0,};
            // 기본 인덱스 {0,0,0,0}
            for(int j = 0 ; j <4 ; j++){
                // 10000 일때 j가 하나씩 움직이면서 j&1일때 고부분만 arr[j]를 넣어주는거임 와 개쩐다... 진짜로 이러면 0001 0010 0011 0100 0101 ... 1111 까지 1들어가는 곳에 idx[j] = arr[j] 가 되는거
                if(i & (1<<j)){
                    idx[j] = arr[j];
                }
            }
            vec[idx[0]][idx[1]][idx[2]][idx[3]].push_back(e);
        }
    
    }
    // 이제 이 벡터 모든 경우의 수 대상으로score순으로 sorting 이래야 이따가 쿼리에서 숫자셀 수 있음.
    for(int a = 0 ; a<4 ; a++){
        for(int b = 0 ; b<3 ; b++){
            for(int c = 0 ; c<3 ; c++){
                for(int d = 0 ; d<3 ; d++){
                    sort(vec[a][b][c][d].begin(),vec[a][b][c][d].end());
                }
            }
        }
    }
    for(auto st : query){
        stringstream ss(st);
        string a,b,c,d,temp;
        int e;
        ss>>a>>temp>>b>>temp>>c>>temp>>d>>e;
        //해당값의 주소값을 뽑아옴. 거기에는 스코어별로 정리된 vector가 있을거니까
        auto& list = vec[map[a]][map[b]][map[c]][map[d]];
        
        int res = lower_bound(list.begin(),list.end(),e) - list.begin();
        // lower_bound -> 배열에서 해당값이랑 같거나 큰값이 몇번째 부터 있는지 주소값 return.
        // lower _ bound의 return값은 주소값이니까 비긴만큼 빼줌.
        answer.push_back(list.size() - res);
        //사이즈에서 빼줌.
        

    }

    return answer;
}

int main(){
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    vector<int>answer = solution(info,query);
    for(int i = 0 ; i<answer.size();i++){
        cout << answer[i] << " ";
    }
    return 0;
}