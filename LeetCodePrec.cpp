/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        Node* temp = root;
        vector<Node*>arr;
        while(1){
            arr.push_back(temp);
            if(temp->left != NULL)temp = temp->left;
            else break;
        }
        int cnt = arr.size();
        while(cnt>0){
            int round = 0;
            temp = arr[cnt-1];
            for(int i = 1 ; i<cnt ; i++){
                


                temp = temp -> next;
                round++;
            }

        }

        return root;
    }


};