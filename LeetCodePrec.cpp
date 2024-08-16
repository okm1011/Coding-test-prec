class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(int i = 0 ; i < tokens.size() ; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int temp;
                if(tokens[i] == "+"){
                    temp = first+second;
                }else if(tokens[i] == "-"){
                    temp = second-first;
                }else if(tokens[i] == "*"){
                    temp = first*second;
                }else{
                    temp = second/first;
                }
                cout << "temp = " << temp <<"\n";
                st.push(temp);
            }else{
                int temp = stoi(tokens[i]);
                st.push(temp);
            }
        }
        return st.top();
    }
};