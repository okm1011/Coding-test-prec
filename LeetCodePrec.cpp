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

    vector<pair<Node*,int>>pair;
    
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        pair.push_back({root,1});
        queue<Node*>q;
        q.push(root);
        int val = 1;
        add_node(q,val);
        Node*temp = root;
        int num = 1;
        for(int i = 1 ; i<pair.size() ; i++){
            if(pair[i].second == num){
                temp->next = pair[i].first;
                temp = temp->next;
            }else{
                temp->next= NULL;
                temp = pair[i].first;
                num++;

            }
        }
        return root;
    }
    void add_node(queue<Node*>temp_q ,int val){
        val++;
        queue<Node*>change_q;
        while(!temp_q.empty()){
            
            Node* target = temp_q.front();
            temp_q.pop();
            if(target->left != NULL){
                pair.push_back({target->left,val});
                change_q.push(target->left);
            }
            if(target->right != NULL){
                pair.push_back({target->right,val});
                change_q.push(target->right);
            }
        }
        if(!change_q.empty())add_node(change_q,val);
        
    }



};