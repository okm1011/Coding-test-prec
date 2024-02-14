#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int sum = 0;
    for(int i = 1;i<10;i++){
        bool flag = true;
        for(int j = 0 ; j<numbers.size();j++){
            if(i == numbers[j]){
                flag = false;
            }
        }
        if(flag)sum = sum+i;
    }
    return sum;
}

int main(){
    vector<int>numbers = {1,2,3,4,6,7,8,0};
    int answer = solution(numbers);

    return 0;
}