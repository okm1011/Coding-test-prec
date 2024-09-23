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
    vector<TreeNode*>arr;
    map<TreeNode*,int>m;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        set_level(root,1);
        queue<TreeNode*>que;
        que.push(root);
        TreeNode* target;
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            if(temp->left == p || temp->left == q ){
                target = temp;
                break;
            }
            if(temp->right == p ||temp->right == q){
                target = temp;
                break;
            }
            que.push(temp->left);
            que.push(temp->right);
        }
        //cout << "target: "<<target->val<<"\n";
        if(m[p]==m[q]){
            return target;
        }else{
            make_arr(root);
            int p_num = 0 ;
            int q_num = 0 ;
            int target_cnt = 0;
            int cnt = 0;
            for(auto a : arr){
                //cout << a->val <<"\n";
                if(a->val == target->val)target_cnt = cnt;
                if(a->val == p->val)p_num = cnt;
                if(a->val == q->val)q_num = cnt;
                cnt++;
            }
            //cout << "t_num: "<< target_cnt << "p " << p_num << "q "<<q_num <<"\n";
            if(target_cnt < p_num && target_cnt < q_num || target_cnt > p_num && target_cnt > q_num){
                if(m[p]<m[q])return p;
                else return q;
            }else{
                return target;
            }
        }


    }
    void make_arr(TreeNode* target){
        if(target->left != NULL){
            make_arr(target->left);
        }
        arr.push_back(target);
        if(target->right != NULL){
            make_arr(target->right);
        }        
        
        //657243018
    }
    void set_level(TreeNode* temp,int level){
        m.insert({temp,level});
        if(temp->left != NULL)set_level(temp->left,level+1);
        if(temp->right != NULL)set_level(temp->right,level+1);
    }



        
    
};