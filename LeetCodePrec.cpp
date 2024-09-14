/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,int>m;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        set_level(root,1);
        // for(auto a : m){
        //     cout << "val = " << a.first->val << "level: "<<a.second<<"\n";
        // }
        if(m[p]<m[q]){
            
            TreeNode* temp = p;
            queue<TreeNode*>que;
            que.push(temp);

            while(!que.empty()){
                TreeNode* top = que.front();
                cout << top->val << "\n";
                if(top->left == q or top->right == q)return p;
                else{
                    if(top->left != NULL) que.push(top->left);
                    if(top->right != NULL) que.push(top->right);
                    que.pop();
                }
            }
        }else if(m[p]>m[q]){
            TreeNode* temp = q;
            queue<TreeNode*>que;
            que.push(temp);

            while(!que.empty()){
                TreeNode* top = que.front();
                cout << top->val << "\n";
                if(top->left == p or top->right == p)return q;
                else{
                    if(top->left != NULL) que.push(top->left);
                    if(top->right != NULL) que.push(top->right);
                    que.pop();
                }
            }
        }
        TreeNode* answer = not_itself(root,p,q);
        return answer;
        
    }
    void set_level(TreeNode* temp,int level){
        m.insert({temp,level});
        if(temp->left != NULL)set_level(temp->left,level+1);
        if(temp->right != NULL)set_level(temp->right,level+1);
    }
    TreeNode* not_itself(TreeNode* root,TreeNode* p , TreeNode* q){
        // 이부분 필요
    }

};