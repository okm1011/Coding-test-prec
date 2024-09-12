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
    bool selected = false;
    int answer=0;
    int sumNumbers(TreeNode* root) {
        vector<TreeNode*>arr;
        search(root,arr);
        return answer;
    }
    void search(TreeNode* target , vector<TreeNode*>arr){

        arr.push_back(target);
        if(target->left == NULL && target->right == NULL){
            int sum = 0;
            for(int i = 0 ; i<arr.size();i++){
                sum  = sum*10 + arr[i]->val;
            }
            answer+=sum;
            cout << "left :" << answer<<"\n";
            return;
        }
        if(target->left !=NULL)search(target->left,arr);
            

        
        if(target->right != NULL)search(target->right,arr);
        
        
    }
};