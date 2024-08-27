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
    int index = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())return nullptr;
        TreeNode* answer = make_node(preorder,inorder,0,preorder.size()-1);
        return answer;

        
    }
    TreeNode* make_node(vector<int>& preorder, vector<int>& inorder,int start, int end){
        if(start>end)return nullptr;
        TreeNode* temp = new TreeNode(preorder[index]);
        int i;
        for(i = start ; i<=end ; i++){
            if(preorder[index] == inorder[i]){
                index++;
                break;
            }
        }
        temp->left = make_node(preorder,inorder,start,i-1);
        temp->right = make_node(preorder,inorder,i+1,end);
        return temp;
    }
};