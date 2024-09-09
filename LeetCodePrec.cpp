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
    vector<TreeNode*>arr;
    void flatten(TreeNode* root) {
        // 포인트는 어떻게 in - place에서 교체를 하느냐인데....
        // pre order 순차대로가면서 right바꿔버리면 .... 참조가안되잖아
        // 일단 순회부분부터 만들어보자 메모리 신경안쓰고
        if(root == NULL)return;
        pre_order(root);
        TreeNode* temp = root;
        for(int i = 1 ; i<arr.size();i++){
            temp->left = NULL;
            temp->right = arr[i];
            temp = arr[i];
        }
        return;
    }
    void pre_order(TreeNode* temp){
        TreeNode* target = temp;
        arr.push_back(target);
        if(temp->left != NULL){
            target = temp->left;
            pre_order(target);
        }
        if(temp->right != NULL){
            target = temp->right;
            pre_order(target);
        }

    } 
};