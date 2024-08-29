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
        if(postorder.empty())return nullptr;
        if(postorder.size() == 1){
            TreeNode* answer = new TreeNode(postorder[0]);
            return answer;
        }
        index = postorder.size()-1;
        TreeNode* answer = make_node(inorder,postorder,0,postorder.size()-1);
        return answer;

        
    }
    TreeNode* make_node(vector<int>& inorder, vector<int>& postorder,int start, int end){
        if(start > end)return nullptr;

        TreeNode* temp = new TreeNode(postorder[index]);

        int i;
        for(i = start ; i<end ; i++ ){
            if(inorder[i] == postorder[index]){
                index--;
                break;
            }
        }
        temp->right = make_node(inorder,postorder,i+1,end);
        temp->left = make_node(inorder,postorder,start,i-1);
        return temp;
    }
};