#include <string>
#include <vector>
#include <sstream>
using namespace std;


2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    for(string& q : quiz)
    {
        stringstream ss(q);
        string x, y, z;
        string op;
        ss >> x;
        ss >> op;
        ss >> y;
        ss >> z;
        ss >> z;

        int result;
        switch(op[0])
        {
            case '+':
                result = stoi(x) + stoi(y);
                break;
            case '-':
                result = stoi(x) - stoi(y);
                break;
            default:
                break;
        }

        if(result == stoi(z))
            answer.push_back("O");
        else
            answer.push_back("X");
    }

    return answer;
}


int main(){
    vector<string> quiz = {"3 - 4 = -3", "5 + 6 = 11"};
    
   
    vector<string> answer = solution(quiz);

}