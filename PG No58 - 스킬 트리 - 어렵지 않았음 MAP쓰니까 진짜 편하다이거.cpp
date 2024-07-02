#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {

    int answer = 0;
    map<char,int>level_map;
 // map으로 1,2,3,4 level 정함 그리고 skill tree에서 level로 올라와 있는지 판단 끝
    for(int i = 0 ; i<skill.size(); i++){
        level_map.insert({skill[i],i+1});
    }
    

    for(int i = 0 ; i<skill_trees.size();i++){
        bool flag = true;
        int cu_level = 1;
        for(int j = 0 ; j<skill_trees[i].size();j++){
            if(level_map[skill_trees[i][j]] == cu_level){
                cu_level++;
            }else if(level_map[skill_trees[i][j]] < cu_level){
                
            }else if(level_map.find(skill_trees[i][j]) == level_map.end()){

            }else{
                flag = false;
                break;                
            }
        }
        if(flag)answer++;
    }
    
    return answer;
}

int main(){

    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    int answer = solution(skill,skill_trees);
    cout << answer;

    return 0;
}