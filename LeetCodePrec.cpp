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
    static bool comp(pair<Node*,int>a ,pair<Node*,int>b ){
        return a.second < b.second;
        
    }

    vector<pair<Node*,int>>pair;
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        pair.push_back({root,1});
        add_node(root,2);
        sort(pair.begin(),pair.end(),comp);
        int val = 1;
        Node*temp = root;
        for(int i = 1 ; i<pair.size();i++){
            cout << "val : " << pair[i].first->val << " num : "<<pair[i].second << "\n";
            if(pair[i].second == val){
                temp->next = pair[i].first;
                temp = pair[i].first;
            }else{
                temp->next = NULL;
                temp = pair[i].first;
            }
            val = pair[i].second;
        }
        return root;
    }
    void add_node(Node* temp,int num){
        Node* target = temp;
        vector<Node*>cont;
        if(target->left != NULL){
            pair.push_back({target->left , num});
            cont.push_back(target->left);
            add_node(target->left , num+1);
        }
        if(target->right != NULL){
            pair.push_back({target->right,num});
            cont.push_back(target->right);
            add_node(target->right , num+1);
        }
        
        
    }


};