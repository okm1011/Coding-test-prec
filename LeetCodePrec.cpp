/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())return nullptr;
        index = postorder.size()-1;
        TreeNode* answer = new TreeNode(postorder[postorder.size()-1]);
        int i;
        for(i = 0 ; i<postorder.size();i++){
            if(inorder[i] == postorder[postorder.size()-1]){
                break;
            }
        }
        answer->left = make_node(inorder,postorder,{0,i-1});
        answer->right = make_node(inorder,postorder, {i+1,postorder.size()-1});
        return answer;
    }
    TreeNode* make_node(vector<int>& inorder, vector<int>& postorder , pair<int,int>pos){
        if(pos.first>pos.second)return nullptr;
        int max_pos = INT_MIN;
        for(int i = pos.first ; i<=pos.second ; i++){
            int target = inorder[i];
            auto pos_idx = find(postorder.begin(),postorder.end(),target);
            if(pos_idx-postorder.begin() > max_pos)max_pos =pos_idx-postorder.begin();
        }
        TreeNode* temp = new TreeNode(postorder[max_pos]);

        int i;
        for(i = pos.first ; i<=pos.second;i++){
            if(inorder[i] == postorder[max_pos]){
                break;
            }
        }        
        temp->left = make_node(inorder,postorder,{pos.first,i-1});
        temp->right = make_node(inorder,postorder,{i+1,pos.second});

        return temp;
    }
};