#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    
    // 이미 하나로 다 연결이 되어있음. 유니온앤파인드가 맞나? 음...
    // n의 최대값이라고 해봐야 100 이니까 O(n의 3제곱)도 쌉가능
    // 라인을 하나씩 끊고 라인 타면서 cnt를 올릴까?

    int min_diff = 1000;
    sort(wires.begin(),wires.end());
    // 3,4 4,3 같은 중복이 없음 왜냐면 1<v1<v2<n 이니까
    for(int i = 0 ; i<wires.size();i++){
        vector<int>temp;
        for(int j = 0 ; j < wires.size();j++){
            if(i==j)continue;
            if(temp.empty()){
                temp.push_back(wires[j][0]);
                temp.push_back(wires[j][1]);
            }else{
                if(find(temp.begin(),temp.end(),wires[j][0])!=temp.end()){
                    if(find(temp.begin(),temp.end(),wires[j][1])==temp.end()){
                        temp.push_back(wires[j][1]);
                    }
                }else if(find(temp.begin(),temp.end(),wires[j][1])!=temp.end()){
                    if(find(temp.begin(),temp.end(),wires[j][0])==temp.end()){
                        temp.push_back(wires[j][0]);
                    }
                }
            }



        }
        int diff = temp.size() - (n-temp.size());
        diff = abs(diff);
        if(diff<min_diff)min_diff=diff;

    }
    return min_diff;
}

int main(){
    int n = 4;
    vector<vector<int>> wires = {{1, 2}, {1, 4}, {2, 3}, {3, 4}};
    int answer = solution(n,wires);
    cout << answer;
    return 0;
}