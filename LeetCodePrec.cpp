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
class BSTIterator {
public:
    vector<TreeNode*>arr;
    int pos = -1;
    BSTIterator(TreeNode* root) {
        in_order(root);
        for(auto a : arr){
            cout << a->val << "\n";
        }
    }
    void in_order(TreeNode*target){
        if(target->left != NULL)in_order(target->left);
        arr.push_back(target);
        if(target->right != NULL)in_order(target->right);   
    }
    int next() {
        pos++;
        return arr[pos]->val;
    }
    
    bool hasNext() {
        if(pos+1<arr.size())return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */