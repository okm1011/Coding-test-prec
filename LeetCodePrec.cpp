#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        string answer = "/";
        stack<string>temp;
        string temp_str = "";
        for(int i = 0 ; i<path.size() ; i++){
            if(path[i] == '/'){
                if(temp_str!=""){
                    temp.push(temp_str); 
                    temp_str = "";
                }
            }else{
                temp_str+=path[i];
            }
        }
        if(temp_str!="")temp.push(temp_str); 

        vector<string>temp_vec;
        while(!temp.empty()){
            string top = temp.top();
            temp.pop();
            if(top == ".."){
                if(!temp.empty())temp.pop();
            }else if(top == "."){
                continue;
            }
            else{
                temp_vec.push_back(top);
            }

        }
        for(int i = temp_vec.size()-1; i>=0; i--){
            answer+=temp_vec[i];
            if(i!=0)answer+='/';
        }
        return answer;

    }
};



int main(){
    string in = "/a/./b/../../c/";
    Solution s;
    string answer = s.simplifyPath(in);
    cout << answer;
    return 0;
}